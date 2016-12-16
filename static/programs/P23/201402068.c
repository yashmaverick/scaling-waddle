#include <stdio.h>
#include <stdlib.h>
typedef struct ll{
	int d;
	struct ll *next;
}ll;
void insert(int val,int *arr);
int  delete(int *arr);
int ins2;
int main()
{
	int n,m;
	int x,y;
	scanf("%d%d",&n,&m);
	ll *a[500005];
	int heap[500005]={};
	int i;
	for(i=0;i<=n;i++)
		a[i]=NULL;
	int count[500005]={};
	int t=m;
	ins2=1;
	while(t--)
	{
		scanf("%d%d",&x,&y);
		count[y]++;
		ll *temp;
		temp=(ll*)malloc(sizeof(ll));
		temp->d=y;
		temp->next=NULL;
		if(a[x]==NULL)
		{
			a[x]=malloc(sizeof(ll));
			a[x]=temp;
		}
		else
		{
			temp->next=a[x];
			a[x]=temp;
		}
	}
	/*for(i=1;i<=n;i++)
	  printf("%d ",count[i]);
	  printf("\n");*/
	for(i=1;i<=n;i++)
		if(count[i]==0)
			insert(i,heap);
	ll *temp;
	while(1)
	{
		int x=delete(heap);
		temp=a[x];
		while(temp!=NULL)
		{
			count[temp->d]--;
			if(count[temp->d]==0)
				insert(temp->d,heap);
			temp=temp->next;
		}
		if(ins2==1)
		{
			printf("%d",x);
			break;
		}

		printf("%d ",x);
	}
	printf("\n");


	return 0;
}
void insert(int val,int *arr)
{
	arr[ins2]=val;
	ins2++;
	int x=ins2-1;
	while(arr[x/2]>arr[x] && x>1)
	{
		int temp=arr[x];
		arr[x]=arr[x/2];
		arr[x/2]=temp;
		x=x/2;
	}
}
int delete(int *arr)
{

	int ret=arr[1];
	arr[1]=arr[--ins2];
	arr[ins2]=0;
	int x=1;
	while((arr[x]>arr[2*x] && arr[2*x]!=0) || (arr[x]>arr[2*x+1] && arr[2*x+1]!=0) && 2*x<=(ins2-1))
	{
		if(arr[2*x+1]<arr[2*x] && arr[2*x+1]!=0)
		{
			int temp=arr[x];
			arr[x]=arr[2*x+1];
			arr[2*x+1]=temp;
			x=2*x+1;
		}
		else
		{
			int temp=arr[x];
			arr[x]=arr[2*x];
			arr[2*x]=temp;
			x=2*x;
		}
	}
	return ret;
}
