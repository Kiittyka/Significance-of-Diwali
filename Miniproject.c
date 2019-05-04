#include<GL/glut.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include "Image.h"
#define PI 3.1416

typedef struct {
    GLfloat x;
    GLfloat y;
    GLfloat z;
    GLfloat arr[3];
}point3;

int glob=0,cur_win=1;
int showIntro = 1, aaglob=1;
int n,i,bi,flag;
int s,x=0;
float x1,y11,x2,y2,x3,y3,x4,y4;
float angle,a=0,b=0,m=0;
double radius;

void intro();
void day();
void road();
void night();
void diyas();
void diyas_night();
void drawtree();
void drawtree2();
void tulsi();
void lantern();
void tulsi_night();
void fireworks();
void blast();
void spin();
void cracker();
void cloud();
void ravan();
void heads();
void ravan_weapon1();
void ravan_weapon2();
void rama();
void rama_hair();
void fire();
void dahan();
void arrow();
void moving_arrow();
void boyhead();
void girlhead();
void trees();
void bush(int x,int y,int r);
void circle_draw(GLint h,GLint k,GLint r);
void circle(GLdouble rad);
void plotpixels(GLint h,GLint k,GLint x,GLint y);
void drawStrokeText(char *string, point3 p, GLfloat size);
void drawstring(float x,float y,float z,char *string);
void display();
void mainmenu(int id);
void init();
void keyPressed( unsigned char key, int x, int y );
int main(int argc,char** argv);

point3 createPoint3D(GLfloat x, GLfloat y, GLfloat z) {
    point3 p;
    p.x = x;
    p.y = y;
    p.z = z;
    p.arr[0] = x;
    p.arr[1] = y;
    p.arr[2] = z;
    return p;
} 
void drawStrokeText(char *string, point3 p, GLfloat size)
{
    char *c;
    glPushMatrix();
    glTranslatef(p.x, p.y, p.z);
    glScalef(0.05f,0.04f, p.z);
    glScalef(size,size,size);
    for (c=string; *c != '\0'; c++) {
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN , *c);
    }
    glPopMatrix();
}
void drawstring(float x,float y,float z,char *string)
{
        char *c;
        glRasterPos3f(x,y,z);
        for(c=string;*c!='\0';c++)
 	        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*c);
}

void intro(){
        if(showIntro==1){
	glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glColor3ub(91,36,122);
                glVertex2f(0,0);
                glVertex2f(2200,0);
        glColor3ub(27,206,223);
                glVertex2f(2200,2200);
                glVertex2f(0,2200);
        glEnd();
        
	glPushMatrix();
	glColor3f(1,1,1);
                glPointSize(1);
	        drawStrokeText("DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING", createPoint3D(250,1900,0),7);
                drawStrokeText("SAHYADRI COLLEGE OF ENGINEERING AND MANAGEMENT - 575 007", createPoint3D(60,1700,0),7);
                drawStrokeText("COMPUTER GRAPHICS PROJECT ON", createPoint3D(560,1500,0),7);
                glColor3f(0,0,0);
                drawStrokeText("SIGNIFICANCE OF DIWALI", createPoint3D(670,1300,0),7);
                glColor3f(1,1,1);
                drawStrokeText("SUBMITTED BY", createPoint3D(250,1100,0),7);
                drawStrokeText("DWITHI D RAI", createPoint3D(250,900,0),7);
                drawStrokeText("KRITHIKA S UDUPA", createPoint3D(250,500,0),7);
                drawStrokeText("4SF15CS046", createPoint3D(250,800,0),7);
                drawStrokeText("4SF15CS065", createPoint3D(250,400,0),7);
		drawStrokeText("VI SEM CSE", createPoint3D(250,700,0),7);
                drawStrokeText("VI SEM CSE", createPoint3D(250,300,0),7);
                drawStrokeText("PROJECT GUIDES:", createPoint3D(1200,1100,0),7);
                drawStrokeText("Mrs.SADHANA", createPoint3D(1200,900,0),7);

                drawStrokeText("Asst.PROFESSOR,DEPARTMENT", createPoint3D(1200,800,0),7);
                drawStrokeText("OF CS&E", createPoint3D(1200,700,0),7);
                drawStrokeText("Mr.SHAILESH SHETTY S", createPoint3D(1200,500,0),7);
                drawStrokeText("Asst.PROFESSOR,DEPARTMENT", createPoint3D(1200,400,0),7);
                drawStrokeText("OF CS&E", createPoint3D(1200,300,0),7);
		drawStrokeText("RIGHT CLICK TO CONTINUE ->", createPoint3D(1500,100,0),4.8);
                glFlush();
       	glPopMatrix();
	        showIntro = 1;
        }
}

void keyPressed( unsigned char key, int x, int y )
{
  if(key == 'z'){
        if(cur_win == 5) {
                exit(0);
        }
	cur_win++;
  }
  
  glutPostRedisplay();
}

void draw_pixel(GLint cx,GLint cy)
{	glPolygonMode(GL_FRONT,GL_FILL);
	glBegin(GL_POINTS);
	glVertex2i(cx,cy);
	glEnd();
}

void plotpixels(GLint h,GLint k,GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
   	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);

	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}

void circle_draw(GLint h,GLint k,GLint r)
{
	GLint d=1-r,x=0,y=r;
	while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0)
			d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}

void rama_hair(){
	x1 = 450,y11 = 1280,radius = 30;
	glColor3f(0.647059,0.164706,0.164706);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1,y11);
	for (angle=1.0f;angle<361.0f;angle+=0.2)
	{
    		x2 = x1+sin(angle)*radius;
   		y2 = y11+cos(angle)*radius;
   		glVertex2f(x2,y2);
	}
	glEnd();	
}

void ravan()
{
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glColor3ub(0,0,0);
                glVertex2f(0,0);
                glVertex2f(2200,0);
        glColor3ub(140,9,9);
                glVertex2f(2200,2200);
                glVertex2f(0,2200);
        glEnd();       
        glColor3f(1,1,1);
        glBegin(GL_POLYGON);
        glColor3f(1,0,0);
	//body
                glVertex2f(1300,1500);
                glVertex2f(1700,1500);
                glVertex2f(1600,1200);
                glVertex2f(1400,1200);
        glEnd();
        glBegin(GL_POLYGON);
                glVertex2f(1200,800);
                glVertex2f(1800,800);
                glVertex2f(1600,1200);
                glVertex2f(1400,1200);
        glEnd();

	//legs
        glBegin(GL_POLYGON);
                glVertex2f(1550,600);
                glVertex2f(1610,600);
                glVertex2f(1610,800);
                glVertex2f(1550,800); 
        glEnd();
        glBegin(GL_POLYGON);
                glVertex2f(1390,600);
                glVertex2f(1450,600);
                glVertex2f(1450,800);
                glVertex2f(1390,800);
        glEnd();

        glBegin(GL_POLYGON);//triangle
        glColor3f(1,0.7,0);
                glVertex2f(1400,1350);
                glVertex2f(1500,1450);
                glVertex2f(1600,1350);
        glEnd();

        glBegin(GL_POLYGON);//shoe
        glColor3f(0.64,0.16,0.16);
                glVertex2f(1550,550);
                glVertex2f(1690,550);
                glVertex2f(1690,600);
                glVertex2f(1670,630);
                glVertex2f(1650,600);
                glVertex2f(1610,600);
                glVertex2f(1550,600);
        glEnd();

        glBegin(GL_POLYGON);//shoe
        glColor3f(0.64,0.16,0.16);
                glVertex2f(1310,550);
                glVertex2f(1450,550);
                glVertex2f(1450,600);
                glVertex2f(1350,600);
                glVertex2f(1330,630);
                glVertex2f(1310,600);
        glEnd();
        
        glBegin(GL_POLYGON);
        glColor3f(0,1,0);
                glVertex2f(1400,1200);
                glVertex2f(1450,950);
                glVertex2f(1500,900);
                glVertex2f(1550,950);
                glVertex2f(1600,1200);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINE_LOOP); //triangle   
        glColor3f(1,0.7,0);
                glVertex2f(1400,1200);
                glVertex2f(1500,1100);
                glVertex2f(1600,1200);
        glEnd();

        glBegin(GL_LINES);
                glVertex2f(1395,1180);
                glVertex2f(1500,1080);
                glVertex2f(1500,1080);
                glVertex2f(1605,1180);
        glEnd(); 

        glBegin(GL_POLYGON);//hands
        glColor3f(1,0,0);
                glVertex2f(1300,1500);
                glVertex2f(1330,1400);
                glVertex2f(1190,1220);
                glVertex2f(1160,1310);
        glEnd(); 
        glBegin(GL_POLYGON);
                glVertex2f(1190,1220);
                glVertex2f(1050,1300);
                glVertex2f(1050,1390);
                glVertex2f(1160,1310);
        glEnd();
        
        glBegin(GL_POLYGON);
        glColor3f(1,0,0);
                glVertex2f(1700,1500);
                glVertex2f(1840,1310);  
                glVertex2f(1810,1220);
                glVertex2f(1670,1400);
        glEnd();
	
        glBegin(GL_POLYGON);
                glVertex2f(1840,1310);
                glVertex2f(1950,1390);
                glVertex2f(1950,1300);
                glVertex2f(1810,1220);
        glEnd();
              
	glBegin(GL_POLYGON);
        glColor3f(0.8,0.4,0.1);//neck
       	        glVertex2f(1465,1580);
	        glVertex2f(1540,1580);
	        glVertex2f(1540,1500);
                glVertex2f(1465,1500);     
	glEnd();   
	rama(); 
	rama_hair();
	//textbox
	glColor3ub(255,255,255);
        glBegin(GL_POLYGON);
                glVertex2f(0,0);
                glVertex2f(2200,0);
                glVertex2f(2200,150);
                glVertex2f(0,150);
        glEnd();   
}

void ravan_weapon1(){
        //sword
        glBegin(GL_POLYGON);
        glColor3f(0.64,0.16,0.16);
                glVertex2f(1010,1380);
                glVertex2f(1030,1340);
                glVertex2f(1050,1350);
                glVertex2f(1030,1390);
        glEnd();
 
        glBegin(GL_POLYGON);
        glColor3f(1,1,1);
                glVertex2f(1010,1380);
                glVertex2f(840,1540);
                glVertex2f(850,1600);
                glVertex2f(910,1580);
                glVertex2f(1030,1390);
        glEnd();
}

void ravan_weapon2(){
         
        //shield
	glPointSize(9.0);
		glColor3f(0.7647,0.7294,0.7294);
	circle_draw(1950,1300,140);
		glColor3f(0.7647,0.7294,0.7294);
	circle_draw(1950,1300,120);
		glColor3f(0.7647,0.7294,0.7294);
	circle_draw(1950,1300,110);
		glColor3f(0.7647,0.7294,0.7294);
	circle_draw(1950,1300,90);
		glColor3f(0.7647,0.7294,0.7294);
	circle_draw(1950,1300,70);
		glColor3f(0.7647,0.7294,0.7294);
	circle_draw(1950,1300,50);
		glColor3f(0.7647,0.7294,0.7294);
	circle_draw(1950,1300,30);
		glColor3f(0.7647,0.7294,0.7294);
	circle_draw(1950,1300,10);
	glColor3ub(128,128,128);
	bush(1950,1200,30);
	bush(1950,1300,30);
	bush(1950,1400,30);
	bush(2050,1300,30);
	bush(1850,1300,30);
	glPointSize(3);
	glColor3f(0,0,0);
	        circle_draw(1950,1200,30);
	        circle_draw(1950,1300,30);
	        circle_draw(1950,1400,30);
	        circle_draw(2050,1300,30);
	        circle_draw(1850,1300,30);
}

