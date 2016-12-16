#include <stdio.h>
#include <math.h>
#define rep(i,n) for(i=0;i<n;i++)
#define MAXN 10001
#define MAXLOGN 101
int M[MAXN][MAXLOGN],input[MAXN];
void in(int *address){
	scanf("%d",address);
}
void out(int value){
	printf("%d ",value);
}
void newl(){
	printf("\n");
}
void solver(int input[],int N){
	int i,j;
	rep(i,N)
		M[i][0]=i;
	for(j=1;1<<j <=N ;j++){
		for(i=0;i+(1<<(j-1))<N;i++){
			if(input[M[i][j-1]]<=input[M[i+(1<<(j-1))][j-1]])
				M[i][j]=M[i][j-1];
			else
				M[i][j]=M[i+(1<<(j-1))][j-1];
		}
	}
}
int printans(int input[],int start,int end){
	int k=end-start;
	k = log(end-start+1)/log(2);
	if(input[M[start][k]]<=input[M[end-(1<<k)+1][k]]) return input[M[start][k]];
	else return input[M[end-(1<<k)+1][k]];
}
int main(){
	int t,j;
	in(&t);
	rep(j,t)
	{
		int n,k,ii;
		in(&n);
		in(&k);
		rep(ii,n) in(&input[ii]);
		solver(input,n);
		rep(ii,n-k) out((printans(input,ii,ii+k-1)));
		printf("%d",printans(input,n-k,n-1));
		newl();
	}
	return 0;
}
