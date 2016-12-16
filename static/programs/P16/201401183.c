#include<stdio.h>
int main()
{
	int t,n,l,i,result;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		int cnt=0;
		int m=n;
		while(n>0)
		{
			cnt++;
			n=n>>1;
		}
		cnt--;
	//	printf("m=%d\n",m);
//		printf("level=%d\n",cnt);
		int p=1;
		int x=2;
		int c=cnt;
//		printf("c=%d\n",c);
		while(cnt>0)
		{
			if(cnt&1)
				p=p*x;
			x=x*x;
			cnt=cnt>>1;
		}
//		printf("power=%d\n",p);
//		printf("c=%d\n",c);
		if(m-p>=p/2)
			printf("%d\n",2*c);
		if(m-p<p/2)
			printf("%d\n",2*c-1);
	}
	return 0;
}



