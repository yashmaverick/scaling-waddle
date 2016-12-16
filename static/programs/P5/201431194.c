#include<stdio.h>
void merge(int* a,int* b,int s,int e){
	int i,j,k,l,n,m;
	if(s==e)
		return ;
	merge(a,b,s,(s+e)/2);
	merge(a,b,(((s+e)/2)+1),e);
	i=s;
	j=((s+e)/2)+1;
	n=s;
	while(i<=(s+e)/2 || j<=e){
		if(a[i]<=a[j] && i<=(s+e)/2){
			b[n]=a[i];
			i++;
			n++;
		}
		else{
			if(a[i]>=a[j] && j<=e){
				b[n]=a[j];
				j++;
				n++;
			}
			else{
				if(i>(s+e)/2){
					while(j<=e){
						b[n]=a[j];
						j++;
						n++;
					}
				}
				else{
					while(i<=(s+e)/2){
						b[n]=a[i];
						i++;
						n++;
					}
				}
			}
		}
	}
	for(i=s;i<=e;i++)
		a[i]=b[i];
	return ;
}
int main(){
	int p,r,i,j,k,l,n,m,t,a[1000],o,b[1000];
	char v[1000];
	scanf("%d",&t);
	while(t--){
		int flag=0;
		scanf("%d%d",&n,&o);
		for(i=0;i<n;i++){
			scanf("%s",v);
			scanf("%d",&a[i]);
		}
		merge(a,b,0,n-1);
/*		for(i=0;i<n;i++)
			printf("%d ",a[i]);*/
		for(i=0;i<n-2;i++){
			p=i+1;
			r=n-1;
			while(p<r){
				if((a[i]+a[p]+a[r])==o){
					flag=1;
					break;
				}
				else if((a[i]+a[p]+a[r])<o)
					p++;
				else
					r--;
			}
			if(flag==1)
				break;
		}
		if(flag==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
