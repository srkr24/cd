// E –> T E’
// E’ –> + T E’ | e
// T –> F T’
// T’ –> * F T’ | e
// F –> ( E ) | id

#include <stdio.h>
#include <string.h>
char *cursor;

int E(), T(), F(), Eprime(), Tprime();

int main()
{
    char string[100];
    printf("Enter the string: ");
    scanf("%s", string);
    cursor = string;

    if (E() && *cursor == '\0')
        printf("Accepted\n");
    else
        printf("Rejected\n");
}
int E()
{
    printf("%s\t E -> TE'\n", cursor);
    if (T())
    {
        if (Eprime())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int T()
{
    printf("%s\t E -> FT'\n", cursor);
    if (F())
    {
        if (Tprime())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int F()
{
    if (*cursor == '(')
    {
        printf("%s\t E -> (E)", cursor);
        cursor++;
        if (E())
        {
            if (*cursor == ')')
            {
                cursor++;
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        printf("%s\t E -> id\n", cursor);
        if (*cursor == 'i' && *(cursor + 1) == 'd')
        {
            cursor += 2;
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
int Eprime()
{
    if (*cursor == '+')
    {
        printf("%s\t E' -> +TE'\n", cursor);
        cursor++;
        if (T())
        {
            if (Eprime())
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        printf("%s\t E' -> e\n", cursor);
        return 1;
    }
}
int Tprime()
{
    if (*cursor == '*')
    {
        printf("%s\t T' -> *FT'E\n", cursor);
        cursor++;
        if (F())
        {
            if (Tprime())
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        printf("%s\t T' -> e\n", cursor);
        return 1;
    }
}