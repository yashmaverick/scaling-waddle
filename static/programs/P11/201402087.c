#include<stdio.h>
long long int n;
long long int top;
long long int st[1000005];
long long int l[1000005];
long long int r[1000005];
void left( long long int a[] );
void right( long long int a[] );
long long int maxarea( long long int a[] );
int main()
{
		scanf("%lld",&n);
		while(n!=0)
		{
				long long int i;
				long long int a[1000005];
				top=0;		
				for(i=0;i<n;i++)
				{
						scanf("%lld",&a[i]);
						st[i]=0;
						l[i]=0;
						r[i]=0;
				}
				left(a);
				right(a);
				//for(i=0;i<n;i++)
				//		printf("i=%d	%d	%d	ma=%d\n",i,l[i],r[i],a[i]*(l[i]+r[i]+1));
				printf("%lld\n",maxarea(a));
				scanf("%lld",&n);
		}
		return 0;
}

void left( long long int a[] )
{
		long long int i;
		top=0;
		for( i=0 ; i<n ; i++ )
		{
				while((top!=0)&&(a[i]<=a[st[top-1]]))
						top--;
				if(top==0)
						l[i]=i;
				else
				{
					//	printf("%d	else\n",i);
						l[i]=i-st[top-1]-1;
				}
				st[top]=i;
			//	printf("%d=top	%d\n",top,st[top]);
				top++;

		}
}

void right(long long int a[] )
{
		long long int i;
		top=0;
		for( i=n-1 ; i>=0 ; i-- )
		{
				while((top!=0)&&(a[i]<=a[st[top-1]]))
						top--;
				if(top==0)
						r[i]=n-1-i;
				else
				{
					//	printf("%d	else\n",i);
						r[i]=st[top-1]-i-1;
				}
				st[top]=i;
			//	printf("%d=top	%d\n",top,st[top]);
				top++;

		}
}

long long int maxarea( long long int a[] )
{
		long long int max=0;
		long long int temp;
		long long int i;
		for(i=0;i<n;i++)
		{
				temp=(a[i]*(l[i]+1+r[i]));
				if(temp>max)
						max=temp;
		}
		return max;
}
