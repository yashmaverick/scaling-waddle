#include<stdio.h>
#include<math.h>
int main()
{
	int n,q,bits=0,y;
	scanf("%d",&n);
	while(n--)
	{
		bits=0;
		scanf("%d",&q);
		y=q;
		if(q==1)
			printf("0\n");
		else
		{
		while(q>=1)
		{
			bits++;
			q=q/2;
		}
		bits--;
        	if(y>=((3*pow(2,bits))/2))
			printf("%d\n",2*bits);
	        else
			printf("%d\n",2*bits-1);
		}
	}
	return 0;
}
