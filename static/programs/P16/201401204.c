#include<stdio.h>
#include<math.h>
int main(){
	int i,n,a[34];
	scanf("%d",&n);
	while(n--){
		int q;
		scanf("%d",&q);
		a[0]=1;
		for(i=1;;i++){
			a[i]=a[i-1]*2;
			if(q<a[i])
				break;
		}
		//printf("i = %d\n",i);
		int av=(a[i-1]+a[i])/2;
		if(q>=av)
			printf("%d\n",2*(i-1));
		else if(q<av&&q>=a[i-1])
			printf("%d\n",2*i-3);
	}
	return 0;
}