void heads(){
        glPushMatrix();
        glBegin(GL_POLYGON);
        glColor3f(0.8,0.4,0.1);//head1
       	        glVertex2f(1430,1580);
                glVertex2f(1500,1550);
                glVertex2f(1570,1580);
                glVertex2f(1570,1700);
                glVertex2f(1430,1700);
	glEnd();

	glBegin(GL_POLYGON);
        glColor3f(0.8,0.4,0.1);//head2
       	        glVertex2f(1570,1580);
                glVertex2f(1640,1550);
                glVertex2f(1710,1580);
                glVertex2f(1710,1700);
                glVertex2f(1570,1700);
	glEnd();
	glBegin(GL_POLYGON);
        glColor3f(0.8,0.4,0.1);//head3
       	        glVertex2f(1710,1580);
                glVertex2f(1780,1550);
                glVertex2f(1850,1580);
                glVertex2f(1850,1700);
                glVertex2f(1710,1700);
	glEnd();
	glBegin(GL_POLYGON);
        glColor3f(0.8,0.4,0.1);//head4
       	        glVertex2f(1850,1580);
                glVertex2f(1920,1550);
                glVertex2f(1990,1580);
                glVertex2f(1990,1700);
                glVertex2f(1850,1700);
	glEnd();
	glBegin(GL_POLYGON);
        glColor3f(0.8,0.4,0.1);//head5
       	        glVertex2f(1990,1580);
                glVertex2f(2060,1550);
                glVertex2f(2130,1580);
                glVertex2f(2130,1700);
                glVertex2f(1990,1700);
	glEnd();
	glBegin(GL_POLYGON);
        glColor3f(0.8,0.4,0.1);//head6
       	        glVertex2f(1290,1580);
                glVertex2f(1360,1550);
                glVertex2f(1430,1580);
                glVertex2f(1430,1700);
                glVertex2f(1290,1700);
	glEnd();
	glBegin(GL_POLYGON);
        glColor3f(0.8,0.4,0.1);//head7
       	        glVertex2f(1150,1580);
                glVertex2f(1220,1550);
                glVertex2f(1290,1580);
                glVertex2f(1290,1700);
                glVertex2f(1150,1700);
	glEnd();
	glBegin(GL_POLYGON);
        glColor3f(0.8,0.4,0.1);//head8
       	        glVertex2f(1010,1580);
                glVertex2f(1080,1550);
                glVertex2f(1150,1580);
                glVertex2f(1150,1700);
                glVertex2f(1010,1700);
	glEnd();
	glBegin(GL_POLYGON);
        glColor3f(0.8,0.4,0.1);//head9
       	        glVertex2f(870,1580);
                glVertex2f(940,1550);
                glVertex2f(1010,1580);
                glVertex2f(1010,1700);
                glVertex2f(870,1700);
	glEnd();
	glBegin(GL_POLYGON);
        glColor3f(0.8,0.4,0.1);//head10
       	        glVertex2f(730,1580);
                glVertex2f(800,1550);
                glVertex2f(870,1580);
                glVertex2f(870,1700);
                glVertex2f(730,1700);
	glEnd();

	 //crown1
        glBegin(GL_POLYGON);
        glColor3f(1,0.7,0);
                glVertex2f(1430,1700);
                glVertex2f(1430,1730);
                glVertex2f(1570,1730);
                glVertex2f(1570,1700);
        glEnd();
        glBegin(GL_POLYGON);
                glVertex2f(1450,1730);
                glVertex2f(1450,1760);
                glVertex2f(1550,1760);
                glVertex2f(1550,1730);
        glEnd();  
        glBegin(GL_POLYGON);
                glVertex2f(1470,1760);
                glVertex2f(1470,1790);
                glVertex2f(1530,1790);
                glVertex2f(1530,1760);
        glEnd();
        glBegin(GL_POLYGON);
                glVertex2f(1480,1790);
                glVertex2f(1500,1830);
                glVertex2f(1520,1790);
        glEnd();

	//crown2
	glBegin(GL_POLYGON);
                glVertex2f(1570,1700);
                glVertex2f(1570,1730);
                glVertex2f(1710,1730);
                glVertex2f(1710,1700);
        glEnd();
        glBegin(GL_POLYGON);
                glVertex2f(1590,1730);
                glVertex2f(1590,1760);
                glVertex2f(1690,1760);
                glVertex2f(1690,1730);
        glEnd();  
        glBegin(GL_POLYGON);
                glVertex2f(1610,1760);
                glVertex2f(1610,1790);
                glVertex2f(1670,1790);
                glVertex2f(1670,1760);
        glEnd();
        glBegin(GL_POLYGON);
                glVertex2f(1620,1790);
                glVertex2f(1640,1830);
                glVertex2f(1660,1790);
        glEnd();

	//crown3
	glBegin(GL_POLYGON);
                glVertex2f(1710,1700);
                glVertex2f(1710,1730);
                glVertex2f(1850,1730);
                glVertex2f(1850,1700);
        glEnd();
        glBegin(GL_POLYGON);
                glVertex2f(1730,1730);
                glVertex2f(1730,1760);
                glVertex2f(1830,1760);
                glVertex2f(1830,1730);
        glEnd();  
        glBegin(GL_POLYGON);
                glVertex2f(1750,1760);
                glVertex2f(1750,1790);
                glVertex2f(1810,1790);
                glVertex2f(1810,1760);
        glEnd();
        glBegin(GL_POLYGON);
                glVertex2f(1760,1790);
                glVertex2f(1780,1830);
                glVertex2f(1800,1790);
        glEnd();
	
	//crown4
	glBegin(GL_POLYGON);
                glVertex2f(1850,1700);
                glVertex2f(1850,1730);
                glVertex2f(1990,1730);
                glVertex2f(1990,1700);
        glEnd();
        glBegin(GL_POLYGON);
                glVertex2f(1870,1730);
                glVertex2f(1870,1760);
                glVertex2f(1970,1760);
                glVertex2f(1970,1730);
        glEnd();  
        glBegin(GL_POLYGON);
                glVertex2f(1890,1760);
                glVertex2f(1890,1790);
                glVertex2f(1950,1790);
                glVertex2f(1950,1760);
        glEnd();
        glBegin(GL_POLYGON);
                glVertex2f(1900,1790);
                glVertex2f(1920,1830);
                glVertex2f(1940,1790);
        glEnd();

	//crown5
	glBegin(GL_POLYGON);
                glVertex2f(1990,1700);
                glVertex2f(1990,1730);
                glVertex2f(2130,1730);
                glVertex2f(2130,1700);
        glEnd();
        glBegin(GL_POLYGON);
                glVertex2f(2010,1730);
                glVertex2f(2010,1760);
                glVertex2f(2110,1760);
                glVertex2f(2110,1730);
        glEnd();  
        glBegin(GL_POLYGON);
                glVertex2f(2030,1760);
                glVertex2f(2030,1790);
                glVertex2f(2090,1790);
                glVertex2f(2090,1760);
        glEnd();
        glBegin(GL_POLYGON);
                glVertex2f(2040,1790);
                glVertex2f(2060,1830);
                glVertex2f(2080,1790);
        glEnd();

	//crown6
	glBegin(GL_POLYGON);
                glVertex2f(1290,1700);
                glVertex2f(1290,1730);
                glVertex2f(1430,1730);
                glVertex2f(1430,1700);
        glEnd();
        glBegin(GL_POLYGON);
                glVertex2f(1310,1730);
                glVertex2f(1310,1760);
                glVertex2f(1410,1760);
                glVertex2f(1410,1730);
        glEnd();  
        glBegin(GL_POLYGON);
                glVertex2f(1330,1760);
                glVertex2f(1330,1790);
                glVertex2f(1390,1790);
                glVertex2f(1390,1760);
        glEnd();
        glBegin(GL_POLYGON);
                glVertex2f(1340,1790);
                glVertex2f(1360,1830);
                glVertex2f(1380,1790);
        glEnd();

	//crown7
	glBegin(GL_POLYGON);
                glVertex2f(1150,1700);
                glVertex2f(1150,1730);
                glVertex2f(1290,1730);
                glVertex2f(1290,1700);
        glEnd();
        glBegin(GL_POLYGON);
                glVertex2f(1170,1730);
                glVertex2f(1170,1760);
                glVertex2f(1270,1760);
                glVertex2f(1270,1730);
        glEnd();  
        glBegin(GL_POLYGON);
                glVertex2f(1190,1760);
                glVertex2f(1190,1790);
                glVertex2f(1250,1790);
                glVertex2f(1250,1760);
        glEnd();
        glBegin(GL_POLYGON);
                glVertex2f(1200,1790);
                glVertex2f(1220,1830);
                glVertex2f(1240,1790);
        glEnd();

	//crown8
	glBegin(GL_POLYGON);       
                glVertex2f(1010,1700);
                glVertex2f(1010,1730);
                glVertex2f(1150,1730);
                glVertex2f(1150,1700);
        glEnd();
        glBegin(GL_POLYGON);       
                glVertex2f(1030,1730);
                glVertex2f(1030,1760);
                glVertex2f(1130,1760);
                glVertex2f(1130,1730);
        glEnd();  
        glBegin(GL_POLYGON);      
                glVertex2f(1050,1760);
                glVertex2f(1050,1790);
                glVertex2f(1110,1790);
                glVertex2f(1110,1760);
        glEnd();
        glBegin(GL_POLYGON);       
                glVertex2f(1060,1790);
                glVertex2f(1080,1830);
                glVertex2f(1100,1790);
        glEnd();

	//crown9
	glBegin(GL_POLYGON);
                glVertex2f(870,1700);
                glVertex2f(870,1730);
                glVertex2f(1010,1730);
                glVertex2f(1010,1700);
        glEnd();
        glBegin(GL_POLYGON);
                glVertex2f(890,1730);
                glVertex2f(890,1760);
                glVertex2f(990,1760);
                glVertex2f(990,1730);
        glEnd();  
        glBegin(GL_POLYGON);
                glVertex2f(910,1760);
                glVertex2f(910,1790);
                glVertex2f(970,1790);
                glVertex2f(970,1760);
        glEnd();
        glBegin(GL_POLYGON);
                glVertex2f(920,1790);
                glVertex2f(940,1830);
                glVertex2f(960,1790);
        glEnd();

	//crown10
	glBegin(GL_POLYGON);
                glVertex2f(730,1700);
                glVertex2f(730,1730);
                glVertex2f(870,1730);
                glVertex2f(870,1700);
        glEnd();
        glBegin(GL_POLYGON);
                glVertex2f(750,1730);
                glVertex2f(750,1760);
                glVertex2f(850,1760);
                glVertex2f(850,1730);
        glEnd();  
        glBegin(GL_POLYGON);
                glVertex2f(770,1760);
                glVertex2f(770,1790);
                glVertex2f(830,1790);
                glVertex2f(830,1760);
        glEnd();
        glBegin(GL_POLYGON);
                glVertex2f(780,1790);
                glVertex2f(800,1830);
                glVertex2f(820,1790);
        glEnd();

	glPointSize(9);
        glBegin(GL_POINTS);//eyes1
        glColor3f(0,0,0);
                glVertex2f(1470,1650);
                glVertex2f(1530,1650);
        glEnd();
	glBegin(GL_POINTS);//eyes2
                glVertex2f(1610,1650);
                glVertex2f(1670,1650);
        glEnd();
	glBegin(GL_POINTS);//eyes3
                glVertex2f(1750,1650);
                glVertex2f(1810,1650);
        glEnd();
	glBegin(GL_POINTS);//eyes4
                glVertex2f(1890,1650);
                glVertex2f(1950,1650);
        glEnd();
	glBegin(GL_POINTS);//eyes5
                glVertex2f(2030,1650);
                glVertex2f(2090,1650);
        glEnd();
	glBegin(GL_POINTS);//eyes6
                glVertex2f(1330,1650);
                glVertex2f(1390,1650);
        glEnd();
	glBegin(GL_POINTS);//eyes7
                glVertex2f(1190,1650);
                glVertex2f(1250,1650);
        glEnd();
	glBegin(GL_POINTS);//eyes8
                glVertex2f(1050,1650);
                glVertex2f(1110,1650);
        glEnd();
	glBegin(GL_POINTS);//eyes9
                glVertex2f(910,1650);
                glVertex2f(970,1650);
        glEnd();
	glBegin(GL_POINTS);//eyes10
                glVertex2f(770,1650);
                glVertex2f(830,1650);
        glEnd();

        glBegin(GL_POLYGON);//moustache1
        glColor3f(0,0,0);
                glVertex2f(1500,1600);
                glVertex2f(1500,1620);
                glVertex2f(1550,1580);
        glEnd(); 
        glBegin(GL_POLYGON);
                glVertex2f(1500,1600);
                glVertex2f(1500,1620);
                glVertex2f(1450,1580);
        glEnd();

	glBegin(GL_POLYGON);//moustache2
                glVertex2f(1640,1600);
                glVertex2f(1640,1620);
                glVertex2f(1690,1580);
        glEnd(); 
        glBegin(GL_POLYGON);
                glVertex2f(1640,1600);
                glVertex2f(1640,1620);
                glVertex2f(1590,1580);
        glEnd();

	glBegin(GL_POLYGON);//moustache3
                glVertex2f(1780,1600);
                glVertex2f(1780,1620);
                glVertex2f(1830,1580);
        glEnd(); 
        glBegin(GL_POLYGON);
                glVertex2f(1780,1600);
                glVertex2f(1780,1620);
                glVertex2f(1730,1580);
        glEnd();

	glBegin(GL_POLYGON);//moustache4
                glVertex2f(1920,1600);
                glVertex2f(1920,1620);
                glVertex2f(1970,1580);
        glEnd(); 
        glBegin(GL_POLYGON);
                glVertex2f(1920,1600);
                glVertex2f(1920,1620);
                glVertex2f(1870,1580);
        glEnd();

	glBegin(GL_POLYGON);//moustache5
                glVertex2f(2060,1600);
                glVertex2f(2060,1620);
                glVertex2f(2110,1580);
        glEnd(); 
        glBegin(GL_POLYGON);
                glVertex2f(2060,1600);
                glVertex2f(2060,1620);
                glVertex2f(2010,1580);
        glEnd();

	glBegin(GL_POLYGON);//moustache6
                glVertex2f(1360,1600);
                glVertex2f(1360,1620);
                glVertex2f(1410,1580);
        glEnd(); 
        glBegin(GL_POLYGON);
                glVertex2f(1360,1600);
                glVertex2f(1360,1620);
                glVertex2f(1310,1580);
        glEnd();
	
	glBegin(GL_POLYGON);//moustache7
                glVertex2f(1220,1600);
                glVertex2f(1220,1620);
                glVertex2f(1270,1580);
        glEnd(); 
        glBegin(GL_POLYGON);
                glVertex2f(1220,1600);
                glVertex2f(1220,1620);
                glVertex2f(1170,1580);
        glEnd();

	glBegin(GL_POLYGON);//moustache8
                glVertex2f(1080,1600);
                glVertex2f(1080,1620);
                glVertex2f(1130,1580);
        glEnd(); 
        glBegin(GL_POLYGON);
                glVertex2f(1080,1600);
                glVertex2f(1080,1620);
                glVertex2f(1030,1580);
        glEnd();

	glBegin(GL_POLYGON);//moustache9
                glVertex2f(940,1600);
                glVertex2f(940,1620);
                glVertex2f(990,1580);
        glEnd(); 
        glBegin(GL_POLYGON);
                glVertex2f(940,1600);
                glVertex2f(940,1620);
                glVertex2f(890,1580);
        glEnd();

	glBegin(GL_POLYGON);//moustache10
                glVertex2f(800,1600);
                glVertex2f(800,1620);
                glVertex2f(850,1580);
        glEnd(); 
        glBegin(GL_POLYGON);
                glVertex2f(800,1600);
                glVertex2f(800,1620);
                glVertex2f(750,1580);
        glEnd();

	//partition
	glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(0,0,0);
        glVertex2f(1430,1580);
        glVertex2f(1430,1730);

	glVertex2f(1570,1580);
        glVertex2f(1570,1730);

	glVertex2f(1710,1580);
        glVertex2f(1710,1730);

	glVertex2f(1850,1580);
        glVertex2f(1850,1730);

	glVertex2f(1990,1580);
        glVertex2f(1990,1730);

	glVertex2f(1430,1580);
        glVertex2f(1430,1730);

	glVertex2f(1570,1580);
        glVertex2f(1570,1730);

	glVertex2f(1290,1580);
        glVertex2f(1290,1730);

	glVertex2f(1150,1580);
        glVertex2f(1150,1730);
	
	glVertex2f(1010,1580);
        glVertex2f(1010,1730);

	glVertex2f(870,1580);
        glVertex2f(870,1730);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(0,0,0);
	        glLineWidth(1);
	        glVertex2f(1430,1580);
                glVertex2f(1500,1550);
	        glVertex2f(1570,1580);
	        glVertex2f(1500,1550);
	glEnd();	
	glPopMatrix();	
}

