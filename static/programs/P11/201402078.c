#include<stdio.h>
int main()
{
	long long int n,i,j,k,t;
	scanf("%lld",&n);
	while (n!=0)
	{
		long long int a[n],st[n],top=-1,max=0,ans=0;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(i=0;i<n;i++)
		{
			if (top==-1||a[st[top]]<a[i])
			{
				top++;
				st[top]=i;
			}
			else
			{
				while(top!=-1 && a[st[top]]>=a[i])
				{
					t=st[top];
					top--;
					if(top!=-1) 
						ans=a[t]*(i-1-st[top]);
					else
						ans=a[t]*i;
					if (max<ans)
						max=ans;
				}
				top++;
				st[top]=i;
			}
		}
		while (top!=-1)
		{
			t=st[top];
			top--;
			if(top!=-1) 
				ans=a[t]*(n-1-st[top]);
			else
				ans=a[t]*n;
			if (max<ans)
				max=ans;

		}
		printf("%lld\n",max);
		scanf("%lld",&n);
	}
	return 0;
}
