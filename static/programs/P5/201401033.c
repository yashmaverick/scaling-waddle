#include<stdio.h>
#define MAX 1000
#define ma 1000
void quick(long long int A[],long long int low,long long int high)
{
	long long int temp2,pivot,temp,i,j,point;
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
	long long int tc,state=0,x,y,s;
	long long int n,k,i,j,key,B[MAX];
	char A[ma][50];
	scanf("%lld",&tc);
	while(tc--)
	{
		state=0;
		scanf("%lld%lld",&n,&key);
		j=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",A[i]);
			scanf("%lld",&B[i]);
		}
		/*for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				s=B[i]+B[j];
				state=binary(B,k-s,j+1,n-1);
				if(state==1)
					break;
			}
			if(state==1)
				break;
		}*/
		quick(B,0,n-1);
		for(i=0;i<=n-2;i++)
		{
			state=0;
			j=i+1;
			k=n-1;
			while(k>j)
			{
				if(B[i]+B[j]+B[k]==key)
				{
					state=1;
					break;
				}
				(B[i]+B[j]+B[k]>key)?k--:j++;
			}
			if(state==1)
				break;
		}
		if(state==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
