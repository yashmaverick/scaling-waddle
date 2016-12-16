#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i;
	scanf("%d",&n);
	int inf[n],in[n],pre[n];

	for(i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		x--;
		pre[i]=x;
	}
	for(i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		x--;
		in[i]=x;
		inf[x]=i;
	}

	int q;
	scanf("%d",&q);

	for(i=0;i<q;i++)
	{
		int x,y,p,q;
		scanf("%d %d",&x,&y);
		x--;
		y--;

		p=inf[x];
		q=inf[y];

		int *temp,w;
		temp=malloc(sizeof(int)*n);
		for(w=0;w<n;w++) temp[w]=0;

		if(p>q){ w=p; p=q; q=w; }

		for(w=p;w<=q;w++)
		{
			temp[in[w]]=1;
		}

//		for(w=0;w<n;w++) printf("%d ",temp[w]);

//		printf("\n");	
		for(w=0;w<n;w++)
		{
			if((temp[pre[w]])==1) break;
		}

		printf("%d\n",pre[w]+1);
	}

	return 0;
}