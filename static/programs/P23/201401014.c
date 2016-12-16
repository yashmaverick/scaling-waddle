#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node node;
int indegree[100005],heap[100005],n,m,heapsize,min_ele,visited[100005];
node *A[100005];
int min(int a,int b )
{
		if(a<b)
			return a;
		else
			return b;
}

void adj_list(int vi, int vj)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->data=vj;
	indegree[vj]++;
	temp->next=NULL;
	if(A[vi]==NULL)
		A[vi]=temp;
	else
	{
		temp->next=A[vi];
		A[vi]=temp;	
	}
}

void delete_min()
{
	int tep,var,min_ind,ifmin,min_in;
//	min_ele=heap[1];
	heap[1]=heap[heapsize];
//	printf("heap[1]: %d\n",heap[1]);
	heapsize--;
	if(heapsize==0)
		return;
	else
	{
		tep=1;		
		while(1)
		{
			//both child exists
			if(((2*tep)+1)<=heapsize )
			{
				if(heap[tep]>min(heap[2*tep],heap[(2*tep)+1]))
				{
					min_in=min(heap[2*tep],heap[(2*tep)+1]);
					if(min_in==heap[2*tep])
						min_ind=2*tep;
					else
						min_ind=2*tep+1;
			//		printf("heap[min_ind]: %d\n",heap[min_ind]);
					var=heap[tep];
					heap[tep]=heap[min_ind];
					heap[min_ind]=var;
					tep=min_ind;
	//				printf("\n%d %d\n",heap[tep],heap[min_ind]);
				}
				else
					break;
			}
			// only left child exists
			else if(((2*tep)+1)>heapsize && (2*tep)<=heapsize)
			{
				if(heap[tep]>heap[2*tep])
				{
					var=heap[tep];
					heap[tep]=heap[2*tep];
					heap[2*tep]=var;
					tep=2*tep;
				}
				else
					break;
			}
			//no child exists
			else
				break;
		//	printf("  heap[1] inside: %d\n",heap[1]);
		}
	}
}

void heap_insert(int vi)
{
	int tep,var;
	heapsize++;
	heap[heapsize]=vi;
	tep=heapsize;
//	printf("heapsize: %d\n",tep);
//	printf("\n%d %d\n",heap[tep],heap[tep/2]);
	while(heap[tep]<heap[tep/2] && tep>=2)
	{
//		printf("while\n");
		var=heap[tep];
		heap[tep]=heap[tep/2];
		heap[tep/2]=var;
		tep=tep/2;
	}
}

int main()
{
	int i,j,a,b,count,cnt,k;
	node *temp;
	scanf("%d%d",&n,&m);
//	if(m!=0)
//	{
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		adj_list(a,b);
	}
	count=0;
	cnt=0;
	for(i=1;i<=n;i++)
	{
		if(indegree[i]==0)
		{
			count++;
			heap_insert(i);
		}
	}
/*	printf("heapsize: %d\n",heapsize);
	for(i=1;i<=n;i++)
		printf("%d: %d\n",i,heap[i]);
	printf("\n"); */
		while(1)
		{
	//		printf("   --------   \n");
	//		for(k=1;k<=heapsize;k++)
	//			printf("%d ",heap[k]);
//			printf("\n");
			if(cnt<n-1)
			{
				printf("%d ",heap[1]);
	//			printf("t\n");
			}
			else
			{
				printf("%d\n",heap[1]);
				break;
			}
			min_ele=heap[1];
//			printf("min: %d\n",min_ele);
			cnt++;
			visited[min_ele]=1;
			delete_min();
/*			printf("  delete   --\n");
			for(k=1;k<=heapsize;k++)
				printf("%d ",heap[k]);
			printf("\n   -- delete\n");*/
			temp=A[min_ele];
	//		printf("A[min]: %d",temp->data);
			while(temp!=NULL)
			{
				if(visited[temp->data]==0)
				{
					indegree[temp->data]--;
					if(indegree[temp->data]==0)
						heap_insert(temp->data);
				}
				temp=temp->next;
			}
/*			printf("\n   ---   \n");
			for(k=1;k<=heapsize;k++)
				printf("%d ",heap[k]);
			printf("\n    ---\n"); */
		}

//	}
return 0;
}		
