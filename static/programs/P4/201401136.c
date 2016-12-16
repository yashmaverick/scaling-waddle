#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmpfunc(const void *a, const void *b)
{
    return ( *(int*)a-*(int*)b);
}
int main()
{
    int t,i,j,l;
    int ans,len;
    int count0;
    int arr[100010];
    char s[100010];
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        count0=ans=0;
        scanf("%s",s);
        len=strlen(s);
        for(j=0;j<len;j++)
        {
            if(j==0)
            {
                if(s[0]=='J')
                    arr[j]=100001;
                else if(s[0]=='M')
                    arr[j]=-100002;
                else
                    arr[j]=1;
            }
            else
            {
                if(s[j]=='J')
                    arr[j]=arr[j-1]+100001;
                else if(s[j]=='M')
                    arr[j]=arr[j-1]-100002;
                else if(s[j]=='R')
                   arr[j]=arr[j-1]+1;
            }
        }
        qsort(arr,len,4,cmpfunc);
        int k=0;
        int b[100010];
        int temp=arr[0];
        for(j=0;j<len;j++)
            b[j]=1;
        for(j=1;j<len;j++)
        {
            if(arr[j]==0)
                count0++;
            else if(arr[j]==temp)
            {
                temp=arr[j];
                b[k]++;
            }
            else
            {
                k++;
                temp=arr[j];
            }
        }
        for(l=0;l<=k;l++)
        {
            ans=ans+((b[l])*(b[l]-1))/2;
        }
        count0=count0+((count0)*(count0-1))/2;
        printf("%d\n",ans+count0);
    }
    return 0;
}
