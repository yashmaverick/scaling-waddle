#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int value;
	struct node *next;
}node;
node *A[1000001];
int b[1000001],d[1000001];
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
void dfs(int p,int l){
	int q,w;
	if(b[p]==0){
		d[p]=l;
		b[p]=1;
		node* head=A[p];
		while(head->next!=NULL){
			q=head->next->value;
			head=head->next;
			dfs(q,l+1);
		}
	}
	return;
}
int main(){
	int a,B,i,j,k,max,t,o,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n!=1){
			for(i=1;i<=n;i++){

				A[i]=(node*)malloc(sizeof(node));
				A[i]->value=i;
				A[i]->next=NULL;
			}
			o=n-1;
			while(o--){
				scanf("%d %d",&a,&B);
				insert(a,B);
				insert(B,a);
			}
			dfs(1,0);
			for(j=1;j<=n;j++){
				b[j]=0;
			}

			max=0;
			for(i=1;i<=n;i++){
				if(d[i]>max){
					max=d[i];
					k=i;
				}
				d[i]=0;
			}
			dfs(k,0);
			max=0;
			for(i=1;i<=n;i++){
				if(d[i]>max){
					max=d[i];
				}
				d[i]=0;
				b[i]=0;
			}
			printf("%d\n",max+1);
		}
		else{
			printf("1\n");
		}
	}
	return 0;
}












