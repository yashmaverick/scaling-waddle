//Circular Buffer
#define loop(i,n) for(i=0;i<n;i++)
#define loop1(a,b) for(j=a;j<b;j++)
#define si(n) scanf("%d",&n)
#define ci(d) scanf("%c",&d)
#define cout(m) printf("%d\n",m)
#include<stdio.h>
int main(){
	int N,n;
	int i,j,empty=1;
	char cbuffer[10001][101];
	char option;
	si(N);
	int start=0,last=-1,flag=0;
	while(1){
		ci(option);
		if(option=='Q')
			return 0;
		else if(option=='A'){
			si(n);
			empty=0;
			loop(i,n){
				last=(last+1)%N;
				if(last==N-1)
					flag=1;
				scanf("%s",cbuffer[last]);
				if(flag && last==start)
					start=(start+1)%N;
			}
			//printf("s:%d l:%d\n",start,last);
		}
		else if(option=='L'){
			if(empty==0)
			{
				if(start<=last){
					loop1(start,last+1){
						printf("%s\n",cbuffer[j]);
					}
				}
				else{
					loop1(start,N){
						printf("%s\n",cbuffer[j]);
					}
					loop(i,last+1){
						printf("%s\n",cbuffer[i]);
					}
				}
			}
		}
		else if(option=='R'){
			si(n);
			if(n!=0)
			{
				if(last>=start){
					start+=n;
					start%=N;
				}
				else{
					if(n<N-start){
						start+=n;
						start%=N;
					}
					else{
						start=n-(N-start);
					}
				}
				//printf("s:%d l:%d\An",start,last);
				if(start==(last+1)%N){
					start=0;
					last=-1;
					empty=1;
					flag=0;
				}
			}
			//printf("s:%d l:%d\n",start,last);
		}
	}
}
