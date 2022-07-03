#include <stdio.h>
#include <graphics.h>
#include <dos.h>

void boundaryFill(int x, int y, int f_color, int b_color)
{
    if (getpixel(x,y)!=b_color && get_pixel(x,y)!=f_color)
    {
        putpixel(x,y,f_color);
        boundaryFill(x+1,y,f_color,b_color);
        boundaryFill(x,y+1,f_color,b_color);
        boundaryFill(x-1,y,f_color,b_color);
        boundaryFill(x,y-1,f_color,b_color);

    }
    
}

int main (int argc, char *argv[]) {
    int gm,gd=DETECT,radius;
    int x,y;
    printf("Enter x and y positions for circle\n");
    scanf("%d %d",&x,&y);
    printf("Enter radius of circle\n");
    scanf("%d",&radius);
    initgraph(&gd,&gm,"");
    circle(x,y,radius);
    rectangle(100,100,200,200);
    printf("Enter the values x and y: \n");
    scanf("%d %d",&x,&y);
    boundaryFill(x,y,4,15);
    delay(50000);
    closegraph();
    return 0;
}
