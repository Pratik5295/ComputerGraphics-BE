/*
 * Curve.c
 *
 *  Created on: 16-Mar-2015
 *      Author: pratik
 */

#include <math.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include "draw_axes.h"

void beizer(int x[4], int y[4])
{
	int gd = DETECT,gm;
	int i;
	double t;
	int midx,midy;
	initgraph(&gd,&gm,"...\\bgi");
	midx = getmaxx()/2;
	midy = getmaxy()/2;
	axes();
	for(t = 0.0;t < 1.0;t+=0.0005)
	{
		double xt = pow(1-t,3)*(x[0]) + 3*t*pow(1-t,2)*(x[1]) + 3*pow(t,2)*(1-t)*(x[2]) + pow(t,3)*(x[3]);
		double yt = pow(1-t,3)*(y[0]) + 3*t*pow(1-t,2)*(y[1]) + 3*pow(t,2)*(1-t)*(y[2]) + pow(t,3)*(y[3]);
		putpixel(xt+midx,midy-yt,WHITE);
	}
	for(i = 0;i < 4;i++)
		putpixel(x[i],y[i],YELLOW);
	delay(7000);
	closegraph();
}

int main(void)
{
	int x[4],y[4];
	int i;
	printf("Enter 4 coordinates :\n");
	for(i = 0;i < 4;i++)
		scanf("%d%d",&x[i],&y[i]);
	beizer(x,y);
}
