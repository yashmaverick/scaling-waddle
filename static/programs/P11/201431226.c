#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #define gc getchar_unlocked
// fast input methods here not working ??
/*void scan(long long int &x)
{
	register long long int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) 
    {
    	x = (x<<1) + (x<<3) + c - 48;
    }
}*/

/*inline void Scan_f(long long int a)
{
	char c = 0;
	while(c<33)
	//c = fgetc_unlocked(stdin);
	c = getc(stdin);
	a = 0;
	while(c>33)
	{
		a = a*10 + c - '0';
		//c = fgetc_unlocked(stdin);
		c = getc(stdin);
	}
}*/
int main()
{
	long long int a[100005],b[100005],c[100005],n,m,q,r,t,y;
	long long int result;
	scanf("%lld",&n);
	//printf("%lld\n",n);
	while(1)
	{
		result = 0 ;
		if(n==0)
			return 0 ;
		for(m=0;m<n;m++)
		{
			scanf("%lld",&a[m]);
	//		printf("%lld\n",a[m]);
		}
		b[0] = -1 ;
	//	printf("testing\n");
		for(m=1;m<n;m=m+1)
		{
			q=m-1;
			while(q>=0)
			{
				if(a[q]>=a[m])
				{
					q=b[q];
				}
				else
				{ 
					break;
				}
			}
			b[m]=q;
		}
		c[n-1]=n;
	//	printf("testing2\n");
		for(m=n-2;m>=0;m=m-1)
		{
			q = m+1;
			while(q<=n-1)
			{
				if(a[q]>=a[m])
				{
					q=c[q];
				}
				else
				{
				 break;
				}
			}
			c[m]=q;
		}
	//	printf("hello\n");
		for(m=0;m<n;m++)
		{
	//		printf("atyam\n");
			if(((c[m]-1-b[m])*a[m])>result)
			{
				result=(c[m]-b[m]-1)*a[m];
	//			printf("%lld\n",result);
			}
		}
		printf("%lld\n",result);
		scanf("%lld",&n);
	}
	return 0;
}
