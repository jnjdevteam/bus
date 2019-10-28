//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormShow(TObject *Sender)
{
    Form3->LB->Items->LoadFromFile("C:\\BUS\\Server\\DATA\\Option.txt");
    Edit1->Text=Form3->LB->Items->Strings[7];
    Edit2->Text=Form3->LB->Items->Strings[9];
    Edit3->Text=Form3->LB->Items->Strings[11];
    CheckBox1->Checked=StrToInt(Form3->LB->Items->Strings[5]);
    RadioGroup1->ItemIndex = StrToInt(Form3->LB->Items->Strings[13]);

    if(Form1->fm2 == 0)
    {
        Form2->Width = 217;
        Form2->Height = 362;
        RadioGroup1->Width = 200;
        RadioGroup1->Height = 152;
        Panel1->Visible = true;
    }
    else if(Form1->fm2 == 1)
    {
        Form2->Height = 167;
        Form2->Width = 153;
        RadioGroup1->Width = 136;
        RadioGroup1->Height = 152;
        Panel1->Visible = true;
    }
    Form2->Left = Form1->Left-Form2->Width;
    Form2->Top = Form1->Top;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
    Form3->LB->Items->LoadFromFile("C:\\BUS\\Server\\DATA\\Option.txt");
    Form3->LB->Items->Strings[7]=Edit1->Text;
    Form3->LB->Items->Strings[9]=Edit2->Text;
    Form3->LB->Items->Strings[11]=Edit3->Text;
    Form3->LB->Items->Strings[5]=IntToStr(CheckBox1->Checked);
    Form3->LB->Items->Strings[13]=IntToStr(RadioGroup1->ItemIndex);
    Form3->LB->Items->SaveToFile("C:\\BUS\\Server\\DATA\\Option.txt");
    for(int j=0; j<Form1->ListBox1->Items->Count; j++)
    {
        Form1->ServerSocket1->Socket->Connections[j]->SendText("_se_"+IntToStr(RadioGroup1->ItemIndex));
    }
    Form1->OptionCB->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioGroup1Click(TObject *Sender)
{
    Form3->LB->Items->LoadFromFile("C:\\BUS\\Server\\DATA\\Option.txt");
    Form3->LB->Items->Strings[13]=IntToStr(RadioGroup1->ItemIndex);
    Form3->LB->Items->SaveToFile("C:\\BUS\\Server\\DATA\\Option.txt");
    for(int j=0; j<Form1->ListBox1->Items->Count; j++)
    {
        Form1->ServerSocket1->Socket->Connections[j]->SendText("_se_"+IntToStr(RadioGroup1->ItemIndex));
    }
    if(Form1->fm2 == 1)
    {
        Form1->OptionCB->Checked = false;
    }
}
//---------------------------------------------------------------------------
