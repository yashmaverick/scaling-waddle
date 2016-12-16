#include<stdio.h>
int main(){
	int n,i,pre[100010],in[100010];
	scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%d",&pre[i]);	
	}
	for (i=0;i<n;i++){
		scanf("%d",&in[i]);	
	}
	int tc,j,f,a,b;
	scanf("%d",&tc);
	while(tc--){
		int state=1;
		scanf("%d %d",&a,&b);
		for (i=0;i<n;i++){
			if(in[i]==a){
				a=i;	
				break;
			}
		}
		for(j=0;j<n;j++){
			if(in[j]==b){
				b=j;
				break;
			}
		}
		if (a>b){
			int temp;
			temp=a;
			a=b;
			b=temp;
		}
		int ans;
		if(a==b){
			printf("%d\n",in[a]);
		}
		else{
			for (i=0;i<n;i++){
				for(j=a;j<=b;j++){
					if (pre[i]==in[j]){
						ans=pre[i];
						state=0;
						break;
					}
				}
			if(state==0)
				break;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
