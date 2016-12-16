#include<stdio.h>
#include<stdlib.h>

typedef struct list {
	int val;
	struct list *next;
}list;

list *arr[1000005];
int leaf,large=0;

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

void dfs(list *head,int c[]){
	c[head->val]=1;

	list *temp;
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		if(c[temp->val]!=1)
		{
			dfs(arr[temp->val],c);
			return;
		}
	}

	if(head->next!=NULL && head->next->next==NULL && c[head->next->val]==1)
		leaf=head->val;
}

void path(list *head,int b , int d[]){
	if(d[head->val]==1)
		return;
	b++;
	if(large<b)
		large=b;	

	d[head->val]=1;

	while(head->next!=NULL)
	{
		//			printf("%d %d\n",b,head->val);
		head=head->next;
		path(arr[head->val],b,d);
	}
	return;
}

int main()
{	
	int t,n,a,b,i;	
	scanf("%d",&t);
	while(t--)
	{
		int c[1000005]={0};
		scanf("%d",&n);
		//		c=(int *)malloc(sizeof(int)*(n));
		for(i=1;i<=n;i++)
		{	arr[i]=(list *)malloc(sizeof(list));
			arr[i]->val=i;	
			arr[i]->next=NULL;
		}

		n--;
		while(n--)
		{
			scanf("%d%d",&a,&b);
			insert(arr[a],b);
			insert(arr[b],a);
		}
		//		inserting done

		// finding the leaf
		dfs(arr[1],c);
		/*	list *head=arr[1];
			while(head!=NULL)
			{
			printf("\n''%d'' ",head->val);
			head=head->next;

			}
		 */
		//		printf("%d %d\n",leaf,large);
		large=0;
		int d[1000005]={0};

		//finding the longest path from leaf
		path(arr[leaf],0,d);

		printf("%d\n",large);
	}
	return 0;
}