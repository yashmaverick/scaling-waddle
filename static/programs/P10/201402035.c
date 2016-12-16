#include<stdio.h>
int n;
int sum;
int flag=0;
int head=0;
int tail=0;
char a[10000][100];
void list()
{
	int i=head;
	if(flag==0 && head==tail)
		return;
	while(1)
	{
		printf("%s\n",a[i]);
		i++;
		i=(i)%n;
		if(i==tail)
			return ;
	}
}

void append(){
	int i,x;
			scanf("%d",&x);
	for(i=0;i<x;i++)
	{
		scanf("%s",a[tail]);
		tail++;
		tail=(tail)%n;
		sum++;
		if(sum>n-1){
			sum=n;
			flag=1;
		}
		if(flag==1)
			head=tail;
	}
}


void del(){
	int i,y;
			scanf("%d",&y);
	for(i=0;i<y;i++){
		head++;
		head=(head)%n;
		sum--;
		if(sum<n)
			flag=0;
	}
}


int main()
{
	char a;
	scanf("%d",&n);
p:
		scanf("%c",&a);
		if(a=='Q')
			return 0;
		else if(a=='L')
			list();
		else if(a=='A')
			append();
	
		else if(a=='R')
			del();
	
goto p;
}

