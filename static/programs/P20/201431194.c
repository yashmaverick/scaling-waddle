#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* ptr;
};
int vis[1000001];
struct node* sabka[1000001];
void insert(int x,int y){
	struct node* new;
	struct node* new1;
	new = (struct node*)malloc(sizeof(struct node));
	new1 = (struct node*)malloc(sizeof(struct node));
	new->ptr = sabka[x];
	new->data = y;
	sabka[x] = new;
	new1->ptr = sabka[y];
	sabka[y] = new1;
	new1->data = x;
	return ;
}
int max=0;
int rem;
void search(struct node* now,int cnt,int upto){
	struct node* tmp = now;
	if(cnt>max){
		max = cnt;
		rem = upto;
	}
	while(tmp!=NULL){
		if(vis[tmp->data]==0){
			vis[tmp->data]=1;
			search(sabka[tmp->data],cnt+1,tmp->data);
		}
		tmp = tmp->ptr;
	}
	return ;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		struct node* tmp;
		int x,y,i,j,k,l,n,m;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			sabka[i]=NULL;
			vis[i]=0;
		}
		max=0;
		for(i=0;i<n-1;i++){
			scanf("%d%d",&x,&y);
			insert(x,y);
		}
/*		for(i=1;i<=n;i++){
			tmp = sabka[i];
			if(tmp!=NULL){
				printf("%d->",i);
				while(tmp!=NULL){
					printf("%d ",tmp->data);
					tmp = tmp->ptr;
				}
				printf("\n");
			}
		}*/
		vis[1]=1;
		search(sabka[1],1,1);
//		printf("%d %d\n",max,rem);
		for(i=1;i<=n;i++)
			vis[i]=0;
		max=0;
		vis[rem]=1;
		search(sabka[rem],1,rem);
		printf("%d\n",max);
	}
	return 0;
}
