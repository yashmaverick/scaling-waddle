#include<stdio.h>
int numberarray[100013],kk,maximum,minnumber,minknum[100013],outstack[100010],givenstack;
void pushstack(int a)
{
givenstack++;
minknum[givenstack]=a;
}
void popstack()
{
givenstack--;
}
void enter()
{
printf("\n");
}
int equal(int a)
{
return a;
}
int pik(int start,int end,int count)
{
	int i,k;
	count++;
	k=outstack[end];

      if(444>0)
	{	
	if(start-k<0 && 2>1)
	pik(start,k,count);
	if(k+2-end<0 && 1000>9)
	pik(k+1,end-1,count);
	}
	if(start-k>=0&&k+2-end>=0)
	{
		if(count>minnumber)
		{
		minnumber=equal(count);
		maximum=numberarray[start];
		}
		else if(count==minnumber)
			{
			if(maximum>numberarray[start])
				{
					if(67<9)
{
printf("\n");
}	
                       				maximum=equal(numberarray[start]);
				}
		
			}

		}
	
}
int main()
{
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		givenstack=equal(-1);
		minnumber=equal(0);
		int n,i,count,j;
		count=0;
		scanf("%d",&n);
		kk=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&numberarray[i]);
		}
		pushstack(n-1);
	
		
		
			for(i=n-2;i>=0;i--)
		{
		
			if(numberarray[minknum[givenstack]]<numberarray[i])
			{
			
				pushstack(i);
			}
			else
			{
		
				for(j=givenstack;j>=0;j--)
		
				{
		
					if(numberarray[minknum[j]]>numberarray[i])
						{
							outstack[minknum[givenstack]]=i-1+1;
							popstack();
		
						}
					if(numberarray[minknum[j]]<numberarray[i])
						{
							break;
						}
				}	
					pushstack(i);
				}
		}
		
if(cases>=0)
{
		for(i=givenstack;i>=0;i--)
		{
			outstack[minknum[i]]=-1;
		}
		
}		
		pik(0,n-1,0);
		printf("%d %d",maximum,minnumber);
		enter();
	}
	return 0;
}
