#include<stdio.h>
#include<stdlib.h>
int visited[100004],n,m;
struct node
{
	int data;
	struct node* next;
};
struct node*a[100004];
void  insert(int ,int );
int stack[100004];
int top=0;
void push(int i)
{	

	stack[top]=i;
	top++;	
}
void dfs(int);


int main()
{
	int i,j,p;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d",&i,&j);
		insert(i,j);
	}
        for(i=0;i<100004;i++)
          	visited[i]=0;

	for(i=n;i>0;i--)
	{
		if(visited[i]==0)
			dfs(i);
	}
	for(i=top-1;i>=0;i--)
	{
		if(i==0)
			printf("%d\n",stack[i]);
		else
			printf("%d ",stack[i]);
	}
	return 0;
}
void dfs(int i)
{

        struct node* p;
        p=a[i];
        visited[i]=1;
        int v;
        while(p!=NULL)
        {
                v=p->data;
                if(visited[v]!=1)
                {
                        dfs(v);

                }
                p=p->next;
        }
        push(i);
}
void  insert(int i,int j)
{
        struct node* p;
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        temp->data=j;
        temp->next=NULL;
        if(a[i]==NULL)
                a[i]=temp;
        else
        {
                p=a[i];
                while(p->next!=NULL)
                        p=p->next;
                p->next=temp;

        }

}

