#include<stdio.h>
#include<stdlib.h>

long long int preorder[1000000];
long long int inorder[1000000];
long long int extra[1000000];

int main()
{
	long long int i,j,k,N,t,val1,val2,count=0,index=0,z,m,state=0,n,impt,sambar=0;
	//	printf("%lld",9);
	scanf("%lld",&N);
	for(j=0;j<N;j++)
	{
		scanf("%lld",&preorder[j]);
	}

	for(k=0;k<N;k++)
	{
		scanf("%lld",&inorder[k]);
	}

	scanf("%lld",&t);
	//	printf("%lld",t);
	for(z=0;z<t;z++)
	{
		sambar=0;
		count=0;
		index=0;
		state=0;
		//printf("iaduciauhisduchsdic\n");
		//printf("nishan");
		//printf("sreyash");
		scanf("%lld",&val1);
		scanf("%lld",&val2);
		//printf("%lld",val2);
		if(val1==val2)
		{
			printf("%lld\n",val2);
			sambar=1;
		}
		else
		{
		//printf("%lld",val1);

		int time=0;	
	
		for(m=0;m<N;m++)
		{
			if(sambar==1)
				break;
			//	printf("ish");
			//time++;
			//printf("%lld %lld\n",inorder[m],m);


			if(count==2)
				break;

			if(inorder[m]==val1||inorder[m]==val2)
			{
				//printf("%lld",inorder[m]);
				state=1;
				count++;
				
//				continue;
			}
			if(state==1)
			{
				//printf("%lld",inorder[m]);
				extra[index++]=inorder[m];
				
				//printf("impt %lld\n",inorder[m]);
			}
		}


		int state2=0;
		for(n=0;n<N;n++)
		{
			//	printf("kshjcskdc");
			if(sambar==1)
				break;
			for(m=0;m<index;m++)
			{
				if(preorder[n]==extra[m])
				{
					state2=1;
					impt=extra[m];
					break;
				}
			}
			if(state2==1)
				break;
		}
		if(sambar!=1);
		printf("%lld\n",impt);
		}
	}

	return 0;
}
