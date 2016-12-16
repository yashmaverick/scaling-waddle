#include<stdio.h>
int main()
{
	long long int n;
	scanf("%lld",&n);
	while(n!=0)
	{
		
		long long int i,a[100000],b[100000],j,c[100000],sum=0,max=0;
	b[0]=-1;
	
		for(i=0;i<n;i++)
		{	scanf("%lld",&a[i]);
			//		if(i>0)
			//		{	
			//		if(a[i]!=a[i-1])
			//			flag=1;
			//		}
		}
		//	if(flag==1)
		//	{
		for(i=1;i<n;i++)
		{	
			j=i-1;
			if(a[i]>a[i-1])
				b[i]=i-1;
			else
			{	if(b[j]==-1)
				b[i]=-1;
				while(b[j]!=-1)
				{	
					if(a[b[j]]<a[i])
					{b[i]=b[j];
						break;
					}
					//	else if(a[b[j]]>=a[i] && b[j]==-1)
					//	{		b[i]=-1;
					//	prlong long intf("1\n");
					//			break;
					//	}
					else
					{
						j=b[j];
						//	prlong long intf("%lld\n",j);
					}
				}
				if(b[j]==-1)
					b[i]=-1;
			}
		}
//		for(i=0;i<n;i++)
//			printf("%lld ",b[i]);
//		printf("\n");
		c[n-1]=-1;
		for(i=n-2;i>=0;i--)
		{	j=i+1;
			if(a[i]>a[i+1])
				c[i]=i+1;
			else
			{	if(c[j]==-1)
				c[i]=-1;
				while(c[j]!=-1)
				{	
					if(a[c[j]]<a[i])
					{
						c[i]=c[j];
						break;
					}
					//	else if (a[c[j]]>=a[i] && c[j]==-1)
					//	{	c[i]=-1;
					//		break;
					//	}

					else
					{
						j=c[j];
					}
					if(c[j]==-1)
						c[i]=-1;
				}
			}
		}
//		for(i=0;i<n;i++)
//			printf("%lld ",c[i]);
//		printf("\n");
		for(i=0;i<n;i++)
		{
			if(c[i]!=-1)
				sum=a[i]*(c[i]-1-b[i]);
			else
				sum=a[i]*(n-1-b[i]);

			if(sum>max)
				max=sum;
		}
		printf("%lld\n",max);
		scanf("%lld",&n);
	}
	//	}
	//	else
	//		prlong long intf("%lld\n",n*a[0]);



	return 0;
}
