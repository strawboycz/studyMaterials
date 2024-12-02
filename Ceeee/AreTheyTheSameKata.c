#include <stdbool.h>
#include <stddef.h>

bool comp(const int a[/*n*/], const int b[/*n*/], size_t n)
{
    if(a == NULL || b == NULL) return false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (b[j]/a[i] == a[i] || b[j]/a[i] == -a[i])
            {
                break;
            }
            if (j == n - 1)
            {
                return false;
            }
        } 
    }
    
    return false;
}