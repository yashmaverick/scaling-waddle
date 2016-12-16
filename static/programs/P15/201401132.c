#include<stdio.h>
int main(){
	int t,n,k,i,p,j,min,f,h,b[1000001];
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		int a[n];
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		p=-1,h=0;
		for(i=0;i<n-k+1;i++){
			f=0;
			if(p==h-1){
				p++;
				b[p]=i;
			}
			if(b[h]<i&&a[b[h]]>=a[i+k-1]){
				min=a[i+k-1];
				h++;
				b[h]=i+k-1;
				f=1;
			}
			else{	
				if(b[h]<i){
					h++;
					b[h]=i;
				}
				for(j=i;j<i+k-1&&i+k-1<n;j++){
					if(a[b[p]]<=a[j+1]||p==h-1){ 
						if(b[p]!=j+1){
							p++;
							b[p]=j+1;
						}

					}
					else
					{
						p--;
						j--;
					}
				}
			}
			if(f!=1){
				min=a[b[h]];
			}
			if(i<n-k){
				printf("%d ",min);
			}
			else{
				printf("%d\n",min);
			}

		}
	}
	return 0;
}
