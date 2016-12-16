#include <stdio.h>
typedef long long int LL;
char x[10005][102];
int main()
{
   int c,i,num;
   int start,end,bufs,els;
   start = end = -1;
   scanf("%d",&bufs);
   getchar();
   while((c=getchar())!='Q')
   {
      getchar();
      if(c=='A')
      {
         scanf("%d",&num);
         getchar();
         while(num--)
         {
            if(start==end && start==-1)
            {
               start = end = 0;
               scanf("%s",x[end]);
            }
            else if((end+1)%bufs==start)
            {
               end = (end+1)%bufs;
               start = (start+1)%bufs;
               scanf("%s",x[end]);
            }
            else 
            {
               end = (end+1)%bufs;
               scanf("%s",x[end]);            
            }
            getchar();
         }
      }
      else if(c=='L')
      {
         if(start==-1 && start==end)
            continue;        
         else
         {
            for(i=start;i!=end;i++,i=i%bufs)
            {
               printf("%s\n",x[i]);
            }
            printf("%s\n",x[i]);
         }
      }
      else if(c=='R')
      {
         scanf("%d",&num);
         getchar();
         if(start==end && start==-1)
            continue;
         if(end >= start)
            els = (end - start + 1);
         else 
            els = (end + bufs - start + 1);
         if(num>=els)
            start=end=-1;
         else
            start = (start+num)%bufs;
      }
   }
   return 0;
}
