#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "drawing.h"

void drawDashedLine(int length);
void (*getRandomColorFunction()) ();
void randomizeColor();
void cursorToBegginging(int offset);
void drawStairset(int count);
void drawBloom(int width);
void drawStamp(int flowerWidth, int flowerHeight);
void drawFlower(int width, int height);
void (*getRandomFlowerColor()) ();
void drawMeadow(int rows, int cols);
void drawAnimation();
void drawWhiteBackground();
void drawBomb();
void advanceSpark();

int main() {
    srand(time(NULL));
    clear_screen();

    int drawing = 0;
    scanf("%d", &drawing);
    switch (drawing)
    {
        case 0:
            int count = 10;
            int length = 10;
            for (int i = 1; i <= count; i++)
            {
                drawDashedLine(length);
                move_down();
                move_down();
                cursorToBegginging(length * 2);
            }     
        break;
        case 1:
            count = 3;
            int stairCount = 5;
            for (int i = 0; i < count; i++)
            {
                
                drawStairset(++stairCount);
                move_to((i + 1) * 5 , 1);
            }
        break;
        case 2:
            int width = 5;
            int height = 10;
            for (int i = 0; i < 5; i++)
            {
                drawFlower(width,++height);
                width += 2;
                move_to(2,(i+1) * (width + 2));
            }
        break;
        case 3: 
            drawMeadow(2,5);
        break;
        case 4: 
            drawAnimation();
        break;
    }
    end_drawing();
    return 0;
}




