#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
    char arr[10000][100],p,q;
    int i,j,k,m,l,first,last,N,n,z;
    scanf("%d",&N);
    scanf("%c",&p);
    int ap=0;
    int ne=0;
    int pp=0;
    while(p!='Q')
    {
        if(p=='A')
        {
            scanf("%d",&n);
            for(i=ap;i<ap+n;i++)
            {
                k=i;
                if(k>=N)
                    k=k-N;
                scanf("%s",arr[k]);
            }

            ap=ap+n;
            if(ap>=N)
                ap=ap-(N);

            ne=ne+n;
            if(ne>N)
                ne=N;
            pp=ap-ne;
            if(pp<0)
                pp=N+pp;
        }

        else if(p=='R')
        {
            scanf("%d",&n);
            ne=ne-n;
            pp=ap-ne;
            if(pp<0)
                pp=pp+ne;
        }
        else if(p=='L')
        {
            pp=ap-ne;
            if (pp<0)
                pp=pp+N;

            if(pp<ap)
                for(i=pp;i<ap;i++)
                {
                    k=i;
                    if(k==N)
                        k=0;
                    printf("%s\n",arr[k]);
                }
            else if(pp==ap && ne==0)
            {}
            else
            {
                for(i=pp;i<N;i++)
                    printf("%s\n",arr[i]);
                for(i=0;i<ap;i++)
                    printf("%s\n",arr[i]);
            }
        }
        scanf("%c",&p);
    }
    return 0;
}
