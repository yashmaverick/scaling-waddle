#include<stdio.h>
int main()
{
	int t,n,q,r,s;
	long long int p;
	scanf("%d",&t);
	while(t--)
	{
		p=1;
		int cnt=-1;
		scanf("%d",&n);
		q=n+1;
		while(q>0)
		{
			q=(q>>1);
			p=(p<<1);
			cnt++;
		}
		s=p;
			p=(p>>1);
			cnt--;
			s=(s-p)/2;
		r=n+1-p;
//			printf("r:%d cnt:%d\n",r,cnt);
		if(r==0)
			printf("%d\n",2*cnt);
		else if(r<=s)
			printf("%d\n",(2*cnt)+1);
		else
			printf("%d\n",(2*cnt)+2);
	}
	return 0;
}
