#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TARGET 999 // Alvo máximo

void gerar_instancia(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo de instância '%s'!\n", filename);
        return;
    }

    // Inicialização de semente
    srand(time(NULL) ^ (rand() << 16));

    int max_numbers = (rand() % 3) + 4; // Entre 4 e 6 números
    int numbers[max_numbers];

    // Gera números aleatórios (mistura entre pequenos e grandes)
    for (int i = 0; i < max_numbers; i++) {
        if (rand() % 2 == 0) { // 50% de chance de ser um número grande
            int grandes[] = {25, 50, 75, 100};
            numbers[i] = grandes[rand() % 4];
        } else { // 50% de chance de ser um número pequeno
            numbers[i] = (rand() % 10) + 1; // Pequenos de 1 a 10
        }
    }

    
    int target = (rand() % (MAX_TARGET - 100)) + 100; // Evita números muito pequenos

    // Escreve no arquivo
    fprintf(file, "%d\n", max_numbers); // Primeiro, a quantidade de números
    for (int i = 0; i < max_numbers; i++) {
        fprintf(file, "%d ", numbers[i]); // Lista de números
    }
    fprintf(file, "\n%d\n", target); // Número alvo

    fclose(file);
    printf("Instância gerada em '%s'\n", filename);
}
