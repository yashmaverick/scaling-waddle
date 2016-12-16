#include<stdio.h>
#include<string.h>
#define size 100005

void merge(int a[],int l1,int h1,int l2,int h2)//setting limits lower and higher of two pairs of virtual arrays
{
    int i,j,k=0,temp[size];
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
	a[i]=temp[k++];
}

void srt(int a[],int l,int h)//lower limit and higher limit (last and first element position of arrays
{
    int n=h-l+1,m;//n=total no of elements
    if(n<=1)//of l>h and l==h (do the math)
	return;
    m=(l+h)/2;//middle element position
    srt(a,l,m);//first virtual part from lower to mid
    srt(a,m+1,h);//second virtual part from mid+1 to higher
    merge(a,l,m,m+1,h);//calling merge
}
/*void qsort(int a[],int w,int p)
{
    int f=w,t=p,l;
    if(w>=p)
	return;
    int i;
    for(i=w;i<p;i++)
    {
	if(a[i]<a[p])
	{
	    int temp=a[i];
	    a[i]=a[w];
	    a[w]=temp;
	    w++;
	}
    }
    int temp=a[p];
    a[p]=a[w];
    a[w]=temp;
    qsort(a,f,w-1);
    qsort(a,w+1,t);
    return;
}
*/
void func(int a[],int n)
{
    //    printf("\n");
    int cnt=1,i,j;
    int ans=0,temp;

    for(i=1;i<n;i++)
    {
	//	printf("a[%d] = %d\n",i,a[i]);
	//	printf("%d , %d\n",a[i-1],a[i]);
	if(a[i]==0)
	    ans++;
	if(a[i]==a[i-1])
	{
	    //	    printf("match - ");
	    cnt++;
	    //	    printf("new cnt=%d\n",cnt);
	    if(a[i]!=a[i+1] || i==n-1)
	    {
		//		printf("inside count >1\n");
		//		printf("cnt=%d - ",cnt);
		temp=(cnt*(cnt-1))/2;
		//		printf("temp=%lld - ",temp);
		ans+=temp;
		//		printf("new ans=%lld\n",ans);
		cnt=1;
	    }

	}
	else
	{
	    //	    printf("notmatch\n");
	}
    }
    //  printf("ans=%lld cnt=%d\n",ans,cnt);
    printf("%d\n",ans);
}

int main()
{
    int t,a[size]={0},i;
    char str[size];
    scanf("%d",&t);

    while(t--)
    {
	int n;
	scanf("%s",str);
	n=strlen(str);
	for(i=0;i<n;i++)
	{
	    //	    printf("str[%d] = %c\n",i,str[i]);
	    if(str[i]=='J')
		a[i]=-100001;
	    else if(str[i]=='M')
		a[i]=-1;
	    else
		a[i]=100002;
	    //	    printf("a[%d] = %d\n",i,a[i]);

	}
	//output
	//	for(i=0;i<n;i++)
	//	    printf("%d ",a[i]);
	//	printf("\n");

	//FINDING CUMULATIVE SUM
	for(i=1;i<n;i++)
	    a[i]+=a[i-1];

	//output
	//	for(i=0;i<n;i++)
	//	    printf("%d ",a[i]);
	//	printf("\n");

	srt(a,0,n-1);

	//output
	//	for(i=0;i<n;i++)
	//	    printf("%d ",a[i]);
	//	printf("\n");

	func(a,n);
    }
    return 0;
}
