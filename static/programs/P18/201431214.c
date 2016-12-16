#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int value;
    struct node* next;
}node;
node* head[1004];
node* head1[1004];
int new[1004];
int ind=-1;
int visited[1004];
int n;
void insert(int num1,int num2,int k)
{
    node* temp;
    node* p;
    temp=(node*)malloc(sizeof(node));
    temp->value=num2;
    temp->next=NULL;
    if(k==1)
    {
        if(head[num1]==NULL)
        {
            head[num1]=temp;
        }
        else
        {
            p=head[num1];
            head[num1]=temp;
            temp->next=p;
        }
    }
    else if(k==2)
    {

        if(head1[num1]==NULL)
        {   
            head1[num1]=temp;
        }
        else
        {
            p=head1[num1];
            head1[num1]=temp;
            temp->next=p;
        }
    }
}
void dfs(int v,int k)
{
    node* temp;
    visited[v]=1;
    if(k==1)
    {
        temp=head[v];
    }
    else if(k==2)
    {
        temp=head1[v];
    }
    ind++;
    new[ind]=v;
    while(temp!=NULL)
    {
        if(visited[temp->value]!=1)
        {
            dfs(temp->value,k);
        }
        temp=temp->next;
    }
}

int main()
{
    int test,t;
    scanf("%d",&test);
    for(t=0;t<test;t++)
    {

        int x,i,j,y,v,count=0,p;
        int flag=0;
        ind=-1;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&y);
            visited[i]=0;
            for(j=1;j<=y;j++)
            {
                scanf("%d",&x);
                insert(x,i,1);
                insert(i,x,2);
            }
        }
        for(v=1;v<=n;v++)
        {
            if(flag==0)
            {
                dfs(v,1);
            }
            if(ind==(n-1))
            {
                p=v;
                flag=1;
                break;
            }
            ind=-1;
            for(i=1;i<=n;i++)
            {
                visited[i]=0;
            }
        }
        ind=-1;
        if(flag==0)
        {
            printf("0\n");
        }
        else  if(flag==1)
        {
            for(i=1;i<=n;i++)
            {
                visited[i]=0;
            }
            dfs(p,2);
            printf("%d\n",(ind+1));
        }
        for(i=1;i<=n;i++)
        {
            head[i]=NULL;
            head1[i]=NULL;
        }
    }
    return 0;
}


