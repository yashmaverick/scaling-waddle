#include <stdio.h>
#include <stdlib.h>
typedef struct node node;
struct node
{
	int val;
	node* next;
};
node* a[1000000];
int n;
void insert(v1,v2)
{
	node* root=a[v1];
	while(root->next!=NULL)
	{
		root=root->next;
	}
	node* tmp=(node*)malloc(sizeof(node));
	tmp->val=v2;
	tmp->next=NULL;
	root->next=tmp;
	root=a[v2];
	while(root->next!=NULL)
	{
		root=root->next;
	}
	node* temp=(node*)malloc(sizeof(node));
	temp->val=v1;
	temp->next=NULL;
	root->next=temp;
}
int flag[1000000]={0},max=0,element;
void  dfs(int v1,int count) 
{
	node* root=a[v1];
	//printf("%d\n",v1);
	count++;
	if(count>max)
	{
		max=count;
		element =root->val;
	}
	flag[v1]=1;
	//printf("count:%d\n",count);
	while(root!=NULL)
	{
		if(root->next!=NULL && flag[root->next->val]!=1)
			dfs(root->next->val,count);
		root=root->next;
	}
}

void blank()
{
	int i;
	for(i=1;i<=n;i++)
	{
		flag[i]=0;
	}
}

int main()
{
	int jaa,test;
	scanf("%d",&test);
	for(jaa=0;jaa<test;jaa++)
	{
		int i;
		max=0;
		blank();
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			a[i]=(node*)malloc(sizeof(node));
			a[i]->val=i;
			a[i]->next=NULL;
		}
		int v1,v2;
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&v1,&v2);
			insert(v1,v2);
		}
/*	printf("start\n"); 
	for(i=1;i<=n;i++)
	{
		node* root=a[i];
		while(root!=NULL)
		{
			printf(" val: %d", root->val);
			root=root->next;
		}
		printf("\n");
	}
	printf("end\n");
	printf("\n");*/
	dfs(1,0);
	//printf("max: %d\n",max);
	//printf("element: %d\n",element);
	max=0;
	blank();
	dfs(element,0);
	printf("%d\n",max);
	//printf("2element: %d\n",element);
}
return 0;
}
