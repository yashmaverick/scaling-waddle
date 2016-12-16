#include<stdio.h>
int main()
{
	int t,i,j,k;
	scanf("%d",&t);
	while(t)
	{
		long long p,q,r;
		scanf("%lld",&p);
		long long a[p];
		for(i=0;i<p;i++)
			scanf("%lld",&a[i]);
		scanf("%lld",&q);
		long long b[q];
		for(i=0;i<q;i++)
			scanf("%lld",&b[i]);
		scanf("%lld",&r);
		long long c[r];
		for(i=0;i<r;i++)
			scanf("%lld",&c[i]);

		long long arrb[q],arrc[r];
		int y=r;
		for(i=0;i<r;i++)
		{
			arrc[i]=y;
			y--;
		}
		long long temp=r-1;
		long long count=0;
	/*	for(i=0;i<p;i++)
			printf("%lld",a[i]);
		printf("\n");
		for(i=0;i<q;i++)
			printf("%lld",b[i]);
		printf("\n");
		for(i=0;i<r;i++)
			printf("%lld",c[i]);
		printf("\n");
*/
		for(i=q-1;i>=0;i--)
		{
			if(temp>=i)
			{
			for(j=temp;j>=i;j--)
			{
				//printf("%d ",j);
				//printf("%d %d ",c[j],b[i]);
				if(c[j]<b[i])
				{
					
					break;
				}

			}
							
			temp=j;
			j++;
			if(j<r)
			count=count+arrc[j];
			
			if(b[i]==b[i-1])
				temp++;
			}
			arrb[i]=count;
			
		}
	//	for(i=0;i<q;i++)
	//		printf("%lld ",arrb[i]);
	//	printf("\n");
		//printf("%lld\n",count);
		temp=q-1,count=0;
		for(i=p-1;i>=0;i--)
		{
			
			if(temp>=i)
			{
			for(j=temp;j>=i;j--)
			{
				//printf("%d ",j);
				//printf("%d %d ",c[j],b[i]);
				if(b[j]<a[i])
				{
					
					break;
				}

			}
							
			temp=j;
			j++;
		//	printf("%d %lld ",j,arrb[j]);
			if(j<q)
			count=count+arrb[j];
			if(a[i]==a[i-1])
				temp++;
		//	printf("%lld\n",count);
			}
			
			
		}

		printf("%lld\n",count);
		t--;
	}
	return 0;
}
