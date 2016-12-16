#include<stdio.h>
int a[1002],flag;
int main()
{
	int m,t;
	scanf("%d",&t);
	char g[10001];
	int i,n,k,q,r,s,j,temp;
	for(m=0;m<t;m++)
	{
		flag=0;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%s ",g);
			scanf("%d",&a[i]);
		}
		for (i = 1; i < n; i++) 
		{
			for (j = 0; j < n - 1; j++) 
			{
				if (a[j] > a[j + 1]) 
				{
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
		for(q=0;q<n-2;q++)
		{
			r=q+1;
			s=n-1;
			while(r<s)
			{
				if(a[r]+a[s]+a[q]==k)
				{
					flag=1;
					printf("YES\n");
					break;
				}
				else if (a[r]+a[s]+a[q]>k)
					s--;
				else 
					r++;

			}
			if(flag==1)
				break;
		}
		if(flag!=1)
			printf("NO\n");
	}
	return 0;
} 
