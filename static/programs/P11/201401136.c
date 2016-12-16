#include<stdio.h>
long long int n;
long long int arr[100010],b[100010];
long long int rear;
void push(long long int i)
{
    rear++;
    b[rear]=i;
}
void pop()
{
    if(rear==0)
        rear=-1;
    else
        rear--;
}
int main()
{
    scanf("%lld",&n);
    while(n!=0)
    {
        long long int i;
        long long int area,maxarea;
        area=maxarea=0;
        rear=-1;
        long long int current;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&arr[i]);
            if(rear==-1)
                push(i);
            else if(arr[i]>=arr[b[rear]])
                push(i);
            else if(arr[i]<arr[i-1])
            {
                while(arr[b[rear]]>arr[i]&&rear!=-1)
                {
                    current=arr[b[rear]];
                    if(rear==0)
                        area=current*(i);
                    else
                        area=current*(i-b[rear-1]-1);
                    if(area>maxarea)
                        maxarea=area;
                    pop();
                }
                push(i);
            }    
    //     int j;
//            for(j=0;j<=rear;j++)
  //              printf("b is %d ",b[j]);
      //      printf("\n");
        }
        //printf("i is %d\n",i);
        while(rear!=-1)
        {
            current=arr[b[rear]];
            if(rear==0)
                area=current*i;
            else
                area=current*(i-b[rear-1]-1);
            if(area>maxarea)
                maxarea=area;
            pop();
        }
        printf("%lld\n",maxarea);
        scanf("%lld",&n);
    }
    return 0;
}
