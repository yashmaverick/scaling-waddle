#include<stdio.h>
int main()
{
	int i,n,I[1000],p[1000],c[1000],t,u,v,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&p[i]);
	for(i=0;i<n;i++)
		scanf("%d",&I[i]);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&u,&v);
		for(i=0;i<n;i++)
		{
			if( I[i]==u )
			{
				j=0;
				while(I[i]!=v)
				{
					c[j++]=I[i];
					i++;
				}
				c[j]=v;
				break;
			}
			if( I[i]==v )
			{
				j=0;
				while(I[i]!=u)
				{
					c[j++]=I[i];
					i++;
				}
				c[j]=u;
				break;
			}
		}
		/*for(i=0;i<=j;i++)
		  printf("%d ",c[i]);*/
		int flag=0;
		for(i=0;i<n;i++)
		{
			for(k=0;k<=j;k++)
				if(c[k]==p[i])
				{
					printf("%d\n",p[i]);
					flag=1;
					break;
				}
			if(flag==1)
				break;


		}
	}
	return 0;
}
