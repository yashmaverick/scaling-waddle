#include<stdio.h>
int main()
{
	char s[25];
	int t, n,i,j,m,k,flag,temp,sum;
	long long int a[1000];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%d",&k);
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			scanf("%lld",&a[i]);
		}

		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
			{
				if(a[i]>a[j])
				{
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		flag=0;

		for(i=0;i<n;i++)
		{
			j=i+1;
			m=n-1;
			while(j<m)
			{
				sum=a[i]+a[j]+a[m];
				if(sum==k)
				{
					flag=1;
					break;
				}
				else if(sum<k)

					j++;
				else
					m--;
			}
			if(flag==1)
				break;
		}
		if(flag==1)
			printf("YES\n");

		else 
			printf("NO\n");

	}
}


