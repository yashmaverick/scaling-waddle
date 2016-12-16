#include<stdio.h>
#include<stdlib.h>
struct BAG
{
	int m;
	struct BAG *next;
	int sum;
	int *array;
};
int main()
{
	int N,MOD;
	int i,j;
	struct BAG *bag,*head=NULL,*temp,*prev;
	//	bag = (struct BAG*)malloc(sizeof(struct BAG)); 
	scanf("%d %d",&N,&MOD);
	for(i=0;i<N;i++)
	{
		bag = (struct BAG*)malloc(sizeof(struct BAG)); 
		scanf("%d",&(bag->m));
		(bag->sum) = 0;
		(bag->next)=NULL;
		(bag->array)=(int*)malloc((bag->m)*sizeof(int));
		for(j=0;j<(bag->m);j++)
		{
			scanf("%d",&(bag->array[j]));
			(bag->sum) = (bag->sum) + (bag->array[j]);
			(bag->sum) = (bag->sum) % MOD;
		}
		if(head == NULL)
		{
			head=bag;
		}
	//	temp = prev->next;
		else
		{
			prev=head;
			if(head->next != NULL)
			{
				temp=head->next;

				while(prev->next != NULL)
				{
					if((temp->next)==NULL && ((temp->sum) < (bag->sum)))
					{
						temp->next = bag;
						break;
					}
					else if((bag->sum) < (temp->sum) && (bag->sum) >= (prev->sum))
					{
						(bag->next) = temp;
						(prev->next) = bag;
						break;
					}
					else if((bag->sum)<(head->sum))
					{
						(bag->next) = head;
						head = bag;
						break;
					}
					else
					{
						prev = prev->next;
						temp = temp->next;
					}
				}
			}
			else
			{
				if((bag->sum) >= (head->sum))
				{
					head->next = bag;
				}
				else
				{
					(bag->next) = head;
					head = bag;
				}
			}
		}
	}

	temp = head;
	int flag=0;
	while(flag==0)
	{
		printf("%d\n",(temp->sum));
		for(i=0;i<(temp->m);i++)
			printf("%d\n",(temp->array[i]));
		printf("\n");
		if(temp->next==NULL)
			flag=1;
		temp=temp->next;
	}
	return 0;
}










