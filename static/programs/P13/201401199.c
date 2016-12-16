#include<stdio.h>
#define size 100005
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
	int i,n,a[size],s[size],d[size],t=-1,depth,val;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	    scanf("%d",&a[i]);
	if(n==0)
	    continue;

	s[++t]=a[n-1];
	d[t]=0;
	depth=0;
	val=a[n-1];
	for(i=n-2;i>=0;i--)
	{
//	    printf("begin\n i=%d a[i]=%d\n",i,a[i]);
//	    printf(" t=%d s[t]=%d\n",t,s[t]);
//	    printf(" val=%d depth=%d\n",val,depth);
	    if(a[i]>s[t])
	    {
		s[++t]=a[i];
		d[t]=d[t-1]+1;
		if(depth<d[t])
		{
		    depth=d[t];
		    val=s[t];
		}	    
	    }
	    if(a[i]<s[t])
	    {
		while(a[i]<s[t] && t>=0)
		{
		    t--;
		}
		s[++t]=a[i];
		d[t]=d[t]+1;
		if(depth<d[t])
		{
		    depth=d[t];
		    val=s[t];
		}	    
	    }
	    if(d[t]==depth)
	    {
		if(val>s[t])
		    val=s[t];
	    }
//	    int j;
//	    for(j=0;j<=t;j++)
//		printf("%d ",s[j]);
//	    printf("\n");
//	    for(j=0;j<=t;j++)
//		printf("%d ",d[j]);
//	    printf("\n");
//	    printf("end\n i=%d a[i]=%d\n",i,a[i]);
//	    printf(" t=%d s[t]=%d\n",t,s[t]);
//	    printf(" val=%d depth=%d\n",val,depth);
//	    printf("\n");
	}
	printf("%d %d\n",val,depth);
    }
    return 0;
}
