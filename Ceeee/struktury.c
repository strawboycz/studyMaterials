#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
    int index;
    char* name;
    float initialValue;
    float finalValue;
    int tradeCount;
}STOCK;
int stringToStock(char *string,STOCK *stock);
void destroyStock(STOCK *stock);
void printStock(const STOCK stock,const char* name);
int hasName(STOCK stock,const char* name);
void printBestStock(STOCK *stocks,int count,const char* name);
int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        printf("Wrong parameters\n");
        return 1;
    }
    const int n = atoi(argv[2]);
    const char *t = argv[1];
    char buff[100];
    STOCK *stocks;
    stocks = (STOCK*)malloc(sizeof(STOCK) * n);
    for (int i = 0; i < n; i++)
    {
        fgets(buff,100,stdin);
        if(stringToStock(buff,&stocks[i]) == 1){
            for (int j = 0; j < i; j++)
            {
                destroyStock(&stocks[j]);
            }
            free(stocks);
            stocks = NULL; 
            return 1;
        } 
    }
    printf("<html>\n<body>\n");
    printBestStock(stocks,n,t);
    printf("<table>\n");
    printf("<thead>\n");
    printf("<tr><th>Day</th><th>Ticker</th><th>Start</th><th>End</th><th>Diff</th><th>Volume</th></tr>\n");
    printf("</thead>\n");
    printf("<tbody>\n");
    for (int i = n - 1; i >= 0; i--)
    {
        printStock(stocks[i],t);
    }
    printf("</tbody>\n");
    printf("</table>\n");
    printf("</body>\n");
    printf("</html>\n");


    for (int i = 0; i < n; i++)
    {
        destroyStock(&stocks[i]);
    }
    free(stocks);
    stocks = NULL; 
    return 0;
}
int stringToStock(char *string,STOCK *stock){
    string[strcspn(string,"\n")] = '\0';
    char *split;
    split = strtok(string,",");
    if (split == NULL) return 1; 
    stock->index = atoi(split);
    split = strtok(NULL,",");
    if (split == NULL) return 1; 
    stock->name = (char*)malloc(sizeof(char) * strlen(split) + 1);
    if (stock->name == NULL) return 1;
    strcpy(stock->name,split);
    split = strtok(NULL,",");
    if (split == NULL) return 1; 
    stock->initialValue = (float)atof(split);
    split = strtok(NULL,",");
    if (split == NULL) return 1; 
    stock->finalValue = (float)atof(split);
    split = strtok(NULL,",");
    if (split == NULL) return 1; 
    stock->tradeCount = atoi(split);
    return 0;
}
void destroyStock(STOCK *stock){
    free(stock->name);
    stock->name = NULL;
}
void printStock(const STOCK stock,const char* name){
    if (hasName(stock,name))
    {
        printf("<tr>\n");
        printf("\t<td><b>%d</b></td>\n",stock.index);
        printf("\t<td><b>%s</b></td>\n",stock.name);
        printf("\t<td><b>%.2f</b></td>\n",stock.initialValue);
        printf("\t<td><b>%.2f</b></td>\n",stock.finalValue);
        printf("\t<td><b>%.2f</b></td>\n",stock.finalValue - stock.initialValue);
       printf("\t<td><b>");
        int tmp = stock.tradeCount;
        if (tmp < 1000)
        {
            printf("%d",tmp);
        }
        else{
            char buffer[20];
            int i;
            for (i = 1; tmp > 0; i++)
            {
                if (i % 4 == 0 && i != 0)
                {
                    buffer[i - 1] = '_';
                    continue;
                }
                
                buffer[i - 1] = (char)(tmp % 10 + 48);
                tmp /= 10;
            }
            buffer[i] = '\0';
            for (int j = i - 2; j >= 0; j--)
            {
                printf("%c",buffer[j]);
            }
            
        }
        
        
        
        printf("</b></td>\n");
        printf("</tr>\n");
    }
    else{
        printf("<tr>\n");
        printf("\t<td>%d</td>\n",stock.index);
        printf("\t<td>%s</td>\n",stock.name);
        printf("\t<td>%.2f</td>\n",stock.initialValue);
        printf("\t<td>%.2f</td>\n",stock.finalValue);
        printf("\t<td>%.2f</td>\n",stock.finalValue - stock.initialValue);
        printf("\t<td>");
        int tmp = stock.tradeCount;
        if (tmp < 1000)
        {
            printf("%d",tmp);
        }
        else{
            char buffer[20];
            int i;
            for (i = 1; tmp > 0; i++)
            {
                if (i % 4 == 0 && i != 0)
                {
                    buffer[i - 1] = '_';
                    continue;
                }
                
                buffer[i - 1] = (char)(tmp % 10 + 48);
                tmp /= 10;
            }
            buffer[i] = '\0';
            for (int j = i - 2; j >= 0; j--)
            {
                printf("%c",buffer[j]);
            }
            
        }
        
        
        
        printf("</td>\n");
        printf("</tr>\n");
    }
    
}
int hasName(STOCK stock,const char* name){
    if (strcmp(stock.name,name) == 0){
        return 1;
    }
    else return 0;
}
void printBestStock(STOCK *stocks,int count,const char* name){
    int max = 0;
    int maxIndex = -1;
    for (int i = 0; i < count; i++)
    {
        if (hasName(stocks[i],name))
        {
            if (stocks[i].tradeCount > max)
            {
                maxIndex = i;
                max = stocks[i].tradeCount;
            }
            
        }
    }
    if (maxIndex == -1)
    {
        printf("<div>\n");
        printf("Ticker %s was not found\n",name);
        printf("</div>\n");
    }
    else{
        printf("<div>\n");
        printf("<h1>%s: highest volume</h1>\n",stocks[maxIndex].name);
        printf("<div>Day: %d</div>\n",stocks[maxIndex].index);
        printf("<div>Start price: %.2f</div>\n",stocks[maxIndex].initialValue);
        printf("<div>End price: %.2f</div>\n",stocks[maxIndex].finalValue);
        printf("<div>Volume: ");
        int tmp = stocks[maxIndex].tradeCount;
        if (tmp < 1000)
        {
            printf("%d",tmp);
        }
        else{
            char buffer[20];
            int i;
            for (i = 1; tmp > 0; i++)
            {
                if (i % 4 == 0 && i != 0)
                {
                    buffer[i - 1] = '_';
                    continue;
                }
                
                buffer[i - 1] = (char)(tmp % 10 + 48);
                tmp /= 10;
            }
            buffer[i] = '\0';
            for (int j = i - 2; j >= 0; j--)
            {
                printf("%c",buffer[j]);
            }
            
        }
        printf("</div>\n");
        printf("</div>\n");
    }
    
    
}