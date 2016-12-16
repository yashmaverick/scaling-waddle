#include<stdio.h>
#include<string.h>
long long int z[100000],b[100000];
void divide(int beg,int end)
{
	int mid,i,j,k;
	if(beg==end)
		return;
	else
	{
		mid=(beg+end)/2;
		divide(beg,mid);
		divide(mid+1,end);
		//merge
		i=beg;j=mid+1;k=0;
		while(i<=mid&&j<=end)
			if(z[i]>z[j])
				b[k++]=z[j++];
			else
				b[k++]=z[i++];
		while(i<=mid&&j>end)
			b[k++]=z[i++];
		while(j<=end&&i>mid)
			b[k++]=z[j++];
		for(i=beg,j=0;i<=end&&j<k;i++)
			z[i]=b[j++];
	}
}

int main()
{
	int i,t,l,sum,c;
	long long int x=-100002,y=1,w=100001;
	char a[100001];
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		scanf("%s",a);
		l=strlen(a);	
		a[l]='\0';
		i=0;
			if(a[i]=='J')
				z[i]=x;
			else if(a[i]=='M')
				z[i]=y;
			else
				z[i]=w;
			i++;
		while(a[i]!='\0')
		{
			if(a[i]=='J')
				z[i]=z[i-1]+x;
			else if(a[i]=='M')
				z[i]=z[i-1]+y;
			else
				z[i]=z[i-1]+w;
			i++;
		}
		divide(0,l-1);
		for(i=0;i<l;i++)
		{
			c=1;
			while(i<l-1&&z[i]==z[i+1])
			{
				c++;
				i++;
			}
			sum+=c*(c-1)/2;
			if(z[i]==0)
				sum+=c;
		}
		printf("%d\n",sum);
	}
	return 0;
}

