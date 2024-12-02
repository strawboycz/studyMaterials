#include <stdio.h>
#include <stddef.h>
void move_zeros(int len, int arr[len]);
int maxSequence(const int* array, size_t n) {
    if(n == 0) return n;
    

}
int main(int argc, char const *argv[])
{
    int array[] = {0,1,0,0,2,3,5,0};
    //move_zeros(8,array);
    for (int i = 0; i < 8; i++)
    {
        printf("%d\n",array[i]);
    }
    getch();
    return 0;
}
void move_zeros(int len, int arr[len])
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (arr[j] == 0 && j != len - 1)
            {
                if (arr[j + 1] != 0)
                {
                    int tmp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = tmp;
                }
                
            }
            
        }
        
        
    }
    
}
