#include<stdio.h>
int siz1=0,siz2=0;
long long int minheap[200003],maxheap[200003];
void insert_minheap(long long int val)
{
	int i;
	long long int temp;
	siz1++;
	minheap[siz1]=val;
	for(i=siz1;i!=1;i=i/2)
	{
		if(minheap[i]<minheap[i/2])
		{
			temp=minheap[i];
			minheap[i]=minheap[i/2];
			minheap[i/2]=temp;
		}
		else
			break;
	}
}
long long int deletemin_minheap()
{
	long long int temp,temp1,temp2;
	long long int ret1=minheap[1];
	minheap[1]=minheap[siz1];
	siz1--;
	int i=1;
	while((2*i)<=siz1)
	{
		if((2*i)==siz1)
		{
			if(minheap[i]>minheap[(2*i)])
			{
				temp=minheap[i];
				minheap[i]=minheap[(2*i)];
				minheap[(2*i)]=temp;
				i=2*i;
			}
			else
				break;
		}
		else if(minheap[(2*i)]<=minheap[(2*i)+1] && minheap[i]>minheap[(2*i)])
		{
			temp1=minheap[(2*i)];
			minheap[(2*i)]=minheap[i];
			minheap[i]=temp1;
			i=(2*i);
		}
		else if(minheap[(2*i)+1]<=minheap[(2*i)] && minheap[i]>minheap[(2*i)+1])
		{
			temp2=minheap[(2*i)+1];
			minheap[(2*i)+1]=minheap[i];
			minheap[i]=temp2;
			i=(2*i)+1;
		}
		else
			break;
	}
	return ret1;
}
void insert_maxheap(val)
{
	long long int tmp;
	int j;
	siz2++;
	maxheap[siz2]=val;
	for(j=siz2;j!=1;j=j/2)
	{
		if(maxheap[j]>maxheap[j/2])
		{
			tmp=maxheap[j];
			maxheap[j]=maxheap[j/2];
			maxheap[j/2]=tmp;
		}
		else
			break;
	}
}
long long int deletemin_maxheap()
{
	long long int tmp,tmp1,tmp2;
	long long int ret2=maxheap[1];
	maxheap[1]=maxheap[siz2];
	siz2--;
	int j=1;
	while((2*j)<=siz2)
	{
		if((2*j)==siz2)
		{
			if(maxheap[j]<maxheap[(2*j)])
			{
				tmp=maxheap[j];
				maxheap[j]=maxheap[(2*j)];
				maxheap[(2*j)]=tmp;
				j=2*j;
			}
			else
				break;
		}
		else if(maxheap[(2*j)]>maxheap[(2*j)+1] && maxheap[j]<maxheap[(2*j)])
		{
			tmp1=maxheap[(2*j)];
			maxheap[(2*j)]=maxheap[j];
			maxheap[j]=tmp1;
			j=(2*j);
		}
		else if(maxheap[(2*j)+1]>maxheap[(2*j)] && maxheap[j]<maxheap[(2*j)+1])
		{
			tmp2=maxheap[(2*j)+1];
			maxheap[(2*j)+1]=maxheap[j];
			maxheap[j]=tmp2;
			j=(2*j)+1;
		}
		else
			break;
	}
	return ret2;
}
int main()
{
	int t,m,i,n;
	long long int f,a,b,c,x,y;
	long long int median;
	long long int sum=0;
	scanf("%d",&t);
	for(m=0;m<t;m++)
	{
		sum=0,siz1=0,siz2=0;
		scanf("%lld%lld%lld%d",&a,&b,&c,&n);
		insert_maxheap(1);
		sum=1;
		median=maxheap[1];
		for(i=2;i<=n;i++)
		{
			f=((a*median)+(b*i)+c)%1000000007;
			sum=sum+f;
			if(f<=median)
			{
				if(siz2==siz1+1)
				{
					x=deletemin_maxheap();
					insert_minheap(x);
					insert_maxheap(f);
				}
				else
					insert_maxheap(f);

			}
			else
			{
				if(siz1==siz2+1)
				{
					y=deletemin_minheap();
					insert_maxheap(y);
					insert_minheap(f);
				}
				else
					insert_minheap(f);
			}
			if(siz1==siz2)
			{
				if(maxheap[1]<minheap[1])
					median=maxheap[1];
				else
					median=minheap[1];
			}
			else if(siz1>siz2)
				median=minheap[1];
			else
				median=maxheap[1];
		}
		printf("%lld\n",sum);
	}
	return 0;
}
