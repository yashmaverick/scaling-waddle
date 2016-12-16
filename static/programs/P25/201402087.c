#include<stdio.h>

int p[1000006];
int size[1000006];
int rank[1000006];

typedef struct node
{
		int u;
		int v;
		int w;
}node;

node ar[1000006];

void makeset(int x)
{
		p[x]=x;
		size[x]=1;
}

int find(int x)
{
		if( p[x]==x )
				return x;
		else
		{
				p[x] = find(p[x]);
				return p[x];
		}
}

void merge(int x, int y)
{
		int tx=find(x);
		int ty=find(y);
		if(size[tx]>size[ty])
		{
			//	printf("yo\n");
				p[ty]=find(tx);
				size[tx]+=size[ty];
				size[ty]=0;
		}
		else
		{
				p[tx]=find(ty);
				size[ty]+=size[tx];
				size[tx]=0;
		}
}


int main()
{
		int n;
		int m;
		int i;
		scanf("%d%d",&n,&m);
		
		for( i=1 ; i<=n ; i++)
				makeset(i);
		
		for( i=1 ; i<=m ; i++)
		{
				int a,b,c;
				scanf("%d%d%d",&a,&b,&c);
				ar[i].u=a;
				ar[i].v=b;
				ar[i].w=c;
		}
		int j;
		int pos,min;
		for(i=1;i<m;i++)
		{
				for(j=i;j<=m;j++)
				{
						if(ar[i].w > ar[j].w)
						{
								node temp;
								temp = ar[i];
								ar[i] = ar[j];
								ar[j] = temp;
						}
				}
		}

//			for(i=1;i<=m;i++)
//				printf("%d	%d	%d\n",ar[i].u,ar[i].v,ar[i].w);

		int count=0;
		int sum=0;
		int flag=0;
		i=0;
		while(1)
		{
				if(count == n-1)
				{
						flag=1;
						break;
				}
				if( i>=m )
						break;
//					printf("before u=%d\n",find(ar[i+1].u));
//					printf("before v=%d\n\n",find(ar[i+1].v));
				if( find(ar[i+1].u) != find(ar[i+1].v) )
				{
						merge( ar[i+1].u , ar[i+1].v);
						count++;
						sum = sum+ar[i+1].w;
				}
//					printf("after u=%d\n",find(ar[i+1].u));
//					printf("after v=%d\n\n",find(ar[i+1].v));
				i++;
		}
		if(flag==1 && sum!=0)
				printf("%d\n",sum);
		else
				printf("-1\n");
		return 0;
}
