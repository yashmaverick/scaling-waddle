#include<stdio.h>
int main()
{
	while(1)
	{
		long long int n;
		scanf("%lld",&n);
		if(n==0)
			return 0;
		else
		{
			long long int a[n],i=0,j=0,k=0,b[n],c[n];
			for(i=0;i<n;i++)
			{
				scanf("%lld",&a[i]);			
			}
			b[0]=-1;
			if(a[1]>a[0])
				b[1]=0;
			else 
				b[1]=-1;
	//		printf("b[0]=%d\nb[1]=%d\n",b[0],b[1]);
			for(i=2;i<n;i++)
			{
				j=i-1;
				k=i;
				while(k--)
				{
					if(a[j]<a[i])
					{	
						b[i]=j;
						break;
					}
					else
					{ 
						j=b[j];
						if(j==-1)
						{	b[i]=j;
							break;
						}
					}

				}
	//			printf("b[%d]=%d\n",i,b[i]);
			}
			c[n-1]=n;
			if(a[n-2] > a[n-1] )
				c[n-2]=n-1;
			else 
				c[n-2]=n;
	//		printf("c[n-1]=%d\nc[n-2]=%d\n",c[n-1],c[n-2]);
			for(i=n-3;i>=0;i--)
			{
				j=i+1;
				k=n-1-i;
				while(k--)
				{
					if(a[i]>a[j])
					{
						c[i]=j;
						break;
					}
					else
					{
						j=c[j];
						if(j==n)
						{	
							c[i]=j;
							break;
						}
					}
				}
	//			printf("c[%d]=%d\n",i,c[i]);
			}
			long long int area,maxarea=-1;
			for(i=0;i<n;i++)
			{
				c[i]=c[i]-b[i]-1;
	//			printf("c[%d]= %d\n",i,c[i]);
				area=c[i]*a[i];
	//			printf("area=%d\n",area);
				if(area>maxarea)
					maxarea=area;
			}
			printf("%lld\n",maxarea);
		}
	}
	return 0;
}
