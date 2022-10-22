#include <stdio.h>
#include <GL/glut.h>

int x = 50, y = 50;
bool isBrown = true;

void whiteBox(int x, int y)
{
	glBegin(GL_LINE_LOOP);
	glVertex2i(x, y);
	glVertex2i(x, y + 50);
	glVertex2i(x + 50, y + 50);
	glVertex2i(x + 50, y);
	glEnd();
}

void brownBox(int x, int y)
{
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.35f, 0.05f);  
	glVertex2i(x, y);
	glVertex2i(x, y + 50);
	glVertex2i(x + 50, y + 50);
	glVertex2i(x + 50, y);
	glEnd();
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);

	for (int i = 0; i < 8; i++)
	{
		if (i % 2 == 0)
		{
			isBrown = true;
		}
		else
		{
			isBrown = false;
		}

		for (int j = 0; j < 8; j++)
		{
			if (isBrown)
			{
				brownBox(x, y);
				isBrown = false;
			}
			else
			{
				whiteBox(x, y);
				isBrown = true;
			}
			x += 50;
		}
		y += 50;
		x = 50;
	}

	brownBox(100, 100);
	whiteBox(150, 100);
	glFlush();
}


void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("8 x 8 brown Chess Board");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;
}