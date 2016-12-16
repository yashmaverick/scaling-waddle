#include<stdio.h>
#include<stdlib.h>
long long int insertionsort(long long int b[],long long int c[],int high)
{
	long long int j=1,k,temp,temp1;
	for(j=1;j<high;j++)
	{
		temp=b[c[j]];
		temp1=c[j];
		k=j-1;
		while(temp<b[c[k]] && k>=0)
		{
			c[k+1]=c[k];
			k--;
		}
		c[k+1]=temp1;
	}
}
int main()
{
	long long int s=0,n,j,i=0,modval,bagnum,k,sum=0,l,m,tc,count=0;
	scanf("%lld %lld",&n,&modval);
	tc=n;
	long long int x[n];
	long long int **a=malloc(n*sizeof(long long int));
	long long int *b=malloc(n*sizeof(long long int));
	long long int *c=malloc(n*sizeof(long long int));
	while(tc--)
	{
		scanf("%lld",&bagnum);
		x[s]=bagnum;
		s++;
		k=bagnum;
		j=1;
		a[i]=(long long int *)malloc((bagnum+1)*sizeof(long long int));
		while(k--)
		{
			scanf("%lld",&a[i][j]);
			j++;
		}
		i++;
	}
	for(l=0;l<n;l++)
	{
		for(m=1;m<=x[l];m++)
		{
			sum=(sum+a[l][m])%modval;
		}
		a[l][0]=sum%modval;
		sum=0;
	}
	for(l=0;l<n;l++)
	{
		b[l]=a[l][0];
	}
	for(l=0;l<n;l++)
	{
		c[l]=count;
		count++;
	}
	insertionsort(b,c,n);
//	for(l=0;l<n;l++)
//		printf("%lld ",c[l]);
//	printf("\n");
	for(l=0;l<n;l++)
	{
		printf("%lld\n",b[c[l]]);
		for(j=1;j<=x[c[l]];j++)
		{
			printf("%lld\n",a[c[l]][j]);
		}
		printf("\n");
	}
	return 0;
}
