#include<stdio.h>
int main()
{
	int n,i,q;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int t,p,r,l,n,ans;
		t=1;
		l=0;
		scanf("%d",&q);
		p=q;
		while(t!=0)
		{
			l=l+1;
			if(p==1)
			{
				ans=0;
				break;
			}
			if(p==2)
			{
				ans=2*l-1;
				break;
			}
			else if(p==3)
			{
				ans=2*l;
				break;
			}
			p=q/2;
			q=p;
		}
		printf("%d\n",ans);
	}
	return 0;
}
