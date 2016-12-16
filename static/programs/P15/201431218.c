#include<stdio.h>
int min(int a,int b)
{
	if(a<b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void print(int i, int n, int k, int mini)
{
		if(i==n-k)
		printf("%d",mini);
		else
		printf("%d ",mini);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t)
	{
		int n,k,i,j,mini;
		scanf("%d%d",&n,&k);
		int Arr[n+5];
		for(i=0;i<n;i++)
		{
			scanf("%d",&Arr[i]);
		}
		int minindex=0;
		mini=Arr[0];
		for(i=0;i<k;i++)
		{
			if(Arr[i]<mini)
				mini=Arr[i];
			minindex=i;
		}
		if(n==k)
		{
			printf("%d",mini);
		}
		else
			printf("%d ",mini);
		for(i=1;i<n-k+1;i++)
		{
			if(mini<=Arr[i])
			{	
				minindex=i;
				mini=Arr[i];
				for(j=i;j<i+k;j++)
				{
					if(min(Arr[j],mini))
					{
						mini=Arr[j];
						minindex=j;
					}
				}
				print(i,n,k,mini);
			}
			else if(mini>Arr[i])
			{
				mini=Arr[i];
				minindex=i;
				print(i,n,k,mini);
			}
		}
		printf("\n");
		t--;
	}
	return 0;
}
