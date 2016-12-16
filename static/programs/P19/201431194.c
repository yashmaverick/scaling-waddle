#include<stdio.h>
#include<stdlib.h>
struct leaf{
	int data;
	int flag;
	struct leaf* ptr[10];
};
int uni;
struct leaf head;
void insert(long long int x,long long int mul){
	int i,j;
	struct leaf* new;
	struct leaf* now = &head;
	if(mul!=0){
		int flag1,summ=0;
		while(now->ptr[x/mul] != NULL && mul!=0){
			now = now->ptr[x/mul];
			x = x%mul;
			mul=mul/10;
			summ++;
			if(mul==0)
				break;
		}
		if(mul==0)
			uni=0;
		if(now!=NULL)
			if(now->flag==1)
				uni=0;
	}
	int sumi=0;
	while(mul!=0){
		new = (struct leaf*)malloc(sizeof(struct leaf));
		new->data = x/mul;
		now->ptr[x/mul] = new;
		now = new;
		now->flag = 0;
		x = x%mul;
		mul=mul/10;
		for(j=0;j<10;j++)
			new->ptr[j]=NULL;
		sumi++;
	}
	if(sumi>0)
		now->flag = 1;
	return;
}
int main(){
	int t,i;
	scanf("%d",&t);
	while(t--){
		head.data = 0;
		head.flag=0;
		struct leaf* now;
		uni = 1;
		int j,k,l,n,o;
		long long int x,tmp,mul=1;
		scanf("%d",&n);
		for(j=0;j<10;j++)
			head.ptr[j]=NULL;
		for(i=0;i<n;i++){
			mul = 1;
			scanf("%lld",&x);
			tmp = x;
			while(tmp != 0){
				tmp = tmp/10;
				mul = mul*10;
			}
			insert(x,mul/10);
		}
		if(uni==0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
