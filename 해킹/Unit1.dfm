object Form1: TForm1
  Left = 192
  Top = 114
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsDialog
  Caption = #54644#53433' '#54532#47196#44536#47016
  ClientHeight = 193
  ClientWidth = 312
  Color = clAqua
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 8
    Width = 113
    Height = 13
    AutoSize = False
    Caption = #51217#49549#52404#53356' : '#44732#51664
    Transparent = True
  end
  object Edit1: TEdit
    Left = 8
    Top = 24
    Width = 121
    Height = 21
    ImeName = 'Microsoft IME 2003'
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 8
    Top = 56
    Width = 121
    Height = 21
    ImeName = 'Microsoft IME 2003'
    TabOrder = 1
  end
  object Button1: TButton
    Left = 8
    Top = 120
    Width = 57
    Height = 25
    Caption = #50672#44208
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 80
    Top = 120
    Width = 49
    Height = 25
    Caption = #52712#49548
    TabOrder = 3
    OnClick = Button2Click
  end
  object Edit3: TEdit
    Left = 8
    Top = 88
    Width = 121
    Height = 21
    ImeName = 'Microsoft IME 2003'
    TabOrder = 4
    OnKeyPress = Edit3KeyPress
  end
  object Memo1: TMemo
    Left = 144
    Top = 8
    Width = 161
    Height = 145
    ImeName = 'Microsoft IME 2003'
    TabOrder = 5
  end
  object Button3: TButton
    Left = 208
    Top = 160
    Width = 89
    Height = 25
    Caption = #53412#48372#46300#54644#53433
    Enabled = False
    TabOrder = 6
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 8
    Top = 160
    Width = 89
    Height = 25
    Caption = #45433#51020#54644#53433
    Enabled = False
    TabOrder = 7
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 104
    Top = 160
    Width = 97
    Height = 25
    Caption = #52897#52432#54644#53433
    Enabled = False
    TabOrder = 8
    OnClick = Button5Click
  end
  object Memo2: TMemo
    Left = 312
    Top = 8
    Width = 185
    Height = 145
    ImeName = 'Microsoft IME 2003'
    TabOrder = 9
  end
  object Button6: TButton
    Left = 368
    Top = 160
    Width = 75
    Height = 25
    Caption = #51200#51109
    Enabled = False
    TabOrder = 10
    OnClick = Button6Click
  end
  object ClientSocket1: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Port = 0
    OnConnect = ClientSocket1Connect
    OnDisconnect = ClientSocket1Disconnect
    OnRead = ClientSocket1Read
    OnError = ClientSocket1Error
    Left = 8
    Top = 8
  end
  object ClientSocket2: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Port = 7575
    OnConnect = ClientSocket2Connect
    OnDisconnect = ClientSocket2Disconnect
    OnRead = ClientSocket2Read
    OnError = ClientSocket2Error
    Left = 40
    Top = 8
  end
  object SaveDialog1: TSaveDialog
    Left = 72
    Top = 8
  end
end
