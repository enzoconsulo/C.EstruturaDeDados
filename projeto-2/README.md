# Projeto 2: Benchmark de Algoritmos de Ordenação

**Autor:** Enzo Cesar Consulo Silva  
**RA:** 22024541

Este projeto em C implementa e compara o tempo de execução de diversos algoritmos de ordenação em dois casos distintos (denominados “Caso 1” e “Caso 2”), usando vetores gerados a partir de uma mesma seed. São testados:

- Insertion Sort  
- Bubble Sort  
- Shell Sort  
- Merge Sort  
- Comb Sort  
- Quick Sort com três estratégias de pivô:  
  - Primeiro elemento (PI)  
  - Último elemento (PS)  
  - Elemento do meio (PM)  

---

## Conceitos e Estruturas Utilizadas

- **Alocação dinâmica de memória**  
  - Uso de `malloc`/`free` para criar e destruir vetores de tamanho definido pelo usuário.  
- **Modularização**  
  - Biblioteca `Funcoes.h`/`Funcoes.c` agrupa:  
    - `criarVetores(item **V1, item **V2, long int n, long int seed)`: preenche dois vetores com mesma sequência pseudo-aleatória.  
    - Funções de ordenação: `insercao()`, `Bolha()`, `shellsort()`, `mergesort()`, `combSort()`, `quickSortPI()`, `quickSortPS()`, `quickSortPM()`.  
    - `CalculoDoTempo(clock_t start, clock_t stop)`: converte ticks de clock em segundos.  
- **Medição de desempenho**  
  - Uso de `<time.h>` e `clock()` para capturar tempo antes e depois de cada ordenação.  
- **Comparação de casos**  
  - Dois conjuntos de dados (Vetor1 e Vetor2) gerados para simular “melhor caso” e “pior caso” ou diferentes distribuições.  

---

## Funcionalidades

1. **Entrada de parâmetros**  
   - Pergunta ao usuário tamanho do vetor (`TAMVet`) e seed (`SEEDVet`).  
2. **Geração de vetores**  
   - Cria dois vetores idênticos em conteúdo, mas que podem resultar em comportamentos diferentes para os algoritmos (por ordem inicial distinta).  
3. **Execução e medição**  
   - Para cada algoritmo e para cada vetor:  
     - Inicia o clock, chama a função de ordenação, para o clock, e imprime o tempo decorrido.  
   - Exibe os resultados agrupados por algoritmo e “Caso 1” / “Caso 2”.  
4. **Limpeza**  
   - Libera toda a memória alocada ao final.  

---

## Estrutura de Arquivos
projeto-2/
─ Funcoes.fila.h # Protótipos de funções de fila
─ Funcoes.h # Declarações das funções de ordenação, geração de vetores e utilitários (troca, cálculo de tempo), além da definição da struct item
─ main.c # Função main com laço de testes e relatórios de tempo
─ README.md # (este arquivo)
