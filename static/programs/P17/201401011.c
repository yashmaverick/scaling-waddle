#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int in[n],pre[n],ind[1000000],i,u,v,t,l,r;

	for(i=0;i<n;i++)
		scanf("%d",&pre[i]);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
		ind[in[i]] = i;
	}

	scanf("%d",&t);

	while(t--)
	{
		scanf("%d%d",&u,&v);
		l = ind[u] < ind[v] ? ind[u]: ind[v];
		r = ind[u] < ind[v] ? ind[v]: ind[u];
		//printf("l = %d and r = %d\n",l,r);
		for(i=0;i<n;i++)		 
		{
		//	printf("pre[i] = %d and ind[pre[i] = %d\n",pre[i],ind[pre[i]]);
			if( ind[pre[i]] <= r && ind[pre[i]] >= l )
			{	
				printf("%d\n",pre[i]);
				break;
			}
		}
	
	}

	return 0;
}
