#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
	int val;
	int root;
};
int count;
int binary_search(int a[],int low,int high,int k)
{
	if(low>high)
		return -1;
	int mid=(low+high)/2;
	if(a[mid]<k&&a[mid+1]>k)
		return mid+1;
	else if(a[mid]<k)
		binary_search(a,mid+1,high,k);
	else
		binary_search(a,low,mid-1,k);
}
node* find(int low,int high,int a[])
{

	if(low>high)
	{
		node* def;
		def=(node*)malloc(sizeof(node));
		def->val=-1;
		return def;
	}
	int nest,r,i;
	if(low==high)
	{
		node* def;
		def=(node*)malloc(sizeof(node));
		def->val=0;
		def->root=a[low];
		return def;
	}
	r=binary_search(a,low,high-1,a[high]);
	if(r==-1)
	{
		r=high;
	}
	node* nest1=find(low,r-1,a);
	nest1->val+=1;
	node* nest2=find(r,high-1,a);
	nest2->val+=1;
	if(nest1->val>nest2->val)
	{
		free(nest2);
		return nest1;
	}
	else if(nest1->val==nest2->val)
	{
		if(nest1->root<nest2->root)
			return nest1;
		else return nest2;
	}
	else
	{
		free(nest1);
		return nest2;
	}
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int *a;
		count=0;
		int n,i;
		scanf("%d",&n);
		a=(int*)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		node* r=find(0,n-1,a);
		printf("%d %d\n",r->root,r->val);
		free(r);
		free(a);
	}
	return 0;
}
