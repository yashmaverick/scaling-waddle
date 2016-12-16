#include<stdio.h>
#include<math.h>

int arr[33];

void init()
{
    int j,i=1;
    for(j=0;j<32;j++)
    {
        arr[j]=i;
        i=i*2;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    init();
    while(n--)
    {
        int q;
        scanf("%d",&q);
        int j=0;
        while(arr[j]<q)
            j++;
        if(arr[j]!=q)
            j--;
        int ans=2*j;
        if(j>0)
            if(q<(arr[j]+arr[j-1]))
                ans--;
        printf("%d\n",ans);
    }
}
