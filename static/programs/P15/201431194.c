#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int min,tmp,x,i,j,k,l,n,a[100000],b[100000],c[100000],s[100000];
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		b[n-1] = n;
		s[0] = n-1;
		l=0;
		for(i=n-2;i>=0;i--){
			if(a[i] >= a[s[l]]){
				b[i] = s[l]; // b is for storing j
				l++;         // s is for stack
				s[l] = i;
			}
			else{
				while(a[i] < a[s[l]] && l>0)
					l--;
				if(l==0){
					if(a[i] >= a[s[l]]){
						b[i] = s[l];
						l++;
						s[l] = i;
					}
					else{
						b[i] = n;
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
		for(i=0;i<n-k+1;i++){
			if(b[i]<=i+k-1){
				x=b[i];
				while(x<=i+k-1){
					tmp=x;
					x = b[x];
					if(x>i+k-1){
						if(i==n-k)
							printf("%d",a[tmp]);
						else
							printf("%d ",a[tmp]);
						break;
					}
				}
			}
			else
				if(i==n-k)
					printf("%d",a[i]);
				else
					printf("%d ",a[i]);
		}
		printf("\n");
	}
	return 0;
}
