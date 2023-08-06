#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
}*head,*tail;
void create()
{
    struct node *nn;
    int a;
    do{
    nn=(struct node*)malloc(sizeof(struct node));
    printf("enter the data value\n");
    scanf("%d",&nn->data);
    nn->next=NULL;
    if(head==NULL)
    {
        tail=head=nn;
        nn->next=head;
    }
    else
    {
        tail->next=nn;
        tail=nn;
        nn->next=head;
    }
    printf("press 1 to continue\n");
    scanf("%d",&a);
    }while(a==1);
}
void inbeg()
{
    struct node *nn;
    int a;
    nn=(struct node*)malloc(sizeof(struct node));
    printf("enter the data value\n");
    scanf("%d",&nn->data);
    nn->next=NULL;
    if(head==NULL)
    {
        tail=head=nn;
        nn->next=head;
    }
    else
    {
        nn->next=head;
        head=nn;
        tail->next=nn;
    }
}
void inend()
{
    struct node *nn,*temp;
    nn=(struct node*)malloc(sizeof(struct node));
    printf("enter the data value\n");
    scanf("%d",&nn->data);
    nn->next=NULL;
    if(head==NULL)
        {
        tail=head=nn;
        nn->next=head;
    }
    else
    {
        tail->next=nn;
        nn->next=head;
        tail=nn;
    }
}
void inpos()
{
    int pos,c=1;
    struct node *nn,*temp;
    nn=(struct node*)malloc(sizeof(struct node));
    printf("enter the data value\n");
    scanf("%d",&nn->data);
    printf("enter the position\n");
    scanf("%d",&pos);
    nn->next=NULL;
    if(head==NULL)
    {
        tail=head=nn;
        nn->next=head;
    }
    else
        {
            temp=head;
            while(c<pos-1)
            {
                temp=temp->next;
                c++;
            }
            nn->next=temp->next;
            temp->next=nn;
        }
}
void delbeg()
{
    struct node *temp;
    if(head==NULL)
        printf("the list is empty\n");
    else
    {
        temp=head;
        printf("the deleted element is %d\n",temp->data);
        head=head->next;
        tail->next=head;
        free(temp);
    }
}
void delend()
{
    struct node *temp,*nn;
    if(head==NULL)
        printf("the list is empty\n");
    else
    {
        temp=head;
        while((temp->next)->next!=head)
        {
            temp=temp->next;
        }
        temp->next=tail->next;
        printf("the deleted element is %d\n",tail->data);
        free(tail);
        tail=temp;
    }
}
void delpos()
{
    int pos,c=1;
    struct node *temp,*nn;
    if(head==NULL)
        printf("the list is empty\n");
    else
    {
        temp=head;
        printf("enter the position\n");
        scanf("%d",&pos);
        while(c<pos-1)
        {
            temp=temp->next;
            c++;
        }
        nn=temp->next;
        printf("the deleted element is %d\n",nn->data);
        temp->next=nn->next;
        free(nn);
    }
}
void display()
{
    struct node *temp;
    if(head==NULL)
        printf("the list is empty\n");
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d\n",tail->data);
    }
}
int main()
{
    int a;
    do{
        printf("enter the choice 1.create\n2.inbegin\n3.inend\n4.inpos\n5.deletebeg\n6.delete end\n7.deletepos\n8.display\n9.exit\n");
        scanf("%d",&a);
        switch(a)
        {
        case 1 : create();break;
        case 2 : inbeg();break;
        case 3 : inend();break;
        case 4 : inpos();break;
        case 5 : delbeg();break;
        case 6 : delend();break;
        case 7 : delpos();break;
        case 8 : display();break;
        case 9 : exit(0);
        }
    }while(1);
}
