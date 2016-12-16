#include<stdio.h>
void merge(long long int a[100001],int b,int m,int e);
void divide(long long int a[100001],int b,int e)
{
        int m;
	long long int temp;
        m=(b+e)/2;
        if(e-b>=2)
        {
                divide(a,b,m);
                divide(a,m+1,e);
                merge(a,b,m,e);
        }
        if(e-b==1)
        {
                if(a[b]>a[e])
                {
                        temp=a[b];
                        a[b]=a[e];
			a[e]=temp;
                }
        }
}
void merge(long long int a[100001],int b,int m,int e)
{
        int p,i=b,j=m+1,k=b;
	long long int c[100001];
        while(k<=e&&i<=m&&j<=e)
        {
                if(a[i]<a[j])
                {
                        c[k]=a[i];
                        i++;
                        k++;
                }
                if(a[i]>=a[j])
                {
                        c[k]=a[j];
                        j++;
                        k++;
                }
        }
        if(i==m+1)
        {
                for(p=k;p<=e;p++)
                {
                        c[p]=a[j];
                        j++;
                }
        }
        else
        {
                for(p=k;p<=e;p++)
                {
                        c[p]=a[i];
                        i++;
                }
        }
        for(p=b;p<=e;p++)
		a[p]=c[p];
}
int main()
{
	long long int a[100001],s;
	char c;
	int t,i,j,p,l,v,n,x,y,z,k;
	scanf("%d%d",&t,&v);
	for(i=0;i<t;i++)
	{
		p=0;s=0;x=0;y=0;z=0;l=0;
		while((c=getchar())=='J'||c=='M'||c=='R')
		{
			if(c=='J')
				x++;
			if(c=='M')
				y++;
			if(c=='R')
				z++;
			if(x!=0&&y!=0&&z!=0)
			{
				x=x-1;
				y=y-1;
				z=z-1;
			}
			a[l]=x*10000000000+y*100000+z;
			l++;
		}
		divide(a,0,l-1);
		while(p<l)
		{
			n=0;
			k=p;
			while((a[k]==a[p])&&k<l)
			{
				k++;
				n++;
			}
			if(a[p]==0)
				n=n+1;
			s=s+(n*(n-1))/2;
			p=k;
		}
		printf("%lld\n",s);
	}
	return 0;
}
