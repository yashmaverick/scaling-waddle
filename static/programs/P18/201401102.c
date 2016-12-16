#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define min(a,b) ((a<b)? a:b)
struct node{int data;struct node* next;};
struct edge{int v1,v2;};
typedef struct edge edge;
typedef struct node node;
node* vertices;
int n,visited[1001],edge_count=0,comp_in_degree[1001],components[1001],count=0,top=-1,order=0,loser[1001],is_on_stack[1001],stack[1000];
edge edges[1000000];
void make_component(int stop)
{
        int temp;
        count++;
        while(1)
        {
                temp=stack[top--];
                is_on_stack[temp]=0;
                components[temp]=count;
                if(temp==stop)
                        break;
        }
}
void find_component(int v)
{
        visited[v]=order;
        loser[v]=order;
        order++;
        stack[++top]=v;
        is_on_stack[v]=1;
        node* temp=vertices[v].next;
        while(temp!=NULL)
        {
                if(visited[temp->data]==-1)
                {
                        find_component(temp->data);
                        loser[v]=min(loser[v],loser[temp->data]);
                }
                else if(is_on_stack[temp->data]==1)
                        loser[v]=min(loser[v],visited[temp->data]);
                temp=temp->next;
        }
        if(loser[v]==visited[v])
                make_component(v);                        
        
}

int bad_warriors()
{
        int j,realms=0;
        for(j=0;j<edge_count;j++)        
                if(components[edges[j].v1]!=components[edges[j].v2])
                        comp_in_degree[components[edges[j].v2]]++;        
        int temp=0;        
        for(j=1;j<=count;j++)
        {
                if(comp_in_degree[j]==0)
                {
                        realms++;
                        if(realms>=2)                        
                                return 0;                       
                        temp=j;
                }
        }
        realms=0;
        for(j=1;j<=n;j++)
                if(components[j]==temp)
                        realms++;
        return realms;

}
int main()
{
        int v,t,i,realms,k,j,s;
        scanf("%d",&t);
        for(i=0;i<t;i++)
        {
                edge_count=0;                
                scanf("%d",&n);
                vertices=(node* )malloc((n+1)*sizeof(node));
                for(j=1;j<=n;j++)
                        vertices[j].next=NULL;
                for(j=1;j<=n;j++)
                {
                        scanf("%d",&s);
                        vertices[j].data=s;
                        for(k=0;k<s;k++)
                        {
                                scanf("%d",&v);
                                node* temp=(node* )malloc(sizeof(node));
                                temp->data=v;
                                temp->next=vertices[j].next;
                                vertices[j].next=temp;
                                edges[edge_count].v1=v;
                                edges[edge_count].v2=j;
                                edge_count++;
                        }
                }                
                order=0;
                count=0;                
                top=-1;
                for(j=1;j<=n;j++)
                {
                        loser[j]=INT_MAX;
                        comp_in_degree[j]=0;
                        visited[j]=-1;
                        is_on_stack[j]=0;
                }

                for(j=1;j<=n;j++)
                {
                        if(visited[j]==-1)
                                find_component(j);              
                }

                //                for(j=1;j<=n;j++)
                //                      printf("%d ",components[j]);

                printf("%d\n",bad_warriors());
        }
        return 0;
}
