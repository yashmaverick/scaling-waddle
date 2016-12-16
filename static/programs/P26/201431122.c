#include<stdio.h>
#include<stdlib.h>


typedef struct ll{
	int ind;
	int we;
	struct ll* next;
}ll;

ll *arr[1000005];


void add(int x, int y, int w)
{

	ll *temp;
	temp=(ll *)malloc(sizeof(ll));
	temp->we=w;
	temp->ind=y;
	temp->next=arr[x];
	arr[x]=temp;
}


int head;
int vis[1000005];
int d[1000005];
int xy[1000005];

	
int que[100001];
int start,end;


void find(int node1,int node2)
{
	int i,j,k,l=0,v;
	if(node1==node2)
	{
		d[node2]=l;
		return;
	}

	que[++end]=node1;
	vis[node1]=1;
	que[++end]=-1;

	 while(start!=end)
	 {
		 v=que[++start];
		 if(v==-1)
		 {
			 v=que[++start];
			 l++;
			 que[++end]=-1;
		 }
		 ll * temp=arr[v];
		 while(temp!=NULL)
		 {
			 if(vis[temp->ind]==0)
			 {
			 que[++end]=temp->ind;
			 vis[temp->ind]=1;
			 }
			 if(temp->ind==node2)
			 
			 {
	//			 printf("end %d\n",que[end]);
				 while(start!=end)
				 {
					 v=que[++start];
	//				 printf("q %d\n",v);
						 if(v==-1)
							 l++;
						 else
							 d[v]=l;
				 }
				 return;
			 }
			 temp=temp->next;


		 }


	 }



}

int sv[100001]={0};
int level;
void sieve()
{
	int i,k,f,j,je;
	for(i=2;i<=10000;i++)
	{
		f=1;
		if(sv[i]==0)
		{
			for(k=2;k*k<=i;k++)
			{
				if(i%k==0)
				{
					f=0;
					break;
				}
			}
		}
		if(f==1)
		{je=2;
			for(j=2*i;j<=10000;j=i*je)
			{
				//				printf("j %d\n",j);

				sv[j]=1;
				je++;
			}
		}



	}

}



int main()
{

	sieve();
	int t,a,a0,b0,c0,d0,i,j,k,z;
	for(i=1000;i<10000;i++)
	{
		a0=i%10;
		b0=(i%100-a0)/10;
		c0=(i%1000-i%100)/100;
		d0=(i%10000-i%1000)/1000;
		//		printf("d0 %d c0 %d b0 %d a0 %d\n",d0,c0,b0,a0);
		for(j=0;j<=9;j++)
		{
			if(j!=a0)
			{
				z=d0*1000+c0*100+b0*10+j;
				if(sv[z]==0)
					add(i,z,1);
			}
		}

		for(j=0;j<=9;j++)
		{
			if(j!=b0)
			{
				z=d0*1000+c0*100+j*10+a0;
				if(sv[z]==0)
					add(i,z,1);
			}
		}
		for(j=0;j<=9;j++)
		{
			if(j!=c0)
			{
				z=d0*1000+j*100+b0*10+a0;
				if(sv[z]==0)
					add(i,z,1);
			}
		}

		for(j=1;j<=9;j++)
		{
			if(j!=d0)
			{
				z=j*1000+c0*100+b0*10+a0;
				if(sv[z]==0)
					add(i,z,1);
			}
		}
	}


	/*	int node,te,l;
		scanf("%d",&te);
		while(te--)
		{
		scanf("%d",&node);
		ll * temp=arr[node];
		while(temp!=NULL)
		{
		printf("node-%d n %d\n",node,temp->v);
		temp=temp->next;
		}

		}*/
	int test,node1,node2,ke;
	scanf("%d",&test);
	while(test--)
	{
		start=0;
		end=0;
	for(ke=1000;ke<=10000;ke++)
	{
		vis[ke]=0;
		d[ke]=0;
	}

		level=0;
		scanf("%d%d",&node1,&node2);
		find(node1,node2);
		printf("%d\n",d[node2]);
	}
	return 0;
}
