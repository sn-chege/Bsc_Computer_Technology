
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

using namespace std;

int x1, y1, x2, y2;

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


void LineBres(int x1, int y1, int x2, int y2)
{
	int dx = fabs(x2 - x1);
	int dy = fabs(y2 - y1);
	int twody = 2 * dy, twodyminusdx = 2 * (dy - dx); 
	int p = 2 * dy - dx; 
	int x, y;

	if (x1 > x2)
	{
		x = x2;
		y = y2;
		x2 = x1;
	}
	else
	{
		x = x1;
		y = y1;

	}
	draw_pixel(x, y);
	cout<<"x: " << x << "  y: "<< y<<endl;

	while (x < x2)
	{
		x++;
		if (p < 0)
			p += twody;
		else
		{
			y++;
			p += twodyminusdx;

		}

		draw_pixel(x, y);
		cout<<"x: " << x << "  y: "<< y<<endl;
	}


}


void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);

	LineBres(x1, y1, x2, y2);
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{

	printf(": Bresenhaim: Enter 2 points");
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

	glutInit(&argc, argv);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(200, 200);
	glutCreateWindow(".Line.");
	init();
	glutDisplayFunc(Display);
	glutMainLoop();
	return 0;
}
