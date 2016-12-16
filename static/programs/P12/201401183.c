#include<stdio.h>
long long int a[500009],st[500009];
long long int sum,top=-1;
void push(long long int val)
{
	st[++top]=val;
}
void pop()
{
	if(top==-1)
		printf("-1\n");
	else
		--top;
}
void peek()
{
	printf("%lld\n",st[top]);
}
void print()
{
	long long int i;
	if(top>-1)
	{
		for(i=0;i<=top;i++)
			printf("%lld  ",st[i]);
		printf("\n");
	}

}
long long int summer(long long int x)
{
	sum+=x;
}
int main()
{
	long long int n,temp,i;
	scanf("%lld",&n);
	while(n!=0)
	{
		long long int j;
		//scanf("%d",&n);
		//if(n!=0)
		//{
		for(j=0;j<n;j++)
			scanf("%lld",&a[j]);
		i=0,sum=0,top=-1;
		while(i<n)
		{
			if(top==-1)
			{

				push(a[i++]);
				//      printf("pushed %d ",a[i-1]);
				temp=top;
				while((st[top]==st[temp])&&(temp>0))
					temp--;
				summer(temp);
			}
				/*else if(a[i]<st[top])
				  {
				  if(top-1 >= 0)
				  sum+=top-1;
				  push(a[i++]);
				  }*/
			else if(a[i]==st[top]||a[i]<st[top])
				{
					push(a[i++]);
					//	printf("pushed %d ",a[i-1]);
					temp=top;
					while((st[top]==st[temp])&&(temp>0))
						temp--;
					summer(temp);
					//push(a[i++]);
				}
				else
				{
					//		printf("popped %d ",st[top]);
					pop();
					//sum+=n-i-1;
					summer(n-i-1);
					//push(a[i++]);
				}
			}
			printf("%lld\n",sum);
			//	}
			//else break;
			scanf("%lld",&n);
	}
	return 0;
	}

