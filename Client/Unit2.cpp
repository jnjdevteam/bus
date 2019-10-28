//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RxGIF"
#pragma link "ShockwaveFlashObjects_OCX"
#pragma link "WinGod"
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
    Form2->Hide();
    Form1->Show();
    Timer1->Enabled = false;
    Timer1->Interval = 0;
    Form1->ComboBox1->Items->LoadFromFile("C:\\BUS\\Client\\DATA\\id.txt");
    ListBox1->Items->LoadFromFile("C:\\BUS\\Client\\DATA\\option.txt");
    AnsiString m;
    m=ListBox1->Items->Strings[1];
    if(m==1)
    {
        Form1->CheckBox1->Checked=true;
    }
    else
    {
        Form1->CheckBox1->Checked=false;
    }
    Form1->ClientSocket1->Active = true;    
}
//---------------------------------------------------------------------------

