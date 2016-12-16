#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
int main()
{
    long long int i,j,k,n,t,counter,num,index,index1,c,pair,l,temp4;
    char b[100010];
    //long long int a[100010];
    
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%s",b);
        l=strlen(b);
        for(i=0;i<l;i++)
        {
            if(b[i]=='J')
                temp4=-100001;
                else if(b[i]=='M')
                    temp4=100000;
                    else
                        temp4=1;

             if(i>0)
             a[i]=temp4+a[i-1];
             else
                 a[i]=temp4;
        }
//        for(i=0;i<l;i++)
  //          printf("%lld  ",a[i]);
        sort(0,l-1);
    //    printf("\n");
      //  for(i=0;i<l;i++)
        //    printf("%lld  ",a[i]);
          //  printf("\n");

        num=a[0];
        index=0;
        a[index]=1;
        c=0;
        counter=0;
        for(i=1;i<l;i++)
        {
           if(a[i]==0)
      //      {
    //        while(a[i]==0)
  //          {
//                i++;
                counter++;


      //      }
    //        num=a[i];
          //  }
//            else
  //          {*/

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
           // }
        }
        
        pair=0;
        for(i=0;i<=c;i++)
        {
            //if(a[i]>1)
           // {
            //   printf("%lld  ",a[i]);
                pair=pair+((a[i])*(a[i]-1))/2;
           // }
        }
      //  printf("\n");
        printf("%lld\n",pair+counter);
    }
return 0;
}
