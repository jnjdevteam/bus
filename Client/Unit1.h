//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "RxGIF.hpp"
#include <ExtCtrls.hpp>
#include <ScktComp.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TImage *Image1;
    TComboBox *ComboBox1;
    TEdit *Edit1;
    TImage *Image2;
    TLabel *Label1;
    TLabel *Label2;
    TImage *Image3;
    TClientSocket *ClientSocket1;
    TCheckBox *CheckBox1;
    TLabel *Label3;
    void __fastcall Image2MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall Image2MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall Label1Click(TObject *Sender);
    void __fastcall ComboBox1KeyPress(TObject *Sender, char &Key);
    void __fastcall Image3MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall Image3MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall Label2Click(TObject *Sender);
    void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
    void __fastcall Image3Click(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall ComboBox1Change(TObject *Sender);
    void __fastcall Edit1Change(TObject *Sender);
    void __fastcall Image2MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall Image3MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall Image2Click(TObject *Sender);
    void __fastcall ClientSocket1Error(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
    void __fastcall ClientSocket1Read(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall send(AnsiString ST);
    void __fastcall ClientSocket1Disconnect(TObject *Sender,
          TCustomWinSocket *Socket);
private:	// User declarations
public:		// User declarations
int se2;
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
