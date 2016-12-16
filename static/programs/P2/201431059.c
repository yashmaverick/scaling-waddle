#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define MAX 100010

int P[MAX],Q[MAX],R[MAX];

int search(int start,int end,int A[],int elem,int state)
{
	if(start==end)
	{
		//printf("hello\n");
		if(A[start]==elem)
			return start;
		else if(A[start]<elem)
			return (state==0?-1:start);
		else if(A[start]>elem)
			return (state==0?start:-1);
	}

	if(start == end-1)
	{
		if(A[start]==elem)
			return start;
		else if(A[end]==elem)
			return end;
		else if(A[start]<elem && elem<A[end])
			return (state==0?end:start);
		else if(A[end]<elem)
			return (state==0?-1:end);
		else if(A[start]>elem)
			return (state==0?start:-1);
	}
	int mid = start + (end-start)/2;
	if(A[mid]>elem)
		return search(start,mid,A,elem,state);
	else if(A[mid]<elem)
		return search(mid,end,A,elem,state);
	else if(A[mid]==elem && state == 0)
		return search(start,mid,A,elem,state);
	else if(A[mid]==elem && state == 1)
		return search(mid,end,A,elem,state);
}


int main()
{
	int t;
	scanf("%d",&t);
	/*int i;
	for(i=0;i<t;i++)
		scanf("%d",P+i);
	while(1)
	{
		int elem,state;
		scanf("%d %d",&elem,&state);
		int pos = search(0,t-1,P,elem,state);
		printf("Ans : %d\n",pos+1);

	}
	*/
	
	while(t--)
	{
		int p,q,r,i;
		scanf("%d",&p);
		for(i=0;i<p;i++)
			scanf("%d",P+i);
		scanf("%d",&q);
		for(i=0;i<q;i++)
			scanf("%d",Q+i);
		scanf("%d",&r);
		for(i=0;i<r;i++)
			scanf("%d",R+i);
		long long int ans=0;

		for(i=0;i<q;i++)
		{
			int Ppos = -1;
			int Rpos = -1;
			if(i<p)
				Ppos = search(0,i,P,Q[i],1);
			else
				Ppos = search(0,p-1,P,Q[i],1);

			if(i<r)
				Rpos = search(i,r-1,R,Q[i],0);
			//printf("%d | %d\n",Ppos,Rpos);
			if(!(Ppos==-1 || Rpos==-1))
				ans+=((long long int)(Ppos+1)*(long long int)(r-Rpos));
		}
		printf("%lld\n",ans);
	}


	return 0;
}
