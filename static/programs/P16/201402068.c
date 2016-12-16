#include <stdio.h>
int main()
{
	int n,q;
	scanf("%d",&n);
	while(n--)
	{
		int w=0;
		scanf("%d",&q);
		int temp=q;
		while(temp>=2)
		{
			w++;
			temp=temp/2;
		}
		int bound1,bound2;
		int i;
		bound1=bound2=1;
		for(i=1;i<=w;i++)
		{
			bound1*=2;
		}
		bound2=bound1*2;
		temp=(bound1+bound2)/2;
		int dia;
		if(q<temp)
			dia=2*w-1;
		else if(q>=temp)
			dia=2*w;
		printf("%d\n",dia);
	}


	return 0;
}
