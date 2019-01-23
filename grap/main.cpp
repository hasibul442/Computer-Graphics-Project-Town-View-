#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>

#include<math.h>

static float	tp3	=  0;
static float	pm=  300.0;
static float	bm=  350.0;
static float	tm=  300.0;
static float	cm=  -300.0;
float spin = 0.0;

GLfloat	tx	=  5;
GLfloat	ty	=  5;



void circle(GLfloat rx,GLfloat ry,GLfloat x,GLfloat y)
{
    int i;
    float rad = 0;
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(i = 0;i<=360; i++){
    rad = i*(3.1416/180);
    glVertex2f(x+rx*cos(rad),y+ry*sin(rad));

    }
    glEnd();


}

void sun()
{
    glPushMatrix();
    glTranslated(270,260,0);
    glColor3f(1.0, 0.76, 0.3);
    circle(20,30,0,0);
    glPopMatrix();
}
void make_cloud(int x, int y)
{

    glColor3f(1.0, 1.0, 1.0);
    circle(10,10,x,y);
    circle(10,10,x+10,y);
    circle(10,10,x+30,y);
    circle(10,10,x+5,y-10);
    circle(10,10,x+20,y-10);
    circle(10,10,x+5,y+10);
    circle(10,10,x+20,y+10);

}

void cloud_move_right(GLfloat t){
    tp3=tp3+t;
    if(tp3>600)
        tp3 = -300;
    glutPostRedisplay();
}


void cloud()
{
    glPushMatrix();
    glTranslatef(tp3,0,0);
    make_cloud(-300,280);
    make_cloud(-500,280);
    make_cloud(-200,250);
    make_cloud(-400,250);
    make_cloud(200,250);
    make_cloud(-100,250);
    make_cloud(-350,230);
    glPopMatrix();
    cloud_move_right(.1);

    glEnd();
}

void rectangle(int x, int y, int x1, int y1)
{
    glBegin(GL_QUADS);
        glVertex2d(x,y);
        glVertex2d(x,y1);
        glVertex2d(x1,y1);
        glVertex2d(x1,y);


    glEnd();
}

void triangle(int x, int y, int x1, int x2,int y1)
{
    glBegin(GL_POLYGON);
        glVertex2d(x,y);
        glVertex2d(x1,y);

        glVertex2d(x1,y);
        glVertex2d(x2,y1);

        glVertex2d(x2,y1);
        glVertex2d(x,y);
        glEnd();
}
void rectangle1(int x1,int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    glBegin(GL_QUADS);
        glVertex2d(x1,y1);
        glVertex2d(x3,y3);
        glVertex2d(x4,y4);
        glVertex2d(x2,y2);
        glEnd();
}

void hill()
{
    glColor3f(0.5, 0.87, 1.0);
    circle(70,120,-250,90);
    circle(70,120,-100,90);
    circle(70,120,50,100);
    circle(70,120,200,90);
}

void soil()
{
    glColor3f(0.75, 0.75, 0.75);
    rectangle(-300,-10,300,130);
}


void ground()
{
     glColor3f(0.3, 1.0, 0.53);
     rectangle(-300,-300,300,-10);

}
void road()
{
        //Road Area
        glColor3f(0.3, 0.3, 0.3);
        rectangle(-300,-200,300,-30);
        //road side broader up
        glColor3f(0.0, 0.0, 0.0);
        rectangle(-300,-30,300,-33);
        //road side broader down
        glColor3f(0.0, 0.0, 0.0);
        rectangle(-300,-205,300,-200);
        //divider
        glColor3f(1.0, 1.0, 1.0);
        rectangle(-270,-120,-230,-110);

        //divider
        glColor3f(1.0, 1.0, 1.0);
        rectangle(-270,-120,-200,-110);
        //divider
        glColor3f(1.0, 1.0, 1.0);
        rectangle(-150,-120,0,-110);

        //divider
        glColor3f(1.0, 1.0, 1.0);
        rectangle(50,-120,150,-110);
        //divider
        glColor3f(1.0, 1.0, 1.0);
        rectangle(200,-120,290,-110);

}

