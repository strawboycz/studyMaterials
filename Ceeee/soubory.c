#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void destroy(char **outputPath,char **inputPath,char **needle);
void toLower(char * str,int count);
void set_red_color();
void reset_color();
int main(int argc, char const *argv[])
{
    int iFlag = 0;
    int oFlag = 0;
    char *outputPath = NULL, *inputPath = NULL, *needle = NULL;
    for (int i = 1; i < argc; i++)
    {
        
        if (argv[i][0] == '-')
        {
            if (strcmp(argv[i],"-i") == 0)
            {
                iFlag++;
            }
            else if (strcmp(argv[i],"-o") == 0)
            {
                if (i + 1 >= argc)
                {
                    printf("Missing output path\n");
                    destroy(&outputPath,&inputPath,&needle);
                    return 1;
                }
                oFlag ++;
                if (oFlag > 1)
                {
                    printf("Parameter -o provided multiple times\n");
                    destroy(&outputPath,&inputPath,&needle);
                    return 1;
                }
                outputPath = strdup(argv[++i]);
            }
        }
        else
        {
            if (inputPath == NULL)
            {
                inputPath = strdup(argv[i]);
            }
            else if (needle == NULL){
                needle = strdup(argv[i]);
            }
            else{
                printf("Too many parameters provided\n");
                destroy(&outputPath,&inputPath,&needle);
                return 1;
            }
        }
        
    }
    if (inputPath == NULL)
    {
        printf("Input path not provided\n");
        destroy(&outputPath,&inputPath,&needle);
        return 1;
    }
    if (needle == NULL)
    {
        printf("Needle not provided\n");
        destroy(&outputPath,&inputPath,&needle);
        return 1;
    }
    if (iFlag > 1)
    {
        printf("Parameter -i provided multiple times\n");
        destroy(&outputPath,&inputPath,&needle);
        return 1;
    }
    if (argc > 6)
    {
        printf("Too many parameters provided\n");
        destroy(&outputPath,&inputPath,&needle);
        return 1;
    }
    FILE *inputFile, *ouputFile;
    if((inputFile = fopen(inputPath,"r")) == NULL) return -1;
    if (oFlag) if((ouputFile = fopen(outputPath,"w")) == NULL) return -1;
    char line[101];
    if (iFlag) toLower(needle,strlen(needle));

    while (fgets(line,101,inputFile) != NULL)
    {
        if (iFlag){
            int offset = 0;
            char * copy;
            copy = strdup(line);
            toLower(copy,strlen(copy));
            char *needlePos = strstr(copy,needle);
            if(needlePos){
                if (oFlag) fprintf(ouputFile,"%s",line);
                else {
                    while (needlePos)
                    {
                        int index = needlePos - copy;
                        for (int i = 0; i < needlePos; i++)
                        {
                            printf("%c",line[i]);
                        }
                        
                        if (copy + index == needlePos)
                        {
                            set_red_color();
                        }
                        if (copy + index == needlePos + strlen(needle))
                        {
                            reset_color();
                            offset = index + strlen(needle);
                            needlePos = strstr(copy + offset,needle);
                            index = 0;
                        }
                        
                    }
                }
            }
            free(copy);
            copy = NULL;
        } 
        else if(strstr(line,needle)){
            if (oFlag) fprintf(ouputFile,"%s",line);
            else {
                 for (int i = 0; i < strlen(line); i++)
                    {
                        if (&line[i] == strstr(line,needle))
                        {
                            set_red_color();
                            
                        }
                        if (&line[i] == strstr(line,needle) + strlen(needle))
                        {
                            reset_color();
                        }
                        
                        printf("%c",line[i]);
                        line[i] == '\0';
                    }
            }
        }
    }
    
    if(oFlag) fclose(ouputFile);
    fclose(inputFile);
    
    destroy(&outputPath,&inputPath,&needle);
    return 0;
}
void destroy(char **outputPath,char **inputPath,char **needle){
    if (outputPath != NULL) free(*outputPath);
    if (inputPath != NULL) free(*inputPath);
    if (needle != NULL) free(*needle);
    outputPath = needle = inputPath = NULL;
}
void toLower(char * str,int count){
    for (int i = 0; i < count; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }
}
void set_red_color() {
  printf("\x1b[41;1m");
  fflush(stdout);
}
void reset_color() {
  printf("\x1b[0m");
  fflush(stdout);
}