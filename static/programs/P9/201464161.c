#include<stdio.h>
#include<stdlib.h>
int mod(int x,int y)
{
return x%y;
}
int main()
{
	int a,x,y,b,swap;
	scanf("%d%d",&x,&y);
	int item[x],wt[x],*arr[x];
	for(a=0;a<x;a++)
	{
		int l,t;
		scanf("%d",&item[a]);
		wt[a]=0;
		arr[a]=(int*)malloc(sizeof(int)*item[a]);
		t=item[a];
		for(l=0;l<t;l++)
		{
			scanf("%d",&arr[a][l]);
			wt[a]=mod(wt[a]+arr[a][l],y);
		}
		wt[a]=mod(wt[a],y);
	}
	int *p;
	for(a=0;a<x;a++)
	{
		for(b=0;b<x-a-1;b++)
		{
			if(wt[b]>wt[b+1])
			{
				swap=item[b];
				item[b]=item[b+1];
				item[b+1]=swap;
				swap=wt[b];
				wt[b]=wt[b+1];
				wt[b+1]=swap;
				p=arr[b];
				arr[b]=arr[b+1];
				arr[b+1]=p;
			}
		}
	}
	int c;
	for (a=0;a<x;a++)
	{
		printf("%d\n",wt[a]);
		c=item[a];
		for (b=0;b<c;b++)
		{
			printf("%d\n",arr[a][b]);
		}
		printf("\n");
	}
	return 0;
}

