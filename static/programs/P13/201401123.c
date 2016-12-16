#include<stdio.h>
typedef long long int L;
#define s(n) scanf("%lld",&n)

typedef struct tree_stack{
	int value;
	int height;
}ts;

int main()
{
	L n,t,i; s(t);
	L maxdepth,ans,temp;
	while(t--)
	{
		s(n);
		ts b[n];
		L a[n];
		for(i=0;i<n;i++)
			s(a[i]);
		L flag = 0;
		L top = -1;
		ans = a[n-1];
		for(i=n-1;i>=0;i--)
		{
			if(top == -1)
			{
				b[++top].value=a[i];
				b[top].height = 0;
				maxdepth=b[top].height;
			}
			else
			{
				if(a[i]>b[top].value)
				{
					b[++top].value = a[i];
					b[top].height=b[top-1].height+1;
					if(b[top].height >= maxdepth)
					{
						maxdepth = b[top].height; ans = a[i];
					}
				}
				else
				{
					while(top !=(-1) && a[i]<b[top].value)
					{
						temp =  b[top].height;
						top--;				
					}
					//if(top==-1)
					//{
					//		b[++top].value=a[i];
					//		b[top].height=temp + 1;
					//	}
					//	else
					//	{
					b[++top].value=a[i];
					b[top].height = temp + 1;
					if(b[top].height >= maxdepth)
					{
						maxdepth = b[top].height; ans = a[i];
					}
				}
			
			}
		}
		printf("%lld %lld\n",ans,maxdepth);
	}
	return 0;
}
