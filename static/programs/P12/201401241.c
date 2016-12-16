#include<stdio.h>
int top=-1;
int a[500010],item1,i,n,tp,j,k;
long long int count=0;
void push(int  item)
{
	if(top!=500010)
	{
		top++;
		a[top]=item;
	}
}

void pop()
{
	if(top!=-1)
	{
		item1=a[top];
		top--;
	}
}

int high()
{
	return a[top];
}

int main()
{
	int s;
	int kk;
	int rr;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
		{
			break;
		}
		//	for(i=0;i<n;i++)
		//	{
		//		scanf("%d",&a[i]);
		//	}
		count=0;
		top=-1;
		for(j=0;j<n;)
		{
			scanf("%d",&kk);
			if(top==-1||a[top]>=kk)
			{
				push(kk);
				j++;
			}
			else
			{
				rr=0;
				while(top>=0 && high()<kk)
				{
					s=0;
					while(top>=2&&a[top]==a[top-1])
					{
						s++;
						rr++;
						pop();
					}
					if(top>=1&&a[top]!=a[top-1])
					{
						count=count+(s+1)*(top-1);
					}
					pop();
					rr++;
				}
				count+=rr*(n-j-1);
				push(kk);
				j++;
			}
		}
		while(top>=0)
		{
			s=0;
			while(top>=2&&a[top]==a[top-1])
			{
				s++;
				pop();
			}
			if(top>=1&&a[top]!=a[top-1])
			{
				count=count+(s+1)*(top-1);
			}
			pop();
		}	
		printf("%lld\n",count);
//		printf("\n");
	}
	return 0;
}
