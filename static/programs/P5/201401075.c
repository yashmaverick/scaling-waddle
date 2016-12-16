#include<stdio.h>
int ar[1000];
int cmpfunc(const void *a,const void *b)
{
	return (*(int *)a - *(int *)b);
}
int main()
{
	int t,n,k,i,j,a,b,c,e,f,answer;
	char ch[1000];
	scanf("%d",&t);
	for(f=0;f<t;f++)
	{
		answer=0;
		scanf("%d%d",&n,&k);
		for(e=0;e<n;e++)
		{
			scanf("%s",ch);
			scanf("%d",&ar[e]);
		}
		qsort(ar,n,sizeof(int),cmpfunc);//correct till here
		for(a=0;a<n;a++)
		{
			for(b=a+1;b<n;b++)
			{
				c=k-ar[a]-ar[b];
				i=b+1;
				j=n-1;
				int ans=0,mid;
//				printf(" %d %d %d ",i,j,c);
				while(i<=j)
				{
					mid=(i+j)/2;
					if(i==j)
					{
						if(ar[mid]==c)
							ans=1;
						break;
					}
			//		printf(" %d %d %d ",i,j,mid);
					if(ar[mid]==c)
					{
						ans=1;
						break;
					}
					if(ar[mid]<c)
						i=mid+1;
					else
						j=mid-1;
				}
//				printf(" %d ",ans);
				if(ans==1)
				{
					answer=1;
					break;
				}
			}
		}
		if(answer==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

			

