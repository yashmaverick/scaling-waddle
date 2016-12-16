#include<stdio.h>
#include<math.h>
int main()
{
	int j,q,n,i,max1,max2,max,k,flag;
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{
		max1=0;max2=0;
		scanf("%d",&n);
		k=log2(n);
		if(n==1)
		{
			max=0;
		}
		 else 
		 {
			 if(n<((pow(2,k)+pow(2,k+1))/2))
		{
			max=(2*k-1);
		}
		else
			max=2*k;
		 }
		printf("%d\n",max);
	}

	return 0;
}
