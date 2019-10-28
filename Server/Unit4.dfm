object Form4: TForm4
  Left = 460
  Top = 149
  BorderStyle = bsNone
  ClientHeight = 329
  ClientWidth = 209
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 209
    Height = 329
    Caption = 'Panel1'
    TabOrder = 0
    object Label1: TLabel
      Left = 7
      Top = 5
      Width = 196
      Height = 13
      AutoSize = False
      Caption = 'C:'
    end
    object FLB2: TListBox
      Left = 0
      Top = 176
      Width = 209
      Height = 152
      ImeName = 'Microsoft IME 2003'
      ItemHeight = 13
      PopupMenu = PopupMenu2
      TabOrder = 0
    end
    object FLB1: TListBox
      Left = 0
      Top = 24
      Width = 209
      Height = 153
      ImeName = 'Microsoft IME 2003'
      ItemHeight = 13
      PopupMenu = PopupMenu1
      TabOrder = 1
      OnDblClick = FLB1DblClick
    end
  end
  object PopupMenu2: TPopupMenu
    Left = 16
    Top = 192
    object N2: TMenuItem
      Caption = #51648#50864#44592
      OnClick = N2Click
    end
    object N6: TMenuItem
      Caption = #45124#44592
      OnClick = N5Click
    end
  end
  object PopupMenu1: TPopupMenu
    Left = 16
    Top = 40
    object N4: TMenuItem
      Caption = #51648#50864#44592
      OnClick = N4Click
    end
    object N5: TMenuItem
      Caption = #45124#44592
      OnClick = N5Click
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 40
    Top = 16
  end
  object ClientSocket1: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Port = 7373
    OnDisconnect = ClientSocket1Disconnect
    OnRead = ClientSocket1Read
    OnError = ClientSocket1Error
    Left = 8
    Top = 16
  end
end
