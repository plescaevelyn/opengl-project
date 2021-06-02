#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <cstdlib>

#define PI 3.1415926535898

static int click1 = 1;
static int click2 = 1;
static GLfloat param = -17.0;
static GLfloat valvestate = 0.0;
static GLfloat pipeflow = 0.0;

void init(void)
{
	glClearColor(1.0, 0.65, 0.65, 0.0);
	glShadeModel(GL_FLAT);
}

//drawing the evaporator
void evaporator() {
	glBegin(GL_POLYGON);

	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(-85.0, -90.0);
	glVertex2f(-85.0, -30.0);
	glVertex2f(-80.0, -30.0);
	glVertex2f(-80.0, -90.0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glVertex2f(-80.0, -90.0);
	glVertex2f(-80.0, -30.0);
	glVertex2f(-75.0, -30.0);
	glVertex2f(-75.0, -90.0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(-75.0, -90.0);
	glVertex2f(-75.0, -30.0);
	glVertex2f(-70.0, -30.0);
	glVertex2f(-70.0, -90.0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glVertex2f(-70.0, -90.0);
	glVertex2f(-70.0, -30.0);
	glVertex2f(-65.0, -30.0);
	glVertex2f(-65.0, -90.0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(-65.0, -90.0);
	glVertex2f(-65.0, -30.0);
	glVertex2f(-60.0, -30.0);
	glVertex2f(-60.0, -90.0);
	glEnd();
	glFlush();

	glEnd();
	glFlush();
}

//drawing the compressor
void compressor() {
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(+20.0, +20.0);
	glVertex2f(+50.0, +10.0);
	glVertex2f(+50.0, -10.0);
	glVertex2f(+20.0, -20.0);
	glEnd();
	glFlush();
}

//drawing the knockout drum
void knockoutDrum() {
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	
	glBegin(GL_LINES);
	glVertex2f(+67.0, +20);
	glVertex2f(+85.0, +20);
	glFlush();
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex2f(+65.0, -20.0);
	glVertex2f(+65.0, +20.0);
	glVertex2f(+67.0, +20.0);
	glVertex2f(+67.0, -20.0);
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON);
	glVertex2f(+85.0, -20.0);
	glVertex2f(+85.0, +20.0);
	glVertex2f(+87.0, +20.0);
	glVertex2f(+87.0, -20.0);
	glEnd();
	glFlush();
	
	glBegin(GL_POLYGON);
	glVertex2f(+65.0, -20.0);
	glVertex2f(+65.0, -17.0);
	glVertex2f(+87.0, -17.0);
	glVertex2f(+87.0, -20.0);
	glEnd();
	glFlush();
	
	glEnd();
	glFlush();
}

//drawing magnetic flow meter
void magneticFlowMeter() {
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(+5.0, +10.0);
	glVertex2f(-5.0, +10.0);
	glVertex2f(-5.0, -10.0);
	glVertex2f(+5.0, -10.0);
	glEnd();
	glFlush();
}

void controlValve() {  //drawing the start button (opens and closes the control valve)
	if (valvestate) {
		glBegin(GL_POLYGON);

		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_TRIANGLES);
		glVertex2f(-10.0, +70.0);
		glVertex2f(-10.0, +50.0);
		glVertex2f(+0.0, +60.0);
		glEnd();
		glFlush();

		glBegin(GL_TRIANGLES);
		glVertex2f(+10.0, +70.0);
		glVertex2f(+10.0, +50.0);
		glVertex2f(+0.0f, +60.0f);
		glEnd();
		glFlush();

		glEnd();
		glFlush();
	}
	else {
		glBegin(GL_POLYGON);
		glColor3f(1.0, 0.0, 0.0);

		glBegin(GL_TRIANGLES);
		glVertex2f(-10.0, +70.0);
		glVertex2f(-10.0, +50.0);
		glVertex2f(+0.0, +60.0);
		glEnd();
		glFlush();

		glBegin(GL_TRIANGLES);
		glVertex2f(+10.0, +70.0);
		glVertex2f(+10.0, +50.0);
		glVertex2f(+0.0f, +60.0f);
		glEnd();
		glFlush();

		glEnd();
		glFlush();
	}
}

void line() { //drawing the lines of the circuit
	//the pipe that goes from the evaporator to the compressor
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-74.0, -30.0);
	glVertex2f(-74.0, -24.0);
	glVertex2f(-74.0, -24.0);
	glVertex2f(+34.0, -24.0);
	glVertex2f(+34.0, -24.0);
	glVertex2f(+34.0, -15.0);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-76.0, -30.0);
	glVertex2f(-76.0, -26.0);
	glVertex2f(-76.0, -26.0);
	glVertex2f(+36.0, -26.0);
	glVertex2f(+36.0, -26.0);
	glVertex2f(+36.0, -15.0);
	glEnd();
	glFlush();

	//the pipe that goes from the evaporator between the line connected to the compressor and the knockout drum
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-74.0, -25.0);
	glVertex2f(-74.0, +39.0);
	glVertex2f(-74.0, +39.0);
	glVertex2f(+34.0, +39.0);
	glVertex2f(+34.0, +39.0);
	glVertex2f(+34.0, +16.0);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-76.0, -25.0);
	glVertex2f(-76.0, +41.0);
	glVertex2f(-76.0, +41.0);
	glVertex2f(+36.0, +41.0);
	glVertex2f(+36.0, +41.0);
	glVertex2f(+36.0, +14.0);
	glEnd();
	glFlush();

	//the pipe that connects to compressor and the knockout drum
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(+50.0, -1.0);
	glVertex2f(+65.0, -1.0);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(+50.0, +1.0);
	glVertex2f(+65.0, +1.0);
	glEnd();
	glFlush();

	//the pipe that connects the compressor and the magnetic flow meter
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(+5.0, -1.0);
	glVertex2f(+20.0, -1.0);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(+5.0, +1.0);
	glVertex2f(+20.0, +1.0);
	glEnd();
	glFlush();

	//the pipe that connects the line to the control valve
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(+0.0, +40.0);
	glVertex2f(+0.0, +60.0);
	glEnd();
	glFlush();
}

