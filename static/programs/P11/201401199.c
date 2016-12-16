#include<stdio.h>
#define size 100005
typedef long long int lli;

void show(lli a[],lli n)
{
    lli i;
    for(i=0;i<n;i++)
    {
	printf("%lld ",a[i]);
    }
    printf("\n");
    return;
}

void calfsl(lli a[],lli fsl[],lli n)
{
    lli i,temp;
    fsl[0]=-1;
    for(i=1;i<n;i++)
    {
	//	printf("i=%lld\n",i);
	temp=i-1;
	//	printf("a[temp] = %lld\n",a[temp]);
	//	printf("a[i] = %lld\n",a[i]);
	while(a[temp]>=a[i] && temp>=0)
	{
	    temp=fsl[temp];
	    //	    printf("new temp = %lld\n",temp);
	}
	fsl[i]=temp;
	//	printf("\n");
    }
    return;
}


void calfsr(lli a[],lli fsr[],lli n)
{
    lli i,temp;
    fsr[n]=n+1;
    for(i=n-1;i>=0;i--)
    {
	//	printf("i=%lld\n",i);
	temp=i+1;
	//	printf("a[temp] = %lld\n",a[temp]);
	//	printf("a[i] = %lld\n",a[i]);
	while(a[temp]>=a[i] && temp<n)
	{
	    temp=fsr[temp];
	    //	    printf("new temp = %lld\n",temp);
	}
	fsr[i]=temp;
	//	printf("\n");
    }
    return;
}

int main()
{
    lli a[size],fsl[size],fsr[size];
    lli i,n=1;
    while(n!=0)
    {
	scanf("%lld",&n);
	//input
	for(i=0;i<n;i++)
	{
	    scanf("%lld",&a[i]);
	}
	//    show(a,n);

	calfsl(a,fsl,n);
	//    show(fsl,n);
	calfsr(a,fsr,n);
	//    show(fsr,n);

	lli val,max=0,temp;

	for(i=0;i<n;i++)
	{
	    temp=fsr[i]-fsl[i]-1;
	    val=temp*a[i];
	    if(max<val)
		max=val;
	}
	if(n!=0)
	    printf("%lld\n",max);
    }
    return 0;
}

