//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include "trayicon.h"
#include <ImgList.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include "RxGIF.hpp"
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TPanel *Panel2;
    TPanel *Panel3;
    TTrayIcon *TrayIcon1;
    TPopupMenu *PopupMenu1;
    TImageList *ImageList1;
    TMenuItem *N1;
    TMenuItem *N2;
    TMenuItem *N3;
    TMenuItem *N4;
    TImage *Image3;
    TImage *Image4;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TImage *Image5;
    TImage *Image6;
    TImage *Image7;
    TImage *Image8;
    TPanel *Panel4;
    TImage *Image9;
    TSpeedButton *SpeedButton1;
    TSpeedButton *SpeedButton2;
    TSpeedButton *SpeedButton3;
    TLabel *Label1;
    TLabel *Label5;
    TButton *Button1;
    TButton *Button2;
    TButton *Button3;
    TTreeView *TreeView1;
    TMemo *Memo1;
    TPanel *Panel5;
    TImage *Image1;
    TTreeView *TreeView2;
    TMemo *Memo2;
    TPanel *Panel6;
    TImage *Image2;
    TLabel *Label6;
    TRadioButton *RadioButton1;
    TRadioButton *RadioButton2;
    TRadioButton *RadioButton3;
    TRadioButton *RadioButton4;
    TRadioButton *RadioButton5;
    TLabel *Label7;
    TLabel *Label8;
    TLabel *Label9;
    TLabel *Label10;
    TLabel *Label11;
    TButton *Button4;
    TLabel *Label12;
    TMemo *Memo3;
    TButton *Button5;
    TButton *Button6;
    TButton *Button7;
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall N2Click(TObject *Sender);
    void __fastcall N1Click(TObject *Sender);
    void __fastcall N4Click(TObject *Sender);
    void __fastcall TrayIcon1Restore(TObject *Sender);
    void __fastcall Image6Click(TObject *Sender);
    void __fastcall Image10Click(TObject *Sender);
    void __fastcall SpeedButton1MouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall SpeedButton2MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall SpeedButton3MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall SpeedButton3MouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall SpeedButton2MouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall SpeedButton1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall Image5MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall TreeView1Click(TObject *Sender);
    void __fastcall Memo1Change(TObject *Sender);
    void __fastcall Image7Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall TreeView2Click(TObject *Sender);
    void __fastcall Memo2Change(TObject *Sender);
    void __fastcall Image8Click(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall RadioButton1Click(TObject *Sender);
    void __fastcall RadioButton2Click(TObject *Sender);
    void __fastcall RadioButton3Click(TObject *Sender);
    void __fastcall RadioButton4Click(TObject *Sender);
    void __fastcall RadioButton5Click(TObject *Sender);
    void __fastcall Button4Click(TObject *Sender);
    void __fastcall Button5Click(TObject *Sender);
    void __fastcall Button6Click(TObject *Sender);
    void __fastcall Button7Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
int fm1;
    __fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
