
#include <windows.h>
#include<string.h>
#include<stdarg.h>
#include<stdio.h>
#include<GL/glut.h>

void *font;
void *currentfont;
static double x=0.0,x1=-3.5,x2=3.5,y1=-1.4,y2=-1.4,x3=-3.5,y3=1.3;
static double move=-60;
static bool goDown=false,goup=false,down=false,congested=false,remote=false;

void setFont(void *font)
{
	currentfont=font;
}

void drawstring(float x,float y,float z,char *string)
{
	char *c;
	glRasterPos3f(x,y,z);
 
	for(c=string;*c!='\0';c++)
	{	glColor3f(0.0,1.0,1.0);
		glutBitmapCharacter(currentfont,*c);
	}
}

void 
stroke_output(GLfloat x, GLfloat y, char *format,...)
{
	va_list args;
	char buffer[200], *p;
	va_start(args, format);
	vsprintf(buffer, format, args);
	va_end(args);
	glPushMatrix();
	glTranslatef(x, y,2);
	glScaled(0.003, 0.005, 0.005);
	for (p = buffer; *p; p++)
    glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
	glPopMatrix();
}


void cloud(){


	//vertical eclipse
	glPushMatrix();
	glTranslatef(0.0,0.0,0.0);
	glScaled(1,3.5,0.1);
	glColor3f(1,1,1);
	glutSolidSphere(1,100,100);
	glPopMatrix();
	
	//horizotal eclipse
	glPushMatrix();
	glTranslatef(0.0,0.0,0.0);
	glScaled(3,2.65,0.1);
	glColor3f(1,1,1);
	glutSolidSphere(1,100,100);
	glPopMatrix();

	glPushMatrix();
	glScaled(3.5,1.8,0.1);
	glRotatef(60,0.0f,1.0f,1.0f);
	glTranslatef(0.0,0.0,0.0);
	glColor3f(1,1,1);
	glutSolidSphere(1,100,100);
	glPopMatrix();

	glPushMatrix();	
	glScaled(1.5,3.5,0.1);
	glRotatef(50,0.0f,1.0f,1.0f);
	glTranslatef(0.0,0.0,0.0);
	glColor3f(1,1,1);
	glutSolidSphere(1,100,100);
	glPopMatrix();
}


void router(float x6, float y6,float z6)
{
	
    glColor3f(0.2,0.3,1);
	glPushMatrix();
	glScaled(0.2,1.0,0.1);
    glRotatef(91,1.0f,0.0f,0.0f);
	glTranslatef(x6,y6,z6);
	glutSolidTorus(0.2,1.5,100,100);
	glPopMatrix();
}

void dte(float x1, float x2)
{
	glPushMatrix();
	glTranslatef(x1,x2,0.1);
	glScaled(1,0.1,0.1);
	glColor3f(1,1,1);
	glRotatef(0,0.0f,1.0f,0.0f);
	glutWireCube(1.5);
	glPopMatrix();
}

void line()
{
glPushMatrix();
    glBegin(GL_LINE_LOOP);
	glColor3f(1,0,0);
	glVertex3f(0.1,-0.2,1);
	glVertex3f(0.0,0,1);
	glVertex3f(2,1.3,1);
	glVertex3f(2.1,1.1,1);
	glEnd();
glPopMatrix();
}

void line1()
{
glPushMatrix();
    glBegin(GL_LINE_LOOP);
	glColor3f(1,0,0);
	glVertex3f(0.2,2.5,1);
	glVertex3f(0.1,2.3,1);
	glVertex3f(2.1,1.1,1);
	glVertex3f(2.3,1.2,1);
	glEnd();
glPopMatrix();
}

void rack(float x1, float x2)
{
glPushMatrix();
	glScaled(0.35,.05,1.0);
	glTranslatef(x1,x2,0.1);
	glColor3f(0,0,0.3);
	glutSolidCube(1.1);
	glPopMatrix();
}

void rack1(float x1, float x2)
{
glPushMatrix();
	glScaled(1.75,.1,1.0);
	glTranslatef(x1,x2,0.3);
	glColor3f(0,0,1.3);
	glutSolidCube(0.5);
	glPopMatrix();
}

