#include<stdio.h>
#include<stdlib.h>

//This is the Iterative Heap which is faster!!

struct Node{
	long long int val;
	long long int weight;
	struct Node* next;
};

long long int marked[1000005]={0};
long long int visited=0;
//The final graph is build in this list
struct Node* mylist[1000005]={NULL};
//For checking if cycles are present or not
long long int AA[1000005];
//Heap uses arrays A, B, C to store x, y and weight of edge
//where x<y, and when we remove the edge from the heap we add the edge from x to y and from y to x
long long int A[1000005]={0};
long long int B[1000005]={0};
long long int C[1000005]={0};
long long int count=0;
long long int sum=0;

long long int findd(long long int i)
{
	if(AA[i]==0)
		return i;
	return findd(AA[i]);
}

void unions(long long int a, long long int b)
{
	long long int aa=findd(a);
	long long int bb=findd(b);
	AA[bb]=aa;
}

void swapper(long long int a, long long int b)
{
	long long int temp,temp2,temp3;
	temp=A[a]; temp2=B[a]; temp3=C[a];
	A[a]=A[b]; B[a]=B[b]; C[a]=C[b];
	A[b]=temp; B[b]=temp2; C[b]=temp3;
	return;
}

void worker(long long int j) //Goes up the tree swapping with the parent wherever required.
{
	long long int temp,temp2,temp3;
	while(j>=2)
	{
		if(A[j/2]>A[j])
		{
			swapper(j,j/2);
			j=j/2;
		}
		else
			break;
	}
}

void insert(long long int x, long long int y, long long int vals)
{
	count++;
	A[count]=vals;
	B[count]=x;
	C[count]=y;
	worker(count);
}

void remover(long long int i) //Shifts down the tree swapping with the children whenever required.
{
	long long int temp,temp2,temp3;
	while(i<=count)
	{
		if(i*2+1<=count && A[i*2+1]>=A[i] && A[i*2]>=A[i])
			break;
		if(i*2+1<=count && A[i*2+1]<=A[i*2])
		{
			swapper(i,i*2+1);
			i=i*2+1;
		}
		else if((i*2+1<=count && A[i*2]<=A[i*2+1]) || (i*2<=count && A[i*2]<=A[i]))
		{
			swapper(i,i*2);
			i=i*2;
		}
		else
			break;
	}
}
void deletetop()
{
	if(count>0)
	{
		A[1]=A[count];
		B[1]=B[count];
		C[1]=C[count];
		count--;
		remover(1);
	}
}

int main()
{
	long long int i,j,k,n,m,a,b,c;
	visited=0;
	scanf("%lld%lld", &n, &m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld", &a, &b, &c);
		insert(a,b,c);
	}
	sum=0;
	while(count>0 && visited<n-1)
	{
		a=A[1];
		b=B[1]; //Node 1
		c=C[1]; //Node 2
		deletetop();
		if(findd(b)!=findd(c))
		{
			visited++;
			sum+=a;
			unions(findd(b),findd(c));
		}
	}
	if(visited==n-1)
		printf("%lld\n", sum);
	else
		printf("-1\n");
	return 0;
}
