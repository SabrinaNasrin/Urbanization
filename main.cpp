#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<math.h>
#include <sys/timeb.h>
#include<bits/stdc++.h>
#define drawOneLine(x1,y1,x2,y2)  glBegin(GL_LINES);  \
   glVertex3f ((x1),(y1),(0.0)); glVertex3f ((x2),(y2),(0.0)); glEnd();

int mov=100,frame=0;
float counter=0.0,counter1=0.0,counter2=0.0,counter3=0.0,counter4=0.0,counter5=0.0;
//writing code
void drawstring(float x, float y,float z, char *string)
{
    char *ct;
    glRasterPos3f(x,y,z);
    for(ct=string; *ct!= '\0'; ct++)
    {
        glColor3f(0.0,0.0,0.0);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *ct);
    }
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
}

//cloud move
void cloud_move()
{
    glLoadIdentity();
	glTranslatef(counter/2.0,0.0,0.0);
	counter+=1.1;
	if(counter>140)
        counter=0.0;
}

//sun circle
void sunCircle(float rad, float xx, float yy) {

	float thetha = 2 * 3.1415 / 20;
	float x, y;
	glColor3f(1.0, 1.0, 0.0);
	glLineWidth(1.0);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < 20; i++) {
		x = rad * cos(i*thetha) + xx;
		y = rad*sin(i*thetha) + yy;
		float z = -0.4;
		glVertex3f(x, y, z);
	}
	glEnd();
}

