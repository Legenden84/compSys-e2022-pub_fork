#include <stdio.h>
#include <unistd.h>
#include <assert.h>

int main() {
    FILE *f = fopen("fopen.txt", "r");
    int rc = fork();

    if (rc == 0) {
        char c;    
        int var = fread(&c, sizeof(char), 1, f);
        assert(var == 1);
        printf("childfile: %c\n", c);
        fclose(f);
    } else {
        char p;
        int var = fread(&p, sizeof(char), 1, f);
        assert(var == 1);
        printf("parentfile: %c\n", p);
        fclose(f);
    }
}