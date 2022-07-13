#include<windows.h>
//#include<C:\Users\Jesus\Desktop\ciclo 2-2017\compu grafica\GLUT\include\GL\glut.h>
#include "..\GLUT\include\GL\glut.h"
#include <math.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include "bitmap.h"
using namespace std;

///////////////////////////////////
BITMAPINFO *TexInfo; /* Texture bitmap information */
GLubyte *TexBits; /* Texture bitmap pixel bits */
///////////////////////////////////
char sound[]="..\\Colision_Ping_Pong.wav";
int vidas=3;
float posicionBarra=0.0;
float posicionPelota[2]={0.0,-26.0};
float direccion[2];
int ladrilloActivo[45]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
float posicionLadrillo[45][2]={
-24.0,25.0,
-18.0,25.0,
-12.0,25.0,
-6.0,25.0,
0.0,25.0,
6.0,25.0,
12.0,25.0,
18.0,25.0,
24.0,25.0,
-24.0,23.0,
-18.0,23.0,
-12.0,23.0,
-6.0,23.0,
0.0,23.0,
6.0,23.0,
12.0,23.0,
18.0,23.0,
24.0,23.0,
-24.0,21.0,
-18.0,21.0,
-12.0,21.0,
-6.0,21.0,
0.0,21.0,
6.0,21.0,
12.0,21.0,
18.0,21.0,
24.0,21.0,
-24.0,19.0,
-18.0,19.0,
-12.0,19.0,
-6.0,19.0,
0.0,19.0,
6.0,19.0,
12.0,19.0,
18.0,19.0,
24.0,19.0,
-24.0,17.0,
-18.0,17.0,
-12.0,17.0,
-6.0,17.0,
0.0,17.0,
6.0,17.0,
12.0,17.0,
18.0,17.0,
24.0,17.0
};
int total=100;


