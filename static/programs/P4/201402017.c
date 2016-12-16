#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
	char a[100004];
	int t,i,l,x,y,z,s,k,c,s1,flag[1000004]={0};
	//scanf("%d",&t);
	//while(t--)

	//{
		x=(-1*100000)-1;
		y=1;
		z=100000;
		scanf("%s",a);
		l=strlen(a);
		s=0;k=1;
		for(i=0;i<l;i++)
		{
			if(a[i]=='J')
			{
				s=s+x;
				flag[k++]=s;
			}
			if(a[i]=='M')
			{
				s=s+y;
				flag[k++]=s;
			}
			if(a[i]=='R')
			{
				s=s+z;
				flag[k++]=s;
			}
		}
		//for(i=0;i<=l;i++)
		//	printf("%d ",flag[i]);
		qsort(flag,l+1,sizeof(int),cmpfunc);
		//for(i=0;i<=l;i++)
		//	printf("%d ",flag[i]);
		c=1;s1=0;
		for(i=1;i<=l;i++)
		{
			if(flag[i-1]==flag[i])
			{
				c++;
			}
			else
			{
				s1=(s1+((c*(c-1))/2));
				c=1;
			}
		}
		s1=(s1+((c*(c-1))/2));
		printf("%d\n",s1);
	}
	return 0;
}



