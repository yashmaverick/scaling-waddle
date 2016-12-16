#include<stdio.h>
#include<math.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int q,res=0;
		scanf("%d",&q);
		int dep=log2(q);
		int x=pow(2,dep);
		if((x/2)+x-1>=q)
		{
			res=1;
		}
		if(res==1)
		{
			printf("%d\n",2*dep-1);
		}
		else
		{
			printf("%d\n",2*dep);
		}
	}
	return 0;
}
