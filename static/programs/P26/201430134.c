#include<stdio.h>
#include<stdlib.h>
int f,e;
void sieve(int p2,int a[],int b[])
{
	int p,q,r,i;
	p=2;
	while(p*p < p2)
	{
		if(a[p]==0)
		{
			for(q=p*p;q<=p2;q+=p)
			{
				a[q]=1;
			}
		}
		p++;
	}
}
void func(int q[],int k,int dist[],int vis[])
{
	q[e]=k;
	dist[k]=dist[q[f]]+1;
	vis[k]=1;
	e++;
}
void create(int dist[],int vis[],int q[],int a[])
{
	int m1,s1,s2,n1,n2,n3,n4,i,j,k;
	s1=q[f];
	for(j=0;j<10;j++)
	{
		if(j!=0)
		{
			n1=s1%1000;
			k=(j*1000)+n1;
			if(a[k]==0 && vis[k]==0)
			{
				func(q,k,dist,vis);
			}
		}

		n2=s1%100;
		m1=s1/1000;
		k=(m1*1000)+(j*100)+n2;
		if(a[k]==0 && vis[k]==0)
		{
			func(q,k,dist,vis);
		}

		n3=s1%10;
		m1=s1/100;
		k=(m1*100)+(j*10)+n3;
		if(a[k]==0 && vis[k]==0)
		{
			func(q,k,dist,vis);
		}

		m1=s1/10;
		k=(m1*10)+j;
		if(a[k]==0 && vis[k]==0)
		{
			func(q,k,dist,vis);
		}
	}
}
int main()
{
	int p1,p2,t,i,j,k,ans,count;
	int a[10000]={0};count=0;
	int b[2000],dist[10000],vis[10000],q[2000];
	sieve(9999,a,b);
//	printf("%d %d\n",a[1333],a[1073]);
/*	for(i=1000;i<10000;i++)
	{
		if(a[i]==0)
			count++;
	}*/
//	printf("%d\n",count);
	scanf("%d",&t);
	while(t>0)
	{
		f=0;e=0;ans=0;
		for(i=0;i<10000;i++)
		{
			dist[i]=0;
			vis[i]=0;
		}
		scanf("%d %d",&p1,&p2);
		q[e]=p1;dist[p1]=0;e++;
		vis[p1]=1;
		while(vis[p2]==0)
		{
			//vis[q[f]]=1;
			create(dist,vis,q,a);
			f++;
		}
		printf("%d\n",dist[p2]);
		t--;
	}
	return 0;
}


