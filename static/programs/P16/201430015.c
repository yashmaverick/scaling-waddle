#include<stdio.h>
#include<math.h>

int main()
{
	int x,i,test;
	scanf("%d",&test);
	while(test)
	{
		test--;
		scanf("%d",&x);
		i=0;
		while(pow(2,i)<x)
		{
			i++;
		}
		if(x==1)
		{
			printf("%d\n",0);
			continue;
		}
		if(x==pow(2,i))
		{
			printf("%d\n",2*i-1);
			continue;
		}
		i--;
		if((x-pow(2,i))<pow(2,i-1))
		{
			printf("%d\n",2*(i-1)+1);
		}
		else
		{
			printf("%d\n",2*(i-1)+2);
		}
	}
	return 0;
}
