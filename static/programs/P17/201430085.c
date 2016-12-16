#include<stdio.h>
int main()
{
	int n,i,a[1001],b[1001],c[1000];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
		c[b[i]]=i;
	}
	int x,y;
	scanf("%d",&x);
	for(y=0;y<x;y++)
	{
		int k,l,s,w,j,r,f=0,ans;
		scanf("%d %d",&k,&l);
		r=0;
		s=c[k];
		w=c[l];
		while(f==0)
		{
			j=c[a[r]];
			if(((s<=j)&&(w>=j))||((s>=j)&&(w<=j)))
			{
				ans=b[j];
				f=1;
			}
			else if(s>j&&w>j)
			{
				if(j>r)
				r=j+1;
				else
					r=r+1;
			}
			else if(s<j&&w<j)
				r=r+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
