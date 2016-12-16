#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,d,e,f,g,h,tes;
	scanf("%d",&tes);
	while(tes--)
	{
		scanf("%d",&a);
		d=log2(a);		
		b=pow(2,d);
		c=pow(2,(d-1));
		f=b+c-1;
		
		if(!(a<=f))
		{
			g=2*d;
			printf("%d\n",g);
		}
		else
		{
			h= (2*d)-1;
			printf("%d\n",h);
		}
	}
	return 0;
}
