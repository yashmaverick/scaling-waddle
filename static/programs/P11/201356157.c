#include<stdio.h>
int array1[100010],array2[100010],array3[100010];
int n,iter,q;
int r,t;
int check(int a, int b)
{
if(a>=b)
return 1;
else
return 0;


}
int checkA(int a,int b,int c, int A)
{
	if(((a-1-b)*c)>A)
		return 1;
	else
		return 0;
}

void shreeya(int q,int iter){

			while(q<=n-1)
				if(check(array1[q],array1[iter]))
					q=array3[q];
				else break;
			array3[iter]=q;
}
void coke(int q,int iter)
{
while(q>=0)
	if(check(array1[q],array1[iter]))
		q=array2[q];
	else 
		break;
array2[iter]=q;

}


int main(){
	
	long long A;
	scanf("%d",&n);
	while(n!=0)
	{       int i;
		A=0;
		for(iter=0;iter<n;iter=iter+1)scanf("%d",&array1[iter]);
		array2[0]=-1;
		for(iter=1;iter<n;iter=iter+1)
		{
			q=iter-1;
			coke(q,iter);
		}
		array3[n-1]=n;
		for(iter=n-2;iter>=0;iter=iter-1)
		{
			q=iter+1;
			shreeya(q,iter);
		}
		for(iter=0;iter<n;iter=iter+1)
			if(((long long)(array3[iter]-1-array2[iter])*array1[iter])>A)
				A=(long long)(array3[iter]-array2[iter]-1)*array1[iter];
		printf("%lld\n",A);

		for(i=0;i<10005;i++)
		{
			array1[i]=0;
			array2[i]=0;
			array3[i]=0;
		}
		iter=0;q=0;t=0;r=0;
		scanf("%d",&n);
	}
	return 0;
}
