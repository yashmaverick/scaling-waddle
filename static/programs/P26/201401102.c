#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10001
struct node
{
        int data;
        struct node* next;
};
typedef struct node node;
node vertices[MAXSIZE];
int m,visited[MAXSIZE]={0},flag,cost[MAXSIZE]={-1},new_prime[4],queue[1100],primes[MAXSIZE]={0},front=0,end=-1;
int main()
{
        int l,temp,j,digit,i,t,p1,p2,n,prime,next,k;
        for(i=2;i<500;i++)
        {
                if(primes[i]==0)
                {
                        for(j=i*i;j<MAXSIZE;j=j+i)
                                primes[j]=1;
                }
        }
        for(i=0;i<MAXSIZE;i++)
                vertices[i].next=NULL;
        for(i=1009;i<=9973;i++)
        {
                for(m=0;m<MAXSIZE;m++)
                        visited[m]=0;
                if(primes[i]!=0)
                        continue;
                for(digit=3;digit>=0;digit--)
                {
                        temp=i;
                        /*for(j=3;j>=0;j--)
                          {
                          new_prime[j]=temp%10;
                          temp=temp/10;
                          }*/
                        for(n=0;n<=9;n++)
                        {
                                temp=i;
                                for(j=3;j>=0;j--)
                                {
                                        new_prime[j]=temp%10;
                                        temp=temp/10;
                                }


                                new_prime[digit]=n;
                                k=1;
                                next=0;
                                for(l=3;l>=0;l--)
                                {
                                        next+=new_prime[l]*k;
                                        k*=10;
                                }
                                //printf("%d\n",next);
                                if(primes[next]!=0||visited[next]!=0||next<1009||next>9973||next==i)
                                        continue;
                                visited[next]==1;
                                node* q=(node* )malloc(sizeof(node));
                                q->data=next;
                                q->next=vertices[i].next;
                                vertices[i].next=q;
                        }
                }
        }
/*        for(i=1009;i<=9973;i++)
        {
                if(primes[i]!=0)
                        continue;*/
/*        node* r=vertices[1033].next;
        while(r!=NULL)
        {
                printf("%d\n",r->data);
                r=r->next;
        }*/
        scanf("%d",&t);
        while(t--)
        {
                flag=0;
                for(i=0;i<=MAXSIZE;i++)
                {
                        visited[i]=0;
                        cost[i]=-1;
                }
                end=-1;
                front=0;
                scanf("%d%d",&p1,&p2);
                cost[p1]=0;
                visited[p1]=1;
                queue[++end]=p1;
                while(end>=front)
                {
//                        printf("hello\n");
//
                        int point=queue[front++];
                        node* temp=vertices[point].next;
                        while(temp!=NULL)
                        {
                                      //           printf("%d\n",temp->data);
                                if(visited[temp->data]==0)
                                {
                                        visited[temp->data]=1;
                                        queue[++end]=temp->data;
                                        cost[temp->data]=cost[point]+1;
                                        if(temp->data==p2)
                                        {
                                                flag=1;
                                                break;
                                        }

                                }
                                temp=temp->next;
                        }
                        if(flag==1)
                                break;
                }
                if(cost[p2]==-1)
                        printf("Impossible\n");
                else
                        printf("%d\n",cost[p2]);
        }
        return 0;
}

