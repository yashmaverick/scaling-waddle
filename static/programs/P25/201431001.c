/*
9 14 
1 2 4
1 8 8
2 8 11
2 3 8
8 9 7
8 7 1
3 4 7
3 9 2
9 7 6
3 6 4
7 6 2
4 5 9
4 6 14
6 5 10
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	long long int src,dest,weight;
}node;

int compare(const void* a, const void* b)
{
    node* a1 = (node*)a;
    node* b1 = (node*)b;
    return (a1->weight > b1->weight);
}

typedef struct subset
{
    long long int parent;
    long long int rank;
}subset;

int find(subset subsets[], int i)
{
    if(subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}
 
void Union(subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
 
    if (subsets[xroot].rank < subsets[yroot].rank)
    {
        subsets[xroot].parent = yroot;
    }
    else if(subsets[xroot].rank > subsets[yroot].rank)
    	subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank=subsets[xroot].rank+1;
    }
}
 
int main()
{
	long long int n,m,i;
	scanf("%lld %lld",&n,&m);

	node *arr = (node *)malloc((m+1) * sizeof(node));
	arr[0].weight=-100000000;
	for(i = 1;i <= m;i++)
	{
		long long int u,v,w;
		scanf("%lld %lld %lld",&u,&v,&w);
		arr[i].src = u;
		arr[i].dest = v;
		arr[i].weight = w;
	}

	qsort(arr,m+1,sizeof(arr[0]),compare);
	
	//printf("Sort--------------------------\n");
	//for(i = 1;i <= m;i++)
	//	printf("%d %d %d\n", arr[i].src,arr[i].dest,arr[i].weight);
	
	subset *subsets = (subset*)malloc((n+1) * sizeof(subset));
 	long long int *visited = (long long int *)malloc((n+1) * sizeof(long long int));
 	memset(visited,0,sizeof(visited));
 	long long int v;
    for (v = 1; v <= n; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    //printf("Edge Chosen-------------------\n");
	long long int sum = 0,e=0;
	for(i = 1;i<=m;i++)
	{
		long long int x = find(subsets, arr[i].src);
        long long int y = find(subsets, arr[i].dest);
 		if(x != y)
		{
			e++;
			visited[arr[i].src]=1;
			visited[arr[i].dest]=1;
	//		printf("%d %d %d\n", arr[i].src,arr[i].dest,arr[i].weight);
			sum += arr[i].weight;
			Union(subsets,x,y);
		}
		//printf("%lld\n", sum);
	}
	if(e==n-1)
		printf("%lld\n",sum);
	else
		printf("-1\n");
	return 0;
}
