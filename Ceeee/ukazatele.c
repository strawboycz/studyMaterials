#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getCypherCount(int number);
int getInputs(char *mode, int *n, int *m);
void readHistograme(int *histograme, int *input, const int n, const int m);
void printHistogrameHorizontal(int *histograme, const int maxCypherCount, const int m);
void printHistogrameVertical(int *histograme, const int m);
int main()
{
    char mode;
    int n,m;

    if (getInputs(&mode,&n,&m) == 1)
    {
        return 1;
    }
    if (n < 0 || m < 0) return 1;

    int histograme[10] = {0};
    int input;
    readHistograme(histograme,&input,n,m);

    if (mode == 'h')
    {
        int maxCypherCount = getCypherCount(m + 8);
        printHistogrameHorizontal(histograme,maxCypherCount,m);
    }
    if (mode == 'v')
    {
        printHistogrameVertical(histograme,m);
    }
    
    
    return 0;
}



int getCypherCount(int number){
    if (number == 0)
    {
        return 1;
    }
    
    int count = 0;
    while (number > 0)
    {
        count++;
        number /= 10;
    }
    return count;
}
int getInputs(char *mode, int *n, int *m){
    scanf(" %c",mode);
    if (*mode != 'h' && *mode != 'v')
    {
        printf("Neplatny mod vykresleni\n");
        return 1;
    }
    scanf("%d %d",n,m);
    return 0;
}
void readHistograme(int *histograme, int *input, const int n, const int m){
    for (int i = 0; i < n; i++)
    {
        scanf("%d",input);
        if (*input >= m && *input <= m + 8)
        {
            histograme[*input - m]++;
        }
        else{
            histograme[9]++;
        }
    }
}
void printHistogrameHorizontal(int *histograme, const int maxCypherCount, const int m){
    for (int i = 0; i < 10; i++)
        {
            if (i == 9)
            {
                if (histograme[9] < 1) break;
                printf("invalid:");
            }
            else{
                if(maxCypherCount - getCypherCount(i + m) > 0) printf(" ");
                printf("%d",i+m);
            }
            for (int j = 0; j < histograme[i]; j++)
            {
                if (j == 0) printf(" ");
                printf("#");
            }
            printf("\n");
        }
}
void printHistogrameVertical(int *histograme, const int m){
    int maxValue = 0;
        for (int i = 0; i < 10; i++)
        {
            if (histograme[i] > maxValue) maxValue = histograme[i];
        }
        for (int i = maxValue; i >= 0; i--)
        {
            if (i == 0)
            {
                printf("i");
            }
            else if (histograme[9] >= i)
            {
                printf("#");
            }
            else{
                printf(" ");
            }
            for (int j = 0; j < 9; j++)
            {
                if (i == 0)
                {
                    printf("%d",m+j);
                }
                else if (histograme[j] >= i)
                {
                    printf("#");
                }
                else{
                    printf(" ");
                }
                
            }
            printf("\n");
        }
}