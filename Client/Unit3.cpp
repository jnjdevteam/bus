//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "trayicon"
#pragma link "RxGIF"
#pragma resource "*.dfm"
#define SC_DRAG_RESIZEL  0xf001  // left resize 
#define SC_DRAG_RESIZER  0xf002  // right resize
#define SC_DRAG_RESIZEU  0xf003  // upper resize
#define SC_DRAG_RESIZEUL 0xf004  // upper-left resize
#define SC_DRAG_RESIZEUR 0xf005  // upper-right resize
#define SC_DRAG_RESIZED  0xf006  // down resize
#define SC_DRAG_RESIZEDL 0xf007  // down-left resize
#define SC_DRAG_RESIZEDR 0xf008  // down-right resize
#define SC_DRAG_MOVE     0xf012  // move
#pragma resource "winxp.res"
TForm3 *Form3;
int se3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action)
{
    if(Form1->ClientSocket1->Active == false)
    {
        Action = caFree;
        Form1->Close();
        Form2->Close();
    }
    else
    {
        if(MessageBox(Handle, "종료하시겠습니까?", "확인", MB_YESNO) == IDYES)
        {
            Action = caFree;
            TrayIcon1->Visible = false;
            Form1->Close();
            Form2->Close();
        }
        else
        {
            Action = caNone;
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N2Click(TObject *Sender)
{
    N1->Enabled = true;
    N2->Enabled = false;
    Form3->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N1Click(TObject *Sender)
{
    N1->Enabled = false;
    N2->Enabled = true;
    Form3->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N4Click(TObject *Sender)
{
    Form3->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::TrayIcon1Restore(TObject *Sender)
{
    N1->Enabled = false;
    N2->Enabled = true;
    Form3->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Image6Click(TObject *Sender)
{
    Panel4->Visible = true;
    Panel5->Visible = false;
    Panel6->Visible = false;
    SpeedButton1->Visible = true;
    Button1->Visible = false;
    Button2->Visible = false;
    Button3->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Image10Click(TObject *Sender)
{
    Panel4->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::SpeedButton1MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(X<=20 && X>=0 && Y<=20 && Y>=0)
    {
        Panel4->Visible = false;
        Panel5->Visible = false;
        Panel6->Visible = false;
        SpeedButton1->Visible = false;
        Button1->Visible = true;
        Button2->Visible = true;
        Button3->Visible = true;
    }
    SpeedButton1->Glyph->LoadFromFile("C:\\BUS\\Client\\images\\Home_off.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TForm3::SpeedButton2MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    SpeedButton2->Glyph->LoadFromFile("C:\\BUS\\Client\\images\\bottom_on.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TForm3::SpeedButton3MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    SpeedButton3->Glyph->LoadFromFile("C:\\BUS\\Client\\images\\X_on.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TForm3::SpeedButton3MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    SpeedButton3->Glyph->LoadFromFile("C:\\BUS\\Client\\images\\X_off.bmp");
    if(X<=20 && X>=0 && Y<=20 && Y>=0)
    {
        Form3->Close();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm3::SpeedButton2MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(X<=20 && X>=0 && Y<=20 && Y>=0)
    {
        N1->Enabled = true;
        N2->Enabled = false;
        Form3->Visible = false;
    }
    SpeedButton2->Glyph->LoadFromFile("C:\\BUS\\Client\\images\\bottom_off.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TForm3::SpeedButton1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    SpeedButton1->Glyph->LoadFromFile("C:\\BUS\\Client\\images\\Home_on.bmp");

}
//---------------------------------------------------------------------------

void __fastcall TForm3::Image5MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    TControl *SenderControl = dynamic_cast<TControl *>(Sender);
    int SysCommWparam; 

    if(X < 0 && Y < 0)
        SysCommWparam = SC_DRAG_RESIZEUL;
    else if(X > SenderControl->Width && Y > SenderControl->Height)
        SysCommWparam = SC_DRAG_RESIZEDR; 
    else if(X < 0 && Y > SenderControl->Height)
        SysCommWparam = SC_DRAG_RESIZEDL; 
    else if(X > SenderControl->Width && Y < 0)
        SysCommWparam = SC_DRAG_RESIZEUR; 
    else if(X < 0)
        SysCommWparam = SC_DRAG_RESIZEL; 
    else if(X > SenderControl->Width) 
        SysCommWparam = SC_DRAG_RESIZER; 
    else if(Y < 0) 
        SysCommWparam = SC_DRAG_RESIZEU; 
    else if(Y > SenderControl->Height)
        SysCommWparam = SC_DRAG_RESIZED;
    else
        SysCommWparam = SC_DRAG_MOVE;

    ReleaseCapture();
    SendMessage(Form3->Handle, WM_SYSCOMMAND, SysCommWparam, 0);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender)
{
    Panel4->Visible = true;
    Panel5->Visible = false;
    Panel6->Visible = false;
    SpeedButton1->Visible = true;
    Button1->Visible = false;
    Button2->Visible = false;
    Button3->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::TreeView1Click(TObject *Sender)
{
    Memo1->Lines->LoadFromFile("C:\\BUS\\Server\\DATA\\"+TreeView1->Selected->Text+".txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Memo1Change(TObject *Sender)
{
    Memo1->Lines->LoadFromFile("C:\\BUS\\Server\\DATA\\"+TreeView1->Selected->Text+".txt");    
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Image7Click(TObject *Sender)
{
    Panel4->Visible = false;
    Panel5->Visible = true;
    Panel6->Visible = false;
    SpeedButton1->Visible = true;
    Button1->Visible = false;
    Button2->Visible = false;
    Button3->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{
    Panel4->Visible = false;
    Panel5->Visible = true;
    Panel6->Visible = false;
    SpeedButton1->Visible = true;
    Button1->Visible = false;
    Button2->Visible = false;
    Button3->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::TreeView2Click(TObject *Sender)
{
    Memo2->Lines->LoadFromFile("C:\\BUS\\Server\\DATA\\"+TreeView2->Selected->Text+"_2.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Memo2Change(TObject *Sender)
{
    Memo2->Lines->LoadFromFile("C:\\BUS\\Server\\DATA\\"+TreeView2->Selected->Text+"_2.txt");    
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Image8Click(TObject *Sender)
{
    Panel4->Visible = false;
    Panel5->Visible = false;
    Panel6->Visible = true;
    SpeedButton1->Visible = true;
    Button1->Visible = false;
    Button2->Visible = false;
    Button3->Visible = false;
    switch(Form1->se2)
    {
        case 0: RadioButton1->Checked = true;
        se3=0;
        break;
        case 1: RadioButton2->Checked = true;
        se3=1;
        break;
        case 2: RadioButton3->Checked = true;
        se3=2;
        break;
        case 3: RadioButton4->Checked = true;
        se3=3;
        break;
        case 4: RadioButton5->Checked = true;
        se3=4;
        break;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button3Click(TObject *Sender)
{
    Panel4->Visible = false;
    Panel5->Visible = false;
    Panel6->Visible = true;
    SpeedButton1->Visible = true;
    Button1->Visible = false;
    Button2->Visible = false;
    Button3->Visible = false;
    switch(Form1->se2)
    {
        case 0: RadioButton1->Checked = true;
        se3=0;
        break;
        case 1: RadioButton2->Checked = true;
        se3=1;
        break;
        case 2: RadioButton3->Checked = true;
        se3=2;
        break;
        case 3: RadioButton4->Checked = true;
        se3=3;
        break;
        case 4: RadioButton5->Checked = true;
        se3=4;
        break;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm3::RadioButton1Click(TObject *Sender)
{
    se3=0;
    RadioButton2->Checked = false;
    RadioButton3->Checked = false;
    RadioButton4->Checked = false;
    RadioButton5->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::RadioButton2Click(TObject *Sender)
{
    se3=1;
    RadioButton1->Checked = false;
    RadioButton3->Checked = false;
    RadioButton4->Checked = false;
    RadioButton5->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::RadioButton3Click(TObject *Sender)
{
    se3=2;
    RadioButton1->Checked = false;
    RadioButton2->Checked = false;
    RadioButton4->Checked = false;
    RadioButton5->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::RadioButton4Click(TObject *Sender)
{
    se3=3;
    RadioButton1->Checked = false;
    RadioButton2->Checked = false;
    RadioButton3->Checked = false;
    RadioButton5->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::RadioButton5Click(TObject *Sender)
{
    se3=4;
    RadioButton1->Checked = false;
    RadioButton2->Checked = false;
    RadioButton3->Checked = false;
    RadioButton4->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button4Click(TObject *Sender)
{
    Form1->ClientSocket1->Socket->SendText("_msg1_"+IntToStr(se3));
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button5Click(TObject *Sender)
{
    Form1->ClientSocket1->Socket->SendText("_msg2_"+Memo3->Lines->Text);
    Memo3->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button6Click(TObject *Sender)
{
    Memo3->Clear();    
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button7Click(TObject *Sender)
{
    ShellExecute(Handle,"open","C:\\BUS\\BUS Client.exe","","",SW_SHOWNORMAL);
    fm1=0;
    Form1->ClientSocket1->Active = false;
    Form3->Close();
}
//---------------------------------------------------------------------------