void window(float x1, float x2)
{
glPushMatrix();
	glScaled(0.5,.3,1.0);
	glTranslatef(x1,x2,0.4);
	glColor3f(0.1,0.1,0.1);
	glutSolidCube(0.5);
	glPopMatrix();
}

void top()
{
glBegin(GL_TRIANGLES);
    
    /* Front */
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3f( 0.0f, 1.0f, 0.0f);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3f(-0.5f,-0.5f, 0.5f);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3f( 0.5f,-0.5f, 0.5f);
 
    /* Left */
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3f(0.0f,1.0f,0.0f);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3f(-0.5f,-0.5f,0.5f);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3f(-0.5f,-0.5,-0.5f);
        
    /* Right */
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3f(0.0f,1.0f,0.0f);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3f(0.5f,-0.5f,0.5f);
    glColor3f(1.0f,1.0f,1.0f);
	glVertex3f(0.5f,-0.5,-0.5f);
                
    /* Back */
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3f( 0.0f, 1.0f, 0.0f);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3f(-0.5f,-0.5f, -0.5f);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3f( 0.5f,-0.5f, -0.5f);
    glEnd();
}

void animate();

void network()
{
   glClearColor(0.0,0,0,0.0);
  //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  	glLoadIdentity();
    glTranslatef(0.0f,0.0f,-13.0f);
  
	// glRotatef(ang,1.0f,1.0f,0.0f);   
	
	//Server
	glPushMatrix();
	glScaled(0.8,2.0,0.8);
	glTranslatef(5,0.8,0.0);
	glColor3f(0,1.5,1.5);
	glutSolidCube(1);
	
	glPushMatrix();
	glScaled(0.5,.1,1.0);
	glTranslatef(.0,3.5,0.01);
	glColor3f(0.3,0.3,0.3);
	glutSolidCube(1.5);
	glPopMatrix();

	rack1(.0,1);
	rack1(.0,2);
	rack1(.0,0);
	
	rack(-1,-4);
	rack(1,-4);
	rack(-1,-6);
	rack(1,-6);
	rack(-1,-8);
	rack(1,-8);
	
	glPopMatrix();

	//Home
	glPushMatrix();
	glScaled(0.8,1.0,0.8);
	glTranslatef(4.8,-2.5,0.0);
	glColor3f(1,1,0);
	glutSolidCube(1);
	

	glPushMatrix();
	glScaled(.7,.1,1.0);
	glTranslatef(0.0,4.5,0.2);
	glColor3f(1.3,1.3,1.3);
	glutSolidCube(1.5);
	glPopMatrix();

	
	glPushMatrix();
	glScaled(0.12,.3,.75);
	glTranslatef(0,-.75,0.02);
	glColor3f(0.3,0.3,0.3);
	glutSolidCube(1.5);
	glPopMatrix();
//home2
	glPushMatrix();
	glScaled(0.8,1.0,0.8);
	glTranslatef(4.8,-2.5,0.0);
	glColor3f(1,1,0);
	glutSolidCube(1);
	

	glPushMatrix();
	glScaled(.7,.1,1.0);
	glTranslatef(0.0,4.5,0.2);
	glColor3f(1.3,1.3,1.3);
	glutSolidCube(1.5);
	glPopMatrix();

	
	glPushMatrix();
	glScaled(0.12,.3,.75);
	glTranslatef(0,-.75,0.02);
	glColor3f(0.3,0.3,0.3);
	glutSolidCube(1.5);
	glPopMatrix();
	// Top
	glPushMatrix();
	glTranslatef(0,.9,0);
	top();
	glPopMatrix();
	window(-.6,-.3);
	glPopMatrix();

	//Office Building
	glPushMatrix();
	glScaled(0.8,2.0,0.8);
	glTranslatef(-4.8,-1,0.0);
	glColor3f(2,.5,.5);
	glutSolidCube(1);
 
	window(-.5,1.3);
	window(.5,1.3);
	window(-.5,0.5);
	window(.5,0.5);
	window(-.5,-0.3);
	window(.5,-0.3);
	window(-.5,-1.1);
	window(.5,-1.1);

	glPopMatrix();


// Remote User
	
	glPushMatrix();
	glTranslatef(-4.0,1.5,0.0);
	glScaled(0.3,.3,.3);
	glColor3f(1.3,1.3,1.3);
	glutSolidCube(0.5);
	glPopMatrix();


// Routers inside cloud
    
	//router 5
	router(10,10,1.15);

	//router 2
	router(-10,10,-1.3);
	
	//router 1
	router(-10,10,1.2);
	
	//router 3
	router(0,10,-2.5);
	
	router(0,10,0);
	
	//router 5
	router(0,10,2.5);
	
	//router 4
	router(10.6,10,-1.2);

	// Line 1
	glPushMatrix();
	glTranslatef(-2.1,0.0,0.5);
	glScaled(0.1,1.8,0.1);
	glColor3f(1,0,0);
	glutWireCube(1.5);
	glPopMatrix();
		
	// Link 2
	glPushMatrix();
	glTranslatef(-2,1.15,0);
	line();
	glPopMatrix();
	//mine
	// glPushMatrix();
	// glTranslatef(-2,1.15,0);
	// // glRotatef(30,0,0,1);
	// glScaled(1.15,1.7,0.1);
	// line();
	// glRotatef(0,130,0,1);
	// glPopMatrix();

	// Link 3 to server
	glPushMatrix();
	glTranslatef(1.2,1.7,0.5);
	glRotatef(57,0,0,1);
	glScaled(0.15,1.7,0.1);
	glColor3f(1,0,0);
	glutWireCube(1.5);
	glPopMatrix();

	// Link 4
	glPushMatrix();
	glTranslatef(0.85,0.4,0.5);
	glRotatef(120,0,0,1);
	glScaled(0.2,1.7,0.1);
	glColor3f(1,0,0);
	glutWireCube(1.5);
	glPopMatrix();

	// Link 5
	glPushMatrix();
	glTranslatef(0,-2.6,0);
	line();
	glPopMatrix();

	// Link 6	
	glPushMatrix();
	glTranslatef(-2.2,-3.85,0);
	line1();
	glPopMatrix();

	// Link 6	mine
	

	// Link 7(1step data transfer from ...)
	glPushMatrix();
	glTranslatef(-1.2,-0.85,0.5);
	glRotatef(125,0,0,1);
	glScaled(0.15,1.6,0.1);
	glColor3f(1,0,0);
	glutWireCube(1.5);
	glPopMatrix();

	// Link 9
	glPushMatrix();
	glTranslatef(0.0,1.0,0.5);
	glScaled(0.1,1.65,0.1);
	glColor3f(1,0,0);
	glutWireCube(1.5);
	glPopMatrix();
	
	//R0 - R6
	glPushMatrix();
	glTranslatef(0.0,-1.6,0.5);
	glScaled(0.1,1.65,0.1);
	glColor3f(1,0,0);
	glutWireCube(1.5);
	glPopMatrix();

	//link 10 from home
	glPushMatrix();
	glTranslatef(1.05,-0.8,0.5);
	glRotatef(52,0,0,1);
	glScaled(0.15,1.6,0.1);
	glColor3f(1,0,0);
	glutWireCube(1.5);
	glPopMatrix();
	
	
	// Link11
	glPushMatrix();
	glTranslatef(-1.05,0.6,0.5);
	glRotatef(57,0,0,1);
	glScaled(0.15,1.6,0.1);
	glColor3f(1,0,0);
	glutWireCube(1.5);
	glPopMatrix();

	// Office Link to Cloud 
	dte(-3.0,-1.4);

	// Home Link to Cloud 
	dte(3.0,-1.4);
	dte(-3.0,1.3);

	// Server Link to Cloud 
	dte(3.0,1.1);
	

	//Cloud Call Function
    cloud();
	
	
	glPushMatrix();
	
	//glScaled(1.1,2.0,0.1);
	glTranslatef(0.0,0.0,2.0);
	
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0,0,0);
	drawstring(-0.3,2.5,0.0,"CLOUD");

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0,0,0);
	drawstring(-2.1,-1.4,0.0,"R1");
	
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0,0,0);
	drawstring(-2.05,0.95,0.0,"R2");

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0,0,0);
	drawstring(0,2,0.0,"R3");

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0,0,0);
	drawstring(-0.1,-0.3,0.0,"R0");
	
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0,0,0);
	drawstring(1.8,0.8,0.0,"R4");
	
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0,0,0);
	drawstring(1.8,-1.35,0.0,"R5");
	
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0,0,0);
	drawstring(0,-2.6,0.0,"R6");

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0,0,0);
	drawstring(3,-2.0,0.0,"HACKER A");

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1,1,1);
	drawstring(-3.5,2,0.0,"HACKER B");

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.5,1.5,1.5);
	drawstring(-3.7,-0.8,0.0,"OFFICE");

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.5,1.5,1.5);
	drawstring(3,2.3,0.0,"SERVER");
	
	glPopMatrix();


	//Transtitions all together

	animate();
	
	glFlush();
   
	glutSwapBuffers();

}

	void animate(){

		
		// Company to server Using path 1

    glPushMatrix();
	glTranslatef(x1,y1,0.2);
	glScaled(0.1,0.1,0.1);
	glColor3f(0,0,1);
	glutSolidCube(0.5);
	glPopMatrix();
	
	if(remote){
	
	glPushMatrix();
	glTranslatef(x3,y3,0.2);
	glScaled(0.1,0.1,0.1);
	glColor3f(1,0,0.5);
	glutSolidCube(0.5);
	glPopMatrix();
		
	}

	if(congested)
	{
	
	glPushMatrix();
	glTranslatef(x2,y2,0.2);
	glScaled(0.1,0.1,0.1);
	glColor3f(4,0,0);
	glutSolidCube(0.5);
	glPopMatrix();

    }
	

	}


