#include<stdio.h>
int main()
{
    int a[100000],b[100000],i,j,n,p,q,ind[100000],t,k,l,m,root;
      scanf("%d",&n);
    for(i=0;i<n;i++)
	scanf("%d",&a[i]);
    for(j=0;j<n;j++)
    {
	scanf("%d",&b[j]);
	ind[b[j]]=j;
    }
    scanf("%d",&t);
    while(t--)
    {
	i=0;
	int z=1;
	int flag=0;
	scanf("%d %d",&p,&q);
	    l = ind[p];
	    m = ind[q];
	while(flag!=1)
	{ 
	    root = a[i];
	    k = ind[a[i]];
	    if(l==k || m==k)
	    {
		printf("%d\n",root);
		flag = 1; 
	    }
	    else if(l<k && m>k || l>k && m<k)
	    {
		printf("%d\n",root);
		flag = 1;
	    }
	    else if(l<k&&m<k)
	    {
		i++;
		z++;
	    }
	    else if(l>k&&m>k)
		i = k+z;	
	}
    }
    return 0;
}
