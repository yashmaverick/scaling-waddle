#include<stdio.h>
#include<time.h>

int n;

int partition(int A[], int start, int end, int pivot)
{
	int i,j,a,b,c,piv,temp;
	piv=A[pivot];
	temp=A[pivot];
	A[pivot]=A[end];
	A[end]=temp;
	int place=start;
	for(i=start;i<=end;i++)
	{	
		if(A[i]<=piv)
		{
			temp=A[place];
			A[place]=A[i];
			A[i]=temp;
			place++;
		}
	}
	return place-1;
}

void quick(int A[], int start, int end)
{
	int newpiv,random;
	if(start<end)
	{
		srand(time(NULL));
		random=rand();
		random=start+random%(end-start);
		newpiv=partition(A,start,end,random);
		quick(A,start,newpiv-1);
		quick(A,newpiv+1,end);
	}
}

int main()
{
  int A[10000]={0};
  int start,end,a,b,kk,c,m,i,j,k,t,state;
  char str[10000];
  scanf("%d", &t);
  for(i=0;i<t;i++)
  {
    state=0;
    for(k=0;k<10000;k++)
      A[k]=0;
    scanf("%d%d", &n, &k);
    for(j=0;j<n;j++)
    {
      scanf("%s", &str);
      scanf("%d", &a);
      A[j]=a;
    }
    quick(A,0,n-1);
    for(kk=0;kk<n-2;kk++)
    {
      start=kk+1;
      end=n-1;
      while(start<end)
      {
        if(A[kk]+A[start]+A[end]>k)
          end--;
        else if(A[kk]+A[start]+A[end]<k)
          start++;
        else
        {
          printf("YES\n");
          state=1;
          break;
        }
      }
      if(state==1)
        break;
    }
    if(state!=1)
      printf("NO\n");
  }
  return 0;
}
