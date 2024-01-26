//일단 create랑 insert_node, print_bst까지만 만들었음
//다른건 나중에 추가할게요...

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} node;

typedef struct BST { //이거 구조체 안만들었어도 됐을거같은데.. 너무 나중에 알았음
    node* parent;
}bst;

bst* create_bst() {
    bst* new_bst = malloc(sizeof(bst));
    if (new_bst == NULL) {
        printf("NOT ENOUGH MEMORY");
    }
    else {
        new_bst->parent = NULL;
        return new_bst;
    }
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
void print_bst(node* parent) {
    if (parent == NULL) {
        printf("NO DATA");
    }
    else {
        
        printf("%d", parent->key);
        if (parent->left != NULL || parent->right != NULL)
        {
            printf("(");
            if (parent->left != NULL) {
                print_bst(parent->left);
            }
            if (parent->right != NULL) {
                printf(",");
                print_bst(parent->right);
            }
            printf(")");
            
        }
        
    }
}
   
int main() { // 메인함수 그냥 내가 대충 만듦
    bst* the_bst = create_bst();
    int pick;
    while (1) {

        printf("select the menu:\n");
        printf("1.insert data in the bst\n");
        printf("2.print the bst\n");
        scanf_s("%d", &pick);

        switch (pick)
        {
        case 1:
            printf("input the data:");
            int data;
            scanf_s("%d", &data);
            insert_node(the_bst, data);
            printf("(");
            print_bst(the_bst->parent);
            printf(")");
            break;

        case 2:
            printf("------------\n");
            printf("the bst:");
            printf("(");
            print_bst(the_bst->parent);
            printf(")");
            break;

        default:
            break;
        }
    }
}
