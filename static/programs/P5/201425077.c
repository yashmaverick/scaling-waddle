#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
int t,a[100000],n,k,i,j,begin,end,mid,flag,no,l,start;
char str[10000];
scanf("%d",&t);

while(t--)
	{flag=0;
 	scanf("%d %d",&n,&k);

	for(i=0;i<n;i++)
		{
		scanf("%s",str);
		scanf("%d",&a[i]);
		}

	qsort(a, n, sizeof(int), cmpfunc);

	//for(i=0;i<n;i++)
	//	printf("%d",a[i]);
	
	for(i=0;i<n;i++)
		{
		start=i+1; end=n-1;
		while(end>start)
			{
			if(a[i]+a[start]+a[end]==k)
				{flag=1; goto end;}
			else if(a[i]+a[start]+a[end]>k)
				end--;
			else
				start++;	

			}
		}	
	end: ;
	if(flag==1)
		printf("YES\n");
	else
		printf("NO\n");
	}

return 0;
}
