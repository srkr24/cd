#include <stdio.h>
#include <ctype.h>
#include <string.h>

int numOfProductions;
char productionSet[10][10];
char result[20];
int m = 0;

void computeFirst(char c)
{
    int i;
    if (!isupper(c))
    { // Terminal case
        result[m++] = c;
    }
    // Non-terminal case
    for (i = 0; i < numOfProductions; i++)
    {
        if (productionSet[i][0] == c)
        {
            if (productionSet[i][2] == '$')
            { // Production X → ε
                result[m++] = '$';
            }
            else if (islower(productionSet[i][2]))
            { // Production X → a..
                result[m++] = productionSet[i][2];
            }
            else
            { // Production X → Y
                computeFirst(productionSet[i][2]);
            }
        }
    }
}

int main()
{
    int i;
    char choice;
    char c;
    printf("How many number of productions? : ");
    scanf("%d", &numOfProductions);

    printf("Enter productions:\n");
    for (i = 0; i < numOfProductions; i++)
    {
        scanf(" %s", productionSet[i]);
    }

    do
    {
        m = 0;
        printf("\nFind the FIRST of: ");
        scanf(" %c", &c);
        computeFirst(c);
        result[m] = '\0';
        printf("\nFIRST(%c) = { %s }\n", c, result);
        printf("Press 'y' to continue: ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
