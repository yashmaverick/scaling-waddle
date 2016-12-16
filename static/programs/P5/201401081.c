#include<stdio.h>

int a[1000],k;
int n,flag;

void print_arr()
{
  int i;
  for(i=0;i<n;i++)
    printf("%u ",a[i]);
  printf("\n");
}

int part(int beg,int end)
{
  int key;
  int wall;
  int temp;
  key=a[end];
  wall=beg-1;
  int i;
  for(i=beg;i<=end;i++)
    if(a[i]<key)
      {
	temp=a[i];
	a[i]=a[wall+1];
	a[wall+1]=temp;
	wall++;
      }
  temp=a[wall+1];
  a[wall+1]=a[end];
  a[end]=temp;
  wall++;
  return wall;
}

void quick_s(int beg,int end)
{
  if(beg>=end)
    return;
  int p;
  p=part(beg,end);
  quick_s(p+1,end);
  quick_s(beg,p-1);
}

int main()
{
  int t,i;
  char junk[10000];
  scanf("%d",&t);
  while(t--)
    {
      flag=0;
      scanf("%d",&n);
      scanf("%d",&k);
      for(i=0;i<n;i++)
	{
	  scanf("%s",junk);
	  scanf("%d",&a[i]);
	}
      quick_s(0,n-1);
      //print_arr();
      int beg,end,sum;
      for(i=0;i<n-2;i++)
	{
	  beg=i+1;
	  end=n-1;
	  while(beg<end)
	    {
	      sum=a[i]+a[beg]+a[end];
	      if(k==sum)
		{
		  //printf("%d %d %d\n",a[i],a[beg],a[end]);
		  flag=1;
		  break;
		}
	      else if(k<sum)
		end--;
	      else if(k>sum)
		beg++;
	    }
	}
      if(flag==1)
	printf("YES\n");
      else
	printf("NO\n");
    }
  return 0;
}
