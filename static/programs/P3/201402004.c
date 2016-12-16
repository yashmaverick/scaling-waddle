#include <stdio.h>
#include <stdlib.h>

#define gc getchar_unlocked
int ascanf() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}

#define max(a,b) a>b?a:b

int n,a[100000],i,t,ans,mn,mx;

int main(void) {
	scanf("%d",&t);
	while(t--)
	{
		n=ascanf();
		for(i=0;i<n;i++)
		{
			a[i]=ascanf();
			//printf("%d ",a[i]);
		}
		mn=mx=a[0];
		ans=0;
		for(i=1;i<n;i++)
		{
			if(a[i]>mx){mx=a[i];}
			if(a[i]<mn)
			{
				ans=max(ans,mx-mn);
				//printf("%d %d\n",mx,mn);
				mn=mx=a[i];
			}
			ans=max(ans,mx-mn);
		}
		printf("%d\n",ans);
	}
	return 0;
}

