#include<stdio.h>
int maxlevel=0;
int value;
int head=-1;
int b[100000];
int d[100000];
void check(void);
void stackpr();
void traverse(int *a,int n)
{
    int i;
    for(i=n-1;i>=0;i--)
    {
     //   printf("condition of stack when inserting %d head is %d %d %d  \n",a[i],head,b[head],d[head]);
      // stackpr();
        if(head==-1||b[head]<a[i])
        {
            head++;
            b[head]=a[i];
            if(head==0)
                d[head]=0;
            else {
                d[head]=d[head-1]+1;
            }
        }
        else {
            while(b[head]>a[i]&&head>=0)
                head--;
            head++;
            b[head]=a[i];
            d[head]=d[head]+1;
        }
       // printf("condition of stack when inserting %d head is %d %d %d  \n",a[i],head,b[head],d[head]);
      // stackpr();
        check();
    }
}
void check()
{
    if(d[head]>=maxlevel)
    {
        if(d[head]>maxlevel)
        {
            value=b[head];
            maxlevel=d[head];
        }
        else {
            if(b[head]<value)
                value=b[head];
        }
    }
}
void stackpr()
{
   int top=head;
   while(top>=0)
   {
    printf("%d\t%d\n",b[head],d[head]);
    top--;
   }
   printf("\n");

}
int main()
{
    int t,*a,n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
         a=(int *)malloc(sizeof(int)*n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        traverse(a,n);
        printf("%d %d\n",value,maxlevel);
        head=-1;
        maxlevel=0;
    }
}
