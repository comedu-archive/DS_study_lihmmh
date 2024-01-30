//delete_node 하나 남기고 웬만한 기능 구현은 다했는데
//얜 진짜 오래걸릴거 같아서 다음에 할게요..

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

void inorder_traversal(node* parent) {
    if (parent == NULL) {
        return;
    }
    inorder_traversal(parent->left);
    printf("%d ", parent->key);  
    inorder_traversal(parent->right);
}

void right_root_left_traversal(node* parent) {
    if (parent == NULL) {
        return;
    }
    right_root_left_traversal(parent->right);
    printf("%d ", parent->key);
    right_root_left_traversal(parent->left);
}

void get_min(node* parent) {
    if (parent->left == NULL) {
        printf("%d", parent->key);
        return;
    }
    get_min(parent->left);
}

void get_max(node* parent) {
    if (parent->right == NULL) {
        printf("%d", parent->key);
        return;
    }
    get_min(parent->right);
}
int get() {
    int a;
    printf("which data are you looking for?");
    scanf_s("%d", &a);
    return a;
}

void find_node(node* parent, int node_value) {
    if (parent->key == node_value) {
        return;
    }
    else if (parent->key > node_value) {
        if (parent->left == NULL) {
            printf("NOT EXIST!");
            return;
        }
        printf("left ");
        find_node(parent->left, node_value);
    }
    else if (parent->key < node_value) {
        if (parent->right == NULL) {
            printf("NOT EXIST!");
            return;
        }
        printf("right ");
        find_node(parent->right, node_value);
    }
}
delete_node(node* parent,int node) {
    
}
int main() { // 메인함수 그냥 내가 대충 만듦
    bst* the_bst = create_bst();
    int pick;
    while (1) {

        printf("\nselect the menu:\n");
        printf("1.insert data in the bst\n");
        printf("2.print the bst\n");
        printf("3.inorder the bst\n");
        printf("4.right_root_left_traversal\n");
        printf("5.get min\n");
        printf("6.get max\n");
        printf("7.find node\n");
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
            printf(")\n");
            break;

        case 2:
            printf("------------\n");
            printf("the bst:");
            printf("(");
            print_bst(the_bst->parent);
            printf(")\n");
            break;
        case 3:
            inorder_traversal(the_bst->parent);
            break;
        case 4:
            right_root_left_traversal(the_bst->parent);
            break;
        case 5:
            get_min(the_bst->parent);
            break;
        case 6:
            get_max(the_bst->parent);
            break;
        case 7:
            int a = get(); // 이거 원래 이렇게 하면 안되거든요?
            //근데 메인함수 좀만 고치면 바로 해결되는 부분이라
            //그냥 넘길게요
            printf("root ");
            find_node(the_bst->parent, a);
        default:
            break;
        }
    }
}
