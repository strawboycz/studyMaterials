#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define FONT_COUNT 26
typedef unsigned char byte;
typedef struct {
    byte id_length;
    byte color_map_type;
    byte image_type;
    byte color_map[5];
    byte x_origin[2];
    byte y_origin[2];
    byte width[2];
    byte height[2];
    byte depth;
    byte descriptor;
} TGAHeader;
typedef struct {
    byte blue;
    byte green;
    byte red;
} Pixel;

void destroy(char **inputPath, char **outputPath, char ** fontDirPath);
Pixel* getPixels(TGAHeader header, FILE* file);
void writeLetter(Pixel *letter,TGAHeader letterHeader,int *x,int *y,Pixel *destination,TGAHeader destinationHeader);
int isBlack(Pixel pixel);
int getPadding(char *input,int count, TGAHeader *headers, int imageWidth);
int main(int argc, char const *argv[])
{
    if (argc != 4)
    {
        printf("Wrong parameters\n");
        return 1;
    }
    char *inputPath = strdup(argv[1]);
    char *outputPath = strdup(argv[2]);
    char *fontDirPath = strdup(argv[3]);

    FILE *inputFile;
    if ((inputFile = fopen(inputPath,"rb")) == NULL)
    {
        printf("Could not load image\n");
        destroy(&inputPath,&outputPath,&fontDirPath);
        return 1;
    }
    TGAHeader inputHeader;
    fread(&inputHeader,sizeof(TGAHeader),1,inputFile);
    Pixel *inputPixels = getPixels(inputHeader,inputFile);
    fclose(inputFile);
    char temp[256] = "";
    
    TGAHeader alphabetHeaders[FONT_COUNT];
    Pixel *alphabetPixels[26];

    char name[2] = "A";
    


    for (int i = 0; i < FONT_COUNT; i++)
    {
        sprintf(temp,"%s/%s.tga",fontDirPath,name);
        fflush(stdin);
        FILE *fontFile;
        if ((fontFile = fopen(temp,"rb")) == NULL)
        {
            destroy(&inputPath,&outputPath,&fontDirPath);
            return 1;
        }
        fread(&alphabetHeaders[i],sizeof(TGAHeader),1,fontFile);
        alphabetPixels[i] = getPixels(alphabetHeaders[i],fontFile);
        fclose(fontFile);
        name[0]++;
    }
    
    
    int top,bottom;
    fgets(temp,strlen(temp),stdin);
    sscanf(temp,"%d %d",&top,&bottom);
    int x = 0;
    int y = 10;
    int increment = 0;
    memcpy(&increment, alphabetHeaders[0].height, 2);
    int width = 0, height = 0;
    memcpy(&width, inputHeader.width, 2);
    memcpy(&height, inputHeader.height, 2);

    char buffer[101] = "";
    for (int i = 0; i < top + bottom; i++)
    {
        
        fgets(buffer,sizeof(buffer),stdin);
        x = getPadding(buffer,strlen(buffer),alphabetHeaders,width);
        if (i == top)
        {
            y = height - (increment * bottom) - 10;
        }
        for (int j = 0; j < strlen(buffer); j++)
        {
            if (!isalpha(buffer[j])){
                if (buffer[j] == ' ')
                {
                    x += 10;
                }
                continue;
            } 
            writeLetter(alphabetPixels[(int) toupper(buffer[j]) - 65],alphabetHeaders[(int) toupper(buffer[j]) - 65],&x,&y,inputPixels,inputHeader);
        }
        
        
        y += increment;
    }
    



    FILE *outputFile;
    if ((outputFile = fopen(outputPath,"wb")) == NULL)
    {
        destroy(&inputPath,&outputPath,&fontDirPath);
        return 1;
    }
    fwrite(&inputHeader,sizeof(inputHeader),1,outputFile);
    
    
    int pixelCount = width * height;

    fwrite(inputPixels,sizeof(Pixel),pixelCount,outputFile);



    fclose(outputFile);

    free(inputPixels);
    for (int i = 0; i < FONT_COUNT; i++)
    {
        free(alphabetPixels[i]);
    }
    
    

    inputPixels = NULL;
    destroy(&inputPath,&outputPath,&fontDirPath);
    return 0;
}
void destroy(char **inputPath, char **outputPath, char ** fontDirPath){
    free(*inputPath);
    free(*outputPath);
    free(*fontDirPath);
    *fontDirPath = *outputPath = *inputPath = NULL;
}
Pixel* getPixels(TGAHeader header, FILE* file) {
    int width = 0;
    int height = 0;

    memcpy(&width, header.width, 2);
    memcpy(&height, header.height, 2);

    Pixel* pixels = (Pixel*) malloc(sizeof(Pixel) * width * height);
    fread(pixels, sizeof(Pixel) * width * height, 1, file);


    return pixels;
}
void writeLetter(Pixel *letter,TGAHeader letterHeader,int *x,int *y,Pixel *destination,TGAHeader destinationHeader){
    int letterWidth = 0, letterHeight = 0;
    memcpy(&letterWidth, letterHeader.width, 2);
    memcpy(&letterHeight, letterHeader.height, 2);

    int destWidth = 0, destHeight = 0;
    memcpy(&destWidth, destinationHeader.width, 2);
    memcpy(&destHeight, destinationHeader.height, 2);

    for (int row = 0; row < letterHeight; row++) {
        for (int col = 0; col < letterWidth; col++) {
            Pixel* letterPixel = letter + (row * letterWidth + col);
            if (isBlack(*letterPixel)) continue;
            Pixel* destPixel = destination + ((*y + row) * destWidth + (*x + col));
            destPixel->blue = letterPixel->blue;
            destPixel->green = letterPixel->green;
            destPixel->red = letterPixel->red;
        }
    }

    *x += letterWidth;
}
int isBlack(Pixel pixel){
    return (pixel.blue == 0 && pixel.green == 0 && pixel.red == 0);
}
int getPadding(char *input,int count, TGAHeader *headers, int imageWidth){
    int output = 0;
    for (int i = 0; i < count; i++)
    {
        if (!isalpha(input[i])){
            if (input[i] == ' ')
            {
                output += 10;
            }
            continue;
        } 
        int letterWidth = 0;
        memcpy(&letterWidth, headers[(int) toupper(input[i]) - 65].width, 2);
        output += letterWidth;
    }
    return (imageWidth - output)/2;
}