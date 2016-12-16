#include<stdio.h>
#define ll long long int
void print(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	}
void limit(int *a,int *b,int st,int it,int size)
{
	register int i,j;
	int stk[100005],k=1;
	stk[0]=st-it;
	stk[1]=st;
	b[st]=st-it;
  j=st;
	for(i=0;i<size-1;i++)
	{
	//rint(stk,k+1);
    j=j+it;
		while(k>0 && a[stk[k]]>=a[j])
			k--;
		b[j]=stk[k];
		k++;
		stk[k]=j;
	}
		//print(stk,k+1);
}
int main()
{
	int left[100005],right[100005],a[100005],n,i,j;
	long long int max,val;
	scanf("%d",&n);
	while(n!=0)
	{
		  for(i=0;i<n;i++)
				scanf("%d",&a[i]);
			limit(a,left,0,1,n);
			//print(left,n);
			limit(a,right,n-1,-1,n);
      //print(right,n);
//			print(a,n);
			max=0;
			val=0;
			for(i=0;i<n;i++)
			{
        val=(ll)((((ll)right[i]-(ll)left[i])-1)*(ll)a[i]);
				if(val>max)
					max=val;
			}
			printf("%lld\n",max);
     	scanf("%d",&n);
	}
	return 0;
}
