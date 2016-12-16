#include<stdio.h>
int f(int mine, int maxdiff, int a[],int n)
{
int j;
for(j=0;j<n;j++)
{
    int diff=a[j]-mine;
    if(diff>maxdiff)
	maxdiff=diff;
    if(a[j]<mine)
	mine=a[j];
}
return maxdiff;
}
int main()
{
    int a[100000];
    int test,q;
    scanf("%d",&test);
    for(q=0;q<test;q++)
    {
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
	scanf("%d",&a[i]);
    }
    int mine=a[0];
    int maxdiff=a[1]-a[0];
    int x=f(mine,maxdiff,a,n);
    if(x<0)
	printf("0\n");
    else 
     printf("%d\n",x);
    }
    return 0;
}
