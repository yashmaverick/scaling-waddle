#include<stdio.h>
#include<stdlib.h>

#define mod 1000000007

long long int minheap[200005]={0};
long long int maxheap[200005]={0};
long long int f[200005]={0};
long long int last;

long long int tmin=1,tmax=1;

void show(long long int heap[],long long int size){
	printf("show\n");
	long long int i;
	for(i=1;i<size;i++){
		printf("  i=%lld heap[i]=%lld\n",i,heap[i]);
	}
	printf("end\n");
	return;
}
void swapmin(long long int e,long long int f){
	long long int g;
	g=minheap[e];
	minheap[e]=minheap[f];
	minheap[f]=g;
	return;
}
void swapmax(long long int e,long long int f){
	long long int g;
	g=maxheap[e];
	maxheap[e]=maxheap[f];
	maxheap[f]=g;
	return;
}
void insertmin(long long int x){
	//printf("t=%lld x=%lld\n",t,x);
	long long int l=tmin,c;
	minheap[l]=x;
	while(minheap[l]<minheap[l/2]){
		swapmin(l,l/2);
		l=l/2;
	}
	tmin++;
	//show();
	return;
}

void insertmax(long long int x){
	//printf("t=%lld x=%lld\n",t,x);
	long long int l=tmax,c;
	maxheap[l]=x;
	while(maxheap[l]>maxheap[l/2] && l!=1){
		swapmax(l,l/2);
		l=l/2;
	}
	tmax++;
	//show();
	return;
}
void delmin(){
//	last=minheap[1];
	minheap[1]=minheap[--tmin];
	//printf("last min=%lld\n",last);
	long long int c=1,fl;
	while(2*c+1<=tmin&&(minheap[c]>minheap[2*c]||minheap[c]>minheap[2*c+1])){
		//	for(long long int i=1;i<t;i++)
		//		cout<<endl<<i<<" "<<a[i];
		//	cout<<"\ndone\n";
		fl=0;
		if(minheap[2*c]<minheap[2*c+1])
			fl=1;
		if(fl==1){
			swapmin(c,2*c);
			c=2*c;
		}
		else{
			swapmin(c,2*c+1);
			c=2*c+1;	
		}

	}
	return;
	//show();
}
void delmax(){
//	last=maxheap[1];
	maxheap[1]=maxheap[--tmax];
	//printf("last max=%lld\n",last);
	long long int c=1,fl;
	while(2*c+1<=tmax&&(maxheap[c]<maxheap[2*c]||maxheap[c]<maxheap[2*c+1])){
		//	for(long long int i=1;i<t;i++)
		//		cout<<endl<<i<<" "<<a[i];
		//	cout<<"\ndone\n";
		fl=0;
		if(maxheap[2*c]>maxheap[2*c+1])
			fl=1;
		if(fl==1){
			swapmax(c,2*c);
			c=2*c;
		}
		else{
			swapmax(c,2*c+1);
			c=2*c+1;	
		}

	}
	return;
	//show();
}
int main(){
	/*long long int x;
	  scanf("%lld",&x);
	  while(x!=-1){
	  insertmax(x);
	  show(maxheap,tmax);
	  scanf("%lld",&x);
	  }
	  long long int p=tmax-1;
	  while(p--){
	  delmax(maxheap[1]);
	  show(maxheap,tmax);
	  }*/
	long long int t;
	long long int sum=0;
	scanf("%lld",&t);
	while(t--){
		long long int i,j=2;/*
		for(i=0;i<200005;i++)
			maxheap[i]=1000000;*/
		f[1]=1;
		long long int a,b,c,n,med=1;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		insertmax(1);
		med=maxheap[1];
		long long int fl=1;
		long long int u=n--;
		while(u--){
		//	printf("tmax = %lld tmin = %lld f[%lld] = %lld ",tmax,tmin,j-1,f[j-1]);
		//	printf("j-1 = %lld med = %lld\n\n",j-1,med);
			if(fl==0){
		//		printf("entered fl\n");
				if(f[j-1]>=med){
					insertmin(f[j-1]);
		//			printf("inserted in if\n");
				}
				else{
					insertmax(f[j-1]);
		//			printf("inserted in else\n");
				}
			}
		//	printf("tmax = %lld tmin = %lld f[%lld] = %lld ",tmax,tmin,j-1,f[j-1]);
		//	printf("med = %lld\n\n",med);
			sum=(sum+f[j-1]);
			if(tmax==tmin){		//	if sizes are equal
				med=maxheap[1];
			}
			else if(tmax-tmin==1){	//	if maxheap is one or more than one than minheap
				med=maxheap[1];
			}
			else if(tmax-tmin>=2){	//	if maxheap is two or more than two than minheap
				insertmin(maxheap[1]);
				delmax();
				med=maxheap[1];
			}
			else if(tmin-tmax>=1){	//	if minheap is one or more than one than maxheap
				insertmax(minheap[1]);
				delmin();
				med=maxheap[1];
			}
		//	printf("med=%lld\n\n",med);
			fl=0;
			f[j]=(((a*med)%mod+(b*j)%mod)%mod+c%mod)%mod;	
			j++;
			//show(minheap,tmin);
			//show(maxheap,tmax);
		}
		printf("%lld\n",sum);
		for(i=0;i<200005;i++){
			minheap[i]=0;
			maxheap[i]=0;
			f[i]=0;
		}
		sum=0;
		med=1;
		tmin=1;
		tmax=1;
	}
	return 0;
}
