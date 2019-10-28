object Form2: TForm2
  Left = 192
  Top = 114
  AutoScroll = False
  Caption = 'Form2'
  ClientHeight = 206
  ClientWidth = 119
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object ListBox1: TListBox
    Left = -19
    Top = -17
    Width = 138
    Height = 153
    ImeName = 'Microsoft IME 2003'
    ItemHeight = 13
    TabOrder = 0
  end
  object ListBox2: TListBox
    Left = -19
    Top = -9
    Width = 138
    Height = 145
    ImeName = 'Microsoft IME 2003'
    ItemHeight = 13
    TabOrder = 1
  end
  object ServerSocket1: TServerSocket
    Active = False
    Port = 7373
    ServerType = stNonBlocking
    OnClientConnect = ServerSocket1ClientConnect
    OnClientDisconnect = ServerSocket1ClientDisconnect
    OnClientRead = ServerSocket1ClientRead
    OnClientError = ServerSocket1ClientError
    Left = 8
    Top = 8
  end
  object Timer1: TTimer
    Interval = 1
    OnTimer = Timer1Timer
    Left = 40
    Top = 8
  end
end
