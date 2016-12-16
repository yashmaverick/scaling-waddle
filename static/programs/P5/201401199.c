#include<stdio.h>
#define size 1003

void merge(long long int a[],int l1,int h1,int l2,int h2)//setting limits lower and higher of two pairs of virtual arrays
{
    //  cout<<"enter merge\n";
    int i,j,k=0;
    long long int temp[size];
    //  cout<<"merge\n"<<l1<<" "<<h1<<" - "<<l2<<" "<<h2<<endl;
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

    // cout<<"temp\n";

    //  for(i=0;i<k;i++)
    //	cout<<temp[i]<<" ";
    //  cout<<"\n";
    //  cout<<"k="<<k<<endl;
    k=0;

    for(i=l1;i<=h2;i++)
    {
	a[i]=temp[k++];
    }

    // cout<<"quit merge\n";
}

void srt(long long int a[],int l,int h)//lower limit and higher limit (last and first element position of arrays
{
    // cout<<"enter srt\n";
    int n=h-l+1,m;//n=total no of elements
    if(n<=1)//of l>h and l==h (do the math)
	return;
    m=(l+h)/2;//middle element position
    //   cout<<"l - m - h = "<<l<<" "<<m<<" "<<h<<endl;
    srt(a,l,m);//first virtual part from lower to mid
    srt(a,m+1,h);//second virtual part from mid+1 to higher
    merge(a,l,m,m+1,h);//calling merge
    //  cout<<"exit srt\n";
}

int main()
{

    int t;
    char str[size];
    long long  a[size];
    scanf("%d",&t);
    while(t--)
    {
	int n,i,fl=0;
	long long int v;
	scanf("%d",&n);
	scanf("%lld",&v);
	for(i=0;i<n;i++)
	{
	    scanf("%s",str);
	    scanf("%lld",&a[i]);
	}
	srt(a,0,n-1);
//	for(i=0;i<n;i++)
//	    printf("%lld ",a[i]);
//	printf("\n");

	int j,k;

	for(i=0;i<n;i++)
	{
	    j=i+1;
	    k=n-1;
	    while(j<k)
	    {
		long long int sum=a[i]+a[j]+a[k];
		if(sum==v)
		{
		    printf("YES\n");
		    fl=1;
		    break;
		}
		if(sum<v)
		    j++;
		else
		    k--;
	    }
	    if(fl==1)
		break;
	}
	if(fl==0)
	    printf("NO\n");
    }
    return 0;
}


