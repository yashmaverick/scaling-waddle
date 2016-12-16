#include<stdio.h>


int cmpfunc (const void * a, const void * b)
{
	   return ( *(int*)a - *(int*)b );
}


int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n,k,i;
		char str[200];
		scanf("%d %d",&n,&k);
		int val[n];
		for(i=0;i<n;i++)
		{
		scanf("%s",str);
			scanf("%d",&val[i]);
	//		printf("****\n");
		}
		qsort(val,n,sizeof(int),cmpfunc);

//		for(i=0;i<n;i++)
//			printf("%d ",val[i]);
//		printf("\n");


		int first=1,last=n-1,flag=0,sum=0;
		for(i=0;i<n-2;i++)
		{
			if(flag==1)
				break;
			while(first<last)
			{
				sum=val[i]+val[first]+val[last];
				if(sum==k)
				{
					printf("YES\n");
					flag=1;
					break;
				}
				if(sum<=k)
				{
					first++;
				}
				if(sum>=k)
				{
					last--;
				}
			}
			first=i+2;
			last=n-1;
		}
			if(flag==0)
				printf("NO\n");
	}

	return 0;
}


