#include <stdio.h>
#include <stdlib.h>
int main()
{
	int pos=0;
	pos=pos+1;
	int n;
	int i = 0;
	pos++;
	int marker = 0;
	long long int  sum = 0;
	int useless;
	while(scanf("%d",&n)!=0)
	{
		if(pos>0)
		{
			pos=0;
		}

		if(n == 0)
		{
			break;
		}
		int * a = (int *)calloc(sizeof(int),n);
		pos++;
		int * b = (int *)calloc(sizeof(int),n);
		pos++;
		i = 0;
		marker = 0;
		pos++;
		sum = 0;

		while(i < n)
		{
			pos++;
			scanf("%d",&a[i]);
			i++;
		}
		pos++;

		b[0] = a[0];


		for(i=1;i<n;i++)
		{
			if(pos==0)
			{
				pos++;
			}
			if(a[i] > b[marker])
			{
				pos++;
				marker --;
				pos++;
				sum += n - 1 - i;

				while(1){

					if(marker == -1)
					{
						pos++;
						break;
					}

					if(a[i] > b[marker])
					{
						pos++;
						marker --;
						pos++;
						sum += n - 1 - i;
					}

					if(marker == -1)
					{
						pos++;
						break;
					}

					if(a[i] <= b[marker])
					{
						if(pos==0)
						{
							pos++;
						}
						if(a[i]==b[marker])
						{
							if(pos==0)
							{
								pos++;
							}
							useless = marker;
							while(useless >= 0)
							{
								if(b[useless]!=a[i])
								{
									pos++;
									break;
								}
								else
								{
									useless--;
								}
							}
							if(useless > 0)
							{
								pos++;
								sum += useless;
							}
							break;								
						}
						pos++;
						sum += marker;
						break; 
					}
				}
			}
			else if(a[i] == b[marker])
			{
				pos++;
				useless = marker;
				while(useless >= 0)
				{
					pos++;
					if(b[useless]!=a[i])
					{
						pos++;
						break;
					}
					else
					{
						pos++;
						useless--;
					}
				}
				if(useless > 0)
				{
					pos++;
					sum += useless;
				}
			}
			else
			{
				pos++;
				sum += marker;
			}
			if(pos>0)
			{
				pos=0;
			}	
			pos++;
			marker ++;
			pos++;
			b[marker] = a[i];
		}

		printf("%lld\n",sum);
	}
	return 0;
}
