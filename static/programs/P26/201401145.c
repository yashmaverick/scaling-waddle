#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define rep(i,s,n,d) for(i=s;i<=n;i+=d)
#define MAX 100009
typedef struct node{
	int val;
	struct node *next;
}node;
int q[MAX],dis[MAX],par[MAX];
int front,rear;
bool isp[MAX],vis[MAX];
node *list[MAX];
void in(int *address) {scanf("%d",address);}
void out(int *pointer){printf("%d\n",*pointer);}
bool empty() {return front>=rear?1:0;}
void push(int v) {q[rear++]=v;}
int pop() {return q[front++];}
node *insert(node *head,int value){
	node *tmp;
	tmp=(node *)malloc(sizeof(node));
	tmp->next=head;
	tmp->val=value;
	return tmp;
}
void isprime()
{
	int i,j;
	isp[0]=isp[1]=1;
	rep(i,2,100,1)if(!isp[i]) rep(j,2*i,10000,i) isp[j] = 1;
}
int arraytonum(int a[])
{
	int tmp=0,k=0;
	while(k<4)tmp = tmp*10 + a[k++];
	return tmp;
}
void numtoarray(int a[],int n)
{
	int w=3;
	while(n)
	{
		a[w--] = n%10;
		n/=10;
	}
}
void bfs(int src,int end){
	node *tmp;
	int cur;
	front=rear=0;
	push(src);
	vis[src]=1;
	dis[src]=0;
	while(!empty()){
		cur=pop();
		tmp=list[cur];
		while(tmp!=NULL){
			if(!vis[tmp->val]){
				dis[tmp->val]=dis[cur]+1;
				push(tmp->val);
				vis[tmp->val]=1;
				if(tmp->val==end)return ;
			}
			tmp=tmp->next;
		}
	}
	return ;
}
void consgraph(){
	int i,j,tmp=1,k;
	int a[4];
	rep(i,1000,9999,1){
		if(!isp[i]){
			rep(k,0,3,1){
				numtoarray(a,i);
				rep(j,0,9,1){
					a[k]=j;
					tmp=arraytonum(a);
					if(isp[tmp]==0 && tmp!=i && tmp>=1000 ){
						list[i]=insert(list[i],tmp);
						list[tmp]=insert(list[tmp],i);
					}
				}
			}
		}
	}
}
int main()
{
	int t,z;
	rep(z,1000,10000,1){
		isp[z]=0;
		list[z]=NULL;
	}
	isprime();
	consgraph();
	in(&t);
	rep(z,1,t,1){
		front=rear=0;
		int start,end,n,j,tmp,i;
		rep(i,1000,10000,1){
			dis[i]=-1;
			vis[i]=0;
		}
		in(&start);
		in(&end);
		bfs(start,end);
		dis[end]==-1?printf("Impossible\n"): out(&dis[end]);
	}
	return 0;
}
