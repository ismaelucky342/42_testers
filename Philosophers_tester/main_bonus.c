/*
Este programa demuestra el manejo correcto de hilos y semáforos en C, evitando fugas de memoria:

	1. **Hilos**:
	- Crea varios hilos usando `pthread_create`.
	- Algunos hilos son separados (`pthread_detach`) para que se limpien automáticamente.
	- Otros hilos se unen (`pthread_join`) para garantizar su finalización controlada.
	- Se asigna memoria dinámica para los identificadores de los hilos, que se libera dentro de cada hilo.

	2. **Semáforos**:
	- Se crea un semáforo nombrado con `sem_open` para sincronización.
	- Se limpia correctamente utilizando `sem_close` para cerrar el descriptor y `sem_unlink` para eliminar el nombre del semáforo.

	3. **Verificación de recursos**:
	- No hay fugas de memoria si se ejecuta correctamente.
	- Ideal para comprobar con herramientas como `valgrind`.
*/

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define SEM_NAME "/test_semaphore"
#define THREAD_COUNT 5

void *thread_function(void *arg) {
    int id = *(int *)arg;
    printf("Thread %d: Running\n", id);
    sleep(1);
    printf("Thread %d: Finished\n", id);
    free(arg); // Liberar la memoria asignada al ID del hilo
    return NULL;
}

int main() {
    pthread_t threads[THREAD_COUNT];
    sem_t *sem;
    int *thread_id;

    // Crear el semáforo
    sem = sem_open(SEM_NAME, O_CREAT | O_EXCL, 0644, 1);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        exit(EXIT_FAILURE);
    }

    // Crear hilos y demostrar detach y join
    for (int i = 0; i < THREAD_COUNT; i++) {
        thread_id = malloc(sizeof(int));
        if (thread_id == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        *thread_id = i;

        if (pthread_create(&threads[i], NULL, thread_function, thread_id) != 0) {
            perror("pthread_create");
            free(thread_id);
            exit(EXIT_FAILURE);
        }

        if (i % 2 == 0) {
            // Usar detach para algunos hilos
            if (pthread_detach(threads[i]) != 0) {
                perror("pthread_detach");
                exit(EXIT_FAILURE);
            }
        }
    }

    // Unir los hilos no separados
    for (int i = 0; i < THREAD_COUNT; i++) {
        if (i % 2 != 0) {
            if (pthread_join(threads[i], NULL) != 0) {
                perror("pthread_join");
                exit(EXIT_FAILURE);
            }
        }
    }

    // Cerrar y desvincular el semáforo
    if (sem_close(sem) != 0) {
        perror("sem_close");
        exit(EXIT_FAILURE);
    }

    if (sem_unlink(SEM_NAME) != 0) {
        perror("sem_unlink");
        exit(EXIT_FAILURE);
    }

    printf("All threads completed and semaphore cleaned up.\n");
    return 0;
}