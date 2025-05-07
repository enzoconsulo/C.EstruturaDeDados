typedef struct tarefaa
{
    int codigo;
    char nome[30];
    char projeto[30];
    long inicio;
    long fim;
    int status;

}tarefa

typedef struct no
{
    tarefa;
    struct no* prox;
}No;

typedef struct fila
{
    No * ini;
    No * fim;
} Fila;

Fila* criafila()
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

No* ins_fim (No* fim, float A)
{
    No* p = (No*)
    malloc(sizeof(No));
    p->info= A;
    p->prox = NULL;
    if (fim != NULL)
    fim->prox = p;
    return p;
}


void insere (Fila* f, float v)
(
    f->fim=ins_fim(f->fim,v);
    if (f->ini==NULL)
    f->ini = f->fim;
)

No* ret_ini (No* ini)
{
    No* p = ini->prox;
    free(ini);
    return p;
}

tarefa* retira (Fila* f)
{
    tarefa* t = (tarefa*) malloc(sizeof(tarefa))

    if (f->ini==NULL)
    {
    printf("INVALIDO! Lista está vazia!\n");
    return NULL;
    }
    *t=f->ini->tarefa;
    f->ini = ret_ini(f->ini);
    if (f->ini == NULL)
    {f->fim = NULL;}
    return t;
}
