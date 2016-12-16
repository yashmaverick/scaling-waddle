#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int start=0,end=0,count=0;


int main()
{
    int i,j,k,l,n;
    scanf("%d",&n);
    getchar();
    char arr[n][100],option,c[100];
    option=getchar();
    while(option!='Q')
    {
        void print(int ss,int ee)
        {
            int k,l;
            for(k=ss;k<ee;k++)
            {
                for(l=0;arr[k][l]!='\0';l++)
                    printf("%c",arr[k][l]);
                printf("\n");
            }
        }
        if(option=='A')
        {
            int ii;
            scanf("%d",&ii);
            for(j=0;j<ii;j++)
            {
                scanf("%s",c);
                if(start==end&&count!=0)
                {
                    start++;
                    count--;
                    if(start>=n)
                        start=start%n;
                }
                for(i=0;c[i]!='\0';i++)
                {
                    arr[end][i]=c[i];
                }
                arr[end][i]='\0';
                end++;
                count++;
                if(end>=n)
                    end=end%n;
            }
        }
        if(option=='L')
        {
            if (!(start==end&&count==0))
            {
                if(start<end)
                    print(start,end);
                else
                {
                    print(start,n);
                    print(0,end);
                }
            }
        }
        if(option=='R')
        {
            scanf("%d",&j);
            for(i=0;i<j;i++)
            {
                if(count==0)break;
                start=(start+1)%n;
                count--;
            }
        }
        option=getchar();
    }
    return 0;
}
