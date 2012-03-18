//---------------------------------------------------------------------------

#ifndef WindowH
#define WindowH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "Scene3D.h"
#include "EpiCar3D.h"
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *Archivo1;
        TMenuItem *Ayuda1;
        TStatusBar *StatusBar;
        TPopupMenu *PopupMenu1;
        TMenuItem *Camaras1;
        TPanel *MainPanel;
        TToolBar *ToolBar;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TPanel *LeftPanel;
        TScrollBox *RightPanel;
        TButton *Button3;
        TPanel *Panel1;
        TPanel *Panel3;
        TPanel *Panel2;
        TPanel *Panel4;
        TListBox *ListBox1;
        TShape *Shape1;
        TShape *Shape2;
        TShape *Shape3;
        TShape *Shape4;
        TPanel *Panel5;
        TTreeView *TreeView1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormPaint(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall PopupMenu1Popup(TObject *Sender);
        void __fastcall Panel1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Panel2MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Panel3MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Panel4MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall FormMouseWheelDown(TObject *Sender,
          TShiftState Shift, TPoint &MousePos, bool &Handled);
        void __fastcall FormMouseWheelUp(TObject *Sender,
          TShiftState Shift, TPoint &MousePos, bool &Handled);
private:	// User declarations

        Scene3D *_scene;

        ViewPort3D *_last_viewport;

        ViewPort3D *_vp1;
        ViewPort3D *_vp2;
        ViewPort3D *_vp3;
        ViewPort3D *_vp4;

        void __fastcall RecalculateGUI();


        EpiCar3D *_epicar;

public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
