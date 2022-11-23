#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    int wstatus;
    pid_t rc = fork();
    if (rc == 0) {
        printf("child: Hello\n");
    } else {
        waitpid(rc, &wstatus, 0);
        printf("parent: Goodbye\n");
    }
}