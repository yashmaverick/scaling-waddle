#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmpfunc(const void *x,const void *y)
{
	return (*(int*)x-*(int*)y);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char c[100001];
		scanf("%s",c);
		int n,i,j,a[100001],l=0,k=1,sum=0;
		n=strlen(c);
		//printf("%lld\n",n);
		//593 7 -600
		//if(c[0]=='J')
		//	a[0]=1;
		//else if(c[0]=='M')
		//	b[0]=1;
		//else if(c[0]=='R')
		//	d[0]=1;
		//	printf("%lld %lld %lld\n",a[0],b[0],d[0]);
		for(i=0;i<n;i++)
		{		
			if(c[i]=='J')
				a[i]=594;
			else if(c[i]=='M')
				a[i]=7;
			else if(c[i]=='R')
				a[i]=-601;
		}
		for(i=1;i<n;i++)
		{
			a[i]=a[i]+a[i-1];	
		}
		qsort(a,n,sizeof(int),cmpfunc);
		//for(i=0;i<n;i++)
		//printf("%d\n",a[i]);
		int flag;	
		for(i=1;i<n;i++)
		{
			if(a[i]==a[i-1])
			{
				k++;

			}
			else if(a[i]!=a[i-1])
			{
				flag=1;
				sum=sum+k*(k-1)/2;
				k=1;
			}
		}
		sum=sum+k*(k-1)/2;
			k=0;
			for(i=0;i<n;i++)
			{
				if(a[i]==0)
					k++;	
			}
			printf("%d\n",sum+k);

			//		printf("%lld %lld %lld\n",a[i],b[i],d[i]);


	}	
		return 0;
	}
