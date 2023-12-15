#include <stdio.h>
#include <stdbool.h>
#include<string.h>
bool dfa(char str[])
{
    int state=0, n = strlen(str);
    for(int i=0;i<n;i++)
    {
        switch(state){
            case 0:
                str[i] == 'a' ? state =1 : (state = 3);
                break;
            case 1:
                str[i] == 'a' ? state = 1 : (state = 2);
                break;
            case 2:
                str[i] == 'a' ? state = 3 : (state = 2);
                break;
            case 3:
                str[i] == 'a' ? state = 3 : (state = 3);
                break;
            default:
                return false;
                
        }
    }
    return state==2;
    
}
int main() {
    char input[100];
    printf("enter expression:");
    scanf("%s",input);
    if(dfa(input))
    {
        printf("accepted");
    }
    else
    {
        printf("not accepted");
    }
    return 0;
}
