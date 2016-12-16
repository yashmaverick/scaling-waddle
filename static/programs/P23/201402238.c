#include<stdio.h>
#include<stdlib.h>

//concept of lexicographic manner + dfs as in Q.P20

typedef struct list {
	int val;
	struct list *next;
}list;

list *arr[100005];
int c[100005]={0},u=-1,a[100005]={0};

void insert(list *head,int node)
{	
	if(head->next==NULL)
	{
		head->next=(list *)malloc(sizeof(list));
		head->next->val=node;
		head->next->next=NULL;
		//		printf("'%d' ",head->next->val);
		return;
	}
	//	printf("'%d' ",head->val);
	insert(head->next,node);
}

void dfs(list *head){
	if(c[head->val]==1)
		return;

	c[head->val]=1;

	list *temp;
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;

		//if(c[temp->val]!=1)
			dfs(arr[temp->val]);

	}

	a[++u]=head->val;

}

int main()
{	
	int n,m,i,g,b;	
		
		scanf("%d %d",&n,&m);

		for(i=1;i<=n;i++)
		{	arr[i]=(list *)malloc(sizeof(list));
			arr[i]->val=i;	
			arr[i]->next=NULL;
		}

		while(m--)
		{
			scanf("%d%d",&g,&b);
			insert(arr[g],b);
		}

		i--;
		while(n!=0)
		{
			dfs(arr[n]);
			n--;
		}

		printf("%d",a[u]);
		u--;
		for(i=u;i>=0;i--)
			printf(" %d",a[i]);
		printf("\n");
	return 0;
}