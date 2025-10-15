# include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Hello World!\n");
    
    // Loop to print all input variables except the first one (executable name)  
    for (int i = 1; i < argc; i++) {
        printf("%s", argv[i]);

        // Add space between arguments, except for the last one
        if (i < argc - 1) {
            printf(" ");
        }
    }
    
    return(0);
}