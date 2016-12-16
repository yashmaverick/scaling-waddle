#include<stdio.h>
#include<math.h>
int p[100000];
int in[100000];
int a[100000];
int b[100000];
int n;
int func(const void * p, const void *q)
{
	return (*(int *)p-*(int *)q);
}
int  lca(int v1,int v2)
{
	int i1,i2,i,j,k,c[100000],d[100000];
	for(i1=0;i1<n;i1++)
	{
	//	printf("%d\n",in[i1]);
		if(in[i1]==v1)
			break;
	}
	for(i2=0;i2<n;i2++)
	{
		if(in[i2]==v2)
			break;
	}
	/*printf("%d\n",n);
	printf("%d %d\n",v1,v2);
	printf("%d %d\n",i1,i2);*/
	if(i1>i2)
	{
		for(i=i2;i<i1+1;i++)
		{
			c[i-i2]=in[i];
		}
	}
	else
	{
		for(i=i1;i<i2+1;i++)
		{
			c[i-i1]=in[i];
			//printf("%d\n",in[i]);
		}
	}
	//printf("%d\n",c[0]);
	for(j=0;j<abs(i2-i1)+1;j++)
	{
		for(k=0;k<n;k++)
		{
			if(c[j]==p[k])
			{
				d[j]=k;
				break;
			}
		}
	}
	int j1;
	/*for(j1=0;j1<j+1;j++)
		printf("%d\n",d[j1]);*/
	qsort(d,j,sizeof(int),func);
	return p[d[0]];
}
int main()
{
	int i,j,k,m,t;
	scanf("%d",&n);
	for(t=0;t<n;t++)
	{
		scanf("%d",&p[t]);
	}
	for(t=0;t<n;t++)
	{
		scanf("%d",&in[t]);
	}
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&a[i],&b[i]);	
		printf("%d\n",lca(a[i],b[i]));
	}
	return 0;
}
