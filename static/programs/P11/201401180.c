#include <stdio.h>
struct node
{
	long long int val;
	long long int index;
	long long int pop;
};
void push(struct node a[], struct node b, long long int *top)
{
	(*top)++;
	a[(*top)]= b;
}
void pop(struct node a[], long long int *top)
{
	(*top)--;
}
int main()
{
	while(1)
	{
		long long int n,i,j,top,max,d,e,f,tmp,end,tmp1;
		max=0;
		top=-1;
		scanf("%lld",&n);
		struct node a[100200];
		struct node b;
		long long int ind=0;
		long long int in[100200];
		long long int po;
		if (n == 0) break;
		for (i = 0; i < n; i++)
			scanf("%lld",&in[i]);
		for (i = 0; i < n; i++)
		{
			b.val=in[i];
			b.index=i;
			b.pop=0;
			if (i == 0)
			{	
				push(a,b,&top);
			}
			else
			{
				if (top == -1|| (a[top].val) <= in[i])
				{
					push(a,b,&top);
				}
				//po=0;
				else
				{
					while (a[top].val > in[i])
					{
						pop(a,&top);
						if (top == -1) break;
						//tmp=(a[top].val * a[top].pop) + ((i-a[top].index)*a[top].val);
						tmp = a[top+1].val * (i-a[top].index-1);
						//po=po+1+a[top].pop;
						//tmp = a[top].val * (i-top);
						if (tmp > max)
							max = tmp;
					}
					if ((top == -1 || (a[top].val) <= in[i]))
					{
						if (top == -1) tmp = a[top+1].val * i;
						//else tmp = a[top+1].val * (i-a[top].index-1);
						if (tmp > max) max = tmp;
						push(a,b,&top);
					}
				}		
			}
		}
		while (top > -1)
		{	
			pop(a,&top);
			if (top == -1) tmp = a[top+1].val * i;
			else tmp = a[top+1].val * (i-a[top].index-1);
			//tmp=(a[top].val * (a[top].pop)) + ((i-a[top].index-1)*a[top].val);
			if (tmp > max)
				max = tmp;
		}
		printf("%lld\n",max);
	}
	return 0;
}

