#include <stdio.h>

/*int partition (int arr[], int l, int h)
{
	int x = arr[h];
	int i = (l - 1);

	for (int j = l; j <= h- 1; j++)
	{
		if (arr[j] <= x)
		{
			i++;
			swap (&arr[i], &arr[j]);
		}
	}
	swap (&arr[i + 1], &arr[h]);
	return (i + 1);
}

void quickSort(int A[], int l, int h)
{
	if (l < h)
	{       
		int p = partition(A, l, h);  Partitioning index 
		quickSort(A, l, p - 1); 
		quickSort(A, p + 1, h);
	}
}*/
int main()
{
	int n,m,i,j,ac;
	int w,mod,ar[1000000],bag[1000][1000],sum,tmp;

	scanf("%d %d",&n,&mod);
	ac=0;

	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		ar[ac]=m;
		bag[i][0]=ac;
		ac++;
		sum=0;
		for(j=0;j<m;j++)
		{
			scanf("%d",&w);
			sum=(sum%mod+w%mod)%mod;
			ar[ac++]=w;
		}
		bag[i][1]=sum;
	}

	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(bag[i][1]>bag[j][1])
			{
				tmp=bag[i][1];
				bag[i][1]=bag[j][1];
				bag[j][1]=tmp;
				tmp=bag[i][0];
				bag[i][0]=bag[j][0];
				bag[j][0]=tmp;

			}
		}
	}

	for(i=0;i<n;i++)
	{
		printf("%ld\n",bag[i][1]);
		for(j=1;j<=ar[bag[i][0]];j++)
		{
			printf("%ld\n",ar[j+bag[i][0]]);
		}
		printf("\n");
	}

	return 0;
}
