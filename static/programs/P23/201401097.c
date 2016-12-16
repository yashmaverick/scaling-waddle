#include<stdio.h>
#include<stdlib.h>
long long int heap[100005],last=0,par[100005],count[100005];
int visit[100005];
typedef struct node
{
    long long int no;
    struct node *next;
}node;
node *list[100005];
void insertnode(long long int v1,long long int v2)
{
    node* temp;
    temp=(node *)malloc(sizeof(node));
    temp->no=v2;
    temp->next=list[v1];
    list[v1]=temp;

}
void insert(long long int v)
{
    long long int temp,t;
    last++;
    temp=last;
    heap[temp]=v;
    if(temp>1)
    {
     while((heap[temp/2]>heap[temp])&&(temp>1))
     {
         t=heap[temp];
         heap[temp]=heap[temp/2];
         heap[temp/2]=t;
         temp=temp/2;
    }
    }     

}
void delmin()
{
    long long int t,i,temp;
   t=heap[last]; 
   heap[last]=heap[1];
   heap[1]=t;
   temp=1;
   last--;
   while(((heap[temp*2]<heap[temp])||(heap[(temp*2)+1]<heap[temp]))&&(temp*2<last))
   {
       if((heap[temp*2]<heap[temp])&&(heap[(temp*2)+1]>heap[temp*2]))
       {
           t=heap[temp];
           heap[temp]=heap[temp*2];
           heap[temp*2]=t;
           temp=temp*2;
       }
       else if(heap[(temp*2)+1]<heap[temp])
       {
           t=heap[temp];
           heap[temp]=heap[(temp*2)+1];
           heap[(temp*2)+1]=t;

           temp=(temp*2)+1;
             
       }

   }
   if((temp*2==last)&&(heap[temp*2]<heap[temp]))
   {

          t=heap[temp];
          heap[temp]=heap[temp*2];
          heap[temp*2]=t;

   }
}
int main ()
{
   long long int n,i,v1,v2,t,e,space=0;
   node *temp;
   scanf("%lld%lld",&n,&e);
   for(i=0;i<n;i++)
       count[i]=0;
   for(i=0;i<e;i++)
   {
       scanf("%lld%lld",&v1,&v2);
       insertnode(v1,v2);
       count[v2]++;

   }
   for(i=1;i<=n;i++)
   {
       if(count[i]==0)
       {
           insert(i);
           visit[i]=1;
       }
   }
   while(last!=0)
   {
        t=heap[1];
       if(space==n-1)
        printf("%lld",t);
       else
           printf("%lld ",t);
        space++;
       
        delmin();
        temp=list[t];
        while(temp!=NULL)
        {
            count[temp->no]--;
            if((count[temp->no]==0)&&(visit[temp->no]!=1))
            {
                 insert(temp->no);
                 visit[temp->no]=1;
            }
            temp=temp->next;
        }
   }
   printf("\n");
  /* for(i=1;i<=n;i++)
   {
       temp=list[i];
       while(temp!=NULL)
       {
           printf("%lld-",temp->no);
           temp=temp->next;
       }
       printf("\n");
   }*/
  
   return 0;
}

