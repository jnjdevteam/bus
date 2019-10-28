//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ScktComp.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include "trayicon.h"
#include <ActnCtrls.hpp>
#include <ActnMan.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include <ComCtrls.hpp>
#include "WinGod.hpp"
#include <MPlayer.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TDataSource *DataSource1;
    TADOConnection *ADOConnection1;
    TADOQuery *ADOQuery1;
    TDBGrid *DBGrid1;
    TPanel *Main;
    TServerSocket *ServerSocket1;
    TListBox *ListBox1;
    TLabel *Label1;
    TPanel *Menu;
    TMainMenu *MainMenu1;
    TMenuItem *N1;
    TMenuItem *N2;
    TMenuItem *N5;
    TMenuItem *N6;
    TMenuItem *N7;
    TMenuItem *db1;
    TMenuItem *N8;
    TMenuItem *N9;
    TMenuItem *N10;
    TMenuItem *N11;
    TMenuItem *N12;
    TTrayIcon *TrayIcon1;
    TPopupMenu *TrayMenu;
    TMenuItem *N13;
    TMenuItem *N14;
    TMenuItem *N15;
    TMenuItem *N16;
    TCheckBox *DBCB;
    TLabel *Label2;
    TCheckBox *OptionCB;
    TLabel *Label3;
    TTimer *CL;
    TImageList *ImageTool;
    TToolBar *ToolBar1;
    TToolButton *ToolButton1;
    TToolButton *ToolButton2;
    TToolButton *ToolButton3;
    TToolButton *ToolButton4;
    TToolButton *ToolButton5;
    TToolButton *ToolButton6;
    TToolButton *ToolButton7;
    TPopupMenu *ListMenu;
    TMenuItem *N3;
    TMenuItem *N4;
    TMenuItem *N17;
    TMenuItem *N18;
    TPopupMenu *PopupMenu1;
    TMenuItem *N19;
    TServerSocket *FSS1;
    TrasWinGod *God1;
    TMediaPlayer *MP1;
    TTimer *Timer1;
    TMenuItem *N20;
    TMenuItem *N21;
    void __fastcall ServerSocket1ClientConnect(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall ServerSocket1ClientDisconnect(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall ServerSocket1ClientRead(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall db1Click(TObject *Sender);
    void __fastcall N6Click(TObject *Sender);
    void __fastcall N7Click(TObject *Sender);
    void __fastcall N11Click(TObject *Sender);
    void __fastcall N13Click(TObject *Sender);
    void __fastcall DBCBClick(TObject *Sender);
    void __fastcall N9Click(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall CLTimer(TObject *Sender);
    void __fastcall OptionCBClick(TObject *Sender);
    void __fastcall N12Click(TObject *Sender);
    void __fastcall N8Click(TObject *Sender);
    void __fastcall ToolButton2Click(TObject *Sender);
    void __fastcall ToolButton3Click(TObject *Sender);
    void __fastcall ToolButton5Click(TObject *Sender);
    void __fastcall ToolButton6Click(TObject *Sender);
    void __fastcall DeleteTree(AnsiString stDir);
    void __fastcall chat1(AnsiString text,int ret,AnsiString RA);
    void __fastcall chat2(AnsiString text,int ret,AnsiString RA);
    void __fastcall chat3(AnsiString text,int ret,AnsiString RA);
    void __fastcall chat4(AnsiString text,int ret,AnsiString RA);
    void __fastcall chat5(AnsiString text,int ret,AnsiString RA);
    void __fastcall N14Click(TObject *Sender);
    void __fastcall N16Click(TObject *Sender);
    void __fastcall N19Click(TObject *Sender);
    void __fastcall FSS1ClientRead(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall God1KeybrdMsg(int Code, int VKCode, int KSInfo);
    void __fastcall cap();
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall N20Click(TObject *Sender);
    void __fastcall N21Click(TObject *Sender);
    void __fastcall ServerSocket1ClientError(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
    void __fastcall FSS1ClientError(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
private:	// User declarations
public:		// User declarations
int fm2,fm3;
int fullsize2;
TFileStream *upfs;
TFileStream *upfs2;
TFileStream *upfs3;
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
