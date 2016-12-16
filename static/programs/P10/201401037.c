#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int f=0,e=1,tl=0,hd=0;
//int n;
char **a;
//char a[10011][110]={'\0'};
void enqueu(char *b,int n)
{
     if(e==1)
          e=0;
     strcpy(a[tl],b);
     if(f==1)
     {   
          // hd=(hd+1)%n;
          tl=(tl+1)%n;
          hd=(hd+1)%n;
     }
     else
          tl=(tl+1)%n;
     if(tl==hd)
     {
          f=1;
     }
}

void dequeu(int n) {
     if(f==1)
          f=0;
     //ia[hd]=0;
     if(e==1)
         return; 

     hd=(hd+1)%n;

     if(hd==tl)
     {
          e=1;
          hd=0;
          tl=0;
     }


}

/*void head()
{
     printf("%d\n",a[hd]);
}
*/
void print(int n)
{    int i3;
     if(hd==tl && e==1)
          return ;
     if(hd<tl)
     {
          for(i3=hd;i3<tl;i3++)
          {
               printf("%s\n",a[i3]);
          }
     }

     else if(hd>=tl)
     {
          for(i3=hd;i3<n;i3++)
               printf("%s\n",a[i3]);
          for(i3=0;i3<tl;i3++)
               printf("%s\n",a[i3]);
     }

   //  printf("\n");
}


int main (){
     int p,l,q,i1,i2,n,i;
     char c,b[110];

     scanf("%d\n",&n);
      
     //char **a;
     a=(char**)malloc((n+1)*sizeof(char*));
     for(i=0;i<n;i++)
     {
          a[i]=(char*)malloc((110)*sizeof(char));
     }
     while(1)
     {        
      //  getchar();
          scanf("%c",&c);
                              // printf("c=%c\n",c);
          if(c=='Q')
               break;

          if(c=='A')
          {    getchar();
               scanf("%d",&l);
               if(l==0)
                    continue;
               getchar();
               for(i1=0;i1<l;i1++)
               {
                   scanf("%s",b);
                    enqueu(b,n);
               }
               getchar();
          }

          if(c=='R')
          {    getchar();
               scanf("%d",&l);
               if(l==0)
                   continue;                // printf("l=%d\n",l);
               getchar();
               for(i1=0;i1<l;i1++)
               {
                 dequeu(n);
               }
          }

          if(c=='L')
          {  
              print(n);
              getchar();
          }

     }

     return 0;
}