void rama(){
        glBegin(GL_POLYGON);
        glColor3f(1,0,0);
                glVertex2f(350,700);
                glVertex2f(550,700);
                glVertex2f(590,100);
                glVertex2f(310,100);
        glEnd();	

	glPushMatrix();//dhoti
	glLineWidth(1);
        glBegin(GL_LINES);        
	glColor3ub(132,6,6);
                glVertex2f(450,700);
                glVertex2f(450,100);
                glVertex2f(450,700);
                glVertex2f(430,100);
                glVertex2f(450,700);
                glVertex2f(410,100);
                glVertex2f(450,700);
                glVertex2f(470,100);
                glVertex2f(450,700);
                glVertex2f(490,100);
        glEnd();
	glPopMatrix();
        
        //backpack
        glBegin(GL_POLYGON);
        glColor3ub(168,151,151);   
                glVertex2f(400,1000);
                glVertex2f(300,1200);
                glVertex2f(200,1100);
                glVertex2f(320,900);
        glEnd();
        
        glBegin(GL_POLYGON);//chest
        glColor3ub(121,139,221);;
                glVertex2f(350,700);
                glVertex2f(550,700);
                glVertex2f(600,1000);
                glVertex2f(300,1000);
        glEnd();
        
        //biceps
        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3f(0,0,0);
                glVertex2f(350,950);
                glVertex2f(430,950);
                glVertex2f(430,950);
                glVertex2f(440,980);
                glVertex2f(550,950);
                glVertex2f(470,950);
                glVertex2f(470,950);
                glVertex2f(460,980);
                glVertex2f(370,890);
                glVertex2f(440,890);
                glVertex2f(440,890);
                glVertex2f(440,920);
                glVertex2f(530,890);
                glVertex2f(460,890);
                glVertex2f(460,890);
                glVertex2f(460,920);
                glVertex2f(370,840);
                glVertex2f(440,840);
                glVertex2f(440,840);
                glVertex2f(440,870);
                glVertex2f(530,840);
                glVertex2f(460,840);
                glVertex2f(460,840);
                glVertex2f(460,870);
                glVertex2f(370,790);
                glVertex2f(440,790);
                glVertex2f(440,790);
                glVertex2f(440,820);
                glVertex2f(530,790);
                glVertex2f(460,790);
                glVertex2f(460,790);
                glVertex2f(460,820);
                glVertex2f(370,740);
                glVertex2f(440,740);
                glVertex2f(440,740);
                glVertex2f(440,770);
                glVertex2f(530,740);
                glVertex2f(460,740);
                glVertex2f(460,740);
                glVertex2f(460,770);
        glEnd();
        
        //ramanipples
        glPointSize(3);
        glBegin(GL_POINTS);
        glColor3f(0,0,0);
                glVertex2f(400,960);
                glVertex2f(500,960);
        glEnd(); 
        
        glBegin(GL_POLYGON);//bagpack handle
        glColor3ub(168,151,151);   
                glVertex2f(375,1000);
                glVertex2f(320,1000);
                glVertex2f(550,700);
                glVertex2f(560,750);
        glEnd();
        
        glLineWidth(3);
        glBegin(GL_LINES);//bagpack arrows
        glColor3f(0.4,0.2,0.16);   
                glVertex2f(275,1175);
                glVertex2f(210,1300);
                
                glVertex2f(205,1340);
                glVertex2f(210,1300);
                glVertex2f(190,1310);
                glVertex2f(210,1300);
                
                glVertex2f(255,1145);
                glVertex2f(180,1300);
                
                glVertex2f(180,1300);
                glVertex2f(182,1340);
                
                glVertex2f(180,1300);
                glVertex2f(155,1325);
        glEnd();
        
        //ramarighthand
        glLineWidth(1);
        glBegin(GL_POLYGON);
        glColor3ub(121,139,221);
                glVertex2f(300,1000);
                glVertex2f(310,920);
                glVertex2f(560,790);
                glVertex2f(570,860);
        glEnd();
        
        glBegin(GL_POLYGON);
        glColor3ub(121,139,221);
                glVertex2f(560,790);
                glVertex2f(570,860);
                glVertex2f(800,900);
                glVertex2f(800,850);
        glEnd();
        glBegin(GL_LINE_LOOP);
                glVertex2f(300,1000);
                glVertex2f(310,950);
                glVertex2f(560,790);
                glVertex2f(570,830);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0,0,0);
                glVertex2f(300,1000);
                glVertex2f(570,860);
                glVertex2f(310,920); 
                glVertex2f(560,790);
        glEnd();
        //ramalefthand
        glBegin(GL_POLYGON);
        glColor3ub(121,139,221);
                glVertex2f(600,1000);
                glVertex2f(580,930);
                glVertex2f(700,850);
                glVertex2f(700,930);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(121,139,221);
                glVertex2f(700,850);
                glVertex2f(700,930);
                glVertex2f(800,1000);
                glVertex2f(800,950);
        glEnd();

        glLineWidth(10);
	glBegin(GL_POLYGON);
	glColor3f(0.647059,0.164706,0.164706);
       	        glVertex2f(385,1260);
                glVertex2f(385,1000);
                glVertex2f(510,1000);
                glVertex2f(510,1260);
	glEnd();  

	//head
	glBegin(GL_POLYGON);
        glColor3ub(121,139,221);
       	        glVertex2f(385,1080);
                glVertex2f(450,1020);
                glVertex2f(510,1080);
                glVertex2f(510,1210);
	        glVertex2f(450,1230);
                glVertex2f(385,1210);	
	glEnd();
	
        //neck
	glBegin(GL_POLYGON);
        glColor3ub(121,139,221);
       	        glVertex2f(420,1100);
	        glVertex2f(480,1100);
	        glVertex2f(480,1000);
                glVertex2f(420,1000);     
	glEnd();
        
        glLineWidth(1);
	glColor3f(0,0,0);	
	glBegin(GL_LINES);
	        glVertex2f(385,1080);
                glVertex2f(450,1020);
                glVertex2f(450,1020);
                glVertex2f(510,1080);
        glEnd();
        
	//hair
	glBegin(GL_POLYGON);
        glColor3f(0.647059,0.164706,0.164706);
       	        glVertex2f(385,1210);
                glVertex2f(450,1230);
                glVertex2f(510,1210);
                glVertex2f(510,1260);
                glVertex2f(385,1260);	
	glEnd();
	
	glLineWidth(5);
	glBegin(GL_LINES);
        glColor3f(0.647059,0.164706,0.164706);
       	        glVertex2f(385,1260);
                glVertex2f(385,1000);
                glVertex2f(510,1260);
                glVertex2f(510,1000);	
	glEnd();
	      
	//eyes
	glPointSize(9);
	glBegin(GL_POINTS);
	glColor3f(0,0,0);
	        glVertex2f(420,1170);
	        glVertex2f(475,1170);
	glEnd();

        //nama
        glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(1,0,0);
	        glVertex2f(435,1210);
	        glVertex2f(435,1170);
	        glVertex2f(435,1170);
	        glVertex2f(455,1170);
	        glVertex2f(455,1170);
	        glVertex2f(455,1210);
	glEnd();
	
	//nose
	glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(0,0,0);
	        glVertex2f(445,1150);
	        glVertex2f(437,1110);
                glVertex2f(437,1110);
	        glVertex2f(450,1110);
	glEnd();
	
	//mouth
        glLineWidth(2);
	glBegin(GL_LINES);
	glColor3f(1,0,0);
	        glVertex2f(425,1075);
	        glVertex2f(470,1075);
	glEnd();
	
        //bow       
        glLineWidth(5);
        glBegin(GL_LINE_LOOP);
        glColor3f(0.647059,0.164706,0.164706);
                glVertex2f(800,1200);
                glVertex2f(840,1150);
                glVertex2f(860,1100);
                glVertex2f(880,1050);
                glVertex2f(890,1000);
                glVertex2f(900,950);
                glVertex2f(900,900);
                glVertex2f(890,850);
                glVertex2f(880,800);
                glVertex2f(870,750);
                glVertex2f(850,700);
                glVertex2f(825,650); 
                glVertex2f(800,600);
        glEnd();
        
}
void fire()
{       
        glColor3f(1,0.2,0);
        glBegin(GL_POLYGON);
        glVertex2f(1600,1200);
        glVertex2f(1400,1200);
        glVertex2f(1200,1450);
        glVertex2f(1250,1550);    
        glVertex2f(1350,1450);
        glVertex2f(1400,1550);
        glVertex2f(1450,1450);
        glVertex2f(1500,1550);
        glVertex2f(1500,1450);
        glVertex2f(1600,1550);
        glVertex2f(1600,1450);
        glVertex2f(1700,1550);
        glVertex2f(1700,1450);
        glEnd(); 
        glBegin(GL_POLYGON);
        glColor3f(1,0.5,0);
        glVertex2f(1400,1200);
        glVertex2f(1300,1400);
        glVertex2f(1350,1350);
        glVertex2f(1400,1400);    
        glVertex2f(1450,1350);
        glVertex2f(1500,1400);
        glVertex2f(1550,1350);
        glVertex2f(1600,1400);
        glVertex2f(1650,1350);
        glVertex2f(1670,1400);
        glVertex2f(1600,1200);
        glEnd(); 
        glBegin(GL_POLYGON);
        glColor3f(1,0.8,0);
        glVertex2f(1450,1200);
        glVertex2f(1400,1300);
        glVertex2f(1450,1250);
        glVertex2f(1500,1300);    
        glVertex2f(1550,1250);
        glVertex2f(1600,1300);
        glVertex2f(1550,1200);
        glEnd(); 
        glFlush();  
}

void arrow(){
        glutSetWindowTitle("Story of Diwali");
	        
        glLineWidth(3);
        ravan();
        heads();
        ravan_weapon1();
        ravan_weapon2();
        glBegin(GL_LINES);
        glColor3f(0.4,0.2,0.16);
                glVertex2f(740,790);
                glVertex2f(925,1025);
                glVertex2f(730,810);
                glVertex2f(760,810);
                glVertex2f(760,810);
                glVertex2f(760,780);      	
                glVertex2f(710,790);
                glVertex2f(740,790);  
                glVertex2f(740,790);
                glVertex2f(740,760);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(1,0.3,0.0);
                glVertex2f(890,1020);
                glVertex2f(930,1030);
                glVertex2f(920,990);
        glEnd();
        glColor3f(0,0,0);
        drawstring(50,100,0,"Ram who is known till date for his patience was shattered and outraged at the kidnapping of Sita.");
        drawstring(50,40,0,"He avenged to punish Ravana for his misdeed and rescue Sita as soon as possible from the clutches of Ravana.");
        glColor3f(1,1,1);
	drawstring(1700,200,0,"Press z to continue");
	glFlush();
}

