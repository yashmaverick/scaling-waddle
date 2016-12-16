#include<stdio.h>

int p=1;

void power(int n);

int main(){	
		int test;
		int i;
		scanf("%d",&test);
		for(i=0;i<test;i++)
		{
				int a;
				int k=0;
				scanf("%d",&a);
				while(1)
				{
						p=1;
						power(k);
						//printf("%d %d\n",k,p);
						if( a < p )
								break;
						k++;
				}
				if( a < p/2 + p/4 )
						printf("%d\n",2*(k-1)-1);
				else
						printf("%d\n",2*(k-1));
		}
		return 0;}


void power(int n)
{
		int j;
		for(j=0;j<n;j++)
				p=p*2;
}
