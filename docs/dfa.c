#include<stdio.h>
//(a+aa*b)*  = {e,a,ab, aab, aaab}
void main(){
    char input[100];
    int state = 0;
    printf("enter string: ");
    scanf("%s", input);

    int i = 0;
    while(input[i] != '\0'){
        if(state == 0 && input[i] == 'a'){
            state = 1;
            i++;
        }
        else if(state == 0 && input[i] == 'b'){
            state = 4;
            i++;
        }
        else if(state == 1 && input[i] == 'a'){
            state = 2;
            i++;
        }
        else if(state == 1 && input[i] == 'b'){
            state = 3;
            i++;
        }
        else if(state == 2 && input[i] == 'a'){
            state = 2;
            i++;
        }
        else if(state == 2 && input[i] == 'b'){
            state = 3;
            i++;
        }
        else if(state == 3 && (input[i] == 'a' || input[i] == 'b')){
            state = 4;
            i++;
        }
        else if(state == 4 && (input[i] == 'a' || input[i] == 'b')){
            state = 4;
            i++;
        }
        else{
            printf("Invalid string\n");
            break;
        }
    }
    if(state == 1 || state == 3)
        printf("string accepted\n");
    else 
        printf("string rejected\n");
}