#include <iostream>
#include <math.h>

#include <gl/freeglut.h>
//#include <gl/GLU.h>
using namespace std;
const int Pi = 3.14;
void d()
{
	GLfloat Size[2], Angle;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	glGetFloatv(GL_POINT_SIZE_RANGE, Size);
	glPointSize(Size[0] * 3);
	glBegin(GL_POINTS);
	for (Angle = 0.0; Angle <= 2.1*Pi; Angle += Pi / 20.0)
		glVertex3f(0.5*cos(Angle), 0.5*sin(Angle), 0.0);

	glEnd();
	glFlush();
}

void polygon()
{
	//glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1,1,1,1);
	glColor3f(0.5, 0.4, 0.3);

	glBegin(GL_POLYGON);

	glVertex3f(0.0, 1.0, 0.0); glVertex3f(-1.0, 0.5, 0.0);
	glVertex3f(-1.0, -0.5, 0.0); glVertex3f(0.0, -1.0, 0.0);
	glVertex3f(1.0, -0.5, 0.0); glVertex3f(1.0, 0.5, 0.0);

	glEnd();
	glFlush();
}

int main(int arg, char **argv)
{
	glutInit(&arg, argv);

	int width, hieght;
	width = 600;
	hieght = 600;
	glutInitWindowSize(width, hieght);

	glutCreateWindow("Hello World!!!");
	glutDisplayFunc(polygon);


	glutMainLoop();


	return 0;

}