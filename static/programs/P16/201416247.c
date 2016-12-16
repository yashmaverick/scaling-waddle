#include<stdio.h>
#include<math.h>
int main()
{

	int a,t,x,n,i,k,j;
	scanf("%d",&n);
	for(t=0;t<n;t++)
	{
		scanf("%d",&a);
		x=a+(a/2);
		int   k=log2(a);
		x=pow(2,k);
		//for(i=0;i<100000;i++)
		//printf("%d\n",x);
		//printf("%d\n",k);
		int y=x+x/2;
		if(a>=y)
				printf("%d\n",2*k);
		else
			printf("%d\n",2*k-1);		
	}
	return 0;
}
