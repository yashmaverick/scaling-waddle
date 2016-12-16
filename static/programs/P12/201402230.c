#include<stdio.h>
int main()
{ long long int n,i;
	scanf("%lld",&n);
	while(n!=0)
	{ long long int a[n],left_index[n],right_index[n],stack[n][2],cnt=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
                }
		//for(i=0;i<n;i++)
		//	stack[i][1]=0;
		left_index[0]=-1;
		long long int maxl=a[0];
		for(i=1;i<n;i++)
		{ if(a[i]<a[i-1] && a[i-1]<=maxl)
			left_index[i]=i-1;
			if(a[i]>=a[i-1])
				left_index[i]=left_index[i-1];
			if(maxl<a[i])
			{ maxl=a[i];
				left_index[i]=-1;
			}
		     if(a[i]>a[i-1] && a[i]>=maxl)
			     left_index[i]=-1;
		}
	//	for(i=0;i<n;i++)
	//	{ printf("%d ",left_index[i]);
	//	}
	//	printf("\n");
		long long int maxr=a[n-1];
		right_index[n-1]=-1;
		for(i=n-2;i>=0;i--)
		{ if(a[i]<a[i+1] && a[i+1]<=maxr)
			right_index[i]=i+1;
			if(a[i]>=a[i+1])
				right_index[i]=right_index[i+1];
			if(maxr<a[i])
			{ maxr=a[i];
				right_index[i]=-1;
			}
			if(a[i]>a[i+1] && a[i]>=maxr)
				right_index[i]=-1;
		}
	//	for(i=0;i<n;i++)
	//	{ printf("%d ",right_index[i]);
	//	}
	//	printf("\n");
		//int f=1,fm=1,cnt=0;
		cnt=0;
		for(i=0;i<n;i++)
		{ if(left_index[i]==-1 && right_index[i]!=-1)
	                cnt++;
			if(left_index[i]!=-1 && right_index[i]==-1)
				cnt++;
			if(left_index[i]!=-1 && right_index[i]!=-1)
				cnt+=2;
	           //printf("count %d\n",cnt);
		}
   //             printf("count:%d\n",cnt);
		//for(i=0;i<n;i++)
		//{ if(right_index[i]!=-1)
	         //   cnt++;
               // printf("count %d\n",cnt); 
		//}
                long long int top=0;
		stack[top][0]=a[0];
	       stack[top][1]=1;	
		for(i=1;i<n;i++)
		 { if(a[i]==stack[top][0])
			 {  stack[top][1]+=1;
//			    printf("top:%d",top);
			 }
				 else if(a[i]<stack[top][0])
			 { top+=1;
				 stack[top][0]=a[i];
			         stack[top][1]=1;
//		                 printf("top:%d\n",top);
			 }
			 else if(a[i]>stack[top][0])
			 { while(stack[top][0]<a[i] && top>=0)
				 { if(stack[top][1]>1)
					 cnt+=(stack[top][1]*(stack[top][1]-1))/2;
					 top--;
//				 printf("count:%d top:%d\n",cnt,top);
				 }
				 if(stack[top][0]==a[i] && top>=0)
				 {   stack[top][1]+=1;
  //                                    printf("top:%d",top);
				 }
					 if(top==-1)
					 { top++;
						 stack[top][0]=a[i];
				          stack[top][1]=1;
					 }
					 else if(stack[top][0]>a[i])
					  {       top+=1;
						  stack[top][0]=a[i];
						  stack[top][1]=1;
//					          printf("top:%d\n",top);
					  }
			 }
		//    for(i=0;i<=top;i++)
		//	    printf("%d %d\n",stack[i][0],stack[i][1]);
		 }
               // for(i=0;i<k;i++)
		//{ if(count[i]>1)
		//	cnt+=count[i]*(count[i]-1)/2;
		//}
//		printf("top:%d\n",top);
		 for(i=0;i<=top;i++)
		 { //printf("%d\n",stack[i][1]);
			 if(stack[i][1]>1)
			 cnt+=(stack[i][1]*(stack[i][1]-1))/2;
		 }
//		 printf("count %d\n",cnt);
		
		long long int ans=(n*(n-1)/2)-cnt;
		printf("%lld\n",ans);
		cnt=0;
		scanf("%lld",&n);
	}
	return 0;
}

