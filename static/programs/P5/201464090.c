#include<stdio.h>
int tmp[1001],a[1001],s[1001];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,i,g,r,k,flag=0,temp,j; 
		scanf("%d%d",&n,&k);
		for(m=0;m<n;m++)
			scanf("%s %d",s,&a[m]);
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
		for(i=0; i< n-2 ;i++)
		{
			g=i+1;
			r=n-1;
			while(g<r)
			{
				if((a[i]+a[g]+a[r])==k)
				{
					flag=1;
					printf("YES\n");
					break;
				}
				if((a[i]+a[g]+a[r]) <k)
					g++;
				else
					r--;
			}
			if(flag==1)
				break;
		}
		if(flag==0)
			printf("NO\n");
	}
	return 0;
}
