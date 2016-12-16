#include<stdio.h>
#include<stdlib.h>

char a[10000][100];
int beg=0,end=0;

void push(int N)
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
	int insert=(beg+end)%N;
	scanf("%s",a[insert]);
        if(end!=N)
	    end++;
	else 
	    beg=(beg+1)%N;
       //printf("%d%d%d",beg,end,insert);
    }
        //printf("%d%d%d",beg,end,insert);
}

void pop(int N)
{
    int n;
    scanf("%d",&n);
    end=(end-n);
    beg=(beg+n)%N;
//printf("%d%d",beg,end);
}


void show(int N)
{
    int i=0;
    int k=beg;
    do
    {
	if(i<end)
	{
	    int insert=(k+i)%N;
	    printf("%s\n",a[insert]);
	    i++;
	}
        else
	{
	    break;
	}

    }while(1);
}

int main()
{
    char opt[2];
    char d;
    int flag=0;
    int N;
    scanf("%d",&N);
    //scanf("%c",&d);
    while(flag==0)
    {
	//printf("x");
	//scanf("%s",opt);
	scanf("%s",opt);
        //printf("y %d",n);
	if(opt[0]=='A'||opt[1]=='a')
	    push(N);
	else if(opt[0]=='R'|| opt[0]=='r')
	    pop(N);
	else if(opt[0]=='l'||opt[0]=='L')
	    show(N);
	else
	    flag=1;
    }
    return 0;
}
