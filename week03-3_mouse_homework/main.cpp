#include <GL/glut.h>
#include <stdio.h>
float X=0, Y=0 , Z=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_POLYGON);

    glVertex2f(-0.37, 0.41);
    glVertex2f(-0.21, 0.51);
    glVertex2f(0.12, 0.47);
    glVertex2f(0.45, 0.28);
    glVertex2f(0.32, -0.11);
    glVertex2f(-0.01, -0.29);
    glVertex2f(-0.27, -0.12);
    glVertex2f(-0.32, 0.03);

    glEnd();
    glutSwapBuffers();
}
void mouse(int button , int state , int x,int y)
{
    X = (x-150)/150.0;
    Y = -(y-150)/150.0;
    if(state==GLUT_DOWN) printf("    glVertex2f(%.2f, %.2f);\n",X,Y);
}
int main(int argc, char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03");

    glutMouseFunc(mouse);
    glutDisplayFunc(display);

    glutMainLoop();
}
