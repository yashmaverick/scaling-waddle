#include<stdio.h>
# include<string.h>
//whenever you overwrite front moves forward
int size;  
char cq[10005][110];
int front,rear;

void push(char string[])
{
    if (front == -1)
    {
        front=rear=0;
        //printf("front:%d rear:%d\n",front,rear);
        strcpy(cq[rear],string);
    }
    else
    {
        rear=(rear+1)%size;
        strcpy(cq[rear],string);

        if (front == rear)//overwriting
            front=(rear+1)%size;
        //printf("front:%d rear:%d\n",front,rear);
    }

}

void pop()
{
    if(front==-1)
        {return;printf("empty");}
    else
    {
        //printf("popped:%d\n",cq[front]);

        if (front==rear)
        {front=rear=-1;}
        else
        {
            front=(front+1)%size;
        }
        //printf("front:%d rear:%d\n",front,rear);
    }


}

void printq()
{
    if(front==-1)
    {
        //printf("empty");
        return;}

        //printf("front:%d rear:%d\n",front,rear);

    int i=front;
    if(front==rear)
        printf("%s\n",cq[front]);
    else
        if(front<rear)
        {
            while(i<=rear)
            {printf("%s\n",cq[i]);++i;}


        }
        else if(front>rear)
        {

            while(i<size)
            {printf("%s\n",cq[i]);++i;}

            i=0;
            while(i<=rear)
            {printf("%s\n",cq[i]);++i;}





        }
}
void showfront()
{
    if(front==-1)
        printf("Empty\n");
    else
        printf("Front:%s\n",cq[front]);

}



int main()
{
    char ch,l;char data[100];
    int n,i;
    front=rear=-1;
    while(1)
    {

        scanf("%d",&size);
        scanf("%c",&ch);
        switch(ch)
        {
            case 'A':scanf("%d",&n);
                    for(i=0;i<n;++i)
                        {scanf("%s",data);
                        push(data);}
                    break;
            case 'R':scanf("%d",&n);
                    for(i=0;i<n;++i)
                        {pop();}
                    break;
                     // case 3:showfront();break;
            case 'L':printq();break;
            case 'Q':break;

        }
        if(ch=='Q')
            break;


    }
    return 0;
}

