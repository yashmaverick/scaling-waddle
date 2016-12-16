#include<stdio.h>
#include<stdlib.h>
int heap[100001],count[100001],ans[100001],l,end=1;
struct node{
	int val;
	struct node *next;
};
typedef struct node node;
node *k[100001];
node *insert(node *head,int x)
{
	if(head==NULL)
	{
		head=(node*)malloc(sizeof(node));
		head->val=x;
		head->next=NULL;
		return head;
	}
	else
	{
		head->next=insert(head->next,x);
		return head;
	}
}
int min(int j)
{
	if(heap[2*j]>heap[2*j+1])
		return 2*j+1;
	else
		return 2*j;
}
void shuffledown(int j)
{
	int temp;
	int k;
	if(2*j+1<=end-1)
	{
		k=min(j);
		if(heap[j]>heap[k])
		{
			temp = heap[k];
			heap[k] = heap[j];
			heap[j] = temp;
			shuffledown(k);
		}
		else
			return ;
	}
	else if(2*j==end-1)
	{
		if(heap[j]>heap[2*j])
		{
			temp=heap[2*j];
			heap[2*j]=heap[j];
			heap[j]=temp;
			shuffledown(2*j);
		}
	}
	else
		return ;
}
int deletemin()
{
	int j;
	heap[1] = heap[end-1];
	j=1;
	end--;
	shuffledown(j);
	return end;
}

int heapinsert(int a)
{	int j,temp;
	heap[end]=a;
	if(end>1)
	{
		j=end;
		while(heap[j/2]>heap[j]&& j>1)
		{
			temp=heap[j];
			heap[j]=heap[j/2];
			heap[j/2]=temp;
			j=j/2;
		}
	}
	return end+1;
}
void function()
{	
	if(end==1)
		return ;
	node *temp=k[heap[1]];
	int i;
	ans[l]=heap[1];
	l++;
	end=deletemin();
//	printf("%d\n",heap[1]);
	while(temp!=NULL)
	{
		count[temp->val]--;
		if(count[temp->val]==0)
			end=heapinsert(temp->val);
	//	for(i=1;i<=4;i++)
	//		printf("%d ",count[i]);
	//	printf("\n");
		temp=temp->next;

	}
	function();
}
void print(node *head)
{
	if(head==NULL)
		return ;
	else
	{
		printf("%d ",head->val);
		print(head->next);
	}
}
int main()
{
	int n,m,i,a,b;
	end=1;
	l=0;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{	k[i]=NULL;
		ans[i]=0;
		heap[i]=0;
		count[i]=0;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&a,&b);
		k[a]=insert(k[a],b);
		count[b]+=1;
	}
	for(i=1;i<=n;i++)
	{
		if(count[i]==0)
			end=heapinsert(i);
	}
//	for(i=1;i<n;i++)
//	{	print(k[i]);
//		printf("\n");
//	}
	
//	printf("12\n");
//	for(i=1;i<end;i++)
//		printf("%d ",heap[i]);
//	printf("\n");
	function();
//	printf("fkasjf\n");
	for(i=0;i<n;i++)
	{	if(i==n-1)
			printf("%d\n",ans[i]);
		else
			printf("%d ",ans[i]);
	}
	return 0;
}



