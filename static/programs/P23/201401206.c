#include<stdio.h>
#include<stdlib.h>

struct tree
{
	int no;
	struct tree *next;
};
typedef struct tree tree;
tree *insert(tree *new,int x)
{
	if(new==NULL)
	{
		new=(tree*)malloc(sizeof(tree));
		new->no=x;
		new->next=NULL;
	}
	else
		new->next=insert(new->next,x);
	return new;
}
int hsize=0;
int heap[100000];
void insheap(int x)
{
		int t;
		if(hsize==0)
		{
			hsize++;
			heap[hsize]=x;
		}
		else
		{
			hsize++;
			t=hsize;
			while(x < heap[t/2])
			{
				heap[t]=heap[t/2];
				heap[t/2]=x;
				t=t/2;
			}
			if(x > heap[t/2])
				heap[t]=x;
		}
}

void delete(int x)
{
	int min,t;
	if(2*x+1<=hsize)
	{
		if(heap[2*x] < heap[2*x+1])
			min=2*x;
		else
			min=2*x+1;
		if(heap[x]>heap[min])
		{
			t=heap[x];
			heap[x]=heap[min];
			heap[min]=t;
			delete(min);
		}
		else
		{
			x=1;
			return;
		}
	}
	else if(2*x==hsize)
	{
		if(heap[x] > heap[2*x])
		{
			t=heap[x];
			heap[x]=heap[2*x];
			heap[2*x]=t;
		}
	}
	else { x=1;
		return;
	}
}
int shuffled()
{
	int x=1;
	heap[1]=heap[hsize];
	hsize--;
	delete(x);
}
int main()
{
	int n,m,i;
	scanf("%d %d",&n,&m);
	tree *node[100000]={NULL};
	int count[100001]={0};
	int t=m;
	int ans[n];
	while(t--)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		node[x]=insert(node[x],y);
		count[y]++;
	}
	for(i=1;i<=n;i++)
	{
		if(count[i]==0)
			insheap(i);
	}
//	for(i=1;i<=hsize;i++)
//		printf("%d ",heap[i]);
//	printf("\n");
	i=0;int j;
	int c=0;
	while(hsize!=0)
	{
		int x=heap[1];
		printf("%d",heap[1]);
		c++;
		if(c!=n)
			printf(" ");
		shuffled();
		tree *temp=node[x];
		while(temp!=NULL)
		{
			count[temp->no]--;
			if(count[temp->no]==0)
				insheap(temp->no);
		//	for(j=1;j<=hsize;j++)
		//		printf("%d ",heap[j]);
		//	printf("\n");
			temp=temp->next;
		}
	}
	printf("\n");
	return 0;
}



