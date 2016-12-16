#include<stdio.h>
int main()
{
	int n,ans,temp,index,num;
	scanf("%d",&num);
	while(num--)
	{
	temp=1;
	ans=0;
	scanf("%d",&n);
	for(index=1;index<n;)
	{
		index=(2*index)+1;
		ans++;
		temp=2*temp;
	}
//	printf("%d\n",ans);
//	printf("%d %d\n",index,temp);
	if((index+temp)/2>=n && index!=n)
		printf("%d\n",2*ans-1);
	else if((index+temp)/2<n && index!=n)
		printf("%d\n",2*ans);
	else if(index==n)
		printf("%d\n",2*ans);
	}
	return 0;
}
