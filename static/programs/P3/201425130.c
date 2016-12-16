#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,x,a[100100],p,max=0,k=0,i=0,j,var=0;
		scanf("%lld",&n);
		for(j=0;j<n;j++)
		{

			scanf("%lld",&a[j]);
		}
		for(i=1;i<n;i++)
		{
			k=((a[n-i])-(a[n-i-1]));
			if(k>0)
			{
			 	if(k>max) 
				{
				max=k;
				}
			swap(&a[n-i],&a[n-i-1]);		
			}	
		}
		if(max>=0)
			printf("%lld\n",max);
		else

			printf("0\n");
	}
	return 0;
}
int swap(int *l,int *m)
{
	int var;
	var=*l;
	*l=*m;;
	*m=var;
}
