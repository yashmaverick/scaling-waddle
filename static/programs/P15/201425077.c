#include<stdio.h>

int a[1000001];


int find(int i,int k)
{
	int j,ans=i;

	for(j=i;j<k+i;j++)
		if(a[ans]>a[j])
			ans=j;

	return ans;

}

int main()
{

	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n,k,i,ans=0;

		scanf("%d %d",&n,&k);


		for(i=0;i<n;i++)
			scanf("%d",&a[i]);

		for(i=0;i<n-k+1;i++)
		{

			if(i==0 || i > ans)
				ans=find(i,k);

			if(a[i+k-1] < a[ans])
				ans=i+k-1;

			printf("%d",a[ans]);

			if(i!=n-k)
				printf(" ");

		}

		printf("\n");

	}



	return 0;
}
