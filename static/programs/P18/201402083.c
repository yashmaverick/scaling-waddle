/*
_____________________________________________
PROBLEM STATEMENT: 
TEST CASES:
COMMENTS:

		SOLVED BY - YOGESH SHARMA
______________________________________________ 
*/
#include <stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
typedef struct node node;
struct node
{
    int nodename;
    node *next;
};

node *arr[1005];
node *rev[1005];
int visited[1001];
int length;
node *insert(node *head,int nodename)
{
    node *temp=(node *)malloc(sizeof(node));
    temp->nodename=nodename;
    temp->next=head;
    return temp;

}
void dfs(int n)
{
    length++;
    visited[n]=1;
    node *temp=arr[n];
    while(temp!=NULL)
    {
        if(visited[temp->nodename]==0)   dfs(temp->nodename);
        temp=temp->next;
    }
    return;
}

void rdfs(int n)
{
    length++;
    visited[n]=1;
    node *temp=rev[n];
    while(temp!=NULL)
    {
        if(visited[temp->nodename]==0)   rdfs(temp->nodename);
        temp=temp->next;
    }
}
int main()
{
    int t,n,i,temp,m,j,find=-1;
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<1005;i++) arr[i]=NULL;
        for(i=0;i<1005;i++) rev[i]=NULL;
        length=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&m);
            while(m--)
            {
                scanf("%d",&temp);
                arr[temp]=insert(arr[temp],i);
                rev[i]=insert(rev[i],temp);
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=0;j<1001;j++) visited[j]=0;
            length=0;
            dfs(i);
            if(length==n) {
                find=i;
                break;
            }
        }
        for(j=0;j<1001;j++) visited[j]=0;
        length=0;
        if(find!=-1)   rdfs(find);
        printf("%d\n",length);
        find=-1;
        length=0;
    }
return 0;
}
