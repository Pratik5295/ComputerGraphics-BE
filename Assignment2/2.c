/*
 * 2.c
 *
 *  Created on: 22-Jan-2015
 *      Author: pratik
 */
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<drawaxes.h>

void midpt(int,int,int);
void bres(int,int,int);
void plotpoints(int,int,int,int);

void main()
{
	int gd=DETECT,gm;
	int ch,ans,xc,yc,r,xmax,ymax,xmid,ymid;

	printf("Enter coordinates of the centre");
	scanf("%d%d",&xc,&yc);
	printf("Enter radius");
	scanf("%d",&r);

	initgraph(&gd,&gm,NULL);
	xmax=getmaxx();
	ymax=getmaxy();
	xmid=xmax/2;
	ymid=ymax/2;
	closegraph();

	do
	{
		printf("MENU \n1.Mid-pt. \n2.Bresenham \n3.Exit");
		printf("\nEnter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1: initgraph(&gd,&gm,NULL);
				drawaxis();
				midpt(xmid+xc,ymid-yc,r);
				delay(7500);
				closegraph();
				break;
		case 2:	initgraph(&gd,&gm,NULL);
				drawaxis();
				bres(xmid+xc,ymid-yc,r);
				delay(7500);
				closegraph();
				break;
		case 3: exit(0);
		default: printf("Please enter a valid choice");
				 break;
		}
		printf("Do you wish to continue? \n1.Y 2.N");
		scanf("%d",&ans);
	}while(ans==1);
}

void midpt(int xc, int yc, int r)
{
	int X,Y;
	float dp;

	X=0;
	Y=r;
	dp=(5/4)-r;

	while(X<=Y)
	{
		X++;
		if(dp<=0)
			dp=dp+(2*X)+1;
		else
		{
			Y--;
			dp=dp+(2*(X-Y))+1;
		}
		plotpoints(xc,yc,X,Y);
	}
}

void bres(int xc, int yc, int r)
{
	int X,Y;
	float dp;

	X=0;
	Y=r;
	dp=3-(2*r);

	while(X<=Y)
	{
		if(dp<=0)
			dp=dp+(4*X)+6;
		else
		{
			dp=dp+(4*(X-Y))+10;
			Y--;
		}
		X++;
		plotpoints(xc,yc,X,Y);
	}
}

void plotpoints(int xc, int yc, int X, int Y)
{
	putpixel(xc+X,yc+Y,WHITE);
	putpixel(xc+X,yc-Y,WHITE);
	putpixel(xc-X,yc+Y,WHITE);
	putpixel(xc-X,yc-Y,WHITE);
	putpixel(xc+Y,yc+X,WHITE);
	putpixel(xc+Y,yc-X,WHITE);
	putpixel(xc-Y,yc+X,WHITE);
	putpixel(xc-Y,yc-X,WHITE);
}


