#include<stdio.h>
#include<string.h>
int cmp(const void *c,const void *b)
{
	return (*(int*)c-*(int*)b);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k,i;
		scanf("%d %d",&n,&k);
		int a[n];
		char string[100];
		for(i=0;i<n;i++)
			scanf("%s %d",string,&a[i]);
		qsort(a,n,sizeof(int),cmp);
		int first,last,sum;
		for(i=0;i<n;i++)
		{	
			sum=a[i];
			first=i+1;
			last=n-1;
			while(first<last)
			{
				sum=sum+a[first]+a[last];
				if(sum<k)
				{
					first++;
					sum=a[i];
				}
				else if(sum>k)
				{
					last--;
					sum=a[i];
				}
				else if(sum==k)
				{
					printf("YES\n");
					break;
				}
			}
			if(sum==k)
				break;
		}
			if(sum!=k)
			printf("NO\n");
	}
	return 0;
}
	

