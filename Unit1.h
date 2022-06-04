//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include "VirtualTrees.hpp"
#include <Vcl.Grids.hpp>
#include <Vcl.Outline.hpp>
#include <Vcl.Samples.DirOutln.hpp>
#include <Vcl.ExtCtrls.hpp>


//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TLabel *Label1;
	TVirtualStringTree *VirtualStringTree1;
	TButton *OpenFSButton;
	TButton *DeliteStringButton;
	TButton *ClearDBButton;
	TLabel *Label2;
	TLabel *Label3;
	TButton *Button1;
	void __fastcall Edit1DblClick(TObject *Sender);
	void __fastcall OpenFSButtonClick(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall VirtualStringTree1GetText(TBaseVirtualTree *Sender, PVirtualNode Node,
          TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText);
	void __fastcall DeliteStringButtonClick(TObject *Sender);
	void __fastcall ClearDBButtonClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);


private:

	void WorkToDB(AnsiString str);
    class Thread2 *myTread2;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
    void ReloadViewDB();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
typedef struct{

	unsigned long clusterNum;
	UnicodeString   name;

} TreeNodeStruct;
//---------------------------------------------------------------------------
#endif
