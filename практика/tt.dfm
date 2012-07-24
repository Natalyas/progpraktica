object Form1: TForm1
  Left = 386
  Top = 196
  BorderStyle = bsSingle
  Caption = #1057#1080#1084#1087#1083#1077#1082#1089' '#1084#1077#1090#1086#1076
  ClientHeight = 421
  ClientWidth = 632
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  KeyPreview = True
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesktopCenter
  OnKeyDown = FormKeyDown
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 632
    Height = 402
    ActivePage = TabSheet1
    Align = alClient
    TabIndex = 0
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = #1042#1074#1086#1076' '#1079#1085#1072#1095#1077#1085#1080#1081
      object Label1: TLabel
        Left = 8
        Top = 40
        Width = 155
        Height = 13
        Caption = #1055#1086#1076#1082#1083#1102#1095#1080#1090#1100' '#1092#1072#1081#1083' '#1089' '#1084#1072#1089#1089#1080#1074#1086#1084
      end
      object Label2: TLabel
        Left = 8
        Top = 104
        Width = 155
        Height = 13
        Caption = #1055#1086#1076#1082#1083#1102#1095#1080#1090#1100' '#1092#1072#1081#1083' '#1089' '#1084#1072#1089#1089#1080#1074#1086#1084
      end
      object Label4: TLabel
        Left = 40
        Top = 184
        Width = 130
        Height = 13
        Caption = #1052#1072#1089#1089#1080#1074' '#1094#1077#1083#1077#1074#1086#1081' '#1092#1091#1085#1082#1094#1080#1080
      end
      object Label5: TLabel
        Left = 328
        Top = 144
        Width = 158
        Height = 13
        Caption = #1052#1072#1089#1089#1080#1074' '#1083#1080#1085#1077#1081#1085#1099#1093' '#1086#1075#1088#1072#1085#1080#1095#1077#1085#1080#1081
      end
      object Label6: TLabel
        Left = 328
        Top = 24
        Width = 101
        Height = 13
        Caption = #1055#1086#1083#1091#1095#1080#1090#1100' '#1088#1077#1079#1091#1083#1100#1090#1072#1090
      end
      object Label11: TLabel
        Left = 8
        Top = 56
        Width = 152
        Height = 13
        Caption = #1082#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090#1086#1074' '#1094#1077#1083#1077#1074#1086#1081' '#1092'-'#1080#1080
      end
      object Label12: TLabel
        Left = 8
        Top = 120
        Width = 164
        Height = 13
        Caption = #1089#1080#1089#1090#1077#1084#1099' '#1083#1080#1085#1077#1081#1085#1099#1093' '#1086#1075#1088#1072#1085#1080#1095#1077#1085#1080#1081
      end
      object Button1: TButton
        Left = 184
        Top = 40
        Width = 49
        Height = 25
        Caption = #1054#1073#1079#1086#1088
        TabOrder = 0
        OnClick = Button1Click
      end
      object Button2: TButton
        Left = 184
        Top = 104
        Width = 49
        Height = 25
        Caption = #1054#1073#1079#1086#1088
        TabOrder = 1
        OnClick = Button2Click
      end
      object StringGrid1: TStringGrid
        Left = 40
        Top = 216
        Width = 209
        Height = 65
        DefaultColWidth = 40
        DefaultRowHeight = 18
        FixedCols = 0
        RowCount = 2
        FixedRows = 0
        TabOrder = 2
      end
      object StringGrid2: TStringGrid
        Left = 320
        Top = 176
        Width = 217
        Height = 113
        DefaultColWidth = 40
        DefaultRowHeight = 18
        FixedCols = 0
        FixedRows = 0
        TabOrder = 3
      end
      object Button3: TButton
        Left = 328
        Top = 48
        Width = 57
        Height = 25
        Caption = #1079#1072#1087#1091#1089#1082
        TabOrder = 4
        OnClick = Button3Click
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090
      ImageIndex = 1
      object Label7: TLabel
        Left = 16
        Top = 32
        Width = 144
        Height = 13
        Caption = #1089#1086#1093#1088#1072#1085#1080#1090#1100' '#1088#1077#1079#1091#1083#1100#1090#1072#1090' '#1074' '#1092#1072#1081#1083
      end
      object Label9: TLabel
        Left = 16
        Top = 200
        Width = 145
        Height = 13
        Caption = #1052#1072#1082#1089#1080#1084#1091#1084' '#1094#1077#1083#1077#1074#1086#1081' '#1092#1091#1085#1082#1094#1080#1080
      end
      object Label10: TLabel
        Left = 16
        Top = 104
        Width = 124
        Height = 13
        Caption = #1052#1072#1089#1089#1080#1074'-'#1088#1077#1096#1077#1085#1080#1077' '#1079#1072#1076#1072#1095#1080
      end
      object Label13: TLabel
        Left = 296
        Top = 104
        Width = 153
        Height = 13
        Caption = #1055#1086#1089#1083#1077#1076#1085#1103#1103' '#1089#1080#1084#1087#1083#1077#1082#1089' '#1090#1072#1073#1083#1080#1094#1072
      end
      object Button4: TButton
        Left = 56
        Top = 56
        Width = 65
        Height = 25
        Caption = #1054#1073#1079#1086#1088
        TabOrder = 0
        OnClick = Button4Click
      end
      object StringGrid3: TStringGrid
        Left = 16
        Top = 128
        Width = 217
        Height = 41
        ColCount = 1
        DefaultColWidth = 40
        DefaultRowHeight = 18
        FixedCols = 0
        RowCount = 1
        FixedRows = 0
        TabOrder = 1
      end
      object Edit1: TEdit
        Left = 16
        Top = 224
        Width = 97
        Height = 21
        TabOrder = 2
        Text = 'Edit1'
      end
      object StringGrid4: TStringGrid
        Left = 288
        Top = 128
        Width = 265
        Height = 129
        ColCount = 1
        DefaultColWidth = 35
        DefaultRowHeight = 18
        FixedCols = 0
        RowCount = 1
        FixedRows = 0
        TabOrder = 3
      end
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 402
    Width = 632
    Height = 19
    Panels = <
      item
        Text = #1057#1090#1072#1090#1091#1089' '#1087#1088#1086#1075#1088#1072#1084#1084#1099': '#1047#1072#1076#1072#1085#1080#1077' '#1074#1093#1086#1076#1085#1099#1093' '#1076#1072#1085#1085#1099#1093
        Width = 50
      end>
    SimplePanel = True
    SimpleText = #1057#1090#1072#1090#1091#1089' '#1087#1088#1086#1075#1088#1072#1084#1084#1099': '#1047#1072#1076#1072#1085#1080#1077' '#1076#1072#1085#1085#1099#1093
  end
  object OpenDialog1: TOpenDialog
    Left = 560
  end
  object SaveDialog1: TSaveDialog
    Left = 592
  end
  object MainMenu1: TMainMenu
    Left = 200
    Top = 16
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N2: TMenuItem
        Caption = #1055#1086#1076#1082#1083#1102#1095#1080#1090#1100' '#1084#1072#1089'.'#1082#1086#1101#1092#1092'.'
        OnClick = N2Click
      end
      object N3: TMenuItem
        Caption = #1055#1086#1076#1082#1083#1102#1095#1080#1090#1100' '#1084#1072#1089'.'#1083#1080#1085'.'#1086#1075#1088'.'
        OnClick = N3Click
      end
      object N4: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1088#1077#1079#1091#1083#1100#1090#1072#1090
      end
    end
    object N5: TMenuItem
      Caption = ' '#1047#1072#1087#1091#1089#1082'   F9'
      OnClick = N5Click
    end
    object N6: TMenuItem
      Caption = #1042#1099#1093#1086#1076
      OnClick = N6Click
    end
  end
end
