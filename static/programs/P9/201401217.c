#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long int n,m,i,j,p,temp;
	long long int mod;
	scanf("%lld",&n);
	scanf("%lld",&mod);
	long long int *arr[n];
	long long int ar[n],a[n],aa[n];
	for(i=0;i<n;i++)
	{
		scanf("%lld",&m);
		aa[i]=m;
		arr[i]=(long long int *)malloc((m+1)*(sizeof(long long int)));
		arr[i][0]=0;
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&arr[i][j]);
			arr[i][0]=arr[i][0]+(arr[i][j]%mod);
		}
		arr[i][0]=arr[i][0]%mod;
		a[i]=arr[i][0];
		ar[i]=i;
		//		printf("%d %d %d\n",arr[0][0],arr[0][1],arr[0][2]);
	}
	//	printf("%d %d %d\n",arr[0][0],arr[0][1],arr[0][2]);
	/*for(i=0;i<n;i++)
	  {
	  j=0;
	  while(arr[i][j]!='\0')
	  {
	  printf("%d ",arr[i][j]);
	  j++;
	  }
	  printf("\n");
	  }
	  for(i=0;i<n;i++)
	  printf("%d ",a[i]);
	  printf("\n");
	  for(i=0;i<n;i++)
	  printf("%d ",ar[i]);
	  printf("\n");*/
	for(i=1;i<n;i++)
	{
		for(j=i;a[j]<a[j-1];j--)
		{
			temp=a[j-1];
			a[j-1]=a[j];
			a[j]=temp;
			temp=ar[j-1];
			ar[j-1]=ar[j];
			ar[j]=temp;
			if(j <= 1)
				break;
		}
	}
	/*	for(i=0;i<n;i++)
		printf("%d ",ar[i]);
		printf("\n");
		for(i=0;i<n;i++)
		{
		j=0;
		while(arr[i][j]!='\0')
		{
		printf("%d ",arr[i][j]);
		j++;
		}
		printf("\n");
		}*/
	for(i=0;i<n;i++)
	{
		for(j=0;j<=aa[ar[i]];j++)
		{
			printf("%lld\n",arr[ar[i]][j]);
		}
		printf("\n");
	}
	return 0;
}
