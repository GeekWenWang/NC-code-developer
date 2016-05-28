#ifndef _CNC_CODE_H
#define _CNC_CODE_H

struct CNC_CODE_DATA
{
	double xyCoordinate[6][2];
	double headAngle[5] ;
	int Gcommand[5];
	double lengthBetweenPoint[5];
	double lengthOriginToPoint[5];
	double absAngle[5];
};


void angleCaculator(CNC_CODE_DATA *cncCodeDataPtr);
void cncCodeDataInit(CNC_CODE_DATA *cncCodeDataPtr);
void lengthCaculator(CNC_CODE_DATA *cncCodeDataPtr);




#endif