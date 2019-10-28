//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "RxGIF.hpp"
#include <ExtCtrls.hpp>
#include "WinGod.hpp"
#include <MPlayer.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
    TImage *MainImage;
    TImage *Image3;
    TEdit *P1E;
    TComboBox *IDCB;
    TCheckBox *Security;
    TCheckBox *Auto;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TEdit *P2E;
    TCheckBox *Pass2;
    TLabel *Label6;
    TMediaPlayer *MediaPlayer1;
    TPanel *Panel1;
    TADOConnection *ADOConnection1;
    TADOQuery *ADOQuery1;
    TDBGrid *DBGrid1;
    TDataSource *DataSource1;
    TImage *Image2;
    TListBox *LB;
    TTimer *Jo;
    void __fastcall Pass2Click(TObject *Sender);
    void __fastcall Image2MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall Image2MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall Image3MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall Image3MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall P2EKeyPress(TObject *Sender, char &Key);
    void __fastcall MainImageMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall Join(int join);
    void __fastcall JoTimer(TObject *Sender);
    void __fastcall P1EKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
int sho;
    __fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
