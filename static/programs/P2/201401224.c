#include<stdio.h>
int main()
{
	int m,t;
	scanf("%d",&t);
	for(m=0;m<t;m++)
	{
		long long int u,v,p,q,r,y[100005],x[100005],i,j,k;
		scanf("%lld",&p);
		long long int a[100005];
		for(i=0;i<p;i++)
			scanf("%lld",&a[i]);
		scanf("%lld",&q);
		long long int b[100005];
		for(j=0;j<q;j++)
			scanf("%lld",&b[j]);
		scanf("%lld",&r);
		long long int c[100005];
		for(k=0;k<r;k++)
			scanf("%lld",&c[k]);
		x[q]=0;y[p]=0;
		for(k=0;k<q+1;k++)
			x[k]=0;
		for(j=0;j<p+1;j++)
			y[j]=0;
		k=r-1;
		for(j=q-1;j>=0;j--)
		{
			while(k>=j)
			{
				if(b[j]>c[k])
					break;
				k--;
			}
			x[j]=x[j+1]+r-k-1;
		}
		j=q-1;
		for(i=p-1;i>=0;i--)
		{
			while(j>=i)
			{
				if(a[i]>b[j])
					break;
				j--;
			}
			y[i]=y[i+1]+x[j+1];
		}
		printf("%lld\n",y[0]);
	}
	return 0;
}
