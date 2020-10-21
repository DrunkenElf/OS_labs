#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define N 5	// Number of threads to create

// Fun for thread
void *thread_func(void *threadid) {
    int tid = (int)threadid;

    printf("Hello from thread #%ld\n", tid);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[N];	// thread ids

    for (int i = 0; i < N; i++) {
        pthread_create(threads+i, NULL, thread_func, (void *)i); // create thread

        pthread_join(threads[i], NULL); // join thread to execute it in created order
    }

    pthread_exit(NULL);
    exit(EXIT_SUCCESS);
}