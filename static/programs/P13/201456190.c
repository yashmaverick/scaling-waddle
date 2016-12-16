#include<stdio.h>

long long int depthofall[100005];
long long int a[100005];
long long int b[100005];
long long int right;
long long int left;

long long int x=13412111;
long long int deep=0;
void find(long long int pleft,long long int cur,long long int count)
{
	long long int f=b[cur];
	long long int lflag=0;
	long long int rflag=0;

	if(pleft>cur)
		return;

	depthofall[cur]=count;


	if(a[cur-1]>a[cur])
	{
		right=cur-1;
		rflag=1; 
	}

	if(f!=-1 && f>=pleft) 
	{
		left=f;
		lflag=1; 
	}
	if(lflag==0&&rflag==0) 
		return; 
	/* if(pleft==cur)
	   {
	   if(count>x)
	   { x=count; deep = a[pleft]; }

	   if(count==x)
	   if(a[pleft] < deep)
	   deep=a[pleft];    

	   depthofall[pleft]=count;

	   return;
	   }
	 */
	if(rflag==1 && lflag==1)
	{
		find(left,right,count+1); // right
		find(pleft,left,count+1); // left
	}
	else if(rflag==1)
	{
		find(pleft,cur-1,count+1);
	}
	else if(lflag==1)
	{
		find(pleft,cur-1,count+1);
	}

} 


int main()
{
	long long int test,q;
	scanf("%lld",&test);
	for(q=0;q<test;q++)
	{
		x=0;deep=212312;
		long long int i;
		long long int N;
		scanf("%lld",&N);

		for(i=0;i<N;i++)
			scanf("%lld",&a[i]);

		b[0]=-1;

		for(i=1;i<N;i++)
		{  
			if(a[i-1]<a[i])
				b[i]=i-1;

			else if(b[i-1]==-1)
				b[i]=-1;
			else
			{
				long long int j;
				j=b[i-1];
				while(1)
				{

					if(a[j]<a[i])
					{
						b[i]=j;
						break;
					}
					long long int k;
					k=b[j];
					if(k==-1)
					{
						b[i]=-1;
						break;
					}

					j=k;
				}
			}
		}

		for(i=0;i<N;i++)
			depthofall[i]=-1;

		find(0,N-1,0);

		x=-1;
		for(i=0;i<N;i++)
			if(depthofall[i] > x)	
			{
				//		printf("%lld ",depthofall[i]);

				x=depthofall[i]; deep=a[i];
			}


		printf("%lld %lld\n",deep,x);

		/*     for(i=0;i<N;i++)
		       {
		       printf("%lld ",b[i]);
		       }
		       printf("\n");  */

	}
	return 0;
}              
