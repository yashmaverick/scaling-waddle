#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmpfunc(const void *a,const void *b)
{
	return (*(int*)a-*(int*)b);
}
int main()
{	int t,i,j,m,a[100000],k;
	long long int s,c;
	char str[100007];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%s",str);
		k=strlen(str);
		a[0]=0;
		for(j=0;j<k;j++)
		{
			if(str[j]=='J')
				a[j+1]=a[j]+(100001);
			else if(str[j]=='M')
				a[j+1]=a[j]-(100000);
			else if(str[j]=='R')
				a[j+1]=a[j]-(1);
		}		
	qsort(a,j+1,sizeof(int),cmpfunc);
	s=0;	
	c=1;
		for(j=1;j<k+1;j++)
		{
			if(a[j]==a[j-1])
				c++;
			else
			{
				s+=(c*(c-1))/2;
				c=1;
			}
		}
		s+=(c*(c-1))/2;
		printf("%lld\n",s);
	}
	return 0;
}

