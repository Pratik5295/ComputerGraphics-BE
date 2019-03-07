/*
 * 5.c
 *
 *  Created on: 12-Feb-2015
 *      Author: pratik
 */

#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<drawaxes.h>
#include<math.h>
#define MAX 6
#define pi 3.14159265

void multi(int t[3][3], int o[3][MAX], int r[3][MAX], int n);
void display(int x[3][MAX], int n, int ch);

float a1,a2,b1,b2;
void main()
{
	int ch,ans;
	int obj[3][MAX],trans[3][3],img[3][MAX],n,i;
	float m,c,theta,theta1;

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
		printf("REFLECTION about: \n1.X-axis \n2.Y-axis \n3.Arbitrary axis \n4.Exit");
		printf("\nEnter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:	display(obj,n,1);
				trans[0][0]=trans[2][2]=1;
				trans[0][1]=trans[0][2]=trans[1][0]=trans[1][2]=trans[2][0]=trans[2][1]=0;
				trans[1][1]=-1;
				multi(trans,obj,img,n);
				display(img,n,1);
				break;
		case 2: display(obj,n,2);
				trans[1][1]=trans[2][2]=1;
				trans[0][1]=trans[0][2]=trans[1][0]=trans[1][2]=trans[2][0]=trans[2][1]=0;
				trans[0][0]=-1;
				multi(trans,obj,img,n);
				display(img,n,2);
				break;
		case 3: printf("Enter slope and y-intercept of the arbitrary axis");
				scanf("%f%f",&m,&c);
				a1=200.0;
				a2=-200.0;
				b1=(m*a1)+c;
				b2=(m*a2)+c;
				theta=atan(m)*(180/pi);
				printf("%f",theta);
				theta1=45.0-theta;

				display(obj,n,3);
				trans[0][2]=trans[1][2]=0;
				trans[2][2]=1;
				trans[0][0]=2*sin(theta1)*cos(theta1);
				trans[1][1]=-trans[0][0];
				trans[2][1]=c*trans[0][0]+c;
				trans[0][1]=trans[1][0]=(cos(theta1)*cos(theta1))-(sin(theta1)*sin(theta1));
				trans[2][0]=-c*trans[0][1];
				multi(trans,obj,img,n);
				display(img,n,3);
				break;
		case 4: exit(0);
		default: printf("Please enter a valid choice");
				 break;
		}
		printf("Do you wish to continue? \n1.Y 2.N");
		scanf("%d",&ans);
	}while(ans==1);
}

void multi(int trans[3][3], int obj[3][MAX], int img[3][MAX], int n)
{
	int i,j,k;
	for(i=0;i<3;i++)
	{
		for(j=0;j<n;j++)
		{
			img[i][j]=0;
			for(k=0;k<3;k++)
			{
				img[i][j]=img[i][j]+(trans[i][k]*obj[k][j]);
			}
		}
	}
}

void display(int x[3][MAX], int n, int ch)
{
	int i;
	int xmax,ymax,xmid,ymid;
	int gd=DETECT,gm;

	initgraph(&gd,&gm,NULL);
	xmax=getmaxx();
	ymax=getmaxy();
	xmid=xmax/2;
	ymid=ymax/2;

	if(ch==3)
		line(xmid+a1,ymid-b1,xmid+a2,ymid-b2);

	for(i=0;i<n-1;i++)
	{
		line(xmid+x[0][i],ymid-x[1][i],xmid+x[0][i+1],ymid-x[1][i+1]);
	}
	line(xmid+x[0][n-1],ymid-x[1][n-1],xmid+x[0][0],ymid-x[1][0]);

	drawaxis();
	delay(7500);
	closegraph();
}





