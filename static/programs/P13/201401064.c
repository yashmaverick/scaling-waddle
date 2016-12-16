#include<stdio.h>
int A[100013],kk,big,maxcount,im[100013],ig[100010],mc;
void in(int a)
{
mc++;
im[mc]=a;
}
void out()
{
mc--;
}
int pik(int start,int end,int count)
{
	int i,k;
	count++;
	k=ig[end];

	
	if(start-k<0)
	pik(start,k,count);
	if(k+2-end<0)
	pik(k+1,end-1,count);
	if(start-k>=0&&k+2-end>=0)
	{
		if(count>maxcount)
		{
		maxcount=count;
		big=A[start];
		}
		else if(count==maxcount)
			{
			if(big>A[start])
				{	
				big=A[start];
				}
		
			}

		}
	
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		mc=-1;
		maxcount=0;
		int n,i,count,j;
		count=0;
		scanf("%d",&n);
		kk=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&A[i]);
		}
		in(n-1);
	
		
		
			for(i=n-2;i>=0;i--)
		{
		
			if(A[i]>A[im[mc]])
			{
			
				in(i);
			}
			if(A[im[mc]]>A[i])
			{
		
				for(j=mc;j>=0;j--)
		
				{
		
					if(A[i]<A[im[j]])
						{
						ig[im[mc]]=i;
							out();
		
						}
					if(A[i]>A[im[j]])
						{
							break;
						}
				}	
					in(i);
				}
		}
		
		for(i=mc;i>=0;i--)
		{
			ig[im[i]]=-1;
		}
		
		pik(0,n-1,0);
		printf("%d %d\n",big,maxcount);
	}
	return 0;
}
