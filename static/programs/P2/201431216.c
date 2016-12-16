#include<stdio.h>
int main()
{
	long long int a[100010],b[100010],c[100010],multi1,multi0,i;
	int test;
	scanf("%d",&test);
	for(i=0;i<test;i++)
	{
		long long int n,j;
		scanf("%lld",&n);
		for(j=0;j<n;j++)
		{
			scanf("%lld",&a[j]);
		}
		long long int p;
		scanf("%lld",&p);
		for(j=0;j<p;j++)
		{
			scanf("%lld",&b[j]);
		}
		long long int q;
		scanf("%lld",&q);
		for(j=0;j<q;j++)
		{
			scanf("%lld",&c[j]);
		}
		long long int sum=0,m;
		for(j=0;j<p;j++)
		{  
			multi0=0;
			multi1=0;
			if(a[j]<=b[j])
			{       multi0=j+1;
				//printf("%d xx ",multi0);
				if(c[j]>=b[j])
				{
					 multi1=q-j;
				          //printf("%d ",multi1);
				}
				else if(c[j]<b[j])
				{
					//printf("xxxx  \n");
					for(m=j+1;c[m]<b[j];m++)
					{};
					//printf("xxx  \n");
					multi1=q-m;
				}
                              
                       }
			
			if(a[j]>b[j])
			{
				for(m=j-1;a[m]>b[m];m--)
				{};
				multi0=m+1;
				if(c[j]>=b[j])
				{
					multi1=q-j;
				}
				else if(c[j]<b[j])
				{
					for(m=j+1;c[m]<b[j];m++)
					{};
					multi1=q-m;
				}
			}

			
			//printf("xxxx    \n");
			//printf("%d ==  %d",multi0,multi1);
			sum=sum+multi0*multi1;
		}
		printf("%lld\n",sum);
	}
	return 0;
}






