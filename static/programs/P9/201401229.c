#include<stdio.h>
#define max 1000000
typedef struct bag{
	int sum;
	int start;
	int end;
	int M;
}bag;
int cut(bag S[], int left, int right)
{
	bag t;          //temp
	int i,j;
	int p=S[right].sum;      //pivot
	int w=left-1;            //wall
	for(i=left;i<=right-1;i++)
	{
		if(S[i].sum<=p)
		{
			w++;

			t.start=S[w].start;
			t.end=S[w].end;
			t.sum=S[w].sum;
			t.M=S[w].M;
			S[w].start=S[i].start;
			S[w].end=S[i].end;
			S[w].sum=S[i].sum;
			S[w].M=S[i].M;
			S[i].start=t.start;
			S[i].end=t.end;
			S[i].sum=t.sum;
			S[i].M=t.M;
		}
	}
	w++;
//	bag t;
		
				t.start=S[w].start;
				t.end=S[w].end;
				t.sum=S[w].sum;
				t.M=S[w].M;
				S[w].start=S[i].start;
				S[w].end=S[i].end;
				S[w].sum=S[i].sum;
				S[w].M=S[i].M;
				S[i].start=t.start;
				S[i].end=t.end;
				S[i].sum=t.sum;
				S[i].M=t.M;
	return w;
}

void qsort(int left,int right,bag S[])
{
	if(left<right)
	{
		int p=cut(S,left,right);
		qsort(left,p-1,S);
		qsort(p+1,right,S);
	}
}
int main()
{
	int A[1000010];
	int N, MOD;
	bag B[1010];
	scanf("%d%d", &N,&MOD);
	int i,j,count;
	count=0;
	for(i=0;i<N;++i)
	{
		scanf("%d",&B[i].M);
		B[i].start=count;
		count+=B[i].M;
		B[i].end=B[i].start+B[i].M-1;
		for(j=B[i].start;j<=B[i].end;j++)
		{
			scanf("%d",&A[j]);
			B[i].sum=((B[i].sum)%MOD+(A[j])%MOD)%MOD;
		}
	}
	bag temp;

/*	for(i=0;i<100;i++)
		printf("%lld ",A[i]);
	printf("\n");                          

for(i=0;i<N;i++)
	{
		printf("%d\n",B[i].sum % MOD);
		for(j=B[i].start;j<=B[i].end;j++)
			printf("%d\n",A[j]);
		printf("\n");
	}*/                                                

/*	for(i=0;i<N-1;i++)
	{
		for(j=0;j<N-i-1;j++)
		{
//			if(B[j].sum==B[j+1].sum) break;
			if(B[j].sum>B[j+1].sum)
			{
				temp.start=B[j+1].start;
				temp.end=B[j+1].end;
				temp.sum=B[j+1].sum;
				temp.M=B[j+1].M;
				B[j+1].start=B[j].start;
				B[j+1].end=B[j].end;
				B[j+1].sum=B[j].sum;
				B[j+1].M=B[j].M;
				B[j].start=temp.start;
				B[j].end=temp.end;
				B[j].sum=temp.sum;
				B[j].M=temp.M;
			}
		}
	}
*/

	//Quick Sort
	qsort(0,N-1,B);
	for(i=0;i<N;i++)
	{
		printf("%d\n",B[i].sum%MOD);
		for(j=B[i].start;j<=B[i].end;j++)
			printf("%d\n",A[j]);
		printf("\n");
	}
	return 0;
}

				