void flag()
{
        //flag stand
        glColor3f(0.0, 0.0, 0.0);
        rectangle(-170,-9,-167,125);
        //flag area
        glColor3f(0.18, 0.72, 0.18);
        rectangle(-167,75,-120,125);

        //flag circle
        glColor3f(0.9, 0.0, 0.0);
        circle(10,20,-143,100);
}


void shaheed_minar()
{
    glColor3f(0.0, 0.0, 0.0);
    rectangle(-270,-9,-268,60);
    rectangle(-262,-9,-260,60);
    rectangle(-268,58,-260,60);

    rectangle(-255,-9,-253,65);
    rectangle(-247,-9,-245,65);
    rectangle(-255,62,-245,65);

    glColor3f(0.9, 0.0, 0.0);
    circle(12,20,-231,40);

    glColor3f(0.0, 0.0, 0.0);
    rectangle(-240,-9,-238,75);
    rectangle(-232,-9,-230,75);
    rectangle(-224,-9,-222,75);
    rectangle(-240,73,-222,75);

    rectangle(-217,-9,-215,65);
    rectangle(-209,-9,-207,65);
    rectangle(-217,62,-207,65);

    rectangle(-202,-9,-200,60);
    rectangle(-194,-9,-192,60);
    rectangle(-202,58,-192,60);

}
void tree(int a,int b,int c,int d, int e,int f,int g, int h , int i)
{
   glColor3f(0.25, 0.25, 0.25);
   rectangle(a,b,c,d);
   glColor3f(0.0, 0.3, 0.0);
   triangle(e,f,g,h,i);

}
void tree1()
{
    tree(-200,110,-202,140,-195,140,-205,-200,170); //1
    tree(-300,110,-298,140,-305,140,-293,-299,170); //2
    tree(-270,110,-268,140,-275,140,-263,-269,170); //3
    tree(-240,110,-238,140,-245,140,-233,-239,170); //4
    tree(-210,110,-208,140,-215,140,-203,-209,170); //5
    tree(-180,110,-178,140,-185,140,-173,-179,170); //6
    tree(-150,110,-148,140,-155,140,-143,-149,170); //7
    tree(-120,110,-118,140,-125,140,-113,-119,170); //8
    tree(-90,110,-88,140,-95,140,-83,-89,170); //9
    tree(-60,110,-58,140,-65,140,-53,-59,170); //10
    tree(-30,110,-28,140,-35,140,-23,-29,170); //11
    tree(0,110,2,140,-5,140,7,1,170); //12
    tree(30,110,32,140,25,140,37,31,170); //13
    tree(60,110,62,140,55,140,67,61,170); //14
    tree(90,110,92,140,85,140,97,91,170);
    tree(120,110,122,140,115,140,127,121,170);
    tree(150,110,152,140,145,140,157,151,170);
    tree(180,110,182,140,175,140,187,181,170);
    tree(210,110,212,140,205,140,217,211,170);
    tree(240,110,242,140,235,140,247,241,170);
    tree(270,110,272,140,265,140,277,271,170);
    tree(300,110,302,140,295,140,307,301,170);
    tree(330,110,332,140,325,140,337,331,170);


}

