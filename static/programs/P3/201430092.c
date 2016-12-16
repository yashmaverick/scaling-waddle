#include<stdio.h>
int main()
{
    int n,i,a[100000],prof,profmax,m,j,temp;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
	scanf("%d",&m);
	for(j=0;j<m;j++)
	{
	    scanf("%d",&a[j]);
	}
	profmax=0;prof=0;
	for(j=m-1;j>0;j--)
	{
	    if(a[j-1]<a[j])
	    {	prof=a[j]-a[j-1];
	   // printf("%d",prof);
	    if(prof>profmax)
	    {
		profmax=prof;
	    }
	    temp=a[j];
	    a[j]=a[j-1];
	    a[j-1]=temp;
	}
	}
	printf("%d\n",profmax);
    }
    return 0;
}
