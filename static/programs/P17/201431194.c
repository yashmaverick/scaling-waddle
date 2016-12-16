#include<stdio.h>
int main(){
	int val,t,x,y,i,j,k,l,n,m,a[100000],b[100000],c[100000];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		a[x] = i;
	}
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
		c[b[i]] = i;
	}
//	for(i=0;i<10;i++)
//		printf("%d %d %d\n",a[i],b[i],c[i]);
	scanf("%d",&t);
	for(i=0;i<t;i++){
		int min=100000000;
		scanf("%d%d",&x,&y);
//		printf("%d %d\n",c[x],c[y]);
		if(c[x] < c[y]){
			for(j=c[x];j<=c[y];j++)
				if(a[b[j]] < min){
					min = a[b[j]];
					val = b[j];
				}
		}
		else{
			for(j=c[y];j<=c[x];j++)
				if(a[b[j]]<min){
					min = a[b[j]];
					val = b[j];
				}
		}
		printf("%d\n",val);
	}
	return 0;
}
