#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int value;
	struct node* next;
}node;

node * arr[1000006];

int min_heap[1000006],min_end=0;

void insert_min(int a)
{
	min_end++;
	min_heap[min_end]=a;

	int c,f,temp;

	c=min_end;
	f=c/2;

	while(min_heap[f]>min_heap[c])
	{
		if(f<1)
			break;

		temp=min_heap[f];
		min_heap[f]=min_heap[c];
		min_heap[c]=temp;

		c=f;
		f=c/2;
	}
}

void delete_min()
{
	min_heap[1]=min_heap[min_end];
	min_end--;

	int f,c1,c2,temp,small;

	f=1;
	c1=f*2;
	c2=f*2+1;

	if(c2>min_end)
		min_heap[c2]=min_heap[c1]+1;

	while(min_heap[f]>min_heap[c1] || min_heap[f]>min_heap[c2])
	{
		if(c1>min_end)
			break;

		if(min_heap[c1]>min_heap[c2])
			small=c2;
		else
			small=c1;

		temp=min_heap[f];
		min_heap[f]=min_heap[small];
		min_heap[small]=temp;

		f=small;
		c1=f*2;
		c2=f*2+1;

		if(c2>min_end)
			min_heap[c2]=min_heap[c1]+1;
	}
}

node * insert(int value, node* root)
{
	node* temp=(node *)malloc(sizeof(node));
	temp->value=value;
	temp->next=root;
	return temp;
}
int in_count[1000006],done[1000006];

void check(node *u)
{
	delete_min();
	while(u)
	{
		in_count[u->value]--;
	//	printf("incount %d-----%d\n",u->value,in_count[u->value]);
		if(in_count[u->value]==0)
		{
			if(done[u->value]==0)
			{
	//			printf("conn----%d\n",u->value);
	
				insert_min(u->value);
				done[u->value]=-1;
			}
		}
		u=u->next;
	}
}

int main()
{
	int n,m,x,y,final[1000006],index=0,i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		arr[x]=insert(y,arr[x]);

		in_count[y]++;
	}
	for(i=1;i<=n;i++)
	{
		if(in_count[i]==0)
		{
		//	printf("i----%d\n",i);
			if(done[i]==0)
			{
				insert_min(i);
				done[i]=-1;
			}
		}
	}

//	printf("@@@@@@@ %d @@@@@@\n",done[1]);
	while(index!=n)
	{
		index++;
		final[index]=min_heap[1];
	//	printf("calling-----%d\n",min_heap[1]);
		check( arr[min_heap[1]] );
		//delete_min();
	}

	for(i=1;i<=index-1;i++)
		printf("%d ",final[i]);
	printf("%d\n",final[index]);

	return 0;
}
