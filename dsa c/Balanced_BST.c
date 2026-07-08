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

void inorder(struct Node* root, int* arr, int* index) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, arr, index);
    arr[*index] = root->data;
    (*index)++;
    inorder(root->right, arr, index);
}

struct Node* sortedArrayToBST(int* arr, int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = (start + end) / 2;
    struct Node* root = createNode(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
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

struct Node* findMax(struct Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int n, key;
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] != -1) {
            root = insert(root, arr[i]);
        }
    }
    
    printf("Initial BST: ");
    levelOrder(root);
    printf("\n");
    
    int* inorderArr = (int*)malloc(n * sizeof(int));
    int index = 0;
    inorder(root, inorderArr, &index);
    
    struct Node* balancedRoot = sortedArrayToBST(inorderArr, 0, n - 1);
    
    printf("Balanced BST: ");
    levelOrder(balancedRoot);
    printf("\n");
    
    struct Node* maxNode = findMax(balancedRoot);
    struct Node* minNode = findMin(balancedRoot);
    
    printf("Maximum element: %d\n", maxNode->data);
    printf("Minimum element: %d\n", minNode->data);
    
    return 0;
}
