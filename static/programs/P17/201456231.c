#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, q, i, j, k, a[10000], b[10000], new[10000], c,d, x, ans;
    int array_first = 0, array_last = 0;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++)
    {
        scanf("%d", &a[i]);     //Preorder
    }
    
    for (i = 0; i < t; i++)
    {
        scanf("%d", &b[i]);         //Inorder
    }
    
    scanf("%d", &q);
    //~ printf("sex\n");
    for (i = 0; i < q; i++)
    {
        scanf("%d %d", &c, &d);
        
        if (c == d)
        {
            printf("%d\n", c);
        }
        
        else
        {
            array_first = 0; array_last = 0;    
            for (j = 0; j < t; j++)
            {
                //~ printf("fuck\n");
                //~ printf("b %d, c %d, d %d\n", b[j], c, d);
                if (b[j] == c || b[j] == d)
                {
                    //~ printf("maa chod\n");
                    if (array_first)
                    {
                        array_last = j;
                        break;
                    }
        
                    else
                        array_first = j;
                        //~ printf("array first %d\n", array_first);
                }
            }

            //~ printf("hi %d %d\n", array_first, array_last);
            
            x = 0;
            if (array_last > array_first)
            {
                for (j = array_first; j <= array_last; j++)
                {
                    new[x] = b[j];
                    //~ printf("sex");
                    //~ printf("%d ", new[x]);
                    x++;
                }
            }
            
            else
            {
                for (j = array_last; j <= array_first; j++)
                {
                    new[x] = b[j];
                    //~ printf("sex");
                    //~ printf("%d ", new[x]);
                    x++;
                }
            }
            //~ printf("x %d\n", x);
            
            ans = 0;
            for (j = 0; j < t; j++)
            {
                if(!ans)
                {
                    for (k = 0; k < x; k++)
                    {
                        if (a[j] == new[k])
                        {
                            ans = a[j];
                            break;
                        }
                    }
                }
                else
                    break;
            }
            
            printf("%d\n", ans);
        }
    }
    
    return 0;
}
    