void drawDashedLine(int length){
    void (*colorFunction) () = getRandomColorFunction();
    colorFunction();
    for (int i = 0; i < length * 2; i++)
    {
        draw_pixel();
        i % 2 == 0 ? reset_color() : colorFunction();
        move_right();
    }
    reset_color();
}
void (*getRandomColorFunction()) (){
    int random = rand() % 5;
    switch (random)
    {
    case 0:
        return set_red_color;
        break;
    case 1:
        return set_yellow_color;
        break;
    case 2:
        return set_blue_color;
        break;    
    case 3:
        return set_green_color;
        break;
    case 4:
        return set_white_color;
        break;
    default: 
        return set_white_color;
        break;
    }
}
void (*getRandomFlowerColor()) (){
    int random = rand() % 3;
    switch (random)
    {
    case 0:
        return set_red_color;
        break;
    case 1:
        return set_white_color;
        break;
    case 2:
        return set_blue_color;
        break;    
    case 3:
        return set_yellow_color;
        break; 
    default: 
        return set_white_color;
        break;
    }
}
void randomizeColor(){
    void (*colorFunction) () = getRandomColorFunction();
    colorFunction();
}
void cursorToBegginging(int offset){
    for (int i = 0; i < offset; i++)
    {
        move_left();
    }
    
}
void drawStairset(int count){
    randomizeColor();
    int stairLength = 2;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < stairLength; j++)
        {
            move_right();
            draw_pixel();
            
        }
        move_down();
        if(i != count - 1) draw_pixel();
    }
}
void drawBloom(int width){
    void (*outerColorFunction) () = getRandomFlowerColor();
    outerColorFunction();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0)
            {
                if (j == 0 || j == width -1 || j == width/2)
                {
                    draw_pixel();
                    
                }
            }
            else if (i == 3)
            {
                if (j != 0 && j != width -1)
                {
                    draw_pixel();
                }
                
            }
            else
            {
                draw_pixel();
            }
            move_right();
        }
        move_down();
        cursorToBegginging(width);
    }
    
}
void drawStamp(int flowerWidth, int flowerHeight){
    set_green_color();
    int stampHeight = flowerHeight - 4;
    for (int i = 0; i < flowerWidth / 2; i++)
    {
        move_right();
    }
    
    for (int i = 0; i < stampHeight; i++)
    {
        if (i == stampHeight - 2)
        {
            move_left();
            draw_pixel();
            move_right();
            draw_pixel();
            move_right();
            draw_pixel();
            move_left();
        }
         if (i == stampHeight - 3)
        {
            move_left();
            move_left();
            draw_pixel();
            move_right();
            move_right();
            draw_pixel();
            move_right();
            move_right();
            draw_pixel();
            move_left();
            move_left();
        }
        
        draw_pixel();
        move_down();
    }
    
}
void drawFlower(int width, int height){
    drawBloom(width);
    drawStamp(width,height);   
}
void drawMeadow(int rows, int cols ){
    
    int currentHeight = 2;
    int currentWidth = 2;
    int Flowerwidth = 5;
    int Flowerheight = 10;
    for (int i = 0; i < rows; i++)
    {
        move_to(currentHeight,currentWidth);
        for (int j = 0; j < cols; j++)
        {
             drawFlower(Flowerwidth,Flowerheight);
             currentWidth += Flowerwidth + 1;
             move_to(currentHeight,currentWidth);
        }
        currentHeight += Flowerheight + 1;
        currentWidth = 2;
    }
    
}
void drawAnimation(){
    //background
    drawWhiteBackground();
    //bomb
    drawBomb();
    //first ignite
    animate();
    set_red_color();
    for (int i = 0; i < 2; i++)
    {
        move_left();
        draw_pixel();
    }
    //first spark
    animate();
    set_yellow_color();
    for (int i = 0; i < 2; i++)
    {
        move_left();
        draw_pixel();
    }
    move_down();
    move_right();
    move_right();
    for (int i = 0; i < 2; i++)
    {
        
        draw_pixel();
        move_right();
    }
    move_up();
    for (int i = 0; i < 2; i++)
    { 
        draw_pixel();
        move_right();
    }
    move_up();
    move_left();
    move_left();
    for (int i = 0; i < 2; i++)
    {
        move_left();
        draw_pixel();
    }
    animate();
    for (int i = 0; i < 4; i++) advanceSpark();
    clear_screen();
    drawWhiteBackground();
    move_to(1,1);
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            randomizeColor();
            draw_pixel();
            move_right();
        }
        move_to(i+1,1);
        move_down();
    }
    

}
void drawWhiteBackground(){
    set_white_color();
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            draw_pixel();
            move_right();
        }
        move_to(i+1,1);
    }
}
void drawBomb(){
    int startLine = 15;
    int startCol= 30;
    set_black_color();
    move_to(startLine,startCol);
    
    for (int i = 0; i < 10; i++)
    {
        draw_pixel();
        move_right();
    }
    
    move_down();
    for (int i = 0; i < 12; i++) move_left();
    for (int i = 0; i < 14; i++)
    {
        draw_pixel();
        move_right();
    }
    move_down();
    for (int i = 0; i < 16; i++) move_left();
    for (int i = 0; i < 18; i++)
    {
        draw_pixel();
        move_right();
    }
    move_down();
    for (int i = 0; i < 18; i++) move_left();
    for (int i = 0; i < 18; i++)
    {
        draw_pixel();
        move_right();
    }
    move_down();
     for (int i = 0; i < 18; i++) move_left();
    for (int i = 0; i < 18; i++)
    {
        draw_pixel();
        move_right();
    }
    move_down();
     for (int i = 0; i < 18; i++) move_left();
    for (int i = 0; i < 18; i++)
    {
        draw_pixel();
        move_right();
    }
    move_down();
    for (int i = 0; i < 16; i++) move_left();
    for (int i = 0; i < 14; i++)
    {
        draw_pixel();
        move_right();
    }
    move_down();
    for (int i = 0; i < 12; i++) move_left();
    for (int i = 0; i < 10; i++)
    {
        draw_pixel();
        move_right();
    }
    //fuse
    move_to(startLine - 1,startCol + 6);
    for (int i = 0; i < 2; i++)
    {
        draw_pixel();
        move_right();
    }
    move_up();
    for (int i = 0; i < 2; i++)
    {
        draw_pixel();
        move_right();
    }
    move_up();
    for (int i = 0; i < 2; i++)
    {
        draw_pixel();
        move_right();
    }
     move_up();
    for (int i = 0; i < 2; i++)
    {
        draw_pixel();
        move_right();
    }
}
void advanceSpark(){
        set_white_color();
    for (int i = 0; i < 2; i++)
    { 
        draw_pixel();
        move_right();
    }
    move_down();
    move_left();
    move_left();
    set_white_color();
    for (int i = 0; i < 4; i++)
    { 
        draw_pixel();
        move_right();
    }
    set_white_color();
    for (int i = 0; i < 4; i++)
    { 
        draw_pixel();
        move_right();
    }
    move_down();
    for (int i = 0; i < 10; i++) move_left();
    set_red_color();
    for (int i = 0; i < 2; i++)
    { 
        draw_pixel();
        move_right();
    }
    move_down();
    set_yellow_color();
    for (int i = 0; i < 2; i++)
    {
        move_left();
        draw_pixel();
    }
    move_up();
    for (int i = 0; i < 2; i++) move_left();
    for (int i = 0; i < 2; i++)
    {
        draw_pixel();
        move_right();
    }
    move_up();
    animate();
}