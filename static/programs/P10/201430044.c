#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long int i,sum;
	char *a[10000],c;
	for(i=0;i<10000;i++)
		a[i]=(char *)malloc(sizeof(char)*101);
	long long int first,last,n,item,count=0;
	first=last=0;
	scanf("%lld",&n);
	while((c=getchar())!='Q')
	{
		if(c=='A')
		{
			scanf("%lld",&item);
			while(item--)
			{
				if(last<n)
				{
					scanf("%s",a[last]);			
				}
				else
				{
					scanf("%s",a[last%n]);
				}
				if(first%n==last%n&&last>=n)
				{
					first++;
				}
				last++;
			}	
		}
		else if(c=='R')
		{
			scanf("%lld",&item);
				while(item--)
				{	first++;
				}
		}
		else if(c=='L')
		{
			if(first%n<(last)%n)
			{
				for(i=first%n;i<(last)%n;i++)
					printf("%s\n",a[i]);
			}
			else if(last%n==first%n)
			{
				if(first!=last){
				for(i=first%n;i<n;i++)
					printf("%s\n",a[i]);
				for(i=0;i<(last)%n;i++)
					printf("%s\n",a[i]);}
				else;
			}
			else 
			{
				for(i=first%n;i<n;i++)
					printf("%s\n",a[i]);
				for(i=0;i<(last)%n;i++)
					printf("%s\n",a[i]);

			}	
		}
		else if(c=='s')
			printf("%lld %lld %d\n",first%n,last%n,count);	
	}
	return 0;
}
