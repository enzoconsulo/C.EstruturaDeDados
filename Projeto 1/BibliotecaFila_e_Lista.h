typedef struct DATA
{
    int dia;
    int mes;
    int ano;
} data;

typedef struct tarefaa
{
    int codigo;
    char nome[30];
    char projeto[30];
    data inicio;
    data fim;
    int status;
} tarefa;

typedef struct no
{
    tarefa info;
    struct no *prox;
} No;

typedef struct fila
{
    No *ini;
    No *fim;
} Fila;

Fila *criafila()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

No *ins_fim(No *fim, tarefa A)
{
    No *p = (No *)malloc(sizeof(No));
    p->info = A;
    p->prox = NULL;
    if (fim != NULL)
        fim->prox = p;
    return p;
}

void insere(Fila *f, tarefa T)
{
    f->fim = ins_fim(f->fim, T);
    if (f->ini == NULL)
        f->ini = f->fim;
}

No *ret_ini(No *ini)
{
    No *p = ini->prox;
    free(ini);
    return p;
}

tarefa *retira(Fila *f)
{
    tarefa *t = (tarefa *)malloc(sizeof(tarefa));

    if (f->ini == NULL)
    {
        printf("INVALIDO! Lista está vazia!\n");
        return NULL;
    }
    *t = f->ini->info;
    f->ini = ret_ini(f->ini);
    if (f->ini == NULL)
    {
        f->fim = NULL;
    }
    return t;
}

No *inserelista(No *recebida, tarefa T)
{
    No *novo;
    novo = (No *)malloc(sizeof(No));
    novo->info = T;
    novo->prox = recebida;
    return novo;
}