void moving_arrow(){ 
        if(flag == 0){
        i = 0;          
        while(i<700){
        ravan();   
        glColor3f(0,0,0);
        drawstring(50,100,0,"As a consequence, an unprecedented battle in history is fought between Ram and Ravana at the end of which");
        drawstring(50,40,0,"Ram defeats and kills Ravana (the day we celebrate as Dussehra).");
        glPushMatrix();
        glLineWidth(3);
        glBegin(GL_LINES);
        glColor3f(0.4,0.2,0.16);
                glVertex2f(740+i,790+0.5*i);
                glVertex2f(925+i,1025+0.5*i);
                glVertex2f(730+i,810+0.5*i);
                glVertex2f(760+i,810+0.5*i);
        glColor3f(0.4,0.2,0.16);
                glVertex2f(760+i,810+0.5*i);
                glVertex2f(760+i,780+0.5*i);      
        glColor3f(0.4,0.2,0.16);
                glVertex2f(710+i,790+0.5*i);
                glVertex2f(740+i,790+0.5*i); 
                glVertex2f(740+i,790+0.5*i);
                glVertex2f(740+i,760+0.5*i);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(1,0.3,0.0);
                glVertex2f(890+i,1020+0.5*i);
                glVertex2f(930+i,1030+0.5*i);
                glVertex2f(920+i,990+0.5*i);
        glEnd();
        i+=10;
        if(i<650){  
              heads();
              ravan_weapon1(); 
              ravan_weapon2();  
        }
        glPopMatrix();
        glFlush();
        glutSwapBuffers();
        }
        glPushMatrix();
        glTranslatef(0,400,0);
        heads();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(100,-950,0);
        ravan_weapon1();
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(0,-700,0);
        ravan_weapon2();
        glPopMatrix();
        
        glColor3f(1,1,1);
        drawstring(1700,200,0,"Press z to continue");
        } flag = 1;
        
}

void girlhead(){
	x1 = 450,y11 = 1400,radius = 70;
	glColor3f(0.9137,0.6588,0.2039);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1,y11);
	for (angle=1.0f;angle<361.0f;angle+=0.2)
	{
    		x2 = x1+sin(angle)*radius;
   		y2 = y11+cos(angle)*radius;
   		glVertex2f(x2,y2);
	}
	glEnd();	
}

void boyhead(){
	x3 = 1300,y3 = 1400,radius = 70;
	glColor3f(0.9137,0.6588,0.2039);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x3,y3);
	for (angle=1.0f;angle<361.0f;angle+=0.2)
	{
    		x4 = x3+sin(angle)*radius;
   		y4 = y3+cos(angle)*radius;
   		glVertex2f(x4,y4);
   		
   	}
   	glEnd();
}	
void spin(){
	if(a>=100)
		a = 0;
	else{
		a = a + 10;	
                printf("glob=%d\n",glob);
                printf("cur_win=%d\n",cur_win);
                
		glutPostRedisplay();
	}
}
void dahan(){
        glPushMatrix();
        glTranslatef(-350,-100,0);
        glClearColor(0,0,0,0);
        glClear(GL_COLOR_BUFFER_BIT);
        ravan();
        heads();
        ravan_weapon1();
        ravan_weapon2();
        fire();
        glPopMatrix();
        glFlush();
        
}
void cracker(){
        glPushMatrix();
	glTranslatef(100,0,0);
	glTranslatef(800,400,0);
        glRotatef(a,0,0,1);
        glTranslatef(-800,-400,0);
        glBegin(GL_LINES);
        glColor3f(1,0.4,0);
                glVertex2f(800,400);
                glVertex2f(850,650);                 
                glVertex2f(800,400);
                glVertex2f(950,650);  
                glVertex2f(800,400);
                glVertex2f(1050,550);
                glVertex2f(800,400);
                glVertex2f(1050,450);
                glVertex2f(800,400);
                glVertex2f(1050,350);
                glVertex2f(800,400);
                glVertex2f(1050,250);
                glVertex2f(800,400);
                glVertex2f(950,150);
                glVertex2f(800,400);
                glVertex2f(550,450);
                glVertex2f(800,400);
                glVertex2f(550,550);
                glVertex2f(800,400);
                glVertex2f(650,650);
                glVertex2f(800,400);
                glVertex2f(750,650);
                glVertex2f(800,400);
                glVertex2f(750,150);
                glVertex2f(800,400);
                glVertex2f(650,150);
                glVertex2f(800,400);
                glVertex2f(550,250);
                glVertex2f(800,400);
                glVertex2f(550,350);
        glColor3f(1,0.8,0);
                glVertex2f(800,400);
                glVertex2f(900,600);
                glVertex2f(800,400);
                glVertex2f(1000,300);
                glVertex2f(800,400);
                glVertex2f(1000,500);
                glVertex2f(800,400);
                glVertex2f(900,200);
                glVertex2f(800,400);
                glVertex2f(850,150);
                glVertex2f(800,400);
                glVertex2f(800,100);
                glVertex2f(800,400);
                glVertex2f(600,500);
                glVertex2f(800,400);
                glVertex2f(700,600);
                glVertex2f(800,400);
                glVertex2f(700,200);
                glVertex2f(800,400);
                glVertex2f(600,300);
        glColor3f(1,0,0);
                glVertex2f(800,400);
                glVertex2f(1050,650);
                glVertex2f(800,400);
                glVertex2f(1100,400);
                glVertex2f(800,400);
                glVertex2f(1050,150);
                glVertex2f(800,400);
                glVertex2f(550,150);
                glVertex2f(800,400);
                glVertex2f(500,400);
                glVertex2f(800,400);
                glVertex2f(550,650);
                glVertex2f(800,400);
                glVertex2f(800,700);
        glEnd();
        
        glPointSize(15);
        glColor3f(0.184314,0.309804,0.184314);
        glBegin(GL_POINTS);
                glVertex2f(800,400);
        glEnd(); 
        glPopMatrix();
        glob=9;
        if(a>=100)
                a=0;
        else{
		a = a + 10;	
                //printf("glob=%d\n",glob);
                //printf("cur_win=%d\n",cur_win);
        }        
	glutPostRedisplay();
	
}

