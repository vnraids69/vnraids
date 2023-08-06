#include<stdio.h>
#include<ctype.h>
#define n 10
int queue[n],front=-1,rear=-1;
void enqueue()
{
    int a;
    if(rear==n-1)
    printf("the queue is full\n");
    else if(front==-1&&rear==-1)
    {
        front=rear=0;
        printf("enter the element to be inserted:\n");
        scanf("%d",&a);
        queue[rear]=a;
    }
    else
    {
        rear++;
        printf("enter the element to be inserted:\n");
        scanf("%d",&a);
        queue[rear]=a;
    }
}
void dequeue()
{
    int r;
    if(front==-1)
        printf("the queue is empty\n");
    else if(front==rear)
    {
        r=queue[front];
        front=rear=-1;
        printf("the deleted element is %d\n",r);
    }
    else
    {
        r=queue[front];
        front++;
        printf("the deleted element is %d\n",r);
    }
}
void display()
{
    int i;
    if(front==-1)
        printf("the queue is empty\n");
    else
    {
        printf("the queue is : ");
        for(i=front;i<=rear;i++)
            printf("%d\t",queue[i]);
            printf("\n");
    }
}
void peek()
{
    if(front==-1)
        printf("the queue is empty\n");
    else
    printf("%d\n",queue[front]);
}
int main()
{
    int b;
    printf("enter the operation 1.enqueue 2.dequeue 3.display 4.peek 0.exit\n");
    scanf("%d",&b);
    while(b!=0)
    {
        switch(b)
        {
            case 1 : enqueue();break;
            case 2 : dequeue();break;
            case 3 : display();break;
            case 4 : peek();break;
        }
          printf("enter the operation 1.enqueue 2.dequeue 3.display 4.peek 0.exit\n");
    scanf("%d",&b);
    }
}
