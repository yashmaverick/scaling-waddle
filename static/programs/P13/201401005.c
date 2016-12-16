#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <stdarg.h>
#include<assert.h>

int a[100001];
int b[100001];
int max=0;
int val=INT_MAX;
int n;

int s[100001];
int top=-1;
/*
void max_index_min(int n){
	int i, j;
	s[++top] = 0;
	b[0] = -1; 
	for(i=1; i<n; i++){
		if(a[i] > a[i-1]){
			s[++top] = i;
			b[i] = i-1;
		}   
		else if(a[i] < a[i-1]){
			j = i;
			while(a[i]<=a[s[top]] && j>=0){
				top--;
				j--;
			}
			s[++top] = i;
			b[i] = s[top-1];
		}   
	}   

		for(i=0; i<n; i++)
			printf("%d ", b[i]);
		printf("\n");
	//	return 0;

}
*/

void max_index_min(int n){
	int i;
	for(i=0;i<n;i++)
		b[i]=-1;
	
	s[++top] = 0;
	for(i=1; i<n; i++){
		while(top!=-1 && a[s[top]]>a[i])
			top--;
		if(top!=-1)
			b[i] = s[top];
		s[++top] = i;
	}
}

void dmax(int l, int r, int count)
{
	if(l > r)
		return;
	if(l == r)
	{
		if(count > max)
		{
			max = count;
			val = a[l];
		}
		if(count == max)
			if(a[l] < val)
				val = a[l];
		return ;
	}
	/*	if(r-l == 1){
		count += 1;
		if(count > max){
		max = count;
		if(b[r] < val)
		val = b[r];
		}
		return ;
		}*/
	int i = b[r];
	//	i = l;
	//	while(a[i] < a[r])
	//		i++;
	//	i = i-1;
	if(l<=i && i<=r)
	{
		dmax(l, i, count+1);
		dmax(i+1, r-1, count+1);
	}
	else
		dmax(l,r-1,count+1);
}

int main(){
	int i, count=0, t;
	scanf("%d", &t);
	while(t--){
		top = -1;
		max = 0;
		val=INT_MAX;
		scanf("%d", &n);
		for(i=0; i<n; i++)
			scanf("%d", &a[i]);
		//		for(i=0; i<n; i++)
		//			b[n-i-1] = a[i];
		max_index_min(n);
		dmax(0, n-1, 0);
		printf("%d %d\n", val, max);
	}
	return 0;
}
