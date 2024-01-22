//일단 create랑 insert_node까지만 만들었음
//나중에 다른 것도 할게요.. 힘들어요...

#include <stdio.h>
#include <string.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} node;

typedef struct BST {
    node* parent;
}bst;

bst* create_bst() {
    bst* new_bst = malloc(sizeof(bst));
    if (new_bst == NULL) {
        printf("NOT ENOUGH MEMORY");
    }
    new_bst->parent = NULL;
    return new_bst;
}

node* new_node(const int data)
{
    node* new_data = malloc(sizeof(node));
    if (new_data == NULL) {
        printf("NOT ENOUGH MEMORY");
    }
    new_data->key = data;
    new_data->left = NULL;
    new_data->right = NULL;
    return new_data;
}

void insert_node(bst* new_bst, const int a)
{
    if (new_bst->parent == NULL) {
        new_bst->parent = new_node(a);
    }

    else {
        node* temp = new_bst->parent;
        while (1) {
            if (a <= temp->key) {
                if (temp->left == NULL) {
                    temp->left = new_node(a);
                    break;
                }
                else {
                    temp = temp->left;
                    continue;
                }
            }
            else {
                if (temp->right == NULL) {
                    temp->right = new_node(a);
                    break;
                }
                else {
                    temp = temp->right;
                    continue;
                }
            }

        }
    }
}

