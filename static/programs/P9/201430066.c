#include<stdio.h>
int main()
{
	int n,mod;
	scanf("%d%d",&n,&mod);
	int y;
	y=1000000;
	int sum[n],a[n],b[y],c[n],d[n],flag[n];
	int i=0,k=0,m,x=0;
	while(i<n)
	{
		scanf("%d",&a[i]);
		m=a[i];
		c[i]=k;
		sum[i]=0;
		while(m!=0)
		{
			scanf("%d",&b[k]);
			k++;
			m--;
		}
		m=a[i];
		while(m!=0)
		{
			sum[i]=((sum[i])%mod+(b[x])%mod)%mod;
			x++;
			m--;
		}
		i++;
	}
	i=0;
	while(i<n)
	{
		flag[i]=0;
		d[i]=sum[i];
		i++;
	}
	int e=0,f=0,temp;
	for(e=0;e<n;e++)
	{
		for(f=0;f<n-1;f++)
		{
			if(d[f]>d[f+1])
			{
				temp=d[f+1];
				d[f+1]=d[f];
				d[f]=temp;
			}
		}
	}

	int l,j=0;
	i=0;
	while(i<n)
	{
		j=0;
		while(j<n)
		{	
			if(sum[j]==d[i] && flag[j]==0)
			{
				l=0;
				printf("%d\n",d[i]);
				while(l<a[j])
				{
				printf("%d\n",b[l+c[j]]);
				l++;
				}
				printf("\n");
				flag[j]=1;
				break;
			}
			j++;
		}
		i++;
	}
	return 0;
}
