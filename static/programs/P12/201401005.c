#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<ctype.h>

int a[500002];
int b[500002];
int c[500002];

typedef struct stack{
	int s[500002];
	int top;
} Stack;

Stack S;

void push(int val){
	S.s[++S.top] = val;
}

void pop(){
	S.top--;
}

int peek(){
	return S.s[S.top];
}

void min_big(int n, int top){
	int i;
	push(1);
	for(i=2; i<=n; i++){
		while(S.top!=-1 && a[peek()]<=a[i])
			pop();
		if(S.top!=-1)
			b[i] = peek();
		push(i);
	}
}

void min_bigeq(int n, int top){
	int i;
	push(1);
	for(i=2; i<=n; i++){
		while(S.top!=-1 && a[peek()]<a[i])
			pop();
		if(S.top!=-1)
			c[i] = peek();
		push(i);
	}
}

int main(){
	int i, n, idx;
	while(1){
		scanf("%d", &n);
		if(n == 0)
			break;
		for(i=1; i<=n; i++){
			scanf("%d", &a[i]);
			b[i] = 0;
			c[i] = 0;
		}

//		memset(b, 0, sizeof(b));
		S.top = -1;
		min_big(n, -1);
//		memset(c, 0, sizeof(c));
		S.top = -1;
		min_bigeq(n, -1);

/*		for(i=1; i<=n; i++){
			printf("%d ", b[i]);
		}
		printf("\n");
		for(i=1; i<=n; i++){
			printf("%d ", c[i]);
		}
		printf("\n");
*/
		long long total = 0;//(n-1/2)*(n-2);
		for(i=1; i<=n; i++){
			idx = i-1;
			total+=idx;
			while(idx >= b[i] && idx > 0){
				total--;
				idx = c[idx];
			}
		}
		printf("%lld\n", total);
	}
	return 0;
}
