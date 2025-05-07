#include <stdio.h>
#include <stdlib.h>
#include "Funcoes.h"
#include <time.h>



int main() {
    int tempo;
    long int TAMVet, SEEDVet;
    clock_t start,stop;

    printf("\n Escolha o tamanho do vetor:\n ");
    scanf("%d", &TAMVet);
    printf("\n Escolha a seed a ser usada:\n ");
    scanf("%d", &SEEDVet);

    item *Vetor1;
    item *Vetor2;


    criarVetores(&Vetor1, &Vetor2, TAMVet, SEEDVet);

    start = clock();
    insercao(Vetor1,TAMVet);
    stop = clock();

    printf("\n-/-/-/-/-/-/-/-/-/-/- Tempo para o InsertionSort -/-/-/-/-/-/-/-/-/-/-\n");
    printf("\n -> Caso 1 : %.6fs", CalculoDoTempo(start,stop));


    start = clock();
    insercao(Vetor2,TAMVet);
    stop = clock();

    printf("\n -> Caso 2 : %.6fs\n", CalculoDoTempo(start,stop));





    criarVetores(&Vetor1, &Vetor2, TAMVet, SEEDVet);


    start = clock();
    Bolha(Vetor1,TAMVet);
    stop = clock();

    printf("\n-/-/-/-/-/-/-/-/-/-/- Tempo para o BubbleSort -/-/-/-/-/-/-/-/-/-/-\n");
    printf("\n -> Caso 1 : %.6fs", CalculoDoTempo(start,stop));


    start = clock();
    Bolha(Vetor2,TAMVet);
    stop = clock();

    printf("\n -> Caso 2 : %.6fs\n", CalculoDoTempo(start,stop));




    criarVetores(&Vetor1, &Vetor2, TAMVet, SEEDVet);


    start = clock();
    shellsort(Vetor1,TAMVet);
    stop = clock();

    printf("\n-/-/-/-/-/-/-/-/-/-/- Tempo para o ShellSort -/-/-/-/-/-/-/-/-/-/-\n");
    printf("\n -> Caso 1 : %.6fs", CalculoDoTempo(start,stop));


    start = clock();
    shellsort(Vetor2,TAMVet);
    stop = clock();

    printf("\n -> Caso 2 : %.6fs\n", CalculoDoTempo(start,stop));









    criarVetores(&Vetor1, &Vetor2, TAMVet, SEEDVet);


    start = clock();
    mergesort(Vetor1,TAMVet);
    stop = clock();

    printf("\n-/-/-/-/-/-/-/-/-/-/- Tempo para o MergeSort -/-/-/-/-/-/-/-/-/-/-\n");
    printf("\n -> Caso 1 : %.6fs", CalculoDoTempo(start,stop));


    start = clock();
    mergesort(Vetor2,TAMVet);
    stop = clock();

    printf("\n -> Caso 2 : %.6fs\n", CalculoDoTempo(start,stop));



    criarVetores(&Vetor1, &Vetor2, TAMVet, SEEDVet);

    start = clock();
    combSort(Vetor1, TAMVet);
    stop = clock();
    printf("\n-/-/-/-/-/-/-/-/-/-/- Tempo para o CombSort -/-/-/-/-/-/-/-/-/-/-\n");
    printf("\n -> Caso 1 : %.6fs", CalculoDoTempo(start, stop));

    start = clock();
    combSort(Vetor2, TAMVet);
    stop = clock();
    printf("\n -> Caso 2 : %.6fs\n", CalculoDoTempo(start, stop));




    criarVetores(&Vetor1, &Vetor2, TAMVet, SEEDVet);


    start = clock();
    quickSortPI(Vetor1,0,TAMVet);
    stop = clock();


    printf("\n-/-/-/-/-/-/-/-/-/-/- Tempo para o Quicksort -/-/-/-/-/-/-/-/-/-/-\n");
    printf("\n -> Caso 1 :");

    printf("\n Tempo no Limite Inferior: %.6fs\n", CalculoDoTempo(start,stop));

    criarVetores(&Vetor1, &Vetor2, TAMVet, SEEDVet);


    start = clock();
    quickSortPS(Vetor1,0,TAMVet);
    stop = clock();

    printf("\n Tempo no Limite Superior: %.6fs\n", CalculoDoTempo(start,stop));

    criarVetores(&Vetor1, &Vetor2, TAMVet, SEEDVet);



    start = clock();
    quickSortPM(Vetor1,0,TAMVet);
    stop = clock();

    printf("\n Tempo no Limite Meio Do Vetor: %.6fs\n", CalculoDoTempo(start,stop));





    criarVetores(&Vetor1, &Vetor2, TAMVet, SEEDVet);


    start = clock();
    quickSortPI(Vetor2,0,TAMVet);
    stop = clock();

    printf("\n -> Caso 2 :");


    printf("\n Tempo no Limite Inferior: %.6fs\n", CalculoDoTempo(start,stop));

    criarVetores(&Vetor1, &Vetor2, TAMVet, SEEDVet);


    start = clock();
    quickSortPM(Vetor2,0,TAMVet);
    stop = clock();

    printf("\n Tempo no Limite Superior: %.6fs\n", CalculoDoTempo(start,stop));


    criarVetores(&Vetor1, &Vetor2, TAMVet, SEEDVet);


    start = clock();
    quickSortPM(Vetor2,0,TAMVet);
    stop = clock();

    printf("\n Tempo no Limite Meio Do Vetor: %.6fs\n", CalculoDoTempo(start,stop));



    printf("\n-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-\n");


    free(Vetor1);
    free(Vetor2);
    return 0;
}
