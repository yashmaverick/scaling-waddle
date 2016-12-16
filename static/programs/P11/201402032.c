#include<stdio.h>

struct stack {
	long long int s[100005];
	long long int top;
} st;

void push(long long int item) {
	st.top++;
	st.s[st.top] = item;
}

long long int stempty() {
	if (st.top == -1)
		return 1;
	else
		return 0;
}

long long int pop() {
	long long int item;
	item = st.s[st.top];
	st.top--;
	return (item);
}

long long int main()
{
	long long int logs[1000005];
	long long int i,n,max_area,top_area,ind;
	scanf("%lld", &n);
	while(n!=0)
	{
		max_area = 0;
		st.top = -1;
		for(i=0;i<n;i++)
			scanf("%lld", &logs[i]);
		for(i=0;i<n;)
		{
			if(stempty() || logs[st.s[st.top]]<= logs[i])
				push(i++);	
			else
			{
				ind = st.s[st.top];
				pop();
				top_area=logs[ind]*(stempty() ? i : i - st.s[st.top] - 1);
				if(max_area < top_area)
					max_area = top_area;
			}
		}
		while(stempty() != 1)
		{
			ind = st.s[st.top];
			pop();
			top_area=logs[ind]*(stempty() ? i : i - st.s[st.top]- 1);
			if(max_area < top_area)
				max_area = top_area;

		}	
		printf("%lld\n",max_area);
		scanf("%lld", &n);

	}
	return 0;
}