#include<stdio.h>
typedef long long int ll;
void merge(ll A[],ll start,ll mid,ll end);
void sort(ll A[],ll start,ll end)
{
  ll mid;
  if(start<end)
  {
    mid=(start+end)/2;
    sort(A,start,mid);
    sort(A,mid+1,end);
    merge(A,start,mid,end);
  }
}

void merge(ll A[],ll start,ll mid,ll end)
{
  ll i,j,k,m,temp[100001];
  i=start;
  j=start;
  m=mid+1;

  while(i<=mid&&m<=end)
  {
    if(A[i]<=A[m])
    {
      temp[j]=A[i];
      i++;
    }
    else
    {
      temp[j]=A[m];
      m++;
    }
    j++;
  }

  if(i>mid)
  {
    k=m;
    while(k<=end)
    {
      temp[j]=A[k];
      k++;
      j++;
    }

  }
  else
  {
    k=i;
    while(k<=mid)
    {
      temp[j]=A[k];
      k++;
      j++;
    }
  }
  for(k=start;k<=end;k++)
    A[k]=temp[k];
}

int main()
{
  ll t,test,i,A[100000],flag=0,count=0,pairc=0,countz=0,n;
  char str[100000];
  scanf("%lld",&test);
  for(t=0;t<test;t++)
  {
    scanf("%s",str);
//    printf("%c",str[0]);

    if(str[0]=='J')
      A[0]=-1000000;
    else if(str[0]=='M')
      A[0]=1000001;
    else if(str[0]=='R')
      A[0]=-1;

    for(i=1;str[i]!='\0';i++)
    {
      if(str[i]=='J')
        A[i]=A[i-1]+(-1000000);
      else if(str[i]=='M')
        A[i]=A[i-1]+1000001;
      else if(str[i]=='R')
        A[i]=A[i-1]-1;
    }
    n=i;
    
//    for(i=0;i<n;i++)
  //  printf("%d ",A[i]);
   // printf("\n");
    
    flag=0,count=0,pairc=0,countz=0;
    sort(A,0,n-1);


//    for(i=0;i<n;i++)
 //     printf("%d ",A[i]);
  //  printf("\n");

    for(i=0;str[i]!='\0';i++)
    {
     // flag=0,count=0,pairc=0,countz=0;
      if(A[i]==0)
       countz++;
      if(A[i]==A[i+1]&&i<n-1)
      {
        flag=1;
        count++;
      }
      else if(A[i]!=A[i+1]||A[n-2]==A[n-1])
      {
        count++;
        flag=0;
        pairc+=(((count)*(count-1))/2);
        count=0;
      }
    }


   // printf("ZERO %d\n",countz);
    pairc+=countz;
    printf("%lld\n",pairc);
  }
  return 0;
}
