#include<stdio.h>
int depth=0,val;
void dm(int ar[],int i,int j,int cur)
{
//	printf("*%d %d %d*\n",i,j,cur);
	if(i>j)
		return;
	if(i==j)
	{
		if(cur>depth)
		{
			depth=cur;
			val=ar[i];
		}
		return;
	}
	int st=i,en=j,k;
	if(ar[en-1]<ar[j])
		dm(ar,i,j-1,cur+1);
	else if(ar[st]>ar[j])
		dm(ar,i,j-1,cur+1);
	else
	{
		while(1)
		{
			if(st>en)
				break;
			if(ar[(st+en)/2]<=ar[j] && ar[(st+en)/2+1]>ar[j] && (st+en)/2+1<j)
			{
				k=(st+en)/2;
				dm(ar,i,k,cur+1);
				dm(ar,k+1,j-1,cur+1);
				break;
			}
			else if(ar[(st+en)/2]<=ar[j])
				st=(st+en)/2+1;
			else if(ar[(st+en)/2]>ar[j])
				en=(st+en)/2-1;
		}
	}
	return;
}
int main()
{
	int t,n,ar[100000],i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		depth=0;
		val=0;
		for(i=0;i<n;i++)
			scanf("%d",&ar[i]);
		dm(ar,0,n-1,0);
		printf("%d %d\n",val,depth);
	}
	return 0;
}
		
