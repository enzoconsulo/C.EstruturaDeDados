// Enzo Cesar Consulo Silva - RA:22024541
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "BibliotecaFila_e_Lista.h"



int comparadatas(data data1, data data2)
{
    if (data1.ano < data2.ano ||
        (data1.ano == data2.ano && data1.mes < data2.mes) ||
        (data1.ano == data2.ano && data1.mes == data2.mes && data1.dia < data2.dia))
    {
        return 1; // data1 > data2
    }
    else
    {
        return 0; // data1 < data2
    }
}

data obterDataAtual()
{
    time_t tempoAtual;
    struct tm *infoTempo;
    data d;

    time(&tempoAtual);
    infoTempo = localtime(&tempoAtual);

    d.dia = infoTempo->tm_mday;
    d.mes = infoTempo->tm_mon + 1;
    d.ano = infoTempo->tm_year + 1900;

    return d;
}

void InsereListaConcluida(int cod, Fila *filatarefas, No **inicio)
{
    tarefa ConcluidaTarefa;
    No *ConcluidaNo = (No *)malloc(sizeof(No));

    if (filatarefas->ini == NULL)
    {
        printf("\nERRO: A lista de tarefas est� vazia!\n");
        return;
    }

    Fila *filaAuxiliar = criafila();
    int encontrou = 0;

    while (filatarefas->ini != NULL && !encontrou)
    {
        tarefa *aux = retira(filatarefas);

        if (cod == aux->codigo)
        {
            ConcluidaTarefa = *aux;
            encontrou = 1;
            free(aux);
        }
        else
        {
            insere(filaAuxiliar, *aux);
            free(aux);
        }
    }

    while (filaAuxiliar->ini != NULL)
    {
        tarefa *aux = retira(filaAuxiliar);
        insere(filatarefas, *aux);
        free(aux);
    }

    if (encontrou == 1)
    {
        ConcluidaNo->info = ConcluidaTarefa;
        ConcluidaNo->prox = NULL;

        No *prev = NULL;
        No *p = *inicio;

        if (p == NULL || comparadatas(ConcluidaNo->info.fim, p->info.fim) == 0)
        {
            ConcluidaNo->prox = p;
            *inicio = ConcluidaNo;
        }
        else
        {
            while (p != NULL && comparadatas(ConcluidaNo->info.fim, p->info.fim) != 0)
            {
                prev = p;
                p = p->prox;
            }
            prev->prox = ConcluidaNo;
            ConcluidaNo->prox = p;
        }
        printf("\n===============================================\n");
        printf("\nTarefa inserida na lista de tarefas concluidas!\n");
        printf("\n===============================================\n");
    }
    else
    {
        printf("\n===============================================\n");
        printf("\n\n ERRO!\n  Nao existe nenhuma tarefa na fila de tarefas com este codigo!\n");
        printf("\n===============================================\n");
    }
}


void InsereListaPendentes(int cod, Fila *filatarefas, No **inicio)
{
    tarefa PendenteTarefa;
    No *ConcluidaNo = (No *)malloc(sizeof(No));

    if (filatarefas->ini == NULL)
    {
        printf("\n===============================================\n");
        printf("\nERRO: A lista de tarefas est� vazia!\n");
        printf("\n===============================================\n");
        return;
    }

    Fila *filaAuxiliar = criafila();
    int encontrou = 0;

    while (filatarefas->ini != NULL && !encontrou)
    {
        tarefa *aux = retira(filatarefas);

        if (cod == aux->codigo)
        {
            PendenteTarefa = *aux;
            PendenteTarefa.status = -1;
            encontrou = 1;
            free(aux);
        }
        else
        {
            insere(filaAuxiliar, *aux);
            free(aux);
        }
    }

    while (filaAuxiliar->ini != NULL)
    {
        tarefa *aux = retira(filaAuxiliar);
        insere(filatarefas, *aux);
        free(aux);
    }

    if (encontrou == 1)
    {
        ConcluidaNo->info = PendenteTarefa;
        ConcluidaNo->prox = NULL;

        No *prev = NULL;
        No *p = *inicio;

        if (p == NULL || comparadatas(ConcluidaNo->info.fim, p->info.fim) == 0)
        {
            ConcluidaNo->prox = p;
            *inicio = ConcluidaNo;
        }
        else
        {
            while (p != NULL && comparadatas(ConcluidaNo->info.fim, p->info.fim) != 0)
            {
                prev = p;
                p = p->prox;
            }
            prev->prox = ConcluidaNo;
            ConcluidaNo->prox = p;
        }
        printf("\n===============================================\n");
        printf("\nTarefa inserida na lista de tarefas pendentes!\n");
        printf("\n===============================================\n");
    }
    else
    {
        printf("\n===============================================\n");
        printf("\n\n ERRO!\n  Nao existe nenhuma tarefa na fila de tarefas com este codigo!\n");
        printf("\n===============================================\n");
    }
}


