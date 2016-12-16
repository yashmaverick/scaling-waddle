#include<stdio.h>
int main()
{
	long long int a[500001],b[500001];
	long long int i,n,res,number,top,tp;
	while(1)
	{
		res=0;
		top=-1;
		scanf("%lld",&n);
		if(n==0)
			break;
		else
		{
			for(i=0;i<n;i++)
				scanf("%lld",&a[i]);
			i=0;
			number=0;
			while(i<n)
			{	number=0;
				if(top==-1||a[i]<=a[b[top]])
				{
					top++;
					b[top]=i;
					i++;
				}
				else
				{
					while(top>=0 && a[i]>a[b[top]])
					{
						res+=n-i-1;
						tp=b[top];
						top--;
						if(top<0)continue;
						if(top>=0 && a[tp]==a[b[top]])
						{
							number++;
						}
						else if(top>=0 && a[tp]!=a[b[top]])
						{
							res+=top;
							res+=(number)*top;
							number=0;
						}
					}
				}
			}
			number=0;
			while(top>=0)
			{
				tp=b[top];
				top--;
				if(top>=0 && a[tp]==a[b[top]])
					number++;
				else if(top>=0 && a[tp]!=a[b[top]])
				{
					res+=top;
					res+=(number)*top;
					number=0;
				}
			}
			printf("%lld\n",res);
		}
	}
	return 0;
}
