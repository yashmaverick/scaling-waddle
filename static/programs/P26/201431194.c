#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	int wt;
	struct node* ptr;
};
int heap[2][50005];
int dis[10005];
int mic;
int vis[10000];
int si[10000];
struct node* sabka[10000];
void makeadj();
void delete();
void swap(int* x,int* y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
	return ;
}
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
		if(vis[tmp->data]==0 && (dis[o] + tmp->wt) < dis[tmp->data]){
			dis[tmp->data] = dis[o]+tmp->wt;
			insertheap(dis[o]+tmp->wt,tmp->data);
		}
		tmp = tmp->ptr;
	}
	return ;
}
void delete(){
	int i;
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
void make(int x){
	int m = 1000,j,i,tmp;
	for(j=1;j<=4;j++){
		for(i=0;i<10;i++){
				if(si[x-((x/m)%10)*m + i*m]==1)
					if((x-((x/m)%10)*m + i*m)/1000!=0)
						makeadj(x,x-((x/m)%10)*m + i*m);
		}
		m = m/10;
	}
	return ;
}
void makeadj(int x,int y){
	if(x==y)
		return;
	struct node* new;
	new = (struct node*)malloc(sizeof(struct node));
	new->data = y;
	new->ptr = sabka[x];
	new->wt = 1;
	sabka[x] = new;
	return ;
}
int main(){
	int i,j,t,p1,p2;
	for(i=1;i<=9999;i++){
		sabka[i]=NULL;
		si[i]=1;
	}
	for(i=2;i*i<=9999;i++){
		if(si[i]==1)
			for(j=2;j*i<=9999;j++)
				si[i*j] = 0;
	}
	for(i=1000;i<=10000;i++)
		if(si[i]==1)
			make(i);
	struct node* new;
	for(i=1000;i<1000;i++){
		new = sabka[i];
		while(new!=NULL){
			printf("%d ",new->data);
			new = new->ptr;
		}
		printf("\n");
	}
	scanf("%d",&t);
	while(t--){
		for(i=1;i<=10000;i++){
			dis[i] = 1000000000;
			vis[i]=0;
		}
		int j,k,l,n,m;
		heap[0][0] = -1;
		scanf("%d%d",&p1,&p2);
		heap[0][1] = 0;
		heap[1][1] = p1;
		dis[p1] = 0;
		mic = 1;
		while(mic!=0){
			if(vis[heap[1][1]]==0){
				vis[heap[1][1]]=1;
				search();
			}
			else
				delete();
			if(vis[p2]==1)
				break;
		}
		if(vis[p2]==0)
			printf("Impossible\n");
		else
			printf("%d\n",dis[p2]);
	}
	return 0;
}
