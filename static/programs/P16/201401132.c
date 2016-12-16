#include<stdio.h>
#include<math.h>
int main(){
	int n,k,i,ans,t,d;
	float p;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n==1){
			printf("0\n");
		}
		else{
			i=0;
			p=n;
			while(p>1){
				d=pow(2,i);
				p=(n/d);
				i++;
			}
			k=i-1;
//			printf("%dk\n",k);
			if(n<(pow(2,k)+pow(2,k-1))){
				ans=2*k-1;
			}
			if(n>=(pow(2,k)+pow(2,k-1))){
				ans=2*k;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}


