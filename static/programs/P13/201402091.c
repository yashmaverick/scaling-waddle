#include<stdio.h>
int min,max;
int minnum(int a,int b)
{
	if(a>b)
		return b;
	else
		return a;
}
int search(int a[],int start,int end,int m)
{	int index,mid;
	while((end-start)>=1)
	{
		if((end-start)==1)
		{
			if(a[start]<m && a[end]>m)
				index=(start+1);
			else
				index=-1;
			break;
		}
		mid=(end+start)/2;
		if(a[mid]>m)
			end=mid;
		else if(a[mid]<m)
			start=mid;
	}
	return index-1;
}
void call(int a[],int start,int end,int dep)
{
	if(end<=start)
	{	if(dep>max)
		{
			max=dep;
			min=a[start];
		}
		else if(dep==max)
			min=minnum(min,a[start]);
//		printf("depth %d\n",dep);
		return;
	}
	if(dep>max)
	{	
		max=dep;
		min=a[end];
	}
	else if(dep==max)
		min=minnum(min,a[end]);
//		printf("depth %d\n",dep);
	int root=a[end];
	int index=search(a,start,end,root);
	if(index!=-2 && index!=(end-1))
	{
		call(a,start,index,dep+1);
		call(a,index+1,end-1,dep+1);
	}
	else if(index==end-1)
	{
		call(a,start,index,dep+1);
	}
	else if(index==-2)
	{	
		call(a,start,end-1,dep+1);
	}
}
int main()
{
	int t,i,n,a[1000007],j;
		scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		for(j=0;j<n;j++)
			scanf("%d",&a[j]);
		min=a[n-1],max=0;
		call(a,0,n-1,0);
		printf("%d %d\n",min,max);
	}
	return 0;
}

