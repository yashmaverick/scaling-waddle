#include<stdio.h>
#include<stdlib.h>
void bubble(int data[],int no_elements,int **);
int main()
{
//  int test_cases;
  int N,M,W,MOD;
  int i,j;
  int *ptr[1001];
  int *sumpot[1001];
  int sum;
  int a[1001];
  //scanf("%d",&test_cases);
  //  while(test_cases--)
  //{
  scanf("%d%d",&N,&MOD);
  i=0;
  int t=N;
  while(t--)
  {
    sum=0;
    scanf("%d",&M);
    ptr[i]=(int*)malloc((M+1)*sizeof(int));
    sumpot[i]=ptr[i];
    j=0;
    ptr[i][0]=M;
    while(M--)
    {
      j++;
      //	puts("hii");
      scanf("%d",&ptr[i][j]);
      //printf("%d--",ptr[i][j]);
      sum=sum+ptr[i][j];
      sum=sum%MOD;
    }
    a[i]=sum;
    //sumpot[i]=ptr[i];
    i++;
  }
  bubble(a,N,sumpot);
  //    printf("%dhii",N);
  for(i=0 ; i<N ; i++)
  {
    printf("%d\n",a[i]);
    for(j=1 ; j<=sumpot[i][0] ; j++)
    {
      printf("%d\n",sumpot[i][j]);
    //  printf("\n");
    }
    printf("\n");
  }
  //    printf("\n");
  //}	
  return 0;
}
void bubble(int data[],int no_elements,int *ptr[])
{
  int *pot;
  int pass,compare,i,last;
  last=no_elements;
  for(pass=0 ; pass <no_elements ; pass++)
  {
    for(compare=0 ; compare<no_elements-pass-1 ; compare++)
    {
      if(data[compare]>data[compare+1])
      {
	int temp=data[compare];
	pot=ptr[compare];
	ptr[compare]=ptr[compare+1];
	ptr[compare+1]=pot;
	data[compare]=data[compare+1];
	data[compare+1]=temp;
      }
    }
//    last =last-1;
  }

  // for( i = 0 ; i<no_elements ; i++)
  //printf("%d ",data[i]);
}









