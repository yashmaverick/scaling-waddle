#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct list element;
typedef element *link;
struct list{
	long long int end;//data;
	link a[10];
};
link head;
long long int state;
void trie(char dinesh[])
{
	link temp;
	temp=head;
	long long int k,i,num;
	k=0;
	num=strlen(dinesh);
	while(num--)
	{
		//k=num%10;
		if(temp->a[dinesh[k]-'0']==NULL)
		{
			temp->a[dinesh[k]-'0']=malloc(sizeof(element));
			(temp->a[dinesh[k]-'0'])->end=0;
            for(i=0;i<10;i++)
            {
            	(temp->a[dinesh[k]-'0'])->a[i]=NULL;
            }
		}
		temp=temp->a[dinesh[k]-'0'];
//		temp->data=k;
//		num=num/10;
		k++;
	}
	if((temp->end)==-1)
		state=1;
	temp->end=-1;
}
void check(link node)
{
	if(state==0)
	{
		long long int i;
		if((node->end)==-1)
		{
			for(i=0;i<10;i++)
			{
				if((node->a[i])!=NULL)
				{
					state=1;
					return;
				}
			}
		}
		else
		{
			for(i=0;i<10;i++)
			{
				if((node->a[i])!=NULL)
				{
					check(node->a[i]);
				}
			}
		}
	}

}
void pre(link node)
{
	if(node==NULL)
		return;
//	printf("%lld %lld\n",node->data,node->end);
	long long int i;
	for(i=0;i<10;i++)
	{
		if((node->a[i])!=NULL)
			pre(node->a[i]);
	}
}
int main()
{
	long long int sw,z;
	scanf("%lld",&sw);
	for(z=0;z<sw;z++){
	   long long int i,j,n,num,reverse;
	   scanf("%lld",&n);
	   char dinesh[11];
		head=malloc(sizeof(element));
		for(i=0;i<10;i++)
			head->a[i]=NULL;
		state=0;
		head->end=0;
		for(i=0;i<n;i++)
		{
		//	reverse=0;
			scanf("%s",dinesh);
		/*	while (num!= 0)
   			{
      			reverse=reverse*10;
      			reverse=reverse+num%10;
      			num=num/10;
   			}*/
   		//	printf("%lld\n",reverse);
			trie(dinesh);
		}
	
		check(head);
		if(state==0)
			printf("YES\n");
		else if(state==1)
			printf("NO\n");
//		head->data=-1;
//		pre(head);
    }
	return 0;
}