void adicionartarefa(Fila *filatarefas)
{
    data dataatual = obterDataAtual();
    int atrasado = 0;

    tarefa tarefainsere;
    printf("Digite os Dados da tarefa que deseja adicionar:\n");

    printf(" -Codigo da tarefa:");
    scanf("%d", &tarefainsere.codigo);

    printf(" -Nome da Tarefa: ");
    scanf("%s", tarefainsere.nome);

    printf(" -Nome do Projeto: ");
    scanf("%s", tarefainsere.projeto);

    printf(" -Data de inicio:\n Dia: ");
    scanf("%d", &tarefainsere.inicio.dia);

    printf(" Mes: ");
    scanf("%d", &tarefainsere.inicio.mes);

    printf(" Ano: ");
    scanf("%d", &tarefainsere.inicio.ano);

    printf(" -Data para Termino:\n Dia: ");
    scanf("%d", &tarefainsere.fim.dia);

    printf(" Mes: ");
    scanf("%d", &tarefainsere.fim.mes);

    printf(" Ano: ");
    scanf("%d", &tarefainsere.fim.ano);

    atrasado = comparadatas(tarefainsere.fim, dataatual);

    if (atrasado == 1)
    {
        tarefainsere.status = 1;
    }
    else
    {
        tarefainsere.status = 0;
    }

    insere(filatarefas, tarefainsere);

    printf("\n===============================================\n");
    printf("\n\n    Tarefa Adicionada com sucesso!");
    printf("\n===============================================\n");
}

void modificatarefa(tarefa *tarefainsere)
{
    printf("Digite os Dados da tarefa que deseja modificar:\n");

    printf(" -Codigo da tarefa:");
    scanf("%d", &tarefainsere->codigo);

    printf(" -Nome da Tarefa: ");
    scanf("%s", tarefainsere->nome);

    printf(" -Nome do Projeto: ");
    scanf("%s", tarefainsere->projeto);

    printf(" -Data de inicio:\n Dia: ");
    scanf("%d", &tarefainsere->inicio.dia);

    printf(" Mes: ");
    scanf("%d", &tarefainsere->inicio.mes);

    printf(" Ano: ");
    scanf("%d", &tarefainsere->inicio.ano);

    printf(" -Data para Termino:\n Dia: ");
    scanf("%d", &tarefainsere->fim.dia);

    printf(" Mes: ");
    scanf("%d", &tarefainsere->fim.mes);

    printf(" Ano: ");
    scanf("%d", &tarefainsere->fim.ano);
}

void Modificartarefa(Fila *filatarefas)
{
    int codigoDesejado;
    printf("\n\n Digite o Codigo da tarefa que deseja mudar:");
    scanf("%d", &codigoDesejado);

    Fila *filaAuxiliar = criafila();
    int encontrou = 0;

    if (filatarefas->ini == NULL)
    {
        printf("\n===============================================\n");
        printf("\n A fila esta vazia! \n");
        printf("\n===============================================\n");
        return;
    }
    else
    {
        while (filatarefas->ini != NULL)
        {
            tarefa *tarefaAtual = retira(filatarefas);

            if (tarefaAtual->codigo == codigoDesejado)
            {
                encontrou = 1;
                modificatarefa(tarefaAtual);
            }

            insere(filaAuxiliar, *tarefaAtual);
            free(tarefaAtual);
        }

        while (filaAuxiliar->ini != NULL)
        {
            tarefa *tarefaAux = retira(filaAuxiliar);
            insere(filatarefas, *tarefaAux);
            free(tarefaAux);
        }

        if (encontrou == 0)
        {
            printf("\n===============================================\n");
            printf("\n Nao existe esse codigo na fila de tarefas!\n");
            printf("\n===============================================\n");
        }
        else
        {
            printf("\n===============================================\n");
            printf("\n Modificacao feita com sucesso!\n");
            printf("\n===============================================\n");
        }
    }
}

