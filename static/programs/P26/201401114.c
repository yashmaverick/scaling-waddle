#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef long long int ll;
typedef struct node
{
        int val;
        struct node*next;
}node;
int sieve[100000], distance[9974], queue[9974], prime[1200],k;
node*arr[9974];
int difference1(int x, int y)
{
        int i,dig1,dig2, count=0;
        for(i=0; i<4; i++)
        {
                dig1=x%10;
                dig2=y%10;
                if(dig1==dig2)
                        count++;
                x/=10;
                y/=10;
        }
        if(count==3)
                return 1;
        return 0;
}
node* insert(int val, node*root)
{
        node*ptr=malloc(sizeof(node));
        ptr->val=val;
        ptr->next=root;
        return ptr;
}
void bfs(int src, int dest)
{
        memset(distance,-1,sizeof(distance));
        distance[src]=0;
        int front=0, rear=0,parent;
        queue[rear++]=src;
        while(front!=rear)
        {
                parent=queue[front++];
                node*ptr=arr[parent];
                while(ptr!=NULL)
                {
                        if(distance[ptr->val]==-1)
                        {
                                distance[ptr->val]=distance[parent]+1;
                                queue[rear++]=ptr->val;
                        }
                        ptr=ptr->next;
                }
        }
}
int main()
{
        ll T;
        memset(sieve, 0, sizeof(sieve));
        int i,j;
        //sieve[2]=1;  //2 is set as prie
        for(i=2;i<9999; i++)
                if(sieve[i]==0)
                        for(j=i;i*j<9999;j++)
                                sieve[i*j]=1;
        k=0;
        
        for(i=1009; i<9999; i++)
        {
                if(sieve[i]==0)
                        prime[k++]=i;
        }
       

                for(i=0; i<k-1; i++)
                {
                                for(j=i+1;j<k; j++)
                                {
                                                if(difference1(prime[i],prime[j])==1)
                                                {
                                                        arr[prime[i]]=insert(prime[j], arr[prime[i]]);
                                                        arr[prime[j]]=insert(prime[i], arr[prime[j]]);
                                                }
                                }
                }

       // printf("Made sieve\n");
        scanf("%lld", &T);
        while(T--)
        {
                int p1, p2;
                scanf("%d %d", &p1, &p2);
                /*for(i=0; i<k-1; i++)
                {
                                for(j=i+1;j<k; j++)
                                {
                                                if(difference1(prime[i],prime[j])==1)
                                                {
                                                        arr[prime[i]]=insert(prime[j], arr[prime[i]]);
                                                        arr[prime[j]]=insert(prime[i], arr[prime[j]]);
                                                }
                                }
                }*/
                bfs(p1,p2);
                if(distance[p2]==-1)
                        printf("Impossible\n");
                else
                        printf("%d\n", distance[p2]);
        }

        return 0;
}
