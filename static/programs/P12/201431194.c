#include<stdio.h>
int main(){
	long long int n;
	scanf("%lld",&n);
	while(n!=0)
	{
		long long int max1,max2,ans,i,j,k,l,m,a[500010],b[500010],s[2][500010];
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		ans=0;
		max1=a[0];
		max2=a[n-1];
		for(i=1;i<n;i++){
			if(a[i]>=max1)
				max1=a[i];
			else
				ans++;
			if(a[n-i-1]>=max2)
				max2=a[n-i-1];
			else
				ans++;
		}
		s[0][0]=a[0];
		s[1][0]=1;
		l=0;
		for(i=1;i<n;i++){
			if(a[i]==s[0][l]){
				ans=ans+s[1][l];
				s[1][l]++;
			}
			else if(a[i]<s[0][l]){
				l++;
				s[0][l]=a[i];
				s[1][l]=1;
			}
			else{
				while(a[i]>s[0][l])
					l--;
				if(l==0){
					if(a[i]==s[0][l]){
						ans=ans+s[1][l];
						s[1][l]++;
					}
					else{
						l++;
						s[0][l]=a[i];
						s[1][l]=1;
					}
				}
				else{
					if(a[i]==s[0][l]){
						ans=ans+s[1][l];
						s[1][l]++;
					}
					else{
						l++;
						s[0][l]=a[i];
						s[1][l]=1;
					}
				}
			}
		}
		ans = (n*(n-1))/2-ans;
		printf("%lld\n",ans);
		scanf("%lld",&n);
	}
	return 0;
}
