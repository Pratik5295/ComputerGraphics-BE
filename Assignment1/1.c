#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<graphics.h>
#include"drawaxes.h"

void dda(int, int, int, int, int);
void bres(int, int, int, int, int);

void main()
{
	int gd=DETECT,gm;
	int ch,ans,x1,y1,x2,y2;
	int xmax,ymax,xmid,ymid;
	printf("Enter starting coordinates of the line");
	scanf("%d%d",&x1,&y1);
	printf("Enter ending coordinates of the line");
	scanf("%d%d",&x2,&y2);

	initgraph(&gd,&gm," ");
	xmax=getmaxx();
	ymax=getmaxy();
	xmid=xmax/2;
	ymid=ymax/2;
	closegraph();

	do
	{
		printf("MENU \n1.DDA \n2.Bresenham \n3.Exit");
		printf("\nEnter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1: printf("Select type \n1.Simple \n2.Dash \n3.Dotted \n4.Thick");
				printf("\nEnter your choice");
				scanf("%d",&ch);
				initgraph(&gd,&gm,NULL);
				drawaxis();
				dda(xmid+x1,ymid-y1,xmid+x2,ymid-y2,ch);
				delay(7500);
				closegraph();
				break;
		case 2: printf("Select type \n1.Simple \n2.Dash \n3.Dotted \n4.Thick");
				printf("\nEnter your choice");
				scanf("%d",&ch);
				initgraph(&gd,&gm,NULL);
				drawaxis();
				bres(xmid+x1,ymid-y1,xmid+x2,ymid-y2,ch);
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

void dda(int x1, int y1, int x2, int y2, int ch)
{
	int i,j,dx,dy,steps;
	float x,y;
	float xinc,yinc;

	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>=abs(dy))
		steps=dx;
	else
		steps=dy;

	xinc=(float)dx/steps;
	yinc=(float)dy/steps;
	x=x1;
	y=y1;

	putpixel(x,y,WHITE);
	for(i=1;i<steps;i++)
	{
		x=x+xinc;
		y=y+yinc;
		x1=x+0.5;
		y1=y+0.5;
		if(ch==1)
			putpixel(x1,y1,WHITE);
		else if(ch==2)
		{
			if(i%5!=0)
				putpixel(x1,y1,WHITE);
			else
				putpixel(x1,y1,BLACK);
		}
		else if(ch==3)
		{
			if(i%5==0)
				putpixel(x1,y1,WHITE);
			else
				putpixel(x1,y1,BLACK);
		}
		else
		{
			for(j=0;j<5;j++)
				putpixel(x1,y1-j,WHITE);
		}
	}
}

void bres(int x1, int y1, int x2, int y2, int ch)
{
	int i,j,x,y,xinc,yinc,dx,dy,tdy,tdx,tdydx,tdxdy,pk,steps;

	dx=x2-x1;
	dy=y2-y1;
	if(dx>0)
		xinc=1;
	else
		xinc=-1;
	if(dy>0)
		yinc=1;
	else
		yinc=-1;

	x=x1;
	y=y1;
	if(abs(dx)>abs(dy))
	{
		steps=abs(dx);
		tdy=2*abs(dy);
		tdydx=(2*abs(dy))-(2*abs(dx));
		pk=(2*abs(dy))-abs(dx);

		for(i=0;i<steps;i++)
		{
			if(ch==1)
				putpixel(x,y,WHITE);
			else if(ch==2)
			{
				if(i%5!=0)
					putpixel(x,y,WHITE);
				else
					putpixel(x,y,BLACK);
			}
			else if(ch==3)
			{
				if(i%5==0)
					putpixel(x,y,WHITE);
				else
					putpixel(x,y,BLACK);
			}
			else
			{
				for(j=0;j<5;j++)
					putpixel(x,y-j,WHITE);
			}

			if(pk<0)
			{
				x=x+xinc;
				pk=pk+tdy;
			}
			else
			{
				x=x+xinc;
				y=y+yinc;
				pk=pk+tdydx;
			}
		}
	}
	else
	{
		steps=abs(dy);
		tdx=2*abs(dx);
		tdxdy=(2*abs(dx))-(2*abs(dy));
		pk=(2*abs(dx))-abs(dy);

		for(i=0;i<steps;i++)
		{
			if(ch==1)
				putpixel(x,y,WHITE);
			else if(ch==2)
			{
				if(i%5!=0)
					putpixel(x,y,WHITE);
				else
					putpixel(x,y,BLACK);
			}
			else if(ch==3)
			{
				if(i%5==0)
					putpixel(x,y,WHITE);
				else
					putpixel(x,y,BLACK);
			}
			else
			{
				for(j=0;j<5;j++)
					putpixel(x,y-j,WHITE);
			}

			if(pk<0)
			{
				y=y+yinc;
				pk=pk+tdx;
			}
			else
			{
				x=x+xinc;
				y=y+yinc;
				pk=pk+tdxdy;
			}
		}
	}
}
