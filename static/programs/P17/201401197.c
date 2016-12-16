#include<stdio.h>
#include<stdlib.h>

struct node{
	int l,r,val;
};

void maketree(int,int,int);
void putintree(int,int,int);
int getmin(int,int,int);
int VCC=1<<30;
struct node *stree;
int main(){
	int n,t,*pre,*prepos,*inpos,i,j,k;
	scanf("%d",&n);
	pre=malloc(sizeof(int)*n);
	prepos=malloc(sizeof(int)*n);
	inpos=malloc(sizeof(int)*n);
	stree=(struct node *)malloc(sizeof(struct node)*n*3);
	stree--;
	for(i=0;i<n;i++){
		scanf("%d",pre+i);
		pre[i]--;
		prepos[pre[i]]=i;
	}
	maketree(1,0,n-1);
	for(i=0;i<n;i++){
		scanf("%d",&j);
		j--;
		inpos[j]=i;
		putintree(1,i,prepos[j]);
	}
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d %d",&j,&k);
		j=inpos[j-1];k=inpos[k-1];
		if(j>k){
			j+=k;k=j-k;j-=k;
		}
		printf("%d\n",pre[getmin(1,j,k)]+1);
	}
	return 0;
}

void maketree(int ind,int low,int high){
	if(low>high){
		return ;
	}
	stree[ind].l=low;stree[ind].r=high;
	stree[ind].val=VCC;
	if(low==high){
		return ;
	}
	maketree(ind<<1,low,(low+high)>>1);
	maketree((ind<<1)+1,((low+high)>>1)+1,high);
}

void putintree(int ind,int pos,int val){
	if(stree[ind].l>pos||stree[ind].r<pos){
		return ;
	}
	if(stree[ind].val>val){
		stree[ind].val=val;
	}
	if(stree[ind].l!=stree[ind].r){
		putintree(ind<<1,pos,val);
		putintree((ind<<1)+1,pos,val);
	}
}

int getmin(int ind,int low,int high){
	int lans,rans;
	if(stree[ind].l>high||stree[ind].r<low){
		return VCC;
	}
	if(stree[ind].l>=low&&stree[ind].r<=high){
		return stree[ind].val;
	}
	lans=getmin(ind<<1,low,high);
	rans=getmin((ind<<1)+1,low,high);
	if(lans>rans){
		lans=rans;
	}
	return lans;
}
