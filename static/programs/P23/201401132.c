#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int value;
	struct node *next;
}node;
node *A[1000001];
int b[1000001],s[1000001],y;
void insert(int a,int b){
	node *head=A[a];
	node* new=(node*)malloc(sizeof(node));
	new->value=b;
	new->next=NULL;
	if(head->next==NULL)
		head->next=new;
	else
	{
		node *temp;
		temp=A[a]->next;
		A[a]->next=new;
		new->next=temp;
	}
	return;

}
void dfs(int p){
	int q,w;
	if(b[p]==0){
		b[p]=1;
		node* head=A[p];
		while(head->next!=NULL){
			q=head->next->value;
			head=head->next;
//			printf("$$$$$");
			dfs(q);
		}
			s[y++]=p;
	}
	return;
}
int main(){
	int a,B,i,j,k,max,e,o,n;
	scanf("%d",&n);
	scanf("%d",&e);
	for(i=1;i<=n;i++){

		A[i]=(node*)malloc(sizeof(node));
		A[i]->value=i;
		A[i]->next=NULL;
		b[i]=0;
	}
	while(e--){
		scanf("%d %d",&a,&B);
		insert(a,B);
	}
	y=0;
	for(i=n;i>=1;i--){
		if(b[i]==0){
//			printf("bottom%d\n",i);
			dfs(i);
		}
	}
	for(i=y-1;i>0;i--){
		printf("%d ",s[i]);
	}
	printf("%d\n",s[0]);
	return 0;
}





