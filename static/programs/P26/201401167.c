#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define sc(n) scanf("%d",&n)
#define DRT()  int t; sc(t); while(t--)
#define f(i,a,n) for(i=a;i<n;i++)
#include<limits.h>
#define set(ch,a) memset(ch,a,sizeof(ch))
#define ml(a) (a*)malloc(sizeof(a))
int ar[1100][1100],sv[10000],qu[1200],q[1200],vis[12000],find[12000],f,r,m,k,w;
typedef struct node{
	int v;
	struct node* n;
}node;node* adj[12000];int pr[1200];
void bfs(int a,int b)
{	r++;k++;
	node* it=adj[a];//int i=0;
	if(it==NULL)printf("%d %d\n",r,f);
	while(it!=NULL)
	{if(!vis[it->v])
		{
			vis[it->v]=1;q[f]=b+1;qu[f++]=pr[it->v];
			ar[m][it->v]=b+1;
			if(ar[m][it->v]!=ar[it->v][m] && ar[it->v][m]<1100)printf("n0\n");
		}
			it=it->n;
	}
	if(r<f)
		bfs(qu[r],q[r]);
}
//void print
int main()
{	int j,i,n,l=0;
	set(sv,0);set(ar,0x7F);
	f(i,2,10000)
		for(j=2;j*i<10000;j++)
			sv[j*i]=1;
	f(i,0,12000){adj[i]=NULL;find[i]=1099;}
	f(i,1000,10000)
		if(sv[i]==0)
		{	pr[l++]=i;
		find[i]=l-1;}
	f(i,0,l)
	{	int t=pr[i];node* nd;
		f(j,1,10)
			if(sv[(t-t%10 +j)]==0&& j!=t%10)
				{	nd=ml(node);nd->v=find[t-t%10 +j];
					nd->n=adj[t];adj[t]=nd;}//printf("%d ",nd->v);	}
		int p=t-t%100;
		f(j,1,10)
			if(sv[(p+(t%100 + j*10)%100)]==0)
			{	nd=ml(node);nd->v=find[p+(t%100 + j*10)%100];
			           nd->n=adj[t];adj[t]=nd;}//printf("%d ",nd->v); }
		p=t-t%1000;
		f(j,1,10)
			if(sv[p+(t%1000 + j*100)%1000]==0)
			{ 	nd=ml(node);nd->v=find[p+(t%1000 + j*100)%1000];
		                nd->n=adj[t];adj[t]=nd;}//printf("%d ",nd->v); }
		p=t%1000;
		f(j,1,10)
			if(sv[p+j*1000]==0 && j!=t/1000)
			{	nd=ml(node);nd->v=find[p+j*1000];
		                  nd->n=adj[t];adj[t]=nd;}//printf("%d ",nd->v); }
	}
//	f(i,0,l){printf("%d ",pr[i]);}
	//return 0;
	m=0;set(vis,0);f=0;r=-1;bfs(pr[0],0);
//	f(i,0,l)printf("%d",vis[i]);
	f(i,1,l)
	{m=i;set(vis,0);f=0;r=-1;bfs(pr[i],0);}
	sc(n);
	f(i,0,n)
	{sc(j);sc(w);if(j==w)printf("0\n");
		else if(ar[find[j]][find[w]]<1100)printf("%d\n",ar[find[j]][find[w]]);
		else printf("Impossible\n");
	}
	return 0;
}
