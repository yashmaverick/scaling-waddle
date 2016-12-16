#include<stdio.h>

int i=0,j=1;
void maxi(int n){
	j=1;
	for(i=0;i<=30;i++){
		if(j>n)
			break;
		j=j*2;
	}
	return;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t){
		t--;
		int n,maxd=0;
		scanf("%d",&n);
		maxi(n);
		if(n>(j/2+j/4-1))
			printf("%d\n",2*(i-1));
		else
			printf("%d\n",2*(i-1)-1);
	}
	return 0;
}
