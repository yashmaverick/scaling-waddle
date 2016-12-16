#include<stdio.h>
void pop();
void push(long long index);
long long top();
long long stack[100003];
long long pt;
int main(){
		long long N,hist[100003];
		long long i,saved;
		long long maxarea,area;
		scanf("%lld" ,&N);
		while(N!=0){
				hist[0]=-1;
				stack[0]=0;
				pt=0;
				maxarea=0;
				i=1;
				while(i<N+1){
						scanf("%lld" ,hist+i);
						i++;
				}
				// finding the areas
				i=1;
				while(i<N+1){
						if(top()==0 || hist[i]>=hist[top()]){
								push(i);
								i++;
						}
						else{
								saved=top();
								pop();
								if(top()==0)
										area=hist[saved]*(i-1);
								else
										area=hist[saved]*(i-top()-1);
								if(maxarea<area){
										maxarea=area;
								}
						}
				}
				while(top()!=0){
						saved=top();
						pop();
						if(top()==0)
								area=hist[saved]*(i-1);
						else
								area=hist[saved]*(i-top()-1);
						if(maxarea<area){
								maxarea=area;
						}

				}
				printf("%lld\n" ,maxarea);
				scanf("%lld" ,&N);
		}
		return 0;
}

void pop(){
		pt--;
		return;
}
void push(long long index){
		pt++;
		stack[pt]=index;
		return;
}
long long top(){
		return stack[pt];
}
