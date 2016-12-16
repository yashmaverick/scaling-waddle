#include<stdio.h>
int main()
{
	int t,n,min_val,diff,ans,i;
	int p[100005];

	scanf("%d",&t);
	while(t--){
		diff=0;
		ans=0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&p[i]);
		}
		min_val=p[0];
		for(i=0;i<n;i++){
			if(p[i]<min_val){
				min_val=p[i];
			}

			diff=p[i]-min_val;
			if(diff>ans){
				ans=diff;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}



