#include<stdio.h>
#include<stdlib.h>

typedef int ll;
ll *a,*b,k,l,t,ans;

void find(){
	int i,j,g=0;
	if(k>=l)
	{for(j=0;j<t&&g==0;j++)
		{
			for(i=l;i<=k&&g==0;i++)
			{
				if(a[j]==b[i])
				{	ans=b[i];
					g=1;
					break;
				}
			}

		}
	}
	else
	{for(j=0;j<t&&g==0;j++)
		{
			for(i=k;i<=l&&g==0;i++)
			{
				if(a[j]==b[i])
				{	//printf("%d ",b[i]);
					ans=b[i];
					g=1;
					break;
				}
			}

		}
	}
}

void check(){
	int i,j=0,s=0;
	for(i=0;i<t;i++)
	{
		if(b[i]==k && j==0)
			{k=i;j=1;}
		if(b[i]==l && s==0)
			{l=i;s=1;}	
	}
	find();
}


int main()
{
	ll n=0,i=0,y=0;
	scanf("%d",&t);
	y=t;
	a=(ll *)malloc(sizeof(ll)*t);
	b=(ll *)malloc(sizeof(ll)*t);

	while(y--)
	{
		scanf("%d",&a[i++]);
	}

	y=t;i=0;
	while(y--)
	{
		scanf("%d",&b[i++]);
	}

	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&k,&l);// k and l are globally declared
		check();
		printf("%d\n",ans);
	}
	return 0;
}