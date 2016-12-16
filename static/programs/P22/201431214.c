#include<stdio.h>
int qmin[200002];
int qmax[200002];
int topmax=0,topmin=0;
long long int a,b,c;
int M=1000000007;
void insertmin(int num)
{
    int j,temp;
    if(topmin==0)
    {
        topmin++;
        qmin[topmin]=num;
    }
    else
    {
        topmin++;
        qmin[topmin]=num;
        for(j=topmin;j>1 && qmin[j]<qmin[j/2];j=j/2)
        {
            temp=qmin[j];
            qmin[j]=qmin[j/2];
            qmin[j/2]=temp;
        }
    }
}
void insertmax(int num)
{
    int j,temp;
    if(topmax==0)
    {
        topmax++;
        qmax[topmax]=num;
    }
    else
    {
        topmax++;
        qmax[topmax]=num;
        for(j=topmax;j>1 && qmax[j]>qmax[j/2];j=j/2)
        {
            temp=qmax[j];
            qmax[j]=qmax[j/2];
            qmax[j/2]=temp;
        }
    }
}
void deletemin()
{
    int i;
    int temp;
    qmin[1]=qmin[topmin];
    topmin--;
    i=1;
    while((2*i<=topmin && qmin[i]>qmin[2*i]) ||(2*i+1<=topmin && qmin[i]>qmin[2*i+1]))
    {
        if(qmin[2*i+1]<qmin[2*i])
        {
            temp=qmin[2*i+1];
            qmin[2*i+1]=qmin[i];
            qmin[i]=temp;
            i=(2*i)+1;
        }
        else
        {
            temp=qmin[2*i];
            qmin[2*i]=qmin[i];
            qmin[i]=temp;
            i=2*i;
        }
    }
    return ;
}
void deletemax()
{
    int i;
    int temp;
    qmax[1]=qmax[topmax];
    topmax--;
    i=1;
    while((2*i<=topmax && qmax[i]<qmax[2*i]) ||(2*i+1<=topmax && qmax[i]<qmax[2*i+1]))
    {
        if(qmax[2*i+1]>qmax[2*i])
        {
            temp=qmax[2*i+1];
            qmax[2*i+1]=qmax[i];
            qmax[i]=temp;
            i=(2*i)+1;
        }
        else
        {
            temp=qmax[2*i];
            qmax[2*i]=qmax[i];
            qmax[i]=temp;
            i=2*i;
        }
    }
    return ;
}
void printmin()
{
    int j;
    for(j=1;j<=topmin;j++)
    {
        printf("%d ",qmin[j]);
    }
    printf("\n");
}
void printmax()
{
    int j;
    for(j=1;j<=topmax;j++)
    {
        printf("%d ",qmax[j]);
    }
    printf("\n");
}

int fun(int n1,int n2)
{
    int x;
    x=((a*n1)+(b*n2)+c)%M;
    return x;
}
int main()
{
    int test,t;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        int n,F[200001],median,i;
        long long int ans=1;
        scanf("%lld %lld %lld %d",&a,&b,&c,&n);
        F[1]=1;
        median=1;
        insertmax(1);
        for(i=2;i<=n;i++)
        {
            F[i]=fun(median,i);
            if(F[i]>median)
            {
                if(topmin>topmax)
                {
                    insertmax(qmin[1]);
                    deletemin();
                }
                insertmin(F[i]);
            }
            else
            {
                if(topmax>topmin)
                {
                    insertmin(qmax[1]);
                    deletemax();
                }
                insertmax(F[i]);
            }
           // printf("min=\n");
           // printmin();
           // printf("max=\n");
           // printmax();
            if(topmin>topmax)
            {
                median=qmin[1];
            }
            else
            {
                median=qmax[1];
            }
           // printf("median=%d\n",median);
            ans=ans+F[i];
        }
        printf("%lld\n",ans);
        topmax=0;
        topmin=0;
    }
    return 0;
}
