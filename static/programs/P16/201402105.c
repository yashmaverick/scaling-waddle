#include<stdio.h>
#include<math.h>
int main()
{
        int test;
        scanf("%d",&test);
        while(test--)
        {
            int n,i,count1=0,count2=0,count=0,x,x1,x2;
            scanf("%d",&n);
                for(i=n/2;i>=1;i=i/2)
            {
                
		count1++;
			
            }
int l,k;
l=count1;
k=pow(2,l);
if(((3*k)/2)-1>=n)
{	//printf("%d ", count1);
               for(i=3;i<n;i=2*i+1)
                {
                    count2++;
                }
            count=count1+count2;
}
else
{
for(i=2;i<=n;i=2*i)
{
count2++;
}
count=count1+count2;
}


		//for(i=2;i<n;i=2*i)
        	//{
		//	count3++;
	//	}
	   									
	printf("%d\n",count);
}
        return 0;
}

