#include <stdio.h>
#include <ctype.h>

char stack[50];
int top = -1;

int precedence(char op){
    if(op=='+' || op=='-') return 1;
    if(op=='*' || op=='/') return 2;
    return 0;
}

void push(char x){ stack[++top] = x; }
char pop(){ return stack[top--]; }

int main(){
    char infix[] = "a+b*c";
    char postfix[50];
    int k = 0;

    for(int i=0; infix[i]!='\0'; i++){
        char ch = infix[i];

        if(isalnum(ch))
            postfix[k++] = ch;
        else{
            while(top!=-1 && precedence(stack[top]) >= precedence(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }

    while(top!=-1)
        postfix[k++] = pop();

    postfix[k] = '\0';

    printf("Postfix: %s\n", postfix);
    return 0;
}

