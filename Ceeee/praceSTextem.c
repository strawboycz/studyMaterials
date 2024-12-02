#include <stdio.h>
#include <stdlib.h>
int parseStringToInt(const char *str);
void toUpper(char *c);
void toLower(char *c);
int countLowerCaseLetters(const char *str);
int countUpperCaseLetters(const char *str);
int countSpaces(const char *str);
void removeRedundantWhiteSpaces(char *str);
void caseWords(char *str);
void removeRedundantCharacters(char *str);
void normalizeString(char *str);
void printStats(const char *str, int initialSpaces, int initialLower, int initialUpper);
int main()
{
   int count;
    char line[51];
    count = parseStringToInt(fgets(line,sizeof(line),stdin));
    int i = 0;
    while(i < count){
        if(fgets(line,sizeof(line),stdin) == NULL){
            printStats(line,0,0,0);
            i++;
            break;
        } 
        if (line[0] == '\n' || line[0] == '\0') continue;  
        int initialSpaces = countSpaces(line); 
        int initialLower = countLowerCaseLetters(line);
        int initialUpper = countUpperCaseLetters(line);
        normalizeString(line);
        printStats(line,initialSpaces,initialLower,initialUpper);
        i++;
        if (i < count) printf("\n");
        
        
    }
    return 0;
}
int parseStringToInt(const char *str){
    int digitCount = 0;
    int isNegative = 0;
    int outp = 0;
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == '-')
        {
            isNegative = 1;
        }
        else if(str[i] >= '0' && str[i] <= '9') digitCount++;
    } 
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] >= '0' && str[i] <= '9')
        {
            int temp = ((int)str[i] - 48);
            for (int j = 0; j < digitCount - 1; j++)
            {
                temp *= 10;
            }
            outp +=  temp;
            digitCount--;
        }
    }
    if (isNegative) outp *= (-1);
    return outp;
}
void toUpper(char *c){
    if (*c >= 'a' && *c <= 'z')
    {
        *c -= 32;
    }
}
void toLower(char *c){
    if (*c >= 'A' && *c <= 'Z')
    {
        *c += 32;
    }
}
int countLowerCaseLetters(const char *str){
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
       if (str[i] >= 'a' && str[i] <= 'z')
       {
            count ++;
       }
    }
    return count;
}
int countUpperCaseLetters(const char *str){
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
       if (str[i] >= 'A' && str[i] <= 'Z')
       {
            count ++;
       }
    }
    return count;
}
int countSpaces(const char *str){
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
       if (str[i] == ' ')
       {
            count ++;
       }
    }
    return count;
}
void removeRedundantWhiteSpaces(char *str){
    int j = 0;
    int i = 0;
    while(str[i] == ' ') i++;
    for(; str[i] != '\0'; i++){
        if(str[i] == '\n') continue;
        if (str[i] == ' ' && (str[i+1] == '\0' || str[i + 1] == ' ' || str[i+1] == '\n')) continue;
        str[j++] = str[i];
    }
    if(str[j-1] == ' ') j--;
    str[j] = '\0';
}
void caseWords(char *str){
    int hasUpper = 0, wordStart = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {

        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            hasUpper = 1;
        }
        if (str[i+1] == '\0' || str[i+1] == ' ')
        {
            for (int j = wordStart; j <= i; j++)
            {
                if (hasUpper)
                {
                    if (j == wordStart)
                    {
                        toUpper(&str[j]);
                    }
                    else{
                        toLower(&str[j]);
                    }
                }
                else{
                    toUpper(&str[j]);
                }
            }
            hasUpper = 0;
            wordStart = i+2;
        }
    }
    

}
void removeRedundantCharacters(char *str){
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i+1] == '\0')
        {
            str[j++] = str[i];
            break;
        }
        if (str[i] != str[i+1])
        {
            str[j++] = str[i];
        }
        
    }
    str[j] = '\0';
}
void normalizeString(char *str){
    removeRedundantWhiteSpaces(str);
    caseWords(str);
    removeRedundantCharacters(str);
}
void printStats(const char *str, int initialSpaces, int initialLower, int initialUpper){
    int lower = countLowerCaseLetters(str);
    int upper = countUpperCaseLetters(str);
    int spaces = countSpaces(str);
    printf("%s",str);
    if (str[0] != '\n')
    {
        printf("\n");
    }
    printf("lowercase: %d -> %d\n",initialLower,lower);
    printf("uppercase: %d -> %d\n",initialUpper,upper);
    printf("spaces: %d -> %d\n",initialSpaces,spaces);
}