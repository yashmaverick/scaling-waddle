#include<stdio.h>
long long int a[10000];
long long int min[20010];
//int index=10005;
//int r=10004;
//int f=10004;
long long int ans[10000];
//int smin[10000];
int main()
{
        int t,n,k,i,j,r,f,l;
        scanf("%d",&t);
        for(i=0;i<t;i++)
        {
                r=10004;
                f=10005;
                l=0;
                scanf("%d%d",&n,&k);
                for(j=0;j<n;j++)                
                        scanf("%lld",&a[j]);
                //min_index=0;
                //min=a[0];
                //smin=a[0];
                //smin_index=0;
                for(j=0;j<=k-1;j++)
                {
                        while(/*r>=10005&&*/a[j]<=a[min[r]]&&r-f>=0)
                                r--;
                        min[++r]=j;
                }
                for(;j<n;j++)
                {
                        ans[l++]=a[min[f]];
                        while(/*f<=10004+k&&*/min[f]<=j-k&&r-f>=0)
                                f++;
                        while(/*r>=10005&&*/a[j]<=a[min[r]]&&r-f>=0)
                                r--;
                        min[++r]=j;
                }
                ans[l]=a[min[f]];
                for(l=0;l<n-k;l++)
                        printf("%lld ",ans[l]);
                printf("%lld\n",ans[l]);
        }
        return 0;
}
                 /*       if(a[j]<a[min_index])
                        {
                                temp=min_index;
                                //temp_index=min_index;
                                //min=a[j];
                                min_index=j;
                                smin_index=temp;
                                //smin_index=temp_index;
                        }
                        else if(a[j]<a[smin_index])
                        {
                                smin_index=j;
                                //smin_index=j;
                        }

                }
                min[0]=min_index;
                smin[0]=smin_index;
                for(j=k;j<n-k;j++)
                {
                        if(min[j-k]==j-k)
                        {
                                if(a[j]<a[smin[j-k]])
                                {
                                        min[j-k+1]=j;
                                        smin[j-k+1]=smin[j-k];
                                }
                                else
                                {
                                        min[j-k+1]=smin[j-k];
                        }
                        else
                        {
                                if(a[j]<min)
                                        minarray[j-k+1]=j;
                                else
                                        minarray[j-k+1]=minarray[j-k];
*/
