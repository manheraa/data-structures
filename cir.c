#include<stdio.h>
#define max 5
int front=-1,rear=-1;
int cqueue[max];
void insert();
int delete();
void display();
main()
{

    int w,no;
    for(;;)
    {
        printf("\n 1.insert");
        printf("\n 2.delete");
        printf("\n 3.display");
        printf("\n 4.exit");
        printf("\n enter what you want");
        scanf("%d",&w);
        switch(w)
        {

        case 1:
            insert();
            break;
        case 2:
            no=delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("\n invalid choice !!\n");
        }
    }
}
void insert()
{
    int no;
    if((front==0&&rear==max-1)||front==rear+1)
    {
        printf("\ncircular queue is full !!");
        return;
    }
    printf("\nenter a number to insert:");
    scanf("%d",&no);
    if(front==-1)
        front=front+1;
        if(rear=max-1)
        rear=0;
    else
        rear=rear+1;
    cqueue[rear]=no;

}
int delete()
{
    int e;
    if(front==-1)
    {
        printf("\nthe circular queue is empty!!\n");
        return ;

    }
    e=cqueue[front];
    if(front ==max-1)
        front=0;
    else if(front==rear)
    {
        front=-1;
        rear=-1;

    }
    else front=front +1;
    printf("\n%d was deleted !!\n",e);
    return e;

}
void display()
{

    int i;
    if(front==-1)
    {
    printf("\n the circular queue is empty! nothing to display\n");
    return ;

    }
    i=front;
    if(front<=rear)
    {

        printf("\n\n");
        while(i<=rear)
            printf("%d",cqueue[i++]);
        printf("\n");
    }
    else
    {
    printf("\n\n");
    while(i<=max-1)
        printf("%d",cqueue[i++]);
    i=0;
    while(i<=rear)
        printf("%d",cqueue[i++]);
    printf("\n");
    }
}
