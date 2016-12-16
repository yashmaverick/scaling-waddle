#include <stdio.h>
#include <stdlib.h>


char * coolest (
        const char * str1,
        const char * str2
        )
{
        char *cp = (char *) str1;
        char *s1, *s2;

        if ( !*str2 )
            return((char *)str1);

        while (*cp)
        {
                s1 = cp;
                s2 = (char *) str2;

                while ( *s1 && *s2 && !(*s1-*s2) )
                        s1++, s2++;

                if (!*s2)
                        return(cp);

                cp++;
        }

        return(NULL);

}
int
cooler(const char *s1, const char *s2, size_t n)
{
    for ( ; n > 0; s1++, s2++, --n)
	if (*s1 != *s2)
	    return ((*(unsigned char *)s1 < *(unsigned char *)s2) ? -1 : +1);
	else if (*s1 == '\0')
	    return 0;
    return 0;
}



int
cool(const char *s1, const char *s2)
{
    for ( ; *s1 == *s2; s1++, s2++)
	if (*s1 == '\0')
	    return 0;
    return ((*(unsigned char *)s1 < *(unsigned char *)s2) ? -1 : +1);
}
int compare(const void *a, const void *b)
{
	return cool(a,b);
}


int main()
{
	int t,juju=0;
	scanf("%d",&t);
	while(juju<t)
	{
		int n,i=0;
		int pichi1=0;
		int i2=1;
		int pompom=0;
		scanf("%d",&n);
		getchar();
		char s[n][11];
		while (i < n)
		{
			scanf("%s",s[i]);
			i++;
		}
		i=0;
		qsort(s,n,11,compare);
		
		while(i2<n)
		{
			if(cooler(s[pichi1],s[i2],1)==0)
			{
				char *r;
				r = coolest(s[i2],s[pichi1]);
				if(r==NULL)
				{
					pichi1++;
					i2++;
				}
				else
				{
					pompom = 1;
					break;
				}
				
			}
			else
			{
				pichi1=pichi1+1;
				i2=i2+1;
			}
		}
		if(pompom!=0)
			printf("NO\n");
		else
			printf("YES\n");
		juju++;

	}
	return 0;
}
