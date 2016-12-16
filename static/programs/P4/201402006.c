#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int comp(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}
int main()
{
	int t;
	long long int s,count;
	int i,k,a[100001],length;
	char instr[100000];
	scanf("%d",&t);
	while(t--)
	{
		a[0]=0;
		s=0;
		count=0;
		scanf("%s",instr);
		length=strlen(instr);
		for(i=0;i<length;i++)
		{
			if(instr[i]=='J')
				a[i+1]=1000001;
			else if(instr[i]=='M')
				a[i+1]=1000002;
			else if(instr[i]=='R')
				a[i+1]=-2000003;
			a[i+1]=a[i]+a[i+1];
		}
		qsort(a,length+1,sizeof(int),comp);
		if(a[0]==a[1]) 
			count++;
		for(k=1;k<=length;k++)
		{
			if(a[k]==a[k-1])
				count++;
			else
			{
				s+=((count)*(count-1))/2;
				count=1;
			}
		}
//		printf("count=%d\n",count);
		s+=((count)*(count-1))/2;
		printf("%lld\n",s);
	}
	return 0;
}
