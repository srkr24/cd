#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int i, l, s;
    int paran_bal = 0;
    char ch[50];
    printf("enter expression:");
    scanf("%s", ch);
    l = strlen(ch);
    for (i = 0; i < l; i++)
    {
        if (isalpha(ch[i]) && isalpha(ch[i + 1]) || isalnum(ch[i]) && ch[i - 1] == ')' || isalnum(ch[i]) && ch[i + 1] == '(') // ab, a(, )a are invalid
        {
            s = 0;
            break;
        }
        if (ch[i] == '+' || ch[i] == '-' || ch[i] == '/' || ch[i] == '*' || ch[i] == '%') // need a operand on either side
        {
            if (isalnum(ch[i - 1]) && isalnum(ch[i + 1]) || ch[i - 1] == ')' || ch[i + 1] == '(')
            {
                s = 1;
            }
            else
            {
                s = 0;
            }
        }
        if(ch[i] == '(') // empty brackets
        {
            paran_bal++;
        }
        if(ch[i] == ')')
        { 
            paran_bal--;
        }
    }
    if (s == 1 && paran_bal == 0)
    {
        printf("valid");
    }
    else
    {
        printf("invalid");
    }
}