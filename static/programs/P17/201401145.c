#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 1000005
#define repf(i,n) for(i=1;i<=n;i++)
#define repb(i,n) for(i=n-1;i>0;i--)
void in(int *address){
	scanf("%d",address);
}
void out(int *pointer){
	printf("%d\n",*pointer);
}
typedef struct info{
	int left;
	int right;
}info;
info l[MAX];
bool vis[MAX];
int p[MAX],np[MAX],a[MAX],b[MAX],par[MAX],stack[MAX];
int main()
{
	int n,i,start=-1,t,x,y;
	in(&n);
	repf(i,n) in(&p[i]);
	repf(i,n) in(&a[i]);
	repf(i,n) b[a[i]]=i;
	repf(i,n) np[i]=b[p[i]];
	stack[++start]=np[n];
	l[n].left=-1;
	repb(i,n){
		if(np[i]>stack[start]){
			l[i].left=stack[start];
			stack[++start]=np[i];
		}
		else{
			while(start>=0 && np[i]<stack[start]) start--;
			if(start==-1) l[i].left=-1;
			else l[i].left=stack[start];
			stack[++start]=np[i];
		}
	}
	start=0;
	stack[start]=np[n];
	l[n].right=-1;
	repb(i,n){
		if(np[i]<stack[start]){
			l[i].right=stack[start];
			stack[++start]=np[i];
		}
		else{
			while(start>=0 && np[i]>stack[start]) start--;
			if(start==-1)l[i].right=-1;
			else l[i].right=stack[start];
			stack[++start]=np[i];
		}
	}
	repf(i,n)vis[i]=0;
	repf(i,n){
		if(l[i].left!=-1){
			if(vis[l[i].left]==0){
				vis[l[i].left]=1;
				par[l[i].left]=np[i];
			}
			else l[i].left=-1;
		}
		if(l[i].right!=-1){
			if(vis[l[i].right]==0){
				vis[l[i].right]=1;
				par[l[i].right]=np[i];
			}
			else l[i].right=-1;
		}
	}
	in(&t);
	while(t--){
		repf(i,n)vis[i]=0;
		scanf("%d%d",&x,&y);
		x=b[x];
		y=b[y];
		while(1){
			vis[x]=1;
			x=par[x];
			if(x==0) break;
		}
		while(vis[y]!=1){
			vis[y]=1;
			y=par[y];
		}
		out(&a[y]);
	}
	return 0;
}
