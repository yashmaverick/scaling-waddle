#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int n,i,j,k,x,z;
	int p,q,r,s,t=0,l;
	char c,d;
	scanf("%d",&n);
	char a[10005][105];
	x=0;i=0;j=0;
	while((c=getchar())!='Q')
	{
		if(c=='A')
		{
			scanf("%d%c",&k,&d);
			if((x+k)<=n)
				x=x+k;
			else
				x=n;
			j=0;
			while(j<k)
			{
				for(l=0;(d=getchar())!='\n';l++)
					a[i][l]=d;
				a[i][l]='\n';
				i++;
				j++;
				if(i==n)
					i=0;
			}
			if(x==n)
				t=i;
		}
		if(c=='R')
		{
			i=t;
			scanf("%d",&k);
			r=x;
			x=x-k;	
			s=r-k;
			j=0;
			while(j<s)
			{
				q=0;
				z=i+k;
				if(z>=n)
					z=z-n;
				while(a[z][q]!='\n')
				{
					a[i][q]=a[z][q];
					q++;
				}
				a[i][q]='\n';
				j++;
				i++;
				if(i==n)
					i=0;
			}
		}
		if(c=='L')
		{
			if((t+x)<n)
				for(p=t;p<(t+x);p++)
				{	
					for(j=0;a[p][j]!='\n';j++)
						printf("%c",a[p][j]);
					printf("\n");
				}
			if((t+x)>=n)				
			{
				for(p=t;p<n;p++)
				{
					for(j=0;a[p][j]!='\n';j++)
                                                printf("%c",a[p][j]);
					printf("\n");
				}
				for(p=0;p<x-n+t;p++)
				{
					for(j=0;a[p][j]!='\n';j++)
                                                printf("%c",a[p][j]);
					printf("\n");

				}
			}
		}
	}
	return 0;
}
