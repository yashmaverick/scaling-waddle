#include<stdio.h>

int main()
{	
	int i,j,n,t,x,y,min;
	scanf("%d",&n);
	int pin[n+1],ppre[n+1];
	int in[n+1],b,a;
	for(i=1;i<=n;i++)
	{scanf("%d",&x);ppre[x]=i;}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&in[i]);
		pin[in[i]]=i;
	}
	scanf("%d",&t);
/*	for(i=1;i<=n;i++)
		printf("%d %d\n",ppre[i],pin[i]);
*/
	while(t--)
	{
		min=100001;
		scanf("%d %d",&x,&y);
		a=pin[x];
		b=pin[y];
		if(b<a)
		{
			x=a;
			a=b;
			b=x;
		}
		for(i=a;i<=b;i++)
		{
			if(ppre[in[i]]<min)
			{
				min=ppre[in[i]];
				a=in[i];
			}
		}
		printf("%d\n",a);
	}
	return 0;
}


