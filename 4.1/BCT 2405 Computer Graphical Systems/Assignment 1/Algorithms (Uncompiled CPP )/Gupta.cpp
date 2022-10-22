
// Guptasprawl Line Drawing
#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#include <cmath>
#include <ctgmath>

using namespace std;

int xstart, ystart, xend, yend;

void init()
{
	glOrtho(0, 50, 0, 50,-1,1);
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
   int addr = (ystart*640+xstart)*4;
 int dx = xend-xstart;
 int dy = yend-ystart;
 int du,dv,u,v,uincr,vincr;
 /* By switching to (u,v), we combine all eight octants */
 if (abs(dx) > abs(dy))
 {

 du = abs(dx);
 dv = abs(dy);
 u = xend;
 v = yend;
 uincr = 4;
 vincr = 640*4;
if (dx < 0) uincr = -uincr;
if (dy < 0) vincr = -vincr;
 }
 else
 {
 du = abs(dy);
 dv = abs(dx);
 u = yend;
 v = xend;
 uincr = 640*4;
 vincr = 4;
if (dy < 0) uincr = -uincr;
if (dx < 0) vincr = -vincr;
 }

 int uend = u + 2 * du;
 int d = (2 * dv) - du;
 int incrS = 2 * dv;
 int incrD = 2 * (dv - du);
 int twovdu = 0;
 double invD = 1.0 / (2.0*sqrt(du*du + dv*dv));
 double invD2du = 2.0 * (du*invD);
 do
 {

draw_pixel(addr, twovdu*invD);
draw_pixel(addr + vincr, invD2du - twovdu*invD);
draw_pixel(addr - vincr, invD2du + twovdu*invD);
if (d < 0)
{

 twovdu = d + du;
 d = d + incrS;
}
else
{

 twovdu = d - du;
 d = d + incrD;
 v = v+1;
 addr = addr + vincr;
}
u = u+1;
addr = addr+uincr;
 } while (u < uend);

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

	printf("Enter 2 points");
	scanf("%d%d%d%d", &xstart, &ystart, &xend, &yend);
	

	glutInit(&argc, argv);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(200, 200);
	glutCreateWindow(".Line.");
	init();
	glutDisplayFunc(Display);
	glutMainLoop();
	return 0;
}
