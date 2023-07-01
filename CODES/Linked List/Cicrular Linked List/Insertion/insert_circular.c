#include <stdio.h>
#include <stdlib.h>
// define the node
struct node
{
    int data;
    struct node *next;
};
struct node *tail = NULL;
struct node *newNode, *temp;
// create circular linked list without head pointer only with tail pointer
struct node *createCirculareLinkedList()
{

    int ch;
    while (1)
    {
        newNode = (struct node *)malloc(sizeof(struct node)); // dynamic mempory allocate
        printf("Enter the data: ");
        scanf("%d", &newNode->data);
        newNode->next = 0;
        // head=newNode;
        if (tail == NULL)
        {
            // head = newNode;
            tail = newNode;
            tail->next = tail;
        }
        else
        {
            // head->next = newNode;
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }

        // check is circular or not
        // printf("tail->next->data: %d\n", tail->next->data);

        printf("Do you want to continue then hit (0 or 1)");
        scanf("%d", &ch); // 1 = True 0 = false

        if (ch == 0)
        {
            break;
        }
    }
    return tail;
}

// insert at the beginning
struct node *insertAtBeginning()
{
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    if (tail == NULL)
    {
        tail = newNode;
        tail->next = tail;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
    }
    printf("Insertion at beginning sucessfull\n");
    printf("tail->next->data: %d\n", tail->next->data);
    return tail;
}

// insert at the end
struct node *insertAtEnd()
{
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    if (tail == NULL)
    {
        tail = newNode;
        tail->next = tail;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    printf("Insertion at end sucessfull\n");
    printf("tail->next->data: %d\n", tail->next->data);
    return tail;
}

// insert at the given position
struct node *insertAtPosition()
{
    int pos, i = 1;
    printf("Enter the pos: \n");
    scanf("%d", &pos);
    if (pos <= 0)
    {
        printf("Invalid\n");
    }
    else if (pos == 1)
    {
        insertAtBeginning();
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newNode->data);
        temp=tail->next;
        while(i<pos){
            temp=temp->next;
            i++;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
    return tail;
}

// traversal without head pointer
void traverseLinkedList(struct node *tail)
{
    if (tail == NULL)
    {
        printf("List is empty");
    }
    else
    {
        struct node *ptr = tail->next;
        do
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        } while (ptr != tail->next);
    }
}
int main()
{
    struct node *head;
    head = createCirculareLinkedList();
    traverseLinkedList(head);
    /*head = insertAtBeginning();
    traverseLinkedList(head);*/
    /*head = insertAtEnd();
    traverseLinkedList(head);*/
    head = insertAtPosition();
    traverseLinkedList(head);
    return 0;
}