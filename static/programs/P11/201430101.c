//GABBAR STUDIOWORKS
//02 - 03 - 2015
// P11 ATTEMPT 2

#include<stdio.h>
#include<stdlib.h>
typedef long long int ll;
ll stack[100003];
ll head=-1;
push(ll l)
{
	stack[++head]=l;
}
pop()
{

	head--;
	return stack[head+1];
}
int main()
{
	ll maxarea=0;
	ll area,i,temp;

	ll n;
	while(3)
	{
		maxarea=0;
		scanf("%lld",&n);
		//dynamic allocation of the array that will contain the elements
		ll *arr=(ll*)malloc(sizeof(ll)*n);
		if(n==0)
			break;
		area=0;

		//scanning the array
		for(i=0;i<n;i++)
		{
			scanf("%lld",&arr[i]);
		}
		i=0;
		for(i=0;i<n;)
		{
			if(head==-1 || arr[i]>=arr[stack[head]])
			{
				push(i);
				//pushing the element i in to the stack
				i++;
			}
			else 
			{
				temp=pop();
				//popping out the element of the stack
				if(head==-1)//if the stack is empty
					area=arr[temp]*i;
				else//if the stack is non empty
					area=arr[temp]*(i-1-stack[head]);
				if(area>maxarea)
					maxarea=area;
			}
		}
		while(head!=-1)//stack empty
		{

			temp=pop();
			if(head==-1)//stack empty
				area=arr[temp]*i;
			else    //non empty stack
				area=arr[temp]*(i-1-stack[head]);
			if(area>maxarea)
				maxarea=area;
		}	
		printf("%lld\n",maxarea);
	}
	return 0;
}
/*
#include<stdio.h>
#include<stdlib.h>
typedef long long int ll;
ll ind(ll *arr,ll start,ll end)
{       
	ll i,index;
	ll min=arr[start];
	for(i=start;i<end;i++)
	{
		if(arr[i]<min)
		{
			min=arr[i];
			index=i;
		}
	}
	return index;
}

ll min(ll *arr,ll start,ll end)
{
	ll i;
	ll min=arr[start];
	for(i=start;i<end;i++)
	{
		if(arr[i]<min)
			min=arr[i];
	}
	return min;
}
ll flash(ll *arr,ll start,ll end)
{
	ll area;
	ll mnm=min(arr,start,end);
	area=(end-start+1)*mnm;
	return area;
}
int main()
{
	ll n,i,maxarea=0,area=0;
	while(3)
	{
		scanf("%lld",&n);
		maxarea=0;
		area=0;
		if(n==0)
			break;
		ll *arr=(ll*)malloc(sizeof(ll)*n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&arr[i]);
		}
		ll start=0;
		ll end=n;
		ll in=end+1;
		while()
		{
			area=flash(arr,start,in-1);
			if(area>maxarea)
				maxarea=area;
			in=ind(arr,in+1,end);
			area=flash(arr,in+1,end);
			if(area>maxarea)
				maxarea=area;
			in=ind(arr,start,end);
		}
	}
	printf("%lld\n",maxarea);
	return 0;
}
*/


