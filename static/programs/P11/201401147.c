#include<stdio.h>
long long int stack[100000];
long long int pointer=-1;
void push(long long int value)
{
	stack[++pointer]=value;
	return ;
}
void pop(){
	pointer--;
	return ;
}
long long int stacktop(){
	return stack[pointer];
}
void printstack(){
	long long int i;
	for(i=pointer;i>=0;i--)
		printf("%lld\t",stack[i]);
	printf("\n");
	return ;
}
long long int empty()
{
	if(pointer >= 0)
		return -1;
	return 1;
}
int main()
{
	while(1){
		long long int N,bars[100000];
		scanf("%lld",&N);
		if(N==0)
			break;
		long long int i;
		long long int presentarea=0,maxarea=0;
		for(i=0;i<N;i++){
			scanf("%lld",&bars[i]);
		}i=0;
		while(i<N){
			if( empty() > 0 || bars[i] > bars[stacktop()])
				push(i++);
			else{
				long long int top=stacktop();
				pop();
				presentarea=bars[top]*((empty() > 0)?i:i-stacktop()-1);
				//			printf("present area is %lld\n",presentarea);
				if(presentarea > maxarea)
					maxarea=presentarea;
			}
		}
		while(empty()!=1){
			long long int top=stacktop();
			pop();
			presentarea=bars[top]*((empty() > 0)?i:i-stacktop()-1);
			//		printf("present area is %lld\n",presentarea);
			if(presentarea > maxarea)
				maxarea=presentarea;

		}
		printf("%lld\n",maxarea);
		pointer=-1;
	}
	return 0;
}
