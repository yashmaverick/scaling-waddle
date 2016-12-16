#include<stdio.h>
int main(){
	long long int total;
	while(1){
		scanf("%lld",&total);
		long long int h[total],i,j,a[total],count=0,top=-1;
		if(total==0){
			break;
		}
		else{
			for(i=0;i<total;i++){
				scanf("%lld",&h[i]);
			}
			for(i=0;i<total;i++)
			{
				if(i==0 || top==-1)
				{
					top++;
					a[top]=h[i];
				}
				else{
					if(a[top]<h[i])
					{
					//	j=top;
						while(top!=-1)
						{
							if(a[top]>=h[i])
							{
								top++;
								a[top]=h[i];
								break;
							}
							else{
								top--;
								count=count+total-i-1;
							//	printf("1  %lld  \n",count);
								if(top==-1)
								{
									top++;
									a[top]=h[i];
									break;
								}
							}
						}
					}
					else {
						top++;
						a[top]=h[i];
					}
				}
				if(top>1)
				{
					for(j=top-1;j>=0;j--)
					{
						if(a[j]>a[top])
						{
							count=count+j;
						//	printf("2  %lld  j=%d\n",count,j);

							break;
						}
					}
				}
			}	
		}
		printf("%lld\n",count);
	}
	return 0;
}
