#include<stdio.h>

/*int compare(long long int A, long long int B)
  {
  if (A     <     B)
  return 1;
  else
  return 0;
  }*/

int main()
{
        char p[10000];
        long long int i,j,a[100000],t,t1,n,k,tmp,m,o,d,flag,mid;
        scanf("%lld",&t);
        for(t1=0;t1<t;t1++)
        {
                flag=0;
                scanf("%lld %lld",&n,&k);
                for(i=0;i<n;i++)
                {

                        scanf(" %s %lld",p,&a[i]);
                }
                for(i=0;i<n-1;i++)
                        for(j=0;j<n-1;j++)
                                if(a[j]>a[j+1])
                                {
                                        tmp=a[j];
                                        a[j]=a[j+1];
                                        a[j+1]=tmp;
                                }


                //qsort(a,a+n,compare);
                for(i=n-1;i>1;i--)
                {
                        if(a[i]<=k)
                        {
                                for(j=i-1;j>0;j--)
                                {
                                        d=k-a[i]-a[j];
                                        if(d>=0)
                                        {
                                                m=0;
                                                o=j-1;
                                                while(m<=o)
                                                {
                                                        mid=(m+o)/2;
                                                        if(d==a[mid])
                                                        {
                                                                printf("YES\n");
                                                                flag=1;
                                                                break;
                                                        }
                                                        else if(a[mid]>d)
                                                                o=mid-1;
                                                        else
                                                                m=mid+1;
                                                }
                                                if(flag==1)
                                                        break;
                                        }
                                }
                        }
                        if(flag==1)
                                break;
                }
                if(flag==0)
                        printf("NO\n");
        }
        return 0;
}
