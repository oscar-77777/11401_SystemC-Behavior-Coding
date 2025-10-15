#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *exeName = argv[0];

    // Find the last path separator ('\' for Windows, '/' for Linux/Mac)
    char *lastSlash = strrchr(exeName, '\\');
    if (!lastSlash) {
        lastSlash = strrchr(exeName, '/');
    }
    if (lastSlash) {
        exeName = lastSlash + 1; // Point after the last separator
    }

    // Remove the .exe extension (Windows only)
    char nameOnly[100];
    strcpy(nameOnly, exeName);
    char *dot = strrchr(nameOnly, '.');
    if (dot && strcmp(dot, ".exe") == 0) {
        *dot = '\0'; // Replace '.' with the end of the string
        }
        
    printf("%s says ", nameOnly);
    printf("Hello World!\n");
    return 0;
}

