
#include<windows.h>
#include <GL/glut.h>
#include<math.h>

double a=50.0,b=50.0,c=300.0,d=300.0;
void DDA(){
double dx=c-a,dy=d-b;
double num_of_steps=dx;
if (dx<dy) {
    num_of_steps=dy;
}
double x=a,y=b;
double xinc=dx / num_of_steps, yinc= dy / num_of_steps;
glClearColor(0,0,0,0);
glPointSize(3);
glColor3f(1,0,0);
glBegin(GL_POINTS);
glVertex2d(x,y);
for (int i=0; i< num_of_steps ; i++) {
    x+=xinc;
    y+=yinc;
    glVertex2d(round(x),round(y));
}
glEnd();
glFlush();
glFinish();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("DDA Line");
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(10,10);
    glOrtho(0,400,0,400,-1,1);

    glutDisplayFunc(DDA);

    glutMainLoop();

    return 0;
}
