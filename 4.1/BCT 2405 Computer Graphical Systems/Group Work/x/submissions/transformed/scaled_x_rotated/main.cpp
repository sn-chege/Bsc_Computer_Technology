#include <stdio.h>
#include <GL/glut.h>

int x = 50, y = 50;
bool isBrown = true;

double scale_x = 0.5, scale_y = 0.5;
double translate_x = 500,translate_y = -500;
GLfloat angle = 60.0;

void myInit(void);

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
	//set fill color to brown
	glColor3f(0.5f, 0.35f, 0.05f);  
	glVertex2i(x, y);
	glVertex2i(x, y + 50);
	glVertex2i(x + 50, y + 50);
	glVertex2i(x + 50, y);
	glEnd();
}

void myDisplay(void)
{	
	//Clear any buffers (specify flag in parameter) 
    // *** A buffer is an area in memory that displays/corresponds to a pixel on the screen
	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(1.0);

	//Nested for loop - to draw the tiles
	//Outer loop draws cells horizontally
	
	for (int i = 0; i < 8; i++)
	{
		//If index of current tile is even number, draw brown tile 
		if (i % 2 == 0)
		{
			isBrown = true;
		}
		else
		{
			isBrown = false;
		}

		//Inner loop draws cells vertically
		for (int j = 0; j < 8; j++)
		{
			if (isBrown)
			{
				glScalef(scale_x,scale_y,0);
				glRotatef(angle, 0.0f, 0.0f, 1.0f);
				glTranslatef(translate_x,translate_y,0);
				brownBox(x, y);
				myInit(); //Reset
				isBrown = false;
			}
			else
			{
				glScalef(scale_x,scale_y,0);
				glRotatef(angle, 0.0f, 0.0f, 1.0f);
				glTranslatef(translate_x,translate_y,0);
				whiteBox(x, y);
				myInit();//Reset
				isBrown = true;
			}
			x += 50;
		}
		y += 50;
		x = 50;
	}
 
	glFlush();
}


void myInit(void)
{
	//Clear window bg to clear
	//Pass intensities of RGB ranging from 0 to 1 (eg 0.5). Hint: 0-black, 1-white
	glClearColor(1.0, 1.0, 1.0, 0.0);
	//Set vertex color.
	glColor3f(0.5f, 0.35f, 0.05f);
	//Set Point size
	glPointSize(4.0);
	//Set projection mode
	glMatrixMode(GL_PROJECTION);
	 //Reset any transformations carried out earlier 
	glLoadIdentity();
	//New Projection
	gluOrtho2D(0.0, 640.0, 0.0, 480.0); //L,R,B,T
}

int main(int argc, char** argv)
{
	//Intialize glut library
	glutInit(&argc, argv);

	//Initialize Display Mode
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    //Initialize window	
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);

	//Create Window
	glutCreateWindow("8 x 8 brown Chess Board");

	//Display Callback
	glutDisplayFunc(myDisplay);

	//Init
	myInit();

	//keep program running
	glutMainLoop();
	
	return 0;
}			