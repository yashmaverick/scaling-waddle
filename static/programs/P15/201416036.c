#include <stdio.h>
int a[10005];
int find_max(int start , int end)
{
//printf("%d %d\n",start , end);
int i,ret;
ret = 1000000009;
for(i=start;i<end;i++)
{
if(a[i] < ret)
	ret = a[i];
}
return ret;
}
int main()
{
int test;
scanf("%d",&test);
int N , k;
int i;
while(test--)
{
scanf("%d %d",&N , &k);
for(i=0;i<N;i++)
	scanf("%d",&a[i]);
printf("%d",find_max(0 , k));
for(i=1;i<=N-k;i++)
	printf(" %d",find_max(i,i+k));
printf("\n");
}
return 0;	
}