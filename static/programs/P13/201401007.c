#include<stdio.h>
typedef struct log{
    int nu;
    int level;
}name;
name A[100005];
int l[100005];
int B[100005];
int max;
int minl;
void func1(int first,int size)
{
    B[0]=-1;
    int last=1,m=B[last-1],i;
    B[last]=first;
    last++;
    l[first]=m;
    for(i=1;i<size;i++)
    {
	m=B[last-1];
	if(A[i].nu>A[m].nu)
	{
	    l[i]=m;
	    B[last]=i;
	    last++;
	}
	else
	{
	    while(A[i].nu<=A[m].nu&&last>1)
	    {
		last--;
		m=B[last-1];
	    }
	    m=B[last-1];
	    B[last]=i;
	    last++;
	    l[i]=m;
	}
    }
}
void partition(int root,int end,int t)
{ 
    int i;
    t++;
    if(root<end)
    {
	return ;
    }
    if(root==end)
    {
	A[root].level=t;
	if(t>=max)
	{
	    minl=A[root].nu;
	    max=t;
	    if(t==max)
	    {
		if(A[root].nu<minl)
		{
		    minl=A[root].nu;
		}
	    }
	}
	return ;
    }
    /*    for(i=root-1;i>=end;i--)
	  {
	  if(A[i].nu<A[root].nu)
	  {
	  break;
	  }
	  }*/
    i=l[root];
    A[root].level=t;
    if((root-1)>=(i+1))
    {
	partition(root-1,i+1,t);
    }
    if(i>=end)
    {
	partition(i,end,t);
    }
}
int main()
{
    int n,i,t;
    scanf("%d",&t);
    while(t--)
    {
	max=0;
	minl=100005;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	    scanf("%d",&A[i].nu);
	}
	func1(0,n);
	partition(n-1,0,0);
	/*	    for(i=0;i<n;i++)
		    {
		    printf("%d=%d\n",A[i].nu,A[i].level);
		    }*/
	printf("%d %d\n",minl,max-1);
    }
    return 0;
}
