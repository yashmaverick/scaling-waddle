#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct try
{
	struct try *a[10];
	int end; // end=0 if no does not end here else = 1 

}try;

int main()
{
	int t,i,j;
	scanf("%d",&t);

	while(t--)
	{
		try * head=(try *)malloc(sizeof(try));

		for(i=0;i<10;i++)
			head->a[i]=NULL;

		head->end=0;

		int n,flag=0;
		scanf("%d",&n);

		while(n--)
		{

			try *temp = head;
			char str[13];

			scanf("%s",str);

			for(i=0;i<strlen(str);i++)
			{
				if(temp->a[str[i]-'0']==NULL)
				{
					if(temp->end==1)
						flag=1;

					try *temp2=(try *)malloc(sizeof(try));

					for(j=0;j<10;j++)
						temp2->a[j]=NULL;

					if(i==strlen(str)-1)
						temp2->end=1;
					else
						temp2->end=0;

					temp->a[str[i]-'0']=temp2;

					temp=temp->a[str[i]-'0'];
				
				}
				
				else
				{
					if(i==strlen(str)-1)
						flag=1;

					temp=temp->a[str[i]-'0'];	
					
				}		
			}		
		
		}

		if(flag==1)
			printf("NO\n");
		else
			printf("YES\n");
	
	}

	return 0;
}
