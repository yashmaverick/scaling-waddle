#include <stdio.h>
#include <stdlib.h>
#define E struct E
#define MAX 100007
#define cL struct cL
#define s(n) scanf("%lld",&n)
long long compo[MAX], MST,noOfEdges;
typedef int (*compfn)(const void*, const void*);

E
{
	long long v1,v2,w;
};

cL
{
	long long val,size,w;
	cL *next;
} *CO[MAX];

void init_compo(long long N)
{
	long long i;
	for(i=1;i<=N;i++)
	{
		compo[i]=i;
		//CO[i]->val=i;
	}

}

long long Size(cL *N)
{
	if(N==NULL)
		return 0;
	else
		return N->size;
}

cL *insert(cL *N,long long v)
{
	cL *t=(cL*)malloc(sizeof(cL));
	t->val=v;
	t->size=Size(N)+1;
	t->next=N;
	N=t;
	return N;
}

void merge(long long a,long long b)
{
	//printf("HEllo merge\n");
	//printf("a=%lld, b=%lld\n",a,b);
	cL *T=CO[b];
	compo[b]=a;
	CO[a]=insert(CO[a],b);
	while(T!=NULL)
	{
		compo[T->val]=a;
		CO[a]=insert(CO[a],T->val);
		T=T->next;

	}	

}

int comp(E *a,E *b)
{
	//const E *a=p1;
	//const E *b=p2;
	if((a->w)<(b->w))
		return -1;
	else if((a->w)>(b->w))
		return 1;
	else return 0;
}	

void find_MST_Sum(E A[],long long N)
{
	long long i;
	for(i=1;i<=N;i++)
	{
		long long a,b;
		a=A[i].v1;
		b=A[i].v2;
		if(compo[a]!=compo[b])
		{
			MST+=A[i].w;
			noOfEdges++;
			//printf("MST: %lld\n",MST);
			long long x=compo[a],y=compo[b];
			long long max,min;
			//printf("Size CO x:%lld  y:%lld\n",Size(CO[x]),Size(CO[y]));
			if(Size(CO[x])>Size(CO[y]))
				{max=x;min=y;}
			else
				{max=y;min=x;}
		merge(max,min);
		}
		//compo[b]=compo[a];//merge cLs here
	}
}

void print_edge(E A[], long long n)
{
	long long i;
	for(i=1;i<=n;i++)
		printf("%lld,%lld; Weight:%lld\n",A[i].v1,A[i].v2,A[i].w);
}


long long main()
{
	E edge[MAX];
	long long N,M,a,i,j,k;
	s(N);s(M);
	for(a=1;a<=M;a++)
	{
		s(i);s(j);s(k);
		edge[a].v1=i;
		edge[a].v2=j;
		edge[a].w=k;			
	}
	init_compo(N);
	qsort((void*)&edge,M+1,sizeof(E),(compfn)comp);
	//print_edge(edge,M);
	MST=0;
	find_MST_Sum(edge,M);
	if(noOfEdges==N-1)
		printf("%lld\n",MST);
	else
		printf("-1\n");
	return 0;
}