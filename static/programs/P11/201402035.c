#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
	long long int val;
	node *next;
};
node *head=NULL;
void *push(long long int x){
	node *tmp=(node*)malloc(sizeof(node));
	tmp->val=x;
	tmp->next=NULL;

	if(head==NULL)
		head=tmp;

	else
		tmp->next=head;
		head=tmp;
	}

void pop(){
	node *inp;
	inp=head;
	head=head->next;
	free(inp);
}
int main(){
long long int i,t,j;
	long long int area[100007];
long long int h[100007];
long long int n;
p:
scanf("%lld",&n);

		for(i=0;i<n;i++)
			scanf("%lld",&h[i]);
		if(n==0)
			return 0;	

		else
		for(i=0;i<n;i++){
			while(head!=NULL){
				if(h[i]<=h[head->val])
					pop();
				else
					break;
			}
			if(head==NULL)
				t=-1;
			else
				t=head->val;

			area[i]=i-t-1;
			push(i);
		}

		while(head!=NULL){
			pop();
		}

		for(i=n-1;i>=0;i--){
			while(head!=NULL){
				if(h[i] <= h[head->val])
					pop();
					else 
						break;
				}
			if(head==NULL)
				t=n;
			else 
				t=head->val;

			area[i]+=t-i-1;
			push(i);
		}
		long long int max=n;

		for(i=0;i<n;i++){
			area[i]=h[i]*(area[i]+1);
			if(area[i]>max)
				max=area[i];
				}
	printf("%lld\n",max);
goto p;
}
