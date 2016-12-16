#include<stdio.h>
#include<stdlib.h>

struct bag{
	unsigned totwei,sz,*ar;
};

void custsort(struct bag *,int,int);
int main(){
	int n,m,w,i,j,k;
	unsigned MOD;
	struct bag *mar;
	scanf("%d %u",&n,&MOD);
	mar=(struct bag *)malloc(sizeof(struct bag)*n);
	for(i=0;i<n;i++){
		scanf("%u",&(mar[i].sz));
		mar[i].ar=(unsigned *)malloc(sizeof(unsigned)*mar[i].sz);
		for(j=0,mar[i].totwei=0;j<mar[i].sz;j++){
			scanf("%u",mar[i].ar+j);
			mar[i].totwei=(mar[i].totwei+mar[i].ar[j])%MOD;
		}
	}
	custsort(mar,0,n-1);
	for(i=0;i<n;i++){
		printf("%u\n",mar[i].totwei);
		for(j=0;j<mar[i].sz;j++){
			printf("%u\n",mar[i].ar[j]);
		}
		printf("\n");
	}
	return 0;
}

void custsort(struct bag *ar,int start,int stop){
	if(start>=stop){
		return ;
	}
	struct bag *temp;
	int mid,a,b,k;
	mid=(start+stop)>>1;
	custsort(ar,start,mid);
	custsort(ar,mid+1,stop);
	temp=(struct bag *)malloc(sizeof(struct bag)*(stop-start+1));
	a=start;b=mid+1;k=0;
	while(a<=mid&&b<=stop){
		if(ar[a].totwei<=ar[b].totwei){
			temp[k]=ar[a];
			a++;
		}
		else{
			temp[k]=ar[b];
			b++;
		}
		k++;
	}
	while(a<=mid){
		temp[k]=ar[a];
		a++;
		k++;
	}
	while(b<=stop){
		temp[k]=ar[b];
		b++;
		k++;
	}
	k--;
	while(k>=0){
		ar[start+k]=temp[k];
		k--;
	}
	free(temp);
}
