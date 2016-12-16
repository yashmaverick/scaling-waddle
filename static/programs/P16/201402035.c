#include<stdio.h>
int main(){
	int n,q,i;
	int k,x,y,z;
	int ans;
	scanf("%d",&n);
	while(n--){
		y=1;
		x=0;
		z=1;
		scanf("%d",&q);
		if(q==1)
			ans=0;
		else{
		k=q;
		while(k!=1){
			k=k/2;
			x++;
		}
		for(i=0;i<x;i++){
			y=y*2;
		}
		for(i=0;i<x-1;i++){
			z=z*2;
		}
		if(q>y+z-1)
			ans=2*x;
		else
			ans=2*x-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
