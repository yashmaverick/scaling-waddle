#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define f(d) scanf("%[^\n]",d)
#define g(x) scanf("%d",&x)
int N;
typedef struct buffer
{
    char name[100];
}buffer;
int main()
{int i,j,a,b,number=0,n,ti=0,initial=0,d,c,point=0,last=0;
    char r,t;
    buffer *w;
    g(N);
  w = (buffer *)malloc(sizeof(buffer)*N);
    getchar();
    while((c=getchar())!='Q')
    {
        if(c == 'A')
        {g(n);
            getchar();
            for(i=initial+number;i<initial+number+n;i++)
            {
               f(w[i%N].name);
               getchar();
            }
            number=number+n;
            if(number>N)
            {   initial=initial+number-N;
                number=N;
            }

}
            if(c == 'R')
            {
                g(a);
                initial=initial+a;
                number=number-a;
               if( number<=0)
                number=0;
            }
            if( c == 'L')
            {
                b=0;
                d=initial;
                while( b<number)
                {
                    printf("%s\n",w[d%N].name);
                    d++;
                    b++;
                }
            }
        }
free(w);
        return 0;
    }
