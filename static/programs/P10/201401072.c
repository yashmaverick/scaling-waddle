#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    char *s[n];
    int i,j,head=-1,tail=-1,x;
    for(i=0;i<n;i++)
    {
        s[i]=(char *)malloc(sizeof(char)*101);
    }
    char c,l[101];
    do {
        c=getchar();
        switch(c)
        {
            case 'A':
                {
                  //  printf("head is %d and tail is %d\n",head,tail);
                    scanf("%d",&x);
                    while(x--)
                    {
                        if(head==-1)
                            head=0;
                        if((tail==head-1||tail==n-1&&head==0)&&tail!=-1)
                            if(head==n-1)
                                head=0;
                            else
                            head++;
                        if(tail==n-1)
                            tail=0;
                        else
                            tail++;
                        scanf("%s",s[tail]);
                    }
                 //  printf("head is %d and tail is %d\n",head,tail);
                    break;

                }
            case 'R':
                {
                    int x;
                    scanf("%d",&x);
                 //   printf("head is %d and tail is %d\n",head,tail);

                    if(head!=-1)
                    {
                       // printf("entered loop 1\n");
                        if((tail-head+1)>x||((n-head+tail+1)>x&&tail<head))
                        {
                         //   printf("entered loop 2\n");
                            if(tail<head)
                            {
                            if(n-head>=x)
                            {
                       //     printf("entered case 1\n");
                                if(n-head==x)
                                    head=0;
                                else
                                    head+=x;
                            }
                            else {
                     //       printf("entered case 2\n");
                                x-=n-head;
                                head=x;
                            }
                            }
                            else {
                                head+=x;
                            }
                        }
                        else {
                            head=tail=-1;
                        }
                    }
                 //  printf("head is %d and tail is %d\n",head,tail);
                    break;
                }
            case 'L':
                {
                 //   printf("head is %d and tail is %d\n",head,tail);
                 if(head!=-1)
                {
                for(i=head;i!=tail;i=(i+1)%n)
                    printf("%s\n",s[i]);
                    printf("%s\n",s[tail]);

                }
               //     printf("head is %d and tail is %d\n",head,tail);
                break;
                }
            default:
                break;
        }

    } while (c!='Q');

return 0;
    }
