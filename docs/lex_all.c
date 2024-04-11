#include <stdio.h>
#include <string.h>
#include <ctype.h>
int isDelimiter(char ch) {
    return strchr(",;()[]{}",ch) != NULL;
}
int isOperator(char ch) {
    return strchr("+=*/=><",ch) != NULL;
}
int isKeyword(char* str) {
	int i;
    char* keywords[] = {"if", "else", "while", "for", "int", "float", "char", "return"};
    for ( i = 0; i < 8; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}
int isValidIdentifier(char* str) {
	int i;
    for ( i =0; i < strlen(str); i++) {
        if (!isalnum(str[i]) && str[i] != '_') {
            return 0;
        }
    }
    return 1;
}
int main() {
    char str[100];
    printf("Enter an expression: ");
    gets(str);

    char* token = strtok(str, " ");
    while (token != NULL) {
        if (isDelimiter(token[0])) {
            printf("Delimiter: %s\n", token);
        } else if (isOperator(token[0])) {
            printf("Operator: %s\n", token);
        } else if (isKeyword(token)) {
            printf("Keyword: %s\n", token);
        } else if (isdigit(token[0])) {
            printf("constant: %s\n", token);
        } else if (isValidIdentifier(token)) {
            printf("Identifier: %s\n", token);
        } else {
            printf("Unknown: %s\n", token);
        }
        token = strtok(NULL, " ");
    }

    return 0;
}