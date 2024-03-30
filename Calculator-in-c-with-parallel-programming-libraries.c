#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>
#include <pthread.h>
#include <locale.h>
// Estrutura spros argumentos das threads
typedef struct {
    int a;
    int b;
    int result;
} ThreadArgs;

// Função para calcular o logaritmo
void *calcLog(void *args) {
    ThreadArgs *data = (ThreadArgs *)args;
    data->result = log(data->a);
    pthread_exit(NULL);
}

// Função para calcular a divisão inteira
void *calcDivInt(void *args) {
    ThreadArgs *data = (ThreadArgs *)args;
    data->result = data->a / data->b;
    pthread_exit(NULL);
}

// Função para calcular o resto da divisão
void *calcRestDiv(void *args) {
    ThreadArgs *data = (ThreadArgs *)args;
    data->result = data->a % data->b;
    pthread_exit(NULL);
}

// Função para realizar a adição
void *calcAddition(void *args) {
    ThreadArgs *data = (ThreadArgs *)args;
    data->result = data->a + data->b;
    pthread_exit(NULL);
}

// Função para realizar a subtração
void *calcSubtraction(void *args) {
    ThreadArgs *data = (ThreadArgs *)args;
    data->result = data->a - data->b;
    pthread_exit(NULL);
}

// Função para realizar a multiplicação
void *calcMultiplication(void *args) {
    ThreadArgs *data = (ThreadArgs *)args;
    data->result = data->a * data->b;
    pthread_exit(NULL);
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    int pergunta = 0;
    int numThreads = 2; // Número de threads
    pthread_t threads[numThreads];
    ThreadArgs args[numThreads];

    do {
        printf("Calculadora Digital\n");
        printf("Operações suportadas: \n1-logaritmo\t2-Divisão Inteira\t3-Resto da divisão");
        printf("\n4-Adição\t5-Subtração\t\t6-Multiplicação\t\t7-Sair\n");
        printf("Escolha: ");
        scanf("%d", &pergunta);

        switch (pergunta) {
            case 1:
                printf("Digite o número para calcular o logaritmo: ");
                scanf("%d", &args[0].a);

                pthread_create(&threads[0], NULL, calcLog, (void *)&args[0]);
                pthread_join(threads[0], NULL);

                printf("Resultado: %d\n", args[0].result);
                break;

            case 2:
                printf("Digite o dividendo: ");
                scanf("%d", &args[0].a);
                printf("Digite o divisor: ");
                scanf("%d", &args[0].b);

                pthread_create(&threads[0], NULL, calcDivInt, (void *)&args[0]);
                pthread_join(threads[0], NULL);

                printf("Resultado: %d\n", args[0].result);
                break;

            case 3:
                printf("Digite o dividendo: ");
                scanf("%d", &args[0].a);
                printf("Digite o divisor: ");
                scanf("%d", &args[0].b);

                pthread_create(&threads[0], NULL, calcRestDiv, (void *)&args[0]);
                pthread_join(threads[0], NULL);

                printf("Resultado: %d\n", args[0].result);
                break;

            case 4:
                printf("Digite o primeiro número: ");
                scanf("%d", &args[0].a);
                printf("Digite o segundo número: ");
                scanf("%d", &args[0].b);

                pthread_create(&threads[0], NULL, calcAddition, (void *)&args[0]);
                pthread_join(threads[0], NULL);

                printf("Resultado: %d\n", args[0].result);
                break;

            case 5:
                printf("Digite o primeiro número: ");
                scanf("%d", &args[0].a);
                printf("Digite o segundo número: ");
                scanf("%d", &args[0].b);

                pthread_create(&threads[0], NULL, calcSubtraction, (void *)&args[0]);
                pthread_join(threads[0], NULL);

                printf("Resultado: %d\n", args[0].result);
                break;

            case 6:
                printf("Digite o primeiro número: ");
                scanf("%d", &args[0].a);
                printf("Digite o segundo número: ");
                scanf("%d", &args[0].b);

                pthread_create(&threads[0], NULL, calcMultiplication, (void *)&args[0]);
                pthread_join(threads[0], NULL);

                printf("Resultado: %d\n", args[0].result);
                break;

            case 7:
                printf("Saindo...\n");
                break;

            default:
                printf("Operação inválida!\n");
                break;
        }
        printf("\n");
    } while (pergunta != 7);

    return 0;
}
