#include "FileSystem.h"

long FileSystem::GetDec(byte vBootRecord[],int size){

	long sum=0;
	for (int i = 0; i < size; i++)
	{
		sum+=vBootRecord[i]*std::pow(16,i*2);
	}
	return sum;
}
bool FileSystem::ReedBootRecord(wchar_t* path,BYTE *dataBuffer){
	 if(fileHander!=NULL)
        ClosedHandle();

	 if(ReedFileHander(path))
		if(ReedCluster(0,dataBuffer))
			return true;

     return false;
}

bool
	FileSystem::ReedFileHander(wchar_t* path){

    fileHander=CreateFileW(path,
	GENERIC_READ,
	FILE_SHARE_READ | FILE_SHARE_WRITE,
	NULL,
	OPEN_EXISTING,
	FILE_ATTRIBUTE_NORMAL,
	NULL);

	if(fileHander == INVALID_HANDLE_VALUE)
	{
		ShowMessage(L"������ ������ �����. ����������� ����� ��������������.");
		ClosedHandle();
		return false;
	}
	 return true;
	}

bool
	FileSystem::ReedCluster(unsigned long long number, BYTE *dataBuffer){

	LARGE_INTEGER sectorOffset;
	sectorOffset.QuadPart=clusterSize*number;;
	unsigned long long currentPosition = SetFilePointer(fileHander,sectorOffset.LowPart,&sectorOffset.HighPart ,FILE_BEGIN);

	 if(currentPosition != sectorOffset.LowPart)  {
		 ShowMessage(L"������ ��������� �������.");
		 return false;
	 }

	 DWORD bytesToRead=clusterSize;
	 DWORD bytesRead;
	 bool readResult = ReadFile(fileHander,dataBuffer,bytesToRead,&bytesRead,NULL);

	 if(readResult == false || bytesRead != bytesToRead){
		 ShowMessage(L"������ ������ ��������.");
		 return false;
	 }
     return true;
	}

void
	FileSystem::ViewInfo(TLabel *Label){

		Label->Caption="�������� �������: ";
		Label->Caption+=name;
	}
void FileSystem::ClosedHandle(){
    CloseHandle(fileHander);
}

