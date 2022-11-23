# Exercises for performant servers

## Exercises from Chapter 8 of Bryant and O'Hallaron on "Control Flow"

* 8.15
How many “Example” lines does this program print?

See 8_15.c

Answer: 9. Forking 3 times. 'if (fork() == 0)' is also considered a folk().

* 8.23
One of your colleagues is thinking of using signals to allow a parent process to
count events that occur in a child process. The idea is to notify the parent each
time an event occurs by sending it a signal and letting the parent’s signal handler
increment a global counter variable, which the parent can then inspect after the
child has terminated. However, when he runs the test program in Figure 8.45 on
his system, he discovers that when the parent calls printf, counter always has a
value of 2, even though the child has sent five signals to the parent. Perplexed, he
comes to you for help. Can you explain the bug?
1
#include "csapp.h"

int counter = 0;

void handler(int sig) {
    counter++;
    sleep(1); /* Do some work in the handler */
    return;
}

int main() {
    int i;
    Signal(SIGUSR2, handler);
    if (Fork() == 0) { /* Child */
        for (i = 0; i < 5; i++) {
            Kill(getppid(), SIGUSR2);
            printf("sent SIGUSR2 to parent\n");
        }
        exit(0);
    }
    Wait(NULL);
    printf("counter=%d\n", counter);
    exit(0);
}


## Exercises from Chapter 12 of Bryant and O'Hallaron on "Concurrent Programming"

* 12.17
A.  The program in Figure 12.46 has a bug. The thread is supposed to sleep for
    1 second and then print a string. However, when we run it on our system,
    nothing prints. Why?
B.  You can fix this bug by replacing the exit function in line 10 with one of two
    different Pthreads function calls. Which ones?
    code/conc/hellobug.c

See 12_17.c for code.
Answer A: Use 'Pthread_join(&tid, NULL);' before exit(0).

* 12.18
Using the progress graph in Figure 12.21, classify the following trajectories as either safe or unsafe.
A. H2 , L2 , U2 , H1, L1, S2 , U1, S1, T1, T2
B. H2 , H1, L1, U1, S1, L2 , T1, U2 , S2 , T2
C. H1, L1, H2 , L2 , U2 , S2 , U1, S1, T1, T2

 T2+--+--+--+--+--+
   |  |  |  |  |  |
 S2+--+--+--+--+--+
   |  |        |  |
 U2+--+ UNSAFE +--+
   |  | REGION |  |
 L2+--+        +--+
   |  |        |  |
 H2+--+--+--+--+--+
   |  |  |  |  |  |
   +--+--+--+--+--+
     H1 L1 U1 S1 T1

* 12.27
Some network programming texts suggest the following approach for reading and
writing sockets: Before interacting with the client, open two standard I/O streams
on the same open connected socket descriptor, one for reading and one for writing:

    FILE *fpin, *fpout;

    fpin = fdopen(sockfd, "r");
    fpout = fdopen(sockfd, "w");

When the server finishes interacting with the client, close both streams as follows:

    fclose(fpin);
    fclose(fpout);

However, if you try this approach in a concurrent server based on threads,
you will create a deadly race condition. Explain.

Answer: Race condiation can happen because each thread shares the same file desciptor table (hence reading/writting to the same vatiables).

* 12.29 (Exam question)

Can the following program deadlock? Why or why not?

Initially: a = 1, b = 1, c = 1.

Thread 1:       Thread 2:
    P(a);           P(c);
    P(b);           P(b);
    V(b);           V(b);
    P(c);           V(c);
    V(c);
    V(a);

En mutex er et specialt tilfælde an en semiphore.

ANSWER: 1) Firstly, draw an process diagram.
        2) Dont consider a, because thread 2 is not using that variable.




## Programming task
In C, create a peer that can act as a client and server at the same time. A Python example has been included which will both send and recieve messages concurrently. Your client should be able to do the same. 

Messages sent between the peers have a simple format. The only element in the header is 4 bytes giving the length of the following body. 