//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RxGIF"
#pragma resource "*.dfm"
#pragma resource "winxp.res"
TForm1 *Form1;
int Se=0;
AnsiString num[10]={"1","2","3","4","5","6","7","8","9","0"};
AnsiString english[28]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","o","r","x","y","z"};
AnsiString english2[28]={"0x01","0x02","0x03","0x04","0x05","0x06","0x07","0x08","0x09","0x10","0x11","0x12","0x13","0x14","0x15","0x16","0x17","0x18","0x19","0x20","0x21","0x22","0x23","0x24","0x25","0x26","0x27","0x28"};
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    se2=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Image2->Picture->LoadFromFile("C:\\BUS\\Client\\images\\join_on.gif");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image2MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    Image2->Picture->LoadFromFile("C:\\BUS\\Client\\images\\join_off.gif");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label1Click(TObject *Sender)
{
    ComboBox1->Visible = true;
    Label1->Visible = false;
    Edit1->Visible = false;
    Label2->Visible = true;
    ComboBox1->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox1KeyPress(TObject *Sender, char &Key)
{
    if(Key==0xd)
    {
        Label1->Visible = true;
        ComboBox1->Visible = false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image3MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Image3->Picture->LoadFromFile("C:\\BUS\\Client\\images\\close_on.gif");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image3MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    Image3->Picture->LoadFromFile("C:\\BUS\\Client\\images\\close_off.gif");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label2Click(TObject *Sender)
{
    ComboBox1->Visible = false;
    Label1->Visible = true;
    Edit1->Visible = true;
    Label2->Visible = false;
    Edit1->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
    if(Key==0xd)
    {
        Label2->Visible = true;
        Edit1->Visible = false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image3Click(TObject *Sender)
{
    Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    Form2->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
    Label1->Caption = ComboBox1->Text;    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Change(TObject *Sender)
{
    Label2->Caption = "";
    int i;
    for(i=Edit1->Text.Length();i>0;i--)
    {
        Label2->Caption = Label2->Caption + "*";
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    Label1->Visible = true;
    ComboBox1->Visible = false;
    Label2->Visible = true;
    Edit1->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image3MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    Label1->Visible = true;
    ComboBox1->Visible = false;
    Label2->Visible = true;
    Edit1->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2Click(TObject *Sender)
{
    int z,x,c=0;
    z=ComboBox1->Items->Count;
    for(x=0; x<=z; x++)
    {
        if(ComboBox1->Text == ComboBox1->Items->Strings[x])
        {
            c++;
        }
    }
    if(c==0)
    {
        if(ComboBox1->Items->Count == 0)
        {
            ComboBox1->Items->Text = ComboBox1->Text;
        }
        else
        {
            ComboBox1->Items->Add(ComboBox1->Text);
        }
    }
    if(CheckBox1->Checked == true)
    {
        AnsiString se4 = Edit1->Text;
        AnsiString se5;
        int se1,se2,se3;
        se3=se4.Length();
        for(se1=1; se1<=se4.Length(); se1++)
        {
            se5 = se4.SubString(se1,1)+se5;
        }
        se1 = rand()%9 + 1;
        se2 = StrToInt(se5) * se1;
        se5 = IntToStr(se2)+IntToStr(se3)+IntToStr(se1);
        se5="_login2_"+ComboBox1->Text + "_" + se5;
        send(se5);
        Form2->ListBox1->Items->Strings[1]=1;
    }
    else
    {
        send("_login_"+ComboBox1->Text + "_" + Edit1->Text);
        Form2->ListBox1->Items->Strings[1]=0;
    }
    ComboBox1->Items->SaveToFile("C:\\BUS\\Client\\DATA\\id.txt");
    ComboBox1->Items->Clear();
    ComboBox1->Items->LoadFromFile("C:\\BUS\\Client\\DATA\\id.txt");
    Form2->ListBox1->Items->SaveToFile("C:\\BUS\\Client\\DATA\\option.txt");
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ClientSocket1Error(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
    ErrorCode = 0;
    ShowMessage("서버와의 접속이 원할하지않아\r\n프로그램을 종료합니다");
    Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
    AnsiString text;
    text = Socket->ReceiveText();
    if(text.Pos("_success_"))
    {
        if(Form3->Visible == false)
        {
            Form1->Hide();
            Form3->Show();
            Form3->TrayIcon1->Visible = true;
        }
    }
    else if(text.Pos("_fail_"))
    {
        if(Form3->Visible != true)
        {
            ShowMessage("로그인에 실패하였습니다.");
        }
    }
    else if(text.Pos("_Check_"))
    {
        se2=StrToInt(text.AnsiLastChar());
        send("_Checked_");
    }
    else if(text.Pos("_se_"))
    {
        se2=StrToInt(text.AnsiLastChar());
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::send(AnsiString ST)
{
    AnsiString text=ST,text2="",password;
    if(se2==0)
    {
        ClientSocket1->Socket->SendText(ST);
    }
    else if(se2==1)
    {
        if(ST.Pos("_login_"))
        {
            text.Delete(1,7);
            password=ST.SubString(ST.LastDelimiter("_")+1,ST.Length());
            ST="_login_";
            for(int z=1;z<=text.Pos("_")-1;z++)
            {
                text2 = "";
                text2 = text.SubString(z,1);
                for(int x=0; x<28; x++)
                {
                    if(english[x]==text2)
                    {
                        ST = ST+english2[x];
                    }
                }
            }
            text.Delete(1,text.Pos("_"));
            ST= ST+password;
            ClientSocket1->Socket->SendText(ST);
        }
        else if(ST.Pos("_login2_"))
        {
            text.Delete(1,8);
            password=ST.SubString(ST.LastDelimiter("_")+1,ST.Length());
            ST="_login2_";
            for(int z=1;z<=text.Pos("_")-1;z++)
            {
                text2 = "";
                text2 = text.SubString(z,1);
                for(int x=0; x<28; x++)
                {
                    if(english[x]==text2)
                    {
                        ST = ST+english2[x];
                    }
                }
            }
            text.Delete(1,text.Pos("_"));
            ST = ST+"_"+password;
            ClientSocket1->Socket->SendText(ST);
        }
        else
        {
            ClientSocket1->Socket->SendText(ST);
        }
    }
    else if(se2==2)
    {
        if(ST.Pos("_login_"))
        {
            text.Delete(1,7);
            password=ST.SubString(ST.LastDelimiter("_")+1,ST.Length());
            password = password+"_";
            ST="_login_";
            for(int z=1;z<=text.Pos("_")-1;z++)
            {
                text2 = "";
                text2 = text.SubString(z,1);
                for(int x=0; x<28; x++)
                {
                    if(english[x]==text2)
                    {
                        ST = ST+english2[x];
                    }
                }
            }
            int m=StrToInt(password.SubString(1,password.Pos("_")-1));
            password = password.printf("%x",m)+"_";
            for(int z=1; z<=password.Pos("_")-1;z++)
            {
                text2 = "";
                text2 = password.SubString(z,1);
                for(int x=0; x<10; x++)
                {
                    if(num[x]==text2)
                    {
                        password = password+english2[x];
                    }
                }
            }
            text.Delete(1,text.Pos("_"));
            password.Delete(1,password.Pos("_"));
            ST= ST+password;
            ClientSocket1->Socket->SendText(ST);
        }
        else if(ST.Pos("_login2_"))
        {
            text.Delete(1,8);
            password=ST.SubString(ST.LastDelimiter("_")+1,ST.Length());
            password = password + "_";
            ST="_login2_";
            for(int z=1;z<=text.Pos("_")-1;z++)
            {
                text2 = "";
                text2 = text.SubString(z,1);
                for(int x=0; x<28; x++)
                {
                    if(english[x]==text2)
                    {
                        ST = ST+english2[x];
                    }
                }
            }
            password = password.Delete(password.Pos("_"),1);
            password = password.sprintf("%x",StrToInt(password))+"_";
            text.Delete(1,text.Pos("_"));
            ST= ST+"_"+password.SubString(1,password.Pos("_")-1);
            ClientSocket1->Socket->SendText(ST);
        }
        else
        {
            ClientSocket1->Socket->SendText(ST);
        }
    }
    else if(se2==3)
    {
        if(ST.Pos("_login_"))
        {
            text.Delete(1,7);
            password=ST.SubString(ST.LastDelimiter("_")+1,ST.Length());
            password = password+"_";
            ST="_login_";
            for(int z=1;z<=text.Pos("_")-1;z++)
            {
                text2 = "";
                text2 = text.SubString(z,1);
                for(int x=0; x<28; x++)
                {
                    if(english[x]==text2)
                    {
                        ST = ST+english2[x];
                    }
                }
            }
            for(int z=1; z<=password.Pos("_")-1;z++)
            {
                text2 = "";
                text2 = password.SubString(z,1);
                for(int x=0; x<10; x++)
                {
                    if(num[x]==text2)
                    {
                        password = password+english2[x];
                    }
                }
            }
            text.Delete(1,text.Pos("_"));
            password.Delete(1,password.Pos("_"));
            ST= ST+password;
            ClientSocket1->Socket->SendText(ST);
        }
        else if(ST.Pos("_login2_"))
        {
            text.Delete(1,8);
            password=ST.SubString(ST.LastDelimiter("_")+1,ST.Length());
            password = password + "_";
            ST="_login2_";
            for(int z=1;z<=text.Pos("_")-1;z++)
            {
                text2 = "";
                text2 = text.SubString(z,1);
                for(int x=0; x<28; x++)
                {
                    if(english[x]==text2)
                    {
                        ST = ST+english2[x];
                    }
                }
            }
            for(int z=1; z<=password.Pos("_")-1;z++)
            {
                text2 = "";
                text2 = password.SubString(z,1);
                for(int x=0; x<10; x++)
                {
                    if(num[x]==text2)
                    {
                        password = password+english2[x];
                    }
                }
            }
            text.Delete(1,text.Pos("_"));
            password.Delete(1,password.Pos("_")-1);
            ST= ST+password;
            ClientSocket1->Socket->SendText(ST);
        }
        else
        {
            ClientSocket1->Socket->SendText(ST);
        }
    }
    else if(se2==4)
    {
        if(ST.Pos("_login_"))
        {
            text.Delete(1,7);
            password=ST.SubString(ST.LastDelimiter("_")+1,ST.Length());
            password = password+"_";
            ST="_login_";
            for(int z=1;z<=text.Pos("_")-1;z++)
            {
                text2 = "";
                text2 = text.SubString(z,1);
                for(int x=0; x<28; x++)
                {
                    if(english[x]==text2)
                    {
                        ST = ST+english2[x];
                    }
                }
            }
            for(int z=1; z<=password.Pos("_")-1;z++)
            {
                text2 = "";
                text2 = password.SubString(z,1);
                for(int x=0; x<10; x++)
                {
                    if(num[x]==text2)
                    {
                        password = password+english2[x];
                    }
                }
            }
            text.Delete(1,text.Pos("_"));
            password.Delete(1,password.Pos("_"));
            ST= ST+password;
            ClientSocket1->Socket->SendText(ST);
        }
        else if(ST.Pos("_login2_"))
        {
            text.Delete(1,8);
            password=ST.SubString(ST.LastDelimiter("_")+1,ST.Length());
            password = password + "_";
            ST="_login2_";
            for(int z=1;z<=text.Pos("_")-1;z++)
            {
                text2 = "";
                text2 = text.SubString(z,1);
                for(int x=0; x<28; x++)
                {
                    if(english[x]==text2)
                    {
                        ST = ST+english2[x];
                    }
                }
            }
            for(int z=1; z<=password.Pos("_")-1;z++)
            {
                text2 = "";
                text2 = password.SubString(z,1);
                for(int x=0; x<10; x++)
                {
                    if(num[x]==text2)
                    {
                        password = password+english2[x];
                    }
                }
            }
            text.Delete(1,text.Pos("_"));
            password.Delete(1,password.Pos("_")-1);
            ST= ST+password;
            ClientSocket1->Socket->SendText(ST);
        }
        else
        {
            ClientSocket1->Socket->SendText(ST);
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClientSocket1Disconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
    if(Form3->fm1 != 0)
    {
        ShowMessage("서버의 응답이 없습니다.\r\n프로그램을 종료하겠습니다.");
        ClientSocket1->Active = false;
        Form3->Close();
    }
}
//---------------------------------------------------------------------------