void kids()
{
        glClearColor(0,0,0,0);
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glColor3ub(75,18,72);
                glVertex2f(0,0);
                glVertex2f(2200,0);
        glColor3ub(249,212,35);
                glVertex2f(2200,2200);
                glVertex2f(0,2200);
        glEnd();
       
        //girl
        glBegin(GL_POLYGON);//neck
        glColor3f(0.9137,0.6588,0.2039);
                glVertex2f(425,1400);
                glVertex2f(475,1400);
                glVertex2f(475,1200);
                glVertex2f(425,1200);
        glEnd();

        glColor3f(1,0,0);
        glBegin(GL_POLYGON);//chest
                glVertex2f(350,1150);
                glVertex2f(550,1150);
                glVertex2f(550,1300);
                glVertex2f(350,1300);
        glEnd();

        glColor3f(1,1,0);
        glBegin(GL_POLYGON);//skirt
                glVertex2f(350,1150);
                glVertex2f(550,1150);
                glVertex2f(600,900);
                glVertex2f(300,900);
        glEnd();
        //girlshoe
        glBegin(GL_POLYGON);
        glColor3f(1,0,1 );
                glVertex2f(330,800);
                glVertex2f(430,800);
                glVertex2f(430,750);
                glVertex2f(330,750);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(1,0,1);
                glVertex2f(480,800);
                glVertex2f(580,800);
                glVertex2f(580,750);
                glVertex2f(480,750);
        glEnd(); 
        glColor3f(0.9137,0.6588,0.2039);
        glBegin(GL_POLYGON);//leg1
                glVertex2f(380,800);
                glVertex2f(380,900);
                glVertex2f(430,900);
                glVertex2f(430,800);
        glEnd();
        glColor3f(0.9137,0.6588,0.2039);
        glBegin(GL_POLYGON);//leg2
                glVertex2f(480,800);
                glVertex2f(480,900);
                glVertex2f(530,900);
                glVertex2f(530,800);
        glEnd();
        //hand1
        glBegin(GL_POLYGON);
        glColor3f(0.9137,0.6588,0.2039);
                glVertex2f(550,1250);
                glVertex2f(550,1300);
                glVertex2f(700,1200);
                glVertex2f(700,1150);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(1,0,0);
                glVertex2f(550,1250);
                glVertex2f(550,1300);
                glVertex2f(600,1280);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.9137,0.6588,0.2039);
                glVertex2f(700,1200);
                glVertex2f(700,1150);
                glVertex2f(750,1200);
                glVertex2f(750,1250);
        glEnd();
         //hand2
        glBegin(GL_POLYGON);
                glVertex2f(350,1250);
                glVertex2f(350,1300);
                glVertex2f(200,1200);
                glVertex2f(200,1150);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(1,0,0);
                glVertex2f(350,1250);
                glVertex2f(350,1300);
                glVertex2f(300,1280);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.9137,0.6588,0.2039);
                glVertex2f(200,1200);
                glVertex2f(200,1150);
                glVertex2f(150,1200);
                glVertex2f(150,1250);
        glEnd();
        
        //boy
        glBegin(GL_POLYGON);//neck
        glColor3f(0.9137,0.6588,0.2039);
                glVertex2f(1275,1400);
                glVertex2f(1330,1400);
                glVertex2f(1330,1200);
                glVertex2f(1275,1200);
        glEnd();
        glColor3f(0.196078,0.8,0.196078);
        glBegin(GL_POLYGON);//chest
                glVertex2f(1200,1100);
                glVertex2f(1200,1300);
                glVertex2f(1400,1300);
                glVertex2f(1400,1100);
        glEnd();
        glColor3f(0.55,0.47,0.14);
        glBegin(GL_POLYGON);//pant
                glVertex2f(1190,950);
                glVertex2f(1190,1100);
                glVertex2f(1410,1100);
                glVertex2f(1410,950);
        glEnd();
        glColor3f(0.9137,0.6588,0.2039);
        glBegin(GL_POLYGON);//leg1
                glVertex2f(1230,770);
                glVertex2f(1230,950);
                glVertex2f(1280,950);
                glVertex2f(1280,770);
        glEnd();
        glColor3f(0.9137,0.6588,0.2039);
        glBegin(GL_POLYGON);//leg2
                glVertex2f(1320,770);
                glVertex2f(1320,950);
                glVertex2f(1370,950);
                glVertex2f(1370,770);
        glEnd();
        //hand1
        glBegin(GL_POLYGON);
        glColor3f(0.9137,0.6588,0.2039);
                glVertex2f(1400,1250);
                glVertex2f(1400,1300);
                glVertex2f(1500,1200);
                glVertex2f(1500,1150);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.196078,0.8,0.196078);
                glVertex2f(1400,1250);
                glVertex2f(1400,1300);
                glVertex2f(1440,1280);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.9137,0.6588,0.2039);
                glVertex2f(1500,1200);
                glVertex2f(1500,1150);
                glVertex2f(1550,1200);
                glVertex2f(1550,1250);
        glEnd();
         //hand2
        glBegin(GL_POLYGON);
        glColor3f(0.9137,0.6588,0.2039);
                glVertex2f(1200,1250);
                glVertex2f(1200,1300);
                glVertex2f(1100,1200);
                glVertex2f(1100,1150);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.196078,0.8,0.196078);
                glVertex2f(1200,1250);
                glVertex2f(1200,1300);
                glVertex2f(1160,1280);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.9137,0.6588,0.2039);
                glVertex2f(1100,1200);
                glVertex2f(1100,1150);
                glVertex2f(1050,1200);
                glVertex2f(1050,1250);
        glEnd();
        //boyshoe
        glBegin(GL_POLYGON);
        glColor3f( 0.647059,0.164706,0.164706);
                glVertex2f(1180,750);
                glVertex2f(1180,800);
                glVertex2f(1280,800);
                glVertex2f(1280,750);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f( 0.647059,0.164706,0.164706);
                glVertex2f(1320,750);
                glVertex2f(1320,800);
                glVertex2f(1420,800);
                glVertex2f(1420,750);
        glEnd(); 
        
        //girlleftsursurkaddi
        glLineWidth(3);
        glBegin(GL_LINES);
        glColor3f(0.647059,0.164706,0.164706);
                glVertex2f(150,1230);
                glVertex2f(140,1280);
        glEnd();
        glLineWidth(3);
        glBegin(GL_LINES);
        glColor3f(0.752941,0.752941,0.752941);
                glVertex2f(140,1280);
                glVertex2f(110,1410);
        glEnd(); 
        glBegin(GL_LINES);
        glColor3f(1,0,0);
                glVertex2f(90,1430);
                glVertex2f(110,1410);
                glVertex2f(110,1410);
                glVertex2f(130,1430);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(1,0.2,0);
                glVertex2f(90,1450);
                glVertex2f(110,1410);
                glVertex2f(110,1410);
                glVertex2f(130,1450);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(1,0.4,0);
                glVertex2f(100,1470);
                glVertex2f(110,1410);
                glVertex2f(110,1410);
                glVertex2f(120,1470);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(1,0.6,0);
                glVertex2f(100,1490);
                glVertex2f(110,1410);
                glVertex2f(110,1410);
                glVertex2f(120,1490);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(1,0.8,0);
                glVertex2f(110,1510);
                glVertex2f(110,1410);
        glEnd();
        //girlrightsursurkaddi
        glLineWidth(3);
        glBegin(GL_LINES);
        glColor3f(0.647059,0.164706,0.164706);
                glVertex2f(750,1230);
                glVertex2f(760,1280);
        glColor3f(0.752941,0.752941,0.752941);
                glVertex2f(760,1280);
                glVertex2f(790,1410);
        glColor3f(1,0,0);
                glVertex2f(770,1430);
                glVertex2f(790,1410);
                glVertex2f(790,1410);
                glVertex2f(810,1430);
        glColor3f(1,0.2,0);
                glVertex2f(770,1450);
                glVertex2f(790,1410);
                glVertex2f(790,1410);
                glVertex2f(810,1450);
        glColor3f(1,0.4,0);
                glVertex2f(780,1470);
                glVertex2f(790,1410);
                glVertex2f(790,1410);
                glVertex2f(800,1470);
        glColor3f(1,0.6,0);
                glVertex2f(780,1490);
                glVertex2f(790,1410);
                glVertex2f(790,1410);
                glVertex2f(800,1490);
        glColor3f(1,0.8,0);
                glVertex2f(790,1510);
                glVertex2f(790,1410);
        glEnd();

        //boyleftsursurkaddi
        glLineWidth(3);
        glBegin(GL_LINES);
        glColor3f(0.647059,0.164706,0.164706);
                glVertex2f(1050,1230);
                glVertex2f(1040,1280);
        glColor3f(0.752941,0.752941,0.752941);
                glVertex2f(1040,1280);
                glVertex2f(1010,1410);
        glColor3f(1,0,0);
                glVertex2f(990,1430);
                glVertex2f(1010,1410);
                glVertex2f(1010,1410);
                glVertex2f(1030,1430);
        glColor3f(1,0.2,0);
                glVertex2f(990,1450);
                glVertex2f(1010,1410);
                glVertex2f(1010,1410);
                glVertex2f(1030,1450);
        glColor3f(1,0.4,0);
                glVertex2f(1000,1470);
                glVertex2f(1010,1410);
                glVertex2f(1010,1410);
                glVertex2f(1020,1470);
        glColor3f(1,0.6,0);
                glVertex2f(1000,1490);
                glVertex2f(1010,1410);
                glVertex2f(1010,1410);
                glVertex2f(1020,1490);
        glColor3f(1,0.8,0);
                glVertex2f(1010,1510);
                glVertex2f(1010,1410);
        glEnd();
        //girlrightsursurkaddi
        glLineWidth(3);
        glBegin(GL_LINES);
        glColor3f(0.647059,0.164706,0.164706);
                glVertex2f(1550,1230);
                glVertex2f(1560,1280);
        glColor3f(0.752941,0.752941,0.752941);
                glVertex2f(1560,1280);
                glVertex2f(1590,1410);
        glColor3f(1,0,0);
                glVertex2f(1570,1430);
                glVertex2f(1590,1410);
                glVertex2f(1590,1410);
                glVertex2f(1610,1430);
        glColor3f(1,0.2,0);
                glVertex2f(1570,1450);
                glVertex2f(1590,1410);
                glVertex2f(1590,1410);
                glVertex2f(1610,1450);
        glColor3f(1,0.4,0);
                glVertex2f(1580,1470);
                glVertex2f(1590,1410);
                glVertex2f(1590,1410);
                glVertex2f(1600,1470);
        glColor3f(1,0.6,0);
                glVertex2f(1580,1490);
                glVertex2f(1590,1410);
                glVertex2f(1590,1410);
                glVertex2f(1600,1490);
        glColor3f(1,0.8,0);
                glVertex2f(1590,1510);
                glVertex2f(1590,1410);
        glEnd();
        
        //nelachakra
        cracker();

        glPushMatrix();
        //flowerpot
        glTranslatef(0,200,0);
        //glTranslatef(0,-200,0);
        glBegin(GL_POLYGON);
        glColor3f(0,1,1);
                glVertex2f(1750,100);
                glVertex2f(1800,200);
                glVertex2f(1850,100);
        glEnd();
        glLineWidth(3); 
        glRotatef(a,0,1,0);
        glBegin(GL_LINES);
        glColor3f(1,0,0);
                glVertex2f(1750,300);
                glVertex2f(1800,200);
                glVertex2f(1800,200);
                glVertex2f(1850,300);
        glColor3f(1,0.1,0);
                glVertex2f(1760,350);
                glVertex2f(1800,200);
                glVertex2f(1800,200);
                glVertex2f(1840,350);
        glColor3f(1,0.2,0);
                glVertex2f(1760,400);
                glVertex2f(1800,200);
                glVertex2f(1800,200);
                glVertex2f(1840,400);        
        glColor3f(1,0.3,0);
                glVertex2f(1770,450);
                glVertex2f(1800,200);
                glVertex2f(1800,200);
                glVertex2f(1830,450);
        glColor3f(1,0.4,0);
                glVertex2f(1770,500);
                glVertex2f(1800,200);
                glVertex2f(1800,200);
                glVertex2f(1830,500); 
        glColor3f(1,0.5,0);
                glVertex2f(1780,550);
                glVertex2f(1800,200);
                glVertex2f(1800,200);
                glVertex2f(1820,550);
        glColor3f(1,0.6,0);
                glVertex2f(1780,600);
                glVertex2f(1800,200);
                glVertex2f(1800,200);
                glVertex2f(1820,600);
        glColor3f(0.9137,0.6588,0.2039);
                glVertex2f(1790,600);
                glVertex2f(1800,200);
                glVertex2f(1800,200);
                glVertex2f(1810,600);
        glColor3f(1,0.8,0);
                glVertex2f(1790,650);
                glVertex2f(1800,200);
                glVertex2f(1800,200);
                glVertex2f(1810,650);
        glColor3f(1,0.9,0);
                glVertex2f(1800,700);
                glVertex2f(1800,200);
                glVertex2f(1800,200);
                glVertex2f(1800,700);
        glEnd();
        glPopMatrix();
                                                                                            
        girlhead();
        //girleyes
        glPointSize(5);
        glBegin(GL_POINTS);
        glColor3f(0,0,0);
                glVertex2f(430,1420);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(0,0,0);
                glVertex2f(470,1420);
        glEnd();
        //smile
        glLineWidth(2);
        glBegin(GL_LINES);
                glColor3f(0,0,0);
                glVertex2f(420,1390);
                glVertex2f(450,1380);
                glVertex2f(450,1380);
                glVertex2f(480,1390);
        glEnd();
        //girlhair
        glBegin(GL_POLYGON);
        glColor3f(0.647059,0.164706,0.164706);
                glVertex2f(380,1450);
                glVertex2f(400,1480);
                glVertex2f(420,1500);
                glVertex2f(450,1510);
                glVertex2f(480,1500);
                glVertex2f(500,1480);
                glVertex2f(520,1450);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.647059,0.164706,0.164706);
                glVertex2f(380,1450);
                glVertex2f(350,1400);
                glVertex2f(410,1400);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.647059,0.164706,0.164706);
                glVertex2f(520,1450);
                glVertex2f(490,1400);
                glVertex2f(550,1400);
        glEnd();
        boyhead();   
        //boyeyes
        glPointSize(5);
        glBegin(GL_POINTS);
        glColor3f(0,0,0);
                glVertex2f(1280,1420);
        glEnd();
        glBegin(GL_POINTS);
        glColor3f(0,0,0);
                glVertex2f(1320,1420);
        glEnd(); 
        //smile
        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3f(0,0,0);
                glVertex2f(1270,1390);
                glVertex2f(1300,1380);
                glVertex2f(1300,1380);
                glVertex2f(1330,1390);
        glEnd(); 
        //boyhair
        glBegin(GL_POLYGON);
        glColor3f(0.647059,0.164706,0.164706);
                glVertex2f(1230,1440);
                glVertex2f(1240,1460);
                glVertex2f(1270,1480);
                glVertex2f(1300,1485);
                glVertex2f(1330,1480);
                glVertex2f(1360,1460);
                glVertex2f(1370,1440);
        glEnd();                                                                         
        glFlush();
        
        //textbox
        glColor3f(1,1,1);
        glBegin(GL_POLYGON);
                glVertex2f(0,2200);
                glVertex2f(2200,2200);
                glVertex2f(2200,2000);
                glVertex2f(0,2000);
        glEnd();
        glColor3f(0,0,0);
	drawstring(300,2130,0,"Diwali is loud,colourful and joyous! Diwali's message about good over evil is timeless.");
	drawstring(500,2030,0,"People triumph by bursting crackers and preparing delicacies.");
        glColor3f(1,1,1);
	drawstring(1700,100,0,"Press z to continue");
} 

void bush(int x,int y,int radius){
        glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x,y);
	for (angle=1.0f;angle<361.0f;angle+=0.2)
	{
    		x1 = x+sin(angle)*radius;
   		y11 = y+cos(angle)*radius;
   		glVertex2f(x1,y11);
	}
	glEnd();
}

