#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define si(n) scanf("%d",&n)
#define dout(n) prlong long intf("%d\n",n)

struct stack{
    long long int key;
    struct stack* prev;
};

void push(long long int elem, struct stack **top)
{
    struct stack *copy=(struct stack*)malloc(sizeof(struct stack));
    copy->key=elem;
    copy->prev=*top;
    *top=copy;
}

long long int pop(struct stack **top)
{
    if (*top==NULL)
        return -1;

    long long int TORETURN=(*top)->key;
    struct stack *temp=(*top)->prev;
    free(*top);
    *top=temp;
    return TORETURN;
}

long long int TOP(struct stack *top)
{
    if (top==NULL)
        return -1;
    else
        return top->key;
}


long long int main()
{
    while(1)
    {
        long long int n;
        scanf("%lld",&n);
        if (n==0)
            break;
        long long int arr[n];
        struct stack *s=NULL;
        push(-1,&s);

        long long int x,i=0,dup,temp,count=0;
        long long int ans=0;
        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);

        for(i=0;i<n;i++)
        {
            x=i;
            // TOTAL - FAVOURABLE

            if (arr[x] <= arr[TOP(s)] || TOP(s)==-1)       // check equal sign here
            {
                push(x,&s);
                count++;
            }
            else
            {
                dup=1;
                while(arr[TOP(s)]<arr[x] && TOP(s)!=-1)      // equals added after verification
                {
                    temp=pop(&s);
                    if (arr[TOP(s)]!=arr[temp])
                    {
                        //                         printf("dup is %lld and temp is %lld\n",dup ,temp);
                        if (TOP(s)!=-1)
                            ans+=(dup*(dup-1))/2 + 2*dup;
                        else
                            ans+=(dup*(dup-1))/2 + dup;

                        dup=1;
                    }
                    else
                        dup++;
                    count--;
                }

                if (dup!=1)
                {
                    if (TOP(s)!=-1)
                        ans+=(dup*(dup-1))/2 + 2*dup;
                    else
                        ans+=(dup*(dup-1))/2 + dup;
                    dup=1;
                }
                //       if (TOP(s)!=-1)
                //           ans++;

                push(x,&s);
                count++;
            }
        //    printf("ans is %lld\n",ans);
        }

    //    printf("ans is %lld\n",ans);
    //    printf("Top is %lld, ans is %lld\n",TOP(s) ,ans);


        dup=1;
        while(TOP(s)!=-1)      // equals added after verification
        {
            temp=pop(&s);
            if (arr[TOP(s)]!=arr[temp])
            {
                if (TOP(s)!=-1)
                    ans+=(dup*(dup-1))/2 + dup;
                else
                    ans+=(dup*(dup-1))/2;
                dup=1;
            }
            else
                dup++;
  //          printf("dup is %lld\n",dup);
        }
//        printf("Top is %lld, ans is %lld\n",TOP(s) ,ans);
        if (dup!=1)
        {
            if (TOP(s)!=-1)
                ans+=(dup*(dup-1))/2 + 2*dup;
            else
                ans+=(dup*(dup-1))/2 + dup;
            dup=1;
        }
      //  printf("ans is %lld\n",ans);

        if ((n%2)==0)
            ans=(long long int)(n/2)*(n-1) - ans;
        else
            ans=(long long int)(n*((n-1)/2) - ans);

        printf("%lld\n",ans);
    }

    return 0;
}
