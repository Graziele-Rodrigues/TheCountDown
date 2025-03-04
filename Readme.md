# Resolução do The Count Down Problem

## Descrição do Projeto

Este projeto implementa um algoritmo que encontra a melhor combinação de operações matemáticas para aproximar um número-alvo a partir de um conjunto de números dados. O código utiliza **força bruta** combinada com **backtracking** para explorar todas as possibilidades e selecionar a melhor solução.

## Estrutura do Código

### Arquivos

- `main.c`: Contém os testes do algoritmo.
- `operacoes.h`: Declaração das funções e estruturas utilizadas.
- `operacoes.c`: Implementação das operações matemáticas e do algoritmo de busca da melhor solução.
- `gerador.h` e `gerador.c`: Responsáveis por gerar instâncias aleatórias do problema.

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

#### `int solve(int numbers[], int count, int target)`

Inicia a busca pela melhor solução e retorna os resultados.

## Geração de Instâncias

O programa gera instâncias aleatórias contendo um conjunto de números e um número-alvo para o problema. Cada instância é salva na pasta `instancias/` com o formato `instancia_X.txt`, onde `X` é o índice da instância gerada.

As instâncias são geradas pelo arquivo `gerador.c`, que:

- Escolhe aleatoriamente um conjunto de números pequenos (1 a 10) e grandes (25, 50, 75, 100).
- Define um número-alvo aleatório.
- Salva essas informações em um arquivo de texto.

Exemplo de arquivo de instância:

```
6
1 3 7 25 50 100
438
```

## Medindo o Tempo de Execução

O programa mede o tempo de execução de cada instância utilizando a função `clock()`. O tempo total e o tempo médio por instância são calculados e armazenados em um arquivo chamado `resultados.txt` dentro da pasta `instancias/`.

O arquivo `resultados.txt` contém:

- Os números e o alvo de cada instância.
- O resultado obtido pelo algoritmo.
- O tempo de execução para cada teste.
- O tempo total e o tempo médio de execução.

Exemplo de saída no arquivo `resultados.txt`:

```
Test case 1:
Números: 1 3 7 25 50 100
Alvo: 438
Resultado: 437
Tempo de execução: 0.002134 segundos

...

============================
Tempo total de execução: 0.213456 segundos
Tempo médio por instância: 0.002134 segundos
============================
```

## Compilação e Execução Linux

Para compilar o código é preciso ter o `gcc` instalado e executar os seguintes comandos:

```sh
 gcc main.c operacoes.c gerador.c -o programa
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

### **2. Backtracking**

O algoritmo utiliza **backtracking** para evitar cálculos desnecessários:

- Em cada nível da recursão, escolhe um par de números, aplica uma operação e continua testando com o novo conjunto reduzido.
- Caso uma operação não leve a uma solução melhor, ele "desfaz" aquela escolha e tenta outras combinações.

O backtracking ocorre na função `find_best()`, que:

- Escolhe dois números, aplica uma operação e reduz o conjunto.
- Continua o processo até que reste apenas um número.
- Se um caminho não leva a uma melhor solução, volta atrás e tenta outra possibilidade.

### **Conclusão**

O algoritmo se baseia principalmente em **força bruta** para testar todas as possibilidades e usa **backtracking** para explorar as soluções de forma estruturada, eliminando combinações inválidas e voltando atrás quando necessário.

