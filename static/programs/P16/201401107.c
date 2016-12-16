#include<stdio.h>

int main()
{
	long long int testcase,i,j,query,flag;
	scanf("%lld",&testcase);
	for(i=0;i<testcase;i++)
	{
		long long int depth=0,val;
		scanf("%lld",&query);
		val=query;
		while(query!=0)
		{
			
			if(query==3||val==1)
				flag=0;
			else if(query==2)
				flag=1;
			depth++;
		
			query/=2;
				
		}
		if(flag==0)
			printf("%lld\n",2*depth-2);
		else if(flag==1)
			printf("%lld\n",2*depth-3);
	}
return 0;
}
