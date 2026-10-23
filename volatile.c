#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void debugConsole() {

    size_t inputSize = 10;
    char* input = (char*) malloc(inputSize * sizeof(char));

    printf("[+] available commands: process, whoami, id\n ");

    if (fgets(input, inputSize, stdin) == NULL) {
        printf("[!] unable to process this cmd\n");
        exit(1);
    }

    input[strlen(input) - 1] = '\0';

    size_t commandSize = 255;
    char* command = (char *) malloc(commandSize * sizeof(command));

    sprintf(command, "./console.sh '%s'", input);

    system(command);
}

int main() {

    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    char secret[] = "raffa moreira c ta sabendo bcraff bro o criador do trap brasileiro 777";

    printf("[*] secret: ");

    size_t secretInputSize = 255;
    char* secretInputBuffer = (char *) malloc(secretInputSize * sizeof(char));

    if(fgets(secretInputBuffer, secretInputSize, stdin) == NULL) {
        printf("[!] unable to parse this secret\n");
        return 1;
    }

    secretInputBuffer[strlen(secretInputBuffer) - 1] = '\0';

    if(strcmp(secretInputBuffer, secret)) {
        size_t outputBufferSize = 255;
        char* outputBuffer = (char *) malloc(outputBufferSize * sizeof(char));

        sprintf(outputBuffer, "[!] invalid secret: %s\n", secretInputBuffer);

        printf(outputBuffer);

        return 1;
    }

    debugConsole();

    return 0;
}
