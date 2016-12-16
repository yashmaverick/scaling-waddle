#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node* next;
    int val;
}node;
int max1=0,max2=0,ans1=1;
node* insert(node* head,int x)
{
    node* temp=malloc(sizeof(node));
    temp->val=x;
    temp->next=head;
    head=temp;
    return head;
}
void dfs(int i,int depth,node** a,int * visited)
{
//    printf("%d\n",i);
    if(depth>max1) { max1=depth;ans1=i; }
    node* head=a[i];
    while(head!=NULL)
    {
        if(visited[head->val]==0)
        {
            visited[head->val]=1;
            dfs(head->val,depth+1,a,visited);
        }
            head=head->next;
    }
    return;
}
void dfs2(int i,int depth,node** a,int * visited)
{
  //  printf("%d %d\n",i,depth);
    if(depth>max2) { max2=depth;ans1=i; }
    node* head=a[i];
    while(head!=NULL)
    {
        if(visited[head->val]==0)
        {
            visited[head->val]=1;
            dfs2(head->val,depth+1,a,visited);
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
        int nodes,i,j,k;
        scanf("%d",&nodes);
        node* a[nodes+1];
        for(i=0;i<=nodes;i++) a[i]=NULL;
        for(i=1;i<=nodes-1;i++)
        {
            scanf("%d %d",&j,&k);
            a[j]=insert(a[j],k);
            a[k]=insert(a[k],j);
        }
    
        int c1=1,visited[nodes+1];
        for(i=0;i<nodes+1;i++) visited[i]=0;
        visited[1]=1;
        dfs(1,c1-1,a,visited);
        //printf("%d %d\n",max1,ans1);
        for(i=0;i<nodes+1;i++) visited[i]=0;
        visited[ans1]=1;
        dfs2(ans1,0,a,visited);
       // printf("%d %d\n",max2,ans1);
        printf("%d\n",max2+1);
        max1=0;max2=0;ans1=1;
    }
    return 0;
}
