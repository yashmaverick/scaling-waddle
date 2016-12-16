#include<stdio.h>
int main()
{ int t,flag=0;
	scanf("%d",&t);
	while(t--)
	{ unsigned int n,cnt=0,ans;
		scanf("%u",&n);
		while(n!=1)
		{ 
		//	n=n>>1;
			cnt++;
			if(n==2)
				flag=1;
			n=n>>1;
		//	n=n
		//	else
		//		flag=0;
		}
	//	printf("%u\n",cnt);
		if(flag==1)
		{	ans=(2*cnt)-1;
		        flag=0;
		}
			else
			ans=2*cnt;
		printf("%u\n",ans);
	}
	return 0;
}
