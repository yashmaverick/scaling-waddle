#include<stdio.h>

int x[1000];

void quicksort(int,int);

void swap(int a,int b)
{
    int temp;
    temp=x[a];
    x[a]=x[b];
    x[b]=temp;
}

int main()
{
    int i,n,k,t,a,b,c,start,end,flag;
    char night[100];

    scanf("%d",&t);
    while(t-->0)
    {
        scanf("%d %d",&n,&k);
        flag=0;

        for(i=0;i<n;i++)
        {
            scanf("%s",night);
            scanf("%d",&x[i]);
        }

        quicksort(0,n-1);

        for(i=0;i<=n-3;i++)
        {
            a=x[i];
            start=i+1;
            end=n-1;

            while(start<end)
            {
                b=x[start];
                c=x[end];

                if((a+b+c)==k)
                {
                    flag=1;
                    start++;
                    end--;
                }
                else if((a+b+c)>k)
                    end--;
                else
                    start++;
            }
        }

        if(flag)
            printf("YES\n");
        else 
            printf("NO\n");
    }

    return 0;
}

void quicksort(int left,int right)
{
    int pivot,j,i;

     if(left<right)
     {
         pivot=left;
         i=left+1;
         j=right;

         while(1)
         {
             while(x[i]<=x[pivot] && i<right)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j)
                 swap(i,j);
             else
                 break;
         }

         swap(pivot,j);
         quicksort(left,j-1);
         quicksort(j+1,right);

    }
}


