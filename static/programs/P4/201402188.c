#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[100010];

int compare(const void *a, const void *b) 
{
	return (*(int*)a - *(int*)b);
}
int main()
{
	int jaa,test;
	scanf("%d",&test);
	for(jaa=0;jaa<test;jaa++)
	{
		int l,i,sum;
		char s[100000];
		scanf("%s",s);
		l=strlen(s);
		sum=0;
		a[0]=0;
		for(i=0;i<l;i++)
		{
			if(s[i]=='J')
			{
				sum=sum+100001;
				a[i+1]=sum;
			}
			else if(s[i]=='M')
			{
				sum=sum+100002;
				a[i+1]=sum;
			}
			else
			{
				sum=sum-200003;
				a[i+1]=sum;
			}
		}

		qsort(a,l+1,sizeof(int),compare);
		/*for(i=0;i<=l;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
*/
		a[l+1]=-1000000000;
		long long int count=1,j,sum1=0;
		for(i=0;i<=l;i++)
		{
			if(a[i]==a[i+1]){
				count++;
	//		printf("count: %d\n",count);
			}
			else if(a[i]!=a[i+1])
			{
				sum1=sum1+(count*(count-1)/2);
				count=1;
			}
		}
				sum1=sum1+(count*(count-1)/2);
		printf("%lld\n",sum1);
	}
	return 0;
}					
