#include<stdio.h>
#include<stdlib.h>
int function(const void *a,const void *b)
{
    return ( *(int*)a-*(int*)b);
}

    int main()
    {
        int t,k,a[1001],n,i,j,p,r;
        char b[1001];
        scanf("%d",&t);
        for(i=0;i<t;i++)
        {
            scanf("%d%d",&n,&k);
            for(j=0;j<n;j++)
            {
                scanf("%s",b);
                scanf("%d",&a[j]);
            }
            qsort(a,n,sizeof(int),function);  
            int flag=0;
            for(j=0;j<n-2;j++)
            {
                p=j+1;
                r=n-1;
                while(p<r)
                {
                    if(a[j]+a[p]+a[r]==k)
                    {
                        flag=1;

                        break;
                    }
                    else if(a[j]+a[p]+a[r]<k)
                        p++;
                    else if(a[j]+a[p]+a[r]>k)
                        r--;
                }
                if(flag==1)
                    break;
            }

            if(flag==0)
                printf("NO\n");
            else
                printf("YES\n");


        }
    
    return 0;
    }


