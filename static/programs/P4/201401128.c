
/*
_____________________________________________

PURPOSE : 

		created by -ABHINAV AGGARWAL
_____________________________________________ 

*/

#include <stdio.h>

int cmp(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{ 
    int t,i,len;
    long long count,temp;
    char string[100005];
    long long compute[100005];
    scanf("%d",&t);

    while(t--)
    {
        len=0;
        count=0;
        scanf("%s",string);
        compute[0]=0;
        for(i=0;string[i]!='\0';i++)
        { 
            len++;
            if(string[i]=='J')
                compute[i+1]=100005+compute[i];
            else if(string[i]=='M')
                compute[i+1]=-100004+compute[i];
            else if(string[i]=='R')
                compute[i+1]=-1+compute[i];
            else compute[i+1]=compute[i];

//            printf("%lld\n",compute[i+1]);
        }

  /*      for(i=0;i<=len;i++)
        {
            printf("%lld ",compute[i]);
        }
            printf("\n");
            */
        
        qsort(compute,len+1,sizeof(long long int),cmp);
//        printf("%lld %lld %lld %lld\n",compute[0],compute[1],compute[2],compute[3]); 
        temp=1;
        for(i=1;i<=len;i++)
        {
            if(compute[i]==compute[i-1])
            {
                temp++;
                if(i==len)
                {   
                    if(temp%2==0)
                        count=count+(temp/2)*(temp-1);
                    else
                        count=count+(temp-1)/2*temp;
                }
            }
            else
              { 
                  if(temp%2==0)
                    count=count+(temp/2)*(temp-1);
                  else
                      count=count+(temp-1)/2*(temp);
                  temp=1;
              }
        }

        printf("%lld\n",count);

    }




return 0;
}
