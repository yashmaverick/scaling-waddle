#include<stdio.h>
#include<stdlib.h>
typedef long long int lld;
void push(lld *a,lld *top,lld x)
{
	a[*top]=x;
	(*top)++;

}
void pop(lld *a,lld *top)
{

	(*top)--;
}
void print_(lld *a,lld top)
{lld i;
	for(i=0;i<top;i++)
		printf("%lld ",a[i]);
	printf("\n");

}
int main()
{lld i,n,t1;
	lld bar[100010],left[100010],right[100010],stackb[100010],stackb1[100010];
	while(1)	
	{
		scanf("%lld",&n);
		if(n==0)
			break;
		/*int *bar=(int*)malloc(n*sizeof(int));
		int *left=(int*)malloc(n*sizeof(int));
		int *right=(int*)malloc(n*sizeof(int));*/
		for(i=0;i<n;i++)
			scanf("%lld",&bar[i]);
		//int *stackb=(int*)malloc(n*sizeof(int));
		lld tops=0;
		for(i=0;i<n;i++)
		{left[i]=0;
		        right[i]=0;
		}
		//lld k;
		push(stackb,&tops,0);
		for(i=1;i<n;i++)
		{ lld flag=0;
			lld j=tops-1;
			lld count=0;
			while(j>=0)

			{
				if(bar[i]>bar[stackb[j]])
				{	
					if(flag!=1)
					left[i]=0;
                                   flag=2;
					push(stackb,&tops,i);
					break;
				}
				else
				{flag=1;
					pop(stackb,&tops);
					count++;
					//left[i]=count+left[tops];
					//j=tops-1;
					j--;
				}
				left[i]=left[i]+left[stackb[tops]];
			}
			//if(flag==2)
			//	left[i]+=left[stackb[tops]];

			left[i]=left[i]+count;

			if(flag!=2)
			push(stackb,&tops,i);
			//k=i;
		}

		//int *stackb1=(int*)malloc(sizeof(int));
		lld tops1=0;
		//lld countr;
		push(stackb1,&tops1,n-1);
		for(i=n-2;i>=0;i--)
		{lld j=tops1-1;
			lld countr=0;
			lld flag=0;
			while(j>=0)
			{if(bar[i]>bar[stackb1[j]])
				{   if(flag!=1)
					right[i]=0;
					flag=2;
					push(stackb1,&tops1,i);
					break;
				}
				else
				{  pop(stackb1,&tops1);
					countr++;
					flag=1;
					//j=tops1-1;
					j--;
				}
				right[i]=right[i]+right[stackb1[tops1]];
			}
			right[i]=right[i]+countr;
			if(flag!=2)
			push(stackb1,&tops1,i);

		
		}
		/*for(i=0;i<n;i++)
			printf("left=%d right=%d\n",left[i],right[i]);*/
		lld max;
		max=(left[0]+right[0]+1)*bar[0];
		for(i=0;i<n;i++)
		{  if(max<((left[i]+right[i]+1)*bar[i]))
			max=(left[i]+right[i]+1)*bar[i];
		}	

		printf("%lld\n",max);
		 
	}

	return 0;
}
