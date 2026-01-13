#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 1000

void replace_word(char* str, const char* search,  char* result, char*replace) {
    char* pos, * start = str;
    result[0] = '\0';

    if (islower(*search)) *replace = toupper(*search);
    while ((pos = strstr(start, search)) != NULL) {
       
        strncat(result, start, pos - start);
        strcat(result, replace);
        start = pos + strlen(search); 
   
    }

    strcat(result, start);
}

int count_occurrences(const char* str, const char* search) {
    int count = 0;
    const char* pos = str;

    while ((pos = strstr(pos, search)) != NULL) {
        count++;
        pos += strlen(search);
    }

    return count;
}


int main(void) {
    char str[MAX_LENGTH], result[MAX_LENGTH], search[100];
    char replace[100];
    printf("Type one line:\n");
    gets(str);

    printf("Type in search-word to capitalize: ");
    scanf("%s", search);
    strcpy(replace, search);

    int count = count_occurrences(str, search);
    replace_word(str, search, result, replace);

    printf("%d matches are capitalized.\n", count);
    printf("Result: %s\n", result);

    return 0;
}
