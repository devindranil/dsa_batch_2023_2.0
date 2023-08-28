#include<stdio.h>
#include<stdlib.h>

//implement priority queue using Linked List
//priority queue is a queue in which every element has a priority associated with it
//elements are popped according to their priority
//elements with same priority are popped according to their order in queue

//structure for priority queue
struct node
{
    int data;
    int priority;
    struct node *next;
};

//function to create a new node
struct node *newNode(int data, int priority)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;
    return temp;
}

//function to check if queue is empty
int isEmpty(struct node *head)
{
    return head == NULL;
}

//function to insert a new node in queue according to its priority
// priority is less value for higher priority
void insert(struct node **head, int data, int priority)
{
    struct node *start = (*head);

    //create new node
    struct node *temp = newNode(data, priority);

    //if queue is empty or priority of first node is more than priority of new node
    //then insert new node at the beginning
    if (isEmpty(*head) || (*head)->priority > priority)
    {
        temp->next = *head;
        (*head) = temp;
    }
    else
    {
        //traverse the queue to find the position to insert new node
        while (start->next != NULL && start->next->priority < priority)
        {
            start = start->next;
        }

        //insert new node at correct position
        temp->next = start->next;
        start->next = temp;
    }
}

//function to remove the element-normal deletion form front end 
void deleteNode(struct node **head)
{
    struct node *temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

//function to print the queue
void printList(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

//main function

int main()
{
    //create a priority queue
    struct node *pq = newNode(4, 1);
    insert(&pq, 5, 2);
    insert(&pq, 6, 3);
    insert(&pq, 7, 0);

    printf("Priority Queue: ");
    printList(pq);

    printf("\n\nAfter deleting an element with highest priority \n");
    deleteNode(&pq);
    printf("Priority Queue: ");
    printList(pq);

    return 0;
}
