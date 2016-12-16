#include<stdio.h>
#include<string.h>
void merge(long long int a[],long long int ,long long int ,long long int);
void sort(long long int a[], long long int start, long long int end)
{
    long long int mid;
    if(start>=end)
	return;
    else
    {
	mid=(start+end)/2;
	sort(a,start,mid);
	sort(a,mid+1,end);
	merge(a,start,mid,end);
    }
}

void merge(long long int a[],long long int start ,long long int mid, long long int end)
{
    long long int temp[100000];
    long long int i,j,k,l;
    k=start;
    l=mid+1;

    for(i=start;k<=mid&&l<=end; i++)
    {
	if(a[k]<=a[l])
	{
	    temp[i]=a[k];
	    k++;
	}
	else
	{
	    temp[i]=a[l];
	    l++;
	}
    }
    while(k>mid && l<=end)
    {
	temp[i]=a[l];
	i++;
	l++;
    }
    while(l>end && k<=mid)
    {
	temp[i]=a[k];
	i++;
	k++;
    }

    for(i=start;i<=end;i++)
	a[i]=temp[i];
}

long long int prefix[100000];
int main()
{
    int t;
    int j=100000,m=100001,r=-200001;
    scanf("%d",&t);
    long long int i;
   long long int temp;
    long long int l,a,b;
    long long int total=0,count=1;
    char s[100000];
    //long long int prefix[100005];
    for(i=0;i<t;i++)
    {
	total=0;
	scanf("%s",s);
	l=strlen(s);
	if(s[0]=='J')
	    prefix[0]=j;
	else if (s[0]=='M')
	    prefix[0]=m;
	else
	    prefix[0]=r;

	for(a=1;a<l;a++)
	{
	    if(s[a]=='J')
		prefix[a]=prefix[a-1]+j;
	    else if(s[a]=='M')
		prefix[a]=prefix[a-1]+m;
	    else
		prefix[a]=prefix[a-1]+r;
	}
//for(a=0;a<l;a++)
//printf("%lld ",prefix[a]);
//printf("\n");

	    
	sort(prefix,0,l-1);
//for(a=0;a<l;a++)
// printf("%lld ",prefix[a]);
//printf("\n");

	for(a=0;a<l-1;)
	{
	    count=1;
	    temp=prefix[a];
	    for(b=a+1;b<l;b++)
	    {
		if(prefix[b]==temp)
		    count++;
		else
		    break;
	    }
	    if(count>=2)
		total+=(count*(count-1))/2;
	    if(prefix[a]==0)
		total+=b-a;
	    a=b;
	}
	printf("%lld\n",total);
    }
    return 0;
}





