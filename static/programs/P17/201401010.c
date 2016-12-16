#include<stdio.h>
#include<stdlib.h>
#define min(a,b) (a<b)?a:b
#define max(a,b) (a>b)?a:b

/*int binary(int a[],int init,int len,int num){
	int start=init;
	int end=len;
	int mid=(start+end)/2;
	while(start<=end){
		if(start==end && a[start]!=num)
			return -1;
		if(a[mid]==num)
			return mid;
		else if(a[mid]<num)
			start=mid;
		else
			end=mid;
		mid=(start+end)/2;
	}
}*/

int main(){
	int t,i,n,x,y,j,ans,k,flag=0;
	int idx,idy;
	scanf("%d",&n);
	int pre[100000],in[100000];
	for(i=0;i<n;i++){
		scanf("%d",&pre[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	scanf("%d",&t);
	for(i=0;i<t;i++){
		flag=0;
		scanf("%d%d",&x,&y);
		for(j=0;j<n;j++){
			if(in[j]==x){
				idx=j;
				break;
			}	
		}
		for(j=0;j<n;j++){
			if(in[j]==y){
				idy=j;
				break;
			}
		}
		int a=min(idx,idy);
		int b=max(idx,idy);
		for(j=0;j<n;j++){
			flag=0;
			for(k=a;k<=b;k++){
				if(pre[j]==in[k]){
					ans=pre[j];
					printf("%d\n",ans);
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
	}
	return 0;
}
