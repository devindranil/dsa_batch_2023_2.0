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

// delete at the beginning
// check the list is empty or not
//  using temp pointer
struct node *deleteAtBeginning()
{
    if (tail == NULL)
    {
        printf("List is empty:\n");
    }
    // only if one node is present at the time of deletion
    else if (tail->next == tail)
    {
        temp = tail;
        tail = NULL;
        free(temp);
    }
    else
    {
        temp = tail->next;
        tail->next = temp->next;
        free(temp);
    }
    return tail;
}

// delete at the end
// check the list is empty or not
//  using temp pointer
struct node *deleteAtEnd()
{
    struct node *current, *previous;
    current=tail->next;
    if (tail == NULL)
    {
        printf("List is empty:\n");
    }
    // only if one node is present at the time of deletion
    else if (tail->next == tail)
    {
        temp = tail;
        tail = NULL;
        free(temp);
    }
    else{
        while(current->next != tail->next)
        {
            previous = current;
            current = current->next;
        }
        previous->next=tail->next;
        tail=previous;
        free(current);
    }
    return tail;
}

// circular linked list length
int l = 0;
int length()
{
    struct node *current;
    current = tail->next;
    do
    {
        l++;
        current = current->next;
    } while (current != tail->next);
    return l;
}
// delete at the given position
// check the list is empty or not
// using temp pointer
// if position is 1 then delete at the beginning
// if position is last then delete at the end
// else delete at the given position

struct node *deleteAtGivenPosition()
{
    struct node *current, *previous;
    int pos, i=1;
    l=length();
    current=tail->next;
    if(tail==NULL)
    {
        printf("List is empty: \n");
    }
    else
    {
        printf("Enter the pos: ");
        scanf("%d",&pos);
        if(pos>l)
        {
            printf("Invalid position\n");
        }
        else if(pos==1)
        {
            deleteAtBeginning();
        }
        else if(pos==l)
        {
            deleteAtEnd();
        }
        else{
            while(i<pos-1)
            {
                current=current->next;
                i++;
            }
            previous=current->next;
            current->next=previous->next;
            free(previous);
        }
    }
    return tail;
}
// traverse the linked list
void traverseLinkedList(struct node *tail)
{
    struct node *ptr;
    ptr = tail->next;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != tail->next);
    printf("\n");
}

int main()
{
    struct node *head;
    head = createCirculareLinkedList();
    traverseLinkedList(head);
    /*head = deleteAtBeginning();
    traverseLinkedList(head);*/
    /*head = deleteAtEnd();
    traverseLinkedList(head);*/
    head = deleteAtGivenPosition();
    traverseLinkedList(head);

    return 0;
}