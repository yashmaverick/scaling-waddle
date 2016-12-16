#include<stdio.h>
#include<stdlib.h>
int T[100001],P[100001],Q[100001];
int n,leaf,deep;
void Depth(int a,int d)
{
	int b=Q[a];
	P[a]=1;
	if(d>leaf)
	{
		leaf=d;
		deep=T[a];
	}
	else if(d==leaf&&deep>T[a])
		deep=T[a];
	if(a==n-1 || P[a+1]==1)
		return;
	d++;
	if(b!=-1&&P[b]==0)
		Depth(b,d);
	if(P[a+1]==0)
		Depth(a+1,d);
}		
int main()
{
	int t,i,j,k;
	scanf("%d",&t);
	for(k=0;k<t;k++)
	{
		scanf("%d",&n);
		Q[n-1]=-1;deep=T[0];leaf=0;
		for(i=n-1;i>=0;i--)
		{
			scanf("%d",&T[i]);
			P[i]=0;
		}
		for(i=n-2;i>=0;i--)
		{
			j=i+1;
			if(T[j]<T[i])
				Q[i]=j;
			else
			{
				while(Q[j]!=-1&&T[j]>=T[i])
					j=Q[j];
				if(T[j]>=T[i])
					Q[i]=-1;
				else
					Q[i]=j;
			}		
		}
		Depth(i,i);
		printf("%d %d\n",deep,leaf);
	}
	return 0;
}	
