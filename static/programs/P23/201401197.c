#include<stdio.h>
#include<stdlib.h>

struct list{
	int val;
	struct list *next;
};

void insert_x_into_x_(int,int);
void insert(int);
void rev_heapify(int);
int removeh();
void heapify(int);
void swap(int,int);
int heap[100005],hsize,tos[100005],ans[100005],ap;
struct list *ar[100005];
int main(){
	struct list *temp;
	int n,m,i,j,k;
	hsize=0;ap=0;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		tos[i]=0;
		ar[i]=NULL;
	}
	while(m--){
		scanf("%d %d",&i,&j);
		i--;j--;
		insert_x_into_x_(j,i);
		tos[j]++;
	}
	for(i=0;i<n;i++){
		if(tos[i]==0){
			insert(i);
		}
	}
	while(hsize!=0){
		i=removeh();
		ans[ap++]=i+1;
		temp=ar[i];
		while(temp!=NULL){
			tos[temp->val]--;
			if(tos[temp->val]==0){
				insert(temp->val);
			}
			temp=temp->next;
		}
	}
	for(i=0;i<n-1;i++){
		printf("%d ",ans[i]);
	}
	printf("%d\n",ans[n-1]);
	return 0;
}

void insert_x_into_x_(int val,int to){
	struct list *temp;
	temp=ar[to];
	ar[to]=(struct list *)malloc(sizeof(struct list));
	ar[to]->val=val;
	ar[to]->next=temp;
}

void insert(int val){
	heap[++hsize]=val;
	rev_heapify(hsize);
}

void rev_heapify(int ind){
	while(ind>1){
		if(heap[ind>>1]>heap[ind]){
			swap(ind>>1,ind);
			ind>>=1;
		}
		else{
			break;
		}
	}
}

int removeh(){
	int toret;
	toret=heap[1];
	heap[1]=heap[hsize--];
	heapify(1);
	return toret;
}

void heapify(int ind){
	int i;
	while(ind<<1<hsize){
		i=ind<<1;
		if(heap[i]>heap[i+1]){
			i++;
		}
		if(heap[ind]>heap[i]){
			swap(i,ind);
			ind=i;
		}
		else{
			break;
		}
	}
	if(ind<<1==hsize&&heap[ind]>heap[ind<<1]){
		swap(ind,ind<<1);
	}
}

void swap(int a,int b){
	heap[a]+=heap[b];
	heap[b]=heap[a]-heap[b];
	heap[a]-=heap[b];
}
