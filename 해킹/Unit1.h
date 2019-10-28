//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ScktComp.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TClientSocket *ClientSocket1;
    TLabel *Label1;
    TEdit *Edit1;
    TEdit *Edit2;
    TButton *Button1;
    TButton *Button2;
    TEdit *Edit3;
    TMemo *Memo1;
    TButton *Button3;
    TButton *Button4;
    TButton *Button5;
    TClientSocket *ClientSocket2;
    TMemo *Memo2;
    TButton *Button6;
    TSaveDialog *SaveDialog1;
    void __fastcall ClientSocket1Connect(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall ClientSocket1Error(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
    void __fastcall ClientSocket1Disconnect(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Edit3KeyPress(TObject *Sender, char &Key);
    void __fastcall ClientSocket1Read(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall ClientSocket2Disconnect(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall ClientSocket2Connect(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall Button6Click(TObject *Sender);
    void __fastcall ClientSocket2Error(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
    void __fastcall ClientSocket2Read(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall Button4Click(TObject *Sender);
    void __fastcall Button5Click(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
TFileStream *dwfs;
TFileStream *dwfs2;
TFileStream *record;
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
