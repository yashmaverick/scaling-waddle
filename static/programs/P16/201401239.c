#include<stdio.h>
#include<math.h>
int main()
{
	int x,y;
	scanf("%d",&y);
	for(x=0;x<y;x++)
	{
		int n,i;
		scanf("%d",&n);
		i=0;
		while(pow(2,i)<=n)
		{
			i++;
		}
		int p,ans;
		p=i;
		if(n<(pow(2,p)+pow(2,p-1))/2 && n>1)
			ans=2*(p-1)-1;
		else
			ans=2*(p-1);
		printf("%d\n",ans);
	}
	return 0;
}






