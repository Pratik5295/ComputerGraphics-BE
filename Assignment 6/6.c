/*
 * 7.c
 *
 *  Created on: Mar 12, 2015
 *      Author: pratik
 */

#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<drawaxes.h>

int getcode(float,float,float,float,float,float);
void clip(float,float,float,float,float,float,float,float);

const int a=1,b=2,r=4,l=8;
void main()
{
	float xmin,ymin,xmax,ymax,x1,y1,x2,y2;
	int gd=DETECT,gm;

	initgragh(&gd,&gm,NULL);

	printf("Enter co-ordinates of the window");
	scanf("%f%f%f%f",&xmin,&ymin,&xmax,&ymax);
	printf("Enter end points of the line");
	scanf("%f%f%f%f",&x1,&y1,&x2,&y2);

	line(x1,y1,x2,y2);
	rectangle(xmin,ymin,xmax,ymax);
	getch();

	clip(x1,y1,x2,y2,xmin,ymin,xmax,ymax);
	getch();
}

int getcode(float x, float y, float xmin, float ymin, float xmax, float ymax)
{
	int code=0;

	if(y>ymax)
		code=code|a;
	else if(y<ymin)
		code=code|b;
	if(x>xmax)
		code=code|r;
	else if(x<xmin)
		code=code|l;

	return code;
}

void clip(float x1, float y1, float x2, float y2, float xmin, float ymin, float xmax, float ymax)
{
	unsigned int code1, code2, codeout;
	int accept=0, done=0;

	code1=getcode(x1,y1,xmin,ymin,xmax,ymax);
	code2=getcode(x2,y2,xmin,ymin,xmax,ymax);

	do
	{
		if(!(code1|code2))
		{
			accept=1;
			done=1;
		}
		else if(code1&code2)
			done=1;
		else
		{
			float x,y;
			codeout=code1?code1:code2;

			if(codeout&a)
			{
				x=x1+(x2-x1)*((ymax-y1)/(y2-y1));
				y=ymax;
			}
			else if(codeout&b)
			{
				x=x1+(x2-x1)*((ymin-y1)/(y2-y1));
				y=ymin;
			}
			else if(codeout&r)
			{
				x=xmax;
				y=y1+(y2-y1)*((xmax-x1)/(x2-x1));
			}
			else
			{
				x=xmin;
				y=y1+(y2-y1)*((xmin-x1)/(x2-x1));
			}
			if(codeout==code1)
			{
				x1=x;
				y1=y;
				code1=getcode(x1,y1,xmin,ymin,xmax,ymax);
			}
			else
			{
				x2=x;
				y2=y;
				code1=getcode(x2,y2,xmin,ymin,xmax,ymax);
			}
		}
	}while(done==0);

	if(accept)
	{
		line(x1,y1,x2,y2);
		rectangle(xmin,ymin,xmax,ymax);
	}
}
