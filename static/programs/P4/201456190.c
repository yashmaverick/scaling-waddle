#include<stdio.h>
#include<stdlib.h>
char a[100000];
long long int s1[100000];

 int cmpfunc(const void * a, const void * b)
{
       return ( *( int*)a - *( int*)b );
}

int main()
{
    int test,q;
    scanf("%d",&test);
    for(q=0;q<test;q++)
    {
    long long int i,n=0;
    long long int x=1000;
    long long int y=-999;
    long long int z=-1; 
    scanf("%s",a);

    long long int ans=0;
    for(i=0;a[i]!='\0';i++)
    {
      if(a[i]=='j'|| a[i]=='J')
      {
	  ans=ans+x;
	  
      }
      else if(a[i]=='m'|| a[i]=='M')
      {
	  ans=ans+y;
	  
      }
      else if(a[i]=='r' || a[i]=='R')
      {
	  ans=ans+z;
	  
      }
    //  printf("%lld",ans);
      s1[i]=ans;
      n++;
    }
//for(i=0;i<n;i++)
  //  printf("%lld ",s1[i]);
qsort(s1, n, sizeof(long long int), cmpfunc);
/* for(i=0;i<n;i++)
{
    printf("%lld ",s1[i]);
}
*/
long long int current=s1[0];
long long int count=1,newcount=0;
long long int answer=0;
if(s1[0]==0)
    newcount++;
for(i=1;i<n;i++)
{
    if(s1[i]==0)
    {
	newcount++;
    }
    if(s1[i]==current)
    {
	count++;
    }

    else 
    {
	answer=answer+(count*(count-1))/2;
	count=1;
	current=s1[i];
    }
}
answer =answer+(count*(count-1))/2;

printf("%lld\n",answer+newcount); 
}
return 0;
}
