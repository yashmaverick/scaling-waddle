#include<stdio.h>
int main()
{
	int t,n,min=0,max=0,profit,s,k,l;
	int a[100000];
	scanf("%d",&t);
	for(k=0;k<t;k++)
	{
		profit=0;
		scanf("%d",&n);
		for(l=0;l<n;l++)
		{
			scanf("%d",&a[l]);
			if(l==0){
			min=a[l];
			max=a[l];}
			if(a[l]>max)
			{
				max=a[l];
			}
			if(min>a[l])
			{
				min=a[l];
				max=a[l];
			}
			s=max-min;
			if(s>profit){
				profit=s;
			}
		}
		printf("%d\n",profit);
	}
	return 0;
}
