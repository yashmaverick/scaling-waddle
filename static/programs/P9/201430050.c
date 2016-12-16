#include<stdio.h>
#include<stdlib.h>
int partiton(int a[],int f,int l)
{int pivot,pindex,i,t;
	pivot=a[l];
	pindex=f;
	for(i=f;i<l;i++)
	{
		if(a[i]<pivot)
		{//	swap(a[i],a[pindex]);
			t=a[i];
			a[i]=a[pindex];
			a[pindex]=t;
		pindex++;
		}
	}
//	swap(a[l],a[pindex]);
 			t=a[l];
			a[l]=a[pindex];
			a[pindex]=t;
	return pindex;
}
void quicksort(int a[],int f,int l)
{int p;

	if(f>=l)
		return;
	else
	{
        p=partiton(a,f,l);
	quicksort(a,f,p-1);
	quicksort(a,p+1,l);
	}
	return;
}

void push(int *a[],int *top,int x,int r)
{
	a[r][*top]=x;
	(*top)++;
}
void pop(int *a[],int *top)
{        (*top)--;
	
}
void print_(int *a[],int top,int r)
{int i;
       	for(i=0;i<top;i++)
        printf("%d\n",a[r][i]);
    //printf("\n");
}    
void push1(int *a,int *top,int x)
{
	a[*top]=x;
	(*top)++;
}
void print__(int *a,int top)
{int i;
	for(i=0;i<top;i++)
	printf("%d\n",a[i]);

}
int main()
{int N,MOD;
	int i,j,M,x;
	scanf("%d%d",&N,&MOD);
		int **a=(int**)malloc(N*sizeof(int*));
		int *topa=(int*)malloc(N*sizeof(int));
		int *suma=(int*)malloc(N*sizeof(int));
		int tops=0;
		int sumtop=0;
	for(i=0;i<N;i++)
	{ scanf("%d",&M);
		int top=0;
		int sum=0;
	a[i]=(int*)malloc((M+1)*sizeof(int));
		for(j=0;j<M;j++)
		{	   scanf("%d",&x);
			sum=(sum+x)%MOD;
		  push(a,&top,x,i);
	         }
		push(a,&top,sum%MOD,i);
		push1(suma,&sumtop,sum%MOD);
				//top=(int*)malloc(N*sizeof(int));
		//sum=(int*)malloc(N*sizeof(int));
		    push1(topa,&tops,top);
		 }
/*printf("topwala\n");
	print__(topa,tops);
	printf("\n");
for(i=0;i<N;i++)
print_(a,topa[i],i);
*/
	quicksort(suma,0,sumtop-1);
	int k=-1;
	int flag=0;
for(j=0;j<N;j++)
   	{if(flag==1)
		i=k+1;
		else
			i=0;
            while(i<N)
	{
	if(a[i][topa[i]-1]==suma[j])
		   { if(k!=i)
			{printf("%d\n",suma[j]);
			print_(a,topa[i]-1,i);
                         k=i;
			 break;
			}
		   }
		i++;
		
	}
	if(suma[j]==suma[j+1] && j!=N-1)
	{	i=k+1;
	        flag=1;
	}
	else
		flag=0;
	printf("\n");
	}
return 0;

}
                 


