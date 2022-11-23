#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    int wstatus;
    pid_t rc = fork();
    if (rc == 0) {
        waitpid(rc, &wstatus, 0);
        printf("child: Hello\n");
    } else {
        printf("parent: Goodbye\n");
    }
}