void about()
{
	glClearColor(0,0,0,0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f,0.0f,-13.0f);
	
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1,1,1);
	drawstring(-4.2,2,0.0,"About Congestion Control");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	
	drawstring(-3.5,1.5,0.0,"* Congestion is a situation in Communication Networks in which too many packets");
	
	drawstring(-3.5,1,0.0,"   are present in a part of the subnet, performance degrades.");

	drawstring(-3.5,.5,0.0,"* In data networking network congestion occurs when a link or node ");
	
	drawstring(-3.5,0.0,0.0,"   is carrying so much data that its quality of service deteriorates.");
	
	drawstring(-3.5,-0.5,0.0,"* Congestion control concerns controlling traffic entry into a ");
	
	drawstring(-3.5,-1,0.0,"   telecommunications network, so as to avoid congestive collapse by attempting ");
	
	drawstring(-3.5,-1.5,0.0,"   to avoid oversubscription of any of the processing or link capabilities ");
	
	drawstring(-3.5,-2,0.0,"   of the intermediate nodes and networks and taking resource reducing steps, ");
	
	drawstring(-3.5,-2.5,0.0,"   such as reducing the rate of sending packets.");
	
	drawstring(-3.5,-3,0.0,"* It should not be confused with flow control, which prevents the sender from overwhelming the receiver.");
		
	glFlush();
    glutSwapBuffers();
}

