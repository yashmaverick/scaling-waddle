#include<stdio.h>
int s,l;
void kmin(int a[10002],int i,int k)
{
	int j;
	l=1;
	s=a[i];
	for(j=i+1;j<=k;j++)
	{
		if(s>a[j])
		{
			s=a[j];
			l=1;
		}
		else if(s==a[j])
			l++;
	}
}
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int a[10002],n,k,j,x,y,temp;
		scanf("%d%d",&n,&k);
		for(j=1;j<=n;j++)
			scanf("%d",&a[j]);
		l=1;
		kmin(a,1,k);
		if(k!=n)
			printf("%d ",s);
		if(k==n)
			printf("%d\n",s);
		x=k+1;
		y=1;
		while(x<=n)
		{
			temp=s;
			if(s>a[x])
			{
				s=a[x];
				l=1;
			}
			if(temp==a[y]&&l>0)
				l--;
			if(temp<a[x]&&l==0)
				kmin(a,y+1,x);
			else if(temp==a[x])
				l++;
			if(x!=n)
				printf("%d ",s);
			else if(x==n)
				printf("%d\n",s);
			x++;
			y++;
		}
	}
	return 0;
}