void trees(){
	glClearColor(0.658824,0.658824,0.658824,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(0.65,0.49,0.24);
	        glVertex2f(450,1100);//trunk
	        glVertex2f(500,850);
	        glVertex2f(700,850);
	        glVertex2f(750,1100);
	glEnd();
	glBegin(GL_POLYGON);
	        glVertex2f(500,850);
	        glVertex2f(700,850);
	        glVertex2f(750,400);
	        glVertex2f(450,400);
	glEnd();
	
	glColor3f(0.329412,0.329412,0.329412);
	bush(500,1150,150);
	bush(700,1150,150);	
	bush(500,1300,150);	
	bush(700,1300,150);	
	bush(600,1410,150);
	
	glColor3f(1,1,1);//eyes
	bush(500,1350,30);
	bush(700,1350,30);
	
	glLineWidth(6);
	glBegin(GL_LINES);
	glColor3f(0,0,0);
	        glVertex2f(490,1150);
	        glVertex2f(490,1180);
	        glVertex2f(490,1180);
	        glVertex2f(500,1200);
	        glVertex2f(500,1200);
	        glVertex2f(510,1220);
	        glVertex2f(510,1220);
	        glVertex2f(530,1240);
	        glVertex2f(530,1240);
	        glVertex2f(550,1250);
	        glVertex2f(550,1250);
	        glVertex2f(570,1260);
	        glVertex2f(570,1260);
	        glVertex2f(600,1265);
	        glVertex2f(600,1265);
	        glVertex2f(630,1260);
	        glVertex2f(630,1260);
	        glVertex2f(650,1250);
	        glVertex2f(650,1250);
	        glVertex2f(670,1240);
	        glVertex2f(670,1240);
	        glVertex2f(690,1220);
	        glVertex2f(690,1220);
	        glVertex2f(700,1200);
	        glVertex2f(700,1200);
	        glVertex2f(710,1180);
	        glVertex2f(710,1180);
	        glVertex2f(710,1150);
	glEnd();
        glPointSize(10);     
	glBegin(GL_POINTS);//eyeballs
	glColor3f(0,0,0);
	        glVertex2f(500,1350);
	        glVertex2f(700,1350);
        glEnd();
	        
	glPushMatrix();
	glTranslatef(-200,0,0);
	glColor3f(0.65,0.49,0.24);
	glBegin(GL_POLYGON);
	        glVertex2f(1550,1100);
	        glVertex2f(1600,850);
	        glVertex2f(1800,850);
	        glVertex2f(1850,1100);
	glEnd();	
	glBegin(GL_POLYGON);
	        glVertex2f(1600,850);
	        glVertex2f(1800,850);
	        glVertex2f(1850,400);
	        glVertex2f(1550,400);
	glEnd();
	glColor3f(0.329412,0.329412,0.329412);		
	bush(1600,1150,150);
	bush(1800,1150,150);
	bush(1600,1300,150);
	bush(1800,1300,150);
	bush(1700,1410,150);
	
	glColor3f(1,1,1);
	bush(1600,1350,30);
	bush(1800,1350,30);
	
	glBegin(GL_POINTS);//eyeballs
	glColor3f(0,0,0);
	        glVertex2f(1600,1350);
	        glVertex2f(1800,1350);
	glEnd();
	glLineWidth(6);
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	        glVertex2f(1590,1150);
	        glVertex2f(1590,1180);
	        glVertex2f(1590,1180);
	        glVertex2f(1600,1200);
	        glVertex2f(1600,1200);
	        glVertex2f(1610,1220);
	        glVertex2f(1610,1220);
	        glVertex2f(1630,1240);
	        glVertex2f(1630,1240);
	        glVertex2f(1650,1250);
	        glVertex2f(1650,1250);
	        glVertex2f(1670,1260);
	        glVertex2f(1670,1260);
	        glVertex2f(1700,1265);
	        glVertex2f(1700,1265);
	        glVertex2f(1730,1260);
	        glVertex2f(1730,1260);
	        glVertex2f(1750,1250);
	        glVertex2f(1750,1250);
	        glVertex2f(1770,1240);
	        glVertex2f(1770,1240);
	        glVertex2f(1790,1220);
	        glVertex2f(1790,1220);
	        glVertex2f(1800,1200);
	        glVertex2f(1800,1200);
	        glVertex2f(1810,1180);
	        glVertex2f(1810,1180);
	        glVertex2f(1810,1150);
	glEnd();
	glPopMatrix();
	glFlush();
	glColor3f(0,0,0);
	drawstring(690,1800,0,"How can we give 'pure air' to human being,");
	drawstring(690,1700,0,"when their 'DIWALI' too robbed out of all purity,");
	drawstring(690,1600,0,"apart from the usual pollution!");
	glColor3f(0,0,0);
	drawstring(1700,100,0,"Press z to continue");
}
	
void earth()
{
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glColor3ub(227,227,227);
                glVertex2f(0,0);
                glVertex2f(2200,0);
        glColor3ub(255,255,255);
                glVertex2f(2200,2200);
                glVertex2f(0,2200);           
        glEnd();
	drawImage(440,500,1200,1200,bgTexture5);	
	glFlush();
	glColor3f(0,0,0);
	drawstring(600,1900,0,"Don’t Act MEAN, Go GREEN.”");
	drawstring(750,1800,0," Celebrate An Eco Friendly Diwali This Year.");

}

void road()
{      //to draw road 
	glPointSize(8);
	glColor3f(0.1,0.1,0);
	glBegin(GL_POLYGON);
	        glVertex2f(2200,700);
	glColor3f(0.05,0.05,0);
	        glVertex2f(2200,375);
	glColor3f(0.10,0.10,0);
	        glVertex2f(1800,0);
	glColor3f(0.05,0.07,0);
	        glVertex2f(1400,0);
	glEnd();
	glColor3f(1,1,1);
	glBegin(GL_LINES);
	        glVertex2f(2200,550);
	        glVertex2f(1600,0);
	        glVertex2f(2200,560);
	        glVertex2f(1590,0);
	glEnd();
}

void house_day()
{
        glColor3f(0.901,0.891,0.282);
        glBegin(GL_POLYGON);
                glVertex2f(1000,650);
                glVertex2f(1300,650);
                glVertex2f(1300,1000);
                glVertex2f(1000,1000);
        glEnd();
        glColor3f(0.2,0,0);
        glBegin(GL_POLYGON);
                glVertex2f(1000,1000);
                glVertex2f(1150,1100);
                glVertex2f(1300,1000);
        glEnd();
        
        glColor3f(0.1,0,0);
        glBegin(GL_POLYGON);
       	        glVertex2f(1300,1000);
                glVertex2f(1750,1200);
                glVertex2f(1600,1300);
                glVertex2f(1150,1100);
        glEnd();
       	glColor3f(1,1,0.2);
        glBegin(GL_POLYGON);
       	        glVertex2f(1300,650);
                glVertex2f(1750,900);
                glVertex2f(1750,1200);
                glVertex2f(1300,1000);
        glEnd(); 
        glColor3f(0.5,0,0);
        glBegin(GL_POLYGON);
       	        glVertex2f(1100,650);
                glVertex2f(1200,650);
                glVertex2f(1200,850);
                glVertex2f(1100,850);
        glEnd();
        glColor3f(1,0.3,0);
        glBegin(GL_POLYGON);
     	        glVertex2f(1350,870);
                glVertex2f(1450,920);
                glVertex2f(1450,1020);
                glVertex2f(1350,970);
       	glEnd();
        glColor3f(1,0.3,0);
        glBegin(GL_POLYGON);
      	        glVertex2f(1600,1000);
                glVertex2f(1700,1050);
                glVertex2f(1700,1150);
                glVertex2f(1600,1100);
        glEnd();
        glFlush();
}

void lantern(){
        //lantern1
        glColor3f(1,0,0);
        glLineWidth(3);
	glBegin(GL_LINES);
		glVertex2f(1000,1000);
		glVertex2f(1000,950);	
		glVertex2f(950,900);
		glVertex2f(950,850);		
		glVertex2f(1050,900);
		glVertex2f(1050,850);		
		glVertex2f(950,800);
		glVertex2f(950,750);		
		glVertex2f(1050,800);
		glVertex2f(1050,750);		
		glVertex2f(1000,750);
		glVertex2f(1000,700);
	glEnd();
	glColor3f(1,0.3,0);
	glBegin(GL_POLYGON);
		glVertex2f(950,800);
		glVertex2f(1000,750);
		glVertex2f(1050,800);
		glVertex2f(1050,900);
		glVertex2f(1000,950);
		glVertex2f(950,900);
	glEnd();
	glColor3f(1,0.55,0);
	glBegin(GL_POLYGON);
		glVertex2f(1000,800);
		glVertex2f(1030,850);
		glVertex2f(1000,900);
		glVertex2f(970,850);
	glEnd();
	
	//lantern2
	glColor3f(1,0,0);
        glLineWidth(3);
	glBegin(GL_LINES);
		glVertex2f(1300,1000);
		glVertex2f(1300,950);	
		glVertex2f(1350,900);
		glVertex2f(1350,850);		
		glVertex2f(1250,900);
		glVertex2f(1250,850);		
		glVertex2f(1350,800);
		glVertex2f(1350,750);		
		glVertex2f(1250,800);
		glVertex2f(1250,750);		
		glVertex2f(1300,750);
		glVertex2f(1300,700);
	glEnd();
	glColor3f(1,0.3,0);
	glBegin(GL_POLYGON);
		glVertex2f(1250,800);
		glVertex2f(1300,750);
		glVertex2f(1350,800);
		glVertex2f(1350,900);
		glVertex2f(1300,950);
		glVertex2f(1250,900);
	glEnd();
	glColor3f(1,0.55,0);
	glBegin(GL_POLYGON);
		glVertex2f(1300,800);
		glVertex2f(1330,850);
		glVertex2f(1300,900);
		glVertex2f(1270,850);
	glEnd();
}

void house_night()
{
        glColor3f(0.901,0.891,0.282);
        glBegin(GL_POLYGON);
                glVertex2f(1000,650);
	        glVertex2f(1300,650);   
	glColor3f(0,0,0);
	        glVertex2f(1300,1000);  
                glVertex2f(1000,1000);  
        glEnd();
        	glColor3f(0.2,0,0);
        glBegin(GL_POLYGON);
                glVertex2f(1000,1000);
                glVertex2f(1150,1100);
                glVertex2f(1300,1000);
        glEnd();      
        glColor3f(0.1,0,0);
        glBegin(GL_POLYGON);
       	        glVertex2f(1300,1000);
                glVertex2f(1750,1200);
                glVertex2f(1600,1300);
                glVertex2f(1150,1100);
        glEnd();
       	glColor3f(1,1,0.2);
        glBegin(GL_POLYGON);
       	        glVertex2f(1300,650);
	        glVertex2f(1750,900);	
	glColor3f(0,0,0);  
                glVertex2f(1750,1200);  
	        glVertex2f(1300,1000);
        glEnd(); 
        glColor3f(0.5,0,0);
        glBegin(GL_POLYGON);
       	        glVertex2f(1100,650);
                glVertex2f(1200,650);
                glVertex2f(1200,850);
                glVertex2f(1100,850);
        glEnd();
        glColor3f(0,0,0);
                glBegin(GL_POLYGON);
     	        glVertex2f(1350,870);
                glVertex2f(1450,920);
                glVertex2f(1450,1020);
                glVertex2f(1350,970);
       	glEnd();
        glColor3f(0,0,0);
        glBegin(GL_POLYGON);
      	        glVertex2f(1600,1000);
                glVertex2f(1700,1050);
                glVertex2f(1700,1150);
                glVertex2f(1600,1100);
        glEnd();
        lantern();
} 

void circle(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;
    glBegin(GL_POLYGON);
    {
        for( i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}

void cloud(){
		glColor3f(1,1,1);
		glPushMatrix();	
		glTranslatef(200,1800,0);	
		circle(85);
		glTranslatef(85,40,0);
		circle(70);
		glTranslatef(90,-15,0);
		circle(70);
		glTranslatef(-90,-70,0);
		circle(70);
		glTranslatef(120,20,0);
		circle(70);
		glPopMatrix();
	
		glPushMatrix();	
		glTranslatef(900,1700,0);	
		circle(85);
		glTranslatef(85,40,0);
		circle(70);
		glTranslatef(90,-15,0);
		circle(70);
		glTranslatef(-90,-70,0);
		circle(70);
		glTranslatef(120,20,0);
		circle(70);
		glPopMatrix();

		glPushMatrix();		
		glTranslatef(1700,1900,0);
		circle(85);
		glTranslatef(85,40,0);
		circle(70);
		glTranslatef(90,-15,0);
		circle(70);
		glTranslatef(-90,-70,0);
		circle(70);
		glTranslatef(120,20,0);
		circle(70);
		glPopMatrix();
}	

//To draw tree for DAY
void drawtree()
{
		glColor3f(0,0.2,0);//1st tree
	glBegin(GL_POLYGON);
	glVertex2f(50,300);
	glVertex2f(300,300);
	glVertex2f(175,600);
	glEnd();
		glColor3f(0.30,0.4,0);
	glBegin(GL_POLYGON);
	glVertex2f(50,400);
	glVertex2f(300,400);
	glVertex2f(175,700);
	glEnd();
		glColor3f(0.10,0.4,0);
	glBegin(GL_POLYGON);
	glVertex2f(50,500);
	glVertex2f(300,500);
	glVertex2f(175,800);
	glEnd();
		glColor3f(0,0.2,0);//2nd tree
	glBegin(GL_POLYGON);
	glVertex2f(250,300);
	glVertex2f(500,300);
	glVertex2f(375,600);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.3,0.4,0);
	glVertex2f(250,400);
	glVertex2f(500,400);
	glColor3f(0,0.3,0.2);	
	glVertex2f(375,700);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.10,0.4,0);
	glVertex2f(250,500);
	glVertex2f(500,500);
	glColor3f(0.0,0.3,0.2);
	glVertex2f(375,800);
	glEnd();
		glColor3f(0,0.2,0);//3rd tree
	glBegin(GL_POLYGON);
	glVertex2f(450,300);
	glVertex2f(700,300);
	glVertex2f(575,600);
	glEnd();
		glColor3f(0.30,0.4,0);
	glBegin(GL_POLYGON);
	glVertex2f(450,400);
	glVertex2f(700,400);
	glVertex2f(575,700);
	glEnd();
		glColor3f(0.10,0.4,0);
	glBegin(GL_POLYGON);
	glVertex2f(450,500);
	glVertex2f(700,500);
	glVertex2f(575,800);
	glEnd();
	glColor3f(0,0.3,0);

//trunk
		glColor3f(0.2,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(150,0);
		glColor3f(0.47,0,0);
	glVertex2f(150,300);
		glColor3f(0.57,0,0);
	glVertex2f(200,300);
		glColor3f(0.47,0,0);
	glVertex2f(200,0);
	glEnd();

		glColor3f(0.2,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(350,0);
	glVertex2f(350,300);
		glColor3f(0.57,0,0);
	glVertex2f(400,300);
	glVertex2f(400,0);
	glEnd();

		glColor3f(0.2,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(550,0);
	glVertex2f(550,300);
		glColor3f(0.57,0,0);
	glVertex2f(600,300);
	glVertex2f(600,0);
	glEnd();
}

//To draw tree for NIGHT
void drawtree2()
{
		glColor3f(0.1,0.1,0); //1st tree
	glBegin(GL_POLYGON);
	glVertex2f(300,300);
	glVertex2f(175,600);
		glColor3f(0,0,0);
	glVertex2f(50,300);
	glEnd();
		glColor3f(0.1,0.1,0);
	glBegin(GL_POLYGON);
	glVertex2f(175,700);
	glVertex2f(300,400);
		glColor3f(0,0,0);
	glVertex2f(50,400);
	glEnd();
		glColor3f(0.1,0.1,0);
	glBegin(GL_POLYGON);
	glVertex2f(175,800);
	glVertex2f(300,500);
		glColor3f(0,0,0);
	glVertex2f(50,500);
	glEnd();
		glColor3f(0.1,0.1,0);//2nd tree
	glBegin(GL_POLYGON);
	glVertex2f(500,300);
	glVertex2f(375,600);
		glColor3f(0,0,0);
	glVertex2f(250,300);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.1,0.1,0);
	glVertex2f(375,700);	
	glVertex2f(500,400);
		glColor3f(0,0,0);
	glVertex2f(250,400);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.1,0.1,0);
	glVertex2f(375,800);	
	glVertex2f(500,500);
		glColor3f(0,0,0);
	glVertex2f(250,500);
	glEnd();
		glColor3f(0.1,0.1,0);//3rd tree
	glBegin(GL_POLYGON);
	glVertex2f(700,300);
	glVertex2f(575,600);
		glColor3f(0,0,0);
	glVertex2f(450,300);
	glEnd();
		glColor3f(0.1,0.1,0);
	glBegin(GL_POLYGON);
	glVertex2f(700,400);
	glVertex2f(575,700);
		glColor3f(0,0,0);
	glVertex2f(450,400);
	glEnd();
		glColor3f(0.1,0.1,0);
	glBegin(GL_POLYGON);
	glVertex2f(700,500);
	glVertex2f(575,800);
		glColor3f(0,0,0);
	glVertex2f(450,500);
	glEnd();

//trunk
	glColor3f(0.2,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(150,0);
		glColor3f(0,0,0);
	glVertex2f(150,300);
		glColor3f(0.1,0,0);
	glVertex2f(200,300);
		glColor3f(0.1,0,0);
	glVertex2f(200,0);
	glEnd();

	glColor3f(0.2,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(350,0);
	glVertex2f(350,300);
		glColor3f(0.1,0,0);
	glVertex2f(400,300);
		glColor3f(0.1,0,0);
	glVertex2f(400,0);
	glEnd();

	glColor3f(0.2,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(550,0);
	glVertex2f(550,300);
		glColor3f(0.1,0,0);
	glVertex2f(600,300);
		glColor3f(0.1,0,0);
	glVertex2f(600,0);
	glEnd();
}

void tulsi(){
	glColor3f(0.6,0,0);
        glBegin(GL_POLYGON);
                glVertex2f(950,250);
                glVertex2f(1150,250);
                glVertex2f(1150,300);
                glVertex2f(950,300);
        glEnd();
        glBegin(GL_POLYGON);
       	        glVertex2f(1000,300);
                glVertex2f(1100,300);
                glVertex2f(1100,350);
                glVertex2f(1000,350);
        glEnd();
        glBegin(GL_POLYGON);
       	        glVertex2f(950,350);
                glVertex2f(1150,350);
                glVertex2f(1150,400);
                glVertex2f(950,400);
        glEnd();
        glColor3f(0.329,0.756,0.329);
        glLineWidth(5);
        glBegin(GL_LINE_LOOP);
       	        glVertex2f(1050,400);
                glVertex2f(1000,450);
                glVertex2f(1050,400);
                glVertex2f(1050,450);
                glVertex2f(1050,400);
                glVertex2f(1100,450);
                glVertex2f(1050,400);
                glVertex2f(1150,450);
                glVertex2f(1050,400);
                glVertex2f(950,450);
        glEnd();
        
}

void tulsi_night(){
	glColor3f(0.294,0.0353,0.0353);
        glBegin(GL_POLYGON);
       	        glVertex2f(950,250);
                glVertex2f(1150,250);
                glVertex2f(1150,300);
                glVertex2f(950,300);
        glEnd();
        glBegin(GL_POLYGON);
       	        glVertex2f(1000,300);
                glVertex2f(1100,300);
                glVertex2f(1100,350);
                glVertex2f(1000,350);
        glEnd();       
        glBegin(GL_POLYGON);
       	        glVertex2f(950,350);
                glVertex2f(1150,350);
                glVertex2f(1150,400);
                glVertex2f(950,400);
        glEnd();   
        glColor3f(0.109,0.188,0.109);
        glLineWidth(5);
        glBegin(GL_LINES);
       	        glVertex2f(1050,400);
                glVertex2f(1000,450);
       	        glVertex2f(1050,400);
                glVertex2f(1050,450);
        glColor3f(0.109,0.188,0.109);      
       	        glVertex2f(1050,400);
                glVertex2f(1100,450);
        glColor3f(0.109,0.188,0.109);      
       	        glVertex2f(1050,400);
                glVertex2f(1150,450);
        glColor3f(0.109,0.188,0.109);        
       	        glVertex2f(1050,400);
                glVertex2f(950,450);
        glEnd();
}  

void diyas()
{
	glBegin(GL_POLYGON);
	        glVertex2f(800,640);
	        glVertex2f(850,640);
	        glVertex2f(840,625);
	        glVertex2f(825,615);
	        glVertex2f(810,625);
	glEnd();
	glBegin(GL_POLYGON);
	        glVertex2f(855,640);
	        glVertex2f(900,640);
	        glVertex2f(890,625);
	        glVertex2f(875,615);
	        glVertex2f(865,625);
	glEnd();
	glBegin(GL_POLYGON);
	        glVertex2f(905,640);
	        glVertex2f(950,640);
	        glVertex2f(940,625);
	        glVertex2f(925,615);
	        glVertex2f(910,625);
	glEnd();
	glBegin(GL_POLYGON);
	        glVertex2f(955,640);
	        glVertex2f(1000,640);
	        glVertex2f(990,625);
	        glVertex2f(975,615);
	        glVertex2f(960,625);
	glEnd();
	glBegin(GL_POLYGON);
	        glVertex2f(1005,640);
	        glVertex2f(1050,640);
	        glVertex2f(1045,625);
	        glVertex2f(1025,615);
	        glVertex2f(1015,625);
	glEnd();
	glBegin(GL_POLYGON);
	        glVertex2f(1250,640);
	        glVertex2f(1300,640);
	        glVertex2f(1290,625);
	        glVertex2f(1270,615);
	        glVertex2f(1255,625);
	glEnd();
	glBegin(GL_POLYGON);
	        glVertex2f(1250,640);
	        glVertex2f(1300,640);
	        glVertex2f(1290,625);
	        glVertex2f(1270,615);
	        glVertex2f(1255,625);
	glEnd();
//side
	glBegin(GL_POLYGON);
	        glVertex2f(1350,670);
	        glVertex2f(1400,670);
	        glVertex2f(1390,655);
	        glVertex2f(1370,645);
	        glVertex2f(1355,655);
	glEnd();

	glBegin(GL_POLYGON);
	        glVertex2f(1440,720);
	        glVertex2f(1490,720);
	        glVertex2f(1480,705);
	        glVertex2f(1460,695);
	        glVertex2f(1445,705);
	glEnd();
	
	glBegin(GL_POLYGON);
	        glVertex2f(1520,770);
	        glVertex2f(1570,770);
	        glVertex2f(1560,755);
	        glVertex2f(1540,745);
	        glVertex2f(1525,755);
	glEnd();
	
	glBegin(GL_POLYGON);
	        glVertex2f(1610,820);
	        glVertex2f(1660,820);
	        glVertex2f(1650,805);
	        glVertex2f(1630,795);
	        glVertex2f(1615,805);
	glEnd();
	
	glBegin(GL_POLYGON);
	        glVertex2f(1700,870);
	        glVertex2f(1750,870);
	        glVertex2f(1740,855);
	        glVertex2f(1720,845);
	        glVertex2f(1705,855);
	glEnd();	
}

void diyas_night()
{
	glBegin(GL_POLYGON);
	        glVertex2f(800,640);
	        glVertex2f(850,640);
	        glVertex2f(840,625);
	        glVertex2f(825,615);
	        glVertex2f(810,625);
	glEnd();
	glBegin(GL_POLYGON);
	        glVertex2f(855,640);
	        glVertex2f(900,640);
	        glVertex2f(890,625);
	        glVertex2f(875,615);
	        glVertex2f(865,625);
	glEnd();
	glBegin(GL_POLYGON);
	        glVertex2f(905,640);
	        glVertex2f(950,640);
	        glVertex2f(940,625);
	        glVertex2f(925,615);
	        glVertex2f(910,625);
	glEnd();
	glBegin(GL_POLYGON);
	        glVertex2f(955,640);
	        glVertex2f(1000,640);
	        glVertex2f(990,625);
	        glVertex2f(975,615);
	        glVertex2f(960,625);
	glEnd();
	glBegin(GL_POLYGON);
	        glVertex2f(1005,640);
	        glVertex2f(1050,640);
	        glVertex2f(1045,625);
	        glVertex2f(1025,615);
	        glVertex2f(1015,625);
	glEnd();
	glBegin(GL_POLYGON);
	        glVertex2f(1250,640);
	        glVertex2f(1300,640);
	        glVertex2f(1290,625);
	        glVertex2f(1270,615);
	        glVertex2f(1255,625);
	glEnd();
	glPointSize(5);
//side
	glBegin(GL_POLYGON);
	        glVertex2f(1350,670);
	        glVertex2f(1400,670);
	        glVertex2f(1390,655);
	        glVertex2f(1370,645);
	        glVertex2f(1355,655);
	glEnd();

	glBegin(GL_POLYGON);
	        glVertex2f(1440,720);
	        glVertex2f(1490,720);
	        glVertex2f(1480,705);
	        glVertex2f(1460,695);
	        glVertex2f(1445,705);
	glEnd();
	
	glBegin(GL_POLYGON);
	        glVertex2f(1530,770);
	        glVertex2f(1580,770);
	        glVertex2f(1570,755);
	        glVertex2f(1550,745);
	        glVertex2f(1535,755);
	glEnd();
	
	glBegin(GL_POLYGON);
	        glVertex2f(1610,820);
	        glVertex2f(1660,820);
	        glVertex2f(1650,805);
	        glVertex2f(1630,795);
	        glVertex2f(1615,805);
	glEnd();

	glBegin(GL_POLYGON);
	        glVertex2f(1700,870);
                glVertex2f(1750,870);
	        glVertex2f(1740,855);
	        glVertex2f(1720,845);
	        glVertex2f(1705,855);
	glEnd();

	glColor3f(1,1,0);
	glBegin(GL_POINTS);
	        glVertex2f(850,640);
	        glVertex2f(900,640);
	        glVertex2f(950,640);
	        glVertex2f(1000,640);
	        glVertex2f(1050,640);
	        glVertex2f(1250,640);
	        glVertex2f(1400,670);
	        glVertex2f(1490,720);
	        glVertex2f(1580,770);
	        glVertex2f(1660,820);
	        glVertex2f(1750,870);
	glEnd();
        glColor3f(0.6,0.0,0.0);
	glBegin(GL_QUADS);
		glVertex2f(880.0,240.0);
		glVertex2f(920.0,240.0);
		glVertex2f(930.0,270.0);
		glVertex2f(870.0,270.0);
	glEnd();
	glColor3f(1.0,0.5,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(900.0,270.0);
		glVertex2f(910.0,290.0);
		glVertex2f(900.0,310.0);
		glVertex2f(890.0,290.0);
	glEnd();
	glColor3f(0.6,0.0,0.0);
	glBegin(GL_QUADS);
		glVertex2f(1180.0,240.0);
		glVertex2f(1220.0,240.0);
		glVertex2f(1230.0,270.0);
		glVertex2f(1170.0,270.0);
	glEnd();
	glColor3f(1.0,0.5,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(1200.0,270.0);
		glVertex2f(1210.0,290.0);
		glVertex2f(1200.0,310.0);
		glVertex2f(1190.0,290.0);
	glEnd();
}

void day()
{	//to set the sky color and ground color
	glColor3f(0.8,0.37,0.0);
	glBegin(GL_POLYGON);
	        glVertex2f(2200,2200);
	glColor3f(0.7,0.37,0.0);
	        glVertex2f(0,2200);
	glColor3f(0.4,0.6,0.0);
	        glVertex2f(0,0);
	glColor3f(0.4,0.6,0.0);
	        glVertex2f(2200,0);
	glEnd();

	// to draw the sun
	glPointSize(9.0);
	glColor3f(0.9,0.2,0);
	        circle_draw(1400,2000,100);
	glColor3f(0.95,0.2,0);
	        circle_draw(1400,2000,90);
	glColor3f(1.0,0.25,0);
	        circle_draw(1400,2000,70);
	glColor3f(1.1,0.3,0);
	        circle_draw(1400,2000,50);
	glColor3f(1.15,0.35,0);
	        circle_draw(1400,2000,30);
	glColor3f(1.18,.38,0);
	        circle_draw(1400,2000,10);
	drawtree();
	
//to draw street light for DAY
	glColor3f(0.10,0.10,0.0);
	glBegin(GL_POLYGON);
	        glVertex2f(1400,0);
	glColor3f(0.10,0.10,0.0);
	        glVertex2f(1425,0);
	glColor3f(0.10,0.10,0.0);
	        glVertex2f(1425,250);
	        glVertex2f(1400,250);
	glEnd();
	glColor3f(1.0,01.0,01.0);
	circle_draw(1410,280,30);
	circle_draw(1410,280,10);

	glColor3f(0.10,0.10,0.0);
	glBegin(GL_POLYGON);
	        glVertex2f(1600,200);
	glColor3f(0.10,0.10,0.0);
	        glVertex2f(1625,200);
	glColor3f(0.10,0.10,0.0);
	        glVertex2f(1625,350);
	        glVertex2f(1600,350);
	glEnd();
	
	glColor3f(1.0,01.0,01.0);
	circle_draw(1610,380,30);
	circle_draw(1610,380,10);
	glColor3f(0.10,0.10,0.0);
	
	glBegin(GL_POLYGON);
	        glVertex2f(1800,380);
	glColor3f(0.10,0.10,0.0);
	        glVertex2f(1825,380);
	glColor3f(0.10,0.10,0.0);
	        glVertex2f(1825,525);
	        glVertex2f(1800,525);
	glEnd();
	
	glColor3f(1.0,01.0,01.0);
	circle_draw(1810,555,30);
	circle_draw(1810,555,10);

	glColor3f(0.10,0.10,0.0);
	glBegin(GL_POLYGON);
	        glVertex2f(2000,500);
	glColor3f(0.10,0.10,0.0);
	        glVertex2f(2025,500);
	glColor3f(0.10,0.10,0.0);
	        glVertex2f(2025,650);
	        glVertex2f(2000,650);
	glEnd();
	
	glColor3f(1.0,01.0,01.0);
	circle_draw(2010,680,30);
	circle_draw(2010,680,10);
	road();
	house_day();
	diyas();
	tulsi();
        glPushMatrix();
        glTranslatef(x,0,0);
	cloud();
	if(x>500)
                        x=0;
                else
                        x++;
                glPopMatrix();
	glutPostRedisplay();
}
void blast()
{
	glColor3f(0.8,0.7,0.0);
	glPointSize(3);
	glBegin(GL_POINTS);
		glVertex2f(150.0+rand()%2,1280.0+rand()%2);		
		glVertex2f(200.0+rand()%2,1250.0+rand()%2);
		glVertex2f(200.0+rand()%2,1300.0+rand()%2);
		glVertex2f(100.0+rand()%2,1250.0+rand()%2);
		glVertex2f(100.0+rand()%2,1300.0+rand()%2);
		glVertex2f(150.0+rand()%2,1350.0+rand()%2);
		glVertex2f(150.0+rand()%2,1210.0+rand()%2);		
		glVertex2f(50.0+rand()%2,1300.0+rand()%2);
		glVertex2f(250.0+rand()%2,1300.0+rand()%2);
		glVertex2f(100.0+rand()%2,1350.0+rand()%2);
		glVertex2f(200.0+rand()%2,1350.0+rand()%2);
		glVertex2f(150.0+rand()%2,1400.0+rand()%2);
		
	glEnd();
	
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POINTS);
		glVertex2f(1600.0+rand()%2,1650.0+rand()%2);
		glColor3f(0.0,1.0,0.0);
		glVertex2f(1630.0+rand()%2,1670.0+rand()%2);
		glColor3f(0.0,0.0,1.0);
		glVertex2f(1650.0+rand()%2,1700.0+rand()%2);
		glColor3f(0.0,1.0,0.0);
		glVertex2f(1630.0+rand()%2,1730.0+rand()%2);
		glColor3f(0.0,0.0,1.0);
		glVertex2f(1600.0+rand()%2,1750.0+rand()%2);
		glColor3f(0.0,1.0,0.0);
		glVertex2f(1560.0+rand()%2,1730.0+rand()%2);
		glColor3f(0.0,0.0,1.0);
		glVertex2f(1550.0+rand()%2,1700.0+rand()%2);
		glColor3f(0.0,1.0,0.0);
		glVertex2f(1560.0+rand()%2,1670.0+rand()%2);
		glColor3f(0.0,0.0,1.0);
		glVertex2f(1600.0+rand()%2,1700.0+rand()%2);
		
	glEnd();

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POINTS);
		glVertex2f(300.0+rand()%2,1650.0+rand()%2);		
		glVertex2f(330.0+rand()%2,1670.0+rand()%2);
		glVertex2f(300.0+rand()%2,1700.0+rand()%2);
		glVertex2f(330.0+rand()%2,1730.0+rand()%2);
		glVertex2f(300.0+rand()%2,1750.0+rand()%2);
		glVertex2f(260.0+rand()%2,1730.0+rand()%2);
		glVertex2f(250.0+rand()%2,1700.0+rand()%2);
		glVertex2f(260.0+rand()%2,1670.0+rand()%2);
		glVertex2f(300.0+rand()%2,1700.0+rand()%2);
		
	glEnd();
	
	glColor3f(0.0,1.0,0.0);
	glPointSize(3);
	glBegin(GL_POINTS);
		glVertex2f(1100.0+rand()%2,1800.0+rand()%2);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(1140.0+rand()%2,1830.0+rand()%2);
		glColor3f(0.0,1.0,0.0);
		glVertex2f(1140.0+rand()%2,1860.0+rand()%2);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(1100.0+rand()%2,1900.0+rand()%2);
		glColor3f(0.0,1.0,0.0);
		glVertex2f(1050.0+rand()%2,1860.0+rand()%2);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(1050.0+rand()%2,1830.0+rand()%2);
		glColor3f(0.0,1.0,0.0);
		glVertex2f(1100.0+rand()%2,1850.0+rand()%2);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(1070.0+rand()%2,1810.0+rand()%2);
		glColor3f(0.0,1.0,0.0);
		glVertex2f(1130.0+rand()%2,1810.0+rand()%2);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(1130.0+rand()%2,1880.0+rand()%2);
		glColor3f(0.0,1.0,0.0);
		glVertex2f(1070.0+rand()%2,1880.0+rand()%2);
	glEnd();
        glColor3f(0.8,0.5,0.5);
	glPointSize(3);
	glBegin(GL_POINTS);
		glVertex2f(2050.0+rand()%2,1300.0+rand()%2);
		
		glVertex2f(2050.0+rand()%2,1100.0+rand()%2);
		glVertex2f(2050.0+rand()%2,1150.0+rand()%2);
		glVertex2f(2050.0+rand()%2,1200.0+rand()%2);
		glVertex2f(2050.0+rand()%2,1250.0+rand()%2);

		glVertex2f(1960.0+rand()%2,1150.0+rand()%2);
		glVertex2f(1980.0+rand()%2,1200.0+rand()%2);
		glVertex2f(2010.0+rand()%2,1250.0+rand()%2);

		glVertex2f(1900.0+rand()%2,1200.0+rand()%2);
		glVertex2f(1950.0+rand()%2,1250.0+rand()%2);
		glVertex2f(2000.0+rand()%2,1300.0+rand()%2);

		glVertex2f(1850.0+rand()%2,1300.0+rand()%2);
		glVertex2f(1900.0+rand()%2,1300.0+rand()%2);
		glVertex2f(1950.0+rand()%2,1300.0+rand()%2);
		glVertex2f(2000.0+rand()%2,1300.0+rand()%2);
	
		glVertex2f(2000.0+rand()%2,1300.0+rand()%2);
		glVertex2f(1950.0+rand()%2,1350.0+rand()%2);
		glVertex2f(1900.0+rand()%2,1400.0+rand()%2);
		
		glVertex2f(2010.0+rand()%2,1350.0+rand()%2);
		glVertex2f(1980.0+rand()%2,1400.0+rand()%2);
		glVertex2f(1960.0+rand()%2,1450.0+rand()%2);
		
		glVertex2f(2050.0+rand()%2,1350.0+rand()%2);
		glVertex2f(2050.0+rand()%2,1400.0+rand()%2);
		glVertex2f(2050.0+rand()%2,1450.0+rand()%2);
		glVertex2f(2050.0+rand()%2,1500.0+rand()%2);

		glVertex2f(2090.0+rand()%2,1350.0+rand()%2);
		glVertex2f(2120.0+rand()%2,1400.0+rand()%2);
		glVertex2f(2140.0+rand()%2,1450.0+rand()%2);
		
		glVertex2f(2100.0+rand()%2,1300.0+rand()%2);
		glVertex2f(2150.0+rand()%2,1350.0+rand()%2);
		glVertex2f(2200.0+rand()%2,1400.0+rand()%2);
		
		glVertex2f(2100.0+rand()%2,1300.0+rand()%2);
		glVertex2f(2150.0+rand()%2,1300.0+rand()%2);
		glVertex2f(2200.0+rand()%2,1300.0+rand()%2);
		glVertex2f(2250.0+rand()%2,1300.0+rand()%2);

		glVertex2f(2100.0+rand()%2,1300.0+rand()%2);
		glVertex2f(2150.0+rand()%2,1250.0+rand()%2);
		glVertex2f(2200.0+rand()%2,1200.0+rand()%2);
		
		glVertex2f(2090.0+rand()%2,1250.0+rand()%2);
		glVertex2f(2120.0+rand()%2,1200.0+rand()%2);
		glVertex2f(2140.0+rand()%2,1150.0+rand()%2);		
	glEnd();
}
void fireworks()
{
	glColor3f(1.0,0.0,0.0);	
	if(m<1000)
	{
		m=m+3.0;

	glPointSize(6);
	glBegin(GL_POINTS);
		glVertex2f(150.0,500.0+m);
	glEnd();
	glBegin(GL_POINTS);
		glVertex2f(2050.0,500.0+m);
	glEnd();
	
	}
	else  
	blast();
	
	glutPostRedisplay();
}
void night()
{	
        // to set the background color to black
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	        glVertex2f(2200,2200);
	        glVertex2f(0,2200);
	        glVertex2f(0,0);
	        glVertex2f(2200,0);
	glEnd();

	//to draw the moon
	glPointSize(9.0);
	glColor3f(1.0,1.0,1.0);
	circle_draw(1400,2000+s,100);
	circle_draw(1400,2000+s,90);
	circle_draw(1400,2000+s,70);
	circle_draw(1400,2000+s,50);
	circle_draw(1400,2000+s,30);
	circle_draw(1400,2000+s,10);
	glPointSize(5.0);

	//to draw the stars
	glBegin(GL_POINTS);
	        glVertex2f(900,1700);
	        glVertex2f(400,1700);
	        glVertex2f(80,2100);
	        glVertex2f(200,1800);
	        glVertex2f(1800,1700);
	        glVertex2f(1180,2150);
	        glVertex2f(2000,1750);
	        glVertex2f(970,1900);
	        glVertex2f(710,2000);
	        glVertex2f(600,1950);
	        glVertex2f(200,1800);
	        glVertex2f(1600,1750);
	        glVertex2f(1700,1900);
	        glVertex2f(2000,2100);
	glEnd();
	glColor3f(0.7,0.7,0.7);

	//to draw street light for NIGHT
	glColor3f(0.10,0.10,0);
	glBegin(GL_POLYGON);
	        glVertex2f(1400,0);
	glColor3f(0.1,0.1,0);
	        glVertex2f(1425,0);
	glColor3f(0.1,0.1,0);
	        glVertex2f(1425,250);
	        glVertex2f(1400,250);
	glEnd();
	glColor3f(1,1,1);
	circle_draw(1410,280,30);
	circle_draw(1410,280,10);
	glColor3f(0.1,0.1,0);
	
	glBegin(GL_POLYGON);
	glVertex2f(1600,200);
	glColor3f(0.10,0.10,0);
	        glVertex2f(1625,200);
	glColor3f(0.10,0.10,0);
	        glVertex2f(1625,350);
	        glVertex2f(1600,350);
	glEnd();
	glColor3f(1,1,1);
	circle_draw(1610,380,30);
	circle_draw(1610,380,10);
	glColor3f(0.10,0.10,0);
	
	glBegin(GL_POLYGON);
	        glVertex2f(1800,380);
	glColor3f(0.10,0.10,0);
	        glVertex2f(1825,380);
	glColor3f(0.10,0.10,0);
	        glVertex2f(1825,525);
	        glVertex2f(1800,525);
	glEnd();
	glColor3f(1,1,1);
	circle_draw(1810,555,30);
	circle_draw(1810,555,10);
	glColor3f(0.10,0.10,0);
	
	glBegin(GL_POLYGON);
	        glVertex2f(2000,500);
	glColor3f(0.10,0.10,0);
	        glVertex2f(2025,500);
	glColor3f(0.10,0.10,0);
	        glVertex2f(2025,650);
	        glVertex2f(2000,650);
	glEnd();
	glColor3f(1,1,1);
	circle_draw(2010,680,30);
	circle_draw(2010,680,10);

	drawtree2();
	road();
	house_night();
	diyas_night();
	tulsi_night();
        fireworks();
        //textbox
        glColor3ub(0,0,0);
        glBegin(GL_POLYGON);
                glVertex2f(0,0);
                glVertex2f(2200,0);
                glVertex2f(2200,100);
                glVertex2f(0,100);
        glEnd();
        glColor3ub(255,153,153);
        drawstring(800,40,0,"DIWALI,THE FESTIVAL OF LIGHTS!");
        glFlush();
}
void mainmenu(int id)
{
	switch(id)
	{
		case 1:glob=1;
			break;
		case 2:glob=2;
			break;
		case 3:glob=3;
			break;
	}
	glutPostRedisplay();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	      intro();	
	if(glob==1){
		day();
		showIntro = 2;
        }
	if(glob==2)
		night();
        
	if(glob==3){	        
	        arrow();
	        glutKeyboardFunc(keyPressed);
	}
	if(cur_win == 2){
	        moving_arrow();
                glutKeyboardFunc(keyPressed);
	}	
	if(cur_win == 3){
	        glutSetWindowTitle("Diwali Celebrations");
	        kids();
	        glutKeyboardFunc(keyPressed);
	}
	if(cur_win == 4){
               glutSetWindowTitle("Let's not forget our nature this Diwali !"); 
	       trees();
        }
        if(cur_win == 5){
                glutSetWindowTitle("Say NO to Crackers!");
	        earth();
                			
	        glutKeyboardFunc(keyPressed); 
	}			
	glFlush();
	glutSwapBuffers();
}

void init()
{	glClearColor(0.8,0.5,0,1);
	glColor3f(1,0,0);
	glPointSize(5);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,2200,0,2200);
	glutPostRedisplay();

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   	glEnable( GL_BLEND );
    	loadTexture(&bgTexture5, "earth.jpg"); 
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Diwali");
	init();
	glutCreateMenu(mainmenu);
	glutAddMenuEntry("DAY VIEW",1);
	glutAddMenuEntry("NIGHT VIEW",2);
	glutAddMenuEntry("STORY OF DIWALI",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(display);
        //glutIdleFunc(spin);
	glutMainLoop();	
}

