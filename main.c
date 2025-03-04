#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <direct.h>
    #define CREATE_DIR(path) _mkdir(path)
#else
    #include <sys/stat.h>
    #include <sys/types.h>
    #define CREATE_DIR(path) mkdir(path, 0777)
#endif

#include "operacoes.h"
#include "gerador.h" 

#define NUM_INSTANCIAS 100
#define DIR_NAME "instancias" // Nome da pasta onde serão salvos os arquivos
#define RESULT_FILE "instancias/resultados.txt" // Nome do arquivo de resultados

void run_test(int numbers[], int size, int target, int test_case, double *total_time, FILE *result_file) {
    clock_t start, end;
    double cpu_time_used;

    fprintf(result_file, "\nTest case %d:\n", test_case);
    fprintf(result_file, "Números: ");
    for (int i = 0; i < size; i++) {
        fprintf(result_file, "%d ", numbers[i]);
    }
    fprintf(result_file, "\nAlvo: %d\n", target);

    start = clock(); 
    int resultado = solve(numbers, size, target); // Supondo que solve retorna um resultado
    end = clock(); 

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; 
    fprintf(result_file, "Resultado: %d\n", resultado);
    fprintf(result_file, "Tempo de execução: %f segundos\n\n", cpu_time_used);

    *total_time += cpu_time_used;
}

int main() {
    double tempo_total = 0.0; // Para armazenar o tempo total

    // Criar o diretório se não existir
    #ifdef _WIN32
        _mkdir(DIR_NAME);
    #else
        mkdir(DIR_NAME, 0777);
    #endif

    // Abre o arquivo de resultados para escrita
    FILE *result_file = fopen(RESULT_FILE, "w");
    if (result_file == NULL) {
        printf("Erro ao criar arquivo de resultados!\n");
        return 1;
    }

    fprintf(result_file, "Resultados das Instâncias\n");
    fprintf(result_file, "=========================\n");

    for (int i = 0; i < NUM_INSTANCIAS; i++) {
        char filename[100];
        sprintf(filename, "%s/instancia_%d.txt", DIR_NAME, i); // Caminho correto

        gerar_instancia(filename); // Gera uma instância aleatória

        // Lendo a instância do arquivo gerado
        FILE *file = fopen(filename, "r");
        if (file == NULL) {
            printf("Erro ao abrir o arquivo de entrada %s!\n", filename);
            continue;
        }

        int size, target;
        fscanf(file, "%d", &size);

        int numbers[size];
        for (int j = 0; j < size; j++) {
            fscanf(file, "%d", &numbers[j]);
        }
        fscanf(file, "%d", &target);
        fclose(file);

        // Executa o teste e salva no arquivo de resultados
        run_test(numbers, size, target, i + 1, &tempo_total, result_file);
    }

    // Adiciona os tempos finais ao arquivo de resultados
    fprintf(result_file, "\n============================\n");
    fprintf(result_file, "Tempo total de execução: %f segundos\n", tempo_total);
    fprintf(result_file, "Tempo médio por instância: %f segundos\n", tempo_total / NUM_INSTANCIAS);
    fprintf(result_file, "============================\n");

    // Fecha o arquivo de resultados
    fclose(result_file);

    printf("\nResultados salvos em '%s'\n", RESULT_FILE);

    return 0;
}
