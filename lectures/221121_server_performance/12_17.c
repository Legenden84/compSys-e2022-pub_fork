#include "csapp.h"
void *thread(void *vargp);

/* Thread routine */
void *thread(void *vargp) {
    Sleep(1);
    printf("Hello, world!\n");
    return NULL;
}

int main() {
    pthread_t tid;
    Pthread_create(&tid, NULL, thread, NULL);
    exit(0);
}