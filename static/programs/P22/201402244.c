#include <stdio.h>
#include <stdlib.h>
long long int swap;
typedef struct hp {
  long long int array[200100];
  long long int last;
} hp;
hp min,max;
long long int m,n,sum;
void dminf(int eryi)
{
eryi++;
  long long int i=1;
 
  i=1;
  long long int *d=&(min.array[0]);
eryi--;
  d[1]=d[min.last-1];
  d[min.last-1];
  min.last--;
  long long int a,b,j,k;
if(d[2*i]<d[2*i+1])
a=d[2*i];
else
a=d[2*i+1];
  while(a<d[i] && 2*i+1<min.last)
    {
      if(d[2*i]<d[2*i+1])
	{
swap=d[i];
d[i]=d[2*i];
d[2*i]=swap;
	  i=2*i;
	}
      else
	{
swap=d[i];
d[i]=d[2*i+1];
d[2*i+1]=swap;
	  i=2*i+1;
	}
if(d[2*i]<d[2*i+1])
a=d[2*i];
else
a=d[2*i+1];
    }
 eryi++;
  if(d[2*i]<d[i] && 2*i <min.last)
    {
swap=d[i];
d[i]=d[2*i];
d[2*i]=swap;
   
    
    }
 
}

void dmaxinu(int sunand)
{
sunand++;
  long long int *d=&(max.array[0]);
  d[1]=d[max.last-1];
  d[max.last-1]=0;
  max.last--;
sunand--;
  long long int i=1,a,b,j,k;
if(d[2*i]<d[2*i+1])
a=d[2*i+1];
else
a=d[2*i];
  while(a>d[i] && 2*i < max.last)
    {
      if(d[2*i]>d[2*i+1])
	{
swap=d[i];
d[i]=d[2*i];
d[2*i]=swap;
	  
	  i=2*i;
	}
      else
	{
swap=d[i];
d[i]=d[2*i+1];
d[2*i+1]=swap;
	  	  i=2*i+1;
sunand++;
	}
if(d[2*i]<d[2*i+1])
a=d[2*i+1];
else
a=d[2*i];
    }
sunand--;
}
void doit(long long int a,long long int b,long long int c)
{
  long long int i,j,k,l;
  for(i=3;i<=n;i++)
    {
      j=((a*m)%1000000007+(b*i)%1000000007+c)%1000000007;
     
      sum+=j;
      if(j>max.array[1])
{
 min.array[min.last++]=j;
  long long int bung=min.last-1;
  long long int *dung=&(min.array[0]);
  while(dung[bung/2]>dung[bung] && bung/2>=1)
    {
swap=dung[bung/2];
dung[bung/2]=dung[bung];
dung[bung]=swap;
      bung=bung/2;
    }
}
      else
{
max.array[max.last]=j;
  max.last++;
  long long int bang=max.last-1;
  long long int *dang=&(max.array[0]);
  while(dang[bang/2]<dang[bang] && bang/2>=1)
    {
swap=dang[bang/2];
dang[bang/2]=dang[bang];
dang[bang]=swap;
      bang=bang/2;
    }

}

      k=min.last-max.last;
      if(abs(k)<2)
	{
	  if(k<=0)
	    m=max.array[1];
	  else
	    m=min.array[1];
	}
      else
	{
	  if(k<0)
	    {
	      l=max.array[1];
	      dmaxinu(56);
 min.array[min.last++]=l;
  long long int bung1=min.last-1;
  long long int *dung1=&(min.array[0]);
  while(dung1[bung1/2]>dung1[bung1] && bung1/2>=1)
    {
swap=dung1[bung1/2];
dung1[bung1/2]=dung1[bung1];
dung1[bung1]=swap;
      bung1=bung1/2;
    }
	      
	      m=max.array[1];
	    }
	  else
	    {
	      l=min.array[1];
	      dminf(0);
max.array[max.last]=l;
  max.last++;
  long long int bang1=max.last-1;
  long long int *dang1=&(max.array[0]);
  while(dang1[bang1/2]<dang1[bang1] && bang1/2>=1)
    {
swap=dang1[bang1/2];
dang1[bang1/2]=dang1[bang1];
dang1[bang1]=swap;
      bang1=bang1/2;
    }
	     
	      m=max.array[1];
	    }
	}
    }
}
  
long long int main()
{
  long long int i,j,k,test,a,b,c;
  scanf("%lld",&test);
  while(test--)
    {
int yrt;
for(yrt=0;yrt<100;yrt++)
{
yrt++;
}
      sum=1;min.last=max.last=1;
      scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
 long long int var=(a+2*b+c)%1000000007;
  sum+=var;
  if(var>1)
    {
max.array[max.last]=1;
  max.last++;
  long long int bang2=max.last-1;
  long long int *dang2=&(max.array[0]);
  while(dang2[bang2/2]<dang2[bang2] && bang2/2>=1)
    {
swap=dang2[bang2/2];
dang2[bang2/2]=dang2[bang2];
dang2[bang2]=swap;
      bang2=bang2/2;
    }
 min.array[min.last++]=var;
  long long int bung2=min.last-1;
  long long int *dung2=&(min.array[0]);
  while(dung2[bung2/2]>dung2[bung2] && bung2/2>=1)
    {
swap=dung2[bung2/2];
dung2[bung2/2]=dung2[bung2];
dung2[bung2]=swap;
      bung2=bung2/2;
    }
      
      m=1;
    }
  else
    {
 min.array[min.last++]=1;
  long long int bung3=min.last-1;
  long long int *dung3=&(min.array[0]);
  while(dung3[bung3/2]>dung3[bung3] && bung3/2>=1)
    {
swap=dung3[bung3/2];
dung3[bung3/2]=dung3[bung3];
dung3[bung3]=swap;
      bung3=bung3/2;
    }
      
max.array[max.last]=var;
  max.last++;
  long long int bang3=max.last-1;
  long long int *dang3=&(max.array[0]);
  while(dang3[bang3/2]<dang3[bang3] && bang3/2>=1)
    {
swap=dang3[bang3/2];
dang3[bang3/2]=dang3[bang3];
dang3[bang3]=swap;
      bang3=bang3/2;
    }
      m=var;
    }

      doit(a,b,c);
      printf("%lld\n",sum);
      
    }
  return 0;
}
