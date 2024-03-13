#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_TRAINS 2
#define MAX_TRAIN_PRIORITY 3

// Estrutura para representar um trem
typedef struct {
    int id;
    int priority;
    char origin;
    char destination;
    char state;
} Train;

// Semáforos para o cruzamento e para controlar o acesso à região crítica
sem_t crossingSemaphore;
sem_t criticalRegionSemaphore;

// Variável para controlar o ID do próximo trem a cruzar
int nextTrainId = 0;

// Função para simular o comportamento de um trem
void* train_behavior(void* arg) {
    Train* train = (Train*)arg;

    // Simula o comportamento do trem
    printf("Trem %d (Prioridade %d) está se aproximando do cruzamento vindo de %c1 e indo para %c2.\n",
           train->id, train->priority, train->origin, train->destination);
    sleep(1); // Simula o tempo que o trem leva para se aproximar

    // Aguarda o semáforo de cruzamento
    sem_wait(&crossingSemaphore);

    // Acessa a região crítica para cruzar o cruzamento
    sem_wait(&criticalRegionSemaphore);
    if (train->id == nextTrainId) {
        printf("Trem %d está cruzando o cruzamento.\n", train->id);
        nextTrainId++; // Atualiza o ID do próximo trem a cruzar
    }
    sem_post(&criticalRegionSemaphore);

    // Libera o semáforo de cruzamento
    sem_post(&crossingSemaphore);

    // Exibe a mensagem de que o trem cruzou o cruzamento
    printf("Trem %d cruzou o cruzamento.\n", train->id);

    // Libera a memória alocada para o trem
    free(train);

    return NULL;
}

int main() {
    pthread_t threads[NUM_TRAINS];

    // Inicializa os semáforos
    sem_init(&crossingSemaphore, 0, 1);
    sem_init(&criticalRegionSemaphore, 0, 1);

    // Cria os trens com prioridades diferentes
    for (int ii = 0; ii < NUM_TRAINS; ii++) {
        Train* train = (Train*)malloc(sizeof(Train));
        train->id = ii;
        train->priority = (NUM_TRAINS - ii) % MAX_TRAIN_PRIORITY + 1; // Prioridade decrescente para cada trem
        train->origin = ii % 2 == 0 ? 'A' : 'B'; // Alternando entre origem A1 (A) e B1 (B)
        train->destination = ii % 2 == 0 ? 'A' : 'B'; // Alternando entre destino A2 (A) e B2 (B)
        train->state = 'A'; // 'A' para se aproximando do cruzamento
        pthread_create(&threads[ii], NULL, train_behavior, (void*)train);
    }

    // Aguarda a finalização das threads
    for (int i = 0; i < NUM_TRAINS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Libera os semáforos
    sem_destroy(&crossingSemaphore);
    sem_destroy(&criticalRegionSemaphore);

    return 0;
}
