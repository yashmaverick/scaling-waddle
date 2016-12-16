#include <stdio.h>

int n;
int a[100005][2];
int top;
int height,maxd;

void push(int x,int c)
{
    top=top+1;
    a[top][0]=x;
    a[top][1]=c;
    if(height<c)
    {
        height=c;
        maxd=a[top][0];
    }
    else if(height==c)
    {
        if(maxd>a[top][0])
            maxd=a[top][0];
    }
}

void print()
{
    int i;
    for(i=0;i<=top;i++)
    {
        printf("a[%d][%d]=%d ",i,0,a[i][0]);
        printf("a[%d][%d]=%d\n",i,1,a[i][1]);
    }
    printf("\n\n\n");
}

void pop()
{
    if(top==-1)
        return;
    top=top-1;
}


int main()
{
    int i,t,m,c,r;
    int b[100005];
    scanf("%d",&t);
    for(m=1;m<=t;m++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        maxd=0;
        c=0;
        top=-1;
        height=-1;
        push(b[n-1],0);
        for(i=n-2;i>=0;i--)
        {
            if(b[i]>a[top][0])
            {
                c=a[top][1]+1; //
                push(b[i],c);
            }
            else
            {
                while(top!=-1 && b[i]<a[top][0])
                {
                    c=a[top][1];
                    pop();
                }
                c=c+1;
                push(b[i],c);
            }
          //  print();
        }
        printf("%d %d\n",maxd,height);
    }
    return 0;
}
