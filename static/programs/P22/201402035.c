#include<stdio.h>
long long int n_min,n_max;
void swap(long long int *a,long long int *b){
	long long int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}

void insert_max(long long int max[],long long int x){
	long long int tmp,l;
	n_max+=1;
	max[n_max]=x;
	l=n_max;
	while( l/2>=1 && max[l/2]<max[l])
	{
		swap(&max[l/2],&max[l]);
		l=l/2;
	}
}
void insert_min(long long int min[],long long int x){
	long long int tmp,l;
	n_min+=1;
	min[n_min]=x;
	l=n_min;
	while((l/2>=1) && (min[l/2]>min[l]))
	{
		swap(&min[l/2],&min[l]);
		l=l/2;
	}
}
long long int delete_min(long long int min[]){
	long long int k,l,m,root;
	root=min[1];
	min[1]=min[n_min];
	n_min--;
	k=1;
	while((min[k]>min[2*k] || min[k]>min[2*k+1]) && (2*k<=n_min)){
		if((min[k]>min[2*k]) && min[2*k]<=min[2*k+1]){
			swap(&min[2*k],&min[k]);
			k=k*2;
		}
		else{
			swap(&min[k],&min[2*k+1]);
			k=2*k+1;
		}
	}
	return root;
}

long long int delete_max(long long int max[]){
	long long int k,l,m,root;
	root=max[1];
	max[1]=max[n_max];
	n_max--;
	k=1;
	while((max[k]<max[2*k]) || (max[k]<max[2*k+1]) && (2*k<=n_max)){
		if((max[k]<max[2*k]) && max[2*k]>=max[2*k+1]){
			swap(&max[k],&max[2*k]);
			k=2*k;
		}
		else{
			swap(&max[k],&max[2*k+1]);
			k=2*k+1;
		}
	}
	return root;
}

int main(){
	long long int t;
		long long int max[200005];
		long long int min[200005];
	long long int sum;
	scanf("%lld",&t);
	while(t--){
		long long int i,a,b,c,n;
		n_max=0;
		n_min=0;
		insert_max(max,1);
		long long int mid;
		mid=1;
		sum=1;
		//		printf("test case number->%lld\n",t);
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		//		printf("%lld %lld %lld %lld\n",a,b,c,n);
		for(i=2;i<=n;i++){
			//prlong long intf("vinay\n");
			long long int x;
			long long int y;
			x=((a*mid)%1000000007 + (b*i)%1000000007+c%1000000007)%1000000007;

			//prlong long intf("counter i=(%d)\n",i);
			//				printf("mid=(%lld) @ (%lld)and x=(%lld)\n",mid,i,x);
			sum=(sum+x);
			if(x<=mid)
				insert_max(max,x);
			else{
				insert_min(min,x);
			}
			if(n_min>n_max){
				y=delete_min(min);
				insert_max(max,y);
			}

			if(n_max-n_min > 1){
				y=delete_max(max);
				insert_min(min,y);
			}
			mid=max[1];
			//			prlong long intf("our mid->%d",mid);
			//		prlong long intf("(%d)ith time->%d\n",i,sum);

		}
		printf("%lld\n",sum);
		for(i=1;i<=n;i++){
		max[i]=0;
		min[i]=0;
		}
	
	
	}
	return 0;
}
