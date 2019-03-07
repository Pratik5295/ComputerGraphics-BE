/*
 * clip.c
 *
 *  Created on: 16-Mar-2015
 *      Author: pratik
 */

#include <stdio.h>
#include <stdlib.h>
#include<graphics.h>

const int t=1,b=2,r=4,l=8;
int xmin,ymin,xmax,ymax;
int calcode(float x,float y);
void lineclip(int x1,int y1,int x2,int y2);
int calcode(float x,float y)
{
	int code=0;
	if(y>ymax)
		code|=t;
	else if(y<ymin)
		code|=b;
	else if(x>xmax)
		code|=r;
	else if(x<xmin)
		code|=l;
	return code;
}
void lineclip(int x1,int y1,int x2,int y2)
{
	unsigned int code1,code2,codeout;
	int accept=0,done=0;
	code1=calcode(x1,y1);
	code2=calcode(x2,y2);
	do
	{
		if(!(code1 | code2))
		{
			accept=1;
			done=1;
		}
		else if(code1 & code2)
		{
			done=1;
		}
		else
		{
			float x,y;
			codeout=code1?code1:code2;
			if(codeout & t)
			{
				x=x1+(x2-x1)*(ymax-y1)/(y2-y1);
				y=ymax;
			}
			else if(codeout & b)
			{
				x=x1+(x2-x1)*(ymin-y1)/(y2-y1);
				y=ymin;
			}
			else if(codeout & r)
			{
				y=y1+(y2-y1)*(xmax-x1)/(x2-x1);
				x=xmax;
			}
			else
			{
				y=y1+(y2-y1)*(xmin-x1)/(x2-x1);
				x=xmin;
			}
			if(codeout==code1)
			{
				x1=x;
				y1=y;
				code1=calcode(x1,y1);
			}
			else
			{
				x2=x;
				y2=y;
				code2=calcode(x2,y2);
			}
		}
	}while(done==0);
	if(accept)
		line(x1,y1,x2,y2);
	rectangle(xmin,ymin,xmax,ymax);
}
int main()
{
	int x1,y1,x2,y2,inp,n,i;
	int gd=DETECT,gm;
	int polyx[10],polyy[10];
	printf("1. Line Clipping\n2. Polygon clipping\nEnter choice : \n");
	scanf("%d",&inp);
	switch(inp)
	{
		case 1:
			printf("\nEnter the coordinates of the line :\n");
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			printf("\nEnter the coordinates of the window :\n");
			scanf("%d%d%d%d",&xmin,&ymin,&xmax,&ymax);
			initgraph(&gd,&gm,"");
			cleardevice();
			line(x1,y1,x2,y2);
			rectangle(xmin,ymin,xmax,ymax);
			cleardevice();
			lineclip(x1,y1,x2,y2);
			delay(8000);
			closegraph();
			break;

		case 2:
			printf("\nEnter the coordinates of the window :\n");
			scanf("%d%d%d%d",&xmin,&ymin,&xmax,&ymax);
			printf("Enter no of vertices :\n");
			scanf("%d",&n);
			printf("\nEnter the points :\n");
			for(i = 0;i < n;i++)
			{
				scanf("%d%d",&polyx[i],&polyy[i]);
			}
			initgraph(&gd,&gm,"");
			cleardevice();
			//line(x1,y1,x2,y2);
			rectangle(xmin,ymin,xmax,ymax);
			cleardevice();
			for(i = 0;i < n-1;i++)
			{
				lineclip(polyx[i],polyy[i],polyx[i+1],polyy[i+1]);
			}
			lineclip(polyx[n-1],polyy[n-1],polyx[0],polyy[0]);
			delay(8000);
			closegraph();
			break;

		default:
			printf("Invalid\n");
	}

	return(0);

}






