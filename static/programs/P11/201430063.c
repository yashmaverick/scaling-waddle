#include<stdio.h>
int top=-1;
int a[1000001];
long long int largestarea(int arr[],int len);
int empty();
int to();
int pop();
int push(int x);
int empty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
int to()
{
	return a[top];
}
int pop()
{
	if(!empty())
		top--;
}
int push(int x)
{
	top++;
	a[top]=x;
}
long long int largestarea(int arr[], int len)
{
	long long int area[len]; 
	int j;
	//for(j=0;j<len;j++)
	//area[j]=0;
	int n, i, t;



	for (i=0; i<len; i++)
	{
		while (!empty())
		{
			if(arr[i] <= arr[to()])

				pop();

			else
				break;
		}
		if(empty())
			t = -1;
		else
			t = to();

		area[i] = i -t - 1;
		push(i);
	}
	//for(i=0;i<len;i++)
	//printf("li is %d\n",area[i]);

	while (!empty())
		pop();

	for (i=len-1; i>=0; i--)
	{
		while (!empty())
		{
			if(arr[i] <= arr[to()])
			{
				pop();
			}
			else
				break;
		}
		if(empty())
			t = len;
		else
			t = to();

		area[i]+= t - i -1;
		push(i);
	}

	long long int max = 0;

	for (i=0; i<len; i++)
	{
		area[i] =  arr[i]*(area[i] + 1);
		if (area[i] > max)
			max = area[i];
	}
	//for(i=0;i<len;i++)
	//printf("%d\n",area[i]);
	while(!empty())
		pop();
	return max;
}
int main()
{
	int n=-1;
	while(n!=0)
	{
		scanf("%d",&n);
		int b[n];
		int i;

		for(i=0;i<n;i++)
			scanf("%d",&b[i]);
		long long int c; 
		c=largestarea(b,n);
		if(n!=0)
			printf("%lld\n",c);
	}
	return 0;
}



