#include<stdio.h>
#include<stdlib.h>

int P[100000];
int I[100000];
int pos[100000];
int n;


int lca(int a,int b)
{
	if(a==b)
		return a;
	int i,j;
	for(i=0;i<n;i++)
		for(j = pos[a];j<=pos[b];j++)
			if(P[i] == I[j])
				return P[i];
}
int main()
{
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
		scanf("%d",P+i);
	for(i=0;i<n;i++)
	{
		scanf("%d",I+i);
		pos[I[i]]=i;
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if(pos[a] > pos[b])
		{
			int temp = a;
			a = b;
			b = temp;
		}
		printf("%d\n",lca(a,b));
	}


	return 0;
}
