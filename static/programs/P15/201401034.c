#include<stdio.h>
#include<stdlib.h>

//Segment Tree consisting of minimums

int min(int a, int b)
{
	if(b<a)
		return b;
	else
		return a;
}

int mintree[50000]; //The tree you construct
int val[50000]; //Given array

int maketree(int start, int end, int index)
{
	if(start==end)
	{
		mintree[index]=val[start];
		return mintree[index];
	}
	else
	{
	 	mintree[index]=min(maketree(start,(start+end)/2,index*2+1),maketree((start+end)/2+1,end,index*2+2));
		return mintree[index];
	}
}

int rangemin(int start, int end, int fromwhere, int tillwhere, int index)
{
	if(fromwhere>end || tillwhere<start)
		return 1000000001;
	else if(fromwhere<=start && tillwhere>=end)
		return mintree[index];
	else
		return min(rangemin(start,(start+end)/2,fromwhere,tillwhere,index*2+1),rangemin((start+end)/2+1,end,fromwhere,tillwhere,index*2+2));

}

int changeval(int start, int end, int pos, int valtoadd, int index)
{
	if(pos>=start && pos<=end)
	{
		if(start!=end)
			mintree[index]=min(changeval(start,(start+end)/2,pos,valtoadd,index*2+1),changeval((start+end)/2+1,end,pos,valtoadd,index*2+2));
		else
			mintree[index]+=valtoadd;
		return mintree[index];
	}
	if(pos<start || pos>end) 
		return mintree[index];
}

int main()
{
	int i,j,k,a,b,c,n,m,tc;
	scanf("%d", &tc);
	for(m=0;m<tc;m++)
	{
		for(i=0;i<50000;i++)
		{
			val[i]=-1;
			mintree[i]=-1;
		}
		scanf("%d%d", &n, &k);
		for(j=0;j<n;j++)
			scanf("%d", &val[j]);
		maketree(0,n-1,0);
		for(i=0;i<n-k;i++)
		{
			printf("%d ", rangemin(0,n-1,i,i+k-1,0));
		}
		printf("%d", rangemin(0,n-1,n-k,n-1,0));
		printf("\n");
	}
	return 0;
}
