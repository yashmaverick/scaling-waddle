#include<stdio.h>
#include<stdlib.h>
int cmpfunc(const void * a,const void* b)
{
	return(*(int*)a-*(int*)b);
}
int main()
{
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		char b[1000];
		int n,sum;
		scanf("%d %d",&n,&sum);
		int a[n],i,j,k,flag=0,temp;
		for(i=0;i<n;i++)
		{
			scanf("%s %d",b,&a[i]);
		}
		qsort(a,n,sizeof(int),cmpfunc);
//		for(i=0;i<n;i++) printf("%d ",a[i]);
		for(i=0;i<=n-3;i++)
		{
			j=i+1;k=n-1;
			while(j<k)
			{

				temp=a[i]+a[j]+a[k];
				if(temp==sum)
				{
			//		printf("%d %d %d\n",i,j,k);
					flag=1; printf("YES\n");
					break;
				}
				else if(temp<sum) j++;
				else k--;
			} 
			if(flag==1) break;
		}
		if(flag==0) {printf("NO\n");}
	}
	return 0;
}
