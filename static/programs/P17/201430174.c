#include<stdio.h>
int main()
{
	int n,f,t,j,k;
	scanf("%d",&n);
	int pr[n],in[n];
	for(f=0;f<n;f++)
		scanf("%d",&pr[f]);
	for(f=0;f<n;f++)
		scanf("%d",&in[f]);
	scanf("%d",&t);
	for(j=0;j<t;j++)
	{
		int x,y,i,r,a,b,k,g=0,tmp;
		scanf("%d%d",&a,&b);
		for(i=0;i<n;i++)
		{
			if(in[i]==a)
				x=i;
			if(in[i]==b)
				y=i;
		}
		if(x>y)
		{
			tmp=x;
			x=y;
			y=tmp;
		}
		for(i=0;i<n;i++)
		{
			for(k=x;k<=y;k++)
			{
				if(pr[i]==in[k])
				{
					r=pr[i];
					printf("%d\n",r);
					g=1;
				}
				if(g==1)
					break;
			}
			if(g==1)
				break;
		}
	}
	return 0;
}



