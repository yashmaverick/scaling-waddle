#include<stdio.h>
#include<stdlib.h>


typedef struct node
{

	struct node *next;
	long long int data;
}node;

node *a[1000001],*b[1000001];
long long int heapmin[1000001],mintop=0,visited[1000001],answer[1000001],printed[1000001]; 

void swap(long long int *a, long long int *b)
{
	long long int temp=*a;
	*a=*b;
	*b=temp;

}

void pushminheap(long long int n)
{
	mintop++;
	heapmin[mintop]=n;

	long long  int temp=mintop;

	while(temp > 1)
	{
		long long int parent=temp/2;

		if(heapmin[parent] > heapmin[temp])
		{
			swap(&heapmin[temp],&heapmin[parent]);
			temp=parent;
		}

		else
			break;
	}
}

long long int popminheap()
{
	long long int min=heapmin[1];
	heapmin[1]=heapmin[mintop];
	
	long long int index=1;

	while ( index <= (mintop-1)/2 && (heapmin[index] > heapmin[2*index] || heapmin[index] > heapmin[2*index+1]) )
	{
		long long int temp=2*index;
		if(heapmin[2*index] > heapmin[2*index+1])
			temp++;

		if(heapmin[temp] < heapmin[index])
		{
			swap(&heapmin[index],&heapmin[temp]);
			index=temp;
		}

		else
		{
			mintop--;
			return min;
		}
	}

	mintop--;
	return min;
}


void dfs(long long int visited[],node *a[],long long int current)
{
	visited[current]+=1;

	node *temp=a[current];

	while(temp)
	{
		if(visited[temp->data]==0)
			dfs(visited,a,temp->data);	

		temp=temp->next;
	}	

}

int main()
{
	long long int n,m,i;
	scanf("%lld %lld",&n,&m);


	for(i=1;i<1000001;i++)
	{
		a[i]=NULL;
		b[i]=NULL;
		visited[i]=0;
	}

	for(i=1;i<=m;i++)
	{
		long long int t1,t2;
		scanf("%lld %lld",&t1,&t2);

		node *temp=(node *)malloc(sizeof(node));

		temp->next=a[t1];           //   after
		a[t1]=temp;
		temp->data=t2;	
	
		temp=(node *)malloc(sizeof(node));

		temp->next=b[t2];          //   before
		b[t2]=temp;
		temp->data=t1;	
	}

	


	for(i=1;i<=n;i++)
		if(b[i]==NULL)
		{
//			printf("%lld ",i);

			pushminheap(i);
			visited[i]=1;
		}

	long long int aaa=0;
/*	for(i=1;i<=n;i++)
	{
		node *temp100=b[i];

		while(temp100)
		{
			printf("%lld %lld \n",i,temp100->data);
			temp100=temp100->next;
		}
		printf("\n");
	}
*/
	while(mintop)
	{
		long long int current=popminheap();
//		if(current==2 && visited[8]==1 )
//			printf("YES\n");

		answer[aaa++]=current;
		printed[current]=1;

//		printf("%lld ",current);

		node *temp=a[current];

		while(temp)
		{
			long long int temp10=temp->data,flag=0;

			node *temp20=b[temp10];
			while(temp20)
			{
				if(printed[temp20->data]==0)
				{	
					flag=1;
					break;
				}

				temp20=temp20->next;
			}

			if(flag==0)
			{
				if(visited[temp->data]==0)
				{
					pushminheap(temp->data);
					visited[temp->data]=1;
				}
			}

			temp=temp->next;
		}
		
	}

	
//	dfs(visited,a,i);

	


	for(i=0;i<aaa;i++)
	{
		if(i==0)
			printf("%lld",answer[i]);
		else
			printf(" %lld",answer[i]);
	}
	printf("\n");

	return 0;
}
