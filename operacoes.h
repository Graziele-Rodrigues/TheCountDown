#ifndef OPERACOES_H
#define OPERACOES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição das operações matemáticas
typedef enum { ADD, SUB, MUL, DIV } Op;

// Estrutura para representar expressões matemáticas
typedef struct Expr {
    int value;
    Op op;
    struct Expr* left;
    struct Expr* right;
} Expr;

// Estrutura para armazenar o melhor resultado encontrado
typedef struct {
    int best_value;
    int best_diff;
    Expr* best_expr;
} BestResult;

// Funções auxiliares
const char* op_to_string(Op op);
bool is_valid(Op op, int x, int y);
int apply(Op op, int x, int y);
void print_expr(Expr* expr);
void free_expr(Expr* expr);

// Algoritmo de busca
void find_best(int numbers[], int size, int target, BestResult* best);
void solve(int numbers[], int count, int target);

#endif // OPERACOES_H
