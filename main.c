#include "operacoes.h"

int main() {
    int numbers1[] = {1, 3, 7, 10, 25, 50};
    int numbers2[] = {2, 4, 6, 8, 10, 12};
    int numbers3[] = {5, 10, 15, 20, 25, 30};
    int numbers4[] = {1, 2, 3, 4, 5, 6};
    int numbers5[] = {25, 50, 75, 100, 3, 6};


    printf("Test case 1:\n");
    solve(numbers1, 6, 765);

    printf("\nTest case 2:\n");
    solve(numbers2, 6, 24);

    printf("\nTest case 3:\n");
    solve(numbers3, 6, 100);

    printf("\nTest case 4:\n");
    solve(numbers4, 6, 21);

    printf("\nTest case 5:\n");
    solve(numbers5, 6, 952);

    printf("\nTest case 6:\n");
    solve(numbers1, 6, 831);

    return 0;
}
