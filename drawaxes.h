/*
 * drawaxis.h
 *
 *  Created on: 22-Jan-2015
 *      Author: pict
 */

#ifndef DRAWAXIS_H_
#define DRAWAXIS_H_

void drawaxis()
{
	int i,x1,y1,x2,y2,Xmax,Xmid,Ymax,Ymid;
	char s[50];
	Xmax=getmaxx();
	Ymax=getmaxy();
	Xmid=Xmax/2;
	Ymid=Ymax/2;

	line(0,Ymid,Xmax,Ymid);
	line(Xmid,0,Xmid,Ymax);
	outtextxy(Xmax-50,Ymid-15,"X-axis");
	outtextxy(Xmid+5,0,"Y-axis");
	outtextxy(Xmid+5,Ymid+5,"O");

	for(i=30;i<Xmid-30;i=i+30)
	{
		line(Xmid+i,Ymid+2,Xmid+i,Ymid-2);
		sprintf(s,"%d",i);
		outtextxy(Xmid+i,Ymid+5,s);

		line(Xmid-i,Ymid+2,Xmid-i,Ymid-2);
		sprintf(s,"%d",-i);
		outtextxy(Xmid-i,Ymid+5,s);
	}

	for(i=30;i<Ymid;i=i+30)
	{
		line(Xmid+2,Ymid+i,Xmid-2,Ymid+i);
		sprintf(s,"%d",-i);
		outtextxy(Xmid-30,Ymid+i,s);

		line(Xmid+2,Ymid-i,Xmid-2,Ymid-i);
		sprintf(s,"%d",i);
		outtextxy(Xmid-30,Ymid-i,s);
	}
}

#endif /* DRAWAXIS_H_ */
