#include<stdio.h>
void newline()
{
        printf("\n");
}
int main()
{
        int n;
        scanf("%d",&n);
        while(n--)
        {
                int q;
                int l=1,temp;
                scanf("%d",&q);
                if(q==1)
                {
                        printf("0");
                        newline();
                }
                else if(q==2)
                {
                        printf("1");
                        newline();
                }
                else if(q==3)
                {
                        printf("2");
                        newline();
                }
                else
                {
                        temp=q;
                        while(1)
                        {
                                if(temp==2)
                                        break;
                                else if(temp==3)
                                        break;
                                else
                                {
                                        temp=temp/2;
                                        l++;
                                }
                        }
                        if(temp==2)
                        {
                                printf("%d",2*l-1);
                                newline();
                        }
                        else
                        {
                                printf("%d",2*l);
                                newline();
                        }
                }
        }

        return 0;
}

