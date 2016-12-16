#include<stdio.h>
int main(){
	int sw,z;
	scanf("%d",&sw);
	for(z=0;z<sw;z++){
	int q;
	scanf("%d",&q);
	int depth,j,comp;
	long long int ans=0;
	j=q;
	for(depth=0;j>0;depth++){
		j=j/2;
	}
	comp=3;
	depth=depth-1;
	j=depth;
	j=j-1;
	if(j>=0){
	while(j--)
		comp=comp*2;
    }
	if(q>=comp)
		ans=2*depth;
	else
		ans=2*depth-1;
	if(ans<0)
		ans=0;
	printf("%lld\n",ans);
    }
	return 0;
}