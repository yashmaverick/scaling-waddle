#include<stdio.h>
#include<stdlib.h>

typedef struct t
{
		int d;
		struct t* next;
}t;
int a[500005];
int p=1;
int vs[500005];

int min(int i,int j)
{
		if(a[i]>a[j])
				return j;
		return i;
}

void shuffleup(int pos)
{
		if(a[pos/2]>a[pos] && pos!=1)
		{
				int temp;
				temp=a[pos/2];
				a[pos/2]=a[pos];
				a[pos]=temp;

				shuffleup(pos/2);
		}
}

void shuffledown(int pos)
{
		if(a[pos*2]!=0)
		{
				int posd=pos*2;
				if(a[pos*2+1]!=0)
						posd=min(2*pos,2*pos+1);
				if(a[posd]<a[pos])
				{
						int temp;
						temp=a[pos];
						a[pos]=a[posd];
						a[posd]=temp;

						shuffledown(posd);
				}
		}

}


void insert(int num)
{
		a[p]=num;
		shuffleup(p);
		p++;
}

int pop()
{
		int temp=a[1];
		a[1]=a[p-1];
		a[p-1]=0;
		p--;
		shuffledown(1);
		return temp;
}


int main()
{
		int n,m;
		t* ar[500005];
		int in[500005]={};
		int out[500005]={};
		scanf("%d%d",&n,&m);
		int k;
		for( k=1 ; k<=n ; k++ )
		{
				ar[k]=(t*)malloc(sizeof(t));
				ar[k]->next=NULL;
		}

		while( m-- )
		{
				int i,j;
				scanf("%d%d",&i,&j);
				in[j]++;
				out[i]++;
				t* temp;
				temp=(t*)malloc(sizeof(t));
				temp->d=j;
				temp->next=ar[i]->next;
				ar[i]->next=temp;
		}
		for( k=1 ; k<=n ; k++ )
				if( in[k]==0 )
				{
						insert(k);
						vs[k]=1;
				}

	//	for(k=1 ; k<p ; k++)
	//			printf("%d\n",a[k]);
		int count=0;
		while( p!=1 )
		{
				count++;
				int tmp=pop();
				t* yo=ar[tmp]->next;
				printf("%d",tmp);
				if(count!=n)
						printf(" ");
				while( yo!=NULL )
				{
						in[yo->d]--;
						if( in[yo->d]==0 && vs[yo->d]!=1 )
						{
								insert(yo->d);
								vs[yo->d]=1;
						}
						yo=yo->next;
				}
		}
		printf("\n");
		return 0;
}
