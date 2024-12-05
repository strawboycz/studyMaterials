#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char name[100];
    char city[100];
    int naughtiness;
    int presentCount;
}Child;
int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        return 1;
    }
    int childrenCount = atoi(argv[1]);
    int statementCount = atoi(argv[2]);
    Child *children;
    if ((children = (Child*)malloc(sizeof(Child) * childrenCount)) == NULL)
    {
        return 1;
    }
    char buffer[256];
    for (int i = 0; i < childrenCount; i++)
    {
        fgets(buffer,sizeof(buffer),stdin);
        char *token = strtok(buffer,",");
        strcpy(children[i].name,token);
        token = strtok(NULL,",");
        strcpy(children[i].city,token);
        token = strtok(NULL,",");
        children[i].naughtiness = atoi(token);
        token = strtok(NULL,",");
        token[strcspn(token,"\n")] = '\0';
        children[i].presentCount = atoi(token);
    }

    for (int i = 0; i < statementCount; i++)
    {
        fgets(buffer,sizeof(buffer),stdin);
        if (strstr(buffer,"naughtiest-named,"))
        {
            int mostNaughtyIndex;
            int biggestNaughtiness = 0;
            for (int i = 0; i < childrenCount; i++)
            {
                char delimiter = buffer[17];
                if (strchr(children[i].name,delimiter))
                {
                    if (biggestNaughtiness < children[i].naughtiness)
                    {
                        biggestNaughtiness = children[i].naughtiness;
                    }
                    mostNaughtyIndex = i;
                }
            }
           printf("%s,%d\n",children[mostNaughtyIndex].name,children[mostNaughtyIndex].naughtiness);
        }
    }
    free(children);
    children = NULL;
    return 0;
}
