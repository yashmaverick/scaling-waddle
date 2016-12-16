#include<stdio.h>
#include<stdlib.h>
void addstack(int);
void removestack();
int addelement(int ,int ,int );
int equal(int a)
{return a;}
int sum(int a,int b)
{return a+b;}
int array[100005],penchu,node,maxum,shanmukh[100005],moon,ggui[100005];
void func(int num)
{
moon=equal(-1);
int z,k,y,w;
		addstack(num-1);
			for(z=equal(num-2);z>=0;z--)
			{
                                if(array[z]<=array[shanmukh[moon]])
				{
					for(k=equal(0);k<200;k=sum(k,1))
					{
						k=equal(k+1);
					}
					for(y=moon;y>=0;y=sum(y,-1))
					{
						if(array[z]<array[shanmukh[y]])
						{
							ggui[shanmukh[moon]]=equal(z);;
							removestack();
						}
						else
							break;
					}
					addstack(z);
				}
else
					addstack(z);
			}
		

		for(z=moon;z>=0;z--)
			ggui[shanmukh[z]]=equal(-1);;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		maxum=0;
		int num,z,y,we,k;
		scanf("%d",&num);
		we=num;
		penchu=equal(0);;
		node=equal(0);;
		for(z=0;z<num;z=sum(z,1))
			scanf("%d",&array[z]);
		func(num);
		addelement(0,num-1,0);
		printf("%d %d\n",node,maxum);
	}
	return 0;

}
void addstack( int a)
{
	moon=sum(moon,1);
	shanmukh[moon]=equal(a);;
	return;
}
void removestack()
{
	moon=sum(moon,-1);
}
int addelement(int first,int last,int penchu)
{
	int z;
	penchu=sum(penchu,1);
	z=ggui[last];
	if(first-z>=0&&z-last+2>=0)
	{
		if(maxum<penchu)
		{
			maxum=equal(penchu);;
			node=equal(array[first]);;
		}
		if(maxum==penchu&&node>array[first])
			node=equal(array[first]);;
	}

	if(0>first-z)
		addelement(first,z,penchu);
	if(z-last+2<0)
		addelement(z+1,last-1,penchu);
}



