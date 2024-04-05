#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<iostream>
#include<stdio.h>


int wingRotateAngle = 0;
int birdPosition = 0;
int birdFlyDist = 0;
int btnState = 0;
#define M_PI 3.14159265358979323846
int choice;

int introState = 0;
int gameOver = 0;
int level = 1;


int pipeSpawn[3] = { 300,500,700 };
int translatePipePos[3] = { 100,0,150 };

void drawPipe(int index, int pipeXAxis, int pipeYAxis)
{

	glPushMatrix();
	glColor3f(0, 1, 0);
	glBegin(GL_QUADS);
	glVertex2i(pipeXAxis, 800);
	glVertex2i(pipeXAxis + 50, 800);
	glVertex2i(pipeXAxis + 50, 50 + pipeYAxis);
	glVertex2i(pipeXAxis, 50 + pipeYAxis);
	//Pipe head
	glColor3f(0.137255, 0.556863, 0.137255);
	glVertex2i(pipeXAxis - 3, 70 + pipeYAxis);
	glVertex2i(pipeXAxis + 50 + 3, 70 + pipeYAxis);
	glVertex2i(pipeXAxis + 50 + 3, 50 + pipeYAxis);
	glVertex2i(pipeXAxis - 3, 50 + pipeYAxis);
	glEnd();

	//Bottom pipe
	glColor3f(0, 1, 0);
	glBegin(GL_QUADS);
	glVertex2i(pipeXAxis, -800);
	glVertex2i(pipeXAxis + 50, -800);
	glVertex2i(pipeXAxis + 50, -50 + pipeYAxis);
	glVertex2i(pipeXAxis, -50 + pipeYAxis);
	//Pipe Head
	glColor3f(0.137255, 0.556863, 0.137255);
	glVertex2i(pipeXAxis - 3, -70 + pipeYAxis);
	glVertex2i(pipeXAxis + 50 + 3, -70 + pipeYAxis);
	glVertex2i(pipeXAxis + 50 + 3, -50 + pipeYAxis);
	glVertex2i(pipeXAxis - 3, -50 + pipeYAxis);
	glEnd();
	glPopMatrix();
}

void pipeSpawner(int unused)
{
	if (pipeSpawn[0] == -300 && gameOver != 1) {
		pipeSpawn[0] = 300;

		//score++;
	}
	else
		pipeSpawn[0] -= level;

	if (pipeSpawn[1] == -300 && gameOver != 1) {
		pipeSpawn[1] = 300;

		//score++;
	}
	else
		pipeSpawn[1] -= level;

	if (pipeSpawn[2] == -300 && gameOver != 1) {
		pipeSpawn[2] = 300;

		//score++;
	}
	else pipeSpawn[2] -= level;

	glutPostRedisplay();
	glutTimerFunc(10, pipeSpawner, 0);
}

