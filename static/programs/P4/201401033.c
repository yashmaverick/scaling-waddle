#include<stdio.h>
#define MAX 100000
void quick(int A[],int low,int high)
{
	int temp2,pivot,temp,i,j,point;
	if(low<high)
	{
		pivot=(low+high)/2;
		i=low;
		j=high;
		temp2=A[pivot];
		temp=A[pivot];
		A[pivot]=A[j];
		A[j]=temp;
		point=i;
		while(i<=j)
		{
			if(A[i]<=temp2)
			{
				temp=A[i];
				A[i]=A[point];
				A[point]=temp;
				point++;
			}
			i++;
		}	
		//if(k<point)
			quick(A,low,point-2);
		//else if(k>point)
			quick(A,point,high);
	}	
}
int main()
{
	int har,anss,tc,i,j,sum,cnt;
	char A[MAX];
	int B[MAX];
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%s",A);
		sum=0;
		j=0;
		for(i=0;A[i]!='\0';i++)
		{
			if(A[i]=='J')
			{
				sum+=-1-MAX;
				B[j++]=sum;
			}
			else if(A[i]=='M')
			{
				sum+=1;
				B[j++]=sum;
			}
			else if(A[i]=='R')
			{
				sum+=MAX;
				B[j++]=sum;
			}

		}
		B[j++]=0;
		quick(B,0,j-1);
		anss=0;
		cnt=1;
		for(i=0;i<j-1;i++)
		{
			//printf("%d ", cnt);
			if(B[i+1]==B[i])
				cnt++;
			else
			{
				anss+=cnt*(cnt-1)/2;
				cnt=1;
			}
			//printf("%d ", cnt);
		}
		anss+=cnt*(cnt-1)/2;
		printf("%d\n",anss);
		//for(i=0;i<j;i++)
		//	printf("%d ",B[i]);
		//printf("\n");
	}
	return 0;
}
