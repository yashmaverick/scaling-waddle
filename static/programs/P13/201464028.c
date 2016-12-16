#include<stdio.h>
#include<stdlib.h>
#define g(x) scanf("%d",&x)
int max_depth,count,number_maxdepth,*X;
int search(int start,int end,int val)
{
    if(X[start]<val && X[end]>val && (end-start) ==1)
        return start;
    else if(val>X[end])
        return end;
    else if(val<X[start])
        return end;
    else
    {
        int middle=(start+end)/2;
        if(X[middle]<val)
            return search(middle,end,val);
        else
            return search(start,middle,val);
    }}
void max( int start,int end,int value)
{
    int i;
    if( start == end)
    { //value++;
        if(value>=max_depth)
        {// printf("%d %d\n",X[end],count);
            if(value == max_depth)
            {
                if(X[end]<number_maxdepth)
                    number_maxdepth=X[end];
            }
            else
            {max_depth=value;
                number_maxdepth=X[end];}
        }
    return ;
    }
    else
    {int i=end-1,f;
        value++;
        f=search(start,end-1,X[end]);
        max(start,f,value);
       // printf("%d ",f);
        if((f+1)<(end-1))
        max(f+1,end-1,value);
        else
            max(end-1,end-1,value);

        




    }}
int main()
{int i,j,t,n;
    g(t);
    for(i=0;i<t;i++)
    {max_depth=0;
        count=0;
        g(n);
        X=malloc(sizeof(int)*n);
        for(j=0;j<n;j++)
        g(X[j]);
       // number_maxdepth=X[n-1];
        max(0,n-1,count);
        printf("%d %d\n",number_maxdepth,max_depth);
    }
    return 0;
}











