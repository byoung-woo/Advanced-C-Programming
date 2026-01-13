#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main(void) {
    FILE* fp;
    char filename[100], buffer[1024], search[100];
    int bytes = 0, words = 0, lines = 0;
    int find = 0;

    printf("File to read: ");
    scanf("%s", filename);

    printf("Word to search(non-casesensitive): ");
    scanf("%s", search);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "파일 %s을 열 수 없습니다.\n", filename);
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), fp)) {
        lines++;
        
        for (int i = 0; i < strlen(buffer); i++) {
            if (isupper(buffer[i])) buffer[i] = tolower(buffer[i]);
            if (buffer[i] != '\n') {
                bytes++;
            }
        }
       
        char* token = strtok(buffer, " .,\n");
        while (token != NULL) {
            words++;
            if (strcmp(token, search) == 0) {
                find++;
            }
            token = strtok(NULL, " ,.\n");
            
        }
    }

    fclose(fp);

    printf("Number of lines = %d\n", lines);
    printf("Number of searchword found = %d\n", find);
    printf("Number of characters without enter key = %d\n", bytes);
    printf("Number of word = %d\n", words);



    return 0;
}
