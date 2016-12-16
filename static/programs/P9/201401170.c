#include<stdio.h>
typedef struct node
{
	int val;
	int next;
	int end;
}node;
node a[1009];
node temp[1009];
void merge(node a[],int low,int mid,int high)
{
	int i,j,k;
	k=0;
	i=low;
	j=mid+1;
	while(i<=mid&&j<=high)
	{
		if(a[i].val<a[j].val)
		{
			temp[k++]=a[i++];
		}
		else if(a[i].val>a[j].val)
			temp[k++]=a[j++];
		else
		{
			temp[k++]=a[i++];
			temp[k++]=a[j++];
		}
	}
	while(i<=mid)
		temp[k++]=a[i++];
	while(j<=high)
		temp[k++]=a[j++];
	for(i=low,k=0;i<=high;i++,k++)
		a[i]=temp[k];
}
void merge_sort(node a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}

int main()
{
	int n,i,j,m,mod;
	node temp;
	int b[1000007];
	scanf("%d%d",&n,&mod);
	a[0].next=0;
	scanf("%d",&m);
	a[0].end=m-1;
	a[0].val=0;
	for(j=0;j<m;j++)
	{
		scanf("%d",&b[j]);
		a[0].val=(a[0].val%mod+b[j]%mod)%mod;
	}
	for(i=1;i<n;i++)
	{
		a[i].val=0;
		a[i].next=a[i-1].next+m;
		scanf("%d",&m);
		a[i].end=a[i-1].end+m;
		for(j=a[i].next;j<=a[i].end;j++)
		{
			scanf("%d",&b[j]);
			a[i].val=(a[i].val%mod+b[j]%mod)%mod;
		}
	}
	merge_sort(a,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i].val);
		for(j=a[i].next;j<=a[i].end;j++)
			printf("%d\n",b[j]);
		printf("\n");
	}
	return 0;
}
