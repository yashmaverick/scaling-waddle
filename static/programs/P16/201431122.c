#include<stdio.h>
int pw(int p)
{
	int res=1;
	if(p<=0)
		return res;
	else
		while(p--)
			res *=2;
	return res;
}

int main()
{
	int k,t,a,i,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&a);
			i=0;
		while(1)
		{
			k=pw(i);

			if(a<k)
			break;
			else
				i++;

		}
		if(a<k/2+k/4)
			ans=2*(i-1)-1;
		else
			ans=2*(i-1);
		printf("%d\n",ans);
	}
return 0;
}