void college()
{
    glColor3f(1.0, 1.0, 0.3);
    rectangle(-100,-9,60,120);
    glColor3f(0.0, 0.0, 0.7);
    rectangle1(-100,120,60,120,-90,140,70,140);//top
    glColor3f(0.4, 1.0, 1.0);
    rectangle1(60,-9,70,0,60,120,70,140);

        glColor3f(0, 0, 0);
        rectangle(-35,-9,-5,30);
        rectangle(-90,100,-70,80);
        rectangle(-60,100,-40,80);
        rectangle(-30,100,-10,80);
        rectangle(0,100,20,80);
        rectangle(30,100,50,80);

        rectangle(-90,70,-70,50);
        rectangle(-60,70,-40,50);
        rectangle(-30,70,-10,50);
        rectangle(0,70,20,50);
        rectangle(30,70,50,50);


}
void make_plane()
{
    glColor3f(0.0, 0.0, 0.0);
    circle(20,15,0,0);
    rectangle(0,-15,70,15);
    glColor3f(0.0, 0.0, 0.0);
    rectangle1(70,-15,90,35,70,15,90,40);
    glColor3f(1.0, 0.0, 0.0);
    rectangle1(30,15,50,15,60,35,55,30);

glColor3f(1.0, 1.0, 1.0);
circle(5,5,10,0);
circle(5,5,30,0);
circle(5,5,50,0);
circle(5,5,65,0);
rectangle(-5,-5,0,10);


}

void planeMove(){
pm=pm-.5;
    if(pm<-500)
        pm = 300;
        glutPostRedisplay();
}

void plane()
{
    planeMove();
    for(int i=0;i<1;i++)
     {

     glPushMatrix();
     glTranslatef(pm,250,0);
     make_plane();
     glPopMatrix();

    }
}

void makeprivatecar(){
    glColor3f(1.0, 0.0, 0.0);
    circle(5,15,0,0);
    rectangle(0,-15,60,15);

    glColor3f(0.2, 0.47, 1.0);
    triangle(5,15,20,20,45);
    triangle(40,15,60,40,45);

    glColor3f(0, 0, 0);
    rectangle(20,15,40,45);

    glColor3f(1.0, 0.0, 0.0);
    circle(5,10,80,-5);

    glColor3f(1.0, 0.0, 0.0);
    rectangle1(60,-15,80,-15,60,15,80,5);


    glColor3f(0, 0, 0);
    circle(7,14,10,-15);
    circle(7,14,60,-15);

    glColor3f(1.0, 1.0, 1.0);
    circle(6,12,10,-15);
    circle(6,12,60,-15);

}
void privatecarMove(){
cm=cm+.5;
    if(cm>330)
        cm = -350;
        glutPostRedisplay();
}

void privatecar()
{
    privatecarMove();
    for(int i=0;i<1;i++)
     {

     glPushMatrix();
     glTranslatef(cm,-50,0);
     makeprivatecar();
     glPopMatrix();

    }
}

void busmake()
{
    glColor3f(0.9, 0.72, 0.0);
    rectangle(-60,-15,0,15);
    rectangle(-80,-15,-60,25);
    glColor3f(0, 0, 0);
    rectangle(-60,15,-2,50);
    rectangle(-70,25,-60,50);
    glColor3f(0.76, 0.84, 0.84);
    rectangle1(-2,50,-70,50,-7,55,-76,55);

    glColor3f(0.2, 0.8, 1.0);
    rectangle1(-70,25,-74,25,-70,50,-76,55);

    glColor3f(1, 1, 1.0);
    rectangle(-58,0,-50,35);
    glColor3f(0.2, 0.8, 1.0);
    rectangle(-45,30,-40,40);
    rectangle(-35,30,-30,40);
    rectangle(-25,30,-20,40);
    rectangle(-15,30,-10,40);


    glColor3f(0.9, 0.72, 0.0);
    circle(3,15,0,0);
    circle(3,20,-80,5);

    glColor3f(0, 0, 0);
    circle(8,16,-10,-15);
    circle(8,16,-70,-15);

    glColor3f(1, 1, 1);
    circle(6,12,-10,-15);
    circle(6,12,-70,-15);

}

void busMove(){
bm=bm-.4;
    if(bm<-350)
        bm = 350;

        glutPostRedisplay();
}

void bus()
{
     glPushMatrix();
     glTranslatef(bm,-165,0);
     busmake();
     glPopMatrix();
}


