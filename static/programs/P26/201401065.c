#include<stdio.h>

void split(int n,int d[4])
{
	int i,j;
	for(i=0,j=10;i<4;i++,j*=10)
		d[i]=(n%j)/(j/10);
}

void getprimes(int n,int d[4],int g[10000][41],int bp[])
{
	int h=0;
	int i,j,k,l,m;
	for(i=0,j=1;i<4;i++,j*=10)
	{
		l=n-d[i]*j;
		for(k=0;k<=9;k++)
		{
			m=l+k*j;
			if(m>1000&&bp[m]==0&&m!=n)
				g[n][h++]=m;

		}
	}
}

void bfs(int v1,int v2,int list[10000][41])
{
	if(v1==v2)
	{
		printf("0\n");
		return;
	}
	int bv[10000]={0},q[100000];
	int i=0,j,h=0,t=0;
	bv[v1]=1;
	q[t++]=v1;
	int len=-1,fl=0;
	while(1)
	{
		len++;i=h;h=t;
		if(i==h)
		{
			fl=0;
			break;
		}
		while(i<h&&q[i]!=v2)
		{
			j=0;
			while(list[q[i]][j]!=0)
			{
				if(bv[list[q[i]][j]]!=1)
				{
					bv[list[q[i]][j]]=1;
					q[t++]=list[q[i]][j];
				}
				if(list[q[i]][j]==v2)
				{
					fl=1;
					break;
				}
				j++;
			}
			if(fl)
				break;
			i++;
		}
		if(fl)
		{
			len++;
			break;
		}
		if(q[i]==v2)
		{
			fl=1;
			break;
		}
	}
	if(fl)
		printf("%d\n",len);
	else
		printf("Impossible\n");
}

void print(int g[10000][41],int n)
{
	int i=0;
	while(g[n][i]!=0)
		printf("%d ",g[n][i++]);
	printf("\n");
}

int main()
{
	int i,j,np=1,p[3000],bp[10000]={0};
	for(i=2;i<10000;i++)
		if(bp[i]==0)
		{
			p[np++]=i;
			for(j=i*i;j<10000;j+=i)
				bp[j]=1;
		}
	int list[10000][41]={0};
	int d[4];
	for(i=1;i<np;i++)
	{
		split(p[i],d);
		getprimes(p[i],d,list,bp);
	}
	/*for(i=1;i<np;i++)
	{
		printf("%d --> ",p[i]);
		print(list,p[i]);
	}*/
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int v1,v2;
		scanf("%d %d",&v1,&v2);
		bfs(v1,v2,list);
	}
	return 0;
}
