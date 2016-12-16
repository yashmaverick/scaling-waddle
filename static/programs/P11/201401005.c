#include<stdio.h>
#include<limits.h>


typedef struct stack{
	int top;
	int a[1000001];
} Stack;

Stack S;

void push(int val){
	S.a[++S.top] = val;
}

void pop(){
	S.a[S.top--] = INT_MIN;
}

int peek(){
	return S.a[S.top];
}

//int s[1000001];

int main(){
	long long int topp, n, i, j, max, area, x;
	long long int temp1, temp2;
	long long a[1000001];

	while(1){
		int fl = 0;
		scanf("%lld", &n);
		if(n == 0)
			break;
		for(i=0; i<n; i++)
			scanf("%lld", &a[i]);

//		topp = 0;
//		s[topp] = a[0];
//		t[topp] = 0;
//		topp = -1;
		max = 0;
		i = 0;
		S.top = -1;
		while(i < n){
			if(S.top == -1 || a[peek()] <= a[i]){
//				s[++top] = a[i];
				push(i);
				i++;
			}
			else{
				fl++;
//				temp1 = s[topp];
				temp2 = peek();
//				s[topp] = 0;
				pop();

				if(S.top == -1)
					area = a[temp2]*i;
				else
					area = a[temp2]*(i-peek()-1);
				if(area > max)
					max = area;
//				printf("%lld ", max);
			}
		}
		while(S.top >= 0){
//			temp1 = s[topp];
			temp2 = peek();
//			s[topp] = 0;
			pop();

			if(S.top == -1)
				area = a[temp2]*i;
			else
				area = a[temp2]*(i-peek()-1);
			if(area > max)
				max = area;
//				printf("%lld ", max);
		}

		printf("%lld\n", max);
		pop();
		S.top = -1;
	}

	return 0;
}
