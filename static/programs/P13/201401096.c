#include<stdio.h>
#define size 100000
int max,el;
int stack[size];
int input[size];
int a[size];
int n;

int top=-1;    

void partition(int,int,int,int);
int sizeofstack()
{return top+1;}

void push(int el)
{
    a[++top]=el;
    if(top==size)
        return;//printf("Overflow\n");

}

void pop()
{
    if(top==-1)
    { //printf("Underflow\n");
        return;}
    //printf("Popped:%d\n",a[top]);
    top--;
}

void print_stack()
{

    int i;
    //printf("elements: \n");
    for(i=top;i>=0;--i)
        printf("%d ",a[i]);
    printf("%d %d",max,el);
    printf("\n");
}

int peek()
{
    return a[top];
}

void make_stack()
{
    top=-1;
    int i=n-1;
    while(i>=0)
    {
        if(top==-1||input[i]>input[peek()])
        {
            push(i--);
        //printf("pushed:%d\n",input[i]);
        }
        else
        {
            stack[peek()]=i;
            pop();
            
      //  printf("popped:%d\n",input[top+1]);}
        }




    }
}



int main()
{int t;
    int test;
    scanf("%d",&t);test=0;
    while(test<t)
    {
        max=0;
    int i;
    scanf("%d",&n);
    for(i=0;i<n;++i)
        scanf("%d",&input[i]);
    make_stack();
  //  for(i=0;i<n;++i)
    //printf("%d ",stack[i]);
    partition(0,n-2,n-1,0);
    printf("%d %d\n",el,max);
    test++;
    }
    return 0;
}

void partition(int beg,int end, int rootptr,int ans)
{
//    printf("b%d e%d  r%d a%d breaker%d\n",beg,end,rootptr,ans,input[stack[rootptr]]);

    if(beg>=end)
    {
        if(beg==end)
            ans+=1;
        if(ans>max)
        {
            max=ans;
            el=input[beg];
        }
    }
    else{

        partition(beg,stack[rootptr]-1,stack[rootptr],ans+1);
        partition(stack[rootptr]+1,rootptr-2,rootptr-1,ans+1);



    }
}
