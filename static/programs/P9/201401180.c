#include <stdio.h>
#include <stdlib.h>
void merge(int **a, int lo, int mid, int hi, int **b);
void split(int **a, int lo, int hi, int **b)
{
	if (lo < hi)
	{
		int mid = (lo+hi)/2;
		split(a,lo,mid,b);
		split(a,mid+1,hi,b);
		merge(a,lo,mid,hi,b);
	}
}
void merge(int **a, int lo, int mid, int hi, int **b)
{
	int ls = lo, le = mid;
	int rs = mid+1, re = hi;
	int i=lo;
	int j = lo;
	int n = re-ls+1;
	while (ls <= le && rs <= re)
	{
		if (a[ls][0] <= a[rs][0])
		{
			b[i][0] = a[ls][0];
			b[i][1] = a[ls][1];
			i++;
			ls++;
		}
		else
		{
			b[i][0] = a[rs][0];
			b[i][1] = a[rs][1];
			i++;
			rs++;
		}
	}
	while (ls <= le)
	{
		b[i][0] = a[ls][0];
		b[i][1] = a[ls][1];
		i++;
		ls++;
	}
	while (rs <= re)
	{
		b[i][0] = a[rs][0];
		b[i++][1] = a[rs++][1];
	}
	for (i = lo; i <= hi; i++)
	{
		a[i][0] = b[i][0];
		a[i][1] = b[i][1];
	}
}
int main()
{
	int n,mod;
	int m;
	int p;
	int *a;
	int **b;
	int **c;
	int **d;
	int i,j,k;
	scanf("%d%d",&n,&mod);
	a = (int *) malloc(n * sizeof(int));
	b = (int **) malloc(n * sizeof(int *));
	c = (int **) malloc(n * sizeof(int *));
	d = (int **) malloc(n * sizeof(int *));
	for (i = 0; i < n; i++)
	{
		c[i] = (int *) malloc(2* sizeof(int));
		d[i] = (int *) malloc(2* sizeof(int));
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
		m = a[i];
		b[i] = (int *) malloc(m * sizeof(int));
		for (j = 0; j < m; j++)
			scanf("%d",&b[i][j]);
	}
	for (i = 0; i < n; i++)
	{
		m = a[i];
		for (j = 0; j < m; j++)
		{
			c[i][0] += (b[i][j]%mod);
			c[i][0] = c[i][0]%mod;
		}
		c[i][0] = c[i][0]%mod;
		c[i][1] = i;
	}
	split(c,0,n-1,d);
	for (i = 0; i < n; i++)
	{
		printf("%d\n",c[i][0]);
		m = c[i][1];
		p = a[m];
		for (j = 0; j < p; j++)
			printf("%d\n",b[m][j]);
		printf("\n");
	}
	return 0;
}
