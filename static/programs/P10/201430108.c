#include <stdio.h>
char a[10000][111];
int main()
{   
    int start = -1,end=-1;
    int n,m;
    char q;
    scanf("%d",&n);
    scanf("%s",&q);
    int temp;
    while (1)
    {   

        if(q=='A') 
        {
            scanf("%d",&m);
            while (m--) 
            {
                start++;
                start%=n;
                if(start==end&&a[end][0]!='\0')
                    {
                        end++;
                        end%=n;
                    }
                    scanf("%s",a[start]);
                if(end==-1&&start>= 0)
                    end=0;
            }
        }
        else if (q=='R') 
        {
            scanf("%d",&m);
            while (m--) 
            {
                a[end][0]='\0';
                end++;
                end%=n;
            }
        }
        else if (a[end][0]!='\0'&&q=='L') 
        {
            temp=end;

            while(temp!=start) 
            {
                printf("%s\n",a[temp]);
                temp++;
                temp%=n;
            }

            printf("%s\n",a[temp]);
        }
        if(q=='Q')
        return 0;
        scanf("%s",&q);
    }
    return 0;
}
