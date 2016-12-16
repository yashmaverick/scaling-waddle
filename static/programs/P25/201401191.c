#include<stdio.h>
#include<stdlib.h>
typedef struct edge edge;
struct edge{
	int v1;
	int v2;
	int weigh;
};
struct edge arr[1001000];
int compare (const void * a, const void * b)
{

	  edge *edgeA = (edge *)a;
	    edge *edgeB = (edge *)b;

	      return ( edgeA->weigh - edgeB->weigh );
}
struct set{
	int val;
	int par;
};
struct set s[1000000];
int root(int);
void combine(int,int);
int ff=0;
int final[1000000];
int main()
{
	int a1,a2,n,m,i,j,k,w;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&a1,&a2,&w);
		arr[i].v1=a1;
		arr[i].v2=a2;
		arr[i].weigh=w;
	}
	qsort(arr, m, sizeof(edge), compare);
//	for(i=0;i<m;i++)
//	{
//		printf("%d ",arr[i].weigh);
//	} 
	for(i=1;i<=m;i++)
	{
		s[i].val=0;
		s[i].par=i;
	}
	int st=0;
	i=0;
	int cd=1;
	int no_edges=0;
	long long int ans=0;
	ff=0;
//	printf("n is:%d\n",n-1);
//	while(cd--)
	while(ff<n-1)
	{
//		printf("ETRFWSF\n");
		if(i>=m)
		{
			st=1;
			break;
		}
		edge tmp=arr[i++];
		int x=root(tmp.v1);
		int y=root(tmp.v2);
		//printf("%d\t%d\n",x,y);
		if(x!=y)
		{
	//		printf("EF\n");
			ff++;
			ans+=(long long int)tmp.weigh;
			combine(x,y);
		}
	}
/*	for(i=0;i<ff;i++)
	{
		ans+=final[i];
	} */
	if(!st)
		printf("%Ld\n",ans);
	else
		printf("-1\n");
	return 0;
}
int root(int z)
{
	if((s[z].par)!=z)
	{
		s[z].par=root(s[z].par); 
	}
	return s[z].par;
}
void combine(int x,int y)
{
	int x1=root(x);
	int y2=root(y);
	if(1)
//	if(s[x1].val>s[y2].val)
	{
		s[y2].par=x1;
	}
/*	else
	{	
		s[x1].par=y2;
	}
	return; */
}
