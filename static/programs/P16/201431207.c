#include<stdio.h>
int main()
{
	long long int test,flag,i;
	scanf("%lld",&test);
	for(i=0;i<test;i++)
	{
		long long int n,count,temp;
		scanf("%lld",&n);
		temp=n;
		count=0;
		if(n==1)
			printf("0\n");
		else
		{
			while(1)
			{
				if(n==2||n==3)
				{
					if(n==2)
						flag=1;
					else
						flag=0;
					break;
				}
				n=n/2;
			}
			while(1)
			{
				if(temp==1)
					break;
				count++;
				//printf("%d",count);
				temp=temp/2;
			}

			if(flag==1)
				printf("%lld\n",(2*count)-1);
			else
				printf("%lld\n",(2*count));
		}	
	}
	return 0;
}
