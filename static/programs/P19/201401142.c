#include <stdio.h>
#include <stdlib.h>
#define INTS(X) scanf("%d",&X);
//Structures
typedef struct tri{
   struct tri* next[10];
}TR;
typedef TR* T;
//GLobals.
int dumdum;
TR dummy; //For \0
T dum = &dummy;
char x[11]; //For 10 digit number.
T tinsert(T head,int ptr)
{
   if(x[ptr]=='\0')
   {
      if(head!=NULL)
      {
       //  printf("Setting dum dum 1\n");
         dumdum = 1;
      }
      return  dum;
   }
   if(head==NULL)
   {
      head = (T)malloc(sizeof(TR));
      int i;
      for(i=0;i<10;i++)
         head->next[i] = NULL;
   }
   else if(head==dum)
   {
     // printf("Here\n");
     // printf("Setting dum dum 1\n");
      dumdum = 1;
      return dum;
   }
  // printf("Inserting %d\n",x[ptr]-'0');
   head->next[x[ptr]-'0'] = tinsert(head->next[x[ptr]-'0'],ptr+1);
   if(dumdum==1)
      return dum;
   //printf("Head is %llu\n",(unsigned long long)head);
   //printf("Inserting %d\n",x[ptr]-'0');
   //printf("Inserting %d\n",x[ptr]-'0');
   return head;
}
int main()
{
   int t;
   INTS(t);
   getchar();
   while(t--)
   {
      T root = NULL;
      dumdum = 0;
      int num,j;
      INTS(num);
      getchar();
      while(num--)
      {
         //printf("Ready to scna\n");
         scanf("%s",x);
         if(dumdum==1)
            continue;
     //    printf("Scanned %s\n",x);
         root = tinsert(root,0);
      }
      if(dumdum==1)
         printf("NO\n");
      else
         printf("YES\n");
   }
   return 0;
}
