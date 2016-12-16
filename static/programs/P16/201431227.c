#include<stdio.h>
#include<math.h>
int power(int a,int x);
int main()
{
	int t,n,temp,r;
		
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n==1)
			printf("0\n");
		else{
			temp= log2(n);
			r= n-power(2,temp);
			if(r>(power(2,temp-1)-1))
			{
					temp= 2*temp;
					printf("%d\n",temp);
			}
			else
			{
					temp= (2*temp)-1;
					printf("%d\n", temp);
			}}
		
	}
		return 0;
}
int power(int a,int x)
{	int i;
	int ans=a;
	for(i=1;i<x;i++)
		ans=ans*a;
	if(x==0)
		return 1;
	else
	return ans;
}