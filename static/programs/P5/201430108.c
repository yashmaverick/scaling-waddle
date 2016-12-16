#include<stdio.h>
#include<string.h>
int c;
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int binarysearch(int a[],int m,int n,int j)
{
 int l,u,mid;
l=j,u=n-1;
	while(l<=u)
		{
		 mid=(l+u)/2;
		 if(m==a[mid])
			{
			 c=1;
			 break;
		 }
		 else if(m<a[mid])
			{
			 u=mid-1;
		 }
		 else
			 l=mid+1;
	}
	return mid;
}
	int main()
		{   int n,i,s,f,flag,j,sum,t;
			scanf("%d",&t);
			while(t--)
			{
				flag=0,c=0;
			int in[100001];
			char night[10000];
			scanf("%d%d",&n,&s);
			for(i=0;i<n;i++)
				scanf("%s%d",night,&in[i]);
			qsort(in,n,sizeof(int), cmpfunc);
			for(i=0;i<n;i++)
			{
				for(j=i+1;j<n;j++)
				{
					sum=in[i]+in[j];
					//if(s>=sum)
					f=binarysearch(in,(s-sum),n,j+1);
					if(c==1)
					{
						flag=1;
						break;
					}
				}
				if(flag==1)
				{
					printf("YES\n");
					 break;
				}
				}
				if(flag!=1)
					printf("NO\n");
			}

			
			return 0;
		}