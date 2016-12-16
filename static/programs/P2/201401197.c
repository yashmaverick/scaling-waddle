#include<stdio.h>
#include<stdlib.h>
int main(){
	int t,p,q,r,i,j,k,*ar1,*ar2,*ar3;
	long long ans,*greats;
	scanf("%d",&t);
	while(t>0){
		ans=0;
		scanf("%d",&p);
		ar1=(int *)malloc(sizeof(int)*p);
		for(i=0;i<p;i++){
			scanf("%d",ar1+i);
		}
		scanf("%d",&q);
		ar2=(int *)malloc(sizeof(int)*q);
		for(i=0;i<q;i++){
			scanf("%d",ar2+i);
		}
		scanf("%d",&r);
		ar3=(int *)malloc(sizeof(int)*r);
		for(i=0;i<r;i++){
			scanf("%d",ar3+i);
		}
		greats=(long long *)malloc(sizeof(long long)*q);
		i=p-1;
		if(p>q){
			i=q-1;
		}
		for(j=q-1;j>=0;j--){
			while((ar2[j]<ar1[i]||j<i)&&i>=0){
				i--;
			}
			greats[j]=i+1;
		}
		for(i=0;i<q;i++){
			greats[i]+=ans;
			ans=greats[i];
		}
		i=q-1;
		if(q>r){
			i=r-1;
		}
		for(j=r-1,ans=0;j>=0;j--){
			while((ar3[j]<ar2[i]||j<i)&&i>=0){
				i--;
			}
			if(i<0){
				break;
			}
			ans+=greats[i];
		}
		free(ar1);
		free(ar2);
		free(ar3);
		printf("%lld\n",ans);
		t--;
	}
	return 0;
}
