#include<stdio.h>
#include<math.h>
int main()
{
    int N,Q;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&Q);
        int temp=Q;
        int cnt=0;
        while(temp!=0)
        {
            temp/=2;
            cnt++;
        }
        int cnt1=cnt-1;
        int p1,p2;
        p1=pow(2,cnt);
        p2=pow(2,cnt1);
        if(Q<(p1+p2)/2)
            printf("%d\n",2*cnt1-1);
        else
            printf("%d\n",2*cnt1);
    }
    return 0;
}
