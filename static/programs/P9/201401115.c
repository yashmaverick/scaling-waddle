#include<stdio.h>
#include<stdlib.h>
typedef struct doubl{
	long long int sum,bags;
	long long int *a;
	struct doubl *next;
}node;
int main(){
	long long int n,m,i,j,sumofweights,w,mod;
	node *root=NULL;
	scanf("%lld%lld",&n,&mod);
	node *head;
	node *prev;
	for(i=0;i<n;i++){
		node *arr=(node *)malloc(sizeof(node));
		scanf("%lld",&m);
		arr->a = (long long int *)malloc(m*sizeof(long long int));
		arr->bags=m;
		sumofweights=0;
		for(j=0;j<m;j++){
			scanf("%lld",&w);
			arr->a[j] = w;
			sumofweights = ((sumofweights%mod)+(w%mod))%mod;
		}
		arr->sum = sumofweights;
		if(root==NULL){
			root=arr;
		}
		else{
			head = root;
			prev = root;
			if(arr->sum < head->sum){
				arr->next = root;
				root = arr;
			}
			else{
				while(head!=NULL && head->sum <= arr->sum){
					prev = head;
					head = head->next;
				}
				if(head==NULL){
					prev->next = arr;
				}
				else{
					prev->next = arr;
					arr->next = head;
				}
			}
		}
	}
	while(root!=NULL){
		printf("%lld\n",root->sum);
		for(i=0;i<root->bags;i++){
			printf("%lld\n",root->a[i]);
		}
		printf("\n");
		root = root->next;
	}
	return 0;
}