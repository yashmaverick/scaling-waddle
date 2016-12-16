#include<stdio.h>
int main()
{
    int tc,i,j,n,k,arr[100000],head,tail,stack[100000];
    scanf("%d",&tc);
    for(i=0;i<tc;i++)
    {
	stack[head]=head=tail=0;
 	scanf("%d%d",&n,&k);
	for(j=0;j<n;j++) 
		scanf("%d",&arr[j]);
	k=(k<=n)?k:n;
	if(!k)
	{
		for(j=0;j<n;j++)
			printf("1000000001 ");
		printf("1000000001\n");
		continue;
	}
	for(j=0;j<k;j++)
	{
		while(head!=tail && arr[j]<=arr[stack[tail-1]])
			tail--;
		stack[tail++]=j;
	}
	for(;j<n;j++)
	{
		printf("%d ",arr[stack[head]]);
		while(head!=tail && stack[head]<=j-k)
			head++;
		while(head!=tail && arr[j]<=arr[stack[tail-1]])
			tail--;
		stack[tail++]=j;
	}
	printf("%d\n",arr[stack[head]]);
    }
    return 0;
}
