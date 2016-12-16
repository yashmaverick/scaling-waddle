#include <stdio.h>
#include <string.h>
#define ll long long

#define MAX 100003

void print_arr(int A[], int len){
	int i;
	for(i=0; i<len; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
}

long long generate(int x, int y){
	return (MAX*x+y);
}

int compare(const void *a, const void *b){
	return *((long long int *)a) - *((long long int *)b);
}

int main(){
	ll res[MAX];
	char str[MAX];
	int len, T, i;
	scanf("%d", &T);
	while(T--){
		scanf("%s", str);
		len = strlen(str);
		if(str[0]=='J'){
			res[0] = MAX;
		}
		if(str[0]=='R'){
			res[0] = 1;
		}
		if(str[0]=='M'){
			res[0] = -MAX-1;
		}
		for(i=1; i<len; i++){
			res[i] = res[i-1];
			if(str[i]=='J'){
				res[i] +=  MAX;
			}
			if(str[i]=='R')
				res[i] += 1;
			if(str[i]=='M')
				res[i] += -MAX-1;
		}
		qsort(res, len, sizeof(long long), compare);
		for(i=0; i<len; i++){
			//printf("%d ", res[i]);
		}
		ll curr, count;
		ll sum=0;
		curr=res[0];
		count=1;
		for(i=1; i<len; i++){
			if(res[i]!=curr){
				//printf("%d %d %d\n", count, res[i], curr);
				sum += (count)*(count-1)/2;
				if(curr==0) sum += count;
				curr = res[i];
				count = 0;
			}
			count += 1;
		}
		sum += (count)*(count-1)/2;
		if(curr==0) sum += count;
		printf("%lld\n", sum);
	}
	return 0;
}
