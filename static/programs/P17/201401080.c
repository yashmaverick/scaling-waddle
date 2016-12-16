#include<stdio.h>
int b[10000],c[10000],l,m;
void preorder(int a[],int start,int end)
{
	int i=start+1,j,flag1=0,flag2=0;
	if(a[start]!=c[l] && a[start]!=c[m])
	{
		while(a[i]<=a[start])
			i++;
		for(j=start+1;j<i;j++)
		{
			if(a[j]==c[l])
				flag1=1;
			if(a[j]==c[m])
				flag2=1;
		}
		if(flag1+flag2==1)
			printf("%d\n",b[a[start]]);
		if(flag1+flag2==0)
			preorder(a,i,end);
		if(flag1+flag2==2)
			preorder(a,start+1,i-1);
	}
	else
		printf("%d\n",b[a[start]]);
}
int main()
{
	int n,t,i,temp;
	scanf("%d",&n);
        int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
		c[b[i]]=i;
	}
	for(i=0;i<n;i++)
	{
		temp=c[a[i]];
		a[i]=temp;
	}
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&l,&m);
		preorder(a,0,n-1);
	}
	return 0;
}