//sun
void sun()
{
    glColor3f(1.0, 1.0, 0.0);
    sunCircle(7.5, 50.0, 85.0);
}
//cloud circle
void CloudCircle(float rad, float xx, float yy) {

	float thetha = 2 * 3.1415 / 20;
	float x, y;
	glColor3f(1.1, 1.1, 1.10);
	glLineWidth(1.0);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < 20; i++) {
		x = rad * cos(i*thetha) + xx;
		y = rad*sin(i*thetha) + yy;
		float z = -0.5;
		glVertex3f(x, y, z);
	}
	glEnd();
}
//cloud
void cloud()
{
	glColor3f(1.0, 1.0, 1.0);
	CloudCircle(5.5, -28.0, 80.0);
	CloudCircle(5.5, -20.0, 76.0);
	CloudCircle(5.5, -22.0, 81.0);
	CloudCircle(5.5, -24.0, 76.0);
	CloudCircle(5.5, -98.0, 77.0);
	CloudCircle(5.5, -94.0, 72.0);
	CloudCircle(5.5, -90.0, 79.0);
	CloudCircle(5.5, 98.0, 70.0);
	CloudCircle(5.5, 94.0, 65.0);
	CloudCircle(5.5, 90.0, 72.0);
    CloudCircle(5.5, 40.0, 78.0);
	CloudCircle(5.5, 42.0, 85.0);
	CloudCircle(5.5, 35.0, 80.0);

}
//drawing river
void river()
{
     glLoadIdentity();
     glBegin(GL_POLYGON);
     glColor3f(0.22,0.69,0.87);
     glVertex3f(-100.0,-40.0,0.0);
     glColor3f(0.0,0.0,1.0);
     glVertex3f(-100.0,-90.0,0.0);
     glColor3f(0.0,0.0,1.0);
     glVertex3f(100.0,-90.0,0.0);
     glColor3f(0.22,0.69,0.87);
     glVertex3f(100.0,-40.0,0.0);
     glEnd();

}
//drawing boat_roof
void halfCircle(float rad, float xx, float yy,int R,int G,int B) {

	float thetha = 2 * 3.1415 / 20;
	float x, y;
	glColor3ub(R,G,B);
	glLineWidth(1.0);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < 10; i++) {
		x = rad * cos(i*thetha) + xx;
		y = rad*sin(i*thetha) + yy;
		float z = -0.5;
		glVertex3f(x,y,z);
	}
	glEnd();
}
//drawing boat
void boat_1()
{
    glLoadIdentity();
    //boat move
	glTranslatef(counter1/2.0,0.0,0.0);
	counter1-=1.1;
	if(counter1<-200)
        counter1=0.0;
    halfCircle(8.5,59.0,-68.0,165,42,42);  //calling boat_roof
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(40.0,-60.0,0.0);
    glVertex3f(50.0,-70.0,0.0);
    glVertex3f(50.0,-65.0,0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(50.0,-65.0,0.0);
    glVertex3f(50.0,-70.0,0.0);
    glVertex3f(68.0,-70.0,0.0);
    glVertex3f(68.0,-65.0,0.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(68.0,-65.0,0.0);
    glVertex3f(68.0,-70.0,0.0);
    glVertex3f(78.0,-60.0,0.0);
    glEnd();
}
//drawing boat
void boat_2()
{
    glLoadIdentity();
    //boat move
	glTranslatef(counter2/2.0,0.0,0.0);
	counter2+=1.1;
	if(counter2>200)
        counter2=0.0;
    halfCircle(8.5,59.0-70.0,-63.0,165,42,42); //calling boat roof
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(40.0-70.0,-55.0,0.0);
    glVertex3f(50.0-70.0,-65.0,0.0);
    glVertex3f(50.0-70.0,-60.0,0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(50.0-70.0,-60.0,0.0);
    glVertex3f(50.0-70.0,-65.0,0.0);
    glVertex3f(68.0-70.0,-65.0,0.0);
    glVertex3f(68.0-70.0,-60.0,0.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(68.0-70.0,-60.0,0.0);
    glVertex3f(68.0-70.0,-65.0,0.0);
    glVertex3f(78.0-70.0,-55.0,0.0);
    glEnd();
}
//drawing boat
void boat_3()
{
    glLoadIdentity();
    //boat move
	glTranslatef(counter3/2.0,0.0,0.0);
	counter3+=1.1;
	if(counter3>200)
        counter3=0.0;
    halfCircle(8.5,59.0-150.0,-63.0,165,42,42); //calling boat roof
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(40.0-150.0,-55.0,0.0);
    glVertex3f(50.0-150.0,-65.0,0.0);
    glVertex3f(50.0-150.0,-60.0,0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(50.0-150.0,-60.0,0.0);
    glVertex3f(50.0-150.0,-65.0,0.0);
    glVertex3f(68.0-150.0,-65.0,0.0);
    glVertex3f(68.0-150.0,-60.0,0.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(68.0-150.0,-60.0,0.0);
    glVertex3f(68.0-150.0,-65.0,0.0);
    glVertex3f(78.0-150.0,-55.0,0.0);
    glEnd();
}
//drawing tree leaves with circles
void treeCircle(float rad, float xx, float yy,int R,int G, int B) {

	float thetha = 2 * 3.1415 / 20;
	float x, y;
	glColor3ub(R,G,B);
	glLineWidth(1.0);
	glBegin(GL_TRIANGLE_FAN);    //drawing circle
	for (int i = 0; i < 20; i++) {
		x = rad * cos(i*thetha) + xx;
		y = rad*sin(i*thetha) + yy;
		float z = -0.5;
		glVertex3f(x, y, z);
	}
	glEnd();
}
void tree_1()
{
    glLoadIdentity();
    //drawing the body of tree
    glColor3ub(165,42,42);
    glLineWidth(500.0);
    glBegin(GL_POLYGON);
    glVertex2f(20.0+45.0,45.0);
    glVertex2f(19.5+45.0,28.0);
    glVertex2f(25.0+45.0,28.0);
    glVertex2f(24.5+45.0,45.0);
    glEnd();
     glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0+45.0,45.0);
    glVertex2f(22.5+45.0,45.0);
    glVertex2f(18.0+45.0,55.0);
    glVertex2f(15.0+45.0,55.0);
    glEnd();
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(22.0+45.0,45.0);
    glVertex2f(24.5+45.0,45.0);
    glVertex2f(28.5+45.0,55.0);
    glVertex2f(26.0+45.0,55.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(24.0+45.0,39.0);
    glVertex2f(24.0+45.0,37.0);
    glVertex2f(27.0+45.0,42.0);
    glVertex2f(26.0+45.0,43.0);
    glEnd();
    //calling treecircle to draw the leaves
    treeCircle(5.5, 15.0+45.0, 59.0,0,128,0);
    treeCircle(5.5, 21.0+45.0, 58.0,0,128,0);
    treeCircle(5.5, 27.0+45.0, 59.0,0,128,0);
    treeCircle(5.5, 18.0+45.0, 63.0,0,128,0);
    treeCircle(5.5, 24.0+45.0, 63.0,0,128,0);
    treeCircle(5.5, 21.0+45.0, 66.0,0,128,0);
}
//drawing tree
void tree_2()
{
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0+30.0,45.0);
    glVertex2f(19.5+30.0,28.0);
    glVertex2f(25.0+30.0,28.0);
    glVertex2f(24.5+30.0,45.0);
    glEnd();
     glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0+30.0,45.0);
    glVertex2f(22.5+30.0,45.0);
    glVertex2f(18.0+30.0,55.0);
    glVertex2f(15.0+30.0,55.0);
    glEnd();
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(22.0+30.0,45.0);
    glVertex2f(24.5+30.0,45.0);
    glVertex2f(28.5+30.0,55.0);
    glVertex2f(26.0+30.0,55.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(24.0+30.0,39.0);
    glVertex2f(24.0+30.0,37.0);
    glVertex2f(27.0+30.0,42.0);
    glVertex2f(26.0+30.0,43.0);
    glEnd();
    //calling treecircle to draw the leaves
    treeCircle(5.5, 15.0+30.0, 59.0,50,205,50);
    treeCircle(5.5, 21.0+30.0, 58.0,50,205,50);
    treeCircle(5.5, 27.0+30.0, 59.0,50,205,50);
    treeCircle(5.5, 18.0+30.0, 63.0,50,205,50);
    treeCircle(5.5, 24.0+30.0, 63.0,50,205,50);
    treeCircle(5.5, 21.0+30.0, 66.0,50,205,50);
}
void tree_3()
{
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0+15.0,45.0);
    glVertex2f(19.5+15.0,28.0);
    glVertex2f(25.0+15.0,28.0);
    glVertex2f(24.5+15.0,45.0);
    glEnd();
     glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0+15.0,45.0);
    glVertex2f(22.5+15.0,45.0);
    glVertex2f(18.0+15.0,55.0);
    glVertex2f(15.0+15.0,55.0);
    glEnd();
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(22.0+15.0,45.0);
    glVertex2f(24.5+15.0,45.0);
    glVertex2f(28.5+15.0,55.0);
    glVertex2f(26.0+15.0,55.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(24.0+15.0,39.0);
    glVertex2f(24.0+15.0,37.0);
    glVertex2f(27.0+15.0,42.0);
    glVertex2f(26.0+15.0,43.0);
    glEnd();
    treeCircle(5.5, 15.0+15.0, 59.0,0,100,0);
    treeCircle(5.5, 21.0+15.0, 58.0,0,100,0);
    treeCircle(5.5, 27.0+15.0, 59.0,0,100,0);
    treeCircle(5.5, 18.0+15.0, 63.0,0,100,0);
    treeCircle(5.5, 24.0+15.0, 63.0,0,100,0);
    treeCircle(5.5, 21.0+15.0, 66.0,0,100,0);
}
void tree_4()
{
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0,45.0);
    glVertex2f(19.5,28.0);
    glVertex2f(25.0,28.0);
    glVertex2f(24.5,45.0);
    glEnd();
     glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0,45.0);
    glVertex2f(22.5,45.0);
    glVertex2f(18.0,55.0);
    glVertex2f(15.0,55.0);
    glEnd();
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(22.0,45.0);
    glVertex2f(24.5,45.0);
    glVertex2f(28.5,55.0);
    glVertex2f(26.0,55.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(24.0,39.0);
    glVertex2f(24.0,37.0);
    glVertex2f(27.0,42.0);
    glVertex2f(26.0,43.0);
    glEnd();
    treeCircle(5.5, 15.0, 59.0,34,139,34);
    treeCircle(5.5, 21.0, 58.0,34,139,34);
    treeCircle(5.5, 27.0, 59.0,34,139,34);
    treeCircle(5.5, 18.0, 63.0,34,139,34);
    treeCircle(5.5, 24.0, 63.0,34,139,34);
    treeCircle(5.5, 21.0, 66.0,34,139,34);
}
void tree_5()
{
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0+60.0,45.0);
    glVertex2f(19.5+60.0,28.0);
    glVertex2f(25.0+60.0,28.0);
    glVertex2f(24.5+60.0,45.0);
    glEnd();
     glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0+60.0,45.0);
    glVertex2f(22.5+60.0,45.0);
    glVertex2f(18.0+60.0,55.0);
    glVertex2f(15.0+60.0,55.0);
    glEnd();
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(22.0+60.0,45.0);
    glVertex2f(24.5+60.0,45.0);
    glVertex2f(28.5+60.0,55.0);
    glVertex2f(26.0+60.0,55.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(24.0+60.0,39.0);
    glVertex2f(24.0+60.0,37.0);
    glVertex2f(27.0+60.0,42.0);
    glVertex2f(26.0+60.0,43.0);
    glEnd();
    treeCircle(5.5, 15.0+60.0, 59.0,34,139,34);
    treeCircle(5.5, 21.0+60.0, 58.0,34,139,34);
    treeCircle(5.5, 27.0+60.0, 59.0,34,139,34);
    treeCircle(5.5, 18.0+60.0, 63.0,34,139,34);
    treeCircle(5.5, 24.0+60.0, 63.0,34,139,34);
    treeCircle(5.5, 21.0+60.0, 66.0,34,139,34);
}
void tree_6()
{
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0+75.0,45.0);
    glVertex2f(19.5+75.0,28.0);
    glVertex2f(25.0+75.0,28.0);
    glVertex2f(24.5+75.0,45.0);
    glEnd();
     glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0+75.0,45.0);
    glVertex2f(22.5+75.0,45.0);
    glVertex2f(18.0+75.0,55.0);
    glVertex2f(15.0+75.0,55.0);
    glEnd();
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(22.0+75.0,45.0);
    glVertex2f(24.5+75.0,45.0);
    glVertex2f(28.5+75.0,55.0);
    glVertex2f(26.0+75.0,55.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(24.0+75.0,39.0);
    glVertex2f(24.0+75.0,37.0);
    glVertex2f(27.0+75.0,42.0);
    glVertex2f(26.0+75.0,43.0);
    glEnd();
    treeCircle(5.5, 15.0+75.0, 59.0,0,128,1);
    treeCircle(5.5, 21.0+75.0, 58.0,0,128,1);
    treeCircle(5.5, 27.0+75.0, 59.0,0,128,1);
    treeCircle(5.5, 18.0+75.0, 63.0,0,128,1);
    treeCircle(5.5, 24.0+75.0, 63.0,0,128,1);
    treeCircle(5.5, 21.0+75.0, 66.0,0,128,1);
}
void tree_7()
{
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0-17.0,45.0);
    glVertex2f(19.5-17.0,30.0);
    glVertex2f(25.0-17.0,30.0);
    glVertex2f(24.5-17.0,45.0);
    glEnd();
     glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0-17.0,45.0);
    glVertex2f(22.5-17.0,45.0);
    glVertex2f(18.0-17.0,55.0);
    glVertex2f(15.0-17.0,55.0);
    glEnd();
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(22.0-17.0,45.0);
    glVertex2f(24.5-17.0,45.0);
    glVertex2f(28.5-17.0,55.0);
    glVertex2f(26.0-17.0,55.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(24.0-17.0,39.0);
    glVertex2f(24.0-17.0,37.0);
    glVertex2f(27.0-17.0,42.0);
    glVertex2f(26.0-17.0,43.0);
    glEnd();
    treeCircle(5.5, 15.0-17.0, 59.0,124,252,0);
    treeCircle(5.5, 21.0-17.0, 58.0,124,252,0);
    treeCircle(5.5, 27.0-17.0, 59.0,124,252,0);
    treeCircle(5.5, 18.0-17.0, 63.0,124,252,0);
    treeCircle(5.5, 24.0-17.0, 63.0,124,252,0);
    treeCircle(5.5, 21.0-17.0, 66.0,124,252,0);
}
void tree_8()
{
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0-34.0,45.0);
    glVertex2f(19.5-34.0,28.0);
    glVertex2f(25.0-34.0,28.0);
    glVertex2f(24.5-34.0,45.0);
    glEnd();
     glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0-34.0,45.0);
    glVertex2f(22.5-34.0,45.0);
    glVertex2f(18.0-34.0,55.0);
    glVertex2f(15.0-34.0,55.0);
    glEnd();
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(22.0-34.0,45.0);
    glVertex2f(24.5-34.0,45.0);
    glVertex2f(28.5-34.0,55.0);
    glVertex2f(26.0-34.0,55.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(24.0-34.0,39.0);
    glVertex2f(24.0-34.0,37.0);
    glVertex2f(27.0-34.0,42.0);
    glVertex2f(26.0-34.0,43.0);
    glEnd();
    treeCircle(5.5, 15.0-34.0, 59.0,50,205,50);
    treeCircle(5.5, 21.0-34.0, 58.0,50,205,50);
    treeCircle(5.5, 27.0-34.0, 59.0,50,205,50);
    treeCircle(5.5, 18.0-34.0, 63.0,50,205,50);
    treeCircle(5.5, 24.0-34.0, 63.0,50,205,50);
    treeCircle(5.5, 21.0-34.0, 66.0,50,205,50);
}
void tree_9()
{
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0-51.0,45.0);
    glVertex2f(19.5-51.0,28.0);
    glVertex2f(25.0-51.0,28.0);
    glVertex2f(24.5-51.0,45.0);
    glEnd();
     glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0-51.0,45.0);
    glVertex2f(22.5-51.0,45.0);
    glVertex2f(18.0-51.0,55.0);
    glVertex2f(15.0-51.0,55.0);
    glEnd();
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(22.0-51.0,45.0);
    glVertex2f(24.5-51.0,45.0);
    glVertex2f(28.5-51.0,55.0);
    glVertex2f(26.0-51.0,55.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(24.0-51.0,39.0);
    glVertex2f(24.0-51.0,37.0);
    glVertex2f(27.0-51.0,42.0);
    glVertex2f(26.0-51.0,43.0);
    glEnd();
    treeCircle(5.5, 15.0-51.0, 59.0,0,128,0);
    treeCircle(5.5, 21.0-51.0, 58.0,0,128,0);
    treeCircle(5.5, 27.0-51.0, 59.0,0,128,0);
    treeCircle(5.5, 18.0-51.0, 63.0,0,128,0);
    treeCircle(5.5, 24.0-51.0, 63.0,0,128,0);
    treeCircle(5.5, 21.0-51.0, 66.0,0,128,0);
}
void tree_10()
{
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0-68.0,45.0);
    glVertex2f(19.5-68.0,28.0);
    glVertex2f(25.0-68.0,28.0);
    glVertex2f(24.5-68.0,45.0);
    glEnd();
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0-68.0,45.0);
    glVertex2f(22.5-68.0,45.0);
    glVertex2f(18.0-68.0,55.0);
    glVertex2f(15.0-68.0,55.0);
    glEnd();
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(22.0-68.0,45.0);
    glVertex2f(24.5-68.0,45.0);
    glVertex2f(28.5-68.0,55.0);
    glVertex2f(26.0-68.0,55.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(24.0-68.0,39.0);
    glVertex2f(24.0-68.0,37.0);
    glVertex2f(27.0-68.0,42.0);
    glVertex2f(26.0-68.0,43.0);
    glEnd();
    treeCircle(5.5, 15.0-68.0, 59.0,50,205,50);
    treeCircle(5.5, 21.0-68.0, 58.0,50,205,50);
    treeCircle(5.5, 27.0-68.0, 59.0,50,205,50);
    treeCircle(5.5, 18.0-68.0, 63.0,50,205,50);
    treeCircle(5.5, 24.0-68.0, 63.0,50,205,50);
    treeCircle(5.5, 21.0-68.0, 66.0,50,205,50);
}
void tree_11()
{
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0-85.0,45.0);
    glVertex2f(19.5-85.0,28.0);
    glVertex2f(25.0-85.0,28.0);
    glVertex2f(24.5-85.0,45.0);
    glEnd();
     glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0-85.0,45.0);
    glVertex2f(22.5-85.0,45.0);
    glVertex2f(18.0-85.0,55.0);
    glVertex2f(15.0-85.0,55.0);
    glEnd();
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(22.0-85.0,45.0);
    glVertex2f(24.5-85.0,45.0);
    glVertex2f(28.5-85.0,55.0);
    glVertex2f(26.0-85.0,55.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(24.0-85.0,39.0);
    glVertex2f(24.0-85.0,37.0);
    glVertex2f(27.0-85.0,42.0);
    glVertex2f(26.0-85.0,43.0);
    glEnd();
    treeCircle(5.5, 15.0-85.0, 59.0,0,100,0);
    treeCircle(5.5, 21.0-85.0, 58.0,0,100,0);
    treeCircle(5.5, 27.0-85.0, 59.0,0,100,0);
    treeCircle(5.5, 18.0-85.0, 63.0,0,100,0);
    treeCircle(5.5, 24.0-85.0, 63.0,0,100,0);
    treeCircle(5.5, 21.0-85.0, 66.0,0,100,0);
}
void tree_12()
{
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0-102.0,45.0);
    glVertex2f(19.5-102.0,28.0);
    glVertex2f(25.0-102.0,28.0);
    glVertex2f(24.5-102.0,45.0);
    glEnd();
     glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0-102.0,45.0);
    glVertex2f(22.5-102.0,45.0);
    glVertex2f(18.0-102.0,55.0);
    glVertex2f(15.0-102.0,55.0);
    glEnd();
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(22.0-102.0,45.0);
    glVertex2f(24.5-102.0,45.0);
    glVertex2f(28.5-102.0,55.0);
    glVertex2f(26.0-102.0,55.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(24.0-102.0,39.0);
    glVertex2f(24.0-102.0,37.0);
    glVertex2f(27.0-102.0,42.0);
    glVertex2f(26.0-102.0,43.0);
    glEnd();
     treeCircle(5.5, 15.0-102.0, 59.0,50,205,50);
    treeCircle(5.5, 21.0-102.0, 58.0,50,205,50);
    treeCircle(5.5, 27.0-102.0, 59.0,50,205,50);
    treeCircle(5.5, 18.0-102.0, 63.0,50,205,50);
    treeCircle(5.5, 24.0-102.0, 63.0,50,205,50);
    treeCircle(5.5, 21.0-102.0, 66.0,50,205,50);
}
void tree_13()
{
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0-119.0,45.0);
    glVertex2f(19.5-119.0,28.0);
    glVertex2f(25.0-119.0,28.0);
    glVertex2f(24.5-119.0,45.0);
    glEnd();
     glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0-119.0,45.0);
    glVertex2f(22.5-119.0,45.0);
    glVertex2f(18.0-119.0,55.0);
    glVertex2f(15.0-119.0,55.0);
    glEnd();
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(22.0-119.0,45.0);
    glVertex2f(24.5-119.0,45.0);
    glVertex2f(28.5-119.0,55.0);
    glVertex2f(26.0-119.0,55.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(24.0-119.0,39.0);
    glVertex2f(24.0-119.0,37.0);
    glVertex2f(27.0-119.0,42.0);
    glVertex2f(26.0-119.0,43.0);
    glEnd();
    treeCircle(5.5, 15.0-119.0, 59.0,0,100,0);
    treeCircle(5.5, 21.0-119.0, 58.0,0,100,0);
    treeCircle(5.5, 27.0-119.0, 59.0,0,100,0);
    treeCircle(5.5, 18.0-119.0, 63.0,0,100,0);
    treeCircle(5.5, 24.0-119.0, 63.0,0,100,0);
    treeCircle(5.5, 21.0-119.0, 66.0,0,100,0);
}
void tree_14()
{
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0+23.0,45.0-25.0);
    glVertex2f(19.5+23.0,28.0-25.0);
    glVertex2f(25.0+23.0,28.0-25.0);
    glVertex2f(24.5+23.0,45.0-25.0);
    glEnd();
     glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0+23.0,45.0-25.0);
    glVertex2f(22.5+23.0,45.0-25.0);
    glVertex2f(18.0+23.0,55.0-25.0);
    glVertex2f(15.0+23.0,55.0-25.0);
    glEnd();
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(22.0+23.0,45.0-25.0);
    glVertex2f(24.5+23.0,45.0-25.0);
    glVertex2f(28.5+23.0,55.0-25.0);
    glVertex2f(26.0+23.0,55.0-25.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(24.0+23.0,39.0-25.0);
    glVertex2f(24.0+23.0,37.0-25.0);
    glVertex2f(27.0+23.0,42.0-25.0);
    glVertex2f(26.0+23.0,43.0-25.0);
    glEnd();
    treeCircle(5.5, 15.0+23.0, 59.0-25.0,34,139,34);
    treeCircle(5.5, 21.0+23.0, 58.0-25.0,34,139,34);
    treeCircle(5.5, 27.0+23.0, 59.0-25.0,34,139,34);
    treeCircle(5.5, 18.0+23.0, 63.0-25.0,34,139,34);
    treeCircle(5.5, 24.0+23.0, 63.0-25.0,34,139,34);
    treeCircle(5.5, 21.0+23.0, 66.0-25.0,34,139,34);
}
void tree_15()
{
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0+38.0,45.0-25.0);
    glVertex2f(19.5+38.0,28.0-25.0);
    glVertex2f(25.0+38.0,28.0-25.0);
    glVertex2f(24.5+38.0,45.0-25.0);
    glEnd();
     glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0+38.0,45.0-25.0);
    glVertex2f(22.5+38.0,45.0-25.0);
    glVertex2f(18.0+38.0,55.0-25.0);
    glVertex2f(15.0+38.0,55.0-25.0);
    glEnd();
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(22.0+38.0,45.0-25.0);
    glVertex2f(24.5+38.0,45.0-25.0);
    glVertex2f(28.5+38.0,55.0-25.0);
    glVertex2f(26.0+38.0,55.0-25.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(24.0+38.0,39.0-25.0);
    glVertex2f(24.0+38.0,37.0-25.0);
    glVertex2f(27.0+38.0,42.0-25.0);
    glVertex2f(26.0+38.0,43.0-25.0);
    glEnd();
    treeCircle(5.5, 15.0+38.0, 59.0-25.0,0,100,0);
    treeCircle(5.5, 21.0+38.0, 58.0-25.0,0,100,0);
    treeCircle(5.5, 27.0+38.0, 59.0-25.0,0,100,0);
    treeCircle(5.5, 18.0+38.0, 63.0-25.0,0,100,0);
    treeCircle(5.5, 24.0+38.0, 63.0-25.0,0,100,0);
    treeCircle(5.5, 21.0+38.0, 66.0-25.0,0,100,0);
}
void tree_16()
{
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0+53.0,45.0-25.0);
    glVertex2f(19.5+53.0,28.0-25.0);
    glVertex2f(25.0+53.0,28.0-25.0);
    glVertex2f(24.5+53.0,45.0-25.0);
    glEnd();
     glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0+53.0,45.0-25.0);
    glVertex2f(22.5+53.0,45.0-25.0);
    glVertex2f(18.0+53.0,55.0-25.0);
    glVertex2f(15.0+53.0,55.0-25.0);
    glEnd();
    glLoadIdentity();
    glColor3ub(165,42,42);
    glLineWidth(500.0);
    glBegin(GL_POLYGON);
    glVertex2f(22.0+53.0,45.0-25.0);
    glVertex2f(24.5+53.0,45.0-25.0);
    glVertex2f(28.5+53.0,55.0-25.0);
    glVertex2f(26.0+53.0,55.0-25.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(24.0+53.0,39.0-25.0);
    glVertex2f(24.0+53.0,37.0-25.0);
    glVertex2f(27.0+53.0,42.0-25.0);
    glVertex2f(26.0+53.0,43.0-25.0);
    glEnd();
    treeCircle(5.5, 15.0+53.0, 59.0-25.0,0,128,0);
    treeCircle(5.5, 21.0+53.0, 58.0-25.0,0,128,0);
    treeCircle(5.5, 27.0+53.0, 59.0-25.0,0,128,0);
    treeCircle(5.5, 18.0+53.0, 63.0-25.0,0,128,0);
    treeCircle(5.5, 24.0+53.0, 63.0-25.0,0,128,0);
    treeCircle(5.5, 21.0+53.0, 66.0-25.0,0,128,0);
}
void tree_17()
{
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0+68.0,45.0-25.0);
    glVertex2f(19.5+68.0,28.0-25.0);
    glVertex2f(25.0+68.0,28.0-25.0);
    glVertex2f(24.5+68.0,45.0-25.0);
    glEnd();
     glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0+68.0,45.0-25.0);
    glVertex2f(22.5+68.0,45.0-25.0);
    glVertex2f(18.0+68.0,55.0-25.0);
    glVertex2f(15.0+68.0,55.0-25.0);
    glEnd();
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(22.0+68.0,45.0-25.0);
    glVertex2f(24.5+68.0,45.0-25.0);
    glVertex2f(28.5+68.0,55.0-25.0);
    glVertex2f(26.0+68.0,55.0-25.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(24.0+68.0,39.0-25.0);
    glVertex2f(24.0+68.0,37.0-25.0);
    glVertex2f(27.0+68.0,42.0-25.0);
    glVertex2f(26.0+68.0,43.0-25.0);
    glEnd();
    treeCircle(5.5, 15.0+68.0, 59.0-25.0,50,205,50);
    treeCircle(5.5, 21.0+68.0, 58.0-25.0,50,205,50);
    treeCircle(5.5, 27.0+68.0, 59.0-25.0,50,205,50);
    treeCircle(5.5, 18.0+68.0, 63.0-25.0,50,205,50);
    treeCircle(5.5, 24.0+68.0, 63.0-25.0,50,205,50);
    treeCircle(5.5, 21.0+68.0, 66.0-25.0,50,205,50);
}
void tree_18()
{
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0+68.0,45.0-60.0);
    glVertex2f(19.5+68.0,28.0-60.0);
    glVertex2f(25.0+68.0,28.0-60.0);
    glVertex2f(24.5+68.0,45.0-60.0);
    glEnd();
     glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0+68.0,45.0-60.0);
    glVertex2f(22.5+68.0,45.0-60.0);
    glVertex2f(18.0+68.0,55.0-60.0);
    glVertex2f(15.0+68.0,55.0-60.0);
    glEnd();
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(22.0+68.0,45.0-60.0);
    glVertex2f(24.5+68.0,45.0-60.0);
    glVertex2f(28.5+68.0,55.0-60.0);
    glVertex2f(26.0+68.0,55.0-60.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(24.0+68.0,39.0-60.0);
    glVertex2f(24.0+68.0,37.0-60.0);
    glVertex2f(27.0+68.0,42.0-60.0);
    glVertex2f(26.0+68.0,43.0-60.0);
    glEnd();
     treeCircle(5.5, 15.0+68.0, 59.0-60.0,0,128,0);
    treeCircle(5.5, 21.0+68.0, 58.0-60.0,0,128,0);
    treeCircle(5.5, 27.0+68.0, 59.0-60.0,0,128,0);
    treeCircle(5.5, 18.0+68.0, 63.0-60.0,0,128,0);
    treeCircle(5.5, 24.0+68.0, 63.0-60.0,0,128,0);
    treeCircle(5.5, 21.0+68.0, 66.0-60.0,0,128,0);
}
void tree_19()
{
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0+53.0,45.0-60.0);
    glVertex2f(19.5+53.0,28.0-60.0);
    glVertex2f(25.0+53.0,28.0-60.0);
    glVertex2f(24.5+53.0,45.0-60.0);
    glEnd();
     glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0+53.0,45.0-60.0);
    glVertex2f(22.5+53.0,45.0-60.0);
    glVertex2f(18.0+53.0,55.0-60.0);
    glVertex2f(15.0+53.0,55.0-60.0);
    glEnd();
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(22.0+53.0,45.0-60.0);
    glVertex2f(24.5+53.0,45.0-60.0);
    glVertex2f(28.5+53.0,55.0-60.0);
    glVertex2f(26.0+53.0,55.0-60.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(24.0+53.0,39.0-60.0);
    glVertex2f(24.0+53.0,37.0-60.0);
    glVertex2f(27.0+53.0,42.0-60.0);
    glVertex2f(26.0+53.0,43.0-60.0);
    glEnd();
    treeCircle(5.5, 15.0+53.0, 59.0-60.0,0,152,0);
    treeCircle(5.5, 21.0+53.0, 58.0-60.0,0,152,0);
    treeCircle(5.5, 27.0+53.0, 59.0-60.0,0,152,0);
    treeCircle(5.5, 18.0+53.0, 63.0-60.0,0,152,0);
    treeCircle(5.5, 24.0+53.0, 63.0-60.0,0,152,0);
    treeCircle(5.5, 21.0+53.0, 66.0-60.0,0,152,0);
}
void tree_20()
{
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0+38.0,45.0-60.0);
    glVertex2f(19.5+38.0,28.0-60.0);
    glVertex2f(25.0+38.0,28.0-60.0);
    glVertex2f(24.5+38.0,45.0-60.0);
    glEnd();
     glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(20.0+38.0,45.0-60.0);
    glVertex2f(22.5+38.0,45.0-60.0);
    glVertex2f(18.0+38.0,55.0-60.0);
    glVertex2f(15.0+38.0,55.0-60.0);
    glEnd();
    glLoadIdentity();
    glColor3ub(165,42,42);
    glBegin(GL_POLYGON);
    glVertex2f(22.0+38.0,45.0-60.0);
    glVertex2f(24.5+38.0,45.0-60.0);
    glVertex2f(28.5+38.0,55.0-60.0);
    glVertex2f(26.0+38.0,55.0-60.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(24.0+38.0,39.0-60.0);
    glVertex2f(24.0+38.0,37.0-60.0);
    glVertex2f(27.0+38.0,42.0-60.0);
    glVertex2f(26.0+38.0,43.0-60.0);
    glEnd();
    treeCircle(5.5, 15.0+38.0, 59.0-60.0,1,100,1);
    treeCircle(5.5, 21.0+38.0, 58.0-60.0,1,100,1);
    treeCircle(5.5, 27.0+38.0, 59.0-60.0,1,100,1);
    treeCircle(5.5, 18.0+38.0, 63.0-60.0,1,100,1);
    treeCircle(5.5, 24.0+38.0, 63.0-60.0,1,100,1);
    treeCircle(5.5, 21.0+38.0, 66.0-60.0,1,100,1);
}
//drawing hut
void hut_1()
{
    glLoadIdentity();
    //roof
    glBegin(GL_POLYGON);
    glColor3ub(165,42,42);
    glVertex2f(-60.0,45.0);
    glColor3ub(255,230,100);
    glVertex2f(-50.0,35.0);
    glColor3ub(255,230,100);
    glVertex2f(-20.0,35.0);
    glColor3ub(165,42,42);
    glVertex2f(-30.0,45.0);
    glEnd();
    //roof
    glBegin(GL_POLYGON);
    glColor3ub(165,42,42);
    glVertex2f(-60.0,45.0);
    glColor3ub(255,230,100);
    glVertex2f(-70.0,35.0);
    glColor3ub(255,230,100);
    glVertex2f(-65.0,35.0);
    glColor3ub(165,42,42);
    glVertex2f(-57.0,42.5);
    glEnd();
    //wall
    glBegin(GL_POLYGON);
    glColor3ub(165,42,42);
    glVertex2f(-65.0,35.0);
    glColor3ub(255,230,100);
    glVertex2f(-65.0,25.0);
    glColor3ub(255,230,100);
    glVertex2f(-50.0,22.0);
    glColor3ub(165,42,42);
    glVertex2f(-50.0,35.0);
    glVertex2f(-57.0,42.5);
    glEnd();
    //wall
    glBegin(GL_POLYGON);
    glColor3ub(165,42,42);
    glVertex2f(-50.0,35.0);
    glColor3ub(100,0,20);
    glVertex2f(-50.0,22.0);
    glColor3ub(255,230,100);
    glVertex2f(-22.0,26.0);
    glColor3ub(165,42,42);
    glVertex2f(-22.0,35.0);
    glEnd();
    //door
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-35.0,30.0);
    glColor3ub(100,0,20);
    glVertex2f(-35.0,24.0);
    glColor3ub(255,230,100);
    glVertex2f(-31.0,24.8);
    glColor3ub(255,255,255);
    glVertex2f(-31.0,30.0);
    glEnd();
    //window
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-60.0,35.0-2.0);
    glColor3ub(100,0,20);
    glVertex2f(-60.0,30.0-2.0);
    glColor3ub(255,230,100);
    glVertex2f(-55.0,30.0-3.0);
    glColor3ub(255,255,255);
    glVertex2f(-55.0,35.0-3.0);
    glEnd();

}
void hut_2()
{
    glLoadIdentity();
    //roof
    glBegin(GL_POLYGON);
    glColor3ub(165,42,42);
    glVertex2f(-60.0-35.0,45.0+2.0);
    glColor3ub(255,230,100);
    glVertex2f(-50.0-35.0,35.0+2.0);
    glColor3ub(165,42,42);
    glVertex2f(-20.0-35.0,35.0+2.0);
    glColor3ub(165,42,42);
    glVertex2f(-30.0-35.0,45.0+2.0);
    glEnd();
    //roof
    glBegin(GL_POLYGON);
    glColor3ub(165,42,42);
    glVertex2f(-60.0-35.0,45.0+2.0);
    glColor3ub(255,230,100);
    glVertex2f(-70.0-35.0,35.0+2.0);
    glColor3ub(255,230,100);
    glVertex2f(-65.0-35.0,35.0+2.0);
    glColor3ub(165,42,42);
    glVertex2f(-57.0-35.0,42.5+2.0);
    glEnd();
    //wall
    glBegin(GL_POLYGON);
    glColor3ub(165,42,42);
    glVertex2f(-65.0-35.0,35.0+2.0);
    glColor3ub(255,230,100);
    glVertex2f(-65.0-35.0,25.0+2.0);
    glColor3ub(255,230,100);
    glVertex2f(-50.0-35.0,22.0+2.0);
    glColor3ub(165,42,42);
    glVertex2f(-50.0-35.0,35.0+2.0);
    glVertex2f(-57.0-35.0,42.5+2.0);
    glEnd();
    //wall
    glBegin(GL_POLYGON);
    glColor3ub(165,42,42);
    glVertex2f(-50.0-35.0,35.0+2.0);
    glColor3ub(100,0,20);
    glVertex2f(-50.0-35.0,22.0+2.0);
    glColor3ub(255,230,100);
    glVertex2f(-22.0-35.0,26.0+2.0);
    glColor3ub(165,42,42);
    glVertex2f(-22.0-35.0,35.0+2.0);
    glEnd();
    //door
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-35.0-35.0,30.0+2.0);
    glColor3ub(100,0,20);
    glVertex2f(-35.0-35.0,24.0+2.0);
    glColor3ub(255,230,100);
    glVertex2f(-31.0-35.0,24.8+2.0);
    glColor3ub(255,255,255);
    glVertex2f(-31.0-35.0,30.0+2.0);
    glEnd();
    //window
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-60.0-35.0,35.0);
    glColor3ub(100,0,20);
    glVertex2f(-60.0-35.0,30.0);
    glColor3ub(255,230,100);
    glVertex2f(-55.0-35.0,30.0-1.0);
    glColor3ub(255,255,255);
    glVertex2f(-55.0-35.0,35.0-1.0);
    glEnd();

}
void hut_3()
{
    glLoadIdentity();
    //roof
    glBegin(GL_POLYGON);
    glColor3ub(165,42,42);
    glVertex2f(-60.0+35.0,45.0+2.0);
    glColor3ub(255,230,100);
    glVertex2f(-50.0+35.0,35.0+2.0);
    glColor3ub(255,230,100);
    glVertex2f(-20.0+35.0,35.0+2.0);
    glColor3ub(165,42,42);
    glVertex2f(-30.0+35.0,45.0+2.0);
    glEnd();
    //roof
    glBegin(GL_POLYGON);
    glColor3ub(165,42,42);
    glVertex2f(-60.0+35.0,45.0+2.0);
    glColor3ub(255,230,100);
    glVertex2f(-70.0+35.0,35.0+2.0);
    glColor3ub(255,230,100);
    glVertex2f(-65.0+35.0,35.0+2.0);
    glColor3ub(165,42,42);
    glVertex2f(-57.0+35.0,42.5+2.0);
    glEnd();
    //wall
    glBegin(GL_POLYGON);
    glColor3ub(165,42,42);
    glVertex2f(-65.0+35.0,35.0+2.0);
    glColor3ub(255,230,100);
    glVertex2f(-65.0+35.0,25.0+4.0);
    glColor3ub(255,230,100);
    glVertex2f(-50.0+35.0,22.0+4.0);
    glColor3ub(165,42,42);
    glVertex2f(-50.0+35.0,35.0+2.0);
    glVertex2f(-57.0+35.0,42.5+2.0);
    glEnd();
    //wall
    glBegin(GL_POLYGON);
    glColor3ub(165,42,42);
    glVertex2f(-50.0+35.0,35.0+2.0);
    glColor3ub(100,0,20);
    glVertex2f(-50.0+35.0,22.0+4.0);
    glColor3ub(255,230,100);
    glVertex2f(-22.0+35.0,26.0+4.0);
    glColor3ub(165,42,42);
    glVertex2f(-22.0+35.0,35.0+2.0);
    glEnd();
    //door
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-35.0+35.0,30.0+4.0);
    glColor3ub(100,0,20);
    glVertex2f(-35.0+35.0,24.0+4.0);
    glColor3ub(255,230,100);
    glVertex2f(-31.0+35.0,24.8+4.0);
    glColor3ub(255,255,255);
    glVertex2f(-31.0+35.0,30.0+4.0);
    glEnd();
    //window
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-60.0+35.0,35.0+2.0);
    glColor3ub(100,0,20);
    glVertex2f(-60.0+35.0,30.0+2.0);
    glColor3ub(255,230,100);
    glVertex2f(-55.0+35.0,30.0+1.0);
    glColor3ub(255,255,255);
    glVertex2f(-55.0+35.0,35.0+1.0);
    glEnd();
}
//drawing road
void road()
{
     glLoadIdentity();
     glColor3ub(152,152,152);
     glBegin(GL_POLYGON);
     glVertex3f(-100.0,-20.0,0.0);
     glVertex3f(-100.0,-70.0,0.0);
     glVertex3f(100.0,-70.0,0.0);
     glVertex3f(100.0,-20.0,0.0);
     glEnd();
     //drawing road mark
    glColor3f(1.0, 1.0, 1.0);
	glLineWidth(5.0);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(5, 0x1C47);  //draw dash/dot/dash lines
	drawOneLine(-100.0,-45.0, 100.0,-45.0);
	glDisable(GL_LINE_STIPPLE);
}
//drawing building
void building_1(float x1,float x2, float h,float h1, int R1, int G1, int B1,int R2,int G2,int B2,int R3,int G3,int B3)
{
    glLoadIdentity();
    //drawing side
    glBegin(GL_POLYGON);
    glColor3ub(R2,G2,B2);
    glVertex3f(x1-5.0,30.0,0.0);
    glVertex3f(x1,30.0,0.0);
    glVertex3f(x1,30.0+h,0.0);
    glVertex3f(x1-5.0,30.0+h-3.0,0.0);
    glEnd();
    //drawing front side
    glLoadIdentity();
    glBegin(GL_POLYGON);
    glColor3ub(R1,G1,B1);
    glVertex3f(x1,30.0,0.0);
    glVertex3f(x2,30.0,0.0);
    glVertex3f(x2,30.0+h,0.0);
    glVertex3f(x1,30.0+h,0.0);
    glEnd();
    //drawing windows
    glLoadIdentity();
    glBegin(GL_POLYGON);
    glColor3ub(R3-41,G3-41,B3-61);
    glVertex3f(x1+3.0,30.0+h1,0.0);
     glColor3ub(R3,G3,B3);
    glVertex3f(x1+7.0,30.0+h1,0.0);
    glColor3ub(R3-41,G3-41,B3-61);
    glVertex3f(x1+7.0,30.0+h1+5.0,0.0);
     glColor3ub(R3,G3,B3);
    glVertex3f(x1+3.0,30.0+h1+5.0,0.0);
    glEnd();
    glLoadIdentity();
    glBegin(GL_POLYGON);
     glColor3ub(R3-41,G3-41,B3-61);
    glVertex3f(x2-7.0,30.0+h1,0.0);
    glColor3ub(R3,G3,B3);
    glVertex3f(x2-3.0,30.0+h1,0.0);
     glColor3ub(R3-41,G3-41,B3-61);
    glVertex3f(x2-3.0,30.0+h1+5.0,0.0);
    glColor3ub(R3,G3,B3);
    glVertex3f(x2-7.0,30.0+h1+5.0,0.0);
    glEnd();
    glLoadIdentity();
    glBegin(GL_POLYGON);
     glColor3ub(R3-41,G3-41,B3-61);
    glVertex3f(x1+3.0,30.0+h1+8.0,0.0);
    glColor3ub(R3,G3,B3);
    glVertex3f(x1+7.0,30.0+h1+8.0,0.0);
     glColor3ub(R3-41,G3-41,B3-61);
    glVertex3f(x1+7.0,30.0+h1+13.0,0.0);
    glColor3ub(R3,G3,B3);
    glVertex3f(x1+3.0,30.0+h1+13.0,0.0);
    glEnd();
    glLoadIdentity();
    glBegin(GL_POLYGON);
     glColor3ub(R3-41,G3-41,B3-61);
    glVertex3f(x2-7.0,30.0+h1+8.0,0.0);
    glColor3ub(R3,G3,B3);
    glVertex3f(x2-3.0,30.0+h1+8.0,0.0);
     glColor3ub(R3-41,G3-41,B3-61);
    glVertex3f(x2-3.0,30.0+h1+13.0,0.0);
    glColor3ub(R3,G3,B3);
    glVertex3f(x2-7.0,30.0+h1+13.0,0.0);
    glEnd();
     glLoadIdentity();
    glBegin(GL_POLYGON);
    glColor3ub(R3-41,G3-41,B3-61);
    glVertex3f(x1+3.0,30.0+h1+16.0,0.0);
    glColor3ub(R3,G3,B3);
    glVertex3f(x1+7.0,30.0+h1+16.0,0.0);
    glColor3ub(R3-41,G3-41,B3-61);
    glVertex3f(x1+7.0,30.0+h1+21.0,0.0);
    glColor3ub(R3,G3,B3);
    glVertex3f(x1+3.0,30.0+h1+21.0,0.0);
    glEnd();

    glLoadIdentity();
    glBegin(GL_POLYGON);
    glColor3ub(R3-41,G3-41,B3-61);
    glVertex3f(x2-7.0,30.0+h1+16.0,0.0);
    glColor3ub(R3,G3,B3);
    glVertex3f(x2-3.0,30.0+h1+16.0,0.0);
    glColor3ub(R3-41,G3-41,B3-61);
    glVertex3f(x2-3.0,30.0+h1+21.0,0.0);
    glColor3ub(R3,G3,B3);
    glVertex3f(x2-7.0,30.0+h1+21.0,0.0);
    glEnd();


}
//drawing car wheel
car_tier(float rad,float xx,float yy)
{
    float thetha = 2 * 3.1415 / 20;
	float x, y;
	glColor3ub(0,0,0);
	glLineWidth(1.0);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < 20; i++) {
		x = rad * cos(i*thetha) + xx;
		y = rad*sin(i*thetha) + yy;
		float z = -0.5;
		glVertex3f(x, y, z);
	}
	glEnd();

}
//drawing car
void car_1(float x1,float x2, float h, int R1, int G1, int B1, int R2, int G2, int B2, int R3,int G3, int B3)
{
    glLoadIdentity();
    //car move
	glTranslatef(counter4/4.0,0.0,0.0);
	counter4-=1.1;
	if(counter4<-200)
        counter4=0.0;
    //drawing car
    glBegin(GL_POLYGON);
    glColor3ub(R1-51,G1,B1);
    glVertex3f(x1,-35.0,0.0);
    glVertex3f(x2,-35.0,0.0);
    glVertex3f(x2-3.0,-35.0+h,0.0);
    glVertex3f(x1+3.0,-35.0+h,0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(R2,G2-255+102,B2+204);
    glVertex3f(x1+5.0,-35.0+h,0.0);
    glVertex3f(x2-5.0,-35.0+h,0.0);
    glVertex3f(x2-8.0,-35.0+h+4.5,0.0);
    glVertex3f(x1+8.0,-35.0+h+4.5,0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(R3,G3,B3);
    glVertex3f(x1+7.0,-35.0+h+1.0,0.0);
    glVertex3f(x1+11.5,-35.0+h+1.0,0.0);
    glVertex3f(x1+11.5,-35.0+h+3.0,0.0);
    glVertex3f(x1+9.0,-35.0+h+3.0,0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(R3,G3,B3);
    glVertex3f(x2-11.5,-35.0+h+1.0,0.0);
    glVertex3f(x2-7.0,-35.0+h+1.0,0.0);
    glVertex3f(x2-9.0,-35.0+h+3.0,0.0);
    glVertex3f(x2-11.5,-35.0+h+3.0,0.0);
    glEnd();
    //drawing car tier
    car_tier(2.5,x1+8.0,-35.0);
    car_tier(2.5,x2-8.0,-35.0);
}
void sky_field()
{
    //drawing sky
   glBegin(GL_POLYGON);
   glColor3f(1.0,1.0,1.0);
   glVertex2f(-100.0,30.0);
   glColor3f(0.22, 0.69, 0.87);
   glVertex2f(-100.0,100.0);
   glColor3f(0.22, 0.69, 0.87);
   glVertex2f(100.0,100.0);
   glColor3f(1.0,1.0,1.0);
   glVertex2f(100.0,30.0);
   glEnd();
   //field
   glLoadIdentity();
   glBegin(GL_POLYGON);
   glColor3f(0.0,1.0,0.0);
   glVertex3f(-100.0,30.0,0.0);
   glColor3f(0.0,1.0,0.0);
   glVertex3f(100.0,30.0,0.0);
   glColor3f(0.0,0.4,0.0);
   glVertex3f(100.0,-100.0,0.0);
   glColor3f(0.0,0.4,0.0);
   glVertex3f(-100.0,-100.0,0.0);
   glEnd();
}
//cover of the project
void scene_1()
{
       glColor3f(0.0,0.0,0.0);
       glBegin(GL_POLYGON);
       glVertex2f(-100.0,100.0);
       glVertex2f(-100.0,-100.0);
       glVertex2f(100.0,-100.0);
       glVertex2f(100.0,100.0);
       glEnd();
       glColor3f(1.0,1.0,1.0);
       if(frame>5)
        drawstring(-50.0,60.0,0.0,"URBANIZATION");
       glColor3f(1.0,1.0,1.0);
       if(frame>10)
        drawstring(-50.0,50.0,0.0,"Submitted by : Sabrina Nasrin");
        glColor3f(1.0,1.0,1.0);
       if(frame>15)
        drawstring(-50.0,40.0,0.0,"Roll No : 133025");
        glColor3f(1.0,1.0,1.0);
       if(frame>20)
        drawstring(-50.0,30.0,0.0,"Section : A");
        glColor3f(1.0,1.0,1.0);
       if(frame>25)
        drawstring(-50.0,20.0,0.0,"Course No : CSE 4202");
        glColor3f(1.0,1.0,1.0);
        if(frame>30)
        drawstring(-50.0,10.0,0.0,"Course Title : Sessional Based on CSE 4201");

}
void scene_14()
{
    glColor3ub(0,100,0);
       glBegin(GL_POLYGON);
       glVertex2f(-100.0,100.0);
       glVertex2f(-100.0,-100.0);
       glVertex2f(100.0,-100.0);
       glVertex2f(100.0,100.0);
       glEnd();
       glColor3f(1.0,1.0,1.0);
       if(frame>60)
        drawstring(-40.0,20.0,0.0,"Before");
       glColor3f(1.0,1.0,1.0);
       if(frame>65)
        drawstring(-26.0,20.0,0.0,"20");
        glColor3f(1.0,1.0,1.0);
        if(frame>70)
        drawstring(-20.0,20.0,0.0,"Years....");
}
//village
void scene_2()
{
    //sky_field
   glPushMatrix();
   sky_field();
   glPopMatrix();
   //sun
   glPushMatrix();
   sun();
   glPopMatrix();
   //cloud
   glPushMatrix();
   cloud_move();
   cloud();
   glPopMatrix();
   //river
   glPushMatrix();
   river();
   glPopMatrix();
   //calling tree_6
   glPushMatrix();
   tree_6();
   glPopMatrix();
   //calling tree_5
   glPushMatrix();
   tree_5();
   glPopMatrix();
  //calling tree_1
   glPushMatrix();
   tree_1();
   glPopMatrix();
   //calling tree_2
   glPushMatrix();
   tree_2();
   glPopMatrix();
   //calling tree_3
   glPushMatrix();
   tree_3();
   glPopMatrix();
   //calling tree_4
   glPushMatrix();
   tree_4();
   glPopMatrix();
   //calling tree_7
   glPushMatrix();
   tree_7();
   glPopMatrix();
   //calling tree_8
   glPushMatrix();
   tree_8();
   glPopMatrix();
   //calling tree_9
   glPushMatrix();
   tree_9();
   glPopMatrix();
   //calling tree_10
   glPushMatrix();
   tree_10();
   glPopMatrix();
    //calling tree_11
   glPushMatrix();
   tree_11();
   glPopMatrix();
    //calling tree_12
   glPushMatrix();
   tree_12();
   glPopMatrix();
    //calling tree_13
   glPushMatrix();
   tree_13();
   glPopMatrix();
   //calling tree_14
   glPushMatrix();
   tree_14();
   glPopMatrix();
    //calling tree_15
   glPushMatrix();
   tree_15();
   glPopMatrix();
    //calling tree_16
   glPushMatrix();
   tree_16();
   glPopMatrix();
    //calling tree_17
   glPushMatrix();
   tree_17();
   glPopMatrix();
    //calling tree_18
   glPushMatrix();
   tree_18();
   glPopMatrix();
    //calling tree_19
   glPushMatrix();
   tree_19();
   glPopMatrix();
    //calling tree_20
   glPushMatrix();
   tree_20();
   glPopMatrix();
   //drawing hut
   glPushMatrix();
   hut_3();
   glPopMatrix();

   //drawing hut
   glPushMatrix();
   hut_2();
   glPopMatrix();

  //drawing hut
   glPushMatrix();
   hut_1();
   glPopMatrix();

   //drawing boat
   glPushMatrix();
   boat_2();
   glPopMatrix();

   glPushMatrix();
   boat_3();
   glPopMatrix();

   glPushMatrix();
   boat_1();
   glPopMatrix();
}
void scene_3()
{
       glColor3ub(0,100,0);
       glBegin(GL_POLYGON);
       glVertex2f(-100.0,100.0);
       glVertex2f(-100.0,-100.0);
       glVertex2f(100.0,-100.0);
       glVertex2f(100.0,100.0);
       glEnd();
       glColor3f(1.0,1.0,1.0);
       if(frame>260)
        drawstring(-40.0,20.0,0.0,"Before");
       glColor3f(1.0,1.0,1.0);
       if(frame>265)
        drawstring(-28.0,20.0,0.0,"15");
       glColor3f(1.0,1.0,1.0);
       if(frame>270)
        drawstring(-22.0,20.0,0.0,"Years....");
}
//village with less trees
void scene_4()
{
   //sky
   glPushMatrix();
   sky_field();
   glPopMatrix();
   //sun
   glPushMatrix();
   sun();
   glPopMatrix();
   //cloud
   glPushMatrix();
   cloud_move();
   cloud();
   glPopMatrix();
   //river
   glPushMatrix();
   river();
   glPopMatrix();
   //calling tree_6
   glPushMatrix();
   tree_6();
   glPopMatrix();
   //calling tree_5
   glPushMatrix();
   tree_5();
   glPopMatrix();
  //calling tree_1
   glPushMatrix();
   tree_1();
   glPopMatrix();
   //calling tree_2
   glPushMatrix();
   tree_2();
   glPopMatrix();
   //calling tree_3
   glPushMatrix();
   tree_3();
   glPopMatrix();
   //calling tree_4
   glPushMatrix();
   tree_4();
   glPopMatrix();
  //calling tree_14
   glPushMatrix();
   tree_14();
   glPopMatrix();
    //calling tree_15
   glPushMatrix();
   tree_15();
   glPopMatrix();
    //calling tree_16
   glPushMatrix();
   tree_16();
   glPopMatrix();
    //calling tree_17
   glPushMatrix();
   tree_17();
   glPopMatrix();
    //calling tree_18
   glPushMatrix();
   tree_18();
   glPopMatrix();
    //calling tree_19
   glPushMatrix();
   tree_19();
   glPopMatrix();
    //calling tree_20
   glPushMatrix();
   tree_20();
   glPopMatrix();

   //drawing hut
   glPushMatrix();
   hut_3();
   glPopMatrix();

   //drawing hut
   glPushMatrix();
   hut_3();
   glPopMatrix();

   //drawing hut
   glPushMatrix();
   hut_2();
   glPopMatrix();

  //drawing hut
   glPushMatrix();
   hut_1();
   glPopMatrix();

   //drawing boat
   glPushMatrix();
   boat_2();
   glPopMatrix();

   //drawing boat
   glPushMatrix();
   boat_3();
   glPopMatrix();

   //drawing boat
   glPushMatrix();
   boat_1();
   glPopMatrix();
}

void scene_5()
{
       glColor3ub(0,100,0);
       glBegin(GL_POLYGON);
       glVertex2f(-100.0,100.0);
       glVertex2f(-100.0,-100.0);
       glVertex2f(100.0,-100.0);
       glVertex2f(100.0,100.0);
       glEnd();
       glColor3f(1.0,1.0,1.0);
       if(frame>460)
        drawstring(-40.0,20.0,0.0,"Before");
       glColor3f(1.0,1.0,1.0);
       if(frame>465)
        drawstring(-28.0,20.0,0.0,"10");
       glColor3f(1.0,1.0,1.0);
       if(frame>470)
        drawstring(-22.0,20.0,0.0,"Years....");
}
//village without one hut and trees
void scene_6()
{
   //sky
   glPushMatrix();
   sky_field();
   glPopMatrix();
   //sun
   glPushMatrix();
   sun();
   glPopMatrix();
   //cloud
   glPushMatrix();
   cloud_move();
   cloud();
   glPopMatrix();
   //river
   glPushMatrix();
   river();
   glPopMatrix();
  //calling tree_6
   glPushMatrix();
   tree_6();
   glPopMatrix();
   //calling tree_5
   glPushMatrix();
   tree_5();
   glPopMatrix();
  //calling tree_1
   glPushMatrix();
   tree_1();
   glPopMatrix();
   //calling tree_2
   glPushMatrix();
   tree_2();
   glPopMatrix();
   //calling tree_3
   glPushMatrix();
   tree_3();
   glPopMatrix();
   //calling tree_4
   glPushMatrix();
   tree_4();
   glPopMatrix();
   //calling tree_14
   glPushMatrix();
   tree_14();
   glPopMatrix();
   //calling tree_15
   glPushMatrix();
   tree_15();
   glPopMatrix();
    //calling tree_16
   glPushMatrix();
   tree_16();
   glPopMatrix();
    //calling tree_17
   glPushMatrix();
   tree_17();
   glPopMatrix();
   //drawing building
   glPushMatrix();
   building_1(-100.0,-85.0,28.0,4.0,169,169,169,120,120,120,255,255,255);
   building_1(-78.0,-63.0,35.0,7.0,0,102,204,0,64,128,255,255,255);
   building_1(-68.0,-53.0,32.0,5.0,230,0,115,153,0,77,255,255,255);
   building_1(-30.0,-15.0,35.0,7.0,230,230,0,153,153,0,255,255,255);
   building_1(-43.0,-28.0,28.0,4.0,0,204,68,0,102,34,255,255,255);
   glPopMatrix();

   //drawing hut
   glPushMatrix();
   hut_2();
   glPopMatrix();

  //drawing hut
   glPushMatrix();
   hut_1();
   glPopMatrix();

   //drawing boat
   glPushMatrix();
   boat_3();
   glPopMatrix();

   //drawing boat
   glPushMatrix();
   boat_2();
   glPopMatrix();
   //drawing boat
   glPushMatrix();
   boat_1();
   glPopMatrix();

}
void scene_7()
{
       glColor3ub(0,100,0);
       glBegin(GL_POLYGON);
       glVertex2f(-100.0,100.0);
       glVertex2f(-100.0,-100.0);
       glVertex2f(100.0,-100.0);
       glVertex2f(100.0,100.0);
       glEnd();
       glColor3f(1.0,1.0,1.0);
       if(frame>660)
        drawstring(-40.0,20.0,0.0,"Before");
       glColor3f(1.0,1.0,1.0);
       if(frame>665)
        drawstring(-28.0,20.0,0.0,"5");
        glColor3f(1.0,1.0,1.0);
        if(frame>670)
        drawstring(-24.0,20.0,0.0,"Years....");
}
//village with road
void scene_8()
{
   //sky
   glPushMatrix();
   sky_field();
   glPopMatrix();
   //sun
   glPushMatrix();
   sun();
   glPopMatrix();
   //cloud
   glPushMatrix();
   cloud_move();
   cloud();
   glPopMatrix();
   //river
   glPushMatrix();
   river();
   glPopMatrix();
   //calling tree_6
   glPushMatrix();
   tree_6();
   glPopMatrix();
   //calling tree_5
   glPushMatrix();
   tree_5();
   glPopMatrix();
  //calling tree_1
   glPushMatrix();
   tree_1();
   glPopMatrix();
   //calling tree_2
   glPushMatrix();
   tree_2();
   glPopMatrix();
   //calling tree_3
   glPushMatrix();
   tree_3();
   glPopMatrix();
   //calling tree_4
   glPushMatrix();
   tree_4();
   glPopMatrix();

   //drawing building
   glPushMatrix();
   building_1(-100.0,-85.0,28.0,4.0,169,169,169,120,120,120,255,255,255);
   building_1(-78.0,-63.0,35.0,7.0,0,102,204,0,64,128,255,255,255);
   building_1(-90.0,-75.0,30.0,4.0,232,0,0,168,0,0,255,255,255);
   building_1(-55.0,-40.0,35.0,7.0,255,195,77,179,119,0,255,255,255);
   building_1(-68.0,-53.0,32.0,5.0,230,0,115,153,0,77,255,255,255);
   building_1(-30.0,-15.0,35.0,7.0,230,230,0,153,153,0,255,255,255);
   building_1(-43.0,-28.0,28.0,4.0,0,204,68,0,102,34,255,255,255);
   glPopMatrix();

  //drawing hut
   glPushMatrix();
   hut_1();
   glPopMatrix();
   //calling road
   glPushMatrix();
   road();
   glPopMatrix();
   //calling car
   glPushMatrix();
   car_1(-70.0,-45.0,4.5,255,0,0,0,255,0,255,255,255);
   car_1(45.0,70.0,4.5,255,0,0,0,255,0,255,255,255);
   glPopMatrix();
}

void scene_9()
{
       glColor3ub(0,100,0);
       glBegin(GL_POLYGON);
       glVertex2f(-100.0,100.0);
       glVertex2f(-100.0,-100.0);
       glVertex2f(100.0,-100.0);
       glVertex2f(100.0,100.0);
       glEnd();
       glColor3f(1.0,1.0,1.0);
       if(frame>860)
        drawstring(-40.0,20.0,0.0,"Now");
       glColor3f(1.0,1.0,1.0);
       if(frame>865)
        drawstring(-28.0,20.0,0.0,"a");
        glColor3f(1.0,1.0,1.0);
        if(frame>870)
        drawstring(-22.0,20.0,0.0,"days....");
}
//city
void scene_10()
{
   //sky
   glPushMatrix();
   sky_field();
   glPopMatrix();
   //sun
   glPushMatrix();
   sun();
   glPopMatrix();
   //cloud
   glPushMatrix();
   cloud_move();
   cloud();
   glPopMatrix();

   //road
   glPushMatrix();
   road();
   glPopMatrix();

   //calling car
   glPushMatrix();
   car_1(-70.0,-45.0,4.5,255,0,0,0,255,0,255,255,255);
   car_1(45.0,70.0,4.5,255,0,0,0,255,0,255,255,255);
   glPopMatrix();

   //building
   glPushMatrix();
   building_1(-100.0,-85.0,28.0,4.0,169,169,169,120,120,120,255,255,255);
   building_1(-78.0,-63.0,35.0,7.0,0,102,204,0,64,128,255,255,255);
   building_1(-90.0,-75.0,30.0,4.0,232,0,0,168,0,0,255,255,255);
   building_1(-55.0,-40.0,35.0,7.0,255,195,77,179,119,0,255,255,255);
   building_1(-68.0,-53.0,32.0,5.0,230,0,115,153,0,77,255,255,255);
   building_1(-30.0,-15.0,35.0,7.0,230,230,0,153,153,0,255,255,255);
    building_1(-43.0,-28.0,28.0,4.0,0,204,68,0,102,34,255,255,255);
    building_1(-17.0,-02.0,30.0,4.0,198,83,140,153,51,102,255,255,255);
    building_1(85.0,100.0,28.0,4.0,169,169,169,120,120,120,255,255,255);
    building_1(63.0,78.0,35.0,7.0,209,26,255,122,0,153,255,255,255);
    building_1(75.0,90.0,30.0,4.0,230,115,0,153,77,0,255,255,255);
     building_1(40.0,55.0,35.0,7.0,0,102,204,0,64,128,255,255,255);
     building_1(53.0,68.0,32.0,5.0,232,0,0,168,0,0,255,255,255);
    building_1(15.0,30.0,35.0,7.0,255,195,77,179,119,0,255,255,255);
    building_1(28.0,43.0,28.0,4.0,230,0,115,153,0,77,255,255,255);
    building_1(02.0,17.0,30.0,4.0,230,230,0,153,153,0,255,255,255);
   glPopMatrix();
}

//ending
void scene_13()
{
       glColor3f(0.0,0.0,0.0);
       glBegin(GL_POLYGON);
       glVertex2f(-100.0,100.0);
       glVertex2f(-100.0,-100.0);
       glVertex2f(100.0,-100.0);
       glVertex2f(100.0,100.0);
       glEnd();
       glColor3f(1.0,1.0,1.0);
       if(frame>1060)
        drawstring(-65.0,60.0,0.0,"Due to Population explosion, deforestation, river filling and other environmental hazards which are");
       glColor3f(1.0,1.0,1.0);
       if(frame>1065)
        drawstring(-65.0,50.0,0.0,"done by humans are eventually destroying the beauty of our country as well as our precious world.");
       glColor3f(1.0,1.0,1.0);
       if(frame>1070)
        drawstring(-65.0,40.0,0.0,"What we can do is, control the deforestation and implant more and more plants and also prevent");
        glColor3f(1.0,1.0,1.0);
        if(frame>1075)
        drawstring(-65.0,30.0,0.0,"filling the rivers illegally to save our country.");
        glColor3f(1.0,1.0,1.0);
        if(frame>1080)
        drawstring(-65.0,20.0,0.0,"Our small initiative can bring a beautiful new world to our successors....");
}
void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();
   if(frame<55)
   {
     scene_1();
   }
   else if(frame==55 || frame>55 && frame<85)
   {
       scene_14();
   }
    else if(frame==85|| frame>85 && frame<255)
   {
     scene_2();
   }
   else if(frame==255||frame>255 && frame<285)
   {
       scene_3();
   }
   else if(frame==285 || frame>285 && frame<455)
   {
       scene_4();
   }
   else if(frame==455 || frame>455 && frame<485)
   {
       scene_5();
   }
   else if(frame==485 || frame>485 && frame<655)
   {
       scene_6();
   }
   else if(frame==655 || frame>655 && frame<685)
   {
       scene_7();
   }
   else if(frame==685 || frame>685 && frame<855)
   {
       scene_8();
   }
   else if(frame==855 || frame>855 && frame<885)
   {
       scene_9();
   }
   else if(frame==885 || frame>885 && frame<1055)
   {
       scene_10();
   }
   else
   {
       scene_13();
   }
    frame++;
    glutSwapBuffers();
}
//timer function
void Timer(int iUnused)
{
    glutPostRedisplay();
    glutTimerFunc(80, Timer, 0);
}
//reshape function
void reshape(int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);// the value of x,y and z axis in the screen
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}
//main function
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB|GLUT_DEPTH);
   glutInitWindowSize (1000,1400);
   glutInitWindowPosition (0,0);
   glutCreateWindow ("hello");
   init();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   Timer(0);
   glutMainLoop();
   return 0;
}
