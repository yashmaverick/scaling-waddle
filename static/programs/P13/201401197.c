#include<stdio.h>
void push(int);
void popable(int);
int stack[100005],top[100005],head,maxval,maxd;
int main(){
	int t,n,i,j,ar[100005];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		head=-1;maxval=100005;maxd=-1;
		for(i=0;i<n;i++){
			scanf("%d",ar+i);
		}
		push(ar[n-1]);
		for(i=n-2;i>=0;i--){
			popable(ar[i]);
			push(ar[i]);
		}
		printf("%d %d\n",maxval,maxd);
	}
	return 0;
}

void push(int x){
	head++;
	stack[head]=x;
	if(head==maxd&&x<maxval){
		maxval=x;
	}
	else if(head>maxd){
		maxd=head;
		maxval=x;
	}
	if(head==0){
		top[head]=head;
	}
	else{
		if(stack[head]<stack[head-1]){
			top[head]=top[head-1];
		}
		else{
			top[head]=head;
		}
	}
}

void popable(int x){
	int i;
	if(stack[head]<x||head==0){
		return ;
	}
	i=top[head];
	while(i>0&&stack[i-1]>x){
		head=i-1;
		i=top[i-1];
	}
}
