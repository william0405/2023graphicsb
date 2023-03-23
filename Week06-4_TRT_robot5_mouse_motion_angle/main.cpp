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

        glPushMatrix();  ///右邊的
            glTranslatef(0.25,0,0);
            glRotatef(angle,0,0,1);
            glTranslatef(0.25,0,0);
            myCube(); ///上手臂
            glPushMatrix();
                glTranslatef(0.25,0,0);
                glRotatef(angle,0,0,1);
                glTranslatef(0.25,0,0);
                myCube();///下手肘
            glPopMatrix();
        glPopMatrix();

        glPushMatrix();  ///左邊的
            glTranslatef(-0.25,0,0);
            glRotatef(-angle,0,0,1);
            glTranslatef(-0.25,0,0);
            myCube(); ///上手臂
            glPushMatrix();
                glTranslatef(-0.25,0,0);
                glRotatef(-angle,0,0,1);
                glTranslatef(-0.25,0,0);
                myCube();///下手肘
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


    glutMotionFunc(motion);///新增mouse motion
    glutMouseFunc(mouse);///新增 mouse函式
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
}

