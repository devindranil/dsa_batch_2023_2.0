#include<stdio.h>
#define N 5
int q[N];
int front=-1;
int rear=-1;
void enQueue(int x)
{ 
    if(rear==N-1){
        printf("stack overflow");
    }else if(front==-1 && rear==-1){
        front=rear=0;
        q[rear]=x;
    }else{
        rear++;
        q[rear]=x;
    }
}

void deQueue()
{
    if(front==-1 && rear==-1)
    {
        printf("stack underflow");
    }else if(front==rear){
        front=rear=-1;
    }else{
        printf("The deleted element is: %d", q[front]);
        front++;
    }
}

void display()
{
    int i;
    if(front==-1 && rear==-1){
        printf("stack is empty");
    }else{
        for(i=front;i<rear+1;i++){
            printf("%d ",q[i]);
        }
    }
}

void peek()
{
    if(front==-1 && rear==-1){
        printf("stack is empty");
    }else{
        printf("the first element is: %d", q[front]);
    }
}
int main()
{
    enQueue(2);
    enQueue(5);
    enQueue(15);
    display();
    printf("\n");
    peek();
    printf("\n");
    deQueue();
    printf("\n");
    peek();
    printf("\n");
    
    return 0;
}