#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
	int value;
	struct list *next;
}list;
int boo[1000000];
int max,val;
list *head[1000000];
list *itr;
void dfs(struct list* tmp,int localmax)
{
	list *tr;
	tr=head[tmp->value];
	localmax++;
	boo[tr->value]=1;
	itr=tr;
	tr=tr->next;
	while(tr!=NULL)
	{
		if(boo[tr->value]!=1)
		{
			dfs(tr,localmax);
		}
		tr=tr->next;
	}
	localmax--;
	if(localmax>max)
	{
		max=localmax;
		val=itr->value;
	}
}
int main()
{
	list *root=(list *)malloc(sizeof(list));
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int n,j,k,a,b;
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		{
			boo[j]=0;
			head[j]=(list *)malloc(sizeof(list));
			head[j]->value=j;
			head[j]->next=NULL;
		}
		for(j=1;j<n;j++)
		{
			scanf("%d %d",&a,&b);
			list *tmp=(list *)malloc(sizeof(list));
			tmp->value=b;
			itr=head[a]->next;
			head[a]->next=tmp;
			tmp->next=itr;

			list *node=(list *)malloc(sizeof(list));
			node->value=a;
			itr=head[b]->next;
			head[b]->next=node;
			node->next=itr;
		}
		dfs(head[1],0);
		for(j=1;j<=n;j++)
			boo[j]=0;
		max=0;
		dfs(head[val],0);
		printf("%d\n",max+1);	
	for(j=1;j<=n;j++)
		boo[j]=0;
	max=0;val=0;
	free(head[0]);
	}
	return 0;
}