void drawBird1() {
	glTranslatef(0, birdPosition, 0);

	//body
	glColor3f(0.968627451, 0.937254902, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(-190, 0);
	for (int i = 0; i <= 360; i += 10) {
		float angle = i * M_PI / 180.0f;
		glVertex2f(-190 + 10 * cos(angle), 0 + 10 * sin(angle));
	}
	glEnd();

	//eye
	glColor3f(1, 1, 1);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(-184, 6);
	for (int i = 0; i <= 360; i += 10) {
		float angle = i * M_PI / 180.0f;
		glVertex2f(-184 + 6 * cos(angle), 6 + 6 * sin(angle));
	}
	glEnd();


	glColor3f(0, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(-184, 6);
	for (int i = 0; i <= 360; i += 10) {
		float angle = i * M_PI / 180.0f;
		glVertex2f(-184 + 2 * cos(angle), 6 + 2 * sin(angle));
	}
	glEnd();


	// Beak
	glColor3f(0.898039216, 0.180392157, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2i(-180, 3);
	glVertex2i(-175, 0);
	glVertex2i(-180, -3);
	glEnd();


	//Wing
	glColor3f(0.898039216, 0.180392157, 0.0);
	glRotatef(wingRotateAngle, 1, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2i(-202 + 10, 5);
	glVertex2i(-202 + 5, -5);
	glVertex2i(-202 + 15, -5);
	glEnd();

	glPopMatrix();
}

void drawBird2() {
	glTranslatef(0, birdPosition, 0); 

	//body
	glColor3f(0.968627451, 0.937254902, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-200, -25); // Bottom left corner
	glVertex2f(-170, -25);  // Bottom right corner
	glVertex2f(-185, 25);
	glEnd();

	//tail
	glColor3f(0, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-185, 25);
	glVertex2i(-195, 30);
	glVertex2i(-195, 20);
	glEnd();

	//beak
	glColor3f(0.898039216, 0.180392157, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2i(-180, -5);
	glVertex2i(-175, -10);
	glVertex2i(-180, -15);
	glEnd();

	//eye
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(-178, 0);
	for (int i = 0; i <= 360; i += 10) {
		float angle = i * M_PI / 180.0f;
		glVertex2f(-178 + 2.5f * cos(angle), 0 + 2.5f * sin(angle));
	}
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(-185, 0);

	for (int i = 0; i <= 360; i += 10) {
		float angle = i * M_PI / 180.0f;
		glVertex2f(-185 + 2.5f * cos(angle), 0 + 2.5f * sin(angle));
	}
	glEnd();

	glPopMatrix();
}

void drawBird3() {
	glTranslatef(0, birdPosition, 0);  

	//body
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(-178, 0);

	for (int i = 0; i <= 360; i += 10) {
		float angle = i * M_PI / 180.0f;
		glVertex2f(-178 + 21 * cos(angle), 0 + 21 * sin(angle));
	}
	glEnd();


	//toora
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(-178, 23);

	for (int i = 0; i <= 360; i += 10) {
		float angle = i * M_PI / 180.0f;
		glVertex2f(-178 + 3.5f * cos(angle), 23 + 3.5f * sin(angle));
	}
	glEnd();


	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(-185, 21.5);

	for (int i = 0; i <= 360; i += 10) {
		float angle = i * M_PI / 180.0f;
		glVertex2f(-185 + 3.5f * cos(angle), 21.5f + 3.5f * sin(angle));
	}
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(-171, 21.5);

	for (int i = 0; i <= 360; i += 10) {
		float angle = i * M_PI / 180.0f;
		glVertex2f(-171 + 3.5f * cos(angle), 21.5f + 3.5f * sin(angle));
	}
	glEnd();

	//tail
	glColor3f(0, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2i(-210, 5);
	glVertex2f(-195, 0);
	glVertex2i(-210, -5);
	glEnd();

	//beak
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2i(-170, 5);
	glVertex2i(-160, 0);
	glVertex2i(-170, -5);
	glEnd();

	//eye
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(-175, 10);
	for (int i = 0; i <= 360; i += 10) {
		float angle = i * M_PI / 180.0f;
		glVertex2f(-175 + 3.5f * cos(angle), 10 + 3.5f * sin(angle));
	}
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(-165, 10);

	for (int i = 0; i <= 360; i += 10) {
		float angle = i * M_PI / 180.0f;
		glVertex2f(-165 + 3.5f * cos(angle), 10 + 3.5f * sin(angle));
	}
	glEnd();

	glPopMatrix();
}



void birdFly(int unused) {
	if (birdPosition != 300 && birdFlyDist != 0) {
		 
		birdPosition += level;
		birdFlyDist -= level;
	}
	else {
		btnState = 0;
		return;
	}
	glutPostRedisplay();
	glutTimerFunc(10, birdFly, unused);
}

void gravity() {

	if (birdPosition != -300 && btnState == 0) {
		birdPosition--;
	}

	if (birdPosition == -300 || birdPosition > 280) {
		std::cout << "Over" << "\n";
	}
	glutPostRedisplay();
}


void birdPhysic(int unused) {

	gravity();
	glutTimerFunc(10, birdPhysic, 0);
}

void birdMovKey(unsigned char btn, int x, int) {
	if (btn == '1' && introState == 0) {
		choice = 1;
		glutPostRedisplay();
		introState = 1;

	}
	else if (btn == '2' && introState == 0) {
		choice = 2;
		glutPostRedisplay();
		introState = 1;
	}
	else if (btn == '3' && introState == 0) {
		choice = 3;
		glutPostRedisplay();
		introState = 1;
	}
	if (btn == ' ') {
		birdFlyDist = 30;
		btnState = 1;
		birdFly(0);
	}
}

void renderBitmapString(float x, float y, void* font, const char* string) {
	const char* c;
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}


void introScreen()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1, 1, 1, 1);
	glColor3f(0, 0, 0.5);
	renderBitmapString(-50, 140, GLUT_BITMAP_TIMES_ROMAN_24, "Flappy Bird");
	glColor3f(0, 0, 0);
	renderBitmapString(-40, 90, GLUT_BITMAP_HELVETICA_18, "1 . Easy");
	renderBitmapString(-40, 60, GLUT_BITMAP_HELVETICA_18, "2 . Normal");
	renderBitmapString(-40, 30, GLUT_BITMAP_HELVETICA_18, "3 . Hard");
	glFlush();
}

static void display() {
	if (introState == 0) {
		introScreen();
	}
	else {
		
		glClear(GL_COLOR_BUFFER_BIT);//clear previous screen
		glClearColor(0.196078, 0.6, 0.8, 1);// set back ground color
		glLoadIdentity();//resets all transformations

		//glColor3f(1.0f, 1.0f, 1.0f);
		//glPointSize(5.0f); // Increase point size
		//glBegin(GL_POINTS);
		//glVertex2f(0.0f,  280.0f);
		//glEnd();

		drawPipe(0, pipeSpawn[0], translatePipePos[0]);
		drawPipe(1, pipeSpawn[1], translatePipePos[1]);
		drawPipe(2, pipeSpawn[2], translatePipePos[2]);

		switch (choice) {
		case 1:
			level = 1;
			drawBird1();
			break;
		case 2:
			level = 2;
			drawBird2();
			break;
		case 3:
			level = 3;
			drawBird3();
			break;
		default:
			break;
		}

		glFlush();// display change on screen
	}
}

static void init() {
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-300, 300, -300, 300);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Flappy Bird");

	glutDisplayFunc(display);
	glutKeyboardFunc(birdMovKey);

	init();
	 
 
	pipeSpawner(0);
	birdPhysic(0);
	 
 
	glutMainLoop();

}