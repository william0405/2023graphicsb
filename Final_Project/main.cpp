#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;
GLMmodel * body = NULL;
GLMmodel * left_u_arm =NULL;
GLMmodel * left_d_arm = NULL;
int ID = 2;
int show[4]={1,0,0,0};
float teapotX = 0 ,teapotY = 0;
FILE * fout = NULL;
FILE * fin = NULL;
float angle = 0;
void keyboard(unsigned char key , int x , int y)
{
    if(key=='0') show[0] = !show[0];
    if(key=='1') show[1] = !show[1];
    if(key=='2') show[2] = !show[2];
    if(key=='3') show[3] = !show[3];
    glutPostRedisplay();
}
void display()
{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        if(head==NULL)
        {
          head = glmReadOBJ("model/head.obj");
          body = glmReadOBJ("model/body.obj");
          left_u_arm = glmReadOBJ("model/uparmR.obj");
          left_d_arm = glmReadOBJ("model/lowarmR.obj");
         /// glmUnitize(head);
        }
        glPushMatrix();
            glScalef(0.3 , 0.3 , 0.3);
            glPushMatrix();
               /// glTranslated(teapotX , teapotY , 0);
               glTranslatef(0.013333, 0.686666, 0);
               glRotatef(angle,0,0,1);
               glTranslatef(-0.013333, -0.686666, 0);
               if(ID==0)glColor3f(1,0,0);
                else glColor3f(1,1,1);
                if(show[0]) glmDraw(head , GLM_MATERIAL);

                if(ID==1)glColor3f(1,0,0);
                else glColor3f(1,1,1);
                if(show[1])glmDraw(body , GLM_MATERIAL);
                glTranslatef(-0.000000, 0.273333, 0);
                glRotatef(angle,0,0,1);
                glTranslatef(0.000000, -0.273333, 0);


                if(ID==2)glColor3f(1,0,0);
                else glColor3f(1,1,1);
                if(show[2])glmDraw(left_u_arm , GLM_MATERIAL);
                 glTranslated(teapotX , teapotY , 0);

                if(ID==3)glColor3f(1,0,0);
                else glColor3f(1,1,1);
                if(show[3])glmDraw(left_d_arm , GLM_MATERIAL);
        glPopMatrix();
        glPopMatrix();
        glColor3f(0,1,0);
        glutSolidTeapot(0.02);
        glutSwapBuffers();
}
int oldX=0 , oldY=0;
void mouse(int button , int state , int x, int y)
{
    if(state==GLUT_DOWN)
    {
        oldX = x;
        oldY = y;
    }
}
void motion(int x, int y)
{
    teapotX += (x - oldX)/150.0;
    teapotY -= (y-oldY)/150.0;
    printf("glTranslatef(%f, %f, 0);\n",teapotX,teapotY);
    angle += x-oldX;
    oldX = x;
    oldY = y;
    glutPostRedisplay();
}
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week14");

    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);


    glutMainLoop();
}
