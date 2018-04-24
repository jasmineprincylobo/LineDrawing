// brehmans jas.cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
# include "gl/glut.h"
int x1,y1,x2,y2;
void plotpixel(int x,int y)
{
	glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}
void Bresenham_line(int x1,int y1,int x2,int y2)
{
	int dy,dx,x,y,p,i;
	dy=y2-y1;
	dx=x2-x1;
	x=x1;
	y=y1;
	p=(2*dy)-dx;
	if(dx<0)
	{
		x=x2;
		y=y2;
		x2=x1;
	}
	plotpixel(x,y);
	for(i=0;i<dx;i++)
	{
		x++;
		if(p<0)
			p+=(2*dx);
		else
		{
			y++;
			p=p+(2*dy)-(2*dx);
		}
		plotpixel(x,y);
	}
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	Bresenham_line(x1,y1,x2,y2);
	glFlush();
}
void init()
{
	glClearColor(0,0,0,1);
	gluOrtho2D(0,500,0,500);
}
void main()
{
	printf("enter the x0,y0,x1,y1 values:\n");
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(600,600);
	glutCreateWindow("Bresenham_line");
		glutInitWindowSize(600,600);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}





