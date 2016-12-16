#include<stdio.h>
int main()
{
	int arr[31];
	arr[0]=1;
	int i;
	for(i=1;i<=30;i++)
	{
		arr[i]=arr[i-1]*2;
	}
//	printf("%d",arr[30]);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		int ans;
		 scanf("%d",&n); 
		 for(i=0;i<30;i++)
		 {
			 if(arr[i]<=n && arr[i+1]-1>=n)
			 {
				 ans=2*i;
			 	if(n<(arr[i]+arr[i+1])/2)
					ans--;
			 }
		 }
		 printf("%d\n",ans);
	}
	return 0;
}
