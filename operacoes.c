#include "operacoes.h"


// Converte uma operação em string
const char* op_to_string(Op op) {
    switch (op) {
        case ADD: return "+";
        case SUB: return "-";
        case MUL: return "*";
        case DIV: return "/";
        default: return "?";
    }
}

// Verifica se uma operação é válida
bool is_valid(Op op, int x, int y) {
    switch (op) {
        case ADD: return 1;
        case SUB: return x > y;  
        case MUL: return x != 1 && y != 1;  
        case DIV: return y != 1 && x % y == 0;  
        default: return false;
    }
}

// Cria uma nova expressão matemática
Expr* create_expr(int value, Op op, Expr* left, Expr* right) {
    Expr* expr = (Expr*)malloc(sizeof(Expr));
    expr->value = value;
    expr->op = op;
    expr->left = left;
    expr->right = right;
    return expr;
}

// Aplica uma operação matemática
int apply(Op op, int x, int y) {
    switch (op) {
        case ADD: return x + y;
        case SUB: return x - y;
        case MUL: return x * y;
        case DIV: return x / y;
        default: return 0;
    }
}

// Imprime uma expressão matemática
void print_expr(Expr* expr) {
    if (!expr) return;
    if (!expr->left && !expr->right) {
        printf("%d", expr->value);
    } else {
        printf("(");
        print_expr(expr->left);
        printf(" %s ", op_to_string(expr->op));
        print_expr(expr->right);
        printf(")");
    }
}

// Libera a memória alocada para a expressão matemática
void free_expr(Expr* expr) {
    if (!expr) return;
    free_expr(expr->left);
    free_expr(expr->right);
    free(expr);
}

// Função recursiva para encontrar o melhor resultado possível
void find_best(int numbers[], int size, int target, BestResult* best) {
    if (size == 1) {
        int diff = abs(numbers[0] - target);
        if (diff < best->best_diff) {
            best->best_diff = diff;
            best->best_value = numbers[0];

            free_expr(best->best_expr);
            best->best_expr = create_expr(numbers[0], 0, NULL, NULL);
        }
        return;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) continue;

            int new_numbers[size - 1];
            int index = 0;
            for (int k = 0; k < size; k++) {
                if (k != i && k != j) {
                    new_numbers[index++] = numbers[k];
                }
            }

            for (Op op = ADD; op <= DIV; op++) {
                if (!is_valid(op, numbers[i], numbers[j])) continue;

                int result = apply(op, numbers[i], numbers[j]);
                new_numbers[index] = result;

                Expr* left_expr = create_expr(numbers[i], 0, NULL, NULL);
                Expr* right_expr = create_expr(numbers[j], 0, NULL, NULL);
                Expr* new_expr = create_expr(result, op, left_expr, right_expr);

                int diff = abs(result - target);
                if (diff < best->best_diff) {
                    best->best_diff = diff;
                    best->best_value = result;

                    free_expr(best->best_expr);
                    best->best_expr = new_expr;
                } else {
                    free_expr(new_expr);  // Evita vazamento de memória
                }

                find_best(new_numbers, index + 1, target, best);
            }
        }
    }
}


// Resolve o problema e encontra o melhor valor possível para o alvo
void solve(int numbers[], int count, int target) {
    BestResult best = { .best_value = 0, .best_diff = 99999, .best_expr = NULL };
    find_best(numbers, count, target, &best);
    
    printf("Melhor resultado encontrado: %d (Diferença: %d)\n", best.best_value, best.best_diff);
    printf("Expressão correspondente: ");
    print_expr(best.best_expr);
    printf("\n");

    free_expr(best.best_expr);
}
