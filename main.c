/*
Autora: Graziele de Cássia Rodrigues
Matricula: 21.1.8120
*/

#include <stdio.h>
#include <time.h>
#include "operacoes.h"

void run_test(int numbers[], int size, int target, int test_case) {
    clock_t start, end;
    double cpu_time_used;

    printf("\nTest case %d:\n", test_case);
    start = clock(); // Início da medição de tempo
    solve(numbers, size, target);
    end = clock(); // Fim da medição de tempo

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // Tempo em segundos
    printf("Tempo de execução: %f segundos\n", cpu_time_used);
}

int main() {
    int numbers1[] = {1, 3, 7, 10, 25, 50};
    int numbers2[] = {2, 4, 6, 8, 10, 12};
    int numbers3[] = {5, 10, 15, 20, 25, 30};
    int numbers4[] = {1, 2, 3, 4, 5, 6};
    int numbers5[] = {25, 50, 75, 100, 3, 6};

    run_test(numbers1, 6, 765, 1);
    run_test(numbers2, 6, 24, 2);
    run_test(numbers3, 6, 100, 3);
    run_test(numbers4, 6, 21, 4);
    run_test(numbers5, 6, 952, 5);
    run_test(numbers1, 6, 831, 6);

    return 0;
}