void s()
{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

network();
}

void com_ser(){

// No congestion, take the best path

if(!congested && !remote)
{
	if(x1>=-3.5 && y1==-1.4 && x1<=-2)
	{
	x1+=0.1;
	}

	if(x1>=-2 && y1>=-1.4 && x1<=2 && y1<=1.8)
	{
	x1+=0.1;
	y1+=0.065;
	}

	if(x1>=2 && y1>=1 && x1<=3.8)
	{
	x1+=0.1;
	y1=1.1;
	}

}

//if Congested only from Hacker A

if(congested && x2>=2 && y2>=1 && !remote)
{
	if(x1>=-3.5 && y1==-1.4 && x1<=-2){
	x1+=0.1;
	
	}


	if(x1>=-2 && y1>=-1.4 && x1<=0 && y1<=0){
	x1+=0.1;
	y1+=0.07;
	}
	
	if(x1>=-0.05 && x1<=0.05 && y1<=0.05 && y1>=-0.05){
	x1=0;
	y1=0;
	}
	
	
	if(x1==0 && y1>=0 && y1<=2.6){
	
	y1+=0.06;
	

	}

	if(x1==0 && y1>=2.5)
		goDown=true;
	
	if(goDown && x1>=0 && x1<=2 && y1<=2.6 && y1>=1 ){
	x1+=0.1;
	y1-=0.06;
	}

	if(x1>=2 && y1>=1 && x1<=3.8){
	x1+=0.1;
	y1=1.1;
	}
}

// if congested only from Hacker B

if(remote && y3<=1 && !congested)
{
	if(x1>=-3.5 && y1==-1.4 && x1<=-2){
	x1+=0.1;

	}


	if(x1>=-2  && x1<=-0.2 && y1<=-1.4 && y1>=-3){
	x1+=0.1;
	y1-=0.08;
	}
	
	if(x1>=-0.3 && x1<=-0.2 && y1<=-2.7 && y1>=-3 && goup==false){
	x1=0;
	y1=-3;
	goup=true;
	}

	if(goup && y1<=0){
	x1=0.0;
	y1+=0.1;
	
	}


	if(goup && x1>=0 && y1>=0 && x1<=2 && y1<=1.8)
	{
	x1+=0.1;
	y1+=0.055;
	}

	if(x1>=2 && y1>=1 && x1<=3.8)
	{
	x1+=0.1;
	y1=1.1;
	}


}

// if congested  from both Hackers 

if(remote && y3<=1 && congested)
{
	if(x1>=-3.5 && y1==-1.4 && x1<=-2){
	x1+=0.1;

	}


	if(x1>=-2  && x1<=-0.2 && y1<=-1.4 && y1>=-3){
	x1+=0.1;
	y1-=0.08;
	}
	
	if(x1>=-0.3 && x1<=-0.2 && y1<=-2.7 && y1>=-3 && goup==false){
	x1=0;
	y1=-3;
	goup=true;
	}

	if(goup && y1<=2.6 && goDown==false){
	x1=0.0;
	y1+=0.1;
	}
	
	if(x1==0 && y1>=2.5)
		goDown=true;
	
	if(goDown && x1>=0 && x1<=2 && y1<=2.6 && y1>=1 ){
	x1+=0.1;
	y1-=0.06;
	}

	if(x1>=2 && y1>=1 && x1<=3.8){
	x1+=0.1;
	y1=1.1;
	}
	
	
}



//congest the server link1, From hacker A to R


if(congested){

	if(x2<=3.5 && y2==-1.4 && x2>=1.8)
	{
	x2-=0.1;
	}
	
	if(x2<1.8 && x2>=0 && y2<=0 && y2>=-1.4 )
	{
	x2-=0.1;
	y2+=0.08;
	}

	if(x2>=-0.05 && x2<=0.051 && y2<=0.051 && y2>=-0.051){
	x2=0;
	y2=0;
	}
	

	if(x2>=0 && y2>=0 && x2<=2 && y2<=1.8){
	x2+=0.1;
	y2+=0.06;
	}


}



// Congest from Hacker B to Company

if(remote)
{
	if(x3>=-3.5 && y3==1.3 && x3<=-2)
	{
	x3+=0.1;
	}

	if(x3>=-2 && y3<=1.3 && x3<=1.5 && y3>=-1.5 && !down)
	{
	x3+=0.1;
	y3-=0.065;
	
	}
	if(x3>=0.0 && y3<=0.0){
	x3=0;y3=0;down=true;
	}

	if(x3<=0 && x3>=-2 &&  y3>=-1.4 && down)
	{
	x3-=0.1;
	y3-=0.065;
	}

}


		
network();



}



