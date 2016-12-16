//a program to find the deepest node of a tree given a valid post-order traversal of the tree
//created by dipankar jain

#include<stdio.h>
#include<assert.h>
#include<math.h>
#include<stdlib.h>

#define gi(x) scanf("%d",&x)
#define pi(x) printf("%d ",x)
#define endl printf("\n")
#define tab printf("\t")
#define maxn 100000;

int finddepth(int first,int last,int elements,int maxelement,int depth);

int n,maxdepth,minelement;
int *order;

int main()
{
	int t;
	gi(t);
	while(t--)
	{
		int i,ans2=0;
		gi(n);
		order = (int *)malloc(n*sizeof(int));
		for( i=n-1 ; i>=0 ; i--)
		{
			gi(order[i]);
		}
		maxdepth = -1;
		minelement = order[0];
		ans2 = finddepth(0,n-1,n,n,-1);		
		printf("%d %d",minelement,ans2);
//		pi(maxdepth);
		endl;
	}
	return 0;
}

int finddepth(int first,int last,int elements,int maxelement,int depth)
{
	if(elements == 0)
		return depth;
	++depth;
	if(elements == 1)
	{
		if(depth > maxdepth)
		{
			maxdepth = depth;
			minelement = order[first];
		}
		else if(depth == maxdepth)
			if(order[first] < minelement)
				minelement = order[first];
	}
	int greater,smaller,depth1,depth2;
	greater = maxelement-order[first];
	smaller = elements-(greater+1);
	depth2 = finddepth(first+1,first+greater,greater,maxelement,depth);
	depth1 = finddepth(first+greater+1,last,smaller,(order[first]-1),depth);
	if(depth2 > depth1)
		return depth2;
	else 
		return depth1;
}


