#include<stdio.h>
#include<stdlib.h>

int main()
{
	long long int **p,*temp,mod,x;
	long long int n,m,i,j;
	scanf("%lld %lld",&n,&mod);
	p=(long long int **)(malloc(n*sizeof(long long int *)));
	for(i=0;i<n;i++)
	{
		scanf("%lld",&m);
		p[i]=(long long int *)(malloc((m+2)*sizeof(long long int)));
		p[i][0]=m;
		p[i][1]=0;
		for(j=2;j<m+2;j++)
		{
			scanf("%lld",&x);
			p[i][1]=((p[i][1]%mod)+(x%mod))%mod;
			p[i][j]=x;
		}
	}

	for(i=1;i<n;i++)
	{
		for(j=i;j>0;j--)
		{
			if(p[j][1]<p[j-1][1])
			{
				temp=p[j];
				p[j]=p[j-1];
				p[j-1]=temp;
			}
			else
			{
				break;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%lld\n",p[i][1]);
		for(j=2;j<p[i][0]+2;j++)
		{
			printf("%lld\n",p[i][j]);
		}
		printf("\n");
	}
	return 0;
}
