//wap to reverse a linked list
#include <stdio.h>
#include <stdlib.h>
// define the node
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *newNode, *temp;
struct node *createLinkedList(){
    int ch;
    while (1)
    {
        newNode = (struct node *)malloc(sizeof(struct node)); // dynamic mempory allocate
        printf("Enter the data: ");
        scanf("%d", &newNode->data);
        newNode->next = 0;
        // head=newNode;
        if (head == NULL)
        {
            //head = newNode;
            head=temp=newNode;
        }
        else
        {
            //head->next = newNode;
            temp->next=newNode;
            temp=newNode;
        }

        printf("Do you want to continue then hit (0 or 1)");
        scanf("%d",&ch); //1 = True 0 = false

        if(ch==0){
            break;
        }
    }
    return head;

}

void reverse()
{
    struct node *prevNode, *currentNode, *nextNode;
    prevNode=NULL;
    currentNode=nextNode=head;
    while(nextNode!=NULL)
    {
        nextNode=nextNode->next;
        currentNode->next=prevNode;
        prevNode=currentNode;
        currentNode=nextNode;
    }
    head=prevNode;
}

void traverseLinkedList(struct node *head){
    struct node *ptr = head;
    while(ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int main()
{
    head = createLinkedList();
    printf("Without reverse a Linked List\n");
    traverseLinkedList(head);
    printf("Linked List after Reverse\n");
    reverse();
    traverseLinkedList(head);
    return 0;
}