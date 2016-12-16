#include <stdio.h>
#include <string.h>

long long int stack[1000000];

long long int top;

void print(long long int arr[],long long int l)
{
	long long int i;
	for(i = 0; i<=l; i++){
		printf("%lld ", arr[i]);
	}
	printf("\n");
	return ;
}

void push(long long int value){
	top++;
	stack[top] = value;

}

long long int pop(){
	long long int poped_element;
	if ( top == -1 )
		return top;

	poped_element = stack[top];
	top--;
	return poped_element;
}   

long long int is_empty(){
	if ( top == - 1 )
		return 1;
	else
		return 2;
}
long long int top_element(){
	return stack[top];
}


long long int get_max_area(long long int arr[], long long int len)
{
	long long int max_area=0, i=0,tp,area;
	memset(stack,0,sizeof(stack));
	top = -1;
	while(i < len)	{
		if((is_empty() == 1) || (arr[top_element()] <= arr[i]))
		{
			push(i);
			i++;
		}
		else{
			tp = top_element(stack);	
			pop();
			area = arr[tp] * ((is_empty() == 1) ? i : (i - top_element() -1));
			if(max_area < area)
				max_area = area;
		}
	}

	while(is_empty() == 2){
		tp = top_element();
		pop();
		area = arr[tp] * ((is_empty() == 1) ? i : (i - top_element() -1));
		if(max_area < area)
			max_area = area;

	}
	return max_area;
}


int main()
{
	long long int n, t, ans;
	while(1){
		scanf("%lld",&n);
		if(n==0)
			return 0;
		else
		{

		long long int x[100007],i;
			for(i=0;i<n;i++)
			{
				scanf("%lld",&x[i]);
			}

			ans = get_max_area(x, n);
			printf("%lld\n",ans );
		}
	}
	return 0;
}
