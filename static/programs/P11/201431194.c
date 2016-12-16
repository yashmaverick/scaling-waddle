#include<stdio.h>
int main(){
	//int o,i,j,k,l,n,m,a[100000],b[100000],s[100000],c[100000],d[100000];
	long long int n;
	scanf("%lld",&n);
	while(n!=0)
	{
		long long int o,i,j,k,l,m,a[n],b[n],s[n],c[n],d[n];
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		b[0] = -1;
		s[0] = 0;
		l=0;
		for(i=1;i<n;i++){
			if(a[i] > a[s[l]]){
				b[i] = s[l]; // b is for storing j
				l++;	     // s is for stack
				s[l] = i;
			}
			else{
				while(a[i] <= a[s[l]] && l>0){
					l--;
					//				printf("%d ",l);
				}
				//			printf("\n");
				if(l==0){
					if(a[i] > a[0]){
						b[i] = 0;
						l++;
						s[l] = i;
					}
					else{
						b[i] = -1;
						l++;
						s[l] = i;
					}
				}
				else{
					b[i] = s[l];
					l++;
					s[l] = i;
				}
			}
		}
		//	for(i=0;i<n;i++)
		//		printf("%d ",b[i]);
		//	printf("\n");
		for(i=0;i<n;i++)
			c[i] = a[n-i-1];
		d[0] = -1;
		s[0] = 0;
		l = 0;
		for(i=1;i<n;i++){
			if(c[i] > c[s[l]]){
				d[i] = s[l];
				l++;
				s[l] = i;
			}
			else{
				while(c[i] <= c[s[l]] && l>0)
					l--;
				if(l==0){
					if(c[i] > c[0]){
						d[i] = 0;
						l++;
						s[l] = i;
					}
					else{
						d[i] = -1;
						l++;
						s[l] = i;
					}
				}
				else{
					d[i] = s[l];
					l++;
					s[l] = i;
				}
			}
		}
		/*	for(i=0;i<n;i++)
			printf("%d ",c[i]);
			printf("\n");
			for(i=0;i<n;i++)
			printf("%d ",d[i]);
			printf("\n");*/
		long long int ans=0,sum=0;
		for(i=0;i<n;i++){
			sum = a[i]*(n-d[n-i-1]-1-b[i]-1);
			if(sum > ans)
				ans = sum;
			//	printf("%lld ",sum);
		}
		//	printf("\n");
		printf("%lld\n",ans);
		scanf("%lld",&n);
	}
	return 0;
}
