#include<stdio.h>
int main(){
	int a[100000];
	int cs,cp,mp=0;
	int i,n,t;
	scanf("%d",&t);
	while(t--){
		mp=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	cs=a[0];
	for(i=1;i<n;i++){
		if(a[i]<cs)
			cs=a[i];
		else if(a[i]>cs){
			cp=a[i]-cs;
			if(cp>mp){
				mp=cp;
			}
		}
	}
	printf("%d\n",mp);
	}
	return 0;
}
