#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node
{
	struct node *next;
	int vertex;
};
void gcd(int x,int y)
{
	int i;
	for(i=x;i>=1;i--)
	{
		if(x%i==0&&y%i==0)
		{
			break;
		}
	}
	return;
}
void binary(int a[],int n,int m,int l,int u)
{
	int mid,c=0;
	if(l<=u){
		mid=(l+u)/2;
		if(m==a[mid]){
			c=1;
		}
		else if(m<a[mid]){
			return binary(a,n,m,l,mid-1);
		}
		else
			return binary(a,n,m,mid+1,u);
	}
	else
		return ;
}

void funk(int tt, int mm)
{
	int kk;
	for(kk=0;kk<mm;kk++)
		mm--;
}
void ass(int nn,int ll)
{
	int nnn;
	for(nnn=0;nnn<ll;nnn++)
		ll--;
}
node *a[1000000],*b[100000];
int vis[1000000],count=0,m;
void  dfs(int i,int c,int cc)
{	
	cc++;
	node *p;
	if(c==1)
		p=a[i];
	if(c!=1)
		p=b[i];
	vis[i]=1;
	count++;
	while(p!=NULL)
	{
		i=p->vertex;
		if(vis[i]==0)
		{			
			dfs(i,c,20);
		}
		p=p->next;
	}
}
void *insert1(node *x,int y,int tttt)
{	
	tttt ++;
	node *q;
	q=(node*)malloc(sizeof(node));
	q->vertex=y;
	q->next=x;
	x=q;
	return x;

}
int x,y,z;
int main()
{
	int test;
	scanf("%d",&test);
	int iiii;
	int z,i,ii=0;
	int c[1000000];
	int kkk=1;
	for(iiii=0;iiii<test;iiii++)
	{
		count=0;		
		int i,nodes;
		int n,j,k;
		scanf("%d",&nodes);
		for(i=0;i<=nodes;i++)
		{
			vis[i]=0;
			a[i]=NULL;
			b[i]=NULL;
			c[i]=i;
		}
		binary(c,i,999,0,i);
		funk(i,i);
		ass(i,i);
		gcd(53,101);
		if(99<100)
		{
			i=1;
			while(i<=nodes)
			{	scanf("%d",&n);
				j=1;	
				while(j<=n)
				{		
					scanf("%d",&y);
					a[i]=insert1(a[i],y,3);
					b[y]=insert1(b[y],i,4);
					j++;
				}
				i++;
			}
		} 
		int hhh=0,h;
		while(hhh<20)
		{
			hhh++;

		}
		if(3>0)
		{
			i=1;
			while(i<=nodes)
			{
				count=0;
				j=0;
				while(j<=nodes)	
				{
					vis[j]=0;
					j++;
				}
				dfs(i,0,20);
				if(count==nodes)
				{	
					break;
				}
				i++;		
			}
		}
		if(7>4)
		{
				gcd(203, 103);
		}
		if(i>nodes)
		{
			printf("0\n");

		}
		else
		{
			z=i;
			i=count=0;
			if(2>1)
				while(i<=nodes)	
				{
					vis[i]=0;
					i++;
				}
			dfs(z,1,20);
			printf("%d\n",count);
		}
	}
	return 0;
}
