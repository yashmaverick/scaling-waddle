#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	long long int arr[30];
	scanf("%d",&n);
	long long int q;
	while(n--)
	{
		int depth,dia;
		scanf("%lld",&q);
		if(q==1)
		{
			printf("0\n");
			continue;
		}
		else if(q==2)
		{
			printf("1\n");
			continue;
		}
		else if(q==3)
		{
			printf("2\n");
			continue;
		}
		depth = log2(q);
		long long int l ,r;
		l = pow(2,depth);
		r = pow(2,depth+1)-1;
		if((q-l)>(r-q))
			dia = 2*depth;
		else
			dia = 2*depth - 1;
		printf("%d\n",dia);


	}
	return 0;
	

}