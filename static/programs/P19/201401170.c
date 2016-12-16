#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
	struct node *b[10];
}node;
long long int z,flag1;
long long int digit[100];
void quicksort(long long int a[],long long int low,long long int high)
{
	if(low>high)
		return;
	long long int wall,pivot,temp,i;
	pivot=high;
	wall=low;
	for(i=low;i<high;i++)
	{
		if(a[i]>a[pivot])
		{
			temp=a[i];
			a[i]=a[wall];
			a[wall]=temp;
			wall++;
		}
	}
	temp=a[wall];
	a[wall]=a[pivot];
	a[pivot]=temp;
	quicksort(a,low,wall-1);
	quicksort(a,wall+1,high);
	return;
}
void load(long long int x)
{
	long long int y;
	if(x==0)
		return;
	y=x%10;
	x=x/10;
	load(x);
	digit[z++]=y;
}
node*insert(node*head,long long int x)
{
	z=0;
	long long int i,j,status=0;
	if(x==0)
	{
		z=1;
		digit[0]=0;
	}
	else
	{
		load(x);
	}
	node*start=head;
	for(i=0;i<z;i++)
	{
		if(head->b[digit[i]]==NULL)
		{
			node*temp=(node*)malloc(sizeof(node));
			for(j=0;j<10;j++)
				temp->b[j]=NULL;
			head->b[digit[i]]=temp;
			head=head->b[digit[i]];
		}
		else
		{
			status++;
			head=head->b[digit[i]];
		}
	}
	if(status==z)
	{
		flag1=1;
	}
	return start;
}
int main()
{
	long long int a[1000005];
	long long int t,flag2;
	scanf("%lld",&t);
	node*root=NULL;
	while(t--)
	{
		flag1=0;
		root=(node*)malloc(sizeof(node));
		long long int n,i,j,x;
		for(i=0;i<10;i++)
		{
			root->b[i]=NULL;
		}
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		quicksort(a,0,n-1);
		for(i=0;i<n;i++)
		{
			if(flag1==1)
				break;
			root=insert(root,a[i]);
		}
		if(flag1==0)
			printf("YES\n");
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
