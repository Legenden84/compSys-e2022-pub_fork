#include <stdio.h>

int main() {
    int x = 100;
    int rc = fork();
    if (rc == 0) {
        printf("child: %d\n", ++x);
    } else {
        printf("parent: %d\n", --x);
    }
}