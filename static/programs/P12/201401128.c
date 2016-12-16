/*
   _____________________________________________

PURPOSE : 

created by -ABHINAV AGGARWAL
_____________________________________________ 

*/

#include <stdio.h>

int stack[500005];
int SP;

double C(long long int n,int r)
{
    int i;
    double ans=1;
    for(i=0;i<r;i++)
    {
        ans=ans*(double)(n-i)/(double)(r-i);
    }
    return ans;
}

void push(int d)
{
    stack[++SP]=d;
}

int pop()
{
    return stack[SP--];
}

int main()
{
    int M[500005];
    long long int n,ans;
    scanf("%lld",&n);

    long long int wrong_ans=0,temp_wrong=0,wrong;
    int prev;
    while(n!=0)
    {
        SP=-1;
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%d",&M[i]);
        }

        wrong_ans=temp_wrong=0;
        push(M[0]);
        for(i=1;i<n;i++)
        {
            if(M[i]>stack[SP])
            {
                prev=pop();
                wrong=1;;
                temp_wrong=1;
                while(SP>=0 && M[i]>stack[SP])
                {
                    if(stack[SP]==prev)
                    {
                        while(stack[SP]==prev)
                        {
                            prev=pop();
                            wrong++;
                            temp_wrong++;
                        }
                        wrong_ans=wrong_ans+(int)C(temp_wrong,2)-(temp_wrong-1);
                        if(SP>=0)
                            wrong_ans+=temp_wrong-1;
                        temp_wrong=1;
                    }
                    else
                    {
                        prev=pop();
                        wrong++;
                    }
                }
                wrong_ans=wrong_ans+2*wrong;
                if(SP<0)
                    wrong_ans--;
                push(M[i]);

            }
            else 
            {
                push(M[i]);
            }
        }

//         printf("%lld\n",wrong_ans);  
        /* for(i=0;i<=SP;i++)
           {
           printf("%d ",stack[i]);
           }
           putchar('\n');
           */


        long long int count=0;
        int j;
        for(i=SP;i>=0;i--)    
        { 
            j=i;
            while(j>0 && stack[j]==stack[j-1])
            {
                j--;
            }

            if((i-j+1)!=1)
            {
                //      printf("%d %d\n",i-j+1,(int)C(i-j+1,2));
                wrong_ans=wrong_ans+(long long int)C(i-j+1,2);
                if(j>0)
                    wrong_ans=wrong_ans+(i-j+1);
            }
            else
                if(j>0)
                    count++;
            i=j;
        }

        if(count>0)
            wrong_ans=wrong_ans+count;
  //       printf("%lld\n",wrong_ans);
        ans=(long long int)C(n,2)-wrong_ans;
        printf("%lld\n",ans);

        scanf("%lld",&n);
    }
    return 0;
}
