#include<stdio.h>
#include<stdlib.h>
struct mst
{
	int weight;
	int v1;
	int v2;

};
int ind=0;
struct mst weights[100010];
long long int parray[100010];
int comp(const void *p, const void *q)
{
	int m,n;
	m = ((struct mst *)p)->weight;
	n = ((struct mst *)q)->weight;
	return m-n;
}
void addedge(int v1, int v2, int w)
{
	weights[ind].weight = w;
	weights[ind].v1 = v1;
	weights[ind].v2 = v2;
	parray[v1] = v1;
	parray[v2] = v2;
	ind++;
}
int parent(int i)
{
	if(parray[i] == i)
		return i;
	return parent(parray[i]);
}

int rank[100010];

void findrank(long long int parray[],int rank[],int a,int b)
{
        int parenta=parent(a);
        int parentb=parent(b);
        if(rank[parenta]<rank[parentb])
                parray[parenta]=parentb;
        else if(rank[parentb]<rank[parenta])
                parray[parentb]=parenta;
        else
        {
                parray[parentb]=parenta;
                rank[parenta]++;
        }
}


int main()
{
	struct mst* edge;
	int i;
	long long int N,M,sum=0,x,y,w;
	long long int count=0;
	scanf("%lld %lld",&N,&M);
//	int parray[N];
/*	for(i=1;i<=N;i++)
	{
		parray[i] = i;
	}*/
	for(i=0;i<M;i++)
	{
		scanf("%lld %lld %lld",&x,&y,&w);
		addedge(x,y,w);
	}
    for(i=0;i<N;i++)
            rank[i]=0;
	qsort((void*)weights,M,sizeof(weights[0]),comp);
	for(i=0;i<M;i++)
	{
		if( parent(parray[weights[i].v1]) != parent(parray[weights[i].v2]) )
		{
			//parray[weights[i].v2] = parray[weights[i].v1];
			sum = sum + weights[i].weight;
            findrank(parray,rank,parray[weights[i].v1],parray[weights[i].v2]);  
			count++;
			if(count == (N-1))
				break;
		}
		if(count < (N-1) && i == (M-1))
			printf("-1\n");
	}
	if(count == (N-1))
		printf("%lld\n",sum);
	return 0;
}
