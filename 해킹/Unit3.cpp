//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RxGIF"
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormShow(TObject *Sender)
{
    Image1->Picture->LoadFromFile("C:\\picture2.bmp");    
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
    Form1->Button5->Click();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Image1Click(TObject *Sender)
{
    if(Form3->Align == alNone)
    {
        Form3->Align = alClient;
    }
    else
    {
        Form3->Align = alNone;
        Form3->Width = 289;
        Form3->Height = 277;
    }
}
//---------------------------------------------------------------------------
