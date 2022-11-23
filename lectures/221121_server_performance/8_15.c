#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void try() {
    if (fork() == 0) {
        fork();
        fork();
        printf("Example\n");
        return;
    }
    return;
}

int main() {
    try();
    printf("Example\n");
    exit(0);
}