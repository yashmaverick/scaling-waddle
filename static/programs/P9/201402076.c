#include<stdio.h>
int n,mod,b[1023],c[1023],d[1023],a[1000023];
void input()
{
	scanf("%d",&n);
	scanf("%d",&mod);
	int i,j=0;

	for(i=0;i<n;i++)
	{
		int k=0;
		long long sum=0;
		scanf("%d",&b[i]);
		c[i]=j;
		for(k=0;k<b[i];k++)
		{
			scanf("%d",&a[j]);
			sum+=a[j];
			sum%=mod;
			j++;
		}
		d[i]=sum;
	}
}
void process()
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(d[i]>d[j])
			{
				int temp;
				temp=d[i];
				d[i]=d[j];
				d[j]=temp;
			
				temp=b[i];
				b[i]=b[j];
				b[j]=temp;
				
				temp=c[i];
				c[i]=c[j];
				c[j]=temp;
			}
}
void output()
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\n",d[i]);
		int j;
		for(j=c[i];j<c[i]+b[i];j++)
		{
			printf("%d\n",a[j]);
		}
		printf("\n");
	}
}

int main()
{
	input();
	process();
	output();
	return 0;
}
