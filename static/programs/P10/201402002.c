#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

char buff[10010][110];

void print(int n, int ELEMENTS, int E)
{
    if (ELEMENTS == 0)
        return;
    if (E<=0)
        E=n;
    print(n,ELEMENTS-1,E-1);
    printf("%s\n",buff[E-1]);
}

int main()
{
    int n,i,ELEMENTS=0,E=0;    //E stores index of next element after last element // S stored index of first element
    scanf("%d",&n);

    while(1)
    {
        char t;
        scanf(" %c",&t);

        if (t=='A')
        {
            int l,j;
            scanf("%d ",&l);
            ELEMENTS+=l;

            if (ELEMENTS>n)
                ELEMENTS=n;

            for(j=0;j<l;j++)
            {
                scanf("%s",buff[E]);
//                printf("E is %d Saved string is: %s\n",E ,buff[E]);
                E++;
                if (E>=n)
                    E=0;
            }
        }
        else if (t=='R')
        {
            int del,j;
            scanf("%d",&del);
            ELEMENTS-=del;
        }
        else if (t=='L')
        {
            print(n,ELEMENTS,E);
        }
        else if (t=='Q')
            break;
        else
            printf("ENTER Correct value\n");
    }
    return 0;
}