void inicio()
{

    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glOrtho(-32.0,32.0,-32.0,35.0,-1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}
///////////////////////////////////////////////
void dibujado()
{

if(vidas>0 && total!=0){
    total=0;
glClear(GL_COLOR_BUFFER_BIT);
///////////////////////////////
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
TexBits = LoadDIBitmap("C:\\Users\\Jesus\\Desktop\\ciclo 2-2017\\compu grafica\\Ladrillos.bmp", &TexInfo);
glTexImage2D(GL_TEXTURE_2D, 0, 3, TexInfo->bmiHeader.biWidth,
TexInfo->bmiHeader.biHeight, 0, GL_BGR_EXT,
GL_UNSIGNED_BYTE, TexBits);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

//se activa el mapeado de texturas
glEnable(GL_TEXTURE_2D);
glBegin(GL_POLYGON);
glTexCoord2f(0.0, 0.0);
glVertex2f(-32.0, 35.0);
glTexCoord2f(1.0, 0.0);
glVertex2f(-32.0, -32.0);
glTexCoord2f(1.0, 1.0);
glVertex2f(32.0, -32.0);
glTexCoord2f(0.0, 1.0);
glVertex2f(32.0, 35.0);
glEnd();
glDisable(GL_TEXTURE_2D);
//////////////////////////////
for(int j=0;j<=45; j++)
    {
    total=total+ladrilloActivo[j];
    }

glBegin(GL_QUADS);
glColor3f(1,0,0);
glVertex2f(-31.0,-30.0);glVertex2f(-31.0,-31.0);
glVertex2f(31.0,-31.0);glVertex2f(31.0,-30.0);
glVertex2f(30.0,30.0);glVertex2f(30.0,-30.0);
glVertex2f(31.0,-30.0);glVertex2f(31.0,31.0);
glVertex2f(-31.0,31.0);glVertex2f(-31.0,30.0);
glVertex2f(31.0,30.0);glVertex2f(31.0,31.0);
glVertex2f(-31.0,30.0);glVertex2f(-31.0,-30.0);
glVertex2f(-30.0,-30.0);glVertex2f(-30.0,30.0);
glEnd();
for(int i=1;i<=vidas;i=i+1){
glPushMatrix();
glTranslated(31.0-i*3,33.0,0.0);
glBegin(GL_LINES);
glColor3f(0.0,1.0,0.0);
for(float i=0; i<=2*3.1416; i=i+0.0001)
{
    glVertex2f(0.0,0.0);
    glVertex2f(cos(i),sin(i));
}

glEnd();
glPopMatrix();

}



glPushMatrix();
glTranslated(posicionBarra,0,0);
glBegin(GL_QUADS);
glColor3f(1.0,1.0,1.0);
glVertex2f(-4,-27);
glVertex2f(-4,-28);
glVertex2f(4,-28);
glVertex2f(4,-27);
glEnd();
glPopMatrix();




for(int i=0; i<45; i++)
{
if(ladrilloActivo[i]==1)
{
glPushMatrix();
glTranslated(posicionLadrillo[i][0],posicionLadrillo[i][1],0.0);
            glBegin(GL_QUADS);
            glColor3f(0.3,0.7,0.4);
            glVertex2f(-3,1);
            glVertex2f(-3,-1);
            glVertex2f(3,-1);
            glVertex2f(3,1);
            glEnd();
glPopMatrix();
}

}
glPushMatrix();
glTranslated(posicionPelota[0],posicionPelota[1],0.0);
glBegin(GL_LINES);
glColor3f(1.0,1.0,1.0);
for(float i=0; i<=2*3.1416; i=i+0.0001)
{
    glVertex2f(0.0,0.0);
    glVertex2f(cos(i),sin(i));
}

glEnd();
glPopMatrix();


glutSwapBuffers();
}
}

//////////////////////////////////

int pass=0;

void movimiento_bola()
{
if (!pass)
{
srand(time(NULL));
pass = 1;
}
direccion[0]=rand()/4;
direccion[1]=rand();
float modDireccion=sqrt(direccion[0]*direccion[0]+direccion[1]*direccion[1]);
direccion[0]=direccion[0]/modDireccion;
direccion[1]=direccion[1]/modDireccion;

}

void testBola()
{
if( posicionPelota[1] <=-29)
{posicionPelota[0]=0.0;
posicionPelota[1]=-26.0;
posicionBarra=0.0;
direccion[0]=rand()/4;
direccion[1]=rand();
float modDireccion=sqrt(direccion[0]*direccion[0]+direccion[1]*direccion[1]);
direccion[0]=direccion[0]/modDireccion;
direccion[1]=direccion[1]/modDireccion;
vidas=vidas-1;
}

if((posicionPelota[0] < -28 || posicionPelota[0] > 28))
{direccion[0]=(-1)*direccion[0];}
if((posicionPelota[1] < -26 && posicionPelota[0]>=posicionBarra-4 && posicionPelota[0]<=posicionBarra+4  )
   || (posicionPelota[1] > 28))
{direccion[1]=(-1)*direccion[1];}
for(int j=0; j<45; j++)
{
if(posicionPelota[1]>=posicionLadrillo[j][1]-2 && posicionPelota[1]<=posicionLadrillo[j][1]+2 && posicionPelota[0]>=posicionLadrillo[j][0]-4 && posicionPelota[0]<=posicionLadrillo[j][0]+4 && ladrilloActivo[j]==1)
{
if(posicionPelota[0]-direccion[0]<=posicionLadrillo[j][0]-4 || posicionPelota[0]-direccion[0]>=posicionLadrillo[j][0]+4)
{
direccion[0]=(-1)*direccion[0];
}
if(posicionPelota[1]-direccion[1]<=posicionLadrillo[j][1]-2 || posicionPelota[1]-direccion[1]>=posicionLadrillo[j][1]+2)
{
direccion[1]=(-1)*direccion[1];
}
cout<<PlaySound((LPCSTR)sound,NULL,SND_FILENAME | SND_ASYNC);
ladrilloActivo[j]=0;
}
}


posicionPelota[0]=posicionPelota[0]+direccion[0]*0.8;
posicionPelota[1]=posicionPelota[1]+direccion[1]*0.8;

//usleep(33);
glutPostRedisplay();
}

void movimiento_barra(unsigned char key,int x, int y)
{
switch (key)
{
case 'a': (posicionBarra>-27)?posicionBarra=posicionBarra-4.5:0;
break;
case 'd': (posicionBarra<27)?posicionBarra=posicionBarra+4.5:0;
break;
}
glutPostRedisplay();
}





void pantalla()
{



glMatrixMode(GL_MODELVIEW);

dibujado();

glFlush();

}





int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(1400,1000);
    glutInitWindowPosition(10,10);


    glutCreateWindow("No me gustan los titulos, llamen a un psicologo");
    inicio();
    movimiento_bola();
    glutIdleFunc(testBola);

    glutDisplayFunc(pantalla);

    glutKeyboardFunc(movimiento_barra);
    glutMainLoop();



    return EXIT_SUCCESS;
}
