#include "CheckSign.h"

UnicodeString CheckSign::CheckSigns(BYTE *dataBuffer){

	byte jpeg[4]={255, 216, 255,224};
	byte MSOfiice[11]={95,84,121,112,101,115,93,46,120,109,108};
	byte zip[4]={80,75,3,4};
	byte photoshop[12]={56,66,80,83,0,1,0,0,0,0,0,0};
	byte png[8]={137,80,78,71,13,10,26,10};


	 if(dataBuffer[0]==png[0])
		if(Check(0,png,8,dataBuffer))
			return "PNG";
	 if(dataBuffer[0]==jpeg[0])
		if(Check(0,jpeg,4,dataBuffer))
			return "JPEG";

	for(int i=0; i<512; i++)
	{
	 if(dataBuffer[i]==MSOfiice[0])
		if(Check(i,MSOfiice,11,dataBuffer))
			return "MS Office";
	}

	if(dataBuffer[0]==zip[0])
		if(Check(0,zip,4,dataBuffer))
			return "ZIP";

	return "NON";
}

bool CheckSign::Check(int pos,BYTE sign[],int length,BYTE *dataBuffer){
	for(int j=0; j<length;j++)
	{
	  if(sign[j]!=dataBuffer[pos+j])
		return false;
	}
    return true;
}




