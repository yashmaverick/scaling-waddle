#include <stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		int stack[100010];
		int i;
		int a[100010];
		int h[100010];
		int max1[100010];
		for (i = 0; i < 100010; i++)
			max1[i] = 100000;
		int max = 0;
		int top = 0;
		int t;
		scanf("%d",&n);
		for (i = 0; i < n; i++)
			scanf("%d",&a[i]);
		stack[top] = a[n-1];
		h[top] = 0;
		//printf("%d\n",h[top]);
		for (i = n-2; i >= 0; i--)
		{
			if (top == -1 || stack[top] < a[i])
			{
				top++;
				stack[top] = a[i];
				h[top] = h[top-1]+1;
				if (h[top] >= max) 
				{
					max = h[top];
					if (max1[h[top]] > stack[top]) 
						{max1[h[top]] = stack[top];}
				}
				//printf("%d\n",h[top]);
			}
			else if (stack[top] > a[i])
			{
				while (1)
				{
					if (top == -1) {t=h[top+1]; break;}
					else if (stack[top] < a[i]) {t = h[top+1];break;}
					top--;
				}
				top++;
				stack[top] = a[i];
				h[top] = t+1;
				if (h[top] >= max) 
				{
					max = h[top];
					if (max1[h[top]] > stack[top]) 
						{max1[h[top]] = stack[top];}
				}
				//printf("%d\n",h[top]);
			}
		}
		printf("%d %d\n",max1[max],max);
	}
	return 0;
}
