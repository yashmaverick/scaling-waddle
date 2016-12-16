#include<stdio.h>
#include<malloc.h>
 int  n;
void merge( int min,int mid, int max);
struct bags
{
	 int sum;
	 int number;
	 int *weights;
};
struct bags shubh[1001];
void part( int min, int max)
{  int mid;
 if(min<max)
 {
   mid=(min+max)/2;
   part(min,mid);
   part(mid+1,max);
   merge(min,mid,max);
 }
 return;
}
void merge(int min, int mid, int max)
{
  struct bags tmp[1001];
  //tmp=malloc(n*sizeof(struct bags));
   int i,j,k,m; 
  j=min;
  m=mid+1;
  for(i=min; j<=mid && m<=max ; i++)
  {
     if(shubh[j].sum<=shubh[m].sum)
     {
         tmp[i]=shubh[j];
         j++;
     }
     else
     {
         tmp[i]=shubh[m];
         m++;
     }
  }
  if(j>mid)
  {
     for(k=m; k<=max; k++)
     {
         tmp[i]=shubh[k];
         i++;
     }
  }
  else
  {
     for(k=j; k<=mid; k++)
     {
        tmp[i]=shubh[k];
        i++;
     }
  }
  for(k=min; k<=max; k++)
     shubh[k]=tmp[k];
}


int main()
{
	 int j,num,k;
	 int mod,*weight;
	scanf("%d%d",&n,&mod);
	//shubh=malloc(n*sizeof(struct bags));
	for(j=0;j<n;j++)
	{
		 int sum1=0;
		scanf("%d",&num);
		shubh[j].number=num;
		weight=malloc(num*sizeof(int  ));
		shubh[j].weights=malloc(num*sizeof(int));
		for(k=0;k<num;k++)
		{
			scanf("%d",&weight[k]);
			shubh[j].weights[k]=weight[k];
			sum1=(sum1%mod+weight[k]%mod)%mod;
		}
		shubh[j].sum=sum1;
	}
	part(0,n-1);
	for(j=0;j<n;j++)
	{
		printf("%d\n",shubh[j].sum);
		for(k=0;k<shubh[j].number;k++)
		{
			printf("%d\n",shubh[j].weights[k]);
		}
		printf("\n");
	}
	return 0;
}
