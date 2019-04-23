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
	glClearColor(1, 1, 1, 1);
	glColor3f(0.5, 0.4, 0.3);

	glBegin(GL_POLYGON);

	glVertex3f(0.0, 1.0, 0.0); glVertex3f(-1.0, 0.5, 0.0);
	glVertex3f(-1.0, -0.5, 0.0); glVertex3f(0.0, -1.0, 0.0);
	glVertex3f(1.0, -0.5, 0.0); glVertex3f(1.0, 0.5, 0.0);

	glEnd();
	glFlush();
}

void vertexArrayModeling()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glClearColor(1, 1, 1, 1);
	GLfloat MyVertices[8][3] = { {-0.25,-0.25,0.25},{-0.25,0.25, 0.25}, {0.25,0.25,0.25},
								{0.25,-0.25,0.25},{-0.25,-0.25, -0.25}, {-0.25,0.25,-0.25},
								{0.25,0.25,-0.25},{0.25,-0.25, -0.25} };
	GLfloat MyColors[8][3] = { {0.2,0.2,0.2},{1.0,0.0,0.0},{1.0,1.0,0.2},{0.0,1.0,0.0},
							   {0.0,0.0,1.0} ,{1.0,0.0,1.0} ,{1.0,1.0,1.0} ,{0.0,1.0,1.0} };

	GLubyte MyVertexList[24] = { 0,3,2,1, 2,3,7,6, 0,4,7,3, 1,2,6,5, 4,5,6,7, 0,1,5,4 };


	glFrontFace(GL_CCW);
	glEnable(GL_CULL_FACE);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, MyColors);
	glVertexPointer(3, GL_FLOAT, 0, MyVertices);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glRotatef(30.0, 1.0, 1.0, 1.0);
	for (GLint i = 0; i < 6; i++)
		glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, &MyVertexList[4 * i]);

	glFlush();
}

void Mylnit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-0.1, 1.0, -1.0, 1.0, -1.0, 1.0);
}


int main(int arg, char **argv)
{
	glutInit(&arg, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Hello World!!!");
	//Mylnit();
	glutDisplayFunc(vertexArrayModeling);


	glutMainLoop();


	return 0;

}