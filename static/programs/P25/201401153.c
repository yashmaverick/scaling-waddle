#include<stdio.h>
#include<stdlib.h>

typedef struct ll
{
	struct ll *next;
	long long int data;
	long long int wt;
}node;

node* b[1000001];
long long int a[1000001][2], vis[1000001];
long long int dist[1000001];
long long int i,d,htop[2];

node *inser(long long int u,long long int v,long long int w)
{
	node *tm;
	tm=(node*)malloc(sizeof(node));
	tm->data=v;
	tm->wt=w;
	tm->next=b[u];
	b[u]=tm;
	return b[u];
}

void shuffleup(long long int i)
{
	long long int tmp,tmpo;
	if(i!=0)
	{
		if(a[i][0]<a[i/2][0])
		{
			tmp=a[i][0];
			a[i][0]=a[i/2][0];
			a[i/2][0]=tmp;
			
			tmpo=a[i][1];
			a[i][1]=a[i/2][1];
			a[i/2][1]=tmpo;

		shuffleup(i/2);
		}
	}
}

void insert(long long int x,long long int vertex)
{
	i++;
	a[i][0]=x;
	a[i][1]=vertex;
	shuffleup(i);
}

void shuffledown(long long int j)
{
	long long int temp,tempo;
	if(a[2*j][0]!=-1 && a[2*j+1][0]!=-1)
	{
	if(a[2*j][0] < a[j][0]  || a[2*j+1][0] < a[j][0])
	{
		if(a[2*j][0] < a[2*j+1][0])
		{
			temp=a[2*j][0];
			a[2*j][0]=a[j][0];
			a[j][0]=temp;

			tempo=a[2*j][1];
			a[2*j][1]=a[j][1];
			a[j][1]=tempo;

			shuffledown(2*j);
		}
		else
		{
			temp=a[2*j+1][0];
			a[2*j+1][0]=a[j][0];
			a[j][0]=temp;

			tempo=a[2*j+1][1];
			a[2*j+1][1]=a[j][1];
			a[j][1]=tempo;

			shuffledown(2*j+1);
		}
	}
	}
	else if(a[2*j][0]!=-1 && a[2*j+1][0]==-1)
	{
		if(a[2*j][0] < a[j][0])
		{
			temp=a[2*j][0];
			a[2*j][0]=a[j][0];
			a[j][0]=temp;

			tempo=a[2*j][1];
			a[2*j][1]=a[j][1];
			a[j][1]=tempo;
		}
	}
}
void deletemin()
{
	htop[0]=a[1][0];
	htop[1]=a[1][1];
	a[1][0]=a[i][0];
	a[1][1]=a[i][1];
	a[i][0]=-1;
	i--;
	shuffledown(1);
}

void display()
{
	long long int  k;
	for(k=1;k<=i;k++)
	{
		printf("i %lld val %lld\n",k,a[k][0]);
	}
}

int main()
{
	long long int n,m,u,v,w,q,s,t,count=0;
	for(i=0;i<=1000000;i++)
		a[i][0]=-1;
	i=0;
	scanf("%lld %lld",&n,&m);
	for(q=0;q<=1000000;q++)
	{
		b[q]=NULL;
		vis[q]=0;
	}

	for(q=1;q<=m;q++)
	{
		scanf("%lld %lld %lld",&u,&v,&w);
		b[u]=inser(u,v,w);
		b[v]=inser(v,u,w);
	}

	d=0;
	insert(0,1);
	while(a[1][0]!=-1)
	{
		deletemin();
		if(vis[htop[1]]==0)
		{
			d+=htop[0];
			vis[htop[1]]=1;
			count++;
			while(b[htop[1]]!=NULL)
			{
				insert(b[htop[1]]->wt, b[htop[1]]->data);
				b[htop[1]]=b[htop[1]]->next;
			}
		}
	}
	if(count!=n)
		printf("-1\n");
	else
		printf("%lld\n",d);

	return 0;
}
