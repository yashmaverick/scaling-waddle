#include<stdio.h>
int ans(int preord[],int inord[],int n,int x,int y);

int main()
{
    int i,t,n,x,y;
    scanf("%d",&n);
    int preord[n];
    int inord[n];
    for(i=0;i<n;i++)
        scanf("%d",&preord[i]);
    for(i=0;i<n;i++)
        scanf("%d",&inord[i]);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&x,&y);
        //func
        printf("%d\n",ans(preord,inord,n,x,y));
        
    }
    return 0;
}

int ans(int preord[],int inord[],int n,int x,int y)
{
    int beg,end,i,j;
    for(i=0;i<n;i++)
    {
        if(inord[i]==x)
            beg=i;
        else if(inord[i]==y)
            end=i;

    }
    if(beg > end)
    {
        int temp=beg;
        beg=end;
        end=temp;
    }

    for(i=0;i<n;i++)
    {
        for(j=beg;j<=end;j++)
        {
            if(preord[i]==inord[j])
                return preord[i];
        }
    }
}
