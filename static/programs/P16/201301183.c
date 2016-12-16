#include <stdio.h>
int main()
{
	int n;
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int q;
		scanf("%d",&q);
		int d=0;
		while(1)
		{
			d=d+1;
			if(q==2)
			{
				printf("%d\n",2*d-1);
				break;
			}
			if(q==3)
			{
				printf("%d\n",2*d);
				break;
			}
			if(q==1)
			{
				d=0;
				printf("%d\n",d);
				break;
			}
			q = q/2;
			

		}
	}
	return 0;
}