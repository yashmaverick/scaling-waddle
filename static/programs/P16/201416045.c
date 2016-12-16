#include<stdio.h>
int main()
{
	long long int k,i,j,i1,count,flag=0;
	long long int q,n;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		count=0;
		scanf("%lld",&q); i1=q;
		while(q!=1)
		{
			q=q/2;
			count++;
			if(q == 2)
				flag=1;
		}
		if(i1==2) printf("1\n");
		else if(flag==1)
			printf("%lld\n",(2*count)-1);
		else
			printf("%lld\n",2*count);
		flag=0;
	}
return 0;
}

