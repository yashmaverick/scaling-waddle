#include<stdio.h>
#include<math.h>

int main()
{
	int t;

	scanf("%d",&t);

	while(t--)
	{
		int n,aa,p;

		scanf("%d",&n);

		if(n==1)
		{
			printf("0\n");
			goto end;
		}

		aa=log2(n);

		p=pow(2,aa+1);

		if(n >= p-pow(2,aa-1))
			printf("%d\n",2*aa);
		else
			printf("%d\n",2*aa-1);

end:;

	
	}



	return 0;
}
