#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int i ;
#define ini(deci) scanf("%d" , &deci)
#define inll(lldeci) scanf("%lld" , &lldeci)
#define instr(str) scanf(" %s" , str)
#define outi(deci) printf("%d\n" , deci)
#define outll(lldeci) printf("%lld\n" , lldeci)
#define outstr(str) printf("%s\n" , str)
#define loop(initial , final , jump) for(i=initial ; i<final ; i=i+jump)
#define iter(end) loop(0 , end , 1)
#define max(a , b) return ((a >= b)? a: b)
int g_max=0;
int v_max=0;
struct Adjnode 
{
	int dest;
	struct Adjnode* next;
};
#define noi 1000001
typedef struct Adjnode list;

list* vec[noi];
int visited[noi];

void initialize()
{
	int j;
	for(j=0 ; j<noi; j++)
	{
		vec[j]= NULL;
		visited[j]=0;
	}
	g_max=0;
	v_max=0;
}

list* newnode(int dest)
{
	list * new = (list*)malloc(sizeof(list));
	new->dest = dest;
	new->next = NULL;
	return new;
}

void addedge(int src , int dest)
{
	list* new = newnode(dest);
	new->next = vec[src];
	vec[src] = new;

	list* new1 = newnode(src);
	new1->next = vec[dest];
	vec[dest]= new1;
}

void dfs(int src,int temp)
{
	visited[src]=1;
	list * head=vec[src];
	if(temp>g_max)
	{
		g_max=temp;
		v_max=src;
	}
	while(head!=NULL)
	{
		if(visited[head->dest]!=1)
			dfs(head->dest,temp+1);
		head=head->next;
	}
}

int main()
{
	int test;
	int t , n1 , n2;
	ini(test);
	while(test--)
	{
		ini(t);
		t--;
		initialize();
		while(t--)
		{
			ini(n1);
			ini(n2);
			addedge(n1 , n2);
		}
		dfs(1,1);
		int k;
		for(k=0 ; k<noi; k++)
			visited[k]=0;
		int b_max=g_max;
		g_max=0;
		dfs(v_max,1);
		if(b_max>g_max)
			outi(b_max);
		else
			outi(g_max);
	}
	return 0;
}
