#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

static inline unsigned char pattern_at(size_t k) {
    // Repeating pattern: 'A'..'Z', then '1'..'9'
    static const char *AtoZ = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // 26
    static const char *oneToNine = "123456789";              // 9
    size_t idx = k % (26 + 9);
    if (idx < 26) return (unsigned char)AtoZ[idx];
    return (unsigned char)oneToNine[idx - 26];
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <bytes>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]); // per spec: do not validate integer-ness
    if (N < 0) {
        fprintf(stderr, "Negative size is not allowed.\n");
        return 1;
    }
    size_t nbytes = (size_t)N;

    void *mem = malloc(nbytes);
    if (!mem && nbytes != 0) {
        perror("malloc");
        return 1;
    }

    // Fill with pattern via char* and for loop
    unsigned char *cp = (unsigned char*)mem;
    for (size_t i = 0; i < nbytes; ++i) {
        cp[i] = pattern_at(i);
    }

    // Print exactly N bytes as a string (no implicit terminator)
    printf("%.*s\n", (int)nbytes, (const char*)cp);

    // Interpret as int* with guard (only full integers)
    size_t nints = nbytes / sizeof(int);
    int *ip = (int*)mem;
    size_t i = 0;
    while (i < nints) {
        int v = ip[i];
        printf("%d : %d\n", v, v - 1);
        ++i;
    }

    free(mem);
    return 0;
}