void doInit() 
{
    
	/* Background and foreground color */
    glClearColor(0.0,0.0,0.0,0);
       glViewport(0,0,640,480);
 
	/* Select the projection matrix and reset it then
     setup our view perspective */

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0f,(GLfloat)640/(GLfloat)480,0.1f,200.0f);  
	
    /* Select the modelview matrix, which we alter with rotatef() */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearDepth(2.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}


void display()
{
	glClearColor(0.0,0.,0.,0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(0.0f,0.0f,-13.0f);

	
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(3.0,1.0,1.0);
	drawstring(-2.2,1.5,0.0,"DEPARTMENT OF COMPUTER SCIENCE");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0.0,1.0,1.0);
	drawstring(-1.7,1.1,0.0,"Computer Graphics Mini Project on");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0.0,1.0,1.0);
	drawstring(-1.4,0.6,0.0,"CONGESTION CONTROL");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.0,1.0,1.0);
	drawstring(-1.4,0.2,0,"  Using OPENGL and C++");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.0,1.0,1.0);
	drawstring(-0.5,-0.4,0,"By");

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.0,1.0,1.0);
	drawstring(-2,-0.9,0,"ABHISHEK D M (USN : 4RA21CS001)");

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.0,1.0,1.0);
	drawstring(-2,-1.4,0,"DARSHAN B R (USN : 4RA21CS015)");
	

	drawstring(-1,-1.9,0,"Press --> s  to Start");
	drawstring(-1,-2.4,0,"Press --> q  to Quit");
	

	GLfloat mat_ambient[]={0.0f,1.0f,2.0f,1.0f};
	GLfloat mat_diffuse[]={0.0f,1.5f,.5f,1.0f};
	GLfloat mat_specular[]={5.0f,1.0f,1.0f,1.0f};
	GLfloat mat_shininess[]={50.0f};

	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	
	GLfloat lightIntensity[]={1.7f,1.7f,1.7f,1.0f};
	GLfloat light_position3[]={0.0f,5.0f,5.0f,0.0f};

	glLightfv(GL_LIGHT0,GL_POSITION,light_position3);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);

	glEnable(GL_COLOR_MATERIAL);

	glFlush();
	glutSwapBuffers();
    
}



