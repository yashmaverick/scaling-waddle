#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int ans;
		if(n==2)
			ans=1;
		else if(n==3)
			ans=2;
		else if(n==1)
			ans=0;
		else{
		int temp=log10(n)/log10(2);
		int r=n-pow(2,temp);
		
		if(r>=pow(2,temp-1))
		ans=2*temp;
		else
			ans=2*temp-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}