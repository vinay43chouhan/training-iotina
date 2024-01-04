#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INSERT 1
#define PRINT 2
#define DELETE 3
#define SEARCH 4
#define LOWEST 5
#define HIGHEST 6
#define EXIT 7
#define LOWEST_NUMBER -100000
#define HIGHEST_NUMBER 100000

// without typedef
/*

struct treeNode {
    int data;
    struct treeNode *left;
    struct treeNode *right;
} Node;

*/
typedef struct treeNode *treePtr;

typedef struct treeNode {
    int data;
    treePtr left;
    treePtr right;
} Node;

typedef struct pair {
    treePtr node;
    treePtr prev;
} Pair;

treePtr insertIntoBinary(treePtr root, int number);
void printTree(treePtr root);
int search(treePtr root, int element, int level);
int lowest_element(treePtr root);
int highest_element(treePtr root);
void delete(treePtr root, int number);
Pair searching(treePtr root, int number, treePtr prev);

int main(){
    int flag = 0;
    int number = 0;
    int element = 0;
    treePtr root = NULL;
    
    while(1) {
        printf("Please enter the operation you want to perform.\n\n  ============= MENU ============= \n\n Enter 1: Insert \n Enter 2: PrintTree \n Enter 3: Delete \n Enter 4: Search \n Enter 5: Lowest \n Enter 6: Highest \n Enter 7: Exit \n");
        int operation = -1;
        scanf("%d", &operation);
        getchar();
        
        switch (operation)
        {
        case INSERT:
            printf("Enter a element to be inserted into binary tree.\n");
            scanf("%d", &number);
            root = insertIntoBinary(root, number);
            break;

        case PRINT:
            printf("======= INORDER PRINT =======\n"); // Inorder of binary tree is sorted ordered
            printTree(root);
            printf("\n");
            break;

        case DELETE:
            printf("Enter a element to be deleted into binary tree.\n");
            scanf("%d", &number);
            delete(root, number);
            break;

        case SEARCH:
            int ele_to_be_searched = 0;
            int level = 0;
            printf("Enter the element you want to search.\n");
            scanf("%d", &ele_to_be_searched);
            level = search(root, ele_to_be_searched, level);
            level == -1  ? printf("Tree doesn't have %d element.\n", ele_to_be_searched): printf("Tree have element %d at %d level.\n", ele_to_be_searched, level);
            break;

        case LOWEST:
            element = lowest_element(root);
            element == HIGHEST_NUMBER ? printf("Tree is empty.\n") : printf("%d is lowest element in tree.\n", element);
            break;

        case HIGHEST:
            element = highest_element(root);
            element == LOWEST_NUMBER ? printf("Tree is empty.\n") : printf("%d is highest element in tree.\n", element);
            break;

        case EXIT:
            flag = 1;
            break;
        
        default:
            break;
        }
        if (flag){
            break;
        }
    }
    return 0;

}

treePtr insertIntoBinary(treePtr root, int number){
    if(root == NULL){
        treePtr node = (treePtr)malloc(sizeof(Node));
        if(node == NULL){
            printf("Memory is not allocated.\n");
            return root;
        }
        node->data = number;
        return node;
    }else if( root->data < number ){
        root->right = insertIntoBinary(root->right, number);
    }else if( root->data > number){
        root->left = insertIntoBinary(root->left, number);
    }
    return root;

}

void printTree( treePtr root ){
    if(root == NULL){
        return;
    }
    printTree(root->left);
    printf(" %d ", root->data);
    printTree(root->right);
}

int search(treePtr root, int element, int level){
    if(root == NULL){
        return -1;
    }
    if(root->data == element){
        return level;
    }else if(root->data > element){
        return search(root->left, element, level+1);
    }else{
        return search(root->right, element, level+1);
    }
    
}

int lowest_element(treePtr root){
    if(root == NULL){
        return HIGHEST_NUMBER;
    }
    int lowest  = root->data;
    int low = lowest_element(root->left);
    return low < lowest ? low : lowest;
}

int highest_element(treePtr root){
    if(root == NULL){
        return LOWEST_NUMBER;
    }
    int highest = highest_element(root->right);
    return highest < root->data ? root->data : highest;
}

void delete(treePtr root, int number){
    treePtr prev = NULL;
    Pair p = searching(root, number, prev);
    if(p.node == NULL){
        printf("Node is not in tree.\n");
        return;
    }
    
    // node is leaf node
    if(p.node->left == NULL &&  p.node->right == NULL){
        if(p.prev == NULL){
            root = NULL;
            return;
        }
        if(p.prev->left == p.node){
            printf("vinay 1");
            p.prev->left = NULL;
            free(p.node);
        }else{
            p.prev->right = NULL;
            free(p.node);
        }
        return;
    }
    // node have one child either left or right
    if(p.node->left != NULL &&  p.node->right == NULL){
        if(p.prev == NULL){
            root = p.node->left;
            p.node->left = NULL;
            return;
        }
        p.prev->left = p.node->left;
        p.node->left = NULL;
        free(p.node);
        return;
    }
    if(p.node->left == NULL &&  p.node->right != NULL){
        if(p.prev == NULL){
            root = p.node->right;
            p.node->right = NULL;
            return;
        }
        p.prev->right = p.node->right;
        p.node->right = NULL;
        free(p.node);
        return;
    }
    // node have both child
    if(p.node->left && p.node->right){
        treePtr parent_succ = p.node;
        treePtr succ = p.node->right;

        while(succ->left != NULL){
            parent_succ = succ;
            succ = succ->left;
        }

        if(parent_succ != p.node){
            parent_succ->left = succ->right;
        }else{
            parent_succ->right = succ->right;
        }
        succ->right = NULL;
        p.node->data = succ->data;
        free(succ);
        return;
    }
}

Pair searching(treePtr root, int number, treePtr parent){
    Pair p;
    if(root == NULL){
        p.node = root;
        p.prev = NULL;
        return p;
    }
    
    if(root->data == number){
        p.node = root;
        p.prev = parent;
        return p;
    }else if(root->data > number){
        if(root->left && root->left->data == number){
            parent = root;
        }
        return searching(root->left, number, parent);
        
    }else{
        if(root->right && root->right->data == number){
            parent = root;
        }
        return searching(root->right, number, parent);
    }
}



