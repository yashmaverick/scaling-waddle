#include<stdio.h>
int main()
{
	int n,mod;
	scanf("%d%d",&n,&mod);
	int a[1000005];
	int i=0,k,count=0,d,sum[n+2][n+2],j=0;
	int m;
	m=n;
	while(n--)
	{
		scanf("%d",&a[i]);
		sum[1][j]=i;
		count++;
		k=a[i];
		sum[0][j]=0;
		while(k--)
		{
			i++;
			scanf("%d",&a[i]);
			sum[0][j]=(sum[0][j]+ (a[i] % mod) ) % mod;
			count++;
		}
		i++;
		j++;
	}

	int v,b,temp,temp1;
	for(v=0;v<m;v++)
	{
		for(b=0;b<m-1;b++)
		{
			if(sum[0][b]>sum[0][b+1])
			{
				temp=sum[0][b];
				sum[0][b]=sum[0][b+1];
				sum[0][b+1]=temp;

				temp1=sum[1][b];
				sum[1][b]=sum[1][b+1];
				sum[1][b+1]=temp1;
			}
		}
	}

	int r,h,u;
	for(i=0;i<m;i++)
	{
		printf("%d\n",sum[0][i]);
		r=sum[1][i];
		h=a[r];
		u=r;
		while(h--)
		{
			printf("%d\n",a[u+1]);
			u++;
		}
		printf("\n");
	}
	return 0;
}

