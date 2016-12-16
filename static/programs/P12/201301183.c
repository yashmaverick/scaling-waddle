#include <stdio.h>
#include <stdlib.h>
int first=0;
int main()
{
	int n;
	while(scanf("%d",&n)!=0)
	{
		if(first==0)
		{
			first++;
		}
			int i=0,pointer=0,temp,a[n],b[n];
			long long int  sum = 0;	
			if(n == 0)
			{
				break;
			}
			for(i=0;i<n;i++)
			{
				first++;
				scanf("%d",&a[i]);
				first++;
			}
				first++;
			b[0] = a[0];			
				first++;
			for(i=1;i<n;i++)
			{
				first++;
				if(a[i] > b[pointer])
				{
				first++;
					pointer --;
				first++;
					sum += n - 1 - i;	
				first++;
					while(1)
					{
				first++;
						if(pointer == -1)
						{
				first++;
							break;
						}
				first++;
						if(a[i] > b[pointer])
						{
				first++;
							pointer --;
				first++;
							sum += n - 1 - i;
						}
						if(a[i] <= b[pointer])
						{
				first++;
							if(a[i]==b[pointer])
							{
								temp = pointer;
				first++;
								while(temp >= 0)
								{
									if(b[temp]!=a[i])
									{
				first++;
										break;
									}
									else
									{
				first++;
										temp--;
									}
								}
								if(temp > 0)
									sum += temp;
								break;								
							}
				first++;

							sum += pointer;
				first++;
							break; 
						}
					}
				}
				else if(a[i] == b[pointer])
				{
				first++;
					temp = pointer;
				first++;
					while(temp >= 0)
					{
				first++;
						if(b[temp]!=a[i])
							break;
						else
							temp--;
					}
					if(temp > 0)
					{
				first++;
						sum += temp;
					}
				}
				else
				{
				first++;
					sum += pointer;
				}
				pointer ++;
				first++;
				b[pointer] = a[i];
			}
				first++;
			printf("%lld\n",sum);
	}
	return 0;
}
