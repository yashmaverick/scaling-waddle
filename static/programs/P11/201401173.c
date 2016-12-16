#define loop(n) for(i=0;i<n;i++)
#include<stdio.h>
#include<stdlib.h>
//typedef struct stack stack;
typedef struct node node;
struct node{
	long long int val;
	node* next;
};
node* push(node* head,long long int x){
	node* new=(node*)malloc(sizeof(node));
	new->val=x;
	new->next=head;
	return new;
}
node* pop(node* head){
	if(head!=NULL){
		node* tmp=(node*)malloc(sizeof(node));
		tmp=head->next;
		free(head);
		return tmp;
	}
	return;
}
long long int top(node* head){
	//printf("Top element:%d\n",head->val);
	if(head==NULL)
		return -1;
	return head->val;
}
node* popk(node* head,int k){
	node* head2=NULL;
	int i=k-1;
	while(i--){
		head2=push(head2,top(head));
		head=pop(head);
	}
	head=pop(head);
	while(i--){
		head=push(head,top(head2));
		head2=pop(head2);
	}
	return head;
}
/*void print(node* head){
	if(head==NULL)
		return;
	printf("%d ",head->val);
	print(head->next);
}*/
int main(){
	typedef long long int lli;
	lli n,a[100000],i,j;
	lli s[100000];
	while(1){
		lli top=-1;
		scanf("%lld",&n);
		if(n==0)
			break;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		lli b[100000],c[100000];
		//node* head=NULL;
		//head=push(head,0);
		//int l=0;
		//b[l++]=-1;
		for(i=0;i<n;i++){
			if(top==-1){
				b[i]=-1;
				//head=push(head,i);
				s[++top]=i;
			}
			if(a[i]>a[s[top]]){
				b[i]=s[top];
				//head=push(head,i);
				s[++top]=i;
			}
			else if(a[i]<=a[s[top]]){
				while(top!=-1&&a[s[top]]>=a[i]){
					//head=pop(head);
					top--;
				}
				if(top==-1){
					b[i]=-1;
					//head=push(head,i);
					s[++top]=i;
				}
				else{
					b[i]=s[top];
					//head=push(head,i);
					s[++top]=i;
				}
			}
		}
		/*for(i=0;i<n;i++)
		  printf("%d ",b[i]);
		  printf("\n");*/
		//node* head2=NULL;
		top=-1;
		for(j=n-1;j>=0;j--){
			if(top==-1){
				c[j]=-1;
				//head2=push(head2,j);
				s[++top]=j;
			}
			if(a[j]>a[s[top]]){
				//c[j]=top(head2);
				c[j]=s[top];
				//head2=push(head2,j);
				s[++top]=j;
			}
			else if(a[j]<=a[s[top]]){
				while(top!=-1&&a[s[top]]>=a[j]){
					//head2=pop(head2);
					top--;
				}
				if(top==-1){
					c[j]=-1;
					//head2=push(head2,j);
					s[++top]=j;
				}
				else{
					//c[j]=top(head2);
					c[j]=s[top];
					//head2=push(head2,j);
					s[++top]=j;
				}
			}
		}
		//	if(c[0]=0)
		//	c[0]=-1;
		/*for(i=0;i<n;i++)
		  printf("%d ",c[i]);
		  printf("\n");*/
		lli x,y;
		lli ar,max=0;
		loop(n){
			x=i-b[i]-1;
			if(c[i]==-1)
				y=n-i-1;
			else
				y=c[i]-i-1;
			ar=(x+y+1)*a[i];
			//printf("%d\n",ar);
			if(ar>max)
				max=ar;
		}
		printf("%lld\n",max);
	}
	return 0;
}
