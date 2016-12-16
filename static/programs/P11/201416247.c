#include<stdio.h>
long long int a[1000000];
long long int top=-1;
long long int maxarea=0;
long long int topindex;
int botindex;
void push(long long int val)
{
	int i,j;
	if(top==-1)
	  {
	  top=top+1;
	  a[top]=val;	
	  }
	else 
	top=top+1;
	a[top]=val;

}
void pop()
{
	top=top-1;
}
int main()
{
	long long int i,j,n,b[1000000];
	while(1)
	{	long long int max=0,areatop=0;
		scanf("%lld",&n);
		if(n==0)
			break;

		for(i=0;i<n;i++)
		{
			scanf("%lld",&b[i]);
			//push(b[0]);
		}
		i=0;
		while(i<n)
		{
			if(top==-1)
			{
				push(i);
				i++;
			}
			else if(b[a[top]]<=b[i])
			{
				push(i);
				i++;

			}
			else
			{   if(top>=0){
				topindex=a[top];
				pop();
				if(top==-1)
					areatop=b[topindex]*i;
				else
					areatop=b[topindex]*(i-a[top] -1);
				if(max<areatop)
					max=areatop;
			}
			}


		}
		/*	for(i=1;i<n;i++)
			{
			if(b[i-1]<=b[i])
			{
			push(b[i]);
			}
			else 
			{	
			pop();
			topind`ex=top+1;	
			botindex=top-1;
			areatop=a[topindex-1]*(topindex-botindex-1);
			if(max<areatop)
			max=areatop;


			}

			}*/
		while(top>=0)
		{   if(top!=-1){
			topindex=a[top];
			pop();
			if(top==-1)
				areatop=b[topindex]*i;
			else{


				areatop=b[topindex]*(i-a[top]-1);}
			if(max<areatop)
				max=areatop;
		}
		}
		/*	while(top>=0)
			{
			topindex=top+1;
			botindex=top-1;
			areatop=a[topindex]*(n-botindex-1);
			pop();
			if(max<areatop)
			max=areatop;
			}*/

		printf("%lld\n",max);


	}
	return 0;
}
