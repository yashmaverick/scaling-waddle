#include<stdio.h>
int main()
{
	int n,a[100001],b[100001],c[100001],i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int in1,in2,aa,bb;
		scanf("%d%d",&in1,&in2);
		for(i=0;i<n;i++)
		{
			if(b[i]==in1)
				aa=i;
			if(b[i]==in2)
				bb=i;
		}
		for(i=((aa<bb)?aa:bb),j=0;i<=((aa>bb)?aa:bb);i++,j++)
		{
			c[j]=b[i];
		}
		int k=j;
		/*for(j=0;j<k;j++)
			printf("%d ",c[j]);
		printf("\n");*/
		int ans,state=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<k;j++)
				if(a[i]==c[j])
				{
					state=1;
					break;
				}
			if(state==1)
				break;
		}
		printf("%d\n",a[i]);
	}
	return 0;
}
