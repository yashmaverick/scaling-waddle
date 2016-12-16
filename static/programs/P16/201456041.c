#include<stdio.h>
//#include<math.h>

int power(int x,int y);

int main()
{
	int test;
	int i,j,exp;
	int query;
	i=1;
	//printf("Enter the number of test cases:\n");
	scanf("%d",&test);
	while(i<=test)
	{
		//printf("Enter the query:\n");
		scanf("%d",&query);
		exp=0;
		j=query;
		if(query!=1)
		{
			while(j!=1)
			{
				j=j/2;
				exp++;
			}
			if(query<(power(2,exp)+power(2,exp-1)))
				printf("%d\n",2*exp-1);
			else
				printf("%d\n",2*exp);
		}
		else
			printf("0\n");
		i++;
	}
	return 0;
}

int power(int x, int y)
{
	int temp;
	if( y == 0)
		return 1;
	temp = power(x, y/2);
	if (y%2 == 0)
		return temp*temp;
	else
		return x*temp*temp;
}
