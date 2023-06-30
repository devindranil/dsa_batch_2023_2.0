#include <stdio.h>
#include <stdlib.h>
// define the node
struct node
{
    int data;
    struct node *next;
};

struct node *createCirculareLinkedList(){
    struct node *head = NULL;
    struct node *newNode, *temp;
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
        temp->next=head;

        printf("Do you want to continue then hit (0 or 1)");
        scanf("%d",&ch); //1 = True 0 = false

        if(ch==0){
            break;
        }
    }
    return head;

}

void traverseLinkedList(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next!=head)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("%d",ptr->data);
    }
}
int main()
{
    struct node *head;
    head = createCirculareLinkedList();
    traverseLinkedList(head);
    return 0;
}