#include<stdio.h>
void swap(int *a,int *b)
{ int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int compare(int *a,int *b)
{
       if(*a>=*b)
	return 1;
	else
	 return 0;
}
int main()
{ int t,x;
	scanf("%d",&t);
	for(x=0;x<t;x++)
	{    
		int n,k,i,j,a,b,flag;flag=0;
		scanf("%d %d",&n,&k);
		int A[n];
		for(j=0;j<n;j++)
		{  char S[100100];
			scanf("%s",S);
		      	scanf("%d",&A[j]);	
		}
  for(a=0;a<n-1;a++)
  { if(compare(&A[a],&A[a+1])==1)
	{   swap(&A[a],&A[a+1]);
	    for(b=1;b<=a;b++)
	    {
	      if(compare(&A[a-b],&A[a-b+1])==1)
		    swap(&A[a-b],&A[a-b+1]);
	      else
		      break;
	    }
	}
  }
  int l,r;
  for(i=0;i<n-2;i++)
  { l=i+1;
	  r=n-1;
	  while(l<r)
	  { 
		  if(A[i]+A[l]+A[r]==k)
		  {	  flag=1;
		           break;
		  }
		  else if(A[i]+A[l]+A[r] < k)
			  l++;
		  else
			  r--;
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

