#include<stdio.h>
#include<stdlib.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int q,k=0;
		scanf("%d",&q);
		int r=q,c=1,d;
		while(r>1)
		{
			k++;
			c=c*2;
			r=r/2;
		}
		d=c/2;
		int h=2*k-1;
		if(q==1)
			printf("0\n");
		else if(q==2)
			printf("1\n");
		else
		{
		if(q>=c+d)
			printf("%d\n",h+1);
		else
			printf("%d\n",h);
		}
	}
	return 0;
}

