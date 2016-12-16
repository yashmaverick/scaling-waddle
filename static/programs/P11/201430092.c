#include<stdio.h>
#include<string.h>
int main()
{
	long long int m;
	scanf("%lld",&m);
	while(m!=0){
		long long int n,l,j,u,i,x[100000],y[100000],z[100000],stack[100000];
		for(i=0;i<m;i++)
		{
			scanf("%lld",&x[i]);
			stack[i]=y[i]=z[i]=0;
		}
		stack[0]=0;
		j = 0;
		y[0]=-1;
		for(i=1;i<m;i++)
		{
			if(x[i]>x[stack[j]])
			{
				y[i]=stack[j];
			}
			else
			{
				while(x[i]<=x[stack[j]] && j>0)
				{
					j--;
				}
				if(j==0)
				{
					if(x[i] > x[0])
					{
						y[i]=0;
					}
					else
					{
						y[i]=-1;
					}
				}
				else
				{
					y[i]=stack[j];
				}
			}
			j++;
			stack[j]=i;
		}
		stack[0]=m-1;
		z[m-1]=m;
		j=0;
		for(i=m-2;i>=0;i--)
		{
			if(x[i] > x[stack[j]])
			{
				z[i]=stack[j];
			}
			else
			{
				while(x[i] <= x[stack[j]] && j>0)
				{
					j--;
				}
				if(j==0)
				{
					if(x[i]>x[m-1])
					{
						z[i]=m-1;
					}
					else
					{
						z[i]=m;
					}
				}
				else
					z[i]=stack[j];
			}
			j++;
			stack[j]=i;
		}
		long long int max=0;/*
		for(i=0;i<m;i++)
			printf("%lld ",y[i]);
		printf("\n");
		for(i=0;i<m;i++)
			printf("%lld ",z[i]);
		printf("\n");*/
		for(i=0;i<m;i++)
		{
			if((i-y[i]+z[i]-i-1)*x[i] > max)
				max = (i-y[i]+z[i]-i-1)*x[i];
		}
		printf("%lld\n",max);
		scanf("%lld",&m);
	}
	return 0;
}
