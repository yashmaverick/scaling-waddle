#include<stdio.h>

int a[1005],b[1000006],c[1005],v[1000006];
int main()
{
	int n,o,i,j,k;
long long int g;

	scanf("%d %lld",&n,&g);
	//scanf("%d",&g);
	int p=0;
	for(i=0;i<n;i++)
	{
		int sum=0;
		scanf("%d",&a[i]);
		for(j=p;j<p+a[i];j++)
		{
			scanf("%d",&b[j]);

			sum=(sum%g+b[j]%g)%g;

		}
		p=p+a[i];
		c[i]=sum;
	}
	v[0]=a[0];
	for(k=1;k<n;k++)
	{
		v[k]=v[k-1]+a[k];
	
	}
	typedef struct node{
		int data;
		int data1;
		int data2;
	}node;
	node y[1005];
	y[0].data=c[0];
	y[0].data1=0;
	y[0].data2=a[0]-1;
	for(o=1;o<n;o++)
	{
		y[o].data=c[o];
		y[o].data1=v[o-1];
		y[o].data2=v[o]-1;       

	}
	int l,w;
	node temp;
	for(l=0;l<n;l++)
	{
		for(w=l+1;w<n;w++)
		{
			if (y[l].data>y[w].data)
			{
				temp=y[l];
				y[l]=y[w];
				y[w]=temp;
			}
		}
	}
	int u;
	for(u=0;u<n;u++)
	{
		int r=u;
		printf("%d\n",y[u].data);

		for(r=y[u].data1;r<(y[u].data2+1);r++)
			printf("%d\n",b[r]);


		printf("\n");
	}
	return 0;
}