void railline()
{
    glColor3f(0,0,0);
    rectangle(-300,-230,300,-225);
    rectangle(-300,-260,300,-265);
    int i = 0;

    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_QUADS);
    for(i=-305;i<=300;i=i+30){

        glVertex2d(i,-260);
        glVertex2d(i+5,-260);
        glVertex2d(i+20,-225);
        glVertex2d(i+25,-225);

    }
    glEnd();

}

void makerail()
{
    glColor3f(0, 0, 0);
    circle(8,15,-70,-2);
    circle(8,15,-53,-2);

    circle(8,15,-20,-2);
    circle(8,15,-3,-2);

    circle(8,15,30,-2);
    circle(8,15,47,-2);

    circle(8,15,75,-2);
    circle(8,15,93,-2);

    rectangle(-70,0,-70,2);


    glColor3f(1, 1, 1);
    rectangle(-70,0,100,60);
    glColor3f(0.4, 0.4, 0.4);
    rectangle1(-100,0,-70,0,-100,20,-70,60);
    glColor3f(0.75, 0.75, 0.75);
    rectangle1(-70,60,100,60,-75,70,105,70);
    glColor3f(1.0, 1.0, 0.7);
    rectangle1(100,0,104,10,100,60,105,70);
    glColor3f(0.6, 0.87, 1.0);
    rectangle1(-100,20,-70,60,-95,35,-75,70);
    glColor3f(0.4, 0.4, 0.4);
    circle(12,15,-97,15);

    glColor3f(0, 1, 1);
    rectangle(-60,10,-50,50);
    rectangle(-45,30,-35,50);
    rectangle(-30,30,-20,50);
    rectangle(-15,30,-5,50);

    rectangle(0,10,10,50);
    rectangle(15,30,25,50);
    rectangle(30,30,40,50);
    rectangle(45,30,55,50);

    rectangle(60,10,70,50);
    rectangle(75,30,85,50);
    rectangle(90,30,99,50);

   rectangle(-70,0,-70,2);



}

void trainMove(){
tm=tm-1;
    if(tm<-350)
        tm = 350;

        glutPostRedisplay();
}
void train()
{
    trainMove();
    for(int i=0;i<1;i++)
     {

     glPushMatrix();
     glTranslatef(tm,-245,0);
     makerail();
     glPopMatrix();

    }

}

void spinDisplay_left()
{
   spin = spin - .3;

  glutPostRedisplay();
}
void fan()
{
    glColor3f(1, 1, 1);
	rectangle1(-3,0,0,-30,0,30,3,0);
}
void windmil()
{
    glColor3f(0.95, 0.95, 0.95);
	rectangle1(-6,-90,6,-90,-3,4,3,4);
    spinDisplay_left();
	glPushMatrix();
	glRotatef(spin, 0.0, 0.0, 10.0);
	fan();
	glPopMatrix();


}

void windmail()
{
    glPushMatrix();
    glTranslated(90,170,0);
    windmil();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-220,170,0);
    windmil();
    glPopMatrix();

    glPushMatrix();
    glTranslated(00,170,0);
    windmil();
    glPopMatrix();
}

void house()
{
    glColor3f(0.1f, 0.1f, 1.0f);
    rectangle1(200,-9,350,-9,200,80,350,80);
    rectangle1(200,80,250,80,200,120,250,120);
    glColor3f(0.0f, 0.1f, 0.0f);
    triangle(195,120,255,225,150);

    glColor3f(0.4, 1.0, 1.0);
    rectangle1(215,95,235,95,215,115,235,115);

    glColor3f(0.95, 0.95, 0.95);
    rectangle1(220,-9,250,-9,220,40,250,40);


}

void make_tree2()
{
    glColor3f(0.0, 0.6, 0.0);
    circle(20,30,0,0);
    circle(20,30,20,0);
    circle(20,30,40,0);
    circle(20,30,30,30);
    circle(20,30,10,30);
    circle(20,30,10,-30);
    circle(20,30,30,-30);

    circle(10,20,50,-70);
    circle(10,20,60,-60);
    circle(10,20,60,-80);


    glColor3f(0.75, 0.5, 0.25);
    rectangle1(10,-130,30,-130,10,-30,30,-30);
    rectangle1(10,-30,17,-30,5,0,5,0);
    rectangle1(17,-30,22,-30,19,0,19,0);
    rectangle1(22,-30,30,-30,35,0,35,0);
    rectangle1(30,-90,30,-100,55,-70,55,-75);



}

