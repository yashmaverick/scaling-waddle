#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int SpaceEliminate(int text[100]);

typedef struct linkedlist
{

	int *p;
	int var;
	int height;
	int index;
}linkedlist;


int main()
{	
	int number,modulo,u,k,c,h,value,i,*kk,*o;
	linkedlist *S  ;
	scanf("%d %d",&number,&modulo);
	int w,e,j,m=number,l,y,t,f,g,r,v;
	char *tt,oo;
	float gtyd;
	S=(linkedlist *)malloc(sizeof(linkedlist)*number);	
	int T[number];
	e=0;
	for(y=0;y<number;y++)
	{
		scanf("%d",&h);
		{
			w=0;
			S[e].p=malloc(sizeof(int)*h);
			for(f=0;f<h;f++)
			{
				scanf("%d",&value);
				S[e].p[w]=value;
				S[e].var=((S[e].var)+value)%modulo;
				w++;
			}
			T[e]=w-1;
			e++;
		}
	}
	for(w=0;w<m;w++)
	{				
		for(k=0;k<m-1;k++)
		{
			//			l=(S[pp-1].a)-(S[pp].a);
			g=k+1;	
			if((S[g].var)<(S[k].var))
				//			if(l>0)
			{
				c=S[g].var;
				S[g].var=S[k].var;
				S[k].var=c;

				o=S[k].p;
				S[k].p=S[g].p;				
				S[g].p=o; 

				c=T[g];										T[g]=T[k];
				T[k]=c;
			}
		}
	}	
	r=0;
	for(v=0;v<e;v++)
	{
		w=0;
		printf("%d\n",S[v].var);			
		//		for(;T[r]!=0;r++,i++)
		while(T[r]!=-1)
		{
			printf("%d\n",S[v].p[w]);
			w++;
			T[r]--;		
		}
		r++;	
		printf("\n");
	}
	return 0;
}	
   int SpaceEliminate(int text[100])
   {
   int temp,temp1,z;
   while(text[z] != '\0')

   {
   if(text[z] == ' ')
   {	
   int temp1=z+1;
   if(text[temp1] != '\0')
   {
   while(text[temp1] == ' ' && text[temp1] != '\0')
   {
   if(text[temp1] == ' ')
   {
   z++;
   }
   temp++;
   }
   }
   }
   }
   }
