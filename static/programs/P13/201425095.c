#include<stdio.h>
int arr[100000];
int depth;
int node;
struct stack
{
	int sk[100001];
	int top;
	int level[100001];
};

typedef struct stack stk;
stk st;

void push(int n , int l)
{
	/*if(st.top == -1)
	{
		st.top = 0;
		s.sk[st.top] = n;
		st.level[st.top] = l;

	}*/
	if(n<st.sk[st.top])
	{
		int t = st.level[st.top] +1;
		st.top--;
		push(n,t);

	}
	else if(st.top == -1)
	{
		st.top = 0;
		st.sk[st.top]=n;
		st.level[st.top]=l;
	}
	else
	{
		int t;
		if(l==0)
			t = st.level[st.top]+1;
		else
			t=l;
				st.top++;
				st.sk[st.top] = n;
				st.level[st.top] = t;

		
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t-- )
	{
		depth = 0;
		node = 0;

		st.top = -1;
		int num;
		scanf("%d", &num);
		int i;
		for ( i=0; i<num; i++ )
		{
			scanf("%d", &arr[i]);
		}
		for ( i=num-1; i>=0; i--)
		{
			push(arr[i], 0);
			if( st.level[st.top] >= depth )
			{
				depth = st.level[st.top];
				node = st.sk[st.top];
			}
		}
		
		printf("%d %d\n", node, depth);


	}
	return 0;
}
