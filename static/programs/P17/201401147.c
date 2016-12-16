#include<stdio.h>
#include<stdlib.h>
long long int N;
long long int find(long long int v,long long int *a){
	long long int i;
	for(i=0;i<N;i++)
		if(a[i]==v)
			return i;
}
int main(){
	long long int i,j;
	long long int pre[100005];
	long long int in[100005];
	scanf("%lld",&N);
	for(i=0;i<N;i++)
		scanf("%lld",&pre[i]);
	for(i=0;i<N;i++)
		scanf("%lld",&in[i]);
	long long int t,flag,k,in1,in2,a,b,pre1,x,y;
	scanf("%lld",&t);
	for(k=0;k<t;k++){
		flag=0;
		x,y;
		scanf("%lld%lld",&x,&y);
		in1=find(x,in);
		in2=find(y,in);
		a=(in1>in2)?in2:in1;//a=min
		b=(in1<in2)?in2:in1;//b=max
		in1=find(x,pre);
		in2=find(y,pre);	
		pre1=(in1>in2)?in2:in1;//a=min
		for(i=0;i<=pre1;i++){
			for(j=a;j<=b;j++){
				if(pre[i]==in[j]){
					flag=1;
					printf("%lld\n",pre[i]);
					break;
				}
			}
			if(flag==1)
				break;
		}
	}
	return 0;
}
