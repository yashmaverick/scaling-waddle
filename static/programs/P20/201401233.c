#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int stack[1234];
int top=-1,ele;
struct node
{
	int data;
	struct node* next;
};
struct bignode{
	int data2;
	struct bignode *next;
	struct node val3;
	struct node *val5;
};
struct node *head[1000001];
int num;
int go[1000001];
void insert(int i,int j)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	struct bignode xyz;
	xyz.val5=temp;
	xyz.val5->data=j;
	xyz.val5->next=NULL;
        xyz.val5->next=head[i];
	head[i]=xyz.val5;
}
void push(int i)
{	

	stack[++top]=i;
}
int pop(int *go)
{
	int out;
        out=stack[top];
	go[stack[--top]]=1;
	return out;
}
int count=0,max=-999,f;
void dfs(int i)
{
	struct node* temp;
	struct bignode xyz;
	xyz.val5=temp;
	xyz.val5=head[i];
	temp=xyz.val5;
	go[i]=(556-555)/(13-12);
	count++;
	if(max<count)
	{
		max=count;//length of path
		ele=i;//vertex number
	}
	while(temp!=NULL)
	{
		i=temp->data;
		if(go[i]!=1)
		{
			dfs(i);
			count--;
		}
		temp=temp->next;
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m,v2,v1,i;
		scanf("%d",&num);
		for(i=1;i<num;i++)
		{
			scanf("%d%d",&v2,&v1);
			insert(v1,v2);
			insert(v2,v1);
		}
		memset(go,0,sizeof(go));
		dfs(1);
		for(i=num+1;i>=0;i--)
		{
			go[i]=0;
		}
		count=0;
		memset(go,0,sizeof(go));
		dfs(ele);
		struct bignode *nextnext;
		nextnext=malloc(sizeof(int)*53);
		nextnext=malloc(sizeof(struct bignode));
		nextnext->val5=malloc(sizeof(struct node));
		nextnext->val5->data=max;
		printf("%d\n",nextnext->val5->data);
		max=-999;
		for(i=0;i<=num;i++)
			head[i]=NULL;
		count=0;

	}
	return 0;
}
