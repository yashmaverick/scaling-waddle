#include<stdio.h>
#include<stdlib.h>
struct node{
	int d;
	struct node*next;
};
typedef struct node node;
node*head[100005]={NULL};
int heap[100005]={0};
int count[100005]={0};
int t=1;
void insert(int e,int x){
	node*temp=(node*)malloc(sizeof(node));
	temp->d=x;
	temp->next=NULL;
	if(head[e]==NULL)
		head[e]=temp;
	else{
		temp->next=head[e];
		head[e]=temp;
	}
	return;
}
void print(int e){
	printf("%d ->",e);
	node*temp=head[e];
	while(temp){
		printf("%d ",temp->d);
		temp=temp->next;
	}
	printf("\n");
	return;
}
void show(){
	printf("show\n");
	int i;
	for(i=1;i<t;i++){
		printf("  i=%d heap[i]=%d\n",i,heap[i]);
	}
	printf("end\n");
	return;
}
void swap(int e,int f){
	int g;
	g=heap[e];
	heap[e]=heap[f];
	heap[f]=g;
}
void inserth(int x){
	//printf("t=%d x=%d\n",t,x);
	int l=t,c;
	heap[l]=x;
	while(heap[l]<heap[l/2]){
		swap(l,l/2);
		l=l/2;
	}
	t++;
	//show();
	return;
}

void del(int x){
	heap[1]=heap[--t];
	int c=1,fl;
	while(2*c+1<=t&&(heap[c]>heap[2*c]||heap[c]>heap[2*c+1])){
		//	for(int i=1;i<t;i++)
		//		cout<<endl<<i<<" "<<a[i];
		//	cout<<"\ndone\n";
		fl=0;
		if(heap[2*c]<heap[2*c+1])
			fl=1;
		if(fl==1){
			swap(c,2*c);
			c=2*c;
		}
		else{
			swap(c,2*c+1);
			c=2*c+1;	
		}

	}
	//show();
}
int main(){
	int i,n,m,x,y;
	scanf("%d%d",&n,&m);
	int h=m;
	while(h--){
		scanf("%d%d",&x,&y);
		insert(x,y);
		count[y]++;
	}
	//for(i=0;i<10000;i++)
	//	if(head[i]!=NULL)
	//		print(i);	
	for(i=1;i<=n;i++)
		if(count[i]==0)
			inserth(i);	// heap of all nodes with no incoming edges
	//show();
	int ans[100005];
	int l=0,p=t,j;
	p--;
	//printf("p = %d\n",p);
	while(p!=0){
		j=heap[1];
		del(heap[1]);
		ans[l++]=j;
		//printf("j=%d\n",j);
		node*temp=head[j];
		while(temp){
			y=temp->d;
			temp=temp->next;
			count[y]--;
			if(count[y]==0)		
				inserth(y);
			//count[y]--;
		}
		p=t;
		p--;
		//show();
	}
	for(i=0;i<=l-2;i++){
		printf("%d ",ans[i]);
	}
	printf("%d\n",ans[l-1]);
	for(i=0;i<100005;i++)
		head[i]=NULL;
	return 0;
}
