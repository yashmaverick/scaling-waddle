#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}
void sort(int a[],int n)
{
	int t,i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
}
int main()
{
	int flag,t,i,x,y,n,k,a[1004];
	char b[100];
	scanf("%d",&t);
	flag=0;
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%s%d",b,&a[i]);
		qsort(a,n,sizeof(int),cmpfunc);
//		for(i=0;i<n;i++)
//			printf("%d ",a[i]);
	//	printf("\n");
		flag=0;
		for(i=0;i<(n-2);i++)
		{
			x=i+1;
			y=n-1;
			while(x<y)
			{
				if((a[i]+a[x]+a[y]==k))
				{
					flag=1;
					break;

				}
				else if((a[i]+a[x]+a[y])<k)
				{
					x++;
					//printf("f");
				}
				else
				{
					y--;
					//printf("t");
				}
			}
			if(flag==1)
				break;
		}
	//	printf("%d %d %d\n",i,x,y);
		if(flag==0)
		printf("NO\n");
		else printf("YES\n");

	}
	/*if(flag==1)	
	  printf("YES\n");
	  else*/
	return 0;
}
