//TUGAS BESAR GRAFKOM  IF-8 BANGUNAN 3D
/* 

Sandi Satriawan - 10108422 
Reyza Gamaresa - 10108388 
Sugiri - 10108418
Aditya Rinaldi - 10108420

*/

#include "stdlib.h"
#include "gl/glut.h"

int w=600, h=600, z=0;
int x1=0, y1=0, sudut=0, z1=0;
float skalaX=1, skalaY=1, skalaZ=1;
int cx, cy;

void myKeyboard(unsigned char key, int x, int y){
 if (key =='a') z+=5;
 else if (key == 'd') z-=5;
 else if (key == 'w') {
  x1=1;
  y1=0;
  z1=0;
  sudut+=10;
 }
 else if (key == 's') {
  y1=1;
  x1=0;
  z1=0;
  sudut+=-10;
 }
 else if (key == 'q') {
  y1=0;
  x1=0;
  z1=1;
  sudut+=-10;
 }
}

void init(){
 GLfloat LightPosition[] = {10.0f, 10.0f, 20.0f, 0.0f};
 GLfloat LightAmbient[] = {0.0f, 1.0f, 0.0f, 1.0f};
 GLfloat LightDiffuse[] = {0.7f, 0.7f, 0.7f, 1.0f};
 GLfloat LightSpecular[] = {0.5f, 0.5f, 0.5f, 1.0f};
 GLfloat Shine[] = { 80 };

 glShadeModel(GL_SMOOTH);
 glClearColor(0.0f,0.0f,0.0f,0.5f);
 glClearDepth(1.0f);
 glEnable(GL_DEPTH_TEST);
 glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

 glMaterialfv(GL_FRONT, GL_SPECULAR, LightSpecular);
 glMaterialfv(GL_FRONT, GL_SHININESS, Shine);

 glEnable(GL_LIGHTING);
 glEnable(GL_LIGHT0);
 return;

}



void renderScene(void){
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glClearColor(1,1,1,1);

 glLoadIdentity();
 glTranslatef(0,0,z);
 glRotatef(sudut,x1,y1,z1);
 glScalef(skalaX, skalaY, skalaZ);
 
 //tembok
 glPushMatrix();
 glEnable(GL_COLOR_MATERIAL);
 glColor3f(0,1,4.5);
 glRotatef(50,0,1,0);
 glutSolidCube(3);
 glDisable(GL_COLOR_MATERIAL);



 //pintu
glPushMatrix();
glEnable(GL_COLOR_MATERIAL);
glColor3f(0.5,1.8,0);
glTranslatef(-0.6,-1,1.46);
glScalef(7,10,1);
glutSolidCube(0.1);
glDisable(GL_COLOR_MATERIAL);
glPopMatrix();

//jendela
glPushMatrix();
glEnable(GL_COLOR_MATERIAL);
glColor3f(0.5,0.8,0);
glTranslatef(0.5,0.1,1.46);
glScalef(3,3,1);
glutSolidCube(0.1);
glDisable(GL_COLOR_MATERIAL);
glPopMatrix();

glPushMatrix();
glEnable(GL_COLOR_MATERIAL);
glColor3f(0.5,0.8,0);
glTranslatef(0.9,0.1,1.46);
glScalef(3,3,1);
glutSolidCube(0.1);
glDisable(GL_COLOR_MATERIAL);
glPopMatrix();

glPushMatrix();
glEnable(GL_COLOR_MATERIAL);
glColor3f(0.5,0.8,0);
glTranslatef(0.9,-0.3,1.46);
glScalef(3,3,1);
glutSolidCube(0.1);
glDisable(GL_COLOR_MATERIAL);
glPopMatrix();

glPushMatrix();
glEnable(GL_COLOR_MATERIAL);
glColor3f(0.5,0.8,0);
glTranslatef(0.5,-0.3,1.46);
glScalef(3,3,1);
glutSolidCube(0.1);
glDisable(GL_COLOR_MATERIAL);
glPopMatrix();

glPopMatrix();
 

//atap
 glPushMatrix();
 glEnable(GL_COLOR_MATERIAL);
 glColor3f(0.8,0,0);
 glRotatef(5,0,1,0);
 glTranslatef(0,1.5,0);
 glScalef(3,1.3,3);
 glutSolidOctahedron();
 glDisable(GL_COLOR_MATERIAL);
 glPopMatrix();


 glutSwapBuffers();
}

void resize(int w1, int h1){
 glViewport(0,0,w1,h1);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluPerspective(45.0,(float) w1/(float) h1, 1.0,300.0);
 glMatrixMode(GL_MODELVIEW); 
 glLoadIdentity();
}

void timer(int value){
 glutPostRedisplay();
 glutTimerFunc(50,timer,0);
}

main (int argc, char **argv){
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
 glutInitWindowPosition(100,100);
 glutInitWindowSize(w,h);
 glutCreateWindow("Rumah");
 glutDisplayFunc(renderScene);
 glutReshapeFunc(resize);
 glutKeyboardFunc(myKeyboard);
 glutTimerFunc(1,timer,0);
 init();
 glutMainLoop();
}
