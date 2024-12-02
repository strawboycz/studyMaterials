

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x,y;
}Wall;



void initializeMazeRow(char* mazeRow,int width){
    for (int j = 0; j < width; j++)
    {
        mazeRow[j] = (char)254;
    }
}
void printMazeRow(char* mazeRow, int width){
        for (int j = 0; j < width; j++)
        {
            printf("%c",mazeRow[j]);
        }
        printf("\n");

}



int main(){
    // Maze init
    int mazeWidth,mazeHeight;
    scanf("%d %d",&mazeHeight,&mazeWidth);
    char** maze;
    if((maze = (char**)malloc(sizeof(char*) * mazeHeight)) == NULL) return 1;
    for (int i = 0; i < mazeHeight; i++)
    {
        if((maze[i] = (char*)malloc(sizeof(char) * mazeWidth)) == NULL) return 2;
    }
    for (int i = 0; i < mazeHeight; i++)
    {
        initializeMazeRow(maze[i],mazeWidth);
    }

    
    // Prime's algorithm
    srand(time(NULL));
    int y,x;
    y = rand() % mazeHeight;
    x = rand() % mazeWidth;
    maze[y][x] = ' ';
    Wall candidates[4];
    int candidateCount = 0;
    do
    {
       // find Candidates
       
        if (y < mazeHeight - 2 && maze[y + 1][x] != ' ')
        {
            candidates[candidateCount].x = x;
            candidates[candidateCount].y = y + 1;
            candidateCount ++;
        }
        if (y > 0 && maze[y - 1][x] != ' ' )
        {
            candidates[candidateCount].x = x;
            candidates[candidateCount].y = y - 1;
            candidateCount ++;
        }
        if (x < mazeWidth - 2 && maze[y][x + 1] != ' ')
        {
            candidates[candidateCount].x = x + 1;
            candidates[candidateCount].y = y;
            candidateCount ++;
        }
        if (x > 0 && maze[y][x - 1] != ' ' )
        {
            candidates[candidateCount].x = x - 1;
            candidates[candidateCount].y = y;
            candidateCount ++;
        }
        int randomWallIndex = rand() % candidateCount;
        Wall selctedWall = candidates[randomWallIndex];
        y = selctedWall.y;
        x = selctedWall.x;
        if (maze[y][x] == (char)254) {
            int adjX = (x % 2 == 0) ? x + 1 : x - 1;
            int adjY = (y % 2 == 0) ? y + 1 : y - 1;

            if (maze[adjY][adjX] == 0) {
                maze[y][x] = ' ';                
            }
        }
        candidates[randomWallIndex] = candidates[--candidateCount];
    }while(candidateCount > 0);
    


     for (int i = 0; i < mazeHeight; i++)
    {
        printMazeRow(maze[i],mazeWidth);
    }
    getch();
    getch();
    getch();
    return 0;
}