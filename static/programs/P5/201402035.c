#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}


int main()
{
	int t,i,a[100000],n,k,l,r,flag;
	char c[100000];

	scanf("%d",&t);
	while(t--)
	{	
		flag=0;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%s%d",c,&a[i]);
		}

		qsort(a,n,sizeof(int),compare);

	for(i=0;i<n;i++)
		{
			l=i+1;
			r=n-1;

			while(r>l)
			{
				if((a[i]+a[l]+a[r])==k)
				{
					flag=1;
						break;
				}
				else if(a[i]+a[l]+a[r]<k)
					l++;

				else
					r--;
			}
			if(flag==1)
				break;
		}
		if(flag==1)
			printf("YES\n");

		else
		printf("NO\n");

	}
	return 0;
}
