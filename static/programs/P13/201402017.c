#include<stdio.h>
#include<stdlib.h>
struct ans{
	int val;
	int depth;
};
/*int binary(int a[],int low,int high,int x)
  {
  int mid=(low+high)/2;
  if(low>high)
  return -1;
  if(a[mid]<x && a[mid+1]>x)
  return mid+1;
  if(a[mid]>x)
  binary(a,low,mid-1,x);
  if(a[mid]<x)
  binary(a,mid+1,high,x);
  }*/
int search(int a[],int low,int high,int key)
{
	if(low==high)
		return high;
	else if(key>=a[high])
		return high+1;
	else if(key<a[low])
		return low;
	else
	{
		int mid=(low+high)/2;
		if(a[mid]<key)
			return search(a,mid+1,high,key);
		else
			return search(a,low,mid,key);
	}
}
struct ans fun(int a[],int low,int high,int level)
{
	struct ans tree;
	if(low==high)
	{
		tree.depth= level;
		tree.val=a[high];
		return tree;
	}
	if(low>high)
	{
		tree.depth=-1;
		tree.val=100000000;
		return tree;
	}	
	struct ans lnum;
	struct ans rnum;
	lnum=fun(a,low,(search(a,low,high-1,a[high])-1),level+1);
	rnum=fun(a,search(a,low,high-1,a[high]),high-1,level+1);
	if(rnum.depth>lnum.depth)
	{
		return rnum;
	}
	else
	{
		return lnum;
	}
}
int main()
{
	int n,a[100004],i,t;
	scanf("%d",&t);
	while(t--)
	{
	struct ans final;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	final=fun(a,0,n-1,0);
	printf("%d %d\n",final.val,final.depth);
	}
	return 0;
}