void tree2()
{
    glPushMatrix();
    glTranslated(-320,120,0);
    make_tree2();
    glPopMatrix();

    glPushMatrix();
    glTranslated(270,120,0);
    make_tree2();
    glPopMatrix();

    glPushMatrix();
    glTranslated(100,120,0);
    make_tree2();
    glPopMatrix();

}
void man1()
{
    glColor3f(1.0, 1.0, 0.4);
    rectangle1(-12,-30,12,-30,-8,-15,8,-15);
    glColor3f(0,0,0);
    circle(10,20,0,0);
    glColor3f(0.8, 0.6, 0.0);
    circle(6,15,-6,-42);
    circle(6,15,6,-42);
    glColor3f(0,0,0);
    rectangle1(-12,-27,12,-27,-12,-40,12,-40);
    glColor3f(0.8, 0.6, 0.0);
    rectangle1(-10,-50,-2,-52,-10,-62,-2,-62);
    rectangle1(10,-50,2,-52,10,-62,2,-62);


}
float mm =75;
void manmove()
{
    mm=mm+.2;
    if(mm>75)
        mm = -120;
        glutPostRedisplay();

}

void man()
{

     glPushMatrix();
     glTranslatef(-20,mm,0);
     man1();
     glPopMatrix();
}
void child1()
{
    glColor3f(0.0, 0.0, 0.0);
    circle(10,20,00,0);
    rectangle1(-5,0,5,0,-5,-60,5,-60);
    rectangle1(-5,-55,0,-55,-10,-80,-5,-80);
    rectangle1(5,-55,0,-55,10,-80,5,-80);
    rectangle1(-2,-25,2,-25,10,-50,14,-50);
    rectangle1(-2,-25,2,-25,-14,-50,-10,-50);
}

void child2()
{
    glPushMatrix();
     glTranslatef(-320,-150,0);
     child1();
     glPopMatrix();
}
void child()
{
    glPushMatrix();
     glTranslatef(tx,ty,0);
     child2();
     glPopMatrix();
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    sun();
    cloud();
    hill();
    soil();
    ground();
    road();
    tree1();
    windmail();
    tree2();

    flag();
    shaheed_minar();
    man();
    child();
    college();
    house();
    plane();
    privatecar();
    bus();
    railline();
    train();
    //man();

    glFlush();
}


void init()
{
    glClearColor(0.3, .65, 1, 1.0);
	glOrtho(-300,300,-300,300,-150,500);
}

void my_keyboard(unsigned char key, int x, int y)
{

	switch (key) {

		case 's':
			glutIdleFunc(busMove);
			break;

		case 'm':
			glutIdleFunc(manmove);
			break;

		case 'b':
			 glutIdleFunc(NULL);
			 break;

	  default:
			break;
	}
}
void spe_key(int key, int x, int y)
{

	switch (key) {

		case GLUT_KEY_UP:
				ty +=5;
				glutPostRedisplay();
				break;

		case GLUT_KEY_DOWN:

				ty -=5;
				glutPostRedisplay();
				break;

				case GLUT_KEY_RIGHT:
				tx +=5;
				glutPostRedisplay();
				break;
		case GLUT_KEY_LEFT:
				tx -=5;
				glutPostRedisplay();
				break;



	  default:
			break;
	}
}

int main()
{
    PlaySound("1.wav", NULL, SND_FILENAME| SND_ASYNC);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1500,700);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Computer Grapics Project");
    init();
    glutDisplayFunc(myDisplay);
    glutSpecialFunc(spe_key);
    glutKeyboardFunc(my_keyboard);
    glutMainLoop();
    return 0;
}

