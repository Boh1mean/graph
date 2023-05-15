#ifdef __APPLE__
/* Defined before OpenGL and GLUT includes to avoid deprecation messages */
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif
#include <iostream>
#include <cmath>
#include <array>

void firstScece(){ // Главный фон
    glColor3ub(50, 65, 74);
    glBegin(GL_QUADS);
    glVertex2f(-1, 1);
    glVertex2f(1, 1);
    glVertex2f(1, -1);
    glVertex2f(-1, -1);
    glEnd();
    
}
void makeAxes()
{
glBegin(GL_LINES);
glVertex2f(-1.0f, 0.0f);
glVertex2f(1.0f, 0.0f);
glVertex2f(0.0f, -1.0f);
glVertex2f(0.0f, 1.0f);
glEnd();

}

void nameAxes()
{
for (float x = -1.0f; x <= 1.0f; x += 0.1f) {
glRasterPos2f(x, -0.05f);
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, '|');
glRasterPos2f(x, 0.05f);
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, '|');
}
for (float y = -1.0f; y <= 1.0f; y += 0.1f) {
glRasterPos2f(-0.05f, y);
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, '-');
glRasterPos2f(0.05f, y);
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, '-');
}
}

void drawGraph()
{
glBegin(GL_LINE_STRIP);
for (float x = 0.1f; x <= 1.0f; x += 0.1f) {
float y = 1.0f / x;
glVertex2f(x, y);
}
glEnd();
}

void display() {
glClear(GL_COLOR_BUFFER_BIT);
    firstScece();
makeAxes();
nameAxes();
drawGraph();
    
}

int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitWindowSize(400, 400);
glutCreateWindow("Function Graph");
glutDisplayFunc(display);
glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
glutMainLoop();
}
