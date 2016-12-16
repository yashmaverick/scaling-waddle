#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
typedef struct list
{
	int var1count;
	int var2count;
}list;
int cmpfunc(const void *a,const void *b)
{
	struct list *l=(struct list *)a;
	struct list *m=(struct list *)b;
	if(l->var1count==m->var1count)
		return l->var2count-m->var2count;
	else return l->var1count-m->var1count;
}
int main()
{
	int t,i,c,var1,var2,var3,count,j,tempcount;
	char s[1000001];
	list temp;
	list *instance;
	scanf("%d",&t);
//	getchar();
	while(t--)
	{
	//	getchar();
		i=0;
		count=0;
//		while((c=getchar_unlocked())!='\n')
//		{
//			s[i++]=c;
			
			
///		}
	//	printf("i=%d\n",i);
	//	s[i]='\0';
	//	for(j=0;j<i;j++)
	//		printf("%c",s[j]);
	//	printf("\n");
		scanf("%s",s);
		i=strlen(s);
		instance=malloc(sizeof(list)*(i+1));
		var1=0;
		var2=0;
		var3=0;
		instance[0].var1count=0;
		instance[0].var2count=0;
//		i=strlen(s);
		for(j=1;j<=i;j++)
		{
			if(s[j-1]=='J')
			{
				var1++;
				
			}
			else if(s[j-1]=='M')
				var2++;
			else if(s[j-1]=='R')
				var3++;
			instance[j].var1count=var2-var1;
			instance[j].var2count=var3-var1;
		}
//		for(j=0;j<i;j++)
//				printf("var1 =%d var2=%d\n",instance[j].var1count,instance[j].var2count);
		qsort(instance,i+1,sizeof(list),cmpfunc);
//		for(j=0;j<i;j++)
//			printf("after sorting var1 =%d var2=%d\n",instance[j].var1count,instance[j].var2count);
		temp.var1count=INT_MIN;
		temp.var2count=INT_MIN;
		tempcount=0;
		count=0;
		//instance[0].var1count=0;
		//instance[0].var2count=0;
		for(j=0;j<=i;j++)
		{
			
			if(temp.var1count!=instance[j].var1count || temp.var2count!=instance[j].var2count)
			{

				temp.var1count=instance[j].var1count;
				temp.var2count=instance[j].var2count;
				tempcount=0;
			}	
		/*	else
			{
				count=count+(tempcount*(tempcount-1))/2;
				tempcount=0;
				temp.var1count=instance[j].var1count;
				temp.var2count=instance[j].var2count;
			}*/
			count=count+tempcount;
			tempcount++;
		}
		printf("%d\n",count);
		free(instance);
	}
	return 0;
}


		
			



