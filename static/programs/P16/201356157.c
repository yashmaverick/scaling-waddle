#include <stdio.h>
#include <stdlib.h>
int countlevels(int node)
{
node=node/2;
return node;
}

int main()
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
		int node,L,d=0;
		scanf("%d",&node);
		d=1;
		while(1)
		{
			L=2*d;
			if(node==1)
			{
				d=0;
				printf("%d\n",d);
				break;
			}
			
			if(node==3)
			{
				printf("%d\n",L);
				break;
			}
			if(node==2)
			{
				printf("%d\n",L-1);
				break;
			}
			node = countlevels(node);
			d=d+1;
		}
	}
	return 0;
}


