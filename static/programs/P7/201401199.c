#include<stdio.h>
#define size 1000000
long long int temp[size];
long long int a[size];

void merge(long long int l1,long long int h1,long long int l2,long long int h2)//setting limits lower and higher of two pairs of virtual arrays
{
    int i,j,k=0;
    for(i=l1,j=l2;i<=h1 && j<=h2;)
    {   
	if(a[i]<a[j])
	    temp[k++]=a[i++];
	else
	    temp[k++]=a[j++];
    }    
    while(i<=h1)
	temp[k++]=a[i++];
    while(j<=h2)
	temp[k++]=a[j++];
    k=0;    
    for(i=l1;i<=h2;i++)
    {   
	a[i]=temp[k++];
    }       
}

void srt(long long int l,long long int h)//lower limit and higher limit (last and first element position of arrays
{
    int n=h-l+1,m;//n=total no of elements
    if(n<=1)//of l>h and l==h (do the math)
	return;
    m=(l+h)/2;//middle element position
    srt(l,m);//first virtual part from lower to mid
    srt(m+1,h);//second virtual part from mid+1 to higher
    merge(l,m,m+1,h);//calling merge
}
int main()
{
    int t;
    scanf("%d\n",&t);
    while(t--)
    {
	long long int n,i,cnt=1;
	long long int ans=0,temp;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	    scanf("%lld",&a[i]);	
	srt(0,n-1);
	for(i=1;i<n;i++)
	    if(a[i]==a[i-1])
	    {   
		cnt++;
		if(a[i]!=a[i+1] || i==n-1)
		{   
		    temp=((cnt*(cnt-1)))/2;
		    ans+=temp;
		    cnt=1;
		}   
	    }   
	printf("%lld\n",ans);
    }
    return 0;
}

