#include<stdio.h>
int a[1005];
int sort(int m,int n)
{
	int wall=m,pivot=n,temp,i;
	while(wall!=pivot)
	{
		if(a[wall]<=a[pivot])
			wall++;
		else
		{
			temp=a[wall];
			a[wall]=a[pivot-1];
			a[pivot-1]=a[pivot];
			a[pivot]=temp;
			pivot--;
		}
	}
	if(wall-1>m)
		sort(m,wall-1);
	if(n>wall+1)
		sort(wall+1,n);
}
int main()
{
	int t;
	scanf("%d",&t);
	for(;t>0;t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		int i;
		char c;
		for(i=0;i<n;i++)
		{
			getchar();
			c=getchar();
			while(c!=' ')
				c=getchar();
			scanf("%d",&a[i]);
		}
		sort(0,n-1);
		int y=0;
		for(i=0;i<n-2;i++)
		{
			int l=i+1,m=n-1;
			while(l<m)
			{
				if(a[i]+a[l]+a[m]==k)
				{
					y=1;
					break ;
				}
				else if(a[i]+a[l]+a[m]<k)
					l++;
				else if(a[i]+a[l]+a[m]>k)
					m--;
			}
			if(y==1)
				break ;
		}
		if(y==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
