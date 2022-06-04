//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include <sqlite3.h>
#include <typeinfo>

#include "Unit2.h"
#include "Unit1.h"

#include "PassDecorator.h"
#include "CheckSign.h"

#pragma package(smart_init)
unsigned long count;
__fastcall Thread2::Thread2(FileSystem file,bool CreateSuspended)
	: TThread(CreateSuspended)
{
	File = file;
}
//---------------------------------------------------------------------------
void __fastcall Thread2::Execute()
{
	count=0;
	Form1->OpenFSButton->Enabled=false;
	Form1->Edit1->Enabled=false;
	char const * db_name = "Databases.db";

	sqlite3 *db;

	if ( sqlite3_open(db_name,&db))
	{
		sqlite3_close(db);
	}

	Iterator iterator=Iterator(File);

	//if(Form1->ClusterReadingMode->ItemIndex == 1)
	//iterator = PassDecorator(iterator);

	if(File.countCluster != 0)
	{
		iterator.First();
		iterator.SetDone(StrToLong("10000"));

		byte *dataBuffer = new byte[File.clusterSize];
		CheckSign check;
		for(;!iterator.IsDone();iterator.Next()){
		 if(iterator.GetCurrent(dataBuffer))
			{
				UnicodeString type = check.CheckSigns(dataBuffer);
				count++;
				if(count%10000==0)
					Synchronize(&UpdateTable);
				if(type!="NON")
				{
					AnsiString sql="INSERT INTO FILE (ID, NAME) VALUES ("+(AnsiString)iterator.GetPosition()+", \""+ type +"\" );";
					sqlite3_exec(db, sql.c_str(), NULL, 0,NULL);
				}

			 }
		}
		delete[] dataBuffer;
	}
	sqlite3_close(db);
	Synchronize(&End);
}
//---------------------------------------------------------------------------
void __fastcall Thread2::UpdateTable()
{
  Form1->ReloadViewDB();
  Form1->Label2->Caption="Кластеров считано:";
  Form1->Label2->Caption += count;

}
void __fastcall Thread2::End()
{
  Form1->OpenFSButton->Enabled=true;
  Form1->Edit1->Enabled=true;
  Form1->ReloadViewDB();
}
