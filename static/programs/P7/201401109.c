#include<stdio.h>
#include<stdlib.h>
long long int n;
long long int left,right,middle;
long long int a[1000101],b[1000101];
void msort(long long int left,long long int middle,long long int right)
{
	long long int temp,temp1,temp2,l1,l2,d,d1,t1,flag,i;
	 temp1=middle+1;
	 temp=left;
	 temp2=right;
	 l1=middle-left+1;
	 l2=right-middle; d=l1; d1=l2; t1=left;
	 flag=0;
	while(d!=0&&d1!=0)
	{
		if(a[temp]<=a[temp1])
		{
			b[t1]=a[temp];
			temp++;
			d--;
		}
		else
		{
			b[t1]=a[temp1];
			temp1++;
			d1--;
		}
		t1++;
		if(d==0)
			flag=1;
		if(d1==0)
			flag=2;
		
	}
	if(flag==1)
	{
		while(d1>0)
		{
			b[t1]=a[temp1];
			temp1++;
			t1++;
			d1--;
		}
	}
	if(flag==2)
	{
		while(d>0)
		{
			b[t1]=a[temp];
			temp++;
			t1++;
			d--;
		}
	}
	for(i=left;i<=right;i++)
	{
		a[i]=b[i];
	}
}
void sort(long long int left,long long int right)
{
	long long int middle=(left+right)/2;
	if(left<right)
	{
		sort(left,middle);
		sort(middle+1,right);
		msort(left,middle,right);
	}
	else
		return;
}
/*int cmpfunc (const void * a, const void * b)
{
       return ( *(long long int*)a - *(long long int*)b );
}*/
//long long int a[1000101],n;
int main()
{
    long long int i,j,k,t,count,count1,pair,num,c,index;
    scanf("%lld",&t);
    while(t--)
    {
        count=0;count1=0;pair=0;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
         sort(0,n-1);
      //  qsort(a,n,sizeof(long long int),cmpfunc);
        num=a[0];
        index=0;
        a[index]=1;
        c=0;
        for(i=1;i<n;i++)
        {
            if(num==a[i])
            {
               a[index]=a[index]+1;
            }
            else
            {
                c++;
                index=c;
                num=a[i];
                a[index]=1;
             //   num=a[i];
            }
        }
        for(i=0;i<=c;i++)
        {
            if(a[i]>1)
            {
                pair=pair+((a[i])*(a[i]-1))/2;
            }
        }
        printf("%lld\n",pair);
    }
    return 0;
}


                


           


            










