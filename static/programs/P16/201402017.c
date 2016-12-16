#include<stdio.h>
#include<math.h>
int main()
{
  	int a[32]={1};
	int i,n,t;
	for(i=1;i<=30;i++)
	{
		a[i]=pow(2,i);
	}
	scanf("%d",&t);
	while(t--)
	{
	scanf("%d",&n);
	for(i=0;i<=30;i++)
	{
		if(a[i]<=n && a[i+1]>n)
			break;
	}
	//printf("%d",i);
	if(n<=(1.5*a[i])-1)
	{
		printf("%0.0f\n",2*(log2(a[i]))-1);
		//printf("half");
	}
	else{
		printf("%0.0f\n",2*log2(a[i]));}
		//printf("full");}
}
	return 0;
}


