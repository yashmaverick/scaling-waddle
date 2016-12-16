#include<stdio.h>
int main()
{
	int t,n,i,j,s[100010],a[100010],d[100010],max,val;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(j=0;j<n;j++)
			scanf("%d",&a[j]);
		s[0]=a[n-1];
		d[a[n-1]]=0;
	//	printf("%d\n",d[s[n-1]]);
		i=0;
		for(j=n-2;j>=0;j--)
		{
			if(i>=0&&a[j]>s[i])
			{
				d[a[j]]=d[s[i]]+1;
				i=i+1;
				s[i]=a[j];
			}
			else
			{
				while(i>=0&&a[j]<s[i])
					i=i-1;
				d[a[j]]=d[s[i+1]]+1;
				i=i+1;
				s[i]=a[j];
			}
		}
		max=0;
		for(j=0;j<n;j++)
		{
//			printf("%d ",d[a[j]]);
			if(d[a[j]]>max)
			{
				max=d[a[j]];
				val=a[j];
			}
		}
//		printf("\n");
		printf("%d %d\n",val,max);
	}
	return 0;
}


