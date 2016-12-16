#include<stdio.h>
int main()
{
	while(1)
	{
		long long int n,top=-1,i,j,k,final=0,tp;
		scanf("%lld",&n);
		if(n==0)
			break;
		long long int a[n],b[n];
		long long int stack[n],stack2[n];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			if(top==-1||a[i]<=a[stack[top]])
			{
				stack[++top]=i;
				if(top>1)
				{
					j=top-1;
					tp=top;
					while(j>=0&&a[stack[j]]==a[stack[tp]])
						j--;
					if(j!=-1)
					{
							final+=j;
					}
				}
			}
			else
			{
				tp=stack[top];
				top--;
				j=top;
				final+=n-i-1;
				i--;
			}
		}
/*		k=0;
		for(i=top;i>=0;i--)
			b[k++]=a[stack[i]];
		printf("%d\n",final);
		top=-1;
		for(i=0;i<k;i++)
		{
			if(top==-1||b[i]<=b[stack[top]])
			{
				stack[++top]=i;
			}
			else
			{
				tp=stack[top];
				top--;
				j=top;
				final+=k-i-1;
				i--;
			}

		}*/
		printf("%lld\n",final);
	}
	return 0;
}
