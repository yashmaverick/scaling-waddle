#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* ptr;
};
struct node* sabka[100006];
int wt[500001]={0};
int pa=0,ans[100005]={0};
int heap[300005]={0};
int mic=0;
void insert(int x){
	mic++;
	heap[mic] = x;
	int data,tmp = mic;
	while(heap[tmp] < heap[tmp/2]){
		data = heap[tmp];
		heap[tmp] = heap[tmp/2];
		heap[tmp/2] = data;
		tmp = tmp/2;
	}
	return ;
}
void delete(){
	ans[pa] = heap[1];
	pa++;
	heap[1] = heap[mic];
	mic--;
	int data,tmp = 1;
	while((heap[tmp] > heap[2*tmp] && 2*tmp<=mic) || (heap[tmp] > heap[2*tmp+1] && 2*tmp+1<=mic)){
		if(heap[2*tmp]>heap[2*tmp+1] && 2*tmp+1<=mic){
			data = heap[2*tmp+1];
			heap[2*tmp+1] = heap[tmp];
			heap[tmp] = data;
			tmp = 2*tmp+1;
		}
		else{
			data = heap[2*tmp];
			heap[2*tmp] = heap[tmp];
			heap[tmp] = data;
			tmp = 2*tmp;
		}
	}
	return ;
}
void search(){
	int o = heap[1];
	delete();
	struct node* tmp;
	tmp = sabka[o];
	while(tmp!=NULL){
		wt[tmp->data]--;
		if(wt[tmp->data]==0)
			insert(tmp->data);
		tmp = tmp->ptr;
	}
	return ;
}
int main(){
	int x,y,i,j,k,l,n,m;
	struct node* new;
	for(i=1;i<=100000;i++)
		sabka[i] =NULL;
	scanf("%d%d",&n,&m);
	heap[0]=-1;
	for(i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		new = (struct node*)malloc(sizeof(struct node));
		new->data = y;
		new->ptr = sabka[x];
		sabka[x] = new;
		wt[y]++;
	}
	//	struct node* tmp;
	//	for(i=1;i<=n;i++){
	//		tmp = sabka[i];
	//		while(tmp!=NULL){
	//			printf("%d ",tmp->data);
	//			tmp = tmp->ptr;
	//		}
	//		printf("\n");
	//	}
	for(i=1;i<=n;i++)
		if(wt[i]==0)
			insert(i);
	while(mic!=0)
		search();
	for(i=0;i<pa-1;i++)
		printf("%d ",ans[i]);
	printf("%d\n",ans[pa-1]);
	return 0;
}
