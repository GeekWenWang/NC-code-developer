#include < iostream >
#include < cstdlib >
#include < cmath >

#include "developData.h"

extern CNC_CODE_DATA* cncCodeDataPtr;

void angleCaculator(CNC_CODE_DATA *cncCodeDataPtr)
{
	lengthCaculator(cncCodeDataPtr);

	cncCodeDataPtr->headAngle[0] = atan(cncCodeDataPtr->xyCoordinate[1][1]/cncCodeDataPtr->xyCoordinate[1][0])/3.14*180;
	
	if(cncCodeDataPtr->headAngle[0]<0)
	{
		cncCodeDataPtr->Gcommand[0] = 6;
	}
	else
	{
		cncCodeDataPtr->Gcommand[0] = 7;
	}

	cncCodeDataPtr->headAngle[1] =acos(((cncCodeDataPtr->xyCoordinate[1][0]*(cncCodeDataPtr->xyCoordinate[2][0]-cncCodeDataPtr->xyCoordinate[1][0]))+(cncCodeDataPtr->xyCoordinate[1][1]*(cncCodeDataPtr->xyCoordinate[2][1]-cncCodeDataPtr->xyCoordinate[1][1])))/cncCodeDataPtr->lengthBetweenPoint[0]/cncCodeDataPtr->lengthBetweenPoint[1])/3.14*180;
	
	
	if(cncCodeDataPtr->absAngle[0] - cncCodeDataPtr->absAngle[1] > 0 )
	{
		cncCodeDataPtr->Gcommand[1] = 6;
	}
	else
	{
		cncCodeDataPtr->Gcommand[1] = 7;
	}

	cncCodeDataPtr->headAngle[2] = acos((((cncCodeDataPtr->xyCoordinate[2][0]-cncCodeDataPtr->xyCoordinate[1][0])*(cncCodeDataPtr->xyCoordinate[3][0]-cncCodeDataPtr->xyCoordinate[2][0]))+((cncCodeDataPtr->xyCoordinate[2][1]-cncCodeDataPtr->xyCoordinate[1][1])*(cncCodeDataPtr->xyCoordinate[3][1]-cncCodeDataPtr->xyCoordinate[2][1])))/cncCodeDataPtr->lengthBetweenPoint[1]/cncCodeDataPtr->lengthBetweenPoint[2])/3.14*180;
	
	if(cncCodeDataPtr->absAngle[1] - cncCodeDataPtr->absAngle[2] > 0 )
	{
		cncCodeDataPtr->Gcommand[2] = 6;
	}
	else
	{
		cncCodeDataPtr->Gcommand[2] = 7;
	}

	cncCodeDataPtr->headAngle[3] = acos((((cncCodeDataPtr->xyCoordinate[3][0]-cncCodeDataPtr->xyCoordinate[2][0])*(cncCodeDataPtr->xyCoordinate[4][0]-cncCodeDataPtr->xyCoordinate[3][0]))+((cncCodeDataPtr->xyCoordinate[3][1]-cncCodeDataPtr->xyCoordinate[2][1])*(cncCodeDataPtr->xyCoordinate[4][1]-cncCodeDataPtr->xyCoordinate[3][1])))/cncCodeDataPtr->lengthBetweenPoint[2]/cncCodeDataPtr->lengthBetweenPoint[3])/3.14*180;
	
	if(cncCodeDataPtr->absAngle[2] - cncCodeDataPtr->absAngle[3] > 0 )
	{
		cncCodeDataPtr->Gcommand[3] = 6;
	}
	else
	{
		cncCodeDataPtr->Gcommand[3] = 7;
	}

	cncCodeDataPtr->headAngle[4] = acos((((cncCodeDataPtr->xyCoordinate[4][0]-cncCodeDataPtr->xyCoordinate[3][0])*(cncCodeDataPtr->xyCoordinate[5][0]-cncCodeDataPtr->xyCoordinate[4][0]))+((cncCodeDataPtr->xyCoordinate[4][1]-cncCodeDataPtr->xyCoordinate[3][1])*(cncCodeDataPtr->xyCoordinate[5][1]-cncCodeDataPtr->xyCoordinate[4][1])))/cncCodeDataPtr->lengthBetweenPoint[3]/cncCodeDataPtr->lengthBetweenPoint[4])/3.14*180;
	
	if(cncCodeDataPtr->absAngle[3] - cncCodeDataPtr->absAngle[4] > 0 )
	{
		cncCodeDataPtr->Gcommand[4] = 6;
	}
	else
	{
		cncCodeDataPtr->Gcommand[4] = 7;
	}
 return;
}

