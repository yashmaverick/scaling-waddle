#include<stdio.h>
 
int main()
{
  int big,test_cases,size_array,array[100001],copy[100001];
  scanf("%d",&test_cases);

  while(test_cases--)
  {
    int i,small;
  scanf("%d",&size_array);
  for(i= 0 ; i<size_array ; i++)
  {
  scanf("%d",&array[i]);
  }
  small=array[0];
  for(i=0 ; i<size_array ; i++)
  {
    copy[i]=array[i];
  }
    for(i=0 ; i<size_array ; i++ )
  {
    if(copy[i]<=small)
      small=copy[i];
    else
      copy[i]=small;
  }
  for(i=0 ; i<size_array ; i++)
  {
    copy[i]=array[i]-copy[i];
  }
      big=copy[0];
  for(i=0 ; i<size_array ; i++)
  {
    if(copy[i]>big)
      big=copy[i];
  }
  printf("%d\n",big);
  
  
  
  }



return 0;

}
