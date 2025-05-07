#include <time.h>

typedef struct ITEM
{
    long int chave;
    float valor;
}item;

//Tempo-------------------------------------------------

double CalculoDoTempo(clock_t start, clock_t stop)
{
    return ((double)(stop - start)) / CLOCKS_PER_SEC;
}

void troca(item *a, item *b)
{
    item temp = *a;
    *a = *b;
    *b = temp;
}



//InsertionSort-----------------------------------------

void insercao(item *v, int n)
{
    int i, j;
    item aux;

    for (i = 1; i < n; i++)
    {
        for (j = i; j >= 0; j--)
        {
            if(v[j-1].chave<v[j].chave)
            {
                troca(&v[j-1],&v[j]);
            }
        }

    }
}

//BubbleSort---------------------------------------------

void Bolha(item *v, int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
    {
       for(j = 1; j < n-i; j++)
       {
            if (v[j].chave > v[j-1].chave)
            {
                troca(&v[j-1],&v[j]);
            }
       }
    }
}


//ShellSort----------------------------------------------

void shellsort(item *v, int n)
{
    int i, j, h;
    item aux;

    for (h=1; h < n; h = 3*h+1);

    while (h > 0)
    {
        h = (h-1)/3;

        for (i = h; i < n; i++)
        {
            aux = v[i];
            j = i;

            while (v[j - h].chave < aux.chave && j - h >= 0)
            {
                v[j] = v[j - h];
                j -= h;
                if (j<h) break;
            }

            v[j] = aux;
        }
     }
}



//MergeSort----------------------------------------------

void mergesort(item *v, int n)
{
    int *c = malloc(sizeof(int) * n);
    sort(v, c, 0, n-1);
    free(c);
}

void sort(item *v, int *c, int i, int f)
{
    if (i < f)
    {
        int m = (i + f) / 2;
        sort(v, c, i, m);
        sort(v, c, m + 1, f);
        if (v[m].chave < v[m + 1].chave)
        {
            merge(v, c, i, m, f);
        }
    }
}

void merge(item *v, int *c, int i, int m, int f)
{
    int z, iv = i, ic = m + 1;
    for (z = i; z <= f; z++) c[z] = v[z].chave;
    z = i;
    while (iv <= m && ic <= f)
    {
        if (c[iv] >= c[ic])
        {
            v[z++].chave = c[iv++];
        }
        else {
            v[z++].chave = c[ic++];
        }
    }
    while (iv <= m)
    {
        v[z++].chave = c[iv++];
    }
    while (ic <= f)
    {
        v[z++].chave = c[ic++];
    }
}


//quicksort-----------------------------------
long int pivomeio(item *v, long int LI, long int LS)
{
    long int meio = (LI + LS) / 2;
    long int pivo = v[meio].chave;

    while (LI <= LS)
    {
        while (v[LI].chave < pivo)
        {
            LI++;
        }
        while (v[LS].chave > pivo)
        {
            LS--;
        }
        if (LI <= LS)
        {
            long int temp = v[LI].chave;
            v[LI].chave = v[LS].chave;
            v[LS].chave = temp;
            LI++;
            LS--;
        }
    }
    return LI;
}

void quickSortPM(item *v, long int LI, long int LS)
{
    while (LI < LS)
        {
        long int p = pivomeio(v, LI, LS);

        if (p - LI < LS - p)
        {
            quickSortPM(v, LI, p - 1);
            LI = p + 1;
        } else
        {
            quickSortPM(v, p + 1, LS);
            LS = p - 1;
        }
    }
}

long int pivoinferior(item *v, long int LI, long int LS)
{
    long int aux, pivo, e = LI, d = LS;
    pivo = v[e].chave;
    while (e < d)
    {
        while ((v[e].chave <= pivo) && (e < LS))
        {
            e++;
        }
        while ((v[d].chave > pivo) && (d > LI))
        {
            d--;
        }
        if (e < d)
        {
            aux = v[e].chave;
            v[e].chave = v[d].chave;
            v[d].chave = aux;
        }
    }
    aux = v[LI].chave;
    v[LI].chave = v[d].chave;
    v[d].chave = aux;
    return d;
}

void quickSortPI(item *v, long int LI, long int LS)
{
    if (LI < LS)
    {
        long int p;
        p = pivoinferior(v, LI, LS);
        quickSortPI(v, LI, p - 1);
        quickSortPI(v, p + 1, LS);
    }
}

long int pivosuperior(item *v, long int LI, long int LS)
{
    long int aux, pivo, e = LI, d = LS;
    pivo = v[d].chave;
    while (e < d)
    {
        while ((v[e].chave < pivo) && (e < LS))
        {
            e++;
        }
        while ((v[d].chave >= pivo) && (d > LI))
        {
            d--;
        }
        if (e < d)
        {
            aux = v[e].chave;
            v[e].chave = v[d].chave;
            v[d].chave = aux;
        }
    }
    aux = v[LS].chave;
    v[LS].chave = v[e].chave;
    v[e].chave = aux;
    return e;
}

void quickSortPS(item *v, long int LI, long int LS)
{
    if (LI < LS)
    {
        long int p;
        p = pivosuperior(v, LI, LS);
        quickSortPS(v, LI, p - 1);
        quickSortPS(v, p + 1, LS);
    }
}

void combSort(item *v, long int n)
{
    int gap = n;
    int trocado = 1;

    while (gap > 1 || trocado)
        {
        if (gap > 1) {
            gap = (gap * 10) / 13;
        }

        trocado = 0;

        for (long int i = 0; i < n - gap; i++)
        {
            if (v[i].chave < v[i + gap].chave)
            {
                troca(&v[i], &v[i + gap]);
                trocado = 1;
            }
        }
    }
}

//-------------------------------------------------------



void gerarValoresAleatorios(item v[], int seed, long int tamanhoVetor)
{
    srand(seed);

    for (long int i = 0; i < tamanhoVetor; i++)
    {
        v[i].chave = rand();
        v[i].valor = (float)(rand() % 100000) / 100 + 100;
    }
}

void gerarValoresCrescentes(item v[], long int tamanhoVetor,int seed)
{
    for (long int i = 0; i < tamanhoVetor; i++)
        {
        v[i].chave = i*seed;
        v[i].valor = (float)(rand() % 100000) / 100 + 100;
    }
}

void criarVetores(item **Vetor1, item **Vetor2, long int TAMVet, int SEEDVet)
{
    *Vetor1 = (item *)malloc(TAMVet * sizeof(item));
    *Vetor2 = (item *)malloc(TAMVet * sizeof(item));

    if (*Vetor1 == NULL || *Vetor2 == NULL)
    {
        printf("Erro ao alocar memória!");
        exit(EXIT_FAILURE);
    }

    gerarValoresAleatorios(*Vetor1, SEEDVet, TAMVet);
    gerarValoresCrescentes(*Vetor2, TAMVet,SEEDVet);
}

void imprimirVetor(item *v, int n)
{
    for (int i = 0; i < n+1; i++)
    {
    printf("%d ", v[i].chave);
    }
    printf("\n");
}

