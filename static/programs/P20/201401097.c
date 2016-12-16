#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    long long int no;
    struct node* next;

}node;
node *list[1000005];
int visit[1000005];
long long int height[1000005],level[1000005],deepest=0,maxlevel=0,end1;
void insert(long long int v1,long long int v2)
{
    node *temp,*temp2;
    temp=(node *)malloc(sizeof(node));
    temp->no=v2;
    temp->next=list[v1];
    list[v1]=temp;

   temp2=(node *)malloc(sizeof(node));
    temp2->no=v1;
    temp2->next=list[v2];
    list[v2]=temp2;

}
void printlist(long long int n)
{
    long long int i;
    node *temp;
    for(i=0;i<=n;i++)
    {
        temp=list[i];
        while(temp!=NULL)
        {
            printf("%lld ",temp->no);
            temp=temp->next;
        }
        printf("\n");
    }

}
void dfs(long long int root)
{
    node *temp;
  //  printf("visiting-%d\n",visit[list[root]->no]);
    visit[root]=1;
    
//                   printf("%lld-",root);
    temp=list[root];
    while(temp!=NULL)
    { 
               if(visit[temp->no]==0)
               {
                   level[temp->no]=level[root]+1;
                 dfs(temp->no);
               

               }
      

        temp=temp->next;
    }
    return;

}
int main()
{
    long long int i,j,k,m,n,l,v1,v2;
    scanf("%lld",&n);
    for(i=0;i<=100005;i++)
    {
        visit[i]=0;

    }

    for(i=0;i<n;i++)
    {
        deepest=0;
        
        scanf("%lld",&k);
        for(j=0;j<k-1;j++)
        {
           scanf("%lld%lld",&v1,&v2);
           insert(v1,v2);
        }
        dfs(1);
        maxlevel=-1;
        for(l=1;l<=k;l++)
        {
            if(maxlevel < level[l])
            {
                maxlevel=level[l];
                end1=l;
            }
        }
        for(l=0;l<=k;l++)
        {
            visit[l]=0;
            level[l]=0;
        }
        dfs(end1);
        maxlevel=-1;
        for(l=1;l<=k;l++)
        {
            if(maxlevel < level[l])
            {
                maxlevel=level[l];
            }
        }
        for(l=0;l<=k;l++)
        {
            visit[l]=0;
            level[l]=0;
        }
        printf("%lld\n",maxlevel+1);
        for(l=0;l<=k;l++)
        {
            list[l]=NULL;
            visit[l]=0;
            level[l]=0;
        }
       

    }

    return 0;
}
