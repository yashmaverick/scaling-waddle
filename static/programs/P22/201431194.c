#include<stdio.h>
void swap(long long int* x,long long int* y){
	long long int tmp = *x;
	*x = *y;
	*y = tmp;       
	return ;
}
long long int min[200001],mic=0;
long long int max[200001],mac=0;
void insertmin(long long int x){
	mic++;
	min[mic] = x;
	long long int tmp=mic;
	while(min[tmp/2] > min[tmp]){
		swap(&min[tmp/2],&min[tmp]);
		tmp = tmp/2;
	}
	return ;
}
void insertmax(long long int x){
	mac++;
	max[mac] = x;
	long long int tmp = mac;
	while(max[tmp/2] < max[tmp]){
		swap(&max[tmp/2],&max[tmp]);
		tmp = tmp/2;
	}
	return ;
}
void deletemax(){
	long long int tmp = 1;
	max[1] = max[mac];
	mac--;
	tmp = 1;
	while((max[tmp] < max[2*tmp] && 2*tmp<=mac) || (max[tmp] < max[2*tmp+1] && 2*tmp+1<=mac)){
		if(max[tmp] < max[2*tmp] && max[tmp] < max[2*tmp+1]){
			if((max[2*tmp] > max[2*tmp+1])){
				swap(&max[2*tmp],&max[tmp]);
				tmp = 2*tmp;
			}
			else{
				swap(&max[2*tmp+1],&max[tmp]);
				tmp = 2*tmp+1;
			}
		}
		else if(max[tmp] < max[2*tmp]){
			swap(&max[tmp],&max[2*tmp]);
			tmp = tmp*2;
		}
		else{
			swap(&max[tmp],&max[2*tmp+1]);
			tmp = 2*tmp+1;
		}
	}
	return ;
}
void deletemin(){
	min[1] = min[mic];
	mic--;
	long long int tmp = 1;
	while((min[tmp] > min[2*tmp] && 2*tmp<=mic) || (min[tmp] > min[2*tmp+1] && 2*tmp+1 <= mic)){
		if(min[tmp] > min[2*tmp] && min[tmp] > min[2*tmp+1]){
			if((min[2*tmp] < min[2*tmp+1])){
				swap(&min[tmp],&min[2*tmp]);
				tmp = 2*tmp;
			}
			else{
				swap(&min[tmp],&min[2*tmp+1]);
				tmp = 2*tmp+1;
			}
		}
		else if(min[tmp] > min[2*tmp]){
			swap(&min[tmp],&min[2*tmp]);
			tmp = 2*tmp;
		}
		else{
			swap(&min[tmp],&min[2*tmp+1]);
			tmp = 2*tmp+1;
		}
	}
	return ;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		mic=1;
		mac=0;
		max[0] = 100000000000;
		min[0] = -1;
		min[1] = 1;
		long long int a,b,c,x,i,j,k,l,n,m,mod=1000000007;
		long long int sum=1;
		scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
		for(i=1;i<n;i++){
			x = (a*min[1]+b*i+b+c)%mod;
			sum+=x;
			if((mic+mac)%2==1 || i==0 || i==1){
				if((x > max[1]) || i==1 || i==0)
					insertmin(x);
				else{
					insertmin(max[1]);
					deletemax();
					insertmax(x);
				}
			}
			else{
				if(x < min[1])
					insertmax(x);
				else{
					insertmax(min[1]);
					deletemin();
					insertmin(x);
				}
			}/*
			for(j=1;j<=mic;j++)
				printf("%d ",min[j]);
			printf("\n");
			for(j=1;j<=mac;j++)
				printf("%d ",max[j]);
			printf("\n");*/
		}
		printf("%lld\n",sum);
	}
	return 0;
}
