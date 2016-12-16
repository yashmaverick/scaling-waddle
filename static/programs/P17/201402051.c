#include<stdio.h>
int main()
{
	int n,t,x,y,j1,j2,w1,w2,i,j;
		scanf("%d",&n);
int a[n],b[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	scanf("%d",&t);
	while(t--)
	{
int f=0;
		scanf("%d %d",&x,&y);
		for(i=0;i<n;i++)
		{
			if(a[i]==x)
			{
				j1=i;
			}
			if(a[i]==y)
			{
				w1=i;
			}
			if(b[i]==x)
			{
				j2=i;
			}
			if(b[i]==y)
			{
				w2=i;
			}
		}
		if(j2>w2)
		{
			for(i=0;i<n;i++)
			{
				for(j=w2;j<=j2;j++)
				{
					if(a[i]==b[j])
					{
						printf("%d\n",b[j]);
f=1;
						break;
					}
					
				}
if(f==1)
{
break;}
			}
		}
		if(j2<w2)
		{

			for(i=0;i<n;i++)
			{
				for(j=j2;j<=w2;j++)
				{
					if(a[i]==b[j])
					{
						printf("%d\n",b[j]);
f=1;
						break;
					}
				}
if(f==1)
{
break;}
                                            
				
			}
		}
if(j2==w2)
{
printf("%d\n",b[j2]);
}
	}
	return 0;
}

