#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int main()
{
	int t,i,j;
	char string[100000];
	long long int strsum[100001];
	long long int sum,count;
	scanf("%d",&t);
	for (i = 0; i < t; i++)
	{
		scanf("%s",string);
		int len = strlen(string);
		if(string[0]=='J')
			strsum[0]=300000;
		else if(string[0]='M')
			strsum[0]=-1;
		else
			strsum[0]=-299999;
		for(j=1;j<len;j++)
		{
			if(string[j]=='J')
			strsum[j]=strsum[j-1]+300000;
			else if(string[j]=='M')
			strsum[j]=strsum[j-1]-1;
			else
			strsum[j]=strsum[j-1]-299999;
		}
		qsort (strsum, len, sizeof(long long int), compare);
		count=1;
		sum=0;
		for(j=0;j<len;j++)
		{
			if(strsum[j]==strsum[j+1])
				count++;
			else
			{
				sum+=((count)*(count-1))/2;
				count=1;
			}
		}
		for(j=0;j<len;j++)
			if(strsum[j]==0)
				sum++;
		sum+=((count)*(count-1))/2;
		printf("%lld\n",sum);
	}
	return 0;
}