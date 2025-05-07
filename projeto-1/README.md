# Projeto 1: Sistema de Gerenciamento de Tarefas

**Autor:** Enzo Cesar Consulo Silva  
**RA:** 22024541

Este projeto em C implementa um pequeno sistema de gerenciamento de tarefas usando uma **fila** para armazenar as tarefas pendentes e duas **listas simplesmente encadeadas** para registrar tarefas concluídas e pendentes, sempre ordenadas por data de término.

---

## Conceitos e Estruturas de Dados

- **Structs customizadas**  
  - `data` (dia, mês, ano)  
  - `tarefa` (código, nome, projeto, datas de início/fim, status)  
  - `No` (nó de lista encadeada contendo uma `tarefa` e ponteiro `prox`)  
- **Fila (FIFO)**  
  - TAD em `BibliotecaFila_e_Lista.h` com funções `criafila()`, `insere()`, `retira()`, etc.  
- **Lista simplesmente encadeada**  
  - Usada para armazenar tarefas concluídas e pendentes em ordem cronológica.  
- **Manipulação de tempo**  
  - `obterDataAtual()` usa `<time.h>` para obter a data do sistema.  
  - `comparadatas()` compara duas `data` para ordenar as listas.  
- **Alocação dinâmica**  
  - Uso de `malloc`/`free` para criar nós e copiar tarefas.  
- **Modularização procedural**  
  - Cada operação (inserção, remoção, modificação, impressão) é isolada em sua própria função.

---

## Funcionalidades

1. **Adicionar nova tarefa**  
   - Lê código, nome, projeto e datas de início/fim.  
   - Calcula status (0 = em dia, 1 = atrasada).  
   - Insere na fila de tarefas pendentes.  
2. **Modificar tarefa existente**  
   - Busca por código, permite alterar todos os campos.  
3. **Concluir tarefa**  
   - Remove da fila e insere na lista de concluídas, ordenada por data de término.  
4. **Gerenciar pendências**  
   - Verificar status de uma tarefa pelo código.  
   - Remover tarefa da lista de pendentes (retorna à fila).  
   - Marcar tarefa como pendente (status = –1) e adicionar à lista de pendentes, ordenada.  
5. **Listagem**  
   - Exibir lista de tarefas pendentes.  
   - Exibir lista de tarefas concluídas.  
   - Exibir tarefas concluídas separadas em “com atraso” e “sem atraso”.  
6. **Menu interativo**  
   - Interface de texto com 8 opções (incluir, modificar, concluir, gerenciar, listar, sair).

---

## Estrutura de Arquivos
projeto-1/
- BibliotecaFila_e_Lista.h # Protótipos de fila e lista
- Projeto 1.c # Funções e menu principal
- README.md # (este arquivo)
