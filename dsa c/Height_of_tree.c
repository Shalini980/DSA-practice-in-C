#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int value) {
    if (value == -1) {
        return NULL; 
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node* insertNode(struct Node* root, int value) {
    struct Node* newNode = createNode(value);
    if (root == NULL) {
        return newNode;
    }

    struct Node* queue[100]; 
    int front = 0, rear = 0;

    queue[rear++] = root;
    while (front < rear) {
        struct Node* temp = queue[front++];
        if (temp->left == NULL) {
            temp->left = newNode;
            return root;
        } else {
            queue[rear++] = temp->left;
        }
        if (temp->right == NULL) {
            temp->right = newNode;
            return root;
        } else {
            queue[rear++] = temp->right;
        }
    }
    return root;
}
void deleteDeepestNode(struct Node* root, struct Node* dNode) {
    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;
    while (front < rear) {
        struct Node* temp = queue[front++];
        if (temp->left) {
            if (temp->left == dNode) {
                temp->left = NULL;
                free(dNode);
                return;
            } else {
                queue[rear++] = temp->left;
            }
        }
        if (temp->right) {
            if (temp->right == dNode) {
                temp->right = NULL;
                free(dNode);
                return;
            } else {
                queue[rear++] = temp->right;
            }
        }
    }
}
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL) {
        if (root->data == key) {
            free(root);
            return NULL;
        } else {
            return root;
        }
    }

    struct Node* keyNode = NULL;
    struct Node* temp;
    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;
    while (front < rear) {
        temp = queue[front++];
        if (temp->data == key) {
            keyNode = temp;
        }
        if (temp->left) {
            queue[rear++] = temp->left;
        }
        if (temp->right) {
            queue[rear++] = temp->right;
        }
    }

    if (keyNode != NULL) {
        int x = temp->data;
        deleteDeepestNode(root, temp);
        keyNode->data = x;
    }

    return root;
}
int findHeight(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}
int findSize(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + findSize(root->left) + findSize(root->right);
}
bool search(struct Node* root, int key) {
    if (root == NULL) {
        return false;
    }
    if (root->data == key) {
        return true;
    }
    return search(root->left, key) || search(root->right, key);
}
void displayTree(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;
    while (front < rear) {
        struct Node* temp = queue[front++];
        printf("%d ", temp->data);
        if (temp->left) {
            queue[rear++] = temp->left;
        }
        if (temp->right) {
            queue[rear++] = temp->right;
        }
    }
    printf("\n");
}

int main() {
    struct Node* root = NULL;
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] != -1) {
            root = insertNode(root, arr[i]);
        }
    }

    int choice, value;
    while (1) {
        printf("\nPress:\n1 to insert a node\n2 to delete a node\n3 to exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            scanf("%d", &value);
            root = insertNode(root, value);
        } else if (choice == 2) {
            scanf("%d", &value);
            root = deleteNode(root, value);
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    printf("Tree: ");
    displayTree(root);
    printf("Height of tree: %d\n", findHeight(root));
    printf("Number of nodes in tree: %d\n", findSize(root));

    return 0;
}