#include <GL/glut.h>
float angle=0;
void myCube()
{
    glPushMatrix();
        glScalef(1,0.3,0.3);
        glutSolidCube(0.5);
    glPopMatrix();

}
void display()
{
        glColor3f(1,1,1);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

        glutSolidSphere(0.01,30,30);

        glPushMatrix();  ///�k�䪺
            glTranslatef(0.25,0,0);
            glRotatef(angle,0,0,1);
            glTranslatef(0.25,0,0);
            myCube(); ///�W���u
            glPushMatrix();
                glTranslatef(0.25,0,0);
                glRotatef(angle,0,0,1);
                glTranslatef(0.25,0,0);
                myCube();///�U��y
            glPopMatrix();
        glPopMatrix();

        glPushMatrix();  ///���䪺
            glTranslatef(-0.25,0,0);
            glRotatef(-angle,0,0,1);
            glTranslatef(-0.25,0,0);
            myCube(); ///�W���u
            glPushMatrix();
                glTranslatef(-0.25,0,0);
                glRotatef(-angle,0,0,1);
                glTranslatef(-0.25,0,0);
                myCube();///�U��y
            glPopMatrix();
        glPopMatrix();

        glutSwapBuffers();
       /// angle++;
}
int oldX=0;
void mouse(int button ,int state ,int x , int y)
{
    oldX=x;
}
void motion(int x,int y)
{
    angle += (x-oldX);
    oldX=x;
}

int main(int argc,char* argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week06");


    glutMotionFunc(motion);///�s�Wmouse motion
    glutMouseFunc(mouse);///�s�W mouse�禡
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
}

