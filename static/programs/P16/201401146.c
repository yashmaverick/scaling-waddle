#include<stdio.h>
#include<math.h>
int main()
{
	int n,q,p,e,i;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&q);
		if(q==1)
		{
			printf("0\n");
			continue;
		}
		else
		{
			p=q;
			i=-1;
			while(q!=0)
			{
				q=q/2;
				i++;
			}
			e=pow(2,i);
			e=(e/2)+e;
			if(p>=e)
				printf("%d\n",2*i);
			else
				printf("%d\n",2*i-1);
		}
	}
	return 0;
}
