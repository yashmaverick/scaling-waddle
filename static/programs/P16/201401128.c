
/*
_____________________________________________

PURPOSE : 

		created by -ABHINAV AGGARWAL
_____________________________________________ 

*/

#include <stdio.h>

int main()
{
    int GP[31],i;
    GP[0]=1;
    GP[1]=3;
    for(i=2;i<=30;i++)
    {
        GP[i]=GP[i-1]+2*(GP[i-1]-GP[i-2]);
       // printf("%d\n",GP[i]);
    }

    int n,q;
    scanf("%d",&n);
   
    while(n--)
    {
       scanf("%d",&q);
       i=0;
       while(GP[i]<q)
           i++;
      // printf("is is %d\n",i);
       if(q<=(GP[i]+GP[i-1])/2)
           printf("%d\n",2*i-1);
       else
           printf("%d\n",2*i);

    }


return 0;
}
