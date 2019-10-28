object Form2: TForm2
  Left = 231
  Top = 150
  Align = alCustom
  BorderStyle = bsNone
  ClientHeight = 363
  ClientWidth = 220
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
    Width = 220
    Height = 363
    Align = alClient
    TabOrder = 0
    object GroupBox1: TGroupBox
      Left = 8
      Top = 168
      Width = 201
      Height = 185
      Caption = #51088#46041' '#47196#44536#51064
      TabOrder = 1
      object Label2: TLabel
        Left = 40
        Top = 144
        Width = 137
        Height = 13
        AutoSize = False
        Caption = #51088#46041' '#47196#44536#51064
      end
      object Edit1: TEdit
        Left = 16
        Top = 24
        Width = 161
        Height = 21
        ImeName = 'Microsoft IME 2003'
        TabOrder = 0
        Text = 'Edit1'
      end
      object Edit3: TEdit
        Left = 16
        Top = 104
        Width = 161
        Height = 21
        ImeName = 'Microsoft IME 2003'
        PasswordChar = '*'
        TabOrder = 1
        Text = 'Edit3'
      end
      object CheckBox1: TCheckBox
        Left = 16
        Top = 144
        Width = 13
        Height = 13
        Caption = #51088#46041#47196#44536#51064
        TabOrder = 2
      end
      object Button1: TButton
        Left = 129
        Top = 142
        Width = 49
        Height = 18
        Caption = #54869#51064
        TabOrder = 3
        OnClick = Button1Click
      end
      object Edit2: TEdit
        Left = 16
        Top = 68
        Width = 161
        Height = 21
        ImeName = 'Microsoft IME 2003'
        PasswordChar = '*'
        TabOrder = 4
        Text = 'Edit2'
      end
    end
    object RadioGroup1: TRadioGroup
      Left = 9
      Top = 9
      Width = 136
      Height = 152
      Caption = #48372#50504' '#46321#44553
      ItemIndex = 0
      Items.Strings = (
        '1'#45800#44228
        '2'#45800#44228
        '3'#45800#44228
        '4'#45800#44228
        '5'#45800#44228)
      TabOrder = 0
      OnClick = RadioGroup1Click
    end
  end
end
