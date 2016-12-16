#include<stdio.h>
#include<stdlib.h>
#define Mod 1000000007

long long int MINheap[200004],MAXheap[200004];
int endmin=-1,endmax=-1,frontmin=0,frontmax=0;

long long int Fun;
void minidelete();
void maxiidelete();

void Insertmin(int i)
{
	int c,Root,temp;
	c=i;
		while(c!=frontmin)
		{
			Root=(c-1)/2;
			if(MINheap[Root]>MINheap[c])
			{
				temp=MINheap[Root];
				MINheap[Root]=MINheap[c];
				MINheap[c]=temp;
					
			}
			c=Root;
			
		}
}

void Insertmax(int i)
{
	int c,Root,temp;
	c=i;
		while(c!=frontmax)
		{
			Root=(c-1)/2;
			if(MAXheap[Root]<MAXheap[c])
			{
				temp=MAXheap[Root];
				MAXheap[Root]=MAXheap[c];
				MAXheap[c]=temp;
					
			}
			c=Root;
			
		}
}

void Balanceheap()
{
	if((endmax-endmin) >=2)
	{
		endmin++;
		MINheap[endmin]=MAXheap[frontmax];
		Insertmin(endmin);
		maxiidelete();		
	}
	else if((endmax-endmin) <= -2)
	{
		endmax++;
		MAXheap[endmax]=MINheap[frontmin];
		Insertmax(endmax);
		minidelete();

	}
	else return;

}
int main()
{
	int Test;
	scanf("%d",&Test);
	while(Test-- >0)
	{
		long long int a,b,c,N,sum,median;
		int i;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&N);
		if(N==1)
			printf("1\n");
		else if(N==2)
			printf("%lld\n",1+(a+b*2+c)%Mod);
		
		else if(N>2)
		{
			endmax=-1,endmin=-1,frontmax=0,frontmin=0,sum=0;
			for(i=0;i<=N;i++)
			{
				MAXheap[i]=0;
				MINheap[i]=0;
			}

			endmax++;
			MAXheap[endmax]=1;
			Insertmax(endmax);

			Fun=(a%Mod+(b*2)%Mod+c%Mod)%Mod;
			if(Fun>=1)
			{	
				endmin++;
				MINheap[endmin]=Fun;
				Insertmin(endmin);
			}
			else
			{
				endmax++;
				MAXheap[endmax]=Fun;
				Insertmin(endmax);	
			}
			sum=1+Fun;

			for(i=3;i<=N;i++)
			{
				//printf("endmin= %d  endmax=%d\n",endmin,endmax);
				if(endmin==endmax)
					median=MAXheap[frontmax];
				else if(endmax>endmin)
					median=MAXheap[frontmax];
				else
					median=MINheap[frontmin];
			//	printf("median=%lld\n",median);
				Fun=((a%Mod*median%Mod)%Mod+(b*i)%Mod+c%Mod)%Mod;
				//printf("Fun=%d\n",Fun);
				sum=sum+Fun;
				if(Fun<=MAXheap[frontmax])
				{
					endmax++;
					MAXheap[endmax]=Fun;
					Insertmax(endmax);					
				}

				else
				{
					endmin++;
					MINheap[endmin]=Fun;
					Insertmin(endmin);					
				}
				Balanceheap();
			}
			printf("%lld\n",sum);
		}
	}
	return 0;
}

void minidelete()
{
	int b,temp,child,temp1;
	int tempo;
	tempo=MINheap[frontmin];
	MINheap[frontmin]=MINheap[endmin];
	MINheap[endmin]=tempo;
	endmin--;
	b=frontmin;
	while(b!=endmin && endmin!=-1)
	{
		child=2*b+1;
		if(child>endmin)
			break;
		if(MINheap[b]<MINheap[child] )
			if(MINheap[b]<MINheap[child+1] )
				break;
		if(MINheap[b]>MINheap[child])
		{	
			if(child+1>endmin)
			{
				temp1=MINheap[b];
				MINheap[b]=MINheap[child];
				MINheap[child]=temp1;
				b=child;
			}
			else if(MINheap[child]<MINheap[child+1] && child+1<=endmin)
			{
				temp1=MINheap[b];
				MINheap[b]=MINheap[child];
				MINheap[child]=temp1;
				b=child;
			}
			else if(MINheap[child]>MINheap[child+1] && child+1<=endmin)
			{
				temp1=MINheap[b];
				MINheap[b]=MINheap[child+1];
				MINheap[child+1]=temp1;
				b=child+1;
			}
			else
				break;
			
		}
		else if(MINheap[b] >MINheap[child+1] )
		{
			if(MINheap[child+1] < MINheap[child] && child+1<=endmin)
			{
				temp1=MINheap[b];
				MINheap[b]=MINheap[child+1];
				MINheap[child+1]=temp1;
				b=child+1;
			}
			else if(MINheap[child]<MINheap[child+1] && child+1<=endmin)
			{
				temp1=MINheap[b];
				MINheap[b]=MINheap[child];
				MINheap[child]=temp1;
				b=child;
			}
			else
				break;
		}
		else break;	
	}
}
void maxiidelete()
{
	int b,temp,child,temp1;
	int tempo;
	tempo=MAXheap[frontmax];
	MAXheap[frontmax]=MAXheap[endmax];
	MAXheap[endmax]=tempo;
	endmax--;
	b=frontmax;
	while(b!=endmax && endmax!=-1)
	{
		child=2*b+1;
		if(child>endmax)
			break;
		if(MAXheap[b]>MAXheap[child] )
			if(MAXheap[b]>MAXheap[child+1] )
				break;
		if(MAXheap[b]<MAXheap[child])
		{	
			if(child+1>endmax)
			{
				temp1=MAXheap[b];
				MAXheap[b]=MAXheap[child];
				MAXheap[child]=temp1;
				b=child;
			}
			else if(MAXheap[child]>MAXheap[child+1] && child+1<=endmax)
			{
				temp1=MAXheap[b];
				MAXheap[b]=MAXheap[child];
				MAXheap[child]=temp1;
				b=child;
			}
			else if(MAXheap[child]<MAXheap[child+1] && child+1<=endmax)
			{
				temp1=MAXheap[b];
				MAXheap[b]=MAXheap[child+1];
				MAXheap[child+1]=temp1;
				b=child+1;
			}
			else
				break;
			
		}
		else if(MAXheap[b] <MAXheap[child+1] )
		{
			if(MAXheap[child+1] > MAXheap[child] && child+1<=endmax)
			{
				temp1=MAXheap[b];
				MAXheap[b]=MAXheap[child+1];
				MAXheap[child+1]=temp1;
				b=child+1;
			}
			else if(MAXheap[child]>MAXheap[child+1] && child+1<=endmax)
			{
				temp1=MAXheap[b];
				MAXheap[b]=MAXheap[child];
				MAXheap[child]=temp1;
				b=child;
			}
			else
				break;
		}
		else break;	
	}
}