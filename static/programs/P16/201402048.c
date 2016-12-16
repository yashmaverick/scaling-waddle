#include<stdio.h>
int main()
{	int t;
    int i=0;
	scanf("%d",&t);
	while(i<t)
	{
		long long int n,count=0;
		scanf("%lld",&n);
		while(n>3)
		{
			n=n/2;
			count++;
                }
		if(n==2)
			printf("%lld\n",(2*count)+1);
		else if(n==3)
			printf("%lld\n",2*count+2);
                else
                    printf("0\n");
                i++;
	}
	return 0;
}
