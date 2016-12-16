#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define sn(x) scanf("%d", &x);
#define pn(x) printf("%d", x);

char A[10001][101];

int cursize=0;
int head=-1;
int tail=-1;
int sizeq;

void enqueue(char *x)
{
	if(cursize==0)
	{
                tail=0;
		head=tail;
                strcpy(A[tail],x);
                cursize++;
	}
	else if(cursize<sizeq)
	{ 
		tail=(tail+1)%sizeq;
		strcpy(A[tail],x);
                cursize++;
	}
        else if(cursize==sizeq)
        {
                tail=(tail+1)%sizeq;
                head=(head+1)%sizeq;
                strcpy(A[tail],x);
        }
}

void dequeue()
{
        if(cursize!=0)
        {
	        head=(head+1)%sizeq;
                cursize-=1;
        }
        if(cursize==0)
        {
          tail=0;
          head=tail;
        }
}

void front()
{
	if(head!=-1)
		printf("%d\n", A[head]);
}

void print()
{
	int temphead=head;
        int i;
	for(i=0;i<cursize;i++)
	{
		printf("%s\n", A[temphead]);
		temphead=(temphead+1)%sizeq;
        }
}

int main()
{
	sn(sizeq)
	int a,b,i,j,k,nn;
        char mystring[10];
	scanf("%s", mystring);
        char str[101];
	while(mystring[0]!='Q')
	{       
		if(mystring[0]=='A')
		{
                        sn(nn)
                        for(i=0;i<nn;i++)
                        {
			        scanf("%s", str);
			        enqueue(str);
                        }
		}
                else if(mystring[0]=='R')
                {
                  sn(nn)
                  for(i=0;i<nn;i++)
			dequeue();
                }
                else if(mystring[0]=='L')
			print();
		scanf("%s", mystring);
	}
        return 0;
}
