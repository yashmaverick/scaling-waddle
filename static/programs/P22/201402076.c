#include<stdio.h>
int nemax=0;
int heapmax[200005];
int heapmin[200005];
int nemin=0;
void insertmax(int val)
{
  nemax++;
  heapmax[nemax]=val;
  int ind=nemax;
  while(ind>1)
  {
    if(heapmax[ind]>heapmax[ind/2])
    {
      int temp=heapmax[ind];
      heapmax[ind]=heapmax[ind/2];
      heapmax[ind/2]=temp;
    }
    ind=ind/2;
  }
}
void popmax()
{
  
  heapmax[1]=heapmax[nemax];
  nemax--;
  int ind=1;
  if(ind>nemax)
    return;
  while(1)
  {

    int maxind=2*ind;
    if(maxind>nemax)
      return;
    if(heapmax[maxind]<heapmax[maxind+1]&&maxind+1<=nemax)
    {
      maxind++;
    }
    if(heapmax[ind]<heapmax[maxind])
    {
      int temp=heapmax[ind];
      heapmax[ind]=heapmax[maxind];
      heapmax[maxind]=temp;
    }
    ind=maxind;
    if(ind>nemax)
      break;

  }
}
int max()
{
  return heapmax[1];
}

void insertmin(int val)
{
  nemin++;
  heapmin[nemin]=val;
  int ind=nemin;
  while(ind>1)
  {
    if(heapmin[ind]<heapmin[ind/2])
    {
      int temp=heapmin[ind];
      heapmin[ind]=heapmin[ind/2];
      heapmin[ind/2]=temp;
    }
    ind=ind/2;
  }
}
void popmin()
{
  
  heapmin[1]=heapmin[nemin];
  nemin--;
  int ind=1;
  if(ind>nemin)
    return;
  while(1)
  {

    int maxind=2*ind;
    if(maxind>nemin)
      return;
    if(heapmin[maxind]>heapmin[maxind+1]&&maxind+1<=nemin)
    {
      maxind++;
    }
    if(heapmin[ind]>heapmin[maxind])
    {
      int temp=heapmin[ind];
      heapmin[ind]=heapmin[maxind];
      heapmin[maxind]=temp;
    }
    ind=maxind;
    if(ind>nemin)
      break;

  }
}
int min()
{
  return heapmin[1];
}



int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long a,b,c,n;
		nemax=0;
		nemin=0;
		scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
		long long ans=1;
		long long median;
		median=1;
		int i;
		for(i=2;i<=n;i++)
		{
			long long temp=a*median;
			temp+=(b*i);
			temp+=c;
			temp%=1000000007;
			ans+=temp;
			//printf("%lld\n",temp);
			if(i%2==0)
			{
				if(temp>=median)
				{
					int tp=temp;
					insertmin(tp);
				//	ans+=median;
				}
				else
				{
					int tp=temp;
					insertmax(tp);
					tp=median;
					insertmin(tp);
					tp=max();
					median=tp;
					popmax();
				//	ans+=median;
				}
			}
			else
			{
				if(temp<median)
				{
					int tp=temp;
					insertmax(tp);
				//	ans+=median;
				}
				else
				{
					int tp=temp;
					insertmin(tp);
					tp=median;
					insertmax(tp);
					tp=min();
					median=tp;
					popmin();
				//	ans+=median;
				}
			}
		//	printf("%lld\n",median);
		}
		printf("%lld\n",ans);		
	}
	return 0;
}
