#include <stdio.h>
#include <stdlib.h>
/*#include <time.h> 
#include <unistd.h>*/
#define EMPTY_SPACE '.'
#define OCCUPIED_SPACE 'o'
/*#define OBSTACLE_SPACE '#' 
#define EMPTY_SPACE ' ' 
#define TURTLE_SPACE 'z' */
typedef enum{
    left,up,right,down
}ROTATION;
typedef struct{
    int x;
    int y;
    ROTATION rotation;
}TURTLE;
void initializeCanvas(char *canvas, int rows, int cols);
void printCanvas(char *canvas, int rows, int cols/*, int turtleCount, TURTLE turtles[]*/); // int turtleCount,TURTLE turtles[] potreba pouze pro bonus
void rotateTrurtle(TURTLE *turtle, char direction);
void moveTurtle(TURTLE *turtle, int rows, int cols/*,char* canvas*/); //char* canvas potreba pouze pro bonus
int main()
{
    //srand(time(NULL)); // potreba pouze pro bonus
    int rows,cols;
    scanf("%d %d",&rows,&cols);
    char *canvas;
    if ((canvas = (char*)malloc(sizeof(char) * rows * cols)) == NULL)
    {
        return 1;
    }

    initializeCanvas(canvas,rows,cols); 
    int turtleCount = 1;
    TURTLE turtles[3];
    for (int i = 0; i < 3; i++)
    {
        turtles[i].x = 0;
        turtles[i].y = 0;
        turtles[i].rotation = right;
    }

    char instruction;
    
    while (scanf(" %c",&instruction) != EOF)
    {
        //printf("\x1b[2J\x1b[1;1F"); // Bonus: animace
        if (instruction == 'x')
        {
            break;
        }
        else if (instruction == 'f' && turtleCount < 3) turtleCount++;
        else if (instruction == 'o')
        {
            for (int i = 0; i < turtleCount; i++)
            {
               if (canvas[turtles[i].x * cols + turtles[i].y] == EMPTY_SPACE)
               {
                    canvas[turtles[i].x * cols + turtles[i].y] = OCCUPIED_SPACE;
               }
                else
                {
                    canvas[turtles[i].x * cols + turtles[i].y] = EMPTY_SPACE;
                }
            }
        }
        else if (instruction == 'm')
        {
            for (int i = 0; i < turtleCount; i++)
            {
                moveTurtle(&turtles[i],rows,cols/*,canvas*/); //canvas potreba pouze pro bonus

            }
        }
        else
        {
            for (int i = 0; i < turtleCount; i++)
            {
                rotateTrurtle(&turtles[i],instruction);
            }
        }
        //Bonus: animace
        /*printCanvas(canvas,rows,cols,turtleCount,turtles); 
        usleep(200 * 1000);*/
    }

    //Bonus, zde se program jen ukonci pred poslednim printem canvasu :)
    /*free(canvas);
    canvas = NULL;
    return 0;*/

    printCanvas(canvas,rows,cols/*,turtleCount, turtles*/); // turtleCount,turtles potreba pouze pro bonus

    free(canvas);
    canvas = NULL;
    return 0;
}
void initializeCanvas(char *canvas, int rows, int cols){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            //Bonus: pridavani prekazek, pro otestovani bonusu animace bez prekazek staci nechat toto zakomentovane :)
            /*int random;
            random=rand();
            if (rand() % 20 == 0)
            {
                canvas[i * cols + j] = OBSTACLE_SPACE;
                continue;
            }*/
            
            canvas[i * cols + j] = EMPTY_SPACE;
        }
    }
    
}
void printCanvas(char *canvas, int rows, int cols/*, int turtleCount, TURTLE turtles[]*/){ // int turtleCount, TURTLE turtles[] potreba pouze pro bonus
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {   
            //Bonus: print zelvicek
            /*for (int zelva = 0; zelva < turtleCount; zelva++)
            {
                if ((turtles[zelva].x * cols + turtles[zelva].y) == (i * cols + j))
                {
                    printf("%c",TURTLE_SPACE);
                }
                else printf("%c",canvas[i * cols + j]);
            }
            continue;*/
            
            printf("%c",canvas[i * cols + j]); 
        }
        printf("\n");
    }
}
void rotateTrurtle(TURTLE *turtle, char direction){
    switch(direction){
        case 'r' : 
            if (turtle -> rotation == down)
            {
                turtle -> rotation = left;
            }
            else 
            {
                turtle -> rotation ++;
            }
        break;
        case 'l' : 

            if (turtle -> rotation == left)
            {
                turtle -> rotation = down;
            }
            else 
            {
                turtle -> rotation --;
            }
        break;
    }
    
}
void moveTurtle(TURTLE *turtle, int rows, int cols/*, char* canvas*/){ //char* canvas potreba pouze pro bonus
    

    switch (turtle->rotation)
    {
    case left:
        //if ((turtle->y > 0 && canvas[turtle->x * cols + turtle->y - 1] == OBSTACLE_SPACE) || (turtle->y == 0 && canvas[turtle->x * cols + cols-1] == OBSTACLE_SPACE)) break; //Bonus: handling prekazek
        turtle->y == 0 ? turtle->y = cols - 1 : turtle->y--;
        break;
    case up:
        //if ((turtle->x > 0 && canvas[(turtle->x - 1) * cols + turtle->y] == OBSTACLE_SPACE) || (turtle->x == 0 && canvas[(rows-1) * cols + turtle->y] == OBSTACLE_SPACE)) break; //Bonus: handling prekazek
        turtle->x == 0 ? turtle->x = rows - 1 : turtle->x--;
        break;
    case right:
        //if ((turtle->y < cols-1 && canvas[turtle->x * cols + turtle->y + 1] == OBSTACLE_SPACE) || (turtle->y == cols-1 && canvas[turtle->x * cols] == OBSTACLE_SPACE)) break; //Bonus: handling prekazek
        turtle->y == cols - 1 ? turtle->y = 0 : turtle->y++;
        break;
    case down:
        //if ((turtle->x < rows-1 && canvas[(turtle->x + 1) * cols + turtle->y] == OBSTACLE_SPACE) || (turtle->x == rows-1 && canvas[turtle->y] == OBSTACLE_SPACE)) break; //Bonus: handling prekazek
        turtle->x == rows - 1 ? turtle->x = 0 : turtle->x++;
        break;
    }
}