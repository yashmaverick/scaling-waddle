#include<stdio.h>
int main()
{
	int T,t,n,tmp,d;
	scanf("%d",&T);
	for( t=0 ; t<T ; t++ )
	{
		scanf("%d",&n);
		tmp=1;d=0;
		if( n==1 || n==3 || n==2 )
		{
			if( n==1 )
				d=0;
			else if( n==3 )
				d=2;
			else
				d=1;
			tmp=0;
		}
		while( tmp!=0 )
		{
			n=n/2;
			d++;
			if( n==2 )
			{
				d++;
				tmp=0;
				d=(2*d)-1;
				break;
			}
			else if( n==3 )
			{
				d++;
				tmp=0;
				d=2*d;
				break;
			}
			//printf("%d\n",n);
		}
	printf("%d\n",d);
	}
	return 0;
}
