#include<stdio.h>
int main()
{
	int i,j,k,n,t,a,b,x,y,l;
	scanf("%d",&n);
	int in[100100],pre[100100];
	for(j=0;j<n;j++)
	scanf("%d",&pre[j]);
	for(j=0;j<n;j++)
	scanf("%d",&in[j]);
	scanf("%d",&t);
	for(k=0;k<t;k++)
	{
		scanf("%d %d",&a,&b);i=j=-1;x=0;
                while(i==-1 || j==-1)
		{
			if(i==-1 && in[x]==a)
				i=x;
			if(j==-1 && in[x]==b)
				j=x;
			x++;
		}
		if(i>j)
		{
			x=j;
		        j=i;
			i=x;
		}
		l=0;
		for(y=0;y<n;y++)
		{
			for(x=i;x<=j;x++)
			{
				if(pre[y]==in[x])
				{
					l=1;
					printf("%d\n",in[x]);
					break;
				}
			}
			if(l==1)
			  break;
		}
	}
	return 0;
}
			

		
