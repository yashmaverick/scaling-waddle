#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long int a[1000001],b[1000001],tmp[1000001];

void merge(long long int* arr,long long int min,long long int mid,long long int max)
{
	long long int i,j,k,m; 
	j=min;
	m=mid+1;
	for(i=min; j<=mid && m<=max ; i++)
	{
		if(arr[j]<=arr[m])
		{
			tmp[i]=arr[j];
			j++;
		}
		else
		{
			tmp[i]=arr[m];
			m++;
		}
	}
	if(j>mid)
	{
		for(k=m; k<=max; k++)
		{
			tmp[i]=arr[k];
			i++;
		}
	}
	else
	{
		for(k=j; k<=mid; k++)
		{
			tmp[i]=arr[k];
			i++;
		}
	}
	for(k=min; k<=max; k++)
		arr[k]=tmp[k];
}

void sort(long long int *arr,long long int min,long long int max)
{
	long long int mid;
	if(min<max)
	{
		mid=(min+max)/2;
		sort(arr,min,mid);
		sort(arr,mid+1,max);
		merge(arr,min,mid,max);
	}
}
long long int binsearch(long long int l,long long int u,long long int m,long long int *a)
{
	long long int mid;
	long long int c=0;
	while(l<=u)
	{
		mid=(l+u)/2;
		if(m==a[mid])
		{
			printf("NO\n");
			c=1;
			break;
		}
		else if(m<a[mid])
		{
			u=mid-1;
		}
		else
			l=mid+1;
	}
	return c;
}
int main()
{
	long long int t,q,i,f,j,ans;
	scanf("%lld",&t);

	while(t--)
	{
		ans=0;
		j=0;
		scanf("%lld",&q);

		for(i=0;i<q;i++)
		{
			scanf("%lld",&f);
			b[i]=f;
			while(f>9)
			{
				a[j++]=f/10;
				f=f/10;
			}
		}
		sort(a,0,j-1);
		sort(b,0,q-1);
//			int ananya;
//			for(ananya=0;ananya<q;ananya++)
//			printf("%d ",b[ananya]);
		for(i=q-2;i>=0;i--)
		{
			if(b[i]==b[i+1])
			{
				ans=1;

				printf("NO\n");
				break;
			}
		}
		if(ans!=1)
		{
			for(i=q-1;i>=0;i--)
			{
				ans=binsearch(0,j-1,b[i],a);
				if(ans==1)
					break;
			}
		}
		if(ans==0)
			printf("YES\n");
//			long long int ananya;
//			for(ananya=0;ananya<q;ananya++)
//			printf("%lld ",b[ananya]);
//			printf("\n");
//			for(ananya=0;ananya<j;ananya++)
//			printf("%lld ",a[ananya]);
//			printf("\n");
			
	}
	return 0;
}
