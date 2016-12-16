#include<stdio.h>
typedef struct stack
{
	int node;
	int level;
}stack;
int main()

{
	int t,n,i,a[100000];
	stack stac[100000];
	scanf("%d",&t);
	while(t)
	{
		int sp=-1,el,maxlevel,lev;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=n-1;i>=0;i--)
		{
			if(sp==-1)
			{
				sp++;
				stac[sp].node=a[i];
				stac[sp].level=0;
				maxlevel=0;
				el=a[i];
			}
			else if(a[i]>stac[sp].node)
			{
				sp++;
				stac[sp].node=a[i];
				stac[sp].level=stac[sp-1].level+1;
				if(stac[sp].level>=maxlevel)
				{
					maxlevel=stac[sp].level;
					el=stac[sp].node;
				}

			}
			else
			{
				while(a[i]<stac[sp].node)
				{
					lev=stac[sp].level;
					sp--;
					if(sp==-1)
						break;
				}
				sp++;
				stac[sp].node=a[i];
				stac[sp].level=lev+1;
				if(stac[sp].level>=maxlevel)
				{
					maxlevel=stac[sp].level;
					el=stac[sp].node;
				}
			}


		}
		printf("%d %d\n",el,maxlevel);
		t--;
	}
	return 0;
}
