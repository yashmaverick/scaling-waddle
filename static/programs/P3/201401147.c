#include<stdio.h>
#include<stdlib.h>
int main()
{
	int N;
	scanf("%d",&N);
	int i;
	for(i=1;i<=N;i++)
	{
		int n;
		scanf("%d",&n);
		int *a;
		a=malloc(n*sizeof(int));
		int j;
		for(j=0;j<n;j++)
		{scanf("%d",&a[j]);}
		int max_diff=a[1]-a[0];
		int min=a[0];
		for(j=1;j<n;j++)
		{
			if((a[j]-min)>max_diff)
			{
				max_diff=a[j]-min;
			}
			if(a[j]<min)
			{
				min=a[j];
			}
		}
	printf("%d\n",(max_diff<0)?0:max_diff);
	}
return 0;
}
