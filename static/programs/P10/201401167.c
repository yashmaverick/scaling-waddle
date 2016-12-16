#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>
#define Sc(n) scanf("%lld",&n)
#define sc(n) scanf("%d",&n)
#define SET(a,b) memset(a,b,sizeof(a))
#define DRT()  int t; sc(t); while(t--)
int n,s=0;
typedef long long LL;
int stoi(char *a)
{	int i=0,x=0;
	while(a[i]>='0' && a[i]<='9')
	{	x*=10;
		x+=a[i]-'0';
		i++;
		
	}
	return x;
}
struct node{
	char *a;
	struct node* n;
}*fr,*bk;
typedef struct node node;
void rmv(int i)
{	while(i--)
		{node* tmp=bk;
			bk=tmp->n;
			free(tmp);
		
		s--;}
		if(s==0)
			fr=NULL;
}
void insert(char *a)
{	node* tmp= (node*)malloc(sizeof(node));
	tmp->a=(char*)malloc(strlen(a)*sizeof(char));
	int i=0;
	s++;
	while(*(a+i)!='\0')
	{	*(tmp->a+i)=*(a+i);
		i++;
//		printf("%d %c\n",i,a[i]);
	}
	*(tmp->a+i)='\0';
	tmp->n=NULL;
	if(fr==NULL)
		fr=bk=tmp;
	else{
	fr->n=tmp;
	fr=tmp;}
	if(s>n)
		rmv(s-n);
}
void print()
{	node* it=bk;
	while(it!=NULL)
	{	printf("%s\n",it->a);
		it=it->n;
	}
}
int main()
{
	char s[1000];
	char c[1000];
	int k,i;
	sc(n);
	fr=NULL,bk=NULL;
	while(1)
	{
//	SET(c,0);
		scanf("%c",&c[0]);
		//getchar();
//		printf("%s\n",c);
		if(c[0]=='A')
		{	SET(s,0);
			sc(k);
			//k=stoi(c+2);
//			printf("%d\n",k);
			while(k--)
			{	scanf("%s",s);
				insert(s);//printf("%sss",s);
			}	
//			printf("%d%d",r,f);}
		}
		else if( c[0]=='R')
		{	sc(k);
			//k=stoi(c+2);
			rmv(k);
		}
		else if(c[0]=='L')
			print();
		else if(c[0]=='Q')return 0;
//		printf("%c",c[0]);
	}
	return 0;
}
