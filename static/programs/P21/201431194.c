#include<stdio.h>
#include<stdlib.h>
struct node{
	int num;
	int wt;
	struct node* ptr;
};
void swap(int* x,int* y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
	return ;
}
void delete();
struct node* sabka[100005];
int heap[2][100005];
int vis[100005]={0};
int dis[100005];
int mic;
void insertheap(int dis,int into){	
	mic++;
	heap[0][mic] = dis;
	heap[1][mic] = into;
	int tmp = mic;
	while(heap[0][tmp/2] > heap[0][tmp]){
		swap(&heap[0][tmp],&heap[0][tmp/2]);
		swap(&heap[1][tmp],&heap[1][tmp/2]);
		tmp = tmp/2;
	}
	return ;
}
void search(){
	struct node* tmp = sabka[heap[1][1]];
	int o = heap[1][1];
	delete();
	while(tmp!=NULL){
		if(vis[tmp->num]==0 && (dis[o] + tmp->wt) < dis[tmp->num]){
			dis[tmp->num] = dis[o]+tmp->wt;
			insertheap(dis[o]+tmp->wt,tmp->num);
		}
		tmp = tmp->ptr;
	}
	return ;
}
void delete(){
	heap[0][1] = heap[0][mic];
	heap[1][1] = heap[1][mic];
	mic--;
	int tmp = 1;
	struct node* now;
	while((heap[0][tmp] > heap[0][2*tmp] && 2*tmp<=mic) || ((heap[0][tmp] > heap[0][2*tmp+1]) && 2*tmp+1<=mic)){
		if(heap[0][2*tmp] > heap[0][2*tmp+1] && 2*tmp+1<=mic){
			swap(&heap[0][2*tmp+1],&heap[0][tmp]);
			swap(&heap[1][2*tmp+1],&heap[1][tmp]);
			tmp = 2*tmp+1;
		}
		else{
			swap(&heap[0][2*tmp],&heap[0][tmp]);
			swap(&heap[1][2*tmp],&heap[1][tmp]);
			tmp = 2*tmp;
		}
	}
	return ;
}
void insert(int x,int y,int z){
	struct node* new;
	new = (struct node*)malloc(sizeof(struct node));
	new->wt = z;
	new->num = y;
	new->ptr = sabka[x];
	sabka[x] = new;
	return ;
}
int main(){
	int x,z,y,i,j,k,l,n,m;
	struct node* tmp;
	heap[0][0] = -1;
	scanf("%d%d",&n,&m);
	for(i=0;i<100005;i++){
		sabka[i] = NULL;
		dis[i] = 1000000000;
	}
	for(i=0;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		insert(x,y,z);
	}
	struct node* now;
	scanf("%d%d",&x,&y);
	heap[0][1] = 0;
	heap[1][1] = x;
	dis[x] = 0;
	mic=1;
	while(mic!=0){
		if(vis[heap[1][1]]==0){
			vis[heap[1][1]]=1;
			search();
		}
		else
			delete();
	}
	if(vis[y]==0)
		printf("NO\n");
	else
		printf("%d\n",dis[y]);
	return 0;
}
