#include <stdio.h>

long long int n,m,ans,i,in1,in2,mcpy;
 
int main()
{
    scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		in1=in2=0;
		scanf("%lld",&m);
		if(m<=1){printf("0\n");continue;}
		mcpy=m;
		while(m!=0)
		{
			in2=in1;
			in1=m&01;
			m=m>>1;
		}
		m=mcpy;
		if(!in2)
		ans=2*(long long int)(log2((double)m))-1;
		else
		ans=2*(long long int)(log2((double)m));
		printf("%lld\n",ans);
	}
	return 0; 
}

