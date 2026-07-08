#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(char data) {
    struct Node* nn = (struct Node*)malloc(sizeof(struct Node));
    nn->data = data;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}


int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}


int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}


struct Node* b(char* ie) {
    struct Node* ptr[100];
    char opr[100];
    int nodeTop = -1, opTop = -1;

    for (int i = 0; ie[i] != '\0'; i++) {
        char c = ie[i];

        if (isalnum(c)) {
    
            ptr[++nodeTop] = createNode(c);
        } else if (c == '(') {
            opr[++opTop] = c;
        } else if (c == ')') {
            while (opTop >= 0 && opr[opTop] != '(') {
                char op = opr[opTop--];
                struct Node* right = ptr[nodeTop--];
                struct Node* left = ptr[nodeTop--];
                struct Node* nn = createNode(op);
                nn->left = left;
                nn->right = right;
                ptr[++nodeTop] = nn;
            }
            opTop--; 
        } else if (isOperator(c)) {
            
            while (opTop >= 0 && precedence(opr[opTop]) >= precedence(c)) {
                char op = opr[opTop--];
                struct Node* right = ptr[nodeTop--];
                struct Node* left = ptr[nodeTop--];
                struct Node* nn = createNode(op);
                nn->left = left;
                nn->right = right;
                ptr[++nodeTop] = nn;
            }
            opr[++opTop] = c; 
        }
    }

    
    while (opTop >= 0) {
        char op = opr[opTop--];
        struct Node* right = ptr[nodeTop--];
        struct Node* left =ptr[nodeTop--];
        struct Node* nn = createNode(op);
        nn->left = left;
        nn->right = right;
        ptr[++nodeTop] = nn;
    }

    
    return ptr[nodeTop];
}


void generatePostfix(struct Node* root) {
    if (root == NULL) return;
    generatePostfix(root->left);
    generatePostfix(root->right);
    printf("%c", root->data);
}


int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        char infix[100];
        scanf("%s", infix);
        struct Node* root = b(infix);
        generatePostfix(root);
        printf("\n");
    }

    return 0;
} 