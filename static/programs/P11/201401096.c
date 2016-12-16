#include<stdio.h>
long long int n;
long long int ind[100000];
long long int input[100000];
long long int max=0,area;

long long int top_i=-1;    
long long int width;

void push(long long int a[],long long int *top,long long int el)
{
    *(top)=*(top)+1;
    a[*top]=el;
    if(*top==n)
       return;

}

long long int pop(long long int a[],long long int *top)
{
    if(*top==-1)
    return;
    long long int prev=a[*top];
    *top=*(top)-1;
    return prev;
}

void print_stack(long long int a[],long long int top)
{

    long long int i;
    printf("elements: \n");
    for(i=top;i>=0;--i)
        printf("%lld ",a[i]);

    printf("\n");
}

long long int peek(long long int a[],long long int top)
{
    return a[top];
}


int main()
{
    
while(1){ 
        top_i=-1;
       max=0;
        scanf("%lld",&n);

        if(n==0)break;
       
        long long int i;
        for(i=0;i<n;++i)
        {
            scanf("%lld",&input[i]);
        }
        i=0;long long int flag=0;
        long long int lastIndex;
        while(i<n)

        {
            
            
            if((top_i==-1)||input[peek(ind,top_i)]<=input[i])
            {
             //   printf("pushed:%lld\n",input[i]);

                push(ind,&top_i,i);i++;
            }
            else 
                {
                    lastIndex=pop(ind,&top_i);
                   // printf("popped:%lld\n",input[lastIndex]);
                    if(top_i==-1)
                    width=i;
                    else 
                    width=i-peek(ind,top_i)-1;
                        area=input[lastIndex]*width;
                        
                        if(area>max)
                            max=area;
                    //printf("ar=%lld maxar=%lld\n",area,max);
                    }
                }
            //after the process we might still have elements on stack


            while(top_i!=-1)
            {   lastIndex=pop(ind,&top_i);
            // printf("popped:%lld\n",input[lastIndex]);
                if(top_i==-1)
                     width=i;
                else    
                    width=i-peek(ind,top_i)-1;
                area=input[lastIndex]*width;
                if(area>max)
                    max=area;
              //      printf("ar=%lld maxar=%lld\n",area,max);
            }
printf("%lld\n",max);

}
return 0;
}