//****************************************************************************************
//
//****************************************************************************************
void cncCodeDataInit(CNC_CODE_DATA *cncCodeDataPtr)
{
		for(int j=1 ; j<6 ; j++)
	{
		for(int i=0 ; i<2 ;i++)
		{
			cncCodeDataPtr->xyCoordinate[j][i] = 0 ;
		}
	}

	for(int i=0; i<5 ;i++)
	{
		cncCodeDataPtr->headAngle[i] = 0;
	}

	for(int i=0; i<5 ;i++)
	{
		cncCodeDataPtr->Gcommand[i] = 0;
	}
	
	for(int i=0 ; i<5 ;i++)
	{
		cncCodeDataPtr->lengthBetweenPoint[i] = 0;
	}

	for(int i=0 ; i<5 ;i++)
	{
		cncCodeDataPtr->lengthOriginToPoint[i] = 0;
	}

	for(int i=0 ; i<5 ;i++)
	{
		cncCodeDataPtr->absAngle[i] = 0;
	}



	return;
}

//*********************************************************************
//
//*********************************************************************

void lengthCaculator(CNC_CODE_DATA *cncCodeDataPtr)
{
	cncCodeDataPtr->lengthBetweenPoint[0] = sqrt(pow(cncCodeDataPtr->xyCoordinate[1][1] , 2)+ pow(cncCodeDataPtr->xyCoordinate[1][0] , 2));
	cncCodeDataPtr->lengthBetweenPoint[1] = sqrt(pow((cncCodeDataPtr->xyCoordinate[2][1]-cncCodeDataPtr->xyCoordinate[1][1]) , 2)+ pow((cncCodeDataPtr->xyCoordinate[2][0]-cncCodeDataPtr->xyCoordinate[1][0]) , 2));
	cncCodeDataPtr->lengthBetweenPoint[2] = sqrt(pow((cncCodeDataPtr->xyCoordinate[3][1]-cncCodeDataPtr->xyCoordinate[2][1]) , 2)+ pow((cncCodeDataPtr->xyCoordinate[3][0]-cncCodeDataPtr->xyCoordinate[2][0]) , 2));
	cncCodeDataPtr->lengthBetweenPoint[3] = sqrt(pow((cncCodeDataPtr->xyCoordinate[4][1]-cncCodeDataPtr->xyCoordinate[3][1]) , 2)+ pow((cncCodeDataPtr->xyCoordinate[4][0]-cncCodeDataPtr->xyCoordinate[3][0]) , 2));
	cncCodeDataPtr->lengthBetweenPoint[4] = sqrt(pow((cncCodeDataPtr->xyCoordinate[5][1]-cncCodeDataPtr->xyCoordinate[4][1]) , 2)+ pow((cncCodeDataPtr->xyCoordinate[5][0]-cncCodeDataPtr->xyCoordinate[4][0]) , 2));
	
	cncCodeDataPtr->lengthOriginToPoint[0] = sqrt(pow(cncCodeDataPtr->xyCoordinate[1][1] , 2)+ pow(cncCodeDataPtr->xyCoordinate[1][0] , 2));
	cncCodeDataPtr->lengthOriginToPoint[1] = sqrt(pow(cncCodeDataPtr->xyCoordinate[2][1] , 2)+ pow(cncCodeDataPtr->xyCoordinate[2][0] , 2));
	cncCodeDataPtr->lengthOriginToPoint[2] = sqrt(pow(cncCodeDataPtr->xyCoordinate[3][1] , 2)+ pow(cncCodeDataPtr->xyCoordinate[3][0] , 2));
	cncCodeDataPtr->lengthOriginToPoint[3] = sqrt(pow(cncCodeDataPtr->xyCoordinate[4][1] , 2)+ pow(cncCodeDataPtr->xyCoordinate[4][0] , 2));
	cncCodeDataPtr->lengthOriginToPoint[4] = sqrt(pow(cncCodeDataPtr->xyCoordinate[5][1] , 2)+ pow(cncCodeDataPtr->xyCoordinate[5][0] , 2));
	
	if(cncCodeDataPtr->xyCoordinate[1][0] < 0 && cncCodeDataPtr->xyCoordinate[1][1]>0)
	{
		cncCodeDataPtr->absAngle[0] = acos(cncCodeDataPtr->xyCoordinate[1][0]/cncCodeDataPtr->lengthOriginToPoint[0])/3.14*180;
	}
	else if(cncCodeDataPtr->xyCoordinate[1][1] < 0 && cncCodeDataPtr->xyCoordinate[1][0]>0)
	{
		cncCodeDataPtr->absAngle[0] = 360+asin(cncCodeDataPtr->xyCoordinate[1][1]/cncCodeDataPtr->lengthOriginToPoint[0])/3.14*180;
	}
	else if(cncCodeDataPtr->xyCoordinate[1][0] >=0 && cncCodeDataPtr->xyCoordinate[1][1] >= 0)
	{
		cncCodeDataPtr->absAngle[0] = atan(cncCodeDataPtr->xyCoordinate[1][1]/cncCodeDataPtr->xyCoordinate[1][0])/3.14*180;
	}
	else
	{
		cncCodeDataPtr->absAngle[0] = 180+atan(cncCodeDataPtr->xyCoordinate[1][1]/cncCodeDataPtr->xyCoordinate[1][0])/3.14*180;
	}
	
	if(cncCodeDataPtr->xyCoordinate[2][0] < 0 && cncCodeDataPtr->xyCoordinate[2][1]>0)
	{
		cncCodeDataPtr->absAngle[1] = acos(cncCodeDataPtr->xyCoordinate[2][0]/cncCodeDataPtr->lengthOriginToPoint[1])/3.14*180;
	}
	else if(cncCodeDataPtr->xyCoordinate[2][1] < 0 && cncCodeDataPtr->xyCoordinate[2][0]>0)
	{
		cncCodeDataPtr->absAngle[1] = 360+asin(cncCodeDataPtr->xyCoordinate[2][1]/cncCodeDataPtr->lengthOriginToPoint[1])/3.14*180;
	}
	else if(cncCodeDataPtr->xyCoordinate[2][0] >=0 && cncCodeDataPtr->xyCoordinate[2][1] >= 0)
	{
		cncCodeDataPtr->absAngle[1] = atan(cncCodeDataPtr->xyCoordinate[2][1]/cncCodeDataPtr->xyCoordinate[2][0])/3.14*180;
	}
	else
	{
		cncCodeDataPtr->absAngle[1] = 180+atan(cncCodeDataPtr->xyCoordinate[2][1]/cncCodeDataPtr->xyCoordinate[2][0])/3.14*180;
	}

	if(cncCodeDataPtr->xyCoordinate[3][0] < 0 && cncCodeDataPtr->xyCoordinate[3][1]>0)
	{
		cncCodeDataPtr->absAngle[2] = acos(cncCodeDataPtr->xyCoordinate[3][0]/cncCodeDataPtr->lengthOriginToPoint[2])/3.14*180;
	}
	else if(cncCodeDataPtr->xyCoordinate[3][1] < 0 && cncCodeDataPtr->xyCoordinate[3][0]>0)
	{
		cncCodeDataPtr->absAngle[2] = 360+asin(cncCodeDataPtr->xyCoordinate[3][1]/cncCodeDataPtr->lengthOriginToPoint[2])/3.14*180;
	}
	else if(cncCodeDataPtr->xyCoordinate[3][0] >=0 && cncCodeDataPtr->xyCoordinate[3][1] >= 0)
	{
		cncCodeDataPtr->absAngle[2] = atan(cncCodeDataPtr->xyCoordinate[3][1]/cncCodeDataPtr->xyCoordinate[3][0])/3.14*180;
	}
	else
	{
		cncCodeDataPtr->absAngle[2] = 180+atan(cncCodeDataPtr->xyCoordinate[3][1]/cncCodeDataPtr->xyCoordinate[3][0])/3.14*180;
	}

	if(cncCodeDataPtr->xyCoordinate[4][0] < 0 && cncCodeDataPtr->xyCoordinate[4][1]>0)
	{
		cncCodeDataPtr->absAngle[3] = acos(cncCodeDataPtr->xyCoordinate[4][0]/cncCodeDataPtr->lengthOriginToPoint[3])/3.14*180;
	}
	else if(cncCodeDataPtr->xyCoordinate[1][1] < 0 && cncCodeDataPtr->xyCoordinate[1][0]>0)
	{
		cncCodeDataPtr->absAngle[3] = 360+asin(cncCodeDataPtr->xyCoordinate[4][1]/cncCodeDataPtr->lengthOriginToPoint[3])/3.14*180;
	}
	else if(cncCodeDataPtr->xyCoordinate[1][0] >=0 && cncCodeDataPtr->xyCoordinate[1][1] >= 0)
	{
		cncCodeDataPtr->absAngle[3] = atan(cncCodeDataPtr->xyCoordinate[4][1]/cncCodeDataPtr->xyCoordinate[4][0])/3.14*180;
	}
	else
	{
		cncCodeDataPtr->absAngle[3] = 180+atan(cncCodeDataPtr->xyCoordinate[4][1]/cncCodeDataPtr->xyCoordinate[4][0])/3.14*180;
	}

	if(cncCodeDataPtr->xyCoordinate[5][0] < 0 && cncCodeDataPtr->xyCoordinate[5][1]>0)
	{
		cncCodeDataPtr->absAngle[4] = acos(cncCodeDataPtr->xyCoordinate[5][0]/cncCodeDataPtr->lengthOriginToPoint[4])/3.14*180;
	}
	else if(cncCodeDataPtr->xyCoordinate[5][1] < 0 && cncCodeDataPtr->xyCoordinate[5][0]>0)
	{
		cncCodeDataPtr->absAngle[4] = 360+asin(cncCodeDataPtr->xyCoordinate[5][1]/cncCodeDataPtr->lengthOriginToPoint[4])/3.14*180;
	}
	else if(cncCodeDataPtr->xyCoordinate[5][0] >=0 && cncCodeDataPtr->xyCoordinate[5][1] >= 0)
	{
		cncCodeDataPtr->absAngle[4] = atan(cncCodeDataPtr->xyCoordinate[5][1]/cncCodeDataPtr->xyCoordinate[5][0])/3.14*180;
	}
	else
	{
		cncCodeDataPtr->absAngle[4] = 180+atan(cncCodeDataPtr->xyCoordinate[5][1]/cncCodeDataPtr->xyCoordinate[5][0])/3.14*180;
	}



	return;
}