void substance() {
	if (pipeflow) {
		glColor3f(0.0, pipeflow, 0.0);
		glBegin(GL_POLYGON);

		glBegin(GL_POLYGON);
		glVertex2f(+50.0, -1.0);
		glVertex2f(+65.0, -1.0);
		glVertex2f(+65.0, +1.0);
		glVertex2f(+50.0, +1.0);
		glEnd();
		glFlush();

		glBegin(GL_POLYGON);
		glVertex2f(-74.0, -30.0);
		glVertex2f(-74.0, -25.0);
		glVertex2f(-76.0, -25.0);
		glVertex2f(-76.0, -30.0);
		glEnd();
		glFlush();

		glBegin(GL_POLYGON);
		glVertex2f(-74.0, -25.0);
		glVertex2f(-74.0, +40.0);
		glVertex2f(-76.0, +40.0);
		glVertex2f(-76.0, -25.0);
		glEnd();
		glFlush();

		glBegin(GL_POLYGON);
		glVertex2f(-76.0, +39.0);
		glVertex2f(-76.0, +41.0);
		glVertex2f(+36.0, +41.0);
		glVertex2f(+34.0, +39.0);
		glEnd();
		glFlush();

		glBegin(GL_POLYGON);
		glVertex2f(+36.0, +41.0);
		glVertex2f(+34.0, +39.0);
		glVertex2f(+34.0, +16.0);
		glVertex2f(+36.0, +14.0);
		glEnd();
		glFlush();

		glBegin(GL_POLYGON);
		glVertex2f(-74.0, -24.0);
		glVertex2f(-74.0, -26.0);
		glVertex2f(+36.0, -26.0);
		glVertex2f(+36.0, -24.0);
		glEnd();
		glFlush();

		glBegin(GL_POLYGON);
		glVertex2f(+34.0, -26.0);
		glVertex2f(+34.0, -16.0);
		glVertex2f(+36.0, -14.0);
		glVertex2f(+36.0, -26.0);
		glEnd();
		glFlush();

		glEnd();
		glFlush();
	}
	else {
		glBegin(GL_POLYGON);
		glColor3f(1.0, 0.0, 0.0);

		glBegin(GL_POLYGON);
		glVertex2f(-0.0, +39.0);
		glVertex2f(-0.0, +41.0);
		glVertex2f(+36.0, +41.0);
		glVertex2f(+34.0, +39.0);
		glEnd();
		glFlush();

		glBegin(GL_POLYGON);
		glVertex2f(+36.0, +41.0);
		glVertex2f(+34.0, +39.0);
		glVertex2f(+34.0, +16.0);
		glVertex2f(+36.0, +14.0);
		glEnd();
		glFlush();

		glBegin(GL_POLYGON);
		glVertex2f(-74.0, -30.0);
		glVertex2f(-74.0, -25.0);
		glVertex2f(-76.0, -25.0);
		glVertex2f(-76.0, -30.0);
		glEnd();
		glFlush();

		glBegin(GL_POLYGON);
		glVertex2f(-76.0, -24.0);
		glVertex2f(-76.0, -26.0);
		glVertex2f(+36.0, -26.0);
		glVertex2f(+36.0, -24.0);
		glEnd();
		glFlush();

		glBegin(GL_POLYGON);
		glVertex2f(+34.0, -26.0);
		glVertex2f(+34.0, -16.0);
		glVertex2f(+36.0, -14.0);
		glVertex2f(+36.0, -26.0);
		glEnd();
		glFlush();

		glEnd();
		glFlush();
	}
}

void knockoutDrumSubstance() {
	glColor3f(0.0, 0.65, 0.65);

	glRectf(+67, param, +85, -17);
}

void fillDisplay() {
	if (param < 20.0)
		param += 0.05;
	glutPostRedisplay();
}

void fillDisplay2() {
	if (param > -17.0)
		param -= 0.05;
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			valvestate = 0;
			pipeflow = 0;
			glutPostRedisplay();
			click1 = 0;
			glutIdleFunc(fillDisplay2);
			click2 = 1;
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_UP)
		{
			valvestate = 1;
			pipeflow = 1;
			glutPostRedisplay();
			click2 = 1;
			glutIdleFunc(fillDisplay);
			click1 = 0;
		}
		break;
	case GLUT_MIDDLE_BUTTON:
		if (state == GLUT_UP)
			glutIdleFunc(NULL);
		break;
	default:
		break;
	}
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT); //deletes all the pixels
	glMatrixMode(GL_MODELVIEW); //initializes the point of view
	glPushMatrix(); //beginning the rototranslation movement

	glTranslatef(-0.4, 0.0, 0.0); //translation
	glTranslatef(0.4, -0.0, -0.0);

	evaporator();
	controlValve();
	compressor();
	knockoutDrum();
	magneticFlowMeter();
	line();
	substance();
	knockoutDrumSubstance();

	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0); //our coordinate system
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000, 500);
	glutInitWindowPosition(150, 100);
	glutCreateWindow("P&ID");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}