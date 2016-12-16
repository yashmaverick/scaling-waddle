#include <stdio.h>

int front;
int rear;

int a[10005][2];


void print()
{
    int j;
    printf("front=%d rear=%d\n",front,rear);
    for(j=front;j<=rear;j++)
    {
        printf("a[%d][%d]=%d ",j,0,a[j][0]);
        printf("a[%d][%d]=%d\n",j,1,a[j][1]);
    }
    printf("\n\n\n");
}


int main()
{
    int b[10005];
    int x[10005];
    int t,m,n,k,i,c,l;
    scanf("%d",&t);
    for(m=1;m<=t;m++)
    {
        front=-1;
        rear=-1;
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        front=0;
        rear=0;
        c=-1;
        l=0;
        a[front][0]=b[0];
        a[front][1]=0;
        for(i=1;i<k;i++)
        {
            if(b[i]>=a[rear][0])
            {
                rear++;
                a[rear][0]=b[i];
                a[rear][1]=i;
            }
            else
            {
                while(rear!=-1 && b[i]<a[rear][0])
                {
                     rear--;
                }
                rear++;
                a[rear][0]=b[i];
                a[rear][1]=i;
            }
          //  print();
        }
        x[l]=a[front][0];
        l++;
        c++;
      //  printf("c=%d\n",c);
       // printf("a[%d][0]=%d \n",front,a[front][0]);
     //   printf("%d ",a[front][0]);
        for(i=k;i<n;i++)
        {
            if(b[i]>=a[rear][0])
            {
                rear++;
                a[rear][0]=b[i];
                a[rear][1]=i;
            }
            else
            {
                while(rear>=front && b[i]<a[rear][0])
                {
                    rear--;
                }
                rear++;
                a[rear][0]=b[i];
                a[rear][1]=i;
            }
            c++;
            if(c>a[front][1])
            {
                front++;
            }
          //  printf("c=%d\n",c);
          //  print();
          //  printf("%d \n",a[front][0]);
            x[l]=a[front][0];
            l++;
        }
        for(i=0;i<l-1;i++)
        {
            printf("%d ",x[i]);
        }
        printf("%d\n",x[l-1]);
    }
    return 0;
}

