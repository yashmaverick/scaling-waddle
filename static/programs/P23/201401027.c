#include<stdio.h>
#include<stdlib.h>
#define Max 1000007
int degree[Max],min[Max],size,arr1[20],arr2[20];
/*int compare(int a,int b)
{
	int i=0,j=0;
	while(a)
	{
		arr1[i++]=a%10;
		a/=10;
	}
	while(b)
	{
		arr2[j++]=b%10;
		b/=10;
	}
	i--;j--;
	for(;i>=0&&j>=0;i--;j--;)
	{
		if(arr1[i]>arr2[j])
			return 1;
		else if(arr1[i]<arr[j])
			return -1;
	}
	return 0;
}*/
typedef struct list
{
	int data;
	struct list *next;
}list;
list *head[Max];
void swap(int p,int c)
{
	int t=min[p];
	min[p]=min[c];
	min[c]=t;
}
void insert(int a,int b)
{
	list *node=(list*)malloc(sizeof(list));
	node->data=b;
	node->next=head[a];
	head[a]=node;
}
void insmin(long long int c)
{
	long long int p=c/2;
	while(p>0 && min[p]>min[c])
	{
		swap(p,c);
		c=p;
		p=c/2;
	}
}
void heapify(long long int p)
{
	long long int c=2*p;
	while(c<=size)
	{
		if(c+1<=size && min[c]>min[c+1])
			c++;
		if(min[p]>min[c])
			swap(p,c);
		else
			break;
		p=c;
		c=2*p;
	}
}
int main()
{
	int tc,v,e,i,a,b,ans[1000000],l=0;
	//scanf("%d",&tc);
	tc=1;
	while(tc--)
	{
		size=0;
		l=0;
		scanf("%d%d",&v,&e);
		for(i=1;i<=v;i++)
			degree[i]=0;
		for(i=0;i<e;i++)
		{
			scanf("%d%d",&a,&b);
			insert(a,b);
			degree[b]++;
		}
		for(i=1;i<=v;i++)
			if(degree[i]==0)
			{
				min[++size]=i;
				insmin(size);
			}
		while(size!=0)
		{
			list *temp=head[min[1]];
			//printf("%d ",min[1]);
			ans[l++]=min[1];
			swap(1,size--);
			heapify(1);
			while(temp!=NULL)
			{
				degree[temp->data]--;
				if(degree[temp->data]==0)
				{
					min[++size]=temp->data;
					insmin(size);
				}
				temp=temp->next;
			}
		}
		int ll;
		for(ll=0;ll<l-1;ll++)
			printf("%d ",ans[ll]);
		printf("%d\n",ans[ll]);
	}
	return 0;
}
