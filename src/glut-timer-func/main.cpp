/**
 * This demo shows how to periodically call an update() function to create
 * animations over time. In this case, the animation is to rotate a red square.
 *
 * Author: Fernando Bevilacqua <fernando.bevilacqua@uffs.edu.br>
 * License: MIT
 */

#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>

// Constants to define the width/height of the window
const int WIDTH = 800;
const int HEIGHT = 800;

// Define how many frames per seconds we want our
// applications to run.
const unsigned int FRAMES_PER_SECOND = 1000;
const unsigned int UPDATE_INTERVAL_MS = 1000 / FRAMES_PER_SECOND;

// Control the angle to rotate the red square
float angleX = 0;
float angleY = 0;
float x = 0;
float y = 0;
float z = 0;
bool girarX = 0;
bool girarY = 0;

void renderCoordinateAxis()
{
	// X axis - green color
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
		// Left side, negative X
		glVertex2f(-10.0, 0.0);
		glVertex2f(0.0, 0.0);

		// Right side, positive X
		glVertex2f(0.0, 0.0);
		glVertex2f(10.0, 0.0);
	glEnd();

	// Y axis - blue color
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
		// Top side, positive Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 10.0);

		// Bottom side, negative Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, -10.0);
	glEnd();
}

void renderMyCubePlease(){

	glTranslatef(x,y,z);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glRotatef(angleY, 0.0, 1.0, 0.0);

	// glRotatef(angle, 0.0f, 1.0f, 0.0f);

	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f(1.0, -1.0, -1.0);
		
		glVertex3f(-1.0, 1.0, -1.0);
		glVertex3f(1.0, 1.0, -1.0);

		glVertex3f(-1.0, 1.0, -1.0);
		glVertex3f(-1.0, -1.0, -1.0);
		
		glVertex3f(1.0, 1.0, -1.0);
		glVertex3f(1.0, -1.0, -1.0);
	glEnd();


	glBegin(GL_LINES);
		glVertex3f(-1.0, -1.0, 1.0);
		glVertex3f(1.0, -1.0, 1.0);
		
		glVertex3f(-1.0, 1.0, 1.0);
		glVertex3f(1.0, 1.0, 1.0);

		glVertex3f(-1.0, 1.0, 1.0);
		glVertex3f(-1.0, -1.0, 1.0);
		
		glVertex3f(1.0, 1.0, 1.0);
		glVertex3f(1.0, -1.0, 1.0);
	glEnd();

	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
		glVertex3f(1.0, -1.0, -1.0);
		glVertex3f(1.0, -1.0, 1.0);
		
		glVertex3f(1.0, 1.0, -1.0);
		glVertex3f(1.0, 1.0, 1.0);

		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f(-1.0, -1.0, 1.0);
		
		glVertex3f(-1.0, 1.0, -1.0);
		glVertex3f(-1.0, 1.0, 1.0);
	glEnd();

}

void display3009()
{
	// Clear the screen painting it with the white color
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	// Inform we want to make changes to the modelview matrix, starting
	// with no transformation at all.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Move the camera away from the origin along the Z axis by 10 pixels.
	glTranslatef(0, 0, -10.0f);

	// Render the X and Y axis to guide ourselves.
	// renderCoordinateAxis();

	// Rotate the red square by "angle" degrees.
	// glRotatef(angle, 0.0f, 0.0f, 1.0f);
	// glRotatef(angle, 0.0f, 1.0f, 0.0f);
	
	// Render a red square
	//        R  G  B
	// glColor3f(0, 0, 1);
	//        x1    y1    x2     y2
	// glRectf(-1.0f, 1.0f, 1.0f, -1.0f);
	// glRectf(-1.0f, 1.0f, 1.0f, -1.0f);

	// glutWireCube(2.0);
	// glutWireTeapot(2.0);

	renderMyCubePlease();

	// Start the rendering on a new frame
	glutSwapBuffers();
}

float angle;

