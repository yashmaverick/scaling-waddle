#include<stdio.h>
long long int min(long long int a,long long int b)
{
	if(a<b)
		return a;
	else
		return b;
}
long long int max(long long int a,long long int b)
{
	if(a>b)
		return a;
	else
		return b;
}
long long int maxheap[200002],minheap[200002];
long long int median;
int main()
{
	long long int test;
	long long int a,b,c,n,i,sum,F[200002],min_num,max_num,var,temp,min_ind,min_val,max_ind,max_val;
	scanf("%lld",&test);
	while(test--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		min_num=0;
		max_num=0;
		median=1;
		sum=1;
		F[1]=1;
		for(i=2;i<=n;i++)
		{
			F[i]=((((a*median)%1000000007)+(b*i)%1000000007)+c)%1000000007;
			sum+=F[i];
			if(F[i]>median)
			{
				min_num++;
				minheap[min_num]=F[i];
				temp=min_num;
				while(minheap[temp]<minheap[temp/2] && temp>1)
				{
					var=minheap[temp];
					minheap[temp]=minheap[temp/2];
					minheap[temp/2]=var;
					temp=temp/2;
				}
			}
			else
			{
				max_num++;
				maxheap[max_num]=F[i];
				temp=max_num;
				while(maxheap[temp]>maxheap[temp/2] && temp>1)
				{
					var=maxheap[temp];
					maxheap[temp]=maxheap[temp/2];
					maxheap[temp/2]=var;
					temp=temp/2;
				}
			}
			if(max_num>min_num)
			{
				//inserting median into the minheap
			//	var=median;
				min_num++;
				minheap[min_num]=median;
				temp=min_num;
				while(minheap[temp]<minheap[temp/2] && temp>1)
				{
					var=minheap[temp];
					minheap[temp]=minheap[temp/2];
					minheap[temp/2]=var;
					temp=temp/2;
				}
				//	median=deletemax();
				median=maxheap[1];
				maxheap[1]=maxheap[max_num];
				max_num--;
				if(max_num!=0)
				{
					temp=1;
					while(1)
					{
						if(((2*temp)+1)<=max_num)
						{		
						//both child exists
							if(maxheap[temp]<max(maxheap[2*temp],maxheap[(2*temp)+1]))
							{
								max_ind=max(maxheap[2*temp],maxheap[(2*temp)+1]);
								if(max_ind==maxheap[2*temp])
									max_ind=2*temp;
								else
									max_ind=2*temp+1;
								//		printf("heap[min_ind]: %d\n",heap[min_ind]);
								var=maxheap[temp];
								maxheap[temp]=maxheap[max_ind];
								maxheap[max_ind]=var;
								temp=max_ind;
								//	printf("\n%d %d\n",heap[tep],heap[min_ind]);
							}
							else
								break;
						}
						else if(((2*temp)+1)>max_num && (2*temp)<=max_num)
						{
								if(maxheap[temp]<maxheap[2*temp])
								{
									var=maxheap[temp];
									maxheap[temp]=maxheap[2*temp];
									maxheap[2*temp]=var;
									temp=2*temp;
								}
								else
									break;
						}
						else
								break;
							//	printf("  heap[1] inside: %d\n",heap[1]);
					}
				}
			}
			else if(min_num>max_num+1)
			{
				//inserting median into the maxheap
		//		var=median;
				max_num++;
				maxheap[max_num]=median;
				temp=max_num;
				while(maxheap[temp]>maxheap[temp/2] && temp>1)
				{
					var=maxheap[temp];
					maxheap[temp]=maxheap[temp/2];
					maxheap[temp/2]=var;
					temp=temp/2;
				}
				//	median=deletemin();
		//		printf("min:  %d\n",minheap[1]);
				median=minheap[1];
		//		printf("median inside %lld\n",median);
				minheap[1]=minheap[min_num];
				min_num--;
				if(min_num!=0)
				{
					temp=1;
					while(1)
					{
						if(((2*temp)+1)<=min_num)
						{		
							//both child exists
							if(minheap[temp]>min(minheap[2*temp],minheap[(2*temp)+1]))
							{
								min_ind=min(minheap[2*temp],minheap[(2*temp)+1]);
								if(min_ind==minheap[2*temp])
									min_ind=2*temp;
								else
									min_ind=2*temp+1;
							//		printf("heap[min_ind]: %d\n",heap[min_ind]);
								var=minheap[temp];
								minheap[temp]=minheap[min_ind];
								minheap[min_ind]=var;
								temp=min_ind;
							//				printf("\n%d %d\n",heap[tep],heap[min_ind]);
							}
							else
								break;
		
						}	// only left child exists
						else if(((2*temp)+1)>min_num && (2*temp)<=min_num)
						{
								if(minheap[temp]>minheap[2*temp])
								{
									var=minheap[temp];
									minheap[temp]=minheap[2*temp];
									minheap[2*temp]=var;
									temp=2*temp;
								}
								else
									break;
						}
						//no child exists
						else
							break;
					}					
				}
			}
		}
		printf("%lld\n",sum);
	}	
return 0;
}					
