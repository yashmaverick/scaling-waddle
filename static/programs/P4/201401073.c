#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define maxl 100010

int cmpfunc( const void * a,const void * b)
{
	return ((*(int*)a) - (*(int*)b));
}

unsigned long long int add(unsigned long long int n)
{
	return ((n*(n-1))/2);
}

int main()
{
	int testc;
	scanf("%d",&testc);
	while(testc--)
	{
		char str[maxl];
		unsigned long long int i,len,temp,count = 0;
		long long int num,sum[maxl];
		scanf("%s",str);
		len = strlen(str);
		for(i=0;i<len;i++)
		{
			if(str[i]=='J')
				sum[i] = -100001;
			else if(str[i]=='M')
				sum[i] = 1;
			else if(str[i] == 'R')
				sum[i] = 100000;
			if(i!=0)	
				sum[i] = sum[i-1] + sum[i];
		}		
		qsort(sum,len,sizeof(long long int),cmpfunc);
		num = sum[0];
		temp = 1;
		for(i=1;i<len;i++)
		{
			if(sum[i]==num)
				temp++;
			else
			{
				if(num==0)
					count = count + temp + add(temp);
				else
					count = count + add(temp);
				temp = 1;
				num = sum[i];
			}
		}
	if(num==0)
		count = count + temp +add(temp);
	else	
		count = count + add(temp);
	printf("%llu\n",count);
	}
	return 0;
}
