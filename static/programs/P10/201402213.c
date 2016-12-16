#include<stdio.h>
char a[1001][100];
int n; 
int front=-1,back=-1;
void insert(char *c)
{
	int i;
	if(front == -1)
	{
		front=back=0;
		for(i=0;c[i]!='\0';i++)
			a[front][i]=c[i];
		a[front][i]='\0';
	}
	else
	{
		front=(front+1)%n;
		for(i=0;c[i]!='\0';i++)
			a[front][i]=c[i];
		a[front][i]='\0';
		if((front)%n==back)
			back=(back+1)%n;
	}
}


int main()
{
	scanf("%d",&n);
	char o[2],s[101];
	scanf("%s",o);
	int p,j,i,temp;
	while(1)
	{
		switch(o[0])
		{
			case 'A': scanf("%d",&p);
				  for(j=1;j<=p;j++)
				  {
					  scanf("%s",s);
					  insert(s);
				  }
				  break;
			case 'R': scanf("%d",&p);
				  for(j=1;j<=p;j++)
				  {
					  if(back==front)
					  {
						  back=front=-1;
						  break;
					  }
					  back=(back+1)%n;
				  }
				  break;
			case 'L': temp=front;
				  if(temp==-1)
					  break;
				  for(j=back;j!=front;j=(j+1)%n)
					  printf("%s\n",a[j]);
				  printf("%s\n",a[j]);
				  break;
			case 'Q':return 0;
				 break;
		}
		scanf("%s",o);
	}
	return 0;
}
