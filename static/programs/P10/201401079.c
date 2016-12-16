#include<stdio.h>
#include<string.h>
struct buffer
{
    char str[101];
};
int main()
{
     struct buffer p[10001];
     char c;
     char s[101];
     int head=-1,tail=-1,N,n,i,r,count=0;
     scanf("%d",&N);
     while(1)
     {
          scanf("%c",&c);
          if(c=='A')

          {
               scanf("%d",&n);
               for(i=0;i<n;i++)
               {
                   tail=(tail+1)%N; 
                    if(tail==(head+1)%N && count >= N )
                    head=(head+1)%N;
     //               else if(tail==0 && tail==(head+1)%N)
       //                 head=(head+1)%N;
                   scanf("%s",s);
                         strcpy(p[tail].str,s);
                         count++;
               }
          }
          else if(c=='R')
          {
               scanf("%d",&r);
               for(i=0;i<r;i++)
               {
                    if(tail!=-1)
                    head=(head+1)%N;
                    if(head==tail)
                    {
                         head=tail=-1;
                         count=0;
                    }
               }
          }
          else if(c=='L')
          {
                  if(tail>head )
                  {
                       for(i=head+1;i<=tail;i++)
                            printf("%s\n",p[i].str);
                  }
                  else if(tail<=head && tail!=-1)
                  {
                       for(i=head+1;i<N;i++)
                            printf("%s\n",p[i].str);
                       for(i=0;i<=tail;i++)
                       {
                            printf("%s\n",p[i].str);
                       }

                  }
          }


          
          else if(c=='Q')
               break;
     }
     return 0;

}

