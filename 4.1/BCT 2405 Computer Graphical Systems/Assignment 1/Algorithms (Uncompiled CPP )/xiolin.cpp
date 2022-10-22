// xiolin Line Drawing
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


void LineBres(int xstart, int ystart, int xend, int yend ,
                const function<void(int x, int y, float brightess)>& plot)
{auto ipart = [](float x) -> int {return int(std::floor(x));};
    auto round = [](float x) -> float {return std::round(x);};
    auto fpart = [](float x) -> float {return x - std::floor(x);};
    auto rfpart = [=](float x) -> float {return 1 - fpart(x);};

    const bool steep = abs(y1 - y0) > abs(x1 - x0);
    if (steep) {
        std::swap(x0,y0);
        std::swap(x1,y1);
    }
    if (x0 > x1) {
        std::swap(x0,x1);
        std::swap(y0,y1);
    }

    const float dx = x1 - x0;
    const float dy = y1 - y0;
    const float gradient = (dx == 0) ? 1 : dy/dx;

    int xpx11;
    float intery;
    {
        const float xend = round(x0);
        const float yend = y0 + gradient * (xend - x0);
        const float xgap = rfpart(x0 + 0.5);
        xpx11 = int(xend);
        const int ypx11 = ipart(yend);
        if (steep) {
            plot(ypx11,     xpx11, rfpart(yend) * xgap);
            plot(ypx11 + 1, xpx11,  fpart(yend) * xgap);
        } else {
            plot(xpx11, ypx11,    rfpart(yend) * xgap);
            plot(xpx11, ypx11 + 1, fpart(yend) * xgap);
        }
        intery = yend + gradient;
    }

    int xpx12;
    {
        const float xend = round(x1);
        const float yend = y1 + gradient * (xend - x1);
        const float xgap = rfpart(x1 + 0.5);
        xpx12 = int(xend);
        const int ypx12 = ipart(yend);
        if (steep) {
            plot(ypx12,     xpx12, rfpart(yend) * xgap);
            plot(ypx12 + 1, xpx12,  fpart(yend) * xgap);
        } else {
            plot(xpx12, ypx12,    rfpart(yend) * xgap);
            plot(xpx12, ypx12 + 1, fpart(yend) * xgap);
        }
    }

    if (steep) {
        for (int x = xpx11 + 1; x < xpx12; x++) {
            plot(ipart(intery),     x, rfpart(intery));
            plot(ipart(intery) + 1, x,  fpart(intery));
            intery += gradient;
        }
    } else {
        for (int x = xpx11 + 1; x < xpx12; x++) {
            plot(x, ipart(intery),     rfpart(intery));
            plot(x, ipart(intery) + 1,  fpart(intery));
            intery += gradient;
        }
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
