object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 458
  ClientWidth = 764
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  ShowHint = True
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 352
    Top = 118
    Width = 177
    Height = 24
    Caption = #1060#1072#1081#1083#1086#1074#1072#1103' '#1089#1080#1089#1090#1077#1084#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object Label2: TLabel
    Left = 352
    Top = 64
    Width = 102
    Height = 24
    Caption = #1050#1083#1072#1089#1090#1077#1088#1086#1074':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 352
    Top = 22
    Width = 197
    Height = 24
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1073#1091#1082#1074#1091' '#1076#1080#1089#1082#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 555
    Top = 19
    Width = 49
    Height = 27
    Hint = #1044#1074#1086#1081#1085#1086#1077' '#1085#1072#1078#1072#1090#1080#1077' '#1076#1083#1103' '#1074#1099#1073#1086#1088#1072' '#1087#1091#1090#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 0
    Text = 'C'
    TextHint = #1055#1091#1090#1100' '#1076#1083#1103' '#1089#1095#1080#1090#1099#1074#1072#1085#1080#1103
    OnDblClick = Edit1DblClick
  end
  object VirtualStringTree1: TVirtualStringTree
    Left = 8
    Top = 8
    Width = 328
    Height = 367
    DefaultNodeHeight = 26
    Header.AutoSizeIndex = 0
    Header.Options = [hoColumnResize, hoDrag, hoShowSortGlyphs, hoVisible]
    TabOrder = 1
    OnGetText = VirtualStringTree1GetText
    Touch.InteractiveGestures = [igPan, igPressAndTap]
    Touch.InteractiveGestureOptions = [igoPanSingleFingerHorizontal, igoPanSingleFingerVertical, igoPanInertia, igoPanGutter, igoParentPassthrough]
    Columns = <
      item
        Position = 0
        Text = #1053#1086#1084#1077#1088' '#1082#1083#1072#1089#1090#1077#1088#1072
        Width = 203
      end
      item
        Position = 1
        Text = #1058#1080#1087' '#1092#1072#1081#1083#1072
        Width = 112
      end>
  end
  object OpenFSButton: TButton
    Left = 624
    Top = 8
    Width = 73
    Height = 38
    Caption = #1054#1073#1088#1072#1073#1086#1090#1072#1090#1100
    TabOrder = 2
    OnClick = OpenFSButtonClick
  end
  object DeliteStringButton: TButton
    Left = 8
    Top = 381
    Width = 161
    Height = 56
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1074#1099#1073#1088#1072#1085#1085#1091#1102' '#1089#1090#1088#1086#1082#1091
    TabOrder = 3
    OnClick = DeliteStringButtonClick
  end
  object ClearDBButton: TButton
    Left = 175
    Top = 381
    Width = 161
    Height = 57
    Caption = #1054#1095#1080#1089#1090#1082#1072' '#1090#1072#1073#1083#1080#1094#1099
    TabOrder = 4
    OnClick = ClearDBButtonClick
  end
  object Button1: TButton
    Left = 576
    Top = 368
    Width = 161
    Height = 69
    Caption = #1054#1089#1090#1072#1085#1086#1074#1080#1090#1100' '#1087#1086#1090#1086#1082
    TabOrder = 5
    OnClick = Button1Click
  end
end
