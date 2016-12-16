#include<stdio.h>
#include<stdlib.h>
typedef struct akash
{
	int l;
	int *ar;
	long long int s;
}akash;
int main()
{
	int n,mod;
	scanf("%d %d",&n,&mod);
	akash a[n];
	int i,m,j;
	for(i=0;i<n;i++)
	{scanf("%d",&a[i].l);
		a[i].ar=(int*)malloc(a[i].l*sizeof(int));
		a[i].s=0;
		for(m=0;m<a[i].l;m++)
		{
			scanf("%d",&a[i].ar[m]);
			a[i].s=(a[i].s+a[i].ar[m])%mod;
		}
	}
	int b[5005][2];
	for(i=0;i<n;i++)
	{ 
		b[i][0]=a[i].s;
		b[i][1]=i;
	}
	int t;
	int t1;
	for(i=0;i<n;i++)
	{
		t=b[i][0];
		t1=b[i][1];
		m=i-1;
		while((t<b[m][0])&&(m>=0))
		{
			b[m+1][1]=b[m][1];
			b[m+1][0]=b[m][0];
			m=m-1;
		}
		b[m+1][0]=t;
		b[m+1][1]=t1;
	}
			int k;
	for(i=0;i<n;i++)
	{k=b[i][1];
		printf("%lld\n",a[k].s);
		for(j=0;j<a[k].l;j++)
			printf("%d\n",a[k].ar[j]);
		printf("\n");
	}
	return 0;
}





