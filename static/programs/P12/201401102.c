#include<stdio.h>
//#include<stdlib.h>
long long int a[500000];
long long int stack[500000];
//int ub[500000];
int top;
int main()
{
        int n,i,max,cmax,temp;
        long long int ways;
        while(1)
        {
                cmax=0;
                top=0;
                ways=0;
                max=0;
                scanf("%d",&n);
                if(n==0)
                        break;
                //int* a=(int* )malloc(n*sizeof(int));
                for(i=0;i<n;i++)
                {
                        scanf("%lld",&a[i]);
                        if(a[max]<=a[i])
                                max=i;
                }
                for(i=0;i<n;i++)
                {
                        if(a[i]==a[max])
                                cmax++;
                }
                cmax=(((cmax-2)*(cmax-1))/2);
                //printf("%d\n",cmax);

                stack[0]=0;                
                for(i=1;i<n;i++)
                {
                        while(a[i]>a[stack[top]]&&top>=0)
                        {           
                                ways+=(n-1-i);
                                top--;
                        }                        
                        stack[++top]=i;
                        temp=top;
                        while(temp>=0&&(a[stack[top]]==a[stack[temp]]))
                                temp--;                
                        if(temp>0)
                                ways+=temp;
                }                
                printf("%lld\n",ways);
                /*top=0;
                  stack[0]=n-1;
                  for(i=n-2;i>max;i--)
                  {
                  while(a[i]>a[stack[top]]&&top>=0)
                  {
                  ways+=(i-max);
                  top--;
                  }
                  stack[++top]=i;
                  }
                  printf("%d\n",(ways-cmax));*/
        }
        return 0;
}
