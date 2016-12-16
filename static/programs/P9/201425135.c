#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);
int mod;
scanf("%d",&mod);
int a[1000000];
int b[n][2],i=0,j=0,k,l,swap,temp,n1,t,h;
t=n;
while(n--)
{	
	int m,sum=0;
	scanf("%d",&a[i]);
	m=a[i];
	b[j][1]=i;
	i++;
	sum=0;
	while(m--)
	{
		scanf("%d",&a[i]);
		sum=(sum+a[i])%mod;
		i++;
	}
	b[j][0]=sum;
	j++;
}
//for(k=0;k<i;k++)
//printf("%d",a[k]);
//printf("\n");
//for(i=0;i<t;i++)
//	{
//	printf("%d\n",b[i][0]);
//	printf("%d\n",b[i][1]);
//	}
for(k=0;k<t;k++)
{
	for(l=k+1;l<t;l++)
	{
		if(b[l][0] < b[k][0])
		{
		swap=b[l][0];
		b[l][0]=b[k][0];
		b[k][0]=swap;
		temp=b[l][1];
		b[l][1]=b[k][1];
		b[k][1]=temp;
		}
	}
}
//for(i=0;i<t;i++)
//	{
//	printf("%d\n",b[i][0]);
//	printf("%d\n",b[i][1]);
//	}
	
i=0;
for(j=0;j<t;j++)
{
	printf("%d\n",b[j][0]);
	n1=a[b[j][1]];
	k=b[j][1]+1;
	while(n1--)
	{
		printf("%d\n",a[k]);
		k++;
	}
	i=k;
	printf("\n");
}
return 0;
}
