#include<stdio.h>
#include<limits.h>

# define MAX 100005

int Binary_search(int l,int u,long long int a[],int m)
{
	if(u<l)
		return -1;
	int mid,c,K,Pun;
	Pun=l;
	c=0;
    while(l<=u) //(mid==0 or a[mid-1]<m)
    {
         mid=(l+u)/2;
         if(m==a[mid] )
         {
             c=1;
             K=mid;
             break;
         }
         else if(m<a[mid])
         {
             u=mid-1;

         }
         else
             l=mid+1;
    }
    if(c==0 )
    {
    //rintf("hello\n");
    	c=1;
         return l;
    } 
    else if(c==1)
    {
   //printf("hello\n");
    	while(a[K-1]==a[K] && K-1 >=Pun )
    	 { K--;}
    	
         return K;
    }    
     else
     	return -1;
}


int main()
{
	int TEST;
	long long int A[MAX],B[MAX],C[MAX],Digit[MAX];
	int	P,Q,R,i;
	long long int TEMP1=0,TEMP2=0,TRIPLETS=0;
	scanf("%d",&TEST);
	while(TEST>0)
	{
			TEMP1=0,TEMP2=0;
			TRIPLETS=0;
			
			//A
			scanf("%d",&P);
			for ( i = 0; i < P; i++)
				scanf("%lld",&A[i]);
			//B
			scanf("%d",&Q);
			for ( i = 0; i < Q; i++)
				scanf("%lld",&B[i]);
			//C
			scanf("%d",&R);
			for ( i = 0; i < R; i++)
				scanf("%lld",&C[i]);

			Digit[Q]=0;
			
			for(i=Q-1;i>=0;i--)
			{
				TEMP1 = Binary_search(i,R-1,C,B[i]);
			//	printf("%d\n",TEMP);

				if(TEMP1!=-1 )
				{

					Digit[i] = Digit[i+1] + (R-TEMP1) ;
				}
				else 
					Digit[i]=Digit[i+1];

			}

			for(i=P-1;i>=0;i--)
			{
				TEMP2 = Binary_search(i,Q-1,B,A[i]);

				if(TEMP2 != -1)
					TRIPLETS += Digit[ TEMP2 ];
			}
			printf("%lld\n",TRIPLETS);
		TEST--;
	}
	return 0;
	
}