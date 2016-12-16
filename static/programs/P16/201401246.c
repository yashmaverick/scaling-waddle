#include<stdio.h>
#include<math.h>
int main()
{
	int t,log=0;
	long int n,k;
	scanf("%d",&t);
	while(t--)
	{
		log=0;
		scanf("%ld",&n);
		for(k=n;k>1;k=k/2)
			log++;
		if(n==1)
			printf("0\n");
		else if(n<(3*pow(2,log-1)))
			printf("%d\n",(2*log)-1);
		else
			printf("%d\n",(2*log));
	}
	return 0;
}