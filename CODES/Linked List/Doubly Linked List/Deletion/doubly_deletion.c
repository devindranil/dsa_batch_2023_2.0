#include <stdio.h>
#include <stdlib.h>
// define the node
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
//global variable
struct node *head = NULL;
struct node *newNode, *temp, *tail;
struct node *createDoublyLinkedList()
{
    int ch;
    while (1)
    {
        newNode = (struct node *)malloc(sizeof(struct node)); // dynamic mempory allocate
        printf("Enter the data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        newNode->prev = NULL;
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        printf("Do you want to continue then hit (0 or 1)");
        scanf("%d", &ch); // 1 = True 0 = false

        if (ch == 0)
        {
            break;
        }
    }
    return head;
}
// delte form beginning
void deleteFormBeg()
{
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
}
// delete form last node
void deleteLastNode()
{
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp=tail;
        tail->prev->next=NULL;
        tail=tail->prev;
        free(temp);
    }
}
//length of linked list
int length()
{
    int count = 0;
    temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
//delte at any position
/*void deleteAtAnyPos(){
    int pos, i=1, count;
    temp=head;
    printf("Enter the position: ");
    scanf("%d",&pos);
    if(pos==1){
        deleteFormBeg();
    }else if(pos<=0 || pos>(count=length())){
        printf("Invalid position");
        exit(0);
    }else if(pos==(count=length())){
        deleteLastNode();
    }else{
        //at any pos excluding 1st and last
        while(i<pos){
            temp=temp->next;
            i++;
        }
        temp->prev->next=tail;
        temp->next->prev=temp->prev;
        free(temp);
    }
}*/
/*void deleteFromAnyPosition() {
    int pos, i = 1, count;
    printf("Enter the position: ");
    scanf("%d", &pos);
    temp = head;

    if (pos == 1) {
        deleteFormBeg();
    } else {
        count = length();

        if (pos <= 0 || pos > count) {
            printf("Invalid position\n");
            return;
        } else if (pos == count) {
            deleteLastNode();
        } else {
            while (i < pos) {
                temp = temp->next;
                i++;
            }

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
        }
    }
}*/

// forward direction
void traverseLinkedList(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    head = createDoublyLinkedList();
    printf("Forward direction:\n");
    traverseLinkedList(head);
    /*deleteFormBeg();
    printf("After deleting the beginning node:\n");
    traverseLinkedList(head);*/
    printf("After deleting at any pos node:\n");
    deleteFromAnyPosition();
    traverseLinkedList(head);
    return 0;
}