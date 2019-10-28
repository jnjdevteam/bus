//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RxGIF"
#pragma link "WinGod"
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
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
    : TForm(Owner)
{
    sho=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Join(int join)
{
    LB->Items->LoadFromFile("C:\\BUS\\Server\\DATA\\Option.txt");
    if(join == 0 && sho == 0)
    {
        LB->Items->Strings[1] = IntToStr(Pass2->Checked);
        LB->Items->Strings[3] = IntToStr(Security->Checked);
        LB->Items->Strings[5] = IntToStr(Auto->Checked);
        LB->Items->Strings[7] = IDCB->Text;
        LB->Items->Strings[9] = P1E->Text;
        LB->Items->Strings[11] = P2E->Text;
        LB->Items->Strings[13] = Form2->RadioGroup1->ItemIndex;
    }
    else if(join==1 && sho == 0)
    {
        Pass2->Checked = StrToInt(LB->Items->Strings[1]);
        Security->Checked = StrToInt(LB->Items->Strings[3]);
        Auto->Checked = StrToInt(LB->Items->Strings[5]);
        IDCB->Items->Add(LB->Items->Strings[7]);
        Form2->RadioGroup1->ItemIndex=StrToInt(LB->Items->Strings[13]);
        if(Auto->Checked==true)
        {
            IDCB->Text=LB->Items->Strings[7];
            P1E->Text=LB->Items->Strings[9];
            P2E->Text=LB->Items->Strings[11];
            Jo->Enabled = true;
            sho = 1;
        }
        else
        {
            MediaPlayer1->Close();
            MediaPlayer1->FileName = "C:\\BUS\\Server\\sound\\welcome.wav";
            MediaPlayer1->Open();
            MediaPlayer1->Play();
            Form3->Enabled = true;
        }
    }
    LB->Items->SaveToFile("C:\\BUS\\Server\\DATA\\Option.txt");
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Pass2Click(TObject *Sender)
{
    if(Pass2->Checked == true)
    {
        P2E->Visible = true;
    }
    else
    {
        P2E->Visible = false;
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Image2MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Image2->Picture->LoadFromFile("C:\\BUS\\Server\\images\\join_on.gif");
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Image2MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    ADOQuery1->Close();
    ADOQuery1->SQL->Clear();
    if(Pass2->Checked == true)
    {
        ADOQuery1->SQL->Add("Select id,pass,pass2 from Table1 where ID= '" + IDCB->Text + "'");
        ADOQuery1->ExecSQL();
        ADOQuery1->Open();
        AnsiString exid,expass,expass2;
        exid=DBGrid1->Fields[0]->Text;
        expass=DBGrid1->Fields[1]->Text;
        expass2=DBGrid1->Fields[2]->Text;
        if(P1E->Text == "" || IDCB->Text == "" || P2E->Text == "")
        {
            ShowMessage("아이디와 패스워드를 제대로 써주시기 바랍니다.");
        }
        else if(IDCB->Text == exid && P1E->Text == expass && P2E->Text == expass2)
        {
            Form3->Hide();
            Form1->Show();
            Form1->ServerSocket1->Active = true;
            Join(0);
        }
        else
        {
            ShowMessage("로그인에 실패하였습니다.");
        }
    }
    else
    {
        ADOQuery1->SQL->Add("Select id,pass from Table1 where ID= '" + IDCB->Text + "'");
        ADOQuery1->ExecSQL();
        ADOQuery1->Open();
        AnsiString exid,expass;
        exid=DBGrid1->Fields[0]->Text;
        expass=DBGrid1->Fields[1]->Text;
        if(P1E->Text == "" || IDCB->Text == "")
        {
            ShowMessage("아이디와 패스워드를 제대로 써주시기 바랍니다.");
        }
        else if(IDCB->Text == exid && P1E->Text == expass)
        {
            Form3->Hide();
            Form1->Show();
            Join(0);
            Form1->ServerSocket1->Active = true;
        }
        else
        {
            ShowMessage("로그인에 실패하였습니다.");
        }
    }
    Image2->Picture->LoadFromFile("C:\\BUS\\Server\\images\\join_off.gif");
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Image3MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Image3->Picture->LoadFromFile("C:\\BUS\\Server\\images\\close_on.gif");
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Image3MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    Image3->Picture->LoadFromFile("C:\\BUS\\Server\\images\\close_off.gif");
    Form3->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormShow(TObject *Sender)
{
    Join(1);
}
//---------------------------------------------------------------------------


void __fastcall TForm3::P2EKeyPress(TObject *Sender, char &Key)
{
    if(Key==0xd)
    {
        ADOQuery1->Close();
        ADOQuery1->SQL->Clear();
        if(Pass2->Checked == true)
        {
            ADOQuery1->SQL->Add("Select id,pass,pass2 from Table1 where ID= '" + IDCB->Text + "'");
            ADOQuery1->ExecSQL();
            ADOQuery1->Open();
            AnsiString exid,expass,expass2;
            exid=DBGrid1->Fields[0]->Text;
            expass=DBGrid1->Fields[1]->Text;
            expass2=DBGrid1->Fields[2]->Text;
            if(P1E->Text == "" || IDCB->Text == "" || P2E->Text == "")
            {
                ShowMessage("아이디와 패스워드를 제대로 써주시기 바랍니다.");
            }
            else if(IDCB->Text == exid && P1E->Text == expass && P2E->Text == expass2)
            {
                Form3->Hide();
                Form1->Show();
                Form1->ServerSocket1->Active = true;
                Join(0);
            }
            else
            {
                ShowMessage("로그인에 실패하였습니다.");
            }
        }
        else
        {
            ADOQuery1->SQL->Add("Select id,pass from Table1 where ID= '" + IDCB->Text + "'");
            ADOQuery1->ExecSQL();
            ADOQuery1->Open();
            AnsiString exid,expass;
            exid=DBGrid1->Fields[0]->Text;
            expass=DBGrid1->Fields[1]->Text;
            if(P1E->Text == "" || IDCB->Text == "")
            {
                ShowMessage("아이디와 패스워드를 제대로 써주시기 바랍니다.");
            }
            else if(IDCB->Text == exid && P1E->Text == expass)
            {
                Form3->Hide();
                Form1->Show();
                Join(0);
                Form1->ServerSocket1->Active = true;
            }
            else
            {
                ShowMessage("로그인에 실패하였습니다.");
            }
        }
        Image2->Picture->LoadFromFile("C:\\BUS\\Server\\images\\join_off.gif");
    }
    if(Key!='0'&&Key!='1'&&Key!='2'&&Key!='3'&&Key!='4'&&Key!='5'&&Key!='6'&&Key!='7'&&Key!='8'&&Key!='9'&&Key!=8)
    {
        Key=0;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm3::MainImageMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    TControl *SenderControl = dynamic_cast<TControl *>(Sender);
    int SysCommWparam; 

    if(X < 0 && Y < 0)
        SysCommWparam = SC_DRAG_RESIZEUL;
    else if(X > SenderControl->Width-0 && Y > SenderControl->Height-0) 
        SysCommWparam = SC_DRAG_RESIZEDR; 
    else if(X < 0 && Y > SenderControl->Height-0) 
        SysCommWparam = SC_DRAG_RESIZEDL; 
    else if(X > SenderControl->Width-0 && Y < 0) 
        SysCommWparam = SC_DRAG_RESIZEUR; 
    else if(X < 0)
        SysCommWparam = SC_DRAG_RESIZEL; 
    else if(X > SenderControl->Width-0) 
        SysCommWparam = SC_DRAG_RESIZER; 
    else if(Y < 0) 
        SysCommWparam = SC_DRAG_RESIZEU; 
    else if(Y > SenderControl->Height-0)
        SysCommWparam = SC_DRAG_RESIZED;
    else
        SysCommWparam = SC_DRAG_MOVE;

    ReleaseCapture();
    SendMessage(Form3->Handle, WM_SYSCOMMAND, SysCommWparam, 0);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::JoTimer(TObject *Sender)
{
    ADOQuery1->Close();
    ADOQuery1->SQL->Clear();
    if(Pass2->Checked == true)
    {
        ADOQuery1->SQL->Add("Select id,pass,pass2 from Table1 where ID= '" + IDCB->Text + "'");
        ADOQuery1->ExecSQL();
        ADOQuery1->Open();
        AnsiString exid,expass,expass2;
        exid=DBGrid1->Fields[0]->Text;
        expass=DBGrid1->Fields[1]->Text;
        expass2=DBGrid1->Fields[2]->Text;
        if(P1E->Text == "" || IDCB->Text == "" || P2E->Text == "")
        {
            ShowMessage("아이디와 패스워드를 제대로 써주시기 바랍니다.");
        }
        else if(IDCB->Text == exid && P1E->Text == expass && P2E->Text == expass2)
        {
            Form3->Hide();
            Form1->Show();
            Form1->ServerSocket1->Active = true;
            Join(0);
        }
        else
        {
            ShowMessage("로그인에 실패하였습니다.");
            IDCB->Text = "";
            P1E->Text = "";
            P2E->Text = "";
        }
    }
    else
    {
        ADOQuery1->SQL->Add("Select id,pass from Table1 where ID= '" + IDCB->Text + "'");
        ADOQuery1->ExecSQL();
        ADOQuery1->Open();
        AnsiString exid,expass;
        exid=DBGrid1->Fields[0]->Text;
        expass=DBGrid1->Fields[1]->Text;
        if(P1E->Text == "" || IDCB->Text == "")
        {
            ShowMessage("아이디와 패스워드를 제대로 써주시기 바랍니다.");
        }
        else if(IDCB->Text == exid && P1E->Text == expass)
        {
            Form3->Hide();
            Form1->Show();
            Join(0);
            Form1->ServerSocket1->Active = true;
        }
        else
        {
            ShowMessage("로그인에 실패하였습니다.");
            IDCB->Text = "";
            P1E->Text = "";
            P2E->Text = "";
        }
    }
    Jo->Interval = 0;
    Jo->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::P1EKeyPress(TObject *Sender, char &Key)
{
    if(Key==0xd)
    {
        ADOQuery1->Close();
        ADOQuery1->SQL->Clear();
        if(Pass2->Checked == true)
        {
            ADOQuery1->SQL->Add("Select id,pass,pass2 from Table1 where ID= '" + IDCB->Text + "'");
            ADOQuery1->ExecSQL();
            ADOQuery1->Open();
            AnsiString exid,expass,expass2;
            exid=DBGrid1->Fields[0]->Text;
            expass=DBGrid1->Fields[1]->Text;
            expass2=DBGrid1->Fields[2]->Text;
            if(P1E->Text == "" || IDCB->Text == "" || P2E->Text == "")
            {
                ShowMessage("아이디와 패스워드를 제대로 써주시기 바랍니다.");
            }
            else if(IDCB->Text == exid && P1E->Text == expass && P2E->Text == expass2)
            {
                Form3->Hide();
                Form1->Show();
                Form1->ServerSocket1->Active = true;
                Join(0);
            }
            else
            {
                ShowMessage("로그인에 실패하였습니다.");
            }
        }
        else
        {
            ADOQuery1->SQL->Add("Select id,pass from Table1 where ID= '" + IDCB->Text + "'");
            ADOQuery1->ExecSQL();
            ADOQuery1->Open();
            AnsiString exid,expass;
            exid=DBGrid1->Fields[0]->Text;
            expass=DBGrid1->Fields[1]->Text;
            if(P1E->Text == "" || IDCB->Text == "")
            {
                ShowMessage("아이디와 패스워드를 제대로 써주시기 바랍니다.");
            }
            else if(IDCB->Text == exid && P1E->Text == expass)
            {
                Form3->Hide();
                Form1->Show();
                Join(0);
                Form1->ServerSocket1->Active = true;
            }
            else
            {
                ShowMessage("로그인에 실패하였습니다.");
            }
        }
        Image2->Picture->LoadFromFile("C:\\BUS\\Server\\images\\join_off.gif");
    }
}
//---------------------------------------------------------------------------

