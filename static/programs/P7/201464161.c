#include<stdio.h>
long int a[1000003];
long int tmp[1000002];
void mergesort(long int a[],long int s,long int e)
{
    if(s==e)
	return;
    long int mid=(s+e)/2;
    mergesort(a,s,(s+e)/2);
    mergesort(a,((s+e)/2)+1,e);
   long int p1,p2,p;
    p1=s,p2=mid+1;p=0;
    while(p1<=mid||p2<=e){
	if(p1>mid)
	    tmp[p++]=a[p2++];
	else if(p2>e)
	    tmp[p++]=a[p1++];
	else{
	    if(a[p1]<a[p2])
		tmp[p++]=a[p1++];
	    else
		tmp[p++]=a[p2++];
	}
    }
   long  int i;
    for(i=0;i<p;i++)
	a[s+i]=tmp[i];
}

int main()
{
  long int n,k,num=1,z=0,ans=0,test,e;
    scanf("%ld",&test);
    for(e=1;e<=test;e++)
    {
        z=0;
        ans=0;
        num=1;
	scanf("%ld",&n);
	for(k=0;k<n;k++)
	    scanf("%ld",&a[k]);
	mergesort(a,0,n-1);
	for(k=0;k<n-1;k++)
	{
	    if(a[k]==a[k+1])
	    {
		num++;
	    }
	    //  z=z+(num*(num-1))/2;
	    // ans=ans+z;
	    if(a[k]!=a[k+1])
	    {               
		z=z+(num*(num-1))/2;
		num=1;
	    }
	}	  
	z=z+(num*(num-1))/2;
	printf("%ld\n",z);
    }
    return 0;
}





