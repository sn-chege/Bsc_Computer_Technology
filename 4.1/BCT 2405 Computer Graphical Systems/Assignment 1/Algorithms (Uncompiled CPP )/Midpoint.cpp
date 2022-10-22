
// Midpoint Line Drawing
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

using namespace std;

int xstart, ystart, xend, yend;

void init()
{
	glOrtho(0, 100, 0, 100,-1,1);
}



void draw_pixel(int x, int y)
{
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}


void LineBres(int xstart, int ystart, int xend, int yend)
{
    int dx;
    int dy;
    int x,y;

    int dParameter; //decision parameter
    int changeInD;

     x = xstart;
     y = ystart;

    draw_pixel(x,y);
    cout<<"x: " << x << "  y: "<< y<<endl;
   
    dx= xend - xstart;
    dy = yend - ystart;

 
    dParameter = 2 * (dy) - dx;
    changeInD = 2 * (dy - dx);

    while( x < xend){
        x++;
        if(dParameter < 0){
            dParameter = dParameter + (2 * (dy));
        }
        else{
            y += 1;
            dParameter = dParameter + changeInD;
        }
    draw_pixel(x,y);
    cout<<"x: " << x << "  y: "<< y<<endl;
}
}


void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);

	LineBres(xstart, ystart, xend, yend);
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{

	printf("MidPoint.");
	scanf("%d%d%d%d", &xstart, &ystart, &xend, &yend);
	
	glutInit(&argc, argv);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(400, 400);
	glutCreateWindow(".Line.");
	init();
	glutDisplayFunc(Display);
	glutMainLoop();
	return 0;
}
