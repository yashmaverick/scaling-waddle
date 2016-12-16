#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int wgt;
	int num;
	int* ele;
}node;
int main(){
	int size,mod,i,j,nu;
	scanf("%d%d",&size,&mod);
	node a[size];
		node temp;
	for(i=0;i<size;i++){
		scanf("%d",&a[i].num);
		a[i].ele=malloc(sizeof(int)*a[i].num);
		a[i].wgt=0;
		for(j=0;j<a[i].num;j++){
			scanf("%d",&a[i].ele[j]);
			a[i].wgt=((a[i].wgt)%mod+(a[i].ele[j])%mod)%mod;
		}
		a[i].wgt=a[i].wgt%mod;
	}
	for(i=0;i<size-1;i++){
		for(j=i+1;j<size;j++){
			if(a[i].wgt>a[j].wgt){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	for(i=0;i<size;i++){
		printf("%d\n",a[i].wgt);
		for(j=0;j<a[i].num;j++){
			printf("%d\n",a[i].ele[j]);
		}
		printf("\n");
	}
	return 0;
}
