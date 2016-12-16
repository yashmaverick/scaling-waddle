#include<stdio.h>
int main()
{
	int t,i,n,k,l,no,temp,j,p,q,r,y;
	 int b[1001];
	char a[10002];
	scanf("%d",&t);
	for(j=0;j<t;j++)
	{
		int flag=0;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%s",a);
			scanf("%d",&b[i]);
		}
		for(y=n-2;y>=0;y--)
		{
			for(l=0;l<=y;l++)
			{
				if(b[l]>b[l+1])
				{
					temp=b[l];
					b[l]=b[l+1];
					b[l+1]=temp;
				}
			}
		}
		for(p=0;p<n-2;p++)
		{
			q=p+1;
			r=n-1;
			while(q<r)
			{
				if(b[p]+b[q]+b[r]==k)
				{
					printf("YES\n");
					flag=1;
					break;
				}
				else if(b[p]+b[q]+b[r]<k)
					q++;
				else if(b[p]+b[q]+b[r]>k)
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
