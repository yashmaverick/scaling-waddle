#include <stdio.h>

int main()
{
    int n, i;
    scanf("%d",&n);
    
    for(i=0;i<n;++i)
    {
        int q;
        scanf("%d",&q);
        
        int qs = q, qn;
        int h = 0;
        while(q)
        {
            q /= 2;
            h++;
        }
        
        int qf = (1<<h)-1;
        int qh = qf/2;
        int qm = qh+((qh/2)+1);
        
        if(qs==1)
            printf("0\n");
        else if(qs>qm)
        {
            printf("%d\n",(h-1)*2);
        }
        else
        {
            printf("%d\n",((h-1)*2)-1);
        }
    }
    
    return 0;
}