#include<stdio.h>
#include<stdlib.h>
int n,m;
int visited[1000000]={0};
int stack[1000000];
int top=-1;
struct node
{
        int data;
        struct node* next;
};
typedef struct node node;
node* vertices;
void schedule_tasks(int i)
{
                visited[i]=1;
                node* temp=vertices[i].next;
                while(temp!=NULL)
                {
                        if(visited[temp->data]==0)
                                schedule_tasks(temp->data);
                        temp=temp->next;
                }      
        stack[++top]=i;
}
int main()
{
        int i,v1,v2;
        scanf("%d%d",&n,&m);
        vertices=(node* )malloc((n+1)*sizeof(node));
        for(i=1;i<=n;i++)
                vertices[i].next=NULL;
        for(i=0;i<m;i++)
        {
                scanf("%d%d",&v1,&v2);
                node* temp=(node* )malloc(sizeof(node));
                temp->data=v2;
                node* head=vertices[v1].next;
                if(head==NULL)
                {
                        vertices[v1].next=temp;
                        temp->next=NULL;
                }
                else
                {
                while(head->next!=NULL&&head->next->data<temp->data)
                        head=head->next;
                node* p=head->next;
                head->next=temp;
                temp->next=p;
                }
        }
        for(i=n;i>0;i--)
                if(visited[i]==0)
                        schedule_tasks(i);
        for(i=top;i>0;i--)
                printf("%d ",stack[i]);
        printf("%d\n",stack[0]);
        return 0;
}
