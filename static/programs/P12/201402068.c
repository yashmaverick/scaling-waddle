#include <stdio.h>
long long int stack[500005];
long long int elements;
long long int top;
void push(long long int x);
void pop();
long long int peek();
long long int count;
long long int arr[500005];
int main()
{
	long long int n;
	while(1)
	{
		top=-1;
		elements=0;
		count=0;
		scanf("%lld",&n);
		if(n==0)
			break;
		long long int i;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&arr[i]);
		}
		for(i=0;i<n;i++)
		{
			int k;
			if(elements==0)
			{ //printf("pushing alright\n");
				push(arr[i]);
			}
			else
			{
				if(peek()<arr[i])
				{
					while(peek()<arr[i] && elements!=0)
					{
						//printf("INFINITE LOOP 1\n");
						count++;
						pop();

			//printf("\nans1 %lld \n",count);
					}

					if(elements!=0 && peek()==arr[i])

					{

						long long int t=top;

						while(t>-1)
						{ // printf("INFINITE LOOP 2\n");

							if(arr[i]==stack[t])
								count++;
							else if(arr[i]<stack[t])
							{
								count++;
								break;
							}
							t--;
						}
			//printf("\nans2 %lld \n",count);
					}

					if(elements!=0 && peek()>arr[i])
						count++;
					push(arr[i]);
				}
				else if (peek()>arr[i])
				{
					count++;
					push(arr[i]);
				}
				else if(peek()==arr[i])

				{

					long long int t=top;

					while(t>-1 )
					{ // printf("INFINITE LOOP 2\n");

						if(arr[i]==stack[t])
							count++;
						else if(arr[i]<stack[t])
						{
							count++;
							break;
						}
						t--;
					}
					push(arr[i]);
				}
			}
		/*	for(k=0;k<5;k++)
				printf("%lld ",stack[k]);
			printf("\nans %lld \n",count);*/
		}
		long long int ans=(n*(n-1))/2;
		ans=ans-count;
		printf("%lld\n",ans);
	}

	return 0;
}
void push(long long int x)
{

	if(elements==500005)
		return;
	else
	{
		top++;
		elements++;
		stack[top]=x;

	}
}
void pop()
{
	if(elements==0)
		return;
	else
	{
		elements--;
		top--;
	}
}
long long int peek()
{
	if(top==-1)
		return -1;
	else
		return stack[top];
}
