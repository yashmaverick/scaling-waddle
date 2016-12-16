#include<stdio.h>
/*int count(long long int a[],int s,int k)
{
	int i,count;
	long long int min;
	min=1000000000;
	for(i=s;i<=(s+k-1);i++)
		{
			if(a[i]<min)
			{
				min=a[i];
				count=1;
			}
			if(a[i]=min)
			{
				count++;
			}
		}
		return count;
}*/
int min(long long int a[],int s,int k)
{
	int i;
	long long int min;
	min=1000000000;
	for(i=s;i<=(s+k-1);i++)
		{
			if(a[i]<min)
			{
				min=a[i];
			}
		}
		return min;
}
int main()
{
	int t,n=0,k,i;
	long long int a[10001],b[10001],c[10001];
	scanf("%d",&t);
	while(t--)
	{
		for(i=1;i<=n;i++)
			b[i]='\0';
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		b[1]=min(a,1,k);
		printf("%lld",b[1]);
		//if(n>1)
			//printf(" ")
		/*c[1]=count(a,1,k);*/
		for(i=2;i<=n-k+1 ;i++)
		{
			printf(" ");
			if(a[i-1]==b[i-1] && a[i+k-1]>b[i-1]/* && c[i]==1*/)
			{
				b[i]=min(a,i,k);
				//c[i]=count(a,i,k);
			}
			else if(a[i-1]==b[i-1] && a[i+k-1]<=b[i-1]/*c[i]>1*/)
			{
				b[i]=a[i+k-1];	
			}
			else if(a[i-1]!=b[i-1] && a[i+k-1]>b[i-1])
			{
				b[i]=b[i-1];
			}
			else if(a[i-1]!=b[i-1] && a[i+k-1]<=b[i-1])
			{
				b[i]=a[i+k-1];
			}	
			printf("%lld",b[i]);
		}
		printf("\n");
	}
	return 0;
}