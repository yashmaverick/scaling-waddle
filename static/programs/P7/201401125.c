#include<stdio.h>
void merge(long long int[],long long int,long long int,long long int);
void part(long long int[],long long int,long long int);
int main()
{
	long long int a[1000007];
	long long int i,n,size,p,m,ans;
	scanf("%lld",&m);

	for(n=0;n<m;n++)
	{
		ans=0;
		scanf("%lld",&size);
		for(i=0;i<size;i++)
		{
			scanf("%lld",&a[i]);
		}
		part(a,0,size-1);

		for(i=0;i<size;i++)
		{
			p=1;
			while(a[i]==a[i+1])
			{
				p++;
				i++;
			}
			ans+=(p*(p-1))/2;
		}
		printf("%lld\n",ans);
	}
	return 0;

}
void part(long long int a[],long long int min,long long int max)
{
	long long int mid;
	if(min <max)
	{
		mid=(min+max)/2;
		part(a,min,mid);
		part(a,mid+1,max);
		merge(a,min,mid,max);
	}

}
void merge(long long int a[],long long int min,long long int mid,long long int max)
{
	long long int tmp[1000007]; 
	long long int i,j,k,m;
	j=min;
	m=mid+1;
	for(i=min;j<=mid && m<=max;i++)
	{
		if(a[j]<=a[m])
		{
			tmp[i]=a[j];
			j++;
		} 
		else
		{
			tmp[i]=a[m];
			m++;
		}
	}
	if(j>mid)
	{
		for(k=m;k<=max;k++)
		{
			tmp[i]=a[k];
			i++;
		}
	}
	else
	{for(k=j;k<=mid;k++)
		{
			tmp[i]=a[k];
			i++;
		}

	}
	for(k=min;k<=max;k++)
		a[k]=tmp[k];
}



