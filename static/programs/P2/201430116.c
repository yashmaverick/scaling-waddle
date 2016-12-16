#include<stdio.h>
int main(){
	int tc,sw;
	scanf("%d",&tc);
	for(sw=0;sw<tc;sw++){
	long long int i,j,k;
	long long int na;
	scanf("%lld",&na);
	long long int a[na+1];
	for(i=0;i<na;i++)
		scanf("%lld",&a[i]);
	long long int nb;
	scanf("%lld",&nb);
	long long int b[nb+1];
	for(i=0;i<nb;i++)
		scanf("%lld",&b[i]);
	long long int nc;
	scanf("%lld",&nc);
	long long int c[nc+1];
	for(i=0;i<nc;i++)
		scanf("%lld",&c[i]);
	long long int t1[nb+1],l,u,mid,total=0;
	for(i=0;i<nb;i++){
		t1[i]=0;
		for(l=i,u=nc-1;l<=u;){
			if(c[l]>=b[i]){
				t1[i]=nc-l;
				break;
			}
			mid=(l+u)/2;
			if(c[mid]==b[i]){
	/* i, mid*/			t1[i]=nc-mid;
				break;
			}
			else if(c[mid]<b[i]){
				if(c[mid+1]>b[i]){
					t1[i]=nc-1-mid;
					break;
				}
				else
					l=mid+1;
			}
			else{
				u=mid-1;
			}
		}
		total+=t1[i];
	}
	long long int t1_new[nb+1];
	t1_new[0]=total;
	for(i=1;i<nb;i++)
        t1_new[i]=t1_new[i-1]-t1[i-1];
  //  for(i=0;i<nb;i++)printf("%d ",t1[i]);
    //	printf("\n");
    long long int t2[na+1];
    for(i=0;i<na;i++){
        t2[i]=-1;
    	for(l=i,u=nb-1;l<=u;){
			if(b[l]>=a[i]){
				t2[i]=l;
				break;
			}
			mid=(l+u)/2;
			if(b[mid]==a[i]){
				t2[i]=mid;
				break;
			}
			else if(b[mid]<a[i]){
				if(b[mid+1]>a[i]){
					t2[i]=mid+1;
					break;
				}
				else
					l=mid+1;
			}
			else{
				u=mid-1;
			}
		}
    }
    long long int ans=0;
    for(i=0;i<na&&t2[i]>=0;i++){
    	k=t2[i];
    	ans+=t1_new[k];
    }
    printf("%lld\n",ans);
    }
	return 0;
}