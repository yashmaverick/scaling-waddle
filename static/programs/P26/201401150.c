#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define s(n) scanf("%d",&n)
#define Node struct Node
#define MAX 10007
int pT100[30],DP4[MAX],primCount=3,listOfDP4[MAX],listCounter=0,visited[MAX];
int Queue[MAX],fr,ba;

void primeTill100()
{
	pT100[0]=2;
	pT100[1]=3;
	pT100[2]=5;
	pT100[3]=7;
	int i;
	for(i=10;i<=101;i++)
		if(i%2!=0 && i%3!=0 && i%5!=0 && i%7!=0)
			pT100[++primCount]=i;
}
int divbyAny(int x)
{
	int i;
	for(i=0;i<=primCount;i++)
		if(x%pT100[i]==0)
			return 0;
	return 1;
}

void Sieve4()
{
	int i;
	for(i=1000;i<=9999;i++)
		if(divbyAny(i)==1)
		{	
			DP4[i]=1;
			listOfDP4[listCounter++]=i;
		}
}

Node
{
	int val,dist;
	Node *next;
} *	G[MAX];
Node *insert(Node *N,int v)
{
	Node *t=(Node*)malloc(sizeof(Node));
	t->val=v;
	t->next=N;
	N=t;
	return N;
}

void addToGraph(int x)
{
	//printf("Add to graph begin\n");
	int f1=x%10,i;
	int U=x-f1,lim1=x-f1+9;
	for(i=U+1;i<=lim1;i+=2)
		if(DP4[i]==1)
		{
			G[x]=insert(G[x],i);
			//printf("f1:%d, U:%d, lim1:%d, i:%d\n",f1,U,lim1,i);
		} 

	int f2=x%100;
	int T=x-f2+f1,lim10=T+90;
	for(i=T;i<=lim10;i+=10)
		if(DP4[i]==1)
		{
			G[x]=insert(G[x],i);
			//printf("f2:%d, T:%d, lim10:%d, i:%d\n",f2,T,lim10,i);
		} 

	int f3=x%1000;
	int H=x-f3+f2,lim100=H+900;
	//printf("f3:%d, H:%d, lim100:%d\n",f3,H,lim100);
	for(i=H;i<=lim100;i+=100)
		if(DP4[i]==1)
		{
			G[x]=insert(G[x],i);
			//printf("f3:%d, H:%d, lim100:%d, i:%d\n",f3,H,lim100,i);
		} 

	int Th=1000+f3;
	int lim1000=Th+8000;
	for(i=Th;i<=lim1000;i+=1000)
		if(DP4[i]==1)
		{
			G[x]=insert(G[x],i);
			//printf(" Th:%d, lim1000:%d, i:%d\n",Th,lim1000,i);
		} 
	//printf("Add to graph end\n");

}

void Graphify()
{
	int i;
	for(i=0;i<listCounter;i++)
		addToGraph(listOfDP4[i]);

}

void Qinit()
{
	fr=ba=-1;
}

void EnQ(int x)
{
	//if(fr-ba==1)
	//	overflow
	if(ba==-1)
		fr=ba=0;
	else if(ba==MAX-1)
		ba=0;
	else
		ba++;
	Queue[ba]=x;
}

int DQ()
{
	//if(fr==-1)
	//	underflow
	int r=Queue[fr];
	if(fr==MAX-1)
		fr=0;
	if(fr==ba)
		fr=ba=-1;
	else
		fr++;
	return r;
}

int isQEmpty()
{
	if(ba==-1)
		return 1;
	return 0;
}

void Gdinit()
{
	int i;
	for(i=0;i<listCounter;i++)
		G[listOfDP4[i]]->dist=INT_MAX;
}

void BFS(int s,int d)
{
	//Gdinit();
	if(s==d)
		printf("0\n");
	else
	{
		visited[s]=1;
		Qinit();
		EnQ(s);
		G[s]->dist=0;
		int distA=0,f=0;
		while(!isQEmpty())
		{
			int k=DQ();
			//printf("k: %d\n",k);
			Node *T=G[k];
			int DD=G[k]->dist;
			while(T!=NULL)
			{
				if(visited[T->val]==0)
				{
					visited[T->val]=1;
					G[T->val]->dist=DD+1;
					//printf("dist: %d\n",T->dist);
					if(T->val==d)
					{
						f=1;distA=G[T->val]->dist;break;
					}
					EnQ(T->val);
				}
				T=T->next;
			}
			if(f==1)
				break;
		}
		if(f==1)
			printf("%d\n",distA);
		else
			printf("Impossible\n");
	}
}

void printSieve()
{
	int i;
	for(i=0;i<listCounter;i++)
		printf("%d\n",listOfDP4[i]);
}

void Vinit()
{
	memset(visited,0,sizeof(visited));
	//int i;
	//for(i=0;i<MAX;i++)
		//visited[i]=0;	
}

int main()
{
	int t,i,n,k,a,b;
	primeTill100();
	Sieve4();
	Graphify();
	//printSieve();
	s(t);
	for(i=0;i<t;i++)
	{
		Qinit();
		s(a);s(b);
		BFS(a,b);
		Vinit();
	}

	return 0;
}