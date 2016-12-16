#include<stdio.h>
int node,a[100010],maxd;
int func(int beg,int end,int depth,int max,int num)
{
	int i,m1,m2;
	if(num==0)
		return depth;
	if(num==1)
	{
		if(depth>=maxd)
		{
			maxd=depth;
			node=a[beg];
			return maxd;
		}		
	}
	depth++;
	m1=func(beg+1,beg+max-a[beg],depth,max,max-a[beg]);
	m2=func(beg+max-a[beg]+1,beg+num-1,depth,a[beg]-1,num-max+a[beg]-1);
	if(m1<=m2)
		depth=m2;
	else 
		depth=m1;
	return depth;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,depth,beg,end,max;
		scanf("%d",&n);
		for(i=n-1;i>=0;i--)
			scanf("%d",&a[i]);
		node=a[0];
		maxd=0;
		depth=func(0,n-1,0,n,n);
		printf("%d %d\n",node,maxd);
	}
	return 0;
}
