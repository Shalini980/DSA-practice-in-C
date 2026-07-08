#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void levelOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    while (front < rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);
        
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}

int findMaxLevel(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    struct Node* queue[100];
    int front = 0, rear = 0;
    int maxNodes = 0, level = 0, currentLevel = 0;
    queue[rear++] = root;
    
    while (front < rear) {
        int nodeCount = rear - front;
        currentLevel++;
        
        if (nodeCount > maxNodes) {
            maxNodes = nodeCount;
            level = currentLevel;
        }
        
        for (int i = 0; i < nodeCount; i++) {
            struct Node* current = queue[front++];
            if (current->left != NULL) {
                queue[rear++] = current->left;
            }
            if (current->right != NULL) {
                queue[rear++] = current->right;
            }
        }
    }
    
    return level;
}

int main() {
    struct Node* root = NULL;
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] != -1) {
            root = insert(root, arr[i]);
        }
    }
    
    printf("BST: ");
    levelOrder(root);
    printf("\n");
    
    int level = findMaxLevel(root);
    printf("Level %d has maximum number of nodes\n", level);
    
    return 0;
}
