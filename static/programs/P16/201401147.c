#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int N;
		scanf("%d",&N);
		int m=log2(N);
		if(N==1)
			printf("0\n");
		else if(N==2)
			printf("1\n");
		else{
			int k=pow(2,m);
			if(N >= k && N < (k+k/2))
				printf("%d\n",2*m-1);
			else
				printf("%d\n",2*m);
		}
	}
	return 0;
}
