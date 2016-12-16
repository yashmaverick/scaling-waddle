#include<stdio.h>
long long int arr[1000001];
long long int count[1000001];
//int max=-10000000;
int main()
{
  long long int sum;
  long long int i,test_cases,no_elements,min,max;
  
  scanf("%lld",&test_cases);
  while(test_cases--)
  {
 long long int min=10000000;
  scanf("%lld",&no_elements);
  for(i=0 ; i<no_elements ; i++)
  {
  scanf("%lld",&arr[i]);
  //if(arr[i] >max )
    //max=arr[i];
  if(arr[i]<min)
    min=arr[i];
  }
//  for(i=0 ; i<1000000 ; i++)
  //  count[i]=0;
  for(i=0 ; i< no_elements ; i++)
  {
  count[arr[i]-min]++;
  }
  sum=0;
  for(i=0 ; i<1000000 ; i++)
  {
  if(count[i]>=2)
    sum=sum+(count[i]*(count[i]-1))/2;
  count[i]=0;
  }
  printf("%lld\n",sum);
  }

}
