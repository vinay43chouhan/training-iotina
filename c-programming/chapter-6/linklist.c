#include <stdio.h>
#include <stdlib.h>

#define INSERT_BEGIN 1
#define INSERT_END 2
#define INSERT_POSITION 3
#define SEARCH 4
#define DELETE_BEGIN 5
#define DELETE_END 6
#define EXIT 7
#define DELETE_POSITION 8
#define LENGTH 9
#define MID 10
#define MIN 11
#define MAX 12
#define PRINT 13

typedef struct linklist *Ptr;

typedef struct linklist{
    int data;
    Ptr next;
} LinkList;

int lengthOfLinkList(Ptr head);
Ptr addNodeAtEnd(Ptr head, int number);
Ptr addNodeAtBegin(Ptr head, int number);
Ptr addNodeAtPosition(Ptr head, int number, int position);
void print_list(Ptr head);
Ptr deleteNodeFromBegin(Ptr head);
Ptr deleteNodeFromEnd(Ptr head);
Ptr deleteNodeFromPosition(Ptr head, int position);
Ptr findMidNode(Ptr head);
int searchNode(Ptr head, int node_value);
Ptr minValueNode(Ptr head);
Ptr maxValueNode(Ptr head);


int main(){
    int flag = 0;
    int number = 0;
    int position = 0;
    Ptr head = NULL;
    
    while(1) {
        printf("Please enter the operation you want to perform.\n\n  ============= MENU ============= \n\n Enter 1: Insert at begin \t Enter 2: Insert at end \n Enter 3: Insert at position \t Enter 4: Search \n Enter 5: Delete from begin \t Enter 6: Delete from end \n Enter 7: Exit \t\t 8: Delete from position \n 9: Length of linklist \t 10: Mid node \n 11: Minimum element in linklist \t 12: Maximum element in linklist \n 13: Print linklist \n");
        int operation = -1;
        scanf("%d", &operation);
        getchar();
        
        switch (operation)
        {
        case INSERT_BEGIN:
            printf("\nEnter a number you want to add at the front of the linklisted: ");
            scanf("%d", &number);
            head = addNodeAtBegin(head, number);
            break;

        case INSERT_END:
            printf("\nEnter a number you want to add at the end of the linklisted: ");
            scanf("%d", &number);
            addNodeAtEnd(head, number);
            break;

        case INSERT_POSITION:
            printf("\nEnter the position: ");
            scanf("%d", &position);
            printf("\nEnter a number you want to add at the %d position of the linklisted: ", position);
            scanf("%d", &number);
            addNodeAtPosition(head, number, position);
            break;

        case SEARCH:
            printf("\nEnter a number you want to search: ");
            scanf("%d", &number);
            position = searchNode(head, number);
            position == -1 ? printf("\n%d is not present into the linklist.\n", number) : printf("\n%d is present at %d position", number, position);
            break;

        case DELETE_BEGIN:
            head = deleteNodeFromBegin(head);
            break;

        case DELETE_END:
            head = deleteNodeFromEnd(head);
            break;

        case EXIT:
            flag = 1;
            break;

        case DELETE_POSITION:
            printf("\nEnter the position: ");
            scanf("%d", &position);
            head = deleteNodeFromPosition(head, position);
            break;
        
        case LENGTH:
            printf("Length of linklist: %d\n", lengthOfLinkList(head));
            break;
        
        case MID:
            Ptr mid = findMidNode(head);
            mid == NULL ? printf("\nLinklist does not have mid. it is empty.\n") : printf("%d is mid node of linklist.\n", mid->data);
            break;

        case MIN:
            Ptr min = minValueNode(head);
            min == NULL ? printf("\nIt is empty.\n") : printf("\n%d is minimum value.\n", min->data);
            break;

        case MAX:
            Ptr max = maxValueNode(head);
            max == NULL ? printf("\nIt is empty.\n") : printf("\n%d is minimum value.\n", max->data);
            break;
        
        case PRINT:
            print_list(head);
            printf("\n");
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

int lengthOfLinkList(Ptr head){
    int length = 0;
    Ptr temp = head;
    
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    return length;
}

Ptr addNodeAtBegin(Ptr head, int number){
    Ptr node = (Ptr)malloc(sizeof(LinkList));
    if(node == NULL){
        printf("\nMemory is not allocated.\n");
        return head;
    }
    node->data = number;
    if(head == NULL){
        head = node;
        return head;
    }
    node->next = head;
    head = node;
    return head;
}

Ptr addNodeAtEnd(Ptr head, int number){
    Ptr node = (Ptr)malloc(sizeof(LinkList));
    if(node == NULL){
        printf("\nMemory is not allocated.\n");
        return head;
    }
    node->data = number;
    if(head == NULL){
        head = node;
        return head;
    }
    Ptr temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = node;
    return head;
}

Ptr addNodeAtPosition(Ptr head, int number, int position){
    int len = lengthOfLinkList(head);
    if(len + 1 < position){
        printf("\nLinklist does not have %d element.", position);
        return head;
    }
    if(position == 1){
        return addNodeAtBegin(head, number);;
    }
    if(len+1 == position){
        return addNodeAtEnd(head, number);
    }

    Ptr node = (Ptr)malloc(sizeof(LinkList));
    if(node == NULL){
        printf("\nMemory is not allocated.\n");
        return head;
    }
    node->data = number;
    int index = 1;
    Ptr temp = head;
    while(temp->next != NULL && position-1 != index){
        index++;
        temp = temp->next;
    }
    node->next = temp->next;
    temp->next = node;
    return head;
}

Ptr deleteNodeFromBegin(Ptr head){
    if(head == NULL){
        printf("Nothing to delete.\n");
        return head;
    }
    Ptr node = head;
    printf("\n%d is deleted.\n", head->data);
    head = head->next;
    node->next = NULL;
    free(node);
    return head;
}

Ptr deleteNodeFromEnd(Ptr head){
    if(head == NULL){
        printf("Nothing to delete.\n");
        return head;
    }
    Ptr node = head;
    if(node->next == NULL){
        printf("%d to delete.\n", node->data);
        free(node);
        return NULL;
    }
    while(node->next && node->next->next){
        node = node->next;
    }
    Ptr temp = node->next;
    node->next = NULL;
    printf("%d is deleted.\n", node->data);
    free(temp);
    return head;
}
Ptr deleteNodeFromPosition(Ptr head, int position){
    int len = lengthOfLinkList(head);
    if(head == NULL || position > len){
        printf("Nothing to delete.\n");
        return head;
    }

    if(position == 1){
        return deleteNodeFromBegin(head);
    }
    if(position == len){
        return deleteNodeFromEnd(head);
    }
    int index = 1;
    Ptr temp = head;
    while(temp->next != NULL && position-1 != index){
        index++;
        temp = temp->next;
    }
    Ptr node = temp;
    temp = temp->next;
    node->next = temp->next;
    temp->next = NULL;
    printf("%d to delete.\n", temp->data);
    free(temp);
    return head;

}

Ptr findMidNode(Ptr head){
    int len = lengthOfLinkList(head);
    int mid_index = (len+1)/2;
    
    Ptr temp = head;
    while(temp && --mid_index > 0){
        temp = temp->next;
    }
    return temp;
}

int searchNode(Ptr head, int node_value){
    if(head == NULL){
        return -1;
    }
    Ptr temp = head;
    int index = 1;
    while(temp){
        if(temp->data == node_value){
            return index;
        }
        index++;
        temp = temp->next;
    }
    return -1;
}

Ptr minValueNode(Ptr head){
    if(head == NULL){
        return head;
    }
    Ptr minNode = head;
    Ptr temp = head;
    while(temp->next != NULL){
        if(temp->next->data < minNode->data){
            minNode = temp->next;
        }
        temp = temp->next;
    }
    return minNode;
}

Ptr maxValueNode(Ptr head){
    if(head == NULL){
        return head;
    }
    Ptr maxNode = head;
    Ptr temp = head;
    while(temp->next != NULL){
        if(temp->next->data > maxNode->data){
            maxNode = temp->next;
        }
        temp = temp->next;
    }
    return maxNode;
}

void print_list(Ptr head){
    Ptr temp = head;  
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    return;
}

