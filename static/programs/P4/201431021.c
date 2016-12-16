#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int comp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}
int main()
{
	int i,i1,cases,t,a[100000],j,k1;
	char s[100000];
	long long int ans ,k;
	scanf("%d",&t);
	for (i1 = 0; i1 < t; ++i1)
	{
		ans=0;
		int len=0,k=0;
		scanf("%s",s);
		len=strlen(s);
		a[0]=0;
		if(s[0]=='J')
		{
			a[1]=200000;
		}
		else if(s[0]=='M')
		{
			a[1]=-199999;
		}
		else
		{
			a[1]=-1;
		}
		for ( j= 1; j <=len; ++j)
		{
			/* code */
			if (s[j]=='J')
			{
				a[j+1]=a[j]+200000;
				/* code */
			}
			else if (s[j]=='M')
			{
				a[j+1]=a[j]-199999;
				/* code */
			}
			else
			{

				a[j+1]=a[j]-1;
			}
		}
			qsort(a,len+1,sizeof(int),comp);
		k=1;
		for (i = 0; i <= len-1; i++)
		{
			if(a[i]==a[i+1])
				k++;
			else
			{
				ans=ans+(k*(k-1))/2;
				k=1;
			}
		}
		ans=ans+(k*(k-1))/2;
		printf("%lld\n",ans);
		}
	
	return 0;
}
