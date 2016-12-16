#include<stdio.h>
int A[100005];
int maxdiff(int n)
{
    int i,c=0;
    int maxdiff=0;
    int minno=A[0];
    for(i=1;i<n;i++)
    {
	if((A[i]-minno)>maxdiff)
	{
	    maxdiff=A[i]-minno;
	}
	if(A[i]<minno)
	{
	    minno=A[i];
	}
    }
    return maxdiff;
}
int main()
{
    int t,n,i;
    scanf("%d",&t);
    while(t--)
    {
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	    scanf("%d",&A[i]);
	}
	printf("%d\n",maxdiff(n));
    }
    return 0;
}



