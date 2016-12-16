#include<stdlib.h>
#include<stdio.h>
long long  maxarea(long long int stack[],long long int n); 
//long long int height[]
long long  stack[100001];
struct stackitem{
  long long  data;
  long long  index;
};
long long int no_logs;
int main()
{
  long long int i,no_logs;
//  scanf("%lld",&test_cases);
  while(1)
  {
    long long int max_area;
    scanf("%lld",&no_logs);
    if(no_logs==0)
      break;
    else
    {
      for(i=0 ; i<no_logs ; i++)
      {
	scanf("%lld",&stack[i]);
      }  
    }
    max_area=maxarea(stack,no_logs); 
    printf("%lld\n",max_area);
  }
  return 0;
}
long long int maxarea(long long int a[],long long int n)
{
  long long int i,maxarea=-1,top=-1,left,currentarea=0;
  struct stackitem *S=(struct stackitem*)malloc(sizeof(struct stackitem)*n);
  for(i=0 ; i <=n ; i++)
  {

    while(top>=0 && (i==n ||(S[top].data)>=a[i]))
      {
	if(top>0)
	  left=S[top-1].index;
	else
	  left=-1;
    //printf("%dTHE VALUE OF S[TOP]DATA\n",S[top].data);
  //  printf("%d THE VALUE OF i\n",i);
//    printf("i am left %d--\n",left);
	currentarea=(i-left-1)*S[top].data;
	--top;

	//    printf("i am currentarea %d--\n",currentarea);
	if(currentarea>maxarea)
	  maxarea=currentarea;
	//      printf("i am maxarea %d--\n",maxarea);
      }
    
    if(i<n)
    {
      ++top;
      S[top].data=a[i];
      S[top].index=i;
    }
    //printf("i am top %d--\n",top);
    // printf("%d THE VALUE OF CURRENT ELWMENR\n",a[i]);
  }
    return maxarea;
}
