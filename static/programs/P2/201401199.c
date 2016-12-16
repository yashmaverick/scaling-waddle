#include<stdio.h>
#define size 100005
int low(long long int a[],int f,int t,long long int ele)
{
    while(f<=t)
    {   
	int mid=(f+t)/2;
	//      printf("from %d --> %d\n",f,t);
	//      printf("mid =  %d\n",mid);
	//      printf("if(%d<=0 && %lld>=%lld)\n",f,a[f],ele);
	if(f<=0 && a[f]>=ele)
	{
	    //          printf(" - satisfied\nreturn %d\n",f);
	    return f;
	}
	//      printf("if(%d>=%d)\n",f,t);
	if(f>=t)
	{
	    //          printf(" - satisfied\n then\n");
	    //          printf("if(%lld>=%lld)\n",a[t],ele);
	    if(a[t]>=ele)
	    {
		//              printf("return %d\n",t);
		return t;//was f
	    }
	    return -1; 
	}
	//      printf("if(%lld<%lld)\n",a[mid],ele);
	if(a[mid]<ele)
	{
	    //          printf(" - satified\n - f=%d",mid+1);
	    f=mid+1;
	}
	else
	{
	    //          printf(" - not satisfed\n - t=%d",mid);
	    t=mid;
	}
    }
    return -1;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
	//input 
	int p,q,r,i,j,k;
	long long int ans=0;
	long long int a[size],b[size],c[size];
	scanf("%d",&p);
	for(i=0;i<p;i++)
	    scanf("%lld",&a[i]);
	scanf("%d",&q);
	for(i=0;i<q;i++)
	    scanf("%lld",&b[i]);
	scanf("%d",&r);
	for(i=0;i<r;i++)
	    scanf("%lld",&c[i]);

//	printf("Input over\n");
	//calc from here

	//
	long long int cntsum[q];
	int index=0;
	for(j=0;j<q;j++)
	{
	    int lbc=low(c,j,r,b[j]);
	    if(lbc!=-1)
		cntsum[index++]=r-lbc;
	    else
		cntsum[index++]=0;
//	    printf("cntsum = %lld\n",cntsum[index-1]);
	}
	/*
	for(j=0;j<q;j++)
	{
	    printf("%lld ",cntsum[j]);
	}
	printf("\n");
	*/
	//sum all from back
	for(j=q-2;j>=0;j--)
	{
	    cntsum[j]+=cntsum[j+1];
	}
	/*
	for(j=0;j<q;j++)
	{
	    printf("%lld ",cntsum[j]);
	}
	
	printf("\n");

	printf("\n");
*/
	//final step
	for(i=0;i<p;i++)
	{
//	    printf("i=%d - a[i]=%lld\n",i,a[i]);
//	    printf("low(b,%d,%d,%lld)\n",i,q-1,a[i]);
	    int lbb=low(b,i,q-1,a[i]);
//	    printf("lbb=%d  cntsum=%lld\n",lbb,cntsum[lbb]);
//	    printf("ans from %lld --> ",ans);
	    if(lbb!=-1)
		ans+=cntsum[lbb];
	  //  printf("%lld\n",ans);
	}
//	printf("final ans = %lld\n",ans);
	printf("%lld\n",ans);
    }
    return 0;
}

