#include<stdio.h>
#include<stdlib.h>
typedef long long int lld;
lld l;
#define scanint(l) scanf("%lld",&l)

/*#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked
typedef long long int lld;
typedef unsigned long long llu;
typedef long int ld;
#define pb push_back

int  comp(const void *a,const void *b)
{ 
    return *(lld*)a-*(lld*)b;
}

void scanint(lld &x)
{  x=0;
    char c=gc();

    while(c<'0'|| c>'9')
        c=gc() ;               
    for(;c>='0' && c<='9';c=gc())
    { 
        x=x*10+c-48;            
    }
}


inline void outno(int n)
{
    int i=0;
    char ch[20];
    if(n<0)
        if(n==0) pc('0');
        else
            pc('-'),n=n*(-1);

    while(n>0)
    {  ch[i]=n%10 +'0';
        n=n/10;
        i++;
    }

    while(i>0)
    { 
        pc(ch[i-1]);
        i--;
    }
    pc(' ');
}

inline void getstring(char *s)
{
     char ch;
     ch=gc();
     int i=0;
     while((ch>=32)&&(ch<=110))
     {
          s[i++]=ch;
          ch=gc();
     }

     s[i]='\0';
}

inline void putstring(char *s)
{
     int i=0;
     while(s[i]>=32 && s[i]<=127)
     {
          pc(s[i]);
          i++;
     }
     pc('\n');
}
*/
int main(){
     lld n,test,i,j,i1,max,min,b[100010],a[100010];
     scanint(test);
    // lld *a;

     for(i1=0;i1<test;i1++)
     {
          scanint(n);  max=-10000000000; 
      //    a=(lld*)malloc((n+1)*sizeof(lld));
          for(i=1;i<=n;i++)
          {  scanint(a[i]);
          }
          j=n-1; b[0]=0;  b[n]=0;
          for(i=n;i>1;i--)
          {
               b[j--]=a[i]-a[i-1];
               if(a[i] > a[i-1])
               {
                  int temp=a[i];a[i]=a[i-1]; a[i-1]=temp;
               }
          }

          for(i=1;i<n;i++)
               if(b[i]>max)
                    max=b[i];
          if(max<0)
            max=0;
         
          printf("%lld\n",max);

     
     // free(a);
     
     }

     return 0;
}

