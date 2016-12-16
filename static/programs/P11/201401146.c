#include<stdio.h>
int main()
{
	long long int n,i,j,A,x;
	long long int log[100000],indL[100000],indR[100000];
	while(1)
	{
		scanf("%lld",&n);
		if(n==0)
			break;
		indL[0]=-1;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&log[i]);
			if(i!=0 && log[i-1] < log[i])
				indL[i]=i-1;
			else if(log[i-1]>=log[i] && i!=0)
			{
				j=i-1;
				while(j>=0)
				{
					if(log[indL[j]] < log[i] && indL[j]>=0)
					{
						indL[i]=indL[j];
						break;
					}
					else if(indL[j]>=0)
						j=indL[j];
					else
					{
						indL[i]=-1;
						break;
					}
				}
			}
		}
		/*for(i=0;i<n;i++)
			printf("%lld ",indL[i]);
		printf("\n");*/
		A=0;
		indR[n-1]=n;
		for(i=n-1;i>=0;i--)
		{
			j=i+1;
			while(j<n)
			{
				if(log[j]<log[i])
				{
					indR[i]=j;
					break;
				}
				else
				{
					j=indR[j];
					if(j==n)
						indR[i]=n;
				}
			}
			x=(indR[i]-indL[i]-1)*log[i];
			if(x>A)
				A=x;
		}
		/*for(i=0;i<n;i++)
			printf("%lld ",indR[i]);
		printf("\n");*/
		printf("%lld\n",A);
	}
	return 0;
}
