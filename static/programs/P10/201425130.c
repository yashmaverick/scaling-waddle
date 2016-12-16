#include<stdio.h>
struct uniq
{
	char a[103];
};
int main()
{
	int k,n,s,l,v,i,e,flag,z,h,w;
	char c;
	int start,end;
	start=-1;
	end=-1;
	struct uniq b[10000];
	scanf("%d",&z);
	scanf("%c",&c);
	h=0;
	while(1)
	{
		h=0;
		w=0;
		flag=0;
		if(c=='A')
		{
			scanf("%d",&n);
		}
		if(c=='R')
		{
			scanf("%d",&s);
		}
		if(c=='Q')
			return 0;
		if(c=='A')
		{
			if(end==-1)
			{
				start=0;
			}
			//printf("before appendind start is %d\n",start);

			//printf("l starting at %d snd end at %d\n",(end+1),((end+1)+n));
			for(l=(end+1);l<((end+1)+n);l++)
			{
				//printf("for loop running\n");
				//printf("z-1 value %d\n",(z-1));
				//printf("l value is %d\n",l);
				if(l==start)
				{
					if(l!=0)
						w=1;
				}
				if(l<=(z-1))
				{
					//printf("scanning in first if aond\n");
					scanf("%s",b[l].a);
					if(l==(z-1))
						h=1;
				}
				if(l>=z)
				{
					flag=1;
					e=l%z;
					scanf("%s",b[e].a);
					//printf("scan in 2 nd if\n");

				}
			}
			if(flag==1)
			{
				//printf("end from if flag \n");
				end=e;
				//printf("befor start is %d\n",start);
				if((end>=start)&&(h==1))
				{
					if((end+1)<=(z-1))
						start=end+1;

					if((end+1)>=(z-1))
						start=(end+1)%z;
					//printf("start is %d\n",start);
				}
			}
			else
			{
				//printf("end from else\n");
				end=(l-1);
				if((end>=start)&&(h==1))
				{
					if((end+1)<=(z-1))
						start=end+1;
					if((end+1)>=(z-1))
						start=(end+1)%z;
				}
			}
			if(w==1)
			{
				if(end<start)
					start=end+1;
				printf("w con entered is %d\n",w);
			}
			//printf("end is %d\n",end);
			//printf("start after is %d\n",start);

			/*for(l=0;l<n;l++)
			  {
			  end=end+1;
			  }*/
		}
		if(c=='R')
		{
			for(v=0;v<s;v++)
			{
				if(start==end)
				{
					start=-1;
					end=-1;
					h=0;
					//printf("path break \n");
					break;
				}



				if(start<(z-1))
				{
					start=start+1;
				}
				else{
					if((start+1)>=z)
					{
						start=(start+1)%z;
					}
				}
			}
			//printf("strat moved to %d\n",start);
			//printf("end is %d\n",end);
		}
		if(c=='L')
		{
			if(end!=-1){
				//printf("l loop enter\n");
				if(start<end)
				{
					for(i=start;i<=end;i++)
					{
						//printf("entered printing loop\n");
						printf("%s\n",b[i].a);
					}
				}
				if(start>end)
				{
					for(i=start;i<z;i++)
					{
						printf("%s\n",b[i].a);
					}
					for(i=0;i<=end;i++)
					{
						printf("%s\n",b[i].a);
					}

				}
				if(start==end)
				{
					printf("%s\n",b[start].a);
				}

			}
		}


		scanf("%c",&c);
	}
	return 0;
}
