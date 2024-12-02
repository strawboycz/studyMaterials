#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *parse (const char *program)
{
    int size = 0;
	for (int i = 0; i < strlen(program); i++)
    {
      if (program[i] == 'o')
      {
        size++;
      }      
    }
    int* out;
    out = (int*)malloc(sizeof(int) * size);
    int counter = 0;
    int value = 0;
    for (int i = 0; i < strlen(program); i++)
    {
        switch (program[i])
        {
        case 'o':
            out[counter++] = value;
            break;
        case 'i':
            value++;
            break;
        case 'd':
            value--;
            break;
        case 's':
            value *= value;
            break;
        }
        
    }
	return out;
}


int main()
{
    int count;
    char buff[100];
    scanf("%s",buff);
    int* parsed = parse(buff);
    printf("%d\n",sizeof(*parsed));
     printf("%d\n",sizeof(parsed) / sizeof(parsed[0]));
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n",parsed[i]);
    }
    
    getch();
    return 0;
}
