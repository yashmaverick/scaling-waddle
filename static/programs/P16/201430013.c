#include<stdio.h>
#include<math.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int n;
		scanf("%d",&n);
		int x=-1;
		int r;
		while(n>0)
		{
			x++;
			r=n;
			n=n-pow(2,x);

		}
		if(r>pow(2,x)/2)
			printf("%d\n",x*2);
		else
			printf("%d\n",x*2-1);
	}
	return 0;
}


