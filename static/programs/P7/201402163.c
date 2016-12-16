#include<stdio.h>
int main()
{
	int c;
//	scanf("%lld",&n);
	long long int a[1000000],b[1000001],i,j,k,l,m;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%lld",&m);
		i=0;
		k=10000001;
		while(i<m)
		{
			scanf("%lld",&a[i]);
		//	i++;
			if(a[i]<k)
			{
				k=a[i];
			}
			i++;

		}
		i=0;
		while(i<m)
		{
			a[i]=a[i]-k;
			i++;
		}
		
		i=0;
		while(i<1000001)
		{
			b[i]=0;
			i++;
			//printf("*");
		}
		i=0;

		while(i<m)
		{

	//		if(a[i]>=0)
	//		{
				b[a[i]]++;
	//		}
	//		else
	//		{
	//			b[1000000+a[i]]++;
	//		}
	//		printf("*");

			i++;

		}
		i=0;
		l=0;
		while(i<1000001)
		{
			if(b[i]>1)
			{
				l=l+((b[i])*(b[i]-1))/2;
			}
			//printf("*");

			i++;
		}
		printf("%lld\n",l);


	}
	return 0;
}
