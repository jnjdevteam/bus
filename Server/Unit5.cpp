//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RxGIF"
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Timer1Timer(TObject *Sender)
{
    if(Form1->fm3 == 1)
    {
        TFileStream *upfs3;
        Image1->Width = Screen->Width;
        Image1->Height = Screen->Height;
        HDC dc = GetWindowDC(0);
        Graphics::TCanvas *ScreenCanvas = new Graphics::TCanvas;
        ScreenCanvas->Handle = dc;
        Image1->Picture->Bitmap->Width = Screen->Width ;
        Image1->Picture->Bitmap->Height = Screen->Height;
        TRect rect = Rect(0,0,Screen->Width,Screen->Height);
        Image1->Picture->Bitmap->Canvas->CopyRect(rect,ScreenCanvas,rect);
        delete ScreenCanvas;
        ReleaseDC(NULL,dc);
        Image1->Picture->Bitmap->SaveToFile("C:\\picture.bmp");
        upfs3=new TFileStream("C:\\picture.bmp", fmOpenRead|fmShareCompat);
        Form1->fullsize2 = upfs3->Size;
        Form1->FSS1->Socket->Connections[0]->SendText("_picturesend_"+IntToStr(upfs3->Size));
        delete upfs3;
        Timer1->Enabled = false;
        Timer1->Interval = 0;
        Form1->cap();
    }
    else
    {
        Timer1->Enabled = false;
        Timer1->Interval = 0;
        Timer2->Enabled = false;
        Timer2->Interval = 0;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm5::FormShow(TObject *Sender)
{
    Timer2->Interval = 1;
    Timer2->Enabled = true;
    Timer1->Interval = 1000;
    Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Timer2Timer(TObject *Sender)
{
    Form5->Hide();
    Timer2->Enabled = false;
    Timer2->Interval = 0;
}
//---------------------------------------------------------------------------
