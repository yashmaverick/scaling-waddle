#include<stdio.h>
long long int B[1000010],A[1000001];
void mergesort(long long int A[],long long int min,long long int mid,long long int max)
{
	long long int i,j,k,m;
	i=min;
	j=mid+1;
	m=i;
	while(i<=mid && j<=max)
	{
		if(A[i]>A[j])
		{
			B[m]=A[j];
			j++;
		}
		else
		{
			B[m]=A[i];
			i++;
		}
		m++;
	}
	if(i>mid)
	{
		for(k=j;k<=max;k++)
		{
			B[m]=A[k];
			i++;
			m++;
		}
	}
	else
	{
		for(k=i;k<=mid;k++)
		{
			B[m]=A[k];
			i++;
			m++;
		}
	}
	for(i=min;i<=max;i++)
	{
		A[i]=B[i];
	}					   
}
void divide(long long int A[],long long int min,long long int max)
{
	long long int mid=(min+max)/2;
	if(min<max)
	{
		divide(A,min,mid);
		divide(A,mid+1,max);
		mergesort(A,min,mid,max);
	}
}
int main()
{
	long long int i,l,j,E,k;
	long long int n,u,t;
	scanf("%lld",&t);
	for(u=0;u<t;u++)
	{
		l=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&A[i]);
		divide(A,0,n-1);
		j=0;
		while(j<=n-1)
		{
			E=1;
			k=j+1;
			while(k<=n)
			{
				if(A[j]==A[k])
				{
					E++;
					k++;
				}
				else
					break;
			}
			if(E>=2)
			{
				E=(E*(E-1))/2;
				l=l+E;
			}
			j=k;
		}
		printf("%lld\n",l);
	}
	return 0;
}
