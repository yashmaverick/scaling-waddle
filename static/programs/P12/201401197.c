#include<stdio.h>
#include<stdlib.h>

struct stak{
	int count;
	int val;
	struct stak *next;
};

int pushin(int);
struct stak *head,*temp;
int main(){
	int n,i,j,k,ar[500005],max;
	long long ans;
	head=(struct stak *)malloc(sizeof(struct stak));
	head->next=NULL;
	while(1){
		scanf("%d",&n);
		if(n==0){
			break;
		}
		for(i=0;i<n;i++){
			scanf("%d",ar+i);
		}
		ans=0;
		max=ar[0];
		for(i=1;i<n;i++){
			if(ar[i]<max){
				ans++;
			}
			else if(ar[i]>max){
				max=ar[i];
			}
		}
		max=ar[n-1];
		for(i=n-2;i>=0;i--){
			if(ar[i]<max){
				ans++;
			}
			else{
				max=ar[i];
			}
		}
		for(i=0;i<n;i++){
			ans+=pushin(ar[i]);
		}
		printf("%lld\n",(((long long)n*(long long)(n-1))>>1)-ans);
		while(head->next!=NULL){
			temp=head->next;
			head->next=temp->next;
			free(temp);
		}
	}
	return 0;
}

int pushin(int val){
	while(head->next!=NULL&&head->next->val<val){
		temp=head->next;
		head->next=temp->next;
		free(temp);
	}
	if(head->next==NULL||head->next->val>val){
		temp=(struct stak *)malloc(sizeof(struct stak));
		temp->count=0;
		temp->val=val;
		temp->next=head->next;
		head->next=temp;
		return 0;
	}
	else{
		head->next->count++;
		return head->next->count;
	}
}