void verificarStatusPorCodigo(int codigo, Fila *filatarefas)
{
    Fila *filaAuxiliar = criafila();
    int encontrou = 0;
    printf("\n===============================================\n");
    while (filatarefas->ini != NULL)
    {
        tarefa *tarefaAtual = retira(filatarefas);

        if (tarefaAtual->codigo == codigo)
        {
            encontrou = 1;
            printf("\nStatus da Tarefa (Codigo %d):\n", codigo);
            printf("Nome da Tarefa: %s\n", tarefaAtual->nome);
            if (tarefaAtual->status == 1)
            {
                printf("Status: Atrasada\n");
            }
            else
            {
                printf("Status: Em dia\n");
            }
        }

        insere(filaAuxiliar, *tarefaAtual);
        free(tarefaAtual);
    }

    while (filaAuxiliar->ini != NULL)
    {
        tarefa *tarefaAux = retira(filaAuxiliar);
        insere(filatarefas, *tarefaAux);
        free(tarefaAux);
    }

    if (encontrou == 0)
    {
        printf("\nNao existe tarefa com o codigo %d na fila de tarefas!\n", codigo);
    }
    printf("\n===============================================\n");
}

void RemoveListaPendentesPorCodigo(int codigo, No **inicio, Fila *filatarefas)
{
    No *atual = *inicio;
    No *anterior = NULL;
    int encontrou = 0;

    while (atual != NULL && !encontrou)
    {
        if (atual->info.codigo == codigo)
        {
            encontrou = 1;
            tarefa t = atual->info;

            if (anterior == NULL)
            {
                *inicio = atual->prox;
            }
            else
            {
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("\n===============================================\n");
            printf("Tarefa com codigo %d removida da lista de pendentes.\n\n", codigo);

            insere(filatarefas, t);
            printf("Tarefa com codigo %d retornou para a fila de tarefas.\n", codigo);
            printf("\n===============================================\n");
        }
        else
        {
            anterior = atual;
            atual = atual->prox;
        }
    }

    if (encontrou == 0)
    {
        printf("\n===============================================\n");
        printf("Nao existe tarefa com o codigo %d na lista de pendentes.\n", codigo);
        printf("\n===============================================\n");
    }
}

void imprimeLista(No *inicio)
{
    No *atual = inicio;

    if (atual != NULL)
    {
        printf("\n\n======================= Lista de Tarefas =======================\n\n");
        while (atual != NULL)
        {
            printf("\n=================== Tarefa: %d ===================\n", atual->info.codigo);
            printf("Nome da Tarefa: %s\n", atual->info.nome);
            printf("Nome do Projeto: %s\n", atual->info.projeto);
            printf("Data de Inicio: %d/%d/%d\n", atual->info.inicio.dia, atual->info.inicio.mes, atual->info.inicio.ano);
            printf("Data de Termino: %d/%d/%d\n", atual->info.fim.dia, atual->info.fim.mes, atual->info.fim.ano);
            printf("Status: %s\n", (atual->info.status == 1) ? "Atrasada" : "Em dia");
            printf("\n===============================================\n");
            atual = atual->prox;
        }
        printf("\n\n========================= Fim da Lista =========================\n\n");
    }
    else
    {
        printf("\n==============================================================");
        printf("\n\n  LISTA VAZIA!!");
        printf("\n\n==============================================================\n\n");
    }
}

void imprimeTarefasConcluidas(No *inicio)
{
    No *atual = inicio;
    int tarefasComAtraso = 0, tarefasSemAtraso = 0;

    printf("\n\n======================= Tarefas Concluidas =======================\n\n");

    printf("\n         Tarefas com atraso:\n===============================================\n ");
    while (atual != NULL)
    {
        if (atual->info.status == 1)
        {
            printf(" - Codigo da Tarefa: %d\n", atual->info.codigo);
            printf(" - Nome da Tarefa: %s\n", atual->info.nome);
            printf(" - Nome do Projeto: %s\n", atual->info.projeto);
            printf(" - Data de Inicio: %d/%d/%d\n", atual->info.inicio.dia, atual->info.inicio.mes, atual->info.inicio.ano);
            printf(" - Data de Termino: %d/%d/%d\n", atual->info.fim.dia, atual->info.fim.mes, atual->info.fim.ano);
            printf("\n===============================================\n");
            tarefasComAtraso++;
        }
        atual = atual->prox;
    }

    if (tarefasComAtraso == 0)
    {
        printf("\nNenhuma tarefa concluida com atraso.\n");
    }

    atual = inicio;

    printf("\n \n         Tarefas sem atraso:\n===============================================\n");
    while (atual != NULL)
    {
        if (atual->info.status == 0)
        {
            printf(" - Codigo da Tarefa: %d\n", atual->info.codigo);
            printf(" - Nome da Tarefa: %s\n", atual->info.nome);
            printf(" - Nome do Projeto: %s\n", atual->info.projeto);
            printf(" - Data de Inicio: %d/%d/%d\n", atual->info.inicio.dia, atual->info.inicio.mes, atual->info.inicio.ano);
            printf(" - Data de Termino: %d/%d/%d\n", atual->info.fim.dia, atual->info.fim.mes, atual->info.fim.ano);
            printf("\n===============================================\n");
            tarefasSemAtraso++;
        }
        atual = atual->prox;
    }

    printf("\n\n========================= Fim da Lista =========================\n\n");
}

int main()
{

    data dataatual = obterDataAtual();
    printf("\n                               Bem Vindo !\n\n !-!-!-!-!-!-!-!-! Sistema de Gerenciamento de Tarefas !-!-!-!-!-!-!-!-!\n                         Data Atual: %d/%d/%d\n\n", dataatual.dia, dataatual.mes, dataatual.ano);
    Fila *filatarefas = criafila();
    No *INICIOConcluidas = NULL;
    No *INICIOPendentes = NULL;

    int escolha = 0;
    while (escolha != 8)
    {
        printf("\n\n\n\n O que deseja fazer?\n Guia:\n  1. Adicionar uma nova Tarefa\n  2. Modificar uma Tarefa.\n  3. Concluir Tarefa\n  4. Atualizacao do Status da Tarefa\n  5. Lista de Tarefas Pendentes\n  6. Lista de Tarefas Concluidas\n  7. Lista de Tarefas Concluidas com e sem Atrasos\n  8. Sair do Programa\n  ");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            adicionartarefa(filatarefas);
            break;

        case 2:
            Modificartarefa(filatarefas);
            break;

        case 3:
        {
            int codigo = 0;
            printf("Insira o codigo da tarefa que deseja marcar como concluida:");
            scanf("%d", &codigo);
            InsereListaConcluida(codigo, filatarefas, &INICIOConcluidas);
            break;
        }

        case 4:
        {
            int escolhacase4 = 0;
            printf("\n O que deseja fazer?\n(1- Verificar status da tarefa pelo codigo , 2- Remover tarefa da lista de pendentes, 3- Adicionar a lista de pendentes)\n");
            scanf(" %d", &escolhacase4);

                switch (escolhacase4)
                {
                case 1:
                {
                    int codigo = 0;
                    printf("Digite o codigo da tarefa que deseja verificar: ");
                    scanf("%d", &codigo);
                    verificarStatusPorCodigo(codigo, filatarefas);
                    break;
                }

                case 2:
                {
                    int codigo = 0;
                    printf("Digite o codigo da tarefa que deseja remover da lista de pendentes: ");
                    scanf("%d", &codigo);
                    RemoveListaPendentesPorCodigo(codigo, &INICIOPendentes, filatarefas);
                    break;
                }

                case 3:
                {
                    int codigo = 0;
                    printf("Insira o codigo da tarefa que deseja marcar como pendente:");
                    scanf("%d", &codigo);
                    InsereListaPendentes(codigo, filatarefas, &INICIOPendentes);
                    break;
                }

                default:
                    printf("Opcao invalida.\n");
                    break;
                }
            break;
        }

        case 5:
        {
            imprimeLista(INICIOPendentes);
            break;
        }

        case 6:
        {
            imprimeLista(INICIOConcluidas);
            break;
        }

       case 7:
        {
        imprimeTarefasConcluidas(INICIOConcluidas);
        break;
        }

       case 8:
        {
            printf("Finalizando o Programa...");
            break;
        }

        default:
            printf("\n\n Numero inserido invalido!! Revise as informacoes dadas no 'guia'\n\n");

        }
    }
}
