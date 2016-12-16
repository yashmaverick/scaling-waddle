#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int i,j,n,k,start;
		scanf("%d%d",&n,&k);
		int a[n];
		int s[n];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		s[0]=a[0];
		start=0;
		for(i=1;i<n;i++){
			s[i]=a[i];
			if(i>=k)
				start++;
			for(j=i-1;j>=start;j--){
				if(s[j]>s[i])
					s[j]=s[i];
				else
					break;
			}
		}

		for(i=0;i<n-k;i++)
			printf("%d ",s[i]);
		printf("%d\n",s[i]);
	}
	return 0;
}
