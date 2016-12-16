#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int is_prime[100005];
int prime_list[1200];
int size;

struct node 
{
    int num;
    struct node *next;
};
typedef struct node NODE;
typedef NODE *LINK;

LINK adj_list[100005];

int is_neighbour(int a,int b)
{
    int i,count=0;
    for(i=1;i<=4;i++)
    {
        if(a%10!=b%10)
            count++;
        a/=10;b/=10;
    }
    if(count==1)
        return 1;
    else
        return 0;
}

void add_neighbours(int i)
{
    int j;
    LINK temp;
    for(j=0;j<=size;j++)
    {
        if(is_neighbour(i,prime_list[j]))
        {
            temp=(LINK)malloc(sizeof(NODE));
            temp->num=prime_list[j];
            temp->next=adj_list[i];
            adj_list[i]=temp;
        }
    }
}

int D[100005],flag[100005];

void mark_dist(int root,int dest)
{
    memset(D,-1,sizeof(D));
    memset(flag,0,sizeof(flag));
    D[root]=0;
    flag[root]=-1; //in the queue
    int Q[1000006];
    int front,end,first;LINK i;
    front=end=0;
    Q[front]=root;
    while(front<=end)
    {
        first=Q[front++];
//        printf("%d\n",first);
        flag[first]=1; //visited
        for(i=adj_list[first];i!=NULL;i=i->next)
        {   
            if(flag[i->num]==0)
            {
                Q[++end]=i->num;
                flag[i->num]=-1;
                D[i->num]=D[first]+1;
            }
            if(i->num==dest)
                return;
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    
    int a,b;
  //  memset(is_prime,1,sizeof(is_prime));
    
    int i,j;
    for(i=0;i<=100000;i++) is_prime[i]=1;
    is_prime[0]=is_prime[1]=0;
    is_prime[2]=1;
    for(i=2;i*i<=100000;i++)
    {
        if(is_prime[i]==0)
            continue;
        for(j=i*i;j<=100000;j+=i)
        {
            is_prime[j]=0;
        }
    }
    
    for(i=1;i<=100005;i++)
    {
        adj_list[i]=NULL;
    }
    
    size=-1;
    for(i=1000;i<=9999;i++)
    {
        if(is_prime[i]==1)
        {
//            printf("%d\n",i);
            prime_list[++size]=i;
        }
    }
//    printf("sze is %d\n",size);
    for(i=0;i<=size;i++)
    {
        add_neighbours(prime_list[i]);
 /*       printf("%d :",prime_list[i]);
        for(j=adj_list[prime_list[i]];j!=NULL;j=j->next)
        {
            printf(" %d",j->num);
        }
        putchar('\n');
        */
    }

    while(t--)
    {
       scanf("%d%d",&a,&b);
       mark_dist(a,b);  //only till b(the destination)
       if(D[b]!=-1)
          printf("%d\n",D[b]);
       else
          printf("Impossible\n"); 
    }

return 0;
}
