#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node* next;
    int val;
}node;
int count=1;
node* insert(node* head,int x)
{
    node* temp=malloc(sizeof(node));
    temp->val=x;
    temp->next=head;
    head=temp;
    return head;
}
void dfs(int i,int* visited,node** a)
{
    node* head=a[i];
    while(head!=NULL)
    {
        if(visited[head->val]==0)
        {
            count++;
            visited[head->val]=1;
            dfs(head->val,visited,a);
        }
        head=head->next;
    }
    return;
}
int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int nodes,i,j,k,flag=0;
        scanf("%d",&nodes);
        node* a[nodes+1];
        node* b[nodes+1];
        for(i=0;i<nodes+1;i++) a[i]=NULL;
        for(i=0;i<nodes+1;i++) b[i]=NULL;
        for(i=1;i<=nodes;i++)
        {
            int edges;
            scanf("%d",&edges);
            for(j=1;j<=edges;j++)
            {
                int n1;
                scanf("%d",&n1);
                b[i]=insert(b[i],n1);
                a[n1]=insert(a[n1],i);
            }
        }
     /*   for(i=1;i<nodes+1;i++)
        {
            node* head=b[i];
            while(head!=NULL)
            {
                printf("%d ",head->val);
                head=head->next;
            }
            printf("\n");
        }*/
        for(k=1;k<=nodes;k++)
        {
            int visited[nodes+1];
            for(j=0;j<=nodes;j++) visited[j]=0;
            visited[k]=1;
            dfs(k,visited,a);
            if(count==nodes) { flag=1; break;}
            count=1;
        }
        if(flag==0) { printf("0\n"); continue; }
        else
        {
        //    printf("fdfs-> %d",k);
            int visited[nodes+1];
            for(j=0;j<=nodes;j++) visited[j]=0;
            visited[k]=1;
            count=1;
            dfs(k,visited,b);
            printf("%d\n",count);
        }
        count=1;
    }
    return 0;
}
