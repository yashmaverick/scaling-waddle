#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define gc getchar_unlocked

void si(int *p)
{ int x =0,neg=0;
     char c=gc();
    //  if(c=='-'){ neg=-1; printf("bb") ;} 
     while((c<'0'|| c>'9') && c!='-')
          c=gc();
     if(c=='-') {neg=1; c=gc();} 
     for(;c>='0' && c<='9';c=gc())
     {
          x=x*10+c-48;
     }
     if(neg==1)         
       x=-1*x;
                        
          *p=x;
}

inline void getstr(char *a)
{
     char c;
     c=gc();
     int i=0;
     while(c>='A' && c<='Z')
     {
          a[i++]=c;
          c=gc();
     }
     a[i]='\0';
}

typedef struct two{
     int m_j;
     int m_r;
}tw;                         // STRUCT DECLARATION

void swap(int *a,int *b)    // SWAP FUNCTION
{  int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int comp(const void *a,const void *b)   // COMPARATOR FUNCTION
{
     tw *p=(tw*)a;
     tw *q=(tw*)b;

     if((p->m_j) >(q->m_j ))
               return 1;
     else if((p->m_j)< (q->m_j))
          return -1;
     else if((p->m_j==(q->m_j)))
     {
          if((p->m_r)>=(q->m_r))
               return 1;
          else if((p->m_r)< (q->m_r))
               return -1;
     }
}

long long int final(int a)    // NCR FUNCTION
{
     return (a*(a-1))/2 ;
}
              
int main(){
     tw t[100010];
     int i,m,r,j,test,l,i1,count;
     char a[100010];
     long long int ans=0;
     
     si(&test);

     for(i1=0;i1<test;i1++)
     {    count=0; ans=0;
          getstr(a);
          m=0; j=0; r=0;
          l=strlen(a);

         for(i=0;a[i];i++)
          {
               t[i].m_j=m-j;
               t[i].m_r=r-m;
               if(a[i]=='M')
                    m++;
               else if(a[i]=='J')
                    j++;
               else if(a[i]=='R')
                    r++;

               //t[i].m_j=m-j;
               //t[i].m_r=r-m;
          }
               t[i].m_j=m-j;     // last node
               t[i].m_r=r-m;     
                   
             l=i+1;                                 //int i11; for(i11=0;i11<l;i11++) printf("%d %d \n",t[i11].m_j,t[i11].m_r);
          qsort(t,l,sizeof(tw),comp);

                                                 // int i11;   for(i11=0;i11<l;i11++) printf("%d %d \n",t[i11].m_j,t[i11].m_r);
          for(i=0;i<l;)
         {     count=0;
               for(j=i+1;j<l && t[i].m_j==t[j].m_j && t[i].m_r==t[j].m_r;j++)
               {
                    count++;
               }
            count=j-i;
                                                                   //printf("count= %d \n",count);
               ans+=final(count);
              i=j; 
              count=0;
         }

          printf("%lld\n",ans);
     }

     return 0;
}
