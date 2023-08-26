#include<stdio.h>
#include<stdlib.h>
#define N 5
int dq[N];
int front = -1;
int rear = -1;
void enqueue_front(int x)
{
    if((front == 0 && rear == N-1) || (front == rear+1))
    {
        printf("Queue is full");
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        dq[front] = x;
    }
    else if(front == 0)
    {
        front = N-1;
        dq[front] = x;
    }
    else
    {
        front--;
        dq[front] = x;
    }
}
void enqueue_rear(int x)
{
    if((front == 0 && rear == N-1) || (front == rear+1))
    {
        printf("Queue is full");
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        dq[rear] = x;
    }
    else if(rear == N-1)
    {
        rear = 0;
        dq[rear] = x;
    }
    else
    {
        rear++;
        dq[rear] = x;
    }
}
void dequeue_front()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else if(front == rear)
    {
        front = rear = -1;
    }
    else if(front == N-1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}
void dequeue_rear()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else if(front == rear)
    {
        front = rear = -1;
    }
    else if(rear == 0)
    {
        rear = N-1;
    }
    else
    {
        rear--;
    }
}
void display()
{
    int i = front;
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        while(i != rear)
        {
            printf("%d ",dq[i]);
            i = (i+1)%N;
        }
        printf("%d",dq[i]);
    }
}
int main()
{
    int choice, x;
    while(1)
    {
        printf("\n1. Enqueue Front\n2. Enqueue Rear\n3. Dequeue Front\n4. Dequeue Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d",&x);
                enqueue_front(x);
                break;
            case 2:
                printf("Enter the element to be inserted: ");
                scanf("%d",&x);
                enqueue_rear(x);
                break;
            case 3:
                dequeue_front();
                break;
            case 4:
                dequeue_rear();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
    return 0;
}