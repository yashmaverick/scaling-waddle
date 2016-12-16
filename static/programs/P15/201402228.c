#include<stdio.h>
int a[10000];
int stack[10000];
int top;
int head;
void push(int n)
{
	if(head==-1)
		head=0;
	top++;
	stack[top]=n;
	//printf("%d\n",n);

}
void pop()
{
	//	if(head==top)
	//	{
	//		head--;
	//		top--;
	//	}
	//	else
	top--;
	//	if(head>=top)
	//		head=top;
}
void deq()
{
	head=head+1;
	//	a[-1]=head;
}

int main()
{
	int t,j,n,k,i,p,sum=0;
	int min[10000],co;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		sum=0;
		co=0;
		top=-1;
		head=-1;
		scanf("%d%d",&n,&k);
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[j]);
		}
		for(j=0;j<n;j++)
		{
			if(top==-1)
			{
				push(j);
				co++;
			}
			else
			{
				//	printf("hi");
				if(a[j]>=a[stack[top]])
				{
					push(j);
					co++;
				}
				else
				{
					while(a[j]<a[stack[top]] && head<=top)
					{
						pop();
						if(top==-1)
						{
							head=-1;
							break;
						}
					}
					push(j);
					co++;
				}
			}
			//	printf("%d\n",a[stack[head]]);

			if(co>=k && sum<=(n-k+1))
			{
				if(sum<n-k)
					printf("%d ",a[stack[head]]);
				else
					printf("%d\n",a[stack[head]]);
				sum++;

				if(stack[head]==j-(k-1))
				{

					if(k==1)
						pop();
					else
					{

						deq();
						//top=head;
					}
				}
			}
		}
	}
	return 0;
}