void renderMyTowerPlease(){
	glPushMatrix();
	
	// glRotatef(angleX, 1.0, 0.0, 0.0);
	// glRotatef(angleY, 0.0, 1.0, 0.0);

	// glRotatef(90, 0.0f, 1.0f, 0.0f);

	// angle = 90.0;

	//base
	glPushMatrix();
	glColor3f(0, 0, 1);
	glTranslatef(0,-1.1,0);
	glScaled(2,0.2,2.0);
	glutWireCube(1.0);	
	glPopMatrix();

	//corpo
	glPushMatrix();
	glColor3f(0, 0, 1);	
	glScaled(1.5,2.0,1.5);
	glutWireCube(1.0);	
	glPopMatrix();

	//superior
	glPushMatrix();
	glColor3f(0, 0, 1);
	glTranslatef(-0.55,1.25,-0.55);
	glutWireCube(.40);	
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 1);
	glTranslatef(0.55,1.25,0.55);
	glutWireCube(.40);	
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 1);
	glTranslatef(-0.55,1.25,0.55);
	glutWireCube(.40);	
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 1);
	glTranslatef(0.55,1.25,-0.55);
	glutWireCube(.40);	
	glPopMatrix();

	// glColor3f(1, 0, 0);

	// glTranslatef(3,-3,-3);
	// glutWireCube(0.5);

	glPopMatrix();
}



void display0710(){
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, -10.0f);


	// Render the X and Y axis to guide ourselves.
	renderCoordinateAxis();

	// Rotate the red square by "angle" degrees.
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	glRotatef(angle, 0.0f, 1.0f, 0.0f);
	
	// Render a red square
	//        R  G  B
	
	//        x1    y1    x2     y2
	// glRectf(-1.0f, 1.0f, 1.0f, -1.0f);
	// glRectf(-1.0f, 1.0f, 1.0f, -1.0f);

	
	glTranslatef(-4,0,0);
	renderMyTowerPlease();

	
	glTranslatef(6,0,0);
	renderMyTowerPlease();

	glTranslatef(4,0,0);
	renderMyTowerPlease();

	glutSwapBuffers();
}

void update(int value)
{
	// Update the angle of rotation
	if(girarX){
		angleX += 3;
		angle += 0.50;
	}

	if(girarY)
		angleY += 3;

	// if(ax)
	// 	x += 3;
	
	// if(ay)
	// 	y += 3;

	// if(az)
	// 	z += 3;

	// Request a new frame rendering
	glutPostRedisplay();

	// Re-schedule the update() function to be called after a few
	// milliseconds again.
	glutTimerFunc(UPDATE_INTERVAL_MS, update, 0);
}

void keyboard(unsigned char key, int xx, int yy)
{
	if (key == 27) {
		// ESC key
		exit(0);
	}else if(key == 'a'){
		x -= 0.1;
	}else if(key == 's'){
		y -= 0.1;
	}else if(key == 'd'){
		x += 0.1;
	}else if(key == 'w'){
		y += 0.1;
	}else if(key == 'q'){
		girarX = !girarX;
	}else if(key == 'e'){
		girarY = !girarY;
	};
}

void mouse(int button, int state, int x, int y)
{
	std::cout << "Mouse pressed: button=" << button << ", state=" << state << ", x=" << x << " y=" << y << std::endl;
}

void initView()
{
	// We want a window to the world that is a rectangle starting at (0,0)
	// and ending at (WIDTH, HEIGHT).
	glViewport(0, 0, (GLsizei)WIDTH, (GLsizei)HEIGHT);
	
	// Adjust the global projection (camera)
	glMatrixMode(GL_PROJECTION);
	
	// Reset any existing projection settings and adjust the field-of-view (FOV)
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 200.0);
	
	// From now on, every transformation is to be applied on each object, e.g. modelview.
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Transformation - Simple");
	glutDisplayFunc(display0710);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);

	initView();

	// Schedule the update() function to be called after a few
	// milliseconds (calculated as 1000 milliseconds divided by FPS).
	glutTimerFunc(UPDATE_INTERVAL_MS, update, 0);

	glutMainLoop();
	return 0;
}