#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,temp,bit=0;
		scanf("%d",&n);
		temp=n;
		while(temp)
		{
			temp=temp/2;
			bit++;
		}
		int ans=pow(2,bit-1);
		ans+=ans/2;
		if(n<ans)
			printf("%d\n",2*bit-3);
		else
			printf("%d\n",2*bit-2);
	}
	return 0;
}
