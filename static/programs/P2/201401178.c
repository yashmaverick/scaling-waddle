#include<stdio.h>
int binarysearch(long long int c[], int lwr, int upr,long long int val){
	int flag=0,K,LOW;
	int mid;
	LOW=lwr;
	if(val>c[upr]){
		return -1;
	}
	while(lwr<=upr){
		mid=(lwr+upr)/2;
		if(val==c[mid]){
			flag=1;
			K =  mid;
			break;
		}
		if(val<c[mid]){
			upr=mid-1;
		}
		if(val>c[mid]){
			lwr=mid+1;
		}
	}
	if(flag==1)
	{
		while(c[K-1]==c[K] && K-1>=LOW)
			K--;
		return K;

	}	
	//if(val>c[upr]){
	//	return -1;
	if(flag==0)
		return lwr;
}
int main(){
	int test,i;
	scanf("%d",&test);
	for(i=0;i<test;i++){
		long long int a[100000],b[100000],c[100000],d[100001],ans=0,flag=0;
		int sizea,sizeb,sizec,n;
		scanf("%d",&sizea);
		for(n=0;n<sizea;n++)
			scanf("%lld",&a[n]);
		scanf("%d",&sizeb);
		for(n=0;n<sizeb;n++)
			scanf("%lld",&b[n]);
		scanf("%d",&sizec);
		for(n=0;n<sizec;n++)
			scanf("%lld",&c[n]);

		d[n+1]=0;
		int mid;
		for(n=sizeb-1;n>=0;n--){
			mid=binarysearch(c,n,sizec-1,b[n]);
	/*		if(mid==-1){
				flag=1;
			}*/
			if(mid!=-1){
				d[n]=d[n+1] + (sizec-mid);
			}
			else
				d[n]=d[n+1];
		}
		for(n=sizea-1;n>=0;n--){
			int mid=binarysearch(b,n,sizec-1,a[n]);
			if(mid==-1){
				flag=1;
			}
			if(flag==0){
				ans=ans+d[mid];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

