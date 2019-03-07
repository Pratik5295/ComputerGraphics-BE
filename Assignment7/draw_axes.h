/*
 * draw_axes.h
 *
 *  Created on: 16-Mar-2015
 *      Author: pratik
 */

void axes()
{
	int gd=DETECT,gm,x1,x2,y1,y2,xmax,ymax,xmid,ymid,i;
	char s1[20],s2[20],s3[20];
	xmax=getmaxx();
	ymax=getmaxy();
	xmid=xmax/2;
	ymid=ymax/2;
	line(xmid,0,xmid,xmax);
	line(0,ymid,xmax,ymid);
	outtextxy(xmid,ymid,"(0,0)");
	for(i=xmid+30;i<xmax;i=i+30)
	{
		line(i,ymid-3,i,ymid+3);
		sprintf(s1,"%d",i-xmid);
		outtextxy(i,ymid+5,s1);
	}
	for(i=xmid-30;i>0;i=i-30)
	{
		line(i,ymid-3,i,ymid+3);
		sprintf(s1,"%d",xmid-i);
		outtextxy(i,ymid+5,s1);
	}
	for(i=ymid+30;i<ymax;i=i+30)
	{
		line(xmid-3,i,xmid+3,i);
		sprintf(s1,"%d",i-ymid);
		outtextxy(xmid+2,i,s1);
	}
	for(i=ymid-30;i>0;i=i-30)
	{
		line(xmid-3,i,xmid+3,i);
		sprintf(s1,"%d",ymid-i);
		outtextxy(xmid+2,i,s1);
	}

	//delay(7000);
}
