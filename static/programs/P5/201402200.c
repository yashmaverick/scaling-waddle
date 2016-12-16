#include<stdio.h>
#include <stdlib.h>
int entertainment[100001];
int cmpfunc (const void  * a, const void * b)
{
     return ( *(int*)a - *( long long int*)b );
}
int main()
{
  int  flag=0,i,j,k,temp,var,test_cases,no_nights,constraint;
  char night[10000];
  scanf("%d",&test_cases);
  while(test_cases--)
  {

    scanf("%d%d",&no_nights,&constraint);
    /*if(no_nights==0&&constraint==0)
    {
      printf("YES\n");
      continue;
    }
    if(no_nights==0&&constraint!=0)
    {
      printf("NO\n");
      continue;
    }
    if(no_nights==1)
    {
      if(entertainment[0]==constraint)
	printf("YES\n");
      else
	printf("NO\n");
      continue;
    }
    if(no_nights==2)
    {
      if(entertainment[0]+entertainment[1]==constraint)
	printf("YES\n");
      else
	printf("NO\n");
      continue;
    }*/
    for(var=0 ; var <no_nights ; var++)
      scanf("%s%d",night,&entertainment[var]);
    qsort(entertainment , no_nights,sizeof(int),cmpfunc);
//    for(i=0 ; i<no_nights ; i++)
  //    printf("%d ",entertainment[i]);
    j=0;
    
    for(i=0 ; i<no_nights ; i++)
    {
       flag=0;
      j=i+1;
      k=no_nights-1;
      while(k>j)
      {
	if(entertainment[i]+entertainment[j]+entertainment[k]==constraint)
	{
	  flag=1;
	  break;
	}
	if(entertainment[i]+entertainment[j]+entertainment[k]>constraint)
	  k--;
	else
	  j++;
      }
      if(flag==1)
	break;
    }
    if(flag==1)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
