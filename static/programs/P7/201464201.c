#include<stdio.h>
long long int newa[1000005];
void merge(long long int a[], long long int s, long long int e)
{
	int t;
	//	printf("\n");
	//      printf("s==%d e==%d\n", s,e);
	int i,j,k,l,p;
	i=s;
	j=(s+e)/2+1;
	k=s;
	// printf("%d %d %d %d", i,j,(s+e)/2,e);
	while(i<=(s+e)/2 && j<=e)
	{
		if(a[i]<a[j])
		{
			newa[k]=a[i];
			//    a[k]=newa[k];
			k++;i++;
			//      printf("%d", newa[k]);
		}
		else
		{
			newa[k]=a[j];
			//   a[k]=newa[k];
			k++;j++;
			//     printf("%d", newa[k]);
		}
	}
	if(i>(s+e)/2)
	{
		for(p=j;p<=e;p++)
		{
			newa[k]=a[p];
			//    a[k]=newa[k];
			k++;
			//   printf("%d", newa[k]);
		}
	}
	else
	{
		for(p=i;p<=(s+e)/2;p++)
		{
			newa[k]=a[p];
			//   a[k]=newa[k];
			k++;
			// printf("%d", newa[k]);
		}
	}
	for(t=s;t<=e;t++)
	{
		a[t]=newa[t];
	}
}

int mergesort(long long int a[], long long int s, long long int e)
{
	//      printf("s=%d e=%d\n",s,e );
	if(s==e)
	{
		return;
	}
	else
	{
		mergesort(a,s,(s+e)/2);
		mergesort(a,(s+e)/2+1,e);
		merge(a,s,e);
	}
}

int main()
{
	long long int a[1000000],i,j,e,s,p,n,test,t,sum,count;
	scanf("%lld", &test);
	for(t=0;t<test;t++)
	{
		sum=0;
		count=1;
		scanf("%lld", &n);
		for(i=0;i<n;i++)
		{
			scanf("%lld", &a[i]);
		}
		s=0;
		e=n-1;
		mergesort(a,s,e);
	/*	for(i=0;i<n;i++)
		{
			printf("%lld ", newa[i]);
		}

		      printf("\n");*/
		for(j=0;j<n-1;j++)
		{
			if(newa[j]==newa[j+1])
			{
				count++;
			}
			else
			{
				sum=sum+(count*(count-1))/2;
				count=1;
			}
			if(j==n-2)
			{
				sum=sum+(count*(count-1))/2;
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}

