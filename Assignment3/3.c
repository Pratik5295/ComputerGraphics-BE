/*
 * 3.c
 *
 *  Created on: 26-Feb-2015
 *      Author: pratik
 */

#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<drawaxes.h>
#define MAX 6

void display(int x[3][MAX], int n);
void rec_bfill(int,int,int,int);
void rec_ffill(int,int,int,int);

void main()
{
	int ch,ans;
	int obj[3][MAX],n,i;
	int Xmax,Ymax,Xmid,Ymid,x,y;
	int gd=DETECT,gm;

	printf("Enter no. of vertices of the object");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter X coordinate for [%d] point:",i);
		scanf("%d",&obj[0][i]);
		printf("Enter Y coordinate for [%d] point:",i);
		scanf("%d",&obj[1][i]);
		obj[2][i]=1;
	}

	do
	{
		printf("Polygon filling methods: \n1.Recursive Boundary fill \n2.Recursive Flood fill \n3.Non-recursive Boundary fill \n4.Non-recursive Flood fill \n5.Scan-line polygon filling \n6.Exit");
		printf("\nEnter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1: printf("Enter coordinates of any pt. which lies inside the polygon");
				scanf("%d%d",&x,&y);
				initgraph(&gd,&gm,NULL);
				Xmax=getmaxx();
				Ymax=getmaxy();
				Xmid=Xmax/2;
				Ymid=Ymax/2;
				display(obj,n);
				rec_bfill(Xmid+x,Ymid-y,15,10);
				break;
		case 2: printf("Enter coordinates of any pt. which lies inside the polygon");
				scanf("%d%d",&x,&y);
				initgraph(&gd,&gm,NULL);
				Xmax=getmaxx();
				Ymax=getmaxy();
				Xmid=Xmax/2();
				Ymid=Ymax/2;
				display(obj,n);
				rec_ffill(Xmid+x,Ymid-y,15,10);
		break;
		case 3:
		case 4:
		case 5:
		case 6: exit(0);
		default: printf("Please enter a valid choice");
				 break;
		}
		printf("Do you wish to continue? \n1.Y 2.N");
		scanf("%d",&ans);
	}while(ans==1);
}

void display(int x[3][MAX], int n)
{
	int i,Xmax,Ymax,Xmid,Ymid;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	Xmax=getmaxx();
	Ymax=getmaxy();
	Xmid=Xmax/2;
	Ymid=Ymax/2;

	for(i=0;i<n-1;i++)
	{
		line(Xmid+x[0][i],Ymid-x[1][i],Xmid+x[0][i+1],Ymid-x[1][i+1]);
	}
	line(Xmid+x[0][n-1],Ymid-x[1][n-1],Xmid+x[0][0],Ymid-x[1][0]);

	drawaxis();
	delay(3500);
	closegraph();
}

void rec_bfill(int x, int y, int bcolor, int newcolor)
{
	int current;
	current=getpixel(x,y);
	if((current!=bcolor) && (current!=newcolor))
	{
		putpixel(x,y,newcolor);
		rec_bfill(x+1,y,bcolor,newcolor);
		rec_bfill(x-1,y,bcolor,newcolor);
		rec_bfill(x,y+1,bcolor,newcolor);
		rec_bfill(x,y-1,bcolor,newcolor);
	}
	delay(7500);
}

void rec_ffill(int x, int y, int oldcolor, int newcolor)
{
	int current;
	current=getpixel(x,y);
	if((current==oldcolor) && (current!=newcolor))
	{
		putpixel(x,y,newcolor);
		rec_bfill(x+1,y,oldcolor,newcolor);
		rec_bfill(x-1,y,oldcolor,newcolor);
		rec_bfill(x,y+1,oldcolor,newcolor);
		rec_bfill(x,y-1,oldcolor,newcolor);
	}
	delay(7500);
}


