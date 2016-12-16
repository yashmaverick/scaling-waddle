#include<stdio.h>
long long int n,q,head=0,tail=0,size=0;
char a[1005][102];
void enqueue(long long int x)
{
	while(x--)
	{
		scanf("%s",a[tail]);
		tail=(tail+1)%n;
		if(size==n)
		head++;
//	cout<<head<<" "<<tail<<endl;
		else
			size++;
	}
	return ;
}
void dequeue(long long int x)
{
	while(x--)
	{
	if(head==tail && size==0)
		return ;
	head=(head+1)%n;
	size--;
	}
//	cout<<head<<" "<<tail<<endl;
}
/*int front()
{
	return a[head];
}*/
void print()
{
	long long int i,u;
	if(head==tail && size==0)
		return ;
	else
	{
		for(i=0;i<size;i++)
		{
			u=(head+i)%n;
			printf("%s\n",a[u]);
		}
	}
}
int main()
{
	long long int x,ans;
	char p;
	scanf("%lld",&n);
//	printf("%d\n",n);
	getchar();
//	scanf("%s",p);
//	cin>>q;
	while(1)
	{
		scanf("%c",&p);
		if(p=='A')
		{
			scanf("%lld",&x);
				enqueue(x);
		}
		else if(p=='R')
		{
			scanf("%lld",&x);
				dequeue(x);
		}
		else if(p=='L')
		{
			print();
		}
		else if(p=='Q')
			break;
	}
	return 0;
}
