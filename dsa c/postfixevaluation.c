#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100

int top = -1;
int stack[MAX];
char postfix[MAX];

void push(int data) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = data;
}

int isempty() {
    return top == -1;
}

int pop() {
    if (isempty()) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int evaluatePostfix(char* exp)
{
   
    struct Stack* stack = createStack(strlen(exp));
    int i;
 
    
    if (!stack)
        return -1;
 
   
    for (i = 0; exp[i]; ++i) {
         
        
        if (isdigit(exp[i]))
            push(stack, exp[i] - '0');
 
    
        else {
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (exp[i]) {
            case '+':
                push(stack, val2 + val1);
                break;
            case '-':
                push(stack, val2 - val1);
                break;
            case '*':
                push(stack, val2 * val1);
                break;
            case '/':
                push(stack, val2 / val1);
                break;
            }
        }
    }
    return pop(stack);
}
 
int main() {
    int t;
    scanf("%d", &t);
    getchar();  

    while (t--) {
        fgets(postfix, MAX, stdin);

        // Remove the trailing newline manually
        int len = strlen(postfix);
        if (len > 0 && postfix[len - 1] == '\n') {
            postfix[len - 1] = '\0';
        }

        printf("%d\n", evaluatepostfix(postfix));
    }
    return 0;
}
