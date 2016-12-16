#include<stdio.h>
int a[1000000],b[1000000];
int main(){
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	int t;
	scanf("%d",&t);
	int f=0,p,q,x,y,temp;
	while(t--){
		scanf("%d%d",&p,&q);
		for(i=0;i<n;i++){
			if(b[i]==p){
				x=i;
				f++;
			}
			if(b[i]==q){
				y=i;
				f++;
			}
		}
		if(x>y){
			temp=x;
			x=y;
			y=temp;
		}
		int min=n-1,j;
		for(i=x;i<=y;i++){
			for(j=0;j<n;j++){
				if(b[i]==a[j]){
					if(j<min){
						min=j; 
					}
				}
			}
		}
		printf("%d\n",a[min]);
	}
	return 0;
}



