#include<stdio.h>
int A[100001],P[100001],S[100001],n,mdepth,dnode;
void fun(int x, int depth)
{
	P[x]=1;
	if(depth>mdepth)
	{
		mdepth=depth;
		dnode=A[x];
	}
	else if(depth==mdepth && dnode>A[x])
		dnode=A[x];
	if(x==n-1 || P[x+1]==1)
		return;
	int y=S[x];
	//while(y<n && A[y]>A[x])
	//	y++;
	if(y!=-1 &&  P[y]==0)
		fun(y,depth+1);
	if(P[x+1]==0)
		fun(x+1,depth+1);
}		
int main()
{
	int t,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%d",&A[n-1]);
		S[n-1]=-1;P[n-1]=0;
		for(i=n-2;i>=0;i--)
		{
			scanf("%d",&A[i]);
			P[i]=0;
			if(A[i+1]<A[i])
				S[i]=i+1;
			else
			{
				j=i+1;
				while(S[j]!=-1 && A[j]>=A[i])
					j=S[j];
				if(A[j]<A[i])
					S[i]=j;
				else
					S[i]=-1;
			}//printf("for i=%d S[]=%d\n",i,S[i]);		
		}
		mdepth=0;
		dnode=A[0];
		fun(0,0);
		printf("%d %d\n",dnode,mdepth);
	}
	return 0;
}	
