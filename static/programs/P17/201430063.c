#include<stdio.h>
int main()
{

	int n,low=0,i,j;
	scanf("%d",&n);

	int a[n],high=n-1;
	int b[n],flag1=0,flag2=0,flag3=0,u,v;

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	int temp;
	int test;
	scanf("%d",&test);
	while(test--)
	{

	 for(i=0;i<n;i++)
		if(b[i]==a[0])
			temp=i;

		low=0;
		high=n-1;
		flag1=0,flag2=0,flag3=0,u,v;
		scanf("%d %d",&u,&v);
		if(u==v)
		{
			printf("%d\n",u);
			continue;
		}
		while(flag1*flag2!=2)
		{
			if(u==b[temp]||v==b[temp])
				break;
			flag1=0;
			flag2=0;
			flag3=0;

			for(i=low;i<temp;i++)
			{
				if(b[i]==u)
					flag1=1;
				if(b[i]==v)
					flag2=1;
			}

			for(i=temp+1;i<=high;i++)
			{
				if(b[i]==u)
					flag1=2;
				if(b[i]==v)
					flag2=2;
			}

			if(flag1==flag2)
			{
				if(flag1==1)
					high=temp-1;
				else
					low=temp+1;


				for(i=0;i<n;i++)
				{
					for(j=low;j<=high;j++)
						if(a[i]==b[j])
						{   temp=j;
							flag3=1;
							break;
						}
					if(flag3==1)
						break;
				}
			}
		}
		printf("%d\n",b[temp]);
	}
	return 0;
}
