#include <stdio.h>

int main()
{
	int n,q,d,k,ans;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&q);
		if(q==1)
		{
			printf("0\n");
			continue;
		}
		d=0; k=1;
		while(1)
		{
			k*=2;
			if(k>q) break;
			d++;
		}
		ans=2*d;
		if(q<k-k/4) ans--;
		printf("%d\n",ans);
	}
	return 0;
}