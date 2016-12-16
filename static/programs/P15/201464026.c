#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int *modstack,*array,i,k,j=0,s=0,n,debug;
        scanf("%d %d",&n,&k);
        array = (int *)malloc(4*(n+1));
        modstack = (int *)malloc(4*(n+1));
        for(i=0;i<n;i++)
            scanf("%d",&array[i]);
        modstack[j++]=0;
        for(i=1;i<k;i++)
        {
            while(j!=s && array[i]<=array[modstack[j-1]])
                j--;
            modstack[j++]=i;
        }
        while(i<n)
        {
            //for(debug=s;debug<j;debug++)
              //  printf("Debug %d : %d\n",debug,array[modstack[debug]]);
            printf("%d ",array[modstack[s]]);
            while(j!=s && modstack[s]<=i-k)
                s++;
            while(j!=s && array[i] <= array[modstack[j-1]])
                j--;
            modstack[j++]=i++;
        }
        printf("%d\n",array[modstack[s]]);
        free(array);
        free(modstack);
    }
    return 0;
}
