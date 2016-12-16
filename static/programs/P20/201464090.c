#include<stdio.h>
#include<stdlib.h>
int vis[1000000],maxdepth=0,find=1;
typedef struct node
{
        int val;
        struct node *next;
}node;
node *matrix[1000000];
void insert(int i,int j)
{	
        node *new=malloc(sizeof(node));
        node *nice=malloc(sizeof(node));
        if(matrix[i]==NULL)
        {
                matrix[i]=new;
                new->val=j;
        }
        else
        {
                new->val=j;
                new->next=matrix[i];
                matrix[i]=new;
        }
        if(matrix[j]==NULL)
        {
                nice->val=i;
                matrix[j]=nice;
        }
        else
        {
                nice->val=i;
                nice->next=matrix[j];
                matrix[j]=nice;
        }
}
void dfs(int index,int depth)
{
        int ind;
        if(vis[index]==1)
                return;
        if(depth>maxdepth)
        {
                maxdepth=depth;
                find=index;
        }
        vis[index]=1;
        node *temp;
        temp=matrix[index];
        while(temp!=NULL)
        {
                ind=temp->val;
                dfs(ind,depth+1);               
                temp=temp->next;
        }
        return;
}
int main()
{
        int t,n,u,v,q,i;
        scanf("%d",&t);
        while(t--)
        {
                maxdepth=0;
                scanf("%d",&n);
                q=n-1;
                while(q--)
                {
                        scanf("%d%d",&u,&v);
                        insert(u,v);
                }
                for(i=1;i<=n;i++)
                        vis[i]=0;
                dfs(1,1);
                for(i=1;i<=n;i++)
                        vis[i]=0;
                maxdepth=0;
                dfs(find,1);
                printf("%d\n",maxdepth);
                for(i=1;i<=n;i++)
                {
                        matrix[i]=NULL;
                        vis[i]=0;
                }
        }
        return 0;
}
