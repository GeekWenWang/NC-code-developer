#include < iostream >
#include < cstdlib >
#include < cmath >

#include "developData.h"

CNC_CODE_DATA cncCodeData;
CNC_CODE_DATA *cncCodeDataPtr;

using namespace std;




int main()
{
	cncCodeDataPtr = &cncCodeData;

	cncCodeDataInit(cncCodeDataPtr);

	
	cout << "請輸入5個座標點" << endl;
	
	for(int j=1 ; j<6 ; j++)
	{
		for(int i=0 ; i<2 ;i++)
		{
			cin >> cncCodeDataPtr->xyCoordinate[j][i] ;
		}
	}

	angleCaculator(cncCodeDataPtr);
	

	
	FILE *filePtr;

	filePtr = fopen("ncCode.txt","w+");

	fprintf(filePtr,"  N01 G0%d G91 D%.2f; \n N02 G04 1000; \n N03 G00 G91 X %.2f Y %.2f F500.0; \n N04 G04 1000; \n N05 G0%d G91 D%.2f; \n N06 G04 1000; \n N07 G00 G91 X %.2f Y %.2f F500.0; \n  N08 G04 1000; \n N09 G0%d G91 D%.2f; \n N10 G04 1000; \n N11 G00 G91 X %.2f Y %.2f F500.0; \n N12 G04 1000; \n N13 G0%d G91 D%.2f; \n N14 G04 1000; \n N15 G00 G91 X %.2f Y %.2f F500.0; \n N16 G04 1000; \n N17 G0%d G91 D%.2f; \n N18 G04 1000; \n N19 G00 G91 X %.2f Y %.2f F500.0; \n N20 G04 1000; \n N21 M30;", cncCodeDataPtr->Gcommand[0], cncCodeDataPtr->headAngle[0], cncCodeDataPtr->xyCoordinate[1][0], cncCodeDataPtr->xyCoordinate[1][1]
	, cncCodeDataPtr->Gcommand[1], cncCodeDataPtr->headAngle[1], cncCodeDataPtr->xyCoordinate[2][0], cncCodeDataPtr->xyCoordinate[2][1]
	, cncCodeDataPtr->Gcommand[2], cncCodeDataPtr->headAngle[2], cncCodeDataPtr->xyCoordinate[3][0], cncCodeDataPtr->xyCoordinate[3][1]
	, cncCodeDataPtr->Gcommand[3], cncCodeDataPtr->headAngle[3], cncCodeDataPtr->xyCoordinate[4][0], cncCodeDataPtr->xyCoordinate[4][1]
	, cncCodeDataPtr->Gcommand[4], cncCodeDataPtr->headAngle[4], cncCodeDataPtr->xyCoordinate[5][0], cncCodeDataPtr->xyCoordinate[5][1] );

	fclose(filePtr);
		




	return 1;
}


