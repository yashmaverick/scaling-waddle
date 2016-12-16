#include <stdio.h>
void print(int a[], int top)
{
	int i;
	for (i = 0; i <= top; i++)
		printf("%d ",a[i]);
	printf("End of print\n");
}
int main()
{
	while(1)
	{
		long long int n;
		long long int ways=0;
		long long int i,j;
		int f=0;
		int tmp,d,top=-1;
		int stack[500000];
		int stack1[500000];
		int a[500000];
		int c[500000];
		for (i = 0;  i < 500000; i++)
			c[i] = 1;
		scanf("%lld",&n);
		if (n == 0) break;
		for (i = 0; i < n; i++)
			scanf("%d",&a[i]);
		i = 0;
		while(i < n)
		{
			f=0;
			if (top == -1)
			{
				top++;
				stack[top] = a[i];
				i++;
			}
			else if (stack[top] == a[i])
			{
				for (j = top; j >= 0; j--)
					{
						if (stack[j] == a[i])
							ways++;
						else if (f == 0) 
						{
							ways++;
							f=1;
						}
					}
				top++;
				stack[top] = a[i];
				i++;
			}
			else if (stack[top] < a[i])
			{
				top--;
				ways++;
			}
			else if (stack[top] > a[i])
			{
				top++;
				ways++;
				stack[top] = a[i];
				i++;
			}
		}
		long long int ans = (n*(n-1))/2;
		ans -= ways;
		printf("%lld\n",ans);
	}
	return 0;
}
