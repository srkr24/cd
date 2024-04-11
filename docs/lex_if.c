#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isdelim(char c)
{
    if (c == ' ' || c == '(')
        return 1;
    return 0;
}

void main()
{
    char code[100];
    char token_count = 0;
    int i = 0;

    printf("enter the code: ");
    fgets(code,sizeof(code), stdin);

    while (i < strlen(code))
    {
        if (strncmp("if", &code[i], 2) == 0 && isdelim(code[i + 2]))
        {
            printf("if\n");
            token_count++;
            i += 3;
        }
        else if (strncmp("while", &code[i], 5) == 0 && isdelim(code[i + 5]))
        {
            printf("while\n");
            token_count++;
            i += 6;
        }
        else if (strncmp("for", &code[i], 3) == 0 && isdelim(code[i + 3]))
        {
            printf("for\n");
            token_count++;
            i += 4;
        }
        else
        {
            i++;
        }
    }
    printf("total tokens: %d\n", token_count);
}