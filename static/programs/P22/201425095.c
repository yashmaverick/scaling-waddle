#include<stdio.h>
long long int maxarr[1000000];
long long int minarr[1000000];
void swap(long long int *a, long long int *b)
{
	long long int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
long long int maxtop;
long long int mintop;
void maxinsert(long long int num)
{
	maxarr[++maxtop]=num;

	long long int parent;
	long long int i=maxtop;
	while(i>1)
	{
		parent=i/2;
			if(maxarr[i]>maxarr[parent])
			{
			swap(&maxarr[i], &maxarr[parent]);
			i=parent;
		}
		else
			break;
	}
	return;
}

long long int maxdelete()
{
//	swap(&arr[1], &arr[top]);
	long long int temp=maxarr[1];
	maxarr[1]=maxarr[maxtop];

	long long int a;
	a=1;
	maxtop--;
	while(a<=maxtop/2)
	{
		if(2*a==maxtop)
		{
			if(maxarr[2*a] > maxarr[a] && maxarr[2*a])
			{
				swap(&maxarr[a],&maxarr[2*a]);
				a*=2;
			}

			else
				break;
		}

		else if(maxarr[2*a]>maxarr[2*a+1])
		{
			if(maxarr[2*a]>maxarr[a])
			{
				swap(&maxarr[2*a], &maxarr[a]);
				a=2*a;
			}
			else
				break;
		}
		else
		{
			if(maxarr[2*a+1]>maxarr[a])
			{
				swap(&maxarr[2*a+1], &maxarr[a]);
				a=2*a+1;
			}
			else
				break;
		}
	
	}
	return temp;
}

//int maxtop;
//int mintop;
void mininsert(long long int num)
{
	minarr[++mintop]=num;

	long long int parent;
	long long int i=mintop;
	while(i>1)
	{
		parent=i/2;
			if(minarr[i]<minarr[parent])
			{
			swap(&minarr[i], &minarr[parent]);
			i=parent;
		}
		else
			break;
	}
	return;
}

long long int mindelete()
{
//	swap(&arr[1], &arr[top]);
	long long int temp=minarr[1];
	minarr[1]=minarr[mintop];

	long long int a;
	a=1;
	mintop--;
	while(a<=mintop/2)
	{
		if(2*a==mintop)
		{
			if(minarr[2*a] < minarr[a])
			{
				swap(&minarr[a],&minarr[2*a]);
				a*=2;
			}

			else
				break;
		}

		else if(minarr[2*a]<minarr[2*a+1])
		{
			if(minarr[2*a]<minarr[a])
			{
				swap(&minarr[2*a], &minarr[a]);
				a=2*a;
			}
			else
				break;
		}
		else
		{
			if(minarr[2*a+1]<minarr[a])
			{
				swap(&minarr[2*a+1], &minarr[a]);
				a=2*a+1;
			}
			else
				break;
		}
	
	}
	return temp;
}
long long int F[1000000];
long long int M[1000000];
//M[2]=1;
long long int median(long long int i)
{
		
}
long long int main()
{
	long long int t;
	//int F[1000];
	//int M[1000];
	scanf("%lld", &t);
	while(t--)
	{
		maxtop=0;
		mintop=0;
		long long int sum;
		sum=1;
		long long int a,b,c,n;
		scanf("%lld %lld %lld %lld", &a, &b, &c, &n);
		long long int i;
		F[1]=1;
		M[2]=1;
				maxinsert(1);
		
		for(i=2; i<=n; i++)
		{
			F[i]=(a*maxarr[1] +b*i +c)%1000000007;
			sum+=F[i];
		//	printf("%lld ",F[i]);
//			M[i]=median(i);
		//	if(i>2)
			{
//				if(F[i]<=M[i-1])
				if(F[i] < maxarr[1])
				{
					maxinsert(F[i]);
				}
				else
					mininsert(F[i]);

				if(mintop>maxtop)
				{
					long long int tp;
					tp=mindelete();
					maxinsert(tp);
				}
				 if (maxtop-1>mintop)
				{
					long long int tp;
					tp = maxdelete();
					mininsert(tp);
				}
//				M[i] = maxarr[1];
			}
			//else
				//maxinsert(1);

		}

		/*for(i=1;i<=maxtop;i++)
			printf("%lld ",maxarr[i]);
		for(i=1;i<=mintop;i++)
			printf("%lld ",minarr[i]);
*/
		printf("%lld\n", sum);
/*		for (i=1; i<=n; i++)
		{
			long long int temp;
			scanf("%lld", &temp);
//			maxinsert(temp);
			mininsert(temp);
		}
//			printf ("%d", top);
//		for(i=1; i<=n; i++)
//			printf ("%d", arr[i]);
		while(n--)
		{
//			printf("%d ",maxdelete());
			printf("%lld ", mindelete());
		}
*/	}
	return 0;
}
