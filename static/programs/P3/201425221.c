#include<stdio.h>
int main()
{
	int t,n,i,j,cp,p,bp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		cp=p=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&j);
			if(i==0)
				bp=j;
			cp=j-bp;
			if(cp>p)
				p=cp;
			if(cp<0)
				bp=j;
		}
		printf("%d\n",p);
	}
	return 0;
}
