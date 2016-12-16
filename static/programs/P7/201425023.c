#include<stdio.h>
int function(const void *a,const void *b) 
{
        return ( *(int*)a-*(int*)b);
}
int main()
{
        int t,i,j,k,l;
        long long int n;
        long long int all[1000001];
        scanf("%d",&t);
        for(i=0;i<t;i++)
        {
                scanf("%lld",&n);
                for(j=0;j<n;j++)
                {
                        scanf("%lld",&all[j]);
                }
                qsort(all,n,sizeof(long long int),function);
              /*  for(j=0;j<n;j++)
                {
                        printf("%lld\n",all[j]);
                }*/
                int temp=all[0];
                long long int count=1;
                long long int ans=0;
                for(k=1;k<n;k++)
                {
                        if(all[k]==temp)
                        {
                                count+=1;
                                //  if(k==n)
                                //ans=ans+((count)*(count-1))/2;
                        }

                        else if(all[k]!=temp)
                        {
                                temp=all[k];
                                ans = ans + (count*(count-1))/2;
                                //   temp=all[k];//
                                count=1;
                        }

                        //ans=ans+((count)*(count-1))/2;
                }
                        ans=ans+((count)*(count-1))/2;
                printf("%lld\n",ans);
        }
        return 0;
}

