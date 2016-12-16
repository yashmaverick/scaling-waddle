#include <stdio.h>

int main()
{
	long long int i,j,n,a[100001],s[100001],min[100001],max[100001],sp;
	long long int area,maxa;

	scanf("%lld",&n);

	while(n!=0)
	{
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			//s[i]=min[i]=max[i]=0;
		}

		sp=-1;
		//printf("hello\n");

		for(i=0;i<n;i++)
		{
			//printf("hi\n");
			while(sp>-1)
			{
				if(a[s[sp]] < a[i] )
				{
					min[i]=s[sp];
					break;
				}
				if(a[s[sp]] >= a[i])
					sp--;
			}
			if(sp==-1)
			{
				min[i]=-1;
			}
			sp++;
			s[sp]=i;

		}

		sp=-1;

		for(i=n-1;i>=0;i--)
		{

			while(sp>-1)
			{
				if(a[s[sp]] < a[i] )
				{
					max[i]=s[sp];
					break;
				}
				if(a[s[sp]] >= a[i])
					sp--;
			}
			if(sp==-1)
			{
				max[i]=n;
			}
			sp++;
			s[sp]=i;
		}

		/*for(i=0;i<n;i++)
		  printf("%d ",min[i]);
		  printf("\n");
		  for(i=0;i<n;i++)
		  printf("%d ",max[i]);
		  printf("\n");*/

		maxa=0;

		for(i=0;i<n;i++)
		{
			area=(max[i]-min[i]-1)*a[i];
			//printf("%d ",area);
			if(maxa < area)
				maxa=area;
		}
		//printf("\n");

		printf("%lld\n",maxa);

		scanf("%lld",&n);
	}
	return 0;
}
