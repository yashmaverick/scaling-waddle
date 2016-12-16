#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next[10];
};
typedef struct node node;
node *root=NULL;
int flag=0;
void mergesort(long long int a[],long long int s,long long int e,long long int temp2[])
{
	if(s==e)
		return ;
	long long int mid=(s+e)/2;
	mergesort(a,s,mid,temp2);
	mergesort(a,mid+1,e,temp2);
	long long int i=s,j=(mid+1),k=0;
	while(i<=mid || j<=e)
	{
		if(i>mid)
			temp2[k++]=a[j++];
		else if(j>e)
			temp2[k++]=a[i++];
		else
		{
			if(a[i]<a[j])
				temp2[k++]=a[i++];
			else
				temp2[k++]=a[j++];
		}
	}
	long long int p;
	for(p=0;p<k;p++)
		a[s+p]=temp2[p];
}

void insert(long long int b[],long long int siz)
{
	long long int i,in,j;
	if(root==NULL)
	{
		node* temp=malloc(sizeof(node));
		temp->data=999;
		for(i=0;i<10;i++)
			temp->next[i]=NULL;
		root=temp;
	}
	node* new=root;
	for(i=0;i<=siz;i++)
	{
		in=b[i];
		if(new->next[in]==NULL)
		{
			node* temp1=malloc(sizeof(node));
			temp1->data=999;
			for(j=0;j<10;j++)
				temp1->next[j]=NULL;
			new->next[in]=temp1;
		}
		else
		{
			if(i==siz)
			{
				flag=1;
				break;
			}
		}
		new=new->next[in];
	}
}
int main()
{
	int t,m;
	long long int n,i,j,ret,k,tmp,yt;
	long long int b[1000002]={};
	scanf("%d",&t);
	for(m=0;m<t;m++)
	{
		node* y=malloc(sizeof(node));
		y->data=999;
		for(i=0;i<10;i++)
			y->next[i]=NULL;
		root=y;
		flag=0;
		scanf("%lld",&n);
		long long int a[n];
		long long int temp2[n];
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		mergesort(a,0,n-1,temp2);
	//	for(i=0;i<n;i++)
	//		printf("%d ",a[i]);
	//	printf("\n");
		for(i=0;i<n/2;i++)
		{
			yt=a[i];
			a[i]=a[n-i-1];
			a[n-i-1]=yt;
		}
	//	for(i=0;i<n;i++)
	//		printf("%d ",a[i]);
	//	printf("\n");
		for(i=0;i<n;i++)
		{
			j=0;
			ret=a[i];
			while(ret>=10)
			{
				b[j]=ret%10;
				j++;
				ret=ret/10;
			}
			b[j]=ret;
			for(k=0;k<=j/2;k++)
			{
				tmp=b[k];
				b[k]=b[j-k];
				b[j-k]=tmp;
			}
			insert(b,j);
			if(flag==1)
				break;
		}
		if(flag==0)
			printf("YES\n");
		else if(flag==1)
			printf("NO\n");
	}
	return 0;
}
