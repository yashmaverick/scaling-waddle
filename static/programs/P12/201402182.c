#include<stdio.h>
long long int stack[1000007];
int main()
{
	long long int top,n;
	scanf("%lld",&n);
	while(n!=0)
	{
		top=-1;
		long long int i,count2=0,count1=0,tp;
		int flag=0;
		long long int a[n];
		for(i=0;i<n;i++)
		{
			if(flag==0)
				scanf("%lld",&a[i]);
			if(top==-1||a[i]<=a[stack[top]])
			{
				stack[++top]=i;
				if(top>1)
				{
					tp=top-1;
					while(a[stack[tp]]==a[stack[top]]&&tp!=-1)
					{
						tp--;
					}
					if(tp!=-1)
						count2+=tp;
				}
				flag=0;

			}
			else
			{
				top--;
				count1+=(n-i-1);
				i--;
				flag=1;

			}

		}
		long long int answer=count1+count2;
		printf("%lld\n",answer);
		scanf("%lld",&n);
	}
	return 0;
}
