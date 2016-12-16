#include<stdio.h>
#include<stdlib.h>
int main()
{
    char **a,c;
    int i,start=0,end=-1,N,f=0;
    scanf("%d\n",&N);
    a = (char**)malloc(sizeof(char*)*N);
    for(i=0;i<N;i++)
        a[i] = (char*)malloc(sizeof(char)*105);
    while((c=getchar())!='Q')
    {
        //printf("Char is %c : ASCII is :%d\n",c,(int)c);
        if(c=='L')
        {
            int temp,count=f;
            for(temp=start;count--;temp=(temp+1)%N)
            {
                printf("%s\n",a[temp]);
            }
        }
        else if(c=='A')
        {
            int n;
            scanf("%d",&n);
            while(n--)
            {
                end = (end+1)%N;
                scanf("%s",a[end]);
                //printf("Debug End: %d\n",end);
                if (f==N)
                {
                    f--;
                    start = (start+1)%N;
                }
               f++;
            }
        }
        else
        {
            int n;
            scanf("%d",&n);
            while(n--)
            {
                f--;
                a[start][0]='\0';
                start = (start+1)%N;
            }
        }
        getchar();
    }
    return 0;
}
