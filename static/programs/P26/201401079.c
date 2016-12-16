#include<stdio.h>
#include<string.h>
int queue[10000];
int head,tail;
void enque(int x)
{
	tail++;
	queue[tail]=x;
}
int deque()
{
	head++;
	return queue[head];
}
int main()
{
	int b[10000];
	int a[10];
	int cost[10000];
//	int a[100000];
//	int head,tail;
	int i,j,k,l,m,n,t,fl,c,d,num,z;
	int cnt=0;
	for(i=1000;i<10000;i++)
	{
		fl=0;
		for(j=2;j*j<=i;j++)
		{
			if(i%j==0)
			{
				fl=1;
				break;
			}
		}
		if(fl==0)
		{	b[i]=-1;
//		cnt++;
		}
	}
//	if(b[1369]==-1)
//		printf("YES\n");
/*	for(i=1000;i<10000;i++)
	{
		if(b[i]==-1)
			printf("%d\n",i);
	}*/
//	printf("%d\n",cnt);
	scanf("%d",&t);
	while(t--)
	{
		head=-1;
		tail=-1;
		scanf("%d%d",&c,&d);
		if(c==d)
			printf("0\n");
		else
		{

		
		memset(cost , -1 , sizeof(int)*10000);
		cost[c]=0;
                 num=c;
		 z=c;

	        fl=0;
                 
		 while(1)
		 {
			 k=3;

                     l=num;
                 while(l > 0)
		{
		    a[k]=l%10;
	           l=l/10;	
		    k--;    
		}

	//	 k=k-1;
		 
		 
                    for(i=1;i<=9;i++)
		    {   
			    num=a[0]*1000+a[1]*100+a[2]*10+i*1;
			    if(b[num]==-1 && cost[num]==-1)
			    {
                                cost[num]=cost[c]+1;

//				printf("Andargya:%d\n",num);
				if(num==d)
				{
					fl=1;
					break;
				}
			//	printf("Andargya:%d\n",num);
				enque(num);
			    }
		    }
		    if(fl==1)
			    break;

                    for(i=0;i<=9;i++)
		    {   
			    num=a[0]*1000+a[1]*100+i*10+a[3]*1;
			    if(b[num]==-1 && cost[num]==-1)
			    {
                                cost[num]=cost[c]+1;

		//		printf("Andargya:%d\n",num);
				if(num==d)
				{
					fl=1;
					break;
				}
		//		printf("Andargya:%d\n",num);
				enque(num);
			    }
		    }
		   if(fl==1)
			  break; 

                    for(i=0;i<=9;i++)
		    {   
			    num=a[0]*1000+i*100+a[2]*10+a[3]*1;
			    if(b[num]==-1 && cost[num]==-1)
			    {
                                cost[num]=cost[c]+1;

				
		//	printf("Andargya:%d\n",num);
				if(num==d)
				{
					fl=1;
					break;
				}
		//		printf("Andargya:%d\n",num);
				enque(num);
			    }
		    }
		    if(fl==1)
			    break;
		   for(i=1;i<=9;i++) 
		    {   
			    num=i*1000+a[1]*100+a[2]*10+a[3]*1;
			    if(b[num]==-1 && cost[num]==-1)
			    {
                                cost[num]=cost[c]+1;
		//		printf("Andargya:%d\n",num);
				if(num==d)
				{
					fl=1;
					break;
				}
		//		printf("Andargya:%d\n",num);
				enque(num);
			    }
		    } 
		   if(fl==1)
			   break;
		   else if(head==tail+1)
			   break;
		   else
		   {
		   num=deque();
//		   printf("NIKALA:%d\n",num);
		   c=num;
		 //  printf("%d\n",num);
		   }
		   
		 }
//		 if(fl==1)

//		  printf("%d\n",cost[d]);
		  if(cost[d]==-1)
			 printf("Impossible\n");
		 else
			 printf("%d\n",cost[d]);
		}
	}
}
