#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int test;
	scanf("%d", &test);
	while(test--){
		int n, count, a;
		count=0;
		scanf("%d", &n);
		a=n;
		while(n>1){
			n=n>>1;
			count++;
		}
		n=1<<count;
		n=n|(n/2);
		if(a>=n)
			printf("%d\n",2*count);
		else
			printf("%d\n",2*count-1 );
	}


return 0;
}
