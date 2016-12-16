#include<stdio.h>
char st[100001];
int a[1001];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k,x,i,j,l,sum=0,flag=0,temp;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%s ",st);
			scanf("%d",&a[i]);
		}
		for (i = 1; i < n; i++) 
		{
			for (j = 0; j < n - 1; j++) 
			{
				if (a[j] > a[j + 1]) 
				{
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
		for(i=0;i<n-2;i++)
		{
			j=i+1;
			l=n-1;
			while(j<l)
			{
				sum=a[i]+a[j]+a[l];
				if(sum==k)
				{
					flag=1;
					break;
				}
				if(sum<k)
					j++;
				if(sum>k)
					l--;
			}
			if(flag==1)
				break;
		}
		if(flag==0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
