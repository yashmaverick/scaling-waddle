#include<stdio.h>

int main()
{
	long long int n,j,i;
	long long int res, m, arr[50],q;
	arr[0]=1;	

	for(i=1; i<50; i++)
		arr[i]=arr[i-1]*2;

	scanf("%lld", &n);
	while(n--)
	{

		scanf("%lld", &q);
		if(q==1)
			printf("0\n");
		else
		{
			j=0;
			while(q>=arr[j])
				j++;
			j--;        
			//	j--;

			m=(arr[j+1]+arr[j]-1)/2;

			if(q>m)
				res=2*j;
			else
				res=2*j-1;

			printf("%lld\n",res);
		}
	}

	return 0;
}


