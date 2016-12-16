#include<stdio.h>
#include<stdlib.h>
typedef struct block{
	int sum;
	int n;
	int begin;
	int finish;
}block;

int main(){
	int i,j,n,mod,k,t,total,cp;
	block* head;
	scanf("%d%d",&n,&mod);
	head=(block*)malloc(n*sizeof(block));
	int a[1000000];
	for(cp=0,i=0;i<n;i++){
		head[i].begin=cp;
		scanf("%d",&head[i].n);
		j=head[i].n+cp;
		for(total=0;cp<j;cp++){
			scanf("%d",&a[cp]);
			total=(total%mod+a[cp]%mod)%mod;
		}
		head[i].sum=total;
		head[i].finish=cp;
	}

	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(head[i].sum>head[j].sum){
				block temp;
				temp=head[i];
				head[i]=head[j];
				head[j]=temp;
			}
		}
	}

	for(i=0;i<n;i++){
		printf("%d\n",head[i].sum);
		for(j=head[i].begin;j<head[i].finish;j++)
			printf("%d\n",a[j]);
		printf("\n");
	}

	return 0;
}
