#include<stdio.h>
typedef long long int lld;
lld queue[1000010],queue1[1000100],lindex,lindex1,value;

void swap(lld k1,lld k2)
{
    lld temp;
    temp=queue[k1];
    queue[k1]=queue[k2];
    queue[k2]=temp;
}

void swap1(lld k1,lld k2)
{
    lld temp;
    temp=queue1[k1];
    queue1[k1]=queue1[k2];
    queue1[k2]=temp;
}
void insertmin(lld num)
{
    lld i,num1,num2;
    num1=(lindex+1)/2;
    num2=lindex+1;
    queue[lindex+1]=num;
    lindex++;
    while(queue[num1]>queue[num2])
    {
        if(num1<=0)
            break;
        swap(num1,num2);
        num2=num1;
        num1=num1/2;
    }
    // printf("min==%lld\n",queue[1]);
}
void insertmax(lld num)
{
    lld i,num1,num2;
    num1=(lindex1+1)/2;
    num2=lindex1+1;
    queue1[lindex1+1]=num;
    lindex1++;
    //while(num1!=0)
    //{
    while(queue1[num1]<queue1[num2])
    {
        if(num1<=0)
            break;
        swap1(num1,num2);
        num2=num1;
        num1=num1/2;
    }
    //}
    // printf("min==%lld\n",queue[1]);
}
lld deletemin()
{
    lld i,num1,num2,num3,small;
     value=queue[1];
    queue[1]=queue[lindex];
    lindex--;
    num1=1;
    num2=2;num3=3;
    // while(queue[num1]>queue[num2] || queue[num1]>queue[num3])
    while(1)
    {
        if(lindex>=num3)
        {
            if(queue[num1]>queue[num2] ||queue[num1]>queue[num3])
            {
                if(queue[num2]>queue[num3])
                {
                    i=num3;
                    small=queue[num3];
                }
                else
                {
                    i=num2;
                    small=queue[num2];
                }
                swap(i,num1);
                num1=i;
                num2=num1*2;
                num3=num1*2+1;
            }
            else
                break;
        }
        else if(lindex>=num2&&lindex<num3)
        {
            if(queue[num1]>queue[num2])
                swap(num1,num2);
            num1=num2;
            num2=num1*2;
            num3=num1*2+1;
        }
        else
            break;
    }
    return value;
}
lld deletemax()
{
    lld i,num1,num2,num3,small;
    value=queue1[1];
    queue1[1]=queue1[lindex1];
    lindex1--;
    num1=1;
    num2=2;num3=3;
    while(1)
    {
        if(lindex1>=num3)
        {
            if(queue1[num1]<queue1[num2] ||queue1[num1]<queue1[num3])
            {
                if(queue1[num2]<queue1[num3])
                {
                    i=num3;
                    small=queue1[num3];
                }
                else
                {
                    i=num2;
                    small=queue1[num2];
                }
                swap1(i,num1);
                num1=i;
                num2=num1*2;
                num3=num1*2+1;
            }
            else
                break;
        }
        else if(lindex1>=num2&&lindex1<num3)
        {
            if(queue1[num1]<queue1[num2])
                swap1(num1,num2);
            num1=num2;
            num2=num1*2;
            num3=num1*2+1;
        }
        else
            break;
    }
    return value;
   
}

int main()
{
    lld i,j,k,n,t,a,b,c,min,sum,median,f[1000100];
    scanf("%lld",&t);
    while(t--)
    {
        sum=0;
        lindex=0;
        lindex1=0;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
        f[1]=1;
        insertmax(1);
        for(i=2;i<=n;i++)
        {
            if(lindex1-lindex<=1&&lindex1-lindex>=0)
            {
              //  printf("%lld  fc\n",i);
                median=queue1[1];
            }
            else if(lindex1-lindex==-2)
            {
                min=deletemin();
                insertmax(min);
                median=queue1[1];
            }
            else if(lindex1-lindex==-1)
            {
                median=queue[1];

            }
            else if(lindex1-lindex==2)
            {
                min=deletemax();
                insertmin(min);
                median=queue1[1];
            }
            //printf("%lldmedian%lld\n",i,median);

            f[i]=(a*median+b*i+c)%1000000007;
            if(f[i]>median)
            {
                insertmin(f[i]);
            }
            else
            {
                insertmax(f[i]);
            }
        }
        for(i=1;i<=n;i++)
        {
            sum=sum+f[i];
        }
        printf("%lld\n",sum);
    }
    return 0;
}

