#include<stdio.h>
int main()
{
	while(1)
	{
		long long int t;
		scanf("%lld",&t);
		if(t!=0)
		{
			long long int a[100000],b[100000],c[100000];
			long long int i,j,k,l;
			for(i=0;i<t;i++)
			{
				scanf("%lld",&a[i]);
			}
			b[0]=-1;
			long long int min,max=0,sum,small;
			small=a[0];
			for(j=1;j<t;j++)
			{
				if(a[j]<=small)
				{
					small=a[j];
					b[j]=-1;
				}
				else if(a[j-1]>a[j]&&b[j-1]!=-1)
				{
					min=b[j-1];
					for(k=min;k>=0;k--)
					{
						if(a[k]<a[j])
						{
							b[j]=k;
							break;
						}
					}
				}
				else if(a[j-1]<a[j])
				{
					b[j]=j-1;
				}
				else if(a[j]=a[j-1])
				{
					b[j]=b[j-1];
				}
		//		printf("%lld	",b[j]);
			}
			long long int big;
			big =a[t-1];
			c[t-1]=t;
		//		printf("\n");
			for(j=t-2;j>=0;j--)
			{
				if(a[j]<=big)
				{
					big=a[j];
					c[j]=t;
				}
				else if(a[j+1]>a[j]&&c[j+1]!=t)
				{
					min=c[j+1];
					for(k=min;k<t;k++)
					{
						if(a[k]<a[j])
						{
							c[j]=k;
							break;
						}
					}
				}
				else if(a[j+1]<a[j])
				{
					c[j]=j+1;
				}
				else if(a[j]=a[j+1])
				{
					c[j]=c[j+1];
				}
		//		printf("%lld	",c[j]);
			}
		//		printf("\n");
			for(j=0;j<t;j++)
			{
				if(j==0)
				{
				//	if(c[j]!=t)
				//		sum=(c[j]+1)*a[j];
				//	else
						sum=c[j]*a[j];
				}
				else if(j==t-1)
				{
					sum=(t-1-b[j])*a[j];
				}
				else
				{
					if(b[j]==-1||c[j]==t)
					{
						if(b[j]==-1&&c[j]!=t)
						{
							sum=(c[j])*a[j];
						}
						else if(c[j]==t&&b[j]!=-1)
						{
							sum=(t-1-b[j])*a[j];
						}
						else if(b[j]==-1&&c[j]==t)
						{
							sum=t*a[j];
						}
					}
					else
					{
						sum=(c[j]-b[j]-1)*a[j];
					}
				}
				if(sum>max)
				{
					max=sum;
				}
		//	printf("	%lld",sum);
			}
		printf("%lld\n",max);
		}
		else if(t==0)
		{
			break;
		}
	}
	return 0;
}