void menu(int id)
{
	switch(id)
	{
	case 1:
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glutIdleFunc(s);
		break;
	
	case 2:	
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		goDown=false;
		goup=false;
		x=0.0;x1=-3.5;y1=-1.4;
		x2=3.5;
		y2=-1.4;
		glutIdleFunc(com_ser);
		break;

		case 3:
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			goDown=false;
			down=false;
			goup=false;
			x=0.0;x1=-3.5;y1=-1.4;
			x2=3.5;
			y2=-1.4;
			x3=-3.5,y3=1.3;
			congested=true;
			glutIdleFunc(com_ser);
		break;

		case 4:	
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		goDown=false;
		down=false;
		goup=false;
		x=0.0;x1=-3.5;
		x2=3.5;
		y1=-1.4;
		y2=-1.4;
		x3=-3.5;y3=1.3;
		remote=true;	
			glutIdleFunc(com_ser);
		break;

		case 5: congested=false;
		goDown=false;down=false;
		goup=false;
		x=0.0;x1=-3.5;
		x2=3.5;
		y1=-1.4;
		y2=-1.4;
		x3=-3.5;y3=1.3;
				glutIdleFunc(com_ser);
			break;

			
		case 6: remote=false;
		down=false;
		goDown=false;
		goup=false;
		x=0.0;x1=-3.5;
		x2=3.5;
		y1=-1.4;
		y2=-1.4;
		x3=-3.5;y3=1.3;
				glutIdleFunc(com_ser);
			break;

		case 7:
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glutIdleFunc(about);
		break;

		case 8:exit(0);
		break;
	
	}
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}


void mykey(unsigned char key,int x,int y)
{

	
	if(key=='s')
	{
		glutIdleFunc(s);
	}


	if(key=='q'||key=='Q')
	{
		exit(0);
	}

	
}


int main(int argc, char *argv[]) 
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(1000,480);
    glutInitWindowPosition(0,0);
    glutCreateWindow("conjestion control");
    glutDisplayFunc(display);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	glutKeyboardFunc(mykey);

	glutCreateMenu(menu);

	glutAddMenuEntry("Send Some Data",2);
	glutAddMenuEntry("Create Congestion From Hacker A",3);
	glutAddMenuEntry("Create Congestion From Hacker B",4);
	glutAddMenuEntry("Remove Congestion From Hacker A ",5);
	glutAddMenuEntry("Remove Congestion From Hacker B ",6);
    glutAddMenuEntry("About Project       'a/A'",7);
	glutAddMenuEntry("Quit            'q'",8);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	doInit();

    glutMainLoop();
 
}