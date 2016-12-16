#include<stdio.h>
int merge(long long int a[],int l,int mid, int r)
{
        long long int c[100000],i,j=l,k=mid+1;

        for(i=0;j<=mid&&k<=r;i++)
        {
                if(a[j]<a[k])
                {
                        c[i]=a[j];
                        j++;
                }
                else
                {
                        c[i]=a[k];
                        k++;
                }
        }
        if(j>mid)
                for(;k<=r;i++)
                        c[i]=a[k++];
        if(k>r)
                for(;j<=mid;i++)
                        c[i]=a[j++];

        for(i=l,j=0;i<=r;i++)
        {

                a[i]=c[j++];
        }

}
void mergesort(long long int a[],int l,int r)
{
        if(l<r)
        {

                int mid=l+(r-l)/2;
                mergesort(a,l,mid);
                mergesort(a,mid+1,r);
                merge(a,l,mid,r);
        }
}    

int main()
{
        int k,n,j,t,i,c,ans;
        char s[100001];
        long long int a[100000];
        scanf("%d",&t);
        getchar();
  //      printf("%d\n",ans);
        for(i=0;i<t;i++)
        {ans=0;
    //            printf("%d\n",ans);
               
                scanf("%s",s);
                for(j=0;s[j]!='\0';j++)

                {
                        if(s[j]=='J')
                                a[j]=-100002;
                        else if(s[j]=='M')
                                a[j]=1;
                        else
                                a[j]=100001;

                }
                n=j;     

                for(j=1;j<n;j++)
                {
                        a[j]+=a[j-1];
                }
                mergesort(a,0,n-1);
                
                //for(j=0;j<n;j++)
                        //printf("%d ",a[j]);
                ans=0;
                for(j=0;j<n;)
                {c=1;
                        while(a[j+1]==a[j]&&j<n-1)
                        {
                                c++;
                                //printf("%d\n",c);
                                j++;
                        }
                        if(a[j]==0)
                                ans+=(c*(c-1))/2+c;
                        else
                                ans+=(c*(c-1))/2;
                        
                        j++;
                }
                printf("%d\n",ans);

        }
        return 0;
}







