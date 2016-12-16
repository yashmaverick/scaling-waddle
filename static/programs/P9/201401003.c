#include<stdio.h>
typedef struct bag
{
	long long int sum,size,index;
}bag;
bag a[1005],b[1005];
long long int temp[1000009],len=0,n,mod;
void merge(int start,int mid,int end)
{
	int k=start;
	int i=start;
	int j=mid+1,l;
	while(i<=mid && j<=end)
	{
		if(a[i].sum<=a[j].sum)
		{
			b[k].sum=a[i].sum;
			b[k].size=a[i].size;
			b[k].index=a[i].index;
			k++;
			i++;
		}
		else
		{
			b[k].sum=a[j].sum;
			b[k].size=a[j].size;
			b[k].index=a[j].index;
			k++;
			j++;
		}
	}
	if(i>mid)
	{
		while(j<=end)
		{
			b[k].sum=a[j].sum;
			b[k].size=a[j].size;
			b[k].index=a[j].index;
			k++;
			j++;
		}
	}
	if(j>end)
	{
		while(i<=mid)
		{
			b[k].sum=a[i].sum;
			b[k].size=a[i].size;
			b[k].index=a[i].index;
			k++;
			i++;
		}
	}
	for(l=start;l<=end;l++)
	{
		a[l].sum=b[l].sum;
		a[l].size=b[l].size;
		a[l].index=b[l].index;
//		printf("%lld %lld %lld\n",a[l].sum,a[l].index,a[l].size);
	}
	return ;
}
void mergesort(int start,int end)
{
	int mid;
	if(start>=end)
		return ;
	else
	{
		mid=(start+end)/2;
		mergesort(start,mid);
		mergesort(mid+1,end);
		merge(start,mid,end);
		return ;
	}
}
int main()
{
	long long int i,j,s,m;
	scanf("%lld %lld",&n,&mod);
	for(i=0;i<n;i++)
	{
		s=0;
		a[i].index=len;
		scanf("%lld",&m);
		a[i].size=m;
		for(j=0;j<m;j++)
		{
			scanf("%lld",&temp[len]);
			s=(s+temp[len])%mod;
			len++;
		}
		a[i].sum=s;
	}
//	for(i=0;i<n;i++)
//		printf("%lld %lld %lld\n",a[i].sum,a[i].index,a[i].size);
	mergesort(0,n-1);
//	for(i=0;i<n;i++)
//		printf("%lld %lld %lld\n",a[i].sum,a[i].index,a[i].size);
	for(i=0;i<n;i++)
	{
		printf("%lld\n",a[i].sum);
		for(j=0;j<a[i].size;j++)
		{
			printf("%lld\n",temp[j+a[i].index]);
		}
		printf("\n");
	}
	return 0;
}
