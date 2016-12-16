#include<stdio.h>
#include<stdlib.h>
//int a[1000][1000000];
  int **a;
int main()
{
	int t,t1,max,m,mod,i,j,k,k1,l,n;
	long long int sum;
	scanf("%d %d",&n,&mod);
	a=(int **)malloc(sizeof(int *)*n);
	for(t=0;t<n;t++)
	{
		sum=0;
		max=0;
		scanf("%d",&m);
		a[t]=(int *)malloc(sizeof(int)*(m+3));
		/*if(m>max)a
			max=m;
		for(i=0;i<n;i++)
		  for(j=0;j<max+2;j++)
		  {
		  a[i][j]=0;
		  }*/
		a[t][0]=m;
		for(i=0;i<m;i++)
		{
			scanf("%d",&a[t][i+1]);
			sum=(sum+a[t][i+1])%mod;
		}		
		a[t][m+1]=(sum)%mod;
	}
	for(t1=0;t1<n;t1++)
	{  j=0;
		for(t=t1;t<n-1;t++)
		{
			k=a[t1][j];
			k1=a[t+1][j];
			if(a[t1][k+1]>a[t+1][k1+1])
			{
				int * temp;
				temp=a[t1];
				a[t1]=a[t+1];
				a[t+1]=temp;
				
			/*	for(i=0;i<max+2;i++)
				{
					temp=a[t][i];
					a[t][i]=a[t+1][i];
					a[t+1][i]=temp;
				}*/
			}
		}
	}
	for(t=0;t<n;t++)
	{	
		l=a[t][0];
		printf("%d\n",a[t][l+1]);
		for(i=1;i<=l;i++)
		{
			printf("%d\n",a[t][i]);
		}
		printf("\n");
	}
	return 0;
}
