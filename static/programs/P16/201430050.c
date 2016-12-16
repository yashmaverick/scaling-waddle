#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	int count=0;
	int n,flag;
	int depth=1;

	scanf("%d",&n);
	while(n>2)
	{n=n/2;
	count++;
        }
	if(n==2)
		flag=1;
	else
		if(n==1)
		{	flag=0;}
	//printf("count=%d\n",count);

	if(flag==1)
		depth=count+1;
	else
		if(flag==0)
		depth=count;
	//printf("depth=%d\n",depth);

	if(flag==1)
	printf("%d\n",(2*depth)-1);
	  else
		  if(flag==0)
		  {
		printf("%d\n",2*depth);
	}
	}
	  return 0;
}
