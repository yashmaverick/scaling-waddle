#include<stdio.h>
int top=-1,A[100001],S[100001],L[100001],n,max=0,value;
void push(int i)
{
    top=top+1;
    S[top]=i;
}
void pop()
{
    if(top==-1)
        return ;
    else
        top=top-1;
}
void create(int n)
{
    top=-1;
    int i,bar;
    i=n-1;
    while(i>=0)
    {
        if(top==-1 || A[S[top]]<A[i])
        {
            push(i);
            i--;
        }
        else
        {
            bar=S[top];
            pop();
            L[bar]=i;
        }
    }
    //    L[0]=-1;
}
void print(int left,int right,int count,int root) //root is index of root element
{
    int l,r;
    l=L[root];r=root;
    if(left>=right)
    {
        if(left==right)count++;
        //printf("l=%d\n",l);
        //printf("r=%d\n",r);
        if(max<count){max=count;value=A[left];}
    }
    else
    {count++;print(left,L[r]-1,count,L[r]);print(l+1,r-2,count,r-1);}
}
void scan(int n)
{
    int i;
    for(i=0;i<n;i++)scanf("%d",&A[i]);
}
int main()
{
    int i,t,k;
    scanf("%d",&t);
    for(k=0;k<t;k++)
    {max=0;scanf("%d",&n);scan(n);create(n);print(0,n-2,0,n-1);printf("%d %d\n",value,max);
    }
    return 0;
}
