#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct trie{
     struct trie* pt[12];
     char c;
     char e;
}tr;

tr* head=NULL;
int fl=0;
void insert(char *a)
{
     int i=0,j; tr* temp=head;
     if(a[0]=='\0')
          return ;
     while(a[i]!='\0')
     {
          if(head==NULL)
          {
               head=(tr*)malloc(sizeof(tr));
               head->c='@';
               temp=head;
               for(j=0;j<11;j++)temp->pt[j]=NULL;
               temp->pt[a[i]-'0'+1]=(tr*)malloc(sizeof(tr));
               temp->pt[a[i]-'0'+1]->c=a[i];
               temp=temp->pt[a[i]-'0'+1];
               for(j=0;j<11;j++)temp->pt[j]=NULL;
          }

          else
          {
               while(temp->pt[a[i]-'0'+1]!=NULL)
               {
                    temp=temp->pt[a[i]-'0'+1];
                    i++;
                    if(a[i]=='\0')
                    { temp->e='*';
                         fl=1;
                         return ;
                    }
               }
               if(temp->e=='*')
                    fl=1;
               temp->pt[a[i]-'0'+1]=(tr*)malloc(sizeof(tr));
               temp->pt[a[i]-'0'+1]->c=a[i];
               temp=temp->pt[a[i]-'0'+1];
               for(j=0;j<11;j++)temp->pt[j]=NULL;
          }
          i++;
     }
     temp->e='*';
}
void freef(tr* temp)
{
     int i,k;               // printf("func\n");
     if(temp==NULL)
          return ;
     for(i=0;i<11;i++)
     {
          if(temp->pt[i]!=NULL)
               freef(temp->pt[i]);
     }
 
     temp=NULL;
     free(temp);
}


int main(){
     int i,j,n,test,i1;
     char a[15];
     scanf("%d",&test);

     for(i1=0;i1<test;i1++)
     {
          fl=0;
          scanf("%d\n",&n);
          for(i=0;i<n;i++)
          {
               scanf("%s",a);
               insert(a);
          }
          //scanf("%s",b);
          // printf("%d\n",match(b));
          if(fl==1)
               printf("NO\n");
          else
               printf("YES\n");
          freef(head);
          head=NULL;
     }

     return 0;
}
