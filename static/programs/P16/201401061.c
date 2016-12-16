#include<stdio.h>
#include<math.h>
int main()
{
	int i,n,j=0,m,x,k,f;
	scanf("%d",&n);
	while(j<n)
	{
		m=-1;
		f=1;
		scanf("%d",&x);
		k=x;
		while(k)
		{
			k=k>>1;
			m++;
                        f*=2;
		}
		f/=2;
		//printf("%d",m);
		if(x<(f/2+f))
			printf("%d\n",2*m-1);
		else
			printf("%d\n",2*m);
		j++;
	}
	return 0;
}
