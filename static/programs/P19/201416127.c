#include<stdio.h>
#include<stdlib.h>
int func(const void *a,const void *b)
{
	return (*(long long int*)a - *(long long int*)b);
}
int l=0;
void convert(long long int num,long long int b[])
{
	while(1)
	{
		num=num/10;
		//printf("%d\n",num);
		if(num==0)
			break;
		b[l]=num;
		l++;
	}
	return ;
}
int binarysearch(long long int num,long long int b[])
{
	int first,last,middle;
	first=0;
	last=l-1;
	middle=(first+last)/2;
	int c=0;
	while(first<=last)
	{
		if(num==b[middle])
		{
			c=1;
			break;
		}
		else if(num<b[middle])
			last=middle-1;
		else
			first=middle+1;
		middle=(first+last)/2;
	}
	return c;		
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i;
		int flag=0;
		scanf("%d",&n);
		long long int a[n];
		long long int b[9*n];
		l=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			convert(a[i],b);
		}
		qsort(b,l,sizeof(long long int),func);
		qsort(a,n,sizeof(long long int),func);
		//for(i=0;i<n;i++)
		//	printf("%d ",a[i]);
		//printf("\n");
		i=0;
		int check;
		//	binarysearch(a[i],b);
		while(i!=n)
		{	
			check=binarysearch(a[i],b);
			if(check==1)
			{
				printf("NO\n");
				flag=1;
				break;
			}
			//binarysearch(a[i],b);
			i++;
		}
		i=0;
		if(flag==0)
		{
			while(i!=n-1)
			{
				if(a[i]==a[i+1])
				{
					printf("NO\n");
					flag=1;
					break;
				}
				i++;
			}
			if(flag==0)
				printf("YES\n");
		}
	}
	return 0;
}
