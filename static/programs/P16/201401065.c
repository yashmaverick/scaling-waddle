#include<stdio.h>
int main()
{
	int n,q,i,l,r,c;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&q);
		if(q==1)
		{
			printf("%d\n",0);
			continue;
		}
		l=1;r=1;c=0;
		while(1)
		{
			if(q<(l+r))
			{
				break;
			}
			l=l+r;
			r*=2;
			c++;
		}
		if(q<(l+r/2))
			printf("%d\n",(2*c)-1);
		else
			printf("%d\n",(2*c));
	}
	return 0;
}
