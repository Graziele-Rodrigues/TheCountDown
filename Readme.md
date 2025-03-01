# Resolução de Problema com Operações Matemáticas

## Descrição do Projeto
Este projeto implementa um algoritmo que encontra a melhor combinação de operações matemáticas para aproximar um número-alvo a partir de um conjunto de números dados. O código utiliza **força bruta** combinada com **backtracking** para explorar todas as possibilidades e selecionar a melhor solução.

## Estrutura do Código
### Arquivos
- `main.c`: Contém os testes do algoritmo.
- `operacoes.h`: Declaração das funções e estruturas utilizadas.
- `operacoes.c`: Implementação das operações matemáticas e do algoritmo de busca da melhor solução.

### Funções Principais

#### `const char* op_to_string(Op op)`
Converte um operador matemático (`+`, `-`, `*`, `/`) em uma string legível.

#### `bool is_valid(Op op, int x, int y)`
Verifica se uma operação matemática entre dois números é válida (evita divisões por zero, números negativos indesejados, etc.).

#### `int apply(Op op, int x, int y)`
Aplica uma operação matemática (`+`, `-`, `*`, `/`) entre dois números e retorna o resultado.

#### `void print_expr(Expr* expr)`
Imprime a expressão matemática correspondente à melhor solução encontrada.

#### `void free_expr(Expr* expr)`
Libera a memória alocada para a árvore de expressões matemáticas.

#### `void find_best(int numbers[], int size, int target, BestResult* best)`
Função recursiva que busca a melhor combinação de operações para aproximar o número-alvo.

#### `void solve(int numbers[], int count, int target)`
Inicia a busca pela melhor solução e exibe os resultados.

## Compilação e Execução
Para compilar o código utilizando `gcc`, execute:
```sh
gcc main.c operacoes.c -o programa
```

Para executar o programa:
```sh
./programa
```

## Análise do Algoritmo
### **1. Força Bruta**
O algoritmo testa **todas as combinações possíveis** de operações matemáticas entre os números fornecidos. Ele gera todas as expressões válidas e verifica qual delas se aproxima mais do número-alvo.

**Características da força bruta presentes no código:**
- Gera todas as combinações possíveis de números e operações.
- Não usa heurísticas para reduzir o espaço de busca, explorando todas as opções possíveis.
- Exploração exaustiva: mesmo que um número já esteja muito próximo do alvo, o algoritmo continua testando outras possibilidades.

**Exemplo de força bruta:**
Dado `{1, 3, 7, 10, 25, 50}`, o algoritmo testa todas as operações possíveis entre esses números até encontrar o melhor resultado.

### **2. Backtracking**
O algoritmo utiliza **backtracking** para evitar cálculos desnecessários:

- Em cada nível da recursão, escolhe um par de números, aplica uma operação e continua testando com o novo conjunto reduzido.
- Caso uma operação não leve a uma solução melhor, ele "desfaz" aquela escolha e tenta outras combinações.

O backtracking ocorre na função `find_best()`, que:
- Escolhe dois números, aplica uma operação e reduz o conjunto.
- Continua o processo até que reste apenas um número.
- Se um caminho não leva a uma melhor solução, volta atrás e tenta outra possibilidade.

### **3. Paradigmas Não Utilizados**
- **Divisão e Conquista**: não está presente, pois o problema não é dividido em subproblemas independentes que são resolvidos separadamente antes de combinar os resultados.
- **Redução de Problema**: o problema não é transformado em outro problema já resolvido (como converter para um problema de programação dinâmica ou grafos).
- **Programação Dinâmica**: não há armazenamento de subproblemas resolvidos para evitar cálculos repetidos.

### **Conclusão**
O algoritmo se baseia principalmente em **força bruta** para testar todas as possibilidades e usa **backtracking** para explorar as soluções de forma estruturada, eliminando combinações inválidas e voltando atrás quando necessário.

