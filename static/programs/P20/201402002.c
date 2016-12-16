#include<stdio.h>
#include<stdlib.h>

struct node{
    int ver;
    struct node *next;
};

struct node* v[1000006];
struct node* insert(struct node *root, int data)
{
    if (root==NULL)
    {
        struct node *new=(struct node*)malloc(sizeof(struct node));
        new->ver=data;
        new->next=NULL;
        return new;
    }
    else
    {
        root->next=insert(root->next,data);
        return root;
    }
}

int check[1000005]={0};
int max_depth=-1;
int dfs_start_element=1;

void dfs(int vertex, int depth)
{
    check[vertex] = 1;

    if(depth>max_depth)
    {
        max_depth = depth;
        dfs_start_element = vertex;
    }

    struct node *temp=v[vertex];
    while(temp!=NULL)
    {
        if(check[temp->ver] == 0)
            dfs(temp->ver,depth+1);
        temp=temp->next;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
   //t=1;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        if(n==0)
            printf("0\n");
        else
        {

            int d;
            for(d=0;d<=n+3;d++)
                v[d]=NULL;
            int i;
            for(i=1;i<n;i++)
            {
                check[i]=0;
                int t1,t2;
                scanf("%d %d",&t1 ,&t2);
                v[t1]=insert(v[t1],t2);
                v[t2]=insert(v[t2],t1);
            }
            check[n]=0;

            max_depth=-1;
            dfs_start_element = 1;
            dfs(dfs_start_element,1);
            int l;
            for(l=0;l<=n+3;l++)
                check[l]=0;
            max_depth=-1;
            dfs(dfs_start_element,1);

            printf("%d\n",max_depth);
        }
    }
    return 0;
}
