#include<stdio.h>
int main()
{
	long long int left_bound,right_bound,left[100002],right[100002],i,j,A[100002],n,area,max_area,min,count_left,count_right;
	while(1)
	{
		scanf("%lld",&n);
		if(n==0)
			break;
		else
		{
			max_area=0;
			for(i=0;i<n;i++)
				scanf("%lld",&A[i]);
			left[0]=-1;
			for(i=1;i<n;i++)
			{
				if(A[i]<min)
					min=A[i];
				if(A[i]>A[i-1])
					left[i]=i-1;
				else
				{
					j=i-1;
					while(A[i]<=A[j] && j>=0)
					{
//						printf("left\n");
						if(left[j]!=-1)
						{
							if(A[left[j]]<A[i])
							{
								left[i]=left[j];
								break;
							}
							else
								j=left[j];
						}
						else
						{
							left[i]=-1;
							break;
						}
//						printf("%lld A[j]\n",A[j]);
					}
				}
//				printf("%lld ",left[i]);
//				if(left[i]==-1)
//					count_left++;
			}
//			printf("\n");
			right[n-1]=-1;
//			count_right=1;
//			printf("%lld ",right[n-1]);
			for(i=n-2;i>=0;i--)
			{
				if(A[i+1]<A[i])
					right[i]=i+1;
				else
				{
					j=i+1;
					while(A[i]<=A[j] && j<n)
					{
//						printf("right\n");
						if(right[j]!=-1)
						{
							if(A[right[j]]<A[i])
							{
								right[i]=right[j];
								break;
							}
							else
								j=right[j];
						}
						else
						{
							right[i]=-1;
							break;
						}
					}
				}
//				printf("%lld right[i] %lld i\n",right[i],i);
//				if(right[i]==-1)
//				{
//					count_right++;
//					printf("%lld ",right[i]);
//				}
//				if(i==0)
//					printf("%lld right[0]\n",right[0]);
			}
//			printf("\n");
//			printf("%lld rright[0]\n",right[0]);
			for(i=0;i<n;i++)
			{
//				printf("%lld left[i] %lld right[i] %lld A[i]\n",left[i],right[i],A[i]);
				if(left[i]==-1 && right[i]==-1)
			//	{
			//		if(max_area<(A[i]*(i+1)))
			//			max_area=((A[i])*(i+1));
			//		if(max_area<((A[n-i-1])*(i+1)))
			//			max_area=((A[n-i-1])*(i+1));
			//	}
					area=A[i]*(n);
				else if(left[i]!=-1 && right[i]!=-1)
					area=A[i]*(right[i]-left[i]-1);
				else if(left[i]!=-1 && right[i]==-1)
					area=((A[i])*(n-left[i]-1));
				else
					area=((A[i])*(right[i]));
			//	area=(A[i]*(right_bound-left_bound+1));
//				printf("%lld area %lld i\n",area,i);
				if(max_area<area)
					max_area=area;
			}
// increasing sequence
/*			if(count_right==n)
			{
//				printf("count_right\n");
				for(i=0;i<n;i++)
					if(max_area<((n-i)*(A[i])))
						max_area=((n-i)*(A[i]));
			}
// decreasing sequence
			else if(count_left==n)
			{
//				printf("count_left\n");
				for(i=0;i<n;i++)
					if(max_area<((i+1)*(A[i])))
						max_area=((i+1)*(A[i]));
			}
			for(i=0;i<n;i++)
			{
				if(left[i]==-1)
				{
					area=((A[i])*(i+1));
					if(max_area<area)
						max_area=area;
				}
				if(right[n-i-1]==-1)
				{
					area=((A[n-i-1])*(i+1));
					if(max_area<area)
						max_area=area;
				}
			} 
		if(max_area<(min*(n)))	
			max_area=(min*(n)); */
		printf("%lld\n",max_area);
		}
	}	
	return 0;	
}
