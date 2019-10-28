//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <ScktComp.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
    TPopupMenu *PopupMenu2;
    TMenuItem *N2;
    TMenuItem *N6;
    TPopupMenu *PopupMenu1;
    TMenuItem *N4;
    TMenuItem *N5;
    TOpenDialog *OpenDialog1;
    TClientSocket *ClientSocket1;
    TPanel *Panel1;
    TLabel *Label1;
    TListBox *FLB2;
    TListBox *FLB1;
    void __fastcall ClientSocket1Read(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall FLB1DblClick(TObject *Sender);
    void __fastcall N2Click(TObject *Sender);
    void __fastcall N4Click(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall ClientSocket1Error(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
    void __fastcall ClientSocket1Disconnect(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall N5Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
AnsiString RIP;
TFileStream *upfs;
    __fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
