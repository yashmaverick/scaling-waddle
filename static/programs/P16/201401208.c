#include<stdio.h>
#include<math.h>
int l_or_r(long long int val,long long int level);
int main(){
	int t,n,k,i,fl;
	long long int q,ans,res;
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&q);
		ans=log2(q);
		fl=l_or_r(q,ans);
		if(fl==0)
			res=(2*ans)-1;
		else
			res=2*ans;
		printf("%lld\n",res);
	}
	return 0;
}

int l_or_r(long long int val,long long int level){
	int fl;
	long long int start,mid;
	start=pow(2,level);
	if(val==2)
		return 0;
	else if(val==3)
		return 1;
	else{
		if(val < (start+(start/2)))
			return 0;
		else return 1;
	}

}

