#include <stdio.h>
int main()
{
    int t,n,i,change[100001],arr[100001];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        	for(i=1;i<=n;i++)
  			change[i] = arr[i]- arr[i-1];
    
    i=0;
    int index = 0;
    int sum = 0;
    int maxsum = 0;
    while(index < n)
    {
        sum = sum + change[index];
        if(maxsum < sum)
        {
        maxsum = sum; 
         }
        else if (sum<0) 
        {
        sum = 0;
        i=index+1;
        }
        index++;
    }

    printf("%d\n", maxsum);
    }
    return 0;
}