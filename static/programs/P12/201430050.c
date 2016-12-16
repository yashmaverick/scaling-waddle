#include<stdio.h>
#include<stdlib.h>
typedef long long int lld;
void push(lld *stac,lld *top,lld x)
{(*top)++;
	stac[*top]=x;
}
void pop(lld *a,lld *top)
{(*top)--;
}
int main()
{ lld b[500010],stac[500010];
	while(1)
	{ lld n;      
		scanf("%lld",&n);
		if(n==0)
			break;
		/*int *b=(lld*)malloc(n*sizeof(int));
		int *stac=(*)malloc(n*sizeof(int));
		*/
		lld i,tops=-1;
		for(i=0;i<n;i++)
			scanf("%lld",&b[i]);
		push(stac,&tops,b[0]);
		lld sum=0;
		for(i=1;i<n;i++)
		{lld count=0;
			lld flag=0,c2=0,y=1,flag3=0,count2=0;
			lld sum3=0;
			if(b[i]<=stac[tops])
				push(stac,&tops,b[i]);
			else
			{
				while(tops>=0 && b[i]>stac[tops])
				{flag=1;
					if(tops>0) 
					{if(stac[tops]==stac[tops-1]) 
						{y++;
							flag3=1;
						}

						else
						{    count2++;
							sum3=sum3+y-1;
							c2=c2+((y)*(y-1))/2;
							y=1;
						}
					}

				
				//c2=c2+((y)*(y-1))/2;
				pop(stac,&tops);
				count++;	  
				}	

				c2=c2+((y)*(y-1))/2;

			}
			if(flag==1)
			{       
				//push(stac,&tops,b[i]);
				if(tops+1>0)
				{if(flag3==1)

					{	sum=sum+count+count2+sum3+c2;
				//	printf("%lld\n",sum);
				}
					else
					{sum=sum+count+count-1+1;
					   //      printf("%lld\n",sum);
					}
				}
				else
					if(tops+1==0)
				{
					{if(flag3==1)
						{sum=sum+count+sum3+count2+c2;
						//printf("sumforstackemptybutrepetion=%lld\n",sum);
						}
						else
						{	//printf("sum=%lld\n",sum);
							sum=sum+count+count-1;
							//printf("sum=%lld\n",sum);
					}
					}
				}


				push(stac,&tops,b[i]);
			}

		}
	//printf("%d\n",sum);
	lld flag1=0,flag11=0,y1=1,count1=0,c21=0,count11=0;
	lld sum2=0;
	while(tops>=0)
	{flag1=1; 
		if(tops!=0)
		{if(stac[tops]==stac[tops-1])
			{y1++;
				flag11=1;
			}
			else
			{	
				count11++;	
				c21=c21+((y1)*(y1-1))/2;
				sum2=sum2+y1-1;
				y1=1;
			}
		}
		//sum2=sum2+y1-1;
		pop(stac,&tops);
		count1++;

	}
        //sum2=sum2+y1-1;
	c21=c21+((y1)*(y1-1))/2;
	if(flag1==1)
	{if(flag11==1)
		sum=sum+sum2+count11+c21;
		else
			sum=sum+count1-1;
	 }
	//printf("%lld\n",sum);
	lld t2;
	t2=(n*(n-1))/2-sum;
	printf("%lld\n",t2);
	//printf("\n");
}
return 0;
}
