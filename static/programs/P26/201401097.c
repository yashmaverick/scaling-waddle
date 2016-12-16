#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int no;
    struct node * next;

}node;
node *list[100005];
int visit[100005],primes[10010],cost[100005],flag=0;
void insert(int v1,int v2)
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp->no=v2;
    temp->next=list[v1];
    list[v1]=temp;

    /*   temp=(node *)malloc(sizeof(node));
         temp->no=v1;
         temp->next=list[v2];
         list[v2]=temp;
     */

}
void bfs(int num,int search)
{
    int q[100005],i,j,front,rear,lastcost=0,lastnum;
    
    for(i=1000;i<=9999;i++)
    {
        visit[i]=0;
        cost[i]=0;
        

    }
    node *temp;
    q[0]=num;
    front=0;
    rear=0;
    visit[num]=1;

    while(front>=rear)
    {
        temp=list[q[rear]];
        lastnum=q[rear];
        if(temp!=NULL)
            lastcost=cost[lastnum];

        rear++;


        while(temp!=NULL)
        {
            if(visit[temp->no]==0)
            {
                if(temp->no==search)
                {
                    printf("%d\n",lastcost+1);
                    flag=1;
                    break;
                }

                //   printf("%d-",temp->no);
                cost[temp->no]=lastcost+1;
                visit[temp->no]=1;
                q[++front]=temp->no;

            }
            temp=temp->next;
        }

        if(flag==1)
            break;


    }



}
void sieve()
{
    int i,j;
    for(i=2;i*i<10010;i++)
    {
        if(primes[i]==0)
        {
            j=i*2; 

            while(j<10010)
            {
                primes[j]=1;
                j=j+i;

            }

        }

    }
}

void start(int n1)
{
    int temp,i,act,temp2,temp3;
    //1st digit
    temp=n1/10;
    for(i=0;i<=9;i++)
    {
        act=(temp*10)+i;
        if((primes[act]==0)&&(act>=1000)&&(act!=n1)&&(act<=9999))
        {
            insert(n1,act);

        }

    }
    temp=n1/100;
    temp2=n1%10;
    for(i=0;i<=9;i++)
    {
        act=(temp*10+i)*10+temp2;
        if((primes[act]==0)&&(act>=1000)&&(act!=n1)&&(act<=9999))
        {
            insert(n1,act);

        }

    }

    temp=n1/1000;
    temp2=n1%100;
    for(i=0;i<=9;i++)
    {
        act=(temp*10+i)*100+temp2;
        if((primes[act]==0)&&(act>=1000)&&(act!=n1)&&(act<=9999))
        {
            insert(n1,act);

        }

    }

    temp2=n1%1000;
    for(i=0;i<=9;i++)
    {
        act=i*1000+temp2;
        if((primes[act]==0)&&(act>=1000)&&(act!=n1)&&(act<=9999))
        {
            insert(n1,act);

        }

    }

}
int main()
{
    int i,j,k,l,m,n,num1,num2;
    scanf("%d",&n);
    sieve();
    for(i=1000;i<=9999;i++)
    {
        if(primes[i]==0)
            start(i);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&num1,&num2);
        if(num1==num2)
        {
            printf("0\n");
            continue;
        }

        flag=0;
        if((primes[num1]==0)&&(primes[num2]==0))
            bfs(num1,num2);

        if(flag==0) 
            printf("Impossible\n");



    }

    return 0;

}
