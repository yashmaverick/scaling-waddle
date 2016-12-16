#include<stdio.h>
int main(){
	long long int ans,i,j,k,l,n,m,arr[100000],max1,max2,stc[2][100000];
	scanf("%lld",&n);
	while(n!=0){
		ans=0;
		for(i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		stc[0][0] = arr[0];
		stc[1][0] = 1;
		l = 0;
		max1=arr[0];
		max2=arr[n-1];
		for(i=1;i<n;i++){
			if(arr[i]<max1)
				ans++;
			else
				max1 = arr[i];
			if(arr[n-i-1]<max2)
				ans++;
			else
				max2 = arr[n-i-1];
			while(arr[i] > stc[0][l] && l>0)
				l--;
			if(l==0){
				if(arr[i] < stc[0][0]){
					l++;
					stc[0][l]=arr[i];
					stc[1][l]=1;
				}
				else if(arr[i]==stc[0][0]){
					ans = ans+stc[1][l];
					stc[1][l]++;
				}
				else{
					stc[0][0] = arr[i];
					stc[1][0] = 1;
				}
			}
			else{
				if(arr[i]==stc[0][l]){
					ans = ans+stc[1][l];
					stc[1][l]++;
				}
				else{
					l++;
					stc[0][l]=arr[i];
					stc[1][l]=1;
				}
			}
		}
		printf("%lld\n",n*(n-1)/2-ans);
		scanf("%lld",&n);
	}
	return 0;
}
