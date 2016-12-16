#include<stdio.h>
int main()
{
		int n,q,i;
		scanf("%d",&n);
		while(n--)
		{
				scanf("%d",&q);
				for(i=0;;i++)
						if(q<(1<<i))
								break;
				if( q < ((1<<i)-(1<<i-2)) )
						printf("%d\n",i+i-3);
				else
						printf("%d\n",i+i-2);
		}
		return 0;
}
