#include<stdio.h>
#include<stdlib.h>
 long long int mount[500002];
 long long int N;
long long  int no_cases;
struct stackitem{
   long long int   data;
  long long int index;
};
long long int maxarea1(  long long int a[],  long long int n);
long long int maxarea( long long int a[],  long long int n);
long long int maxarea2(  long long int a[],  long long int n);
int main()
{
   long long int i;
  scanf("%lld",&N);
  while(N!=0)
  {
    for(i=0 ; i < N ; i++)
    {
      scanf("%lld",&mount[i]);
    }
    no_cases=maxarea(mount,N)+maxarea1(mount,N)+maxarea2(mount,N);
   printf("%lld\n",((N*(N-1))/2)-no_cases);
   scanf("%lld",&N);
  }
  return 0;
}
long long int maxarea( long long int a[],long long int n)
{
  long long int i,top=-1;
      long long currentno=0;
  struct stackitem *S=(struct stackitem*)malloc(sizeof(struct stackitem)*n);
  for(i=n-1 ; i >=0 ; i--)
  {
    while(top>=0 && ((S[top].data)<a[i]))
    {
      currentno=currentno+1;
      --top;
    }
    if(i<n)
    {
      ++top;
      S[top].data=a[i];
      // S[top].index=i;
    }
    //printf("i am top %d--\n",top);
     //printf("%d THE VALUE OF CURRENT ELWMENR\n",a[i]);
  }
//    printf("i am currentno %lld--\n",currentno);
  free(S);
  return currentno;
}
long long  int maxarea1(  long long int a[],  long long int n)
{
 long long  int currentno1=0;
   long long int i,top=-1;
  struct stackitem *S=(struct stackitem*)malloc(sizeof(struct stackitem)*n);
  for(i=0 ; i <n ; i++)
  {
    while(top>=0 && ((S[top].data)<a[i]))
    {
      currentno1=currentno1+1;
      --top;

    }
    if(i<n)
    {
      ++top;
      S[top].data=a[i];
      //S[top].index=i;
    }
  }
  //      printf("i am currentno1 %lld--\n",currentno1);
  free(S);
  return currentno1;
}
long long int maxarea2(long long   int a[],  long long int n)
{
  
  long long int currentno1=0;
       long long int i,top=-1;
  
  struct stackitem *S=(struct stackitem*)malloc(sizeof(struct stackitem)*n);
  for(i=0 ; i <n ; i++)
  {
   //printf("the value of i anlld top %lld %lld\n",i,top);
    while(top>=0 && i< n )
    {	//printf("%lld(index)---%lld(data)\n",S[top].index,S[top].data);
  //printf("i am  sir currentno1 %lld--\n",currentno1);
    //printf("i am in while\n") ; 
      if ((S[top].data)>a[i])
      {
	if(i<n)
	{
	  ++top;
	  S[top].data=a[i];
	  S[top].index=1;
	}
	i++;
	continue;
        }
	 if ((S[top].data)==a[i])
	{
	(S[top].index)++;
	i++;
	continue;
	}
	if((S[top].data)<a[i])
	{
	  if((S[top].index)>=2)
	  {
	currentno1=(((S[top].index)*((S[top].index)-1))/2)+currentno1;
	 //printf("i am currentno1 %lld \n",currentno1);
	  }
	top--;
	//i++;
	continue;
	}
    }
    
    if(i<n)
    {
      ++top;
      S[top].data=a[i];
      S[top].index=1;
    }
  }
  //printf("%lld\n",top);
  for(i=top ; i>=0 ; i--)
  {
	  if((S[top].index)>=2)
	  {
	currentno1=(((S[top].index)*((S[top].index)-1))/2)+currentno1;
//	 printf(" i %lld\n",S[top].index);
	  }
	top--;
  
  
  }
  //printf("i am  currentno2 %lld--\n",currentno1);
      
  free(S);
  return currentno1;
}

