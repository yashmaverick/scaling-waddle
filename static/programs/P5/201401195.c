#include<stdio.h>
void sort(int x[],int first,int last);
int main()
{
	int t,d;
	scanf("%d",&t);
	for(d=0;d<t;d++)
	{
		int n,k,st=0;
		scanf("%d%d",&n,&k);
		int a[n],i,x,y;
		char s[10000],enter;
		for(i=0;i<n;i++)
		{

			scanf("%s %d",s,&a[i]);
			scanf("%c",&enter);
		}

		if(n==0&&k==0)
		{
			printf("YES\n");
			continue;
		}
		else if (n==0&&k!=0)
		{
			printf("NO\n");
			continue;
		}
		else if(n==1&&a[0]==k)
		{
			printf("YES\n");
			continue;
		}
		else if(n==1&&a[0]!=k)
		{
			printf("NO\n");
			continue;
		}

		else if(n==2)
		{
			if(a[0]==k||a[1]==k||a[0]+a[1]==k)
			{
				printf("YES\n");
				continue;
			}
			else
			{
				printf("NO\n");
				continue;
			}
		}
		else
		{

			sort(a,0,n-1);
			for(x=0;x<n&&st==0;x++)
			{
				int sec=x+1,last=n-1;			
				while(sec<last)
				{
					if(a[sec]+a[x]+a[last]==k)
					{
						st=1;
						break;
					}
					else if(a[sec]+a[x]+a[last]<k)
					{
						sec++;
					}
					else 
						last--;
				}
			}
			if(st==1)
				printf("YES\n");
			else
				printf("NO\n");
			st=0;
		}
	}
	return 0;
}
void sort(int x[],int first,int last)
{
	int pivot,b,t,a;

	if(first<last)
	{
		a=first,pivot=first,b=last;


		while(a<b){
			while(x[a]<=x[pivot])
			{	if(a<last)
				a++;
				else
					break;
			}
			while(x[b]>x[pivot])
				b--;
			if(a<b){
				t=x[a];
				x[a]=x[b];
				x[b]=t;
			}
		}

		t=x[pivot];
		x[pivot]=x[b];
		x[b]=t;
		sort(x,first,b-1);
		sort(x,b+1,last);

	}
}

