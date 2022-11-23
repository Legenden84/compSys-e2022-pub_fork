#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <assert.h>

size_t file_size(FILE* f) {
    assert(fseek(f, 0, SEEK_END) == 0);
    int end = ftell(f);
    assert(fseek(f, 0, SEEK_SET) == 0);
    return end;
}

int main(int argc, char** argv) {
    assert(argc == 2);
    char *filename = argv[1];

    FILE* f = fopen(filename, "a+");
    assert(f != NULL);

    int len = file_size(f);

    unsigned char *p = 
        mmap(NULL, 
        len, 
        PROT_READ | PROT_WRITE, 
        MAP_SHARED, 
        fileno(f), 
        0);
    fclose(f);

    p[0] += 1;
    p[1] += 6;
    p[3] -= 14;
}