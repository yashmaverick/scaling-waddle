#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define f(i,start,n,p) for(i=start;i<=n;i+=p)
#define LL long long int  
#define ch char
LL a[100010],te[100010];
void write(LL *pointer1)
{
printf("%lld\n",*pointer1);
}
void read_integer(LL *address)
{
scanf("%lld",address);
}
void read_string(ch *pointer)
{
scanf("%s",pointer);
}
void join(int start,int end)
{
    int i,j,k;
    i=start;
    int mid=(start+end)/2;
    j=mid+1;
    k=start;
    while(i<=mid && j<=end)
        if(a[i]<=a[j])
            te[k++]=a[i++];
        else
            te[k++]=a[j++];
    while(i<=mid)
        te[k++]=a[i++];
    while(j<=end)
        te[k++]=a[j++];
    for(i=start;i<=end;i++)
        a[i]=te[i];
    return;
}
void divide(int i,int j)
{
    if(i<j)
    {        
        int mid=(i+j)/2;
        divide(i,mid);
        divide(mid+1,j);
        join(i,j);
    }
}
int main()
{
    LL len,k,test,i,j,hem,b,t,count;
    ch temp[100010];
    read_integer(&test);
    while(test--)
    {
        read_string(temp);
        if(temp[0]==74)
            a[0]=100001;
        else if(temp[0]==77)
            a[0]=1;
        else
            a[0]=-100002;
        hem=0;
        len=strlen(temp);
        f(j,1,len-1,1)
            if(temp[j]==74)
                a[j]=a[j-1]+100001;
            else if(temp[j]==77)
                a[j]=a[j-1]+1;
            else
                a[j]=a[j-1]-100002;
        a[j]=0;
        divide(0,j);
        t=a[0];
        count=1;
        f(k,1,j,1)
            if(a[k]==t)
                count++;
            else
            {
                hem+=((count)*(count-1))/2;
                count=1;
                t=a[k];
            }
        hem+=(count*(count-1))/2;
    write(&hem);
    }
    return 0;
}
