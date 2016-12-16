#include<stdio.h>
int main() 
{
        int SIZE,n,i;
        int  r = 0, no =0;
        scanf("%d",&SIZE);
        char op,str[SIZE][100];
        do 
        {
                scanf("%c", &op);
                switch (op) 
                {
                        case 'A':
                                scanf("%d", &n);
                                //append(str[100],n,N);
                                //              int i;
                                no+=n;
                                if (no>SIZE)
                                        no=SIZE;
                                for(i=0;i<n;i++)
                                {
                                        if(r==SIZE)
                                                r=0;
                                        scanf("%s", str[r++]);
                                }
                                
                                break;
                        case 'R':
                                scanf("%d", &n);
                                no-=n;
                                break;
                        case 'L':
                                //list(N,str);
                                if(r-no<0)
                                        i=r-no+SIZE;
                                else
                                        i=r-no;
                               
                                int temp=no;
                                while(temp--)
                                {
                                        if (i==SIZE)
                                                i=0;
                                        printf("%s\n", str[i]);
                                        i++;
                                }
                                break;
                        case 'Q':
                                break;
                }
        } while (op != 'Q');
        return 0;
}
