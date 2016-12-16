#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct node
{
	int data;
	struct node* next;
}node;



node *graph[1000000];

void ginsert(int val1,int val2)
{
	node *temp=(node*)malloc(sizeof(node));
	temp->data=val2;
	temp->next=graph[val1];
	graph[val1]=temp;
	return;
}

int dependency[1000001];

int heap[1000001];

int end=1;

void swap(int val1,int val2)
{
	int temp=heap[val1];
	heap[val1]=heap[val2];
	heap[val2]=temp;
	return;
}

void upchecker()
{
	int val=end-1;
	while(val>1&&heap[val]<heap[val/2])
	{
		swap(val,val/2);
		val=val/2;
	}
	return;
}

void downchecker(int dval)
{
	if(dval==end-1||2*dval>end-1)
		return;
	int sval;
	int flag=0;
	if(2*dval+1>end-1)
	{
		if(heap[dval]>heap[2*dval])
		{
			swap(dval,2*dval);
		}
		return;
	}
	if(heap[dval]>heap[2*dval])
	{
		if(heap[2*dval]>heap[2*dval+1])
			sval=2*dval+1;
		else
			sval=2*dval;
		swap(sval,dval);
		flag=1;
	}
	else if(heap[dval]>heap[2*dval+1])
	{
		//if(heap[2*dval]<heap[2*dval+1])
		//	sval=2*dval;
		sval=2*dval+1;
		swap(sval,dval);
		flag=1;
	}
	if(flag)
		downchecker(sval);
	return;
}

void insert(int val)
{
	//printf("inserted\n");
	heap[end++]=val;
	//	printf("insert end is %d\n",end);
	upchecker();
	return;
}

int delete()
{
	//printf("deleted\n");
	int temp=heap[1];
	heap[1]=heap[end-1];
	if(end!=1)
		end--;
	downchecker(1);
	return temp;
}

void print()
{
	int i=1;
	for(i=1;i<end;i++)
	{
		printf("%d ",heap[i]);
	}
}


int main()
{
	int z;
	int N,M,i,j,k,val1,val2;
	scanf("%d",&N);
	for(z=0;z<=N;z++)
	{
		dependency[z]=0;
	}
	scanf("%d",&M);
	for(j=0;j<M;j++)
	{
		scanf("%d%d",&val1,&val2);
		dependency[val2]=dependency[val2]+1;
		ginsert(val1,val2);
	}
	int m=0, loopvar=0;
	int state=0;
	for(k=1;k<=N;k++)
	{
		if(dependency[k]==0)
		{
			insert(k);
		//	printf("Insert\n");
		//	for(i=1;i<end;i++)
		//	printf("h%d ",heap[i]);
		//	putchar(10);
			state=1;
		}
		else 
		{
			if(state==1)
				continue;
		}
	}
	/*	for(k=1;k<=N;k++)
		{
		if(dependency[k][0]==0)
		{
		state=0;
		break;
		}
		else
		state=1;
		}*/
	if(state==0)
	{
		printf("-1\n");
		return 0;
	}
	do
	{
		//print();
		int val=delete();

		//printf("Delete\n");
		//for(i=1;i<end;i++)
		//	printf("h%d ",heap[i]);
		//putchar(10);
		//	printf("deleted val %d\n",val);
		node *temp=graph[val];
		while(temp!=NULL)
		{
			dependency[temp->data]=dependency[temp->data]-1;
			if(dependency[temp->data]==0)
			{
				insert(temp->data);

				//printf("Insert\n");
				//for(i=1;i<end;i++)
				//	printf("h%d ",heap[i]);
				//putchar(10);

			}
			temp=temp->next;
		}
		loopvar++;
		if(end==1)
			printf("%d",val);
		else 
			printf("%d ",val);
	}while((end)!=1);
	printf("\n");

	return 0;
}
