#include<stdio.h>
int r,s,n;
void LCA(int start,int end,int a[],int b[],int start1,int end1)
{
	int node=a[start],i;
	for(i=start1;i<=end1;i++)
	{
		if(node==b[i])
			break;
	}
	if((r>=i && s<=i) || (r<=i && s>=i))
		printf("%d\n",b[i]);
	if(r>i && s>i)
		LCA(i+1,end,a,b,i+1,end);
	if(r<i && s<i)
		LCA(start+1,i-1,a,b,start,i-1);
}
int main()
{
	scanf("%d",&n);
	int i,a[n],b[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	int t,h,x,y;
	scanf("%d",&t);
	for(h=0;h<t;h++)
	{
		scanf("%d%d",&x,&y);
		for(i=0;i<n;i++)
		{
			if(b[i]==x)
				r=i;
			if(b[i]==y)
				s=i;
		}
		LCA(0,n-1,a,b,0,n-1);
	}
	return 0;
}
