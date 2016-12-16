#include<stdio.h>
#include<math.h>

int main()
{
	int t,i;
	scanf("%d",&t);

	int temp=1,temp1=1,a[35];
	a[0]=1;

	for(i=1;temp<=1000000000;i++)
	{
		temp1*=2;
		temp+=temp1;
		a[i]=temp;
	}
	int en=i-1;

	for(i=0;i<t;i++)
	{
		int x;
		scanf("%d",&x);
		//int start=0,end=en,flag=0,ans,mid;
		int flag=0,ans,j;
		for(j=0;j<=en;j++)
		{
			if(x<=a[j])
			{
			//	printf("j:%d\n",j);
				ans=j;
				if(j!=0)
				{
					int p=(a[j]-a[j-1])/2;
					int q=x-a[j-1];
			//		printf("p:%d q:%d\n",p,q );
					if(q>p) flag=1;
				}
				else {flag=1;}
	
				break;	
			}

		}

		if(flag==1) printf("%d\n",ans*2);
		else printf("%d\n",(ans*2)-1);

	}
	return 0;
}