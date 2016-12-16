#include<stdio.h>
long long int item,item1,i,n,tp,j,t,tp1;
int a[1000000],b[1000000],top=-1;

void push(long long int item,int b[])
{
	//if(top!=100000)
	//{
	top++;
	b[top]=item;
	//}
}

void pop()
{
	if(top!=-1)
	{
		//	item1=a[top];
		top--;
	}
}

int maximum(int p,int q)
{
	if(p>q)
		return p;
	return q;
}
	int max(int x, int y, int z)
{  return maximum(maximum(x, y), z); }

long long int empty()
{
	if(top==-1)
		return 1;
	return 0;
}

int high(int b[])
{
	return b[top];
}


int min(int k,int l)
{
	if(k<l)
		return k;
	return l;
}

/*int minVal(int *a, int i, int j)
{
	    if (i == -1) return j;
	        if (j == -1) return i;
		    return (a[i] < a[j])? i : j;
}*/

int main()
{
	while(1)
	{
		top=-1;
		scanf("%lld",&n);
		if(!n)
		{
			break;
		}
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[j]);
		}
		long long int maxarea=0,area=0;
		i=0;
		while(i<n)
		{
			//		int x=high();
			if( empty() || a[b[top]] <= a[i])
			{
				push(i++,b);
			}
			/*else if(a[i]==a[b[top]])
			  push(i++);*/
			else
			{

				tp=high(b);
				pop();

				area = a[tp] * (empty() ? i : i - high(b) - 1);
				/*if(top==-1)
				  {
				  area=a[tp] * i;
				  }
				  else
				  {
				  area=a[tp] * (i-t-1);
				  }*/
				if(maxarea<area)
					maxarea=area;
			}
		}

		while(empty()==0)
		{
			tp=high(b);
			pop();

			area =a[tp] * (empty() ? i : i - high(b) - 1);

			/*if(top==-1)
			  {
			  area=a[tp] * i;
			  }
			  else
			  {
			  area=a[tp] * (i-tp1-1);
			  }*/
			if(maxarea<area)
				maxarea=area;
		}
		printf("%lld\n",maxarea);
	}
	return 0;
}


int getMid(int s, int e)
{   return s + (e -s)/2